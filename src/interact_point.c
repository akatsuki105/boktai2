#include "collision_map.h"
#include "global.h"
#include "input.h"
#include "malloc.h"
#include "player.h"
#include "sprite.h"
#include "vm.h"

// マップ上の調べられる場所, 近くで壁の方を向いて A を押すと beginScript を実行する, ヒントパネルや ATM など
typedef struct {
  u16 id;              // 0x00, '.n', beginScript / endScript の第1引数になる
  u8 wallSide;         // 0x02, '.d', 0: 左上の壁, 1: 右上の壁, 調べられる向きと位置のずらし方が変わる
  u8 unk_3;            // 0x03, 0 を書くだけ
  bool8 invisible;     // 0x04, '.t', TRUE ならスプライトを出さない (ATM のように絵が BG 側にあるもの)
  u8 state;            // 0x05, 0: 範囲外, 1: 調べられる (範囲内で壁の方を向いている), 2: 調べ中
  bool8 stateChanged;  // 0x06, state を変えたフレームに立つ
  u8 glow;             // 0x07, 0〜5, 調べられる間は増え, 離れると減ってパレットが元に戻る
  ZoneID32 zoneID;     // 0x08, '.m' があれば置いた位置のゾーン, プレイヤーが別のゾーンにいる間は隠れて調べられない, -1 なら常に有効
  u16 beginScript;     // 0x0C, '.b', 調べ始めたときに実行するスクリプト
  u16 endScript;       // 0x0E, '.e', Cmd_EndInteract で調べ終わったときに実行するスクリプト
  u32 rangeSq;         // 0x10, '.D=230' の2乗, 調べられる距離
  u16 args[4];         // 0x14, '.a', beginScript / endScript の第2引数以降になる
  Vec3 pos;            // 0x1C, 調べられるかの判定に使う位置
  AuxSprite sprite;    // 0x24
  AuxSpriteGfx gfx;    // 0x50, SPRITE_HINT_PANEL
} InteractPoint;
static_assert(sizeof(InteractPoint) == 108);

// 調べられる場所をまとめて管理する, スクリプトの EntityCreate(0x83B2, .n = 個数) で作り Cmd_AddInteractPoint で1つずつ登録する
typedef struct InteractPointManager {
  Entity e;               // 0x00, ENTITY_UNK_8
  u8 length;              // 0x18, '.n', points の要素数
  s8 activeIdx;           // 0x19, 調べ中の points の添字, なければ -1
  s8 pendingScript;       // 0x1A, 次のフレームで実行するスクリプト, 0: beginScript, 1: endScript, -1: なし
  u32 usedMask;           // 0x1C, 登録済みの points のビット
  InteractPoint* points;  // 0x20, InteractPoint[length]
  Player* player;         // 0x24, gPlayerPtr[0]
  Vec3 pos;               // 0x28, プレイヤーの位置, 毎フレーム写す
} InteractPointManager;
static_assert(sizeof(InteractPointManager) == 48);

IWRAM_DATA InteractPointManager* gInteractPointManager = NULL;  // 0x0300003C

s32 InteractPoint_SetState(InteractPoint* p, u32 n) {
  p->state = n;
  p->stateChanged = TRUE;
}

bool32 InteractPoint_ConsumeStateChanged(InteractPoint* p) {
  if (p->stateChanged) {
    p->stateChanged = FALSE;
    return TRUE;
  } else {
    return FALSE;
  }
}

// スプライトを割り当てて隠した状態で描画リストに繋ぐ
s32 InteractPoint_InitSprite(InteractPointManager* p, InteractPoint* point, s32 idx) {
  if (!Video_GetAuxSprite(&point->gfx, SPRITE_HINT_PANEL)) {
    return -1;
  }
  AuxSprite_Add(&point->sprite, &point->gfx, SPRFLAG_HIDDEN);
  AuxSprite_SetPoseIdx(&point->sprite, 1);
  point->sprite.priority = 2;
  return 0;
}

// 登録済みで id が n の場所を探す, 見つかればその添字を outIdx に入れて返す
InteractPoint* InteractPointManager_FindById(InteractPointManager* p, u32 n, s32* outIdx) {
  InteractPoint* point;
  s32 i;

  if (outIdx != NULL) {
    *outIdx = -1;
  }
  point = p->points;
  for (i = 0; i < p->length; i++, point++) {
    if ((p->usedMask & (1 << i)) && point->id == n) {
      if (outIdx != NULL) {
        *outIdx = i;
      }
      return point;
    }
  }
  return NULL;
}

// スプライトのパレットを切り替える, 0: 光っている, 1: 中間, 2: 通常, invisible なら何もしない
s32 InteractPoint_SetPltt(InteractPoint* p, s32 level) {
  AuxSpriteGfx* gfx = &p->gfx;

  if (!p->invisible) {
    Video_SetAuxSpritePltt(gfx, OBP_HINT_PANEL(level));
  }
}

// 位置を決める, 判定用の pos とスプライトは wallSide に応じて壁側へずらす
s32 InteractPoint_SetPos(InteractPointManager* p, InteractPoint* point, Vec3* pos) {
  AuxSprite* sprite = &point->sprite;
  VEC3_SET(point->pos, pos->x, pos->y, pos->z);
  VEC3_SET(sprite->pos, pos->x, pos->y, pos->z);
  if (point->wallSide != 0) {
    point->pos.x += Q8(0.5);
    sprite->pos.z -= Q8(0.5);
  } else {
    point->pos.z += Q8(0.5);
    sprite->pos.x -= Q8(0.5);
  }
  sprite->pos.x += Q8(0.235);
  sprite->pos.z += Q8(0.235);
  sprite->pos.y += Q8(0.08);
}

// 調べられる間は glow を上げて光らせ, 離れたら下げて元のパレットに戻す
void InteractPoint_UpdateGlow(InteractPointManager* p, InteractPoint* point) {
  if (point->invisible == 1) {
    return;
  }
  switch (point->state) {
    case 0: {
      if (point->glow == 0) {
        InteractPoint_SetPltt(point, 2);
      } else {
        InteractPoint_SetPltt(point, 1);
        point->glow--;
      }
      break;
    }
    case 1: {
      if (point->glow > 4) {
        InteractPoint_SetPltt(point, 0);
      } else {
        InteractPoint_SetPltt(point, 1);
        point->glow++;
      }
      break;
    }
    case 2: {
      point->glow = 5;
      InteractPoint_SetPltt(point, 0);
      break;
    }
  }
}

// プレイヤーが行動できて, 他の場所を調べ中でなければ TRUE
bool32 InteractPointManager_CanBegin(InteractPointManager* p, InteractPoint* point) {
  Player* player = p->player;

  if (!TEST_FLAGS(player->flag20, PFLAG20_UNK_2 | PFLAG20_WALL_COVER | PFLAG20_QC | PFLAG20_REFUELING | PFLAG20_UNK_11 | PFLAG20_UNK_12) && player->formRequest == 0 && p->activeIdx < 0) {
    return TRUE;
  }
  return FALSE;
}

// id と args を引数5個に詰めてスクリプトを実行する
void InteractPoint_RunScript(InteractPointManager* p, InteractPoint* point, s32 scriptID) {
  u32 argv[5];
  ScriptArgs args;
  s32 i;

  if (scriptID != 0) {
    argv[0] = point->id;
    for (i = 0; i < 4; i++) {
      argv[i + 1] = (s16)point->args[i];
    }
    args.argc = 5;
    args.argv = argv;
    VM_ExecByID(scriptID, &args);
  }
}

// 次のフレームで points[n] の beginScript を実行させる
s32 InteractPointManager_RequestBegin(InteractPointManager* p, s32 n) {
  p->activeIdx = n;
  p->pendingScript = 0;
}

// 次のフレームで points[n] の endScript を実行させる
s32 InteractPointManager_RequestEnd(InteractPointManager* p, s32 n) {
  p->activeIdx = n;
  p->pendingScript = 1;
}

// 状態 0: プレイヤーが範囲内で壁の方を向いたら調べられる状態にする
s32 InteractPoint_StateIdle(InteractPointManager* p, InteractPoint* point, s32 idx) {
  InteractPoint_ConsumeStateChanged(point);
  if (p->player != NULL) {
    u32 mask = PMODE_DEAD | PMODE_LOCKED;
    u32 flags = gPlayerModes[0];
    if (!(flags & mask) && (flags & PMODE_ACTIVE)) {
      s32 dx = point->pos.x - p->pos.x;
      s32 dz = point->pos.z - p->pos.z;
      u32 dist2 = dx * dx + dz * dz;
      s32 dir = ANGLE_TO_DIR8((u16)ArcTan2_8(dx, dz) + 0x10);
      if (dist2 < point->rangeSq) {
        s32 a, b, c;
        if (point->wallSide != 0) {
          a = DIR8_UP, b = DIR8_UP_RIGHT, c = DIR8_RIGHT;
        } else {
          a = DIR8_LEFT, b = DIR8_UP_LEFT, c = DIR8_UP;
        }
        if (a == dir || b == dir || c == dir) {
          s32 facing = p->player->facing;
          bool32 ok = TRUE;
          if (a != facing && b != facing && c != facing) {
            ok = FALSE;
          }
          if (ok) {
            InteractPoint_SetState(point, 1);
          }
        }
      }
    }
  }
  return 0;
}

// 状態 1: A が押されたら調べ中にして beginScript を予約する, 範囲外に出るか向きを変えたら状態 0 に戻す
s32 InteractPoint_StateReady(InteractPointManager* p, InteractPoint* point, s32 idx) {
  s32 dx, dz;
  u32 dist2;
  s32 dir;
  s32 facing;
  s32 a, b, c;
  u32 flags;
  u32 mask;
  bool32 ok;

  InteractPoint_ConsumeStateChanged(point);
  if (p->player != NULL) {
    mask = PMODE_DEAD | PMODE_LOCKED;
    flags = gPlayerModes[0];
    if (!(flags & mask) && (flags & PMODE_ACTIVE)) {
      dx = point->pos.x - p->pos.x;
      dz = point->pos.z - p->pos.z;
      dist2 = dx * dx + dz * dz;
      dir = ANGLE_TO_DIR8((u16)ArcTan2_8(dx, dz) + 0x10);
      if (dist2 < point->rangeSq) {
        if (point->wallSide != 0) {
          a = DIR8_UP, b = DIR8_UP_RIGHT, c = DIR8_RIGHT;
        } else {
          a = DIR8_LEFT, b = DIR8_UP_LEFT, c = DIR8_UP;
        }
        if (a == dir || b == dir || c == dir) {
          facing = p->player->facing;
          ok = TRUE;
          if (a != facing && b != facing && c != facing) {
            ok = FALSE;
          }
          if (ok) {
            if (!(gInput[0].pressed & A_BUTTON)) {
              return 0;
            }
            if (!InteractPointManager_CanBegin(p, point)) {
              return 0;
            }
            point->glow = 5;
            InteractPoint_SetPltt(point, 0);
            InteractPoint_SetState(point, 2);
            InteractPointManager_RequestBegin(p, idx);
            return 0;
          }
        }
      }
    }
  }
  InteractPoint_SetState(point, 0);
  return 0;
}

// 状態 2: 調べ中に範囲外に出るか向きを変えたら状態 0 に戻す
s32 InteractPoint_StateActive(InteractPointManager* p, InteractPoint* point, s32 idx) {
  s32 dx, dz;
  u32 dist2;
  s32 angle;
  s32 dir;
  s32 facing;
  s32 a, b, c;
  u32 flags;
  u32 mask;
  bool32 ok;

  InteractPoint_ConsumeStateChanged(point);
  if (p->player != NULL) {
    mask = PMODE_DEAD | PMODE_LOCKED;
    flags = gPlayerModes[0];
    if (!(flags & mask) && (flags & PMODE_ACTIVE)) {
      dx = point->pos.x - p->pos.x;
      dz = point->pos.z - p->pos.z;
      dist2 = dx * dx + dz * dz;
      angle = ArcTan2_8(dx, dz);
      dir = ANGLE_TO_DIR8((u16)angle + 0x10);
      if (dist2 < point->rangeSq) {
        if (point->wallSide != 0) {
          a = DIR8_UP, b = DIR8_UP_RIGHT, c = DIR8_RIGHT;
        } else {
          a = DIR8_LEFT, b = DIR8_UP_LEFT, c = DIR8_UP;
        }
        if (a == dir || b == dir || c == dir) {
          facing = p->player->facing;
          ok = TRUE;
          if (a != facing && b != facing && c != facing) {
            ok = FALSE;
          }
          if (ok) {
            return;
          }
        }
      }
    }
  }
  InteractPoint_SetState(point, 0);
  return 0;
}

s32 (*const sInteractPointStates[3])(InteractPointManager*, InteractPoint*, s32) = {
    InteractPoint_StateIdle,
    InteractPoint_StateReady,
    InteractPoint_StateActive,
};  // 0x085aa6ac

// 各場所の状態を進め, 予約されたスクリプトを実行する
// ゾーン一致を bool8 を返す static inline (gStat->zoneID == zoneID) にすると 0/1 の作り置きは出るが, 後半の activeIdx / pendingScript の扱いがまだ合わない (109/108)
NON_MATCH s32 InteractPointManager_Update(InteractPointManager* p) {
#ifdef NONMATCHING_C
  InteractPoint* point;
  s32 i;
  bool32 alive;

  if (p->player != NULL) {
    p->pos = p->player->mover.pos;
  }
  point = p->points;
  for (i = 0; i < p->length; i++, point++) {
    if (p->usedMask & (1 << i)) {
      if (point->zoneID >= 0) {
        alive = gStat->zoneID == point->zoneID;
        if (!alive) {
          if (point->invisible != 1) {
            point->sprite.flags |= SPRFLAG_HIDDEN;
          }
          continue;
        }
      }
      if (point->invisible != 1) {
        point->sprite.flags &= ~SPRFLAG_HIDDEN;
      }
      sInteractPointStates[point->state](p, point, i);
      InteractPoint_UpdateGlow(p, point);
    }
  }
  if (p->pendingScript >= 0 && p->activeIdx >= 0) {
    point = &p->points[p->activeIdx];
    if (p->pendingScript == 0) {
      p->pendingScript = -1;
      InteractPoint_RunScript(p, point, point->beginScript);
    } else if (p->pendingScript == 1) {
      p->pendingScript = -1;
      p->activeIdx = -1;
      InteractPoint_RunScript(p, point, point->endScript);
    }
  }
  return 0;
#else
  INCFUNC("asm/func/InteractPointManager_Update.inc");
#endif
}

s32 InteractPointManager_Destroy(InteractPointManager* p) {
  InteractPoint* point;
  s32 i;

  for (point = p->points, i = 0; i < p->length; i++, point++) {
    AuxSprite_Remove(&point->sprite);
  }
  if (p->points != NULL) {
    Free(p->points);
  }
  gInteractPointManager = NULL;
  return 0;
}

s32 InteractPointManager_Init(InteractPointManager* p, u32 _) {
  InteractPoint* point;
  s32 i;

  gInteractPointManager = p;
  p->length = VM_GetNamedArgValue('n', 1);
  p->activeIdx = -1;
  p->pendingScript = -1;
  p->usedMask = 0;
  p->points = Malloc(p->length * sizeof(InteractPoint));
  if (p->points == NULL) {
    return -1;
  }
  ClearMemory(p->points, p->length * sizeof(InteractPoint));
  point = p->points;
  for (i = 0; i < p->length; i++, point++) {
    if (InteractPoint_InitSprite(p, point, i) < 0) {
      return -1;
    }
  }
  p->player = gPlayerPtr[0];
  if (p->player != NULL) {
    p->pos = p->player->mover.pos;
  } else {
    VEC3_SET(p->pos, 0, 0, 0);
  }
  return 0;
}

// 0x83B2
InteractPointManager* InteractPointManager_Create(u32 id) {
  if (gInteractPointManager == NULL) {
    InteractPointManager* p = CreateEntity(ENTITY_UNK_8, sizeof(InteractPointManager));
    if (p != NULL) {
      SetEntityRoutine(p, InteractPointManager_Update, InteractPointManager_Destroy);
      if (InteractPointManager_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gInteractPointManager;
}

// 0x883A, 空いている枠に調べられる場所を1つ登録する, 枠が埋まっていれば -1 を返す
// '.n': id, 調べたときのスクリプトの第1引数になる
// '.d': 0 なら左上の壁, 1 なら右上の壁にある
// '.t': 1 ならスプライトを出さない (ATM のように絵が BG 側にあるもの)
// '.m': 0 以外なら置いた位置のゾーンにプレイヤーがいる間だけ有効にする
// '.b': 調べ始めたときに実行するスクリプト
// '.e': 調べ終わったときに実行するスクリプト
// '.D=230': 調べられる距離
// '.a': スクリプトの第2引数以降に渡す値, 最大4個
// '.p': 位置
NON_MATCH s32 Cmd_AddInteractPoint(void) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 useZone;
  InteractPointManager* p;
  InteractPoint* point;
  s32 i;
  s32 n;
  s32 j;
  s32 range;
  u32 v;

  p = gInteractPointManager;
  if (p == NULL) {
    return -1;
  }
  n = VM_GetNamedArgValue('n', 0);
  point = p->points;
  for (i = 0; i < p->length; i++, point++) {
    if (!(p->usedMask & (1 << i))) {
      point->id = n;
      point->wallSide = VM_GetNamedArgValue('d', 0);
      point->unk_3 = 0;
      point->invisible = VM_GetNamedArgValue('t', 0);
      useZone = VM_GetNamedArgValue('m', 0);
      point->beginScript = VM_GetNamedArgValue('b', 0);
      point->endScript = VM_GetNamedArgValue('e', 0);
      range = VM_GetNamedArgValue('D', 230);
      point->rangeSq = range * range;
      if (VM_SeekToNamedArg('a')) {
        for (j = 0; j < 4; j++) {
          if (VM_GetPC() != NULL) {
            v = VM_GetValue();
          }
          point->args[j] = v;
        }
      } else {
        for (j = 0; j < 4; j++) {
          point->args[j] = 0;
        }
      }
      if (VM_SeekToNamedArg('p')) {
        VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
      } else {
        VEC3_SET(pos, 0, 0, 0);
      }
      InteractPoint_SetPos(p, point, &pos);
      if (useZone != 0) {
        point->zoneID = GetZoneAt(&point->pos);
      } else {
        point->zoneID = -1;
      }
      InteractPoint_SetPltt(point, 2);
      p->usedMask |= 1 << i;
      break;
    }
  }
  if (i == p->length) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Cmd_AddInteractPoint.inc");
#endif
}

// 0x2740, 調べ中の場所を調べ終わりにして endScript を実行させる, ヒントパネルを閉じると呼ばれる
s32 Cmd_EndInteract(void) {
  InteractPointManager* p = gInteractPointManager;
  if (p == NULL || p->activeIdx < 0 || p->activeIdx >= p->length) {
    return -1;
  }
  InteractPointManager_RequestEnd(p, p->activeIdx);
  InteractPoint_SetState(&p->points[p->activeIdx], 0);
  return 0;
}

// 0x1F65, '.n' の id の場所を '.p' の位置に置き直す
s32 Cmd_SetInteractPointPos(void) {
  Vec3 pos;
  InteractPoint* point;

  InteractPointManager* p = gInteractPointManager;
  if (p == NULL) {
    return -1;
  }
  point = InteractPointManager_FindById(p, VM_GetNamedArgValue('n', 0), NULL);
  if (point == NULL) {
    return -1;
  }
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  InteractPoint_SetPos(p, point, &pos);
  if (point->zoneID >= 0) {
    point->zoneID = GetZoneAt(&point->pos);
  }
}
