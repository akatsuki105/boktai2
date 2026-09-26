#include "global.h"
#include "input.h"
#include "malloc.h"
#include "player.h"
#include "sprite.h"
#include "vm.h"

// おそらくこれが、ヒントパネルやATMに対応
typedef struct {
  u16 unk_0;         // 0x00, 根拠: FUN_08009398 がスクリプトの第1引数として渡す
  u8 unk_2;          // 0x02
  u8 unk_3;          // 0x03
  u8 unk_4;          // 0x04
  u8 state;          // 0x05, 0: 範囲外, 1: インタラクト可能(プレイヤーが範囲内でそのオブジェクトを向いている), 2: インタラクト中(ヒントパネルなら読んでいる時, ATMなら操作中)
  bool8 unk_6;       // 0x06
  u8 unk_7;          // 0x07
  s32 id_8;          // 0x08, GameInfo.unk_248 と比較して等しくない場合は、オブジェクトが消えた(消えた後でも等しくなると復活した)
  u16 unk_c;         // 0x0C
  u16 unk_e;         // 0x0E
  u32 unk_10;        // 0x10, 反応範囲の半径の2乗, 根拠: FUN_080093f8 がプレイヤーとの距離の2乗と符号なしで比較する
  u16 unk_14[4];     // 0x14, '.a'
  Vec3 pos;          // 0x1C
  AuxSprite sprite;  // 0x24, gfx を指す描画ノード
  AuxSpriteGfx gfx;  // 0x50
} Entity83B2Data;
static_assert(sizeof(Entity83B2Data) == 108);

// 銀行に入る時に Entity83B2_Create が Entity83B2_Init を呼ぶが、その際に返り値を -1 にして Entity83B2_Init が失敗したことにすると、
// ヒントパネルが消滅し、 銀行のATMはインタラクトできなくなった(ATMのグラ自体はある), ただし、太陽スタンドには何も影響がなかった
// なので、インタラクト可能なオブジェクトの管理用の構造体だと思われる
typedef struct Entity83B2 {
  Entity e;              // 0x00, ENTITY_UNK_8
  u8 length;             // 0x18, list の要素数, 銀行だと3だった
  s8 unk_19;             // 0x19
  s8 unk_1a;             // 0x1A
  u32 unk_1c;            // 0x1C
  Entity83B2Data* list;  // 0x20, Malloc で確保した Entity83B2Data[length], これがインタラクト可能なオブジェクトのリストになっていると思われる
  Player* player;        // 0x24, gPlayerPtr[0]
  Vec3 pos;              // 0x28, Player.pos
} Entity83B2;
static_assert(sizeof(Entity83B2) == 48);

IWRAM_DATA Entity83B2* gEntity83B2 = NULL;  // 0x0300003C

s32 GetMapAreaAt(Vec3* pos);

static inline bool32 IsCurrentObject(s32 id) { return gStat->unk_248 == id; }

extern u32 u32_03002bc0;

s32 FUN_080091c4(Entity83B2Data* p, u32 n) {
  p->state = n;
  p->unk_6 = TRUE;
}

bool32 FUN_080091d0(Entity83B2Data* p) {
  if (p->unk_6) {
    p->unk_6 = FALSE;
    return TRUE;
  } else {
    return FALSE;
  }
}

// list の1要素にアクタースプライトを割り当てて描画リストに繋ぐ
s32 FUN_080091e8(Entity83B2* p, Entity83B2Data* data, s32 idx) {
  if (!Video_GetAuxSprite(&data->gfx, SPRITE_HINT_PANEL)) {
    return -1;
  }
  AuxSprite_Add(&data->sprite, &data->gfx, 1);
  AuxSprite_SetPoseIdx(&data->sprite, 1);
  data->sprite.priority = 2;
  return 0;
}

// unk_0 が n に一致する有効な要素を探す, 見つかればその添字を outIdx に入れて返す
Entity83B2Data* FUN_0800922c(Entity83B2* p, u32 n, s32* outIdx) {
  Entity83B2Data* data;
  s32 i;

  if (outIdx != NULL) {
    *outIdx = -1;
  }
  data = p->list;
  for (i = 0; i < p->length; i++, data++) {
    if ((p->unk_1c & (1 << i)) && data->unk_0 == n) {
      if (outIdx != NULL) {
        *outIdx = i;
      }
      return data;
    }
  }
  return NULL;
}

// スプライトのパレットを切り替える (plttID 0/1/2 に 76 を足したものが実際のパレットID)
s32 FUN_08009278(Entity83B2Data* p, s32 plttID) {
  AuxSpriteGfx* gfx = &p->gfx;
  if (p->unk_4 == 0) {
    Video_SetAuxSpritePltt(gfx, plttID + 76);
  }
  // 返り値は s32 だが実際には何も返さない
}

// 対象の座標を設定する, unk_2 で判定用の座標と描画位置のどちらをずらすかが変わる
void* FUN_08009298(Entity83B2* p, Entity83B2Data* data, Vec3* pos) {
  AuxSprite* sprite = &data->sprite;
  data->pos.x = pos->x;
  data->pos.y = pos->y;
  data->pos.z = pos->z;
  sprite->pos.x = pos->x;
  sprite->pos.y = pos->y;
  sprite->pos.z = pos->z;
  if (data->unk_2 != 0) {
    data->pos.x += 0x80;
    sprite->pos.z -= 0x80;
  } else {
    data->pos.z += 0x80;
    sprite->pos.x -= 0x80;
  }
  sprite->pos.x += 0x3C;
  sprite->pos.z += 0x3C;
  sprite->pos.y += 0x14;
}

// state に応じてパレットを切り替える, インタラクト可能な間は unk_7 を上下させて点滅させる
void FUN_080092f0(Entity83B2* p, Entity83B2Data* data) {
  if (data->unk_4 == 1) {
    return;
  }
  switch (data->state) {
    case 0: {
      if (data->unk_7 == 0) {
        FUN_08009278(data, 2);
      } else {
        FUN_08009278(data, 1);
        data->unk_7--;
      }
      break;
    }
    case 1: {
      if (data->unk_7 > 4) {
        FUN_08009278(data, 0);
      } else {
        FUN_08009278(data, 1);
        data->unk_7++;
      }
      break;
    }
    case 2: {
      data->unk_7 = 5;
      FUN_08009278(data, 0);
      break;
    }
  }
}

// プレイヤーが行動可能で、まだどのオブジェクトも選ばれていない時に TRUE
bool32 FUN_08009364(Entity83B2* p, Entity83B2Data* data) {
  Player* player = p->player;
  u32 mask = 0x186C;
  if ((player->unk_20 & mask) == 0 && player->unk_380[0] == 0 && p->unk_19 < 0) {
    return TRUE;
  }
  return FALSE;
}

// data の情報を引数5個に詰めてスクリプトを実行する
void FUN_08009398(Entity83B2* p, Entity83B2Data* data, s32 scriptID) {
  u32 argv[5];
  ScriptArgs args;
  s32 i;

  if (scriptID != 0) {
    argv[0] = data->unk_0;
    for (i = 0; i < 4; i++) {
      argv[i + 1] = (s16)data->unk_14[i];
    }
    args.argc = 5, args.argv = argv;
    Script_ExecById(scriptID, &args);
  }
}

s32 FUN_080093e0(Entity83B2* p, s32 n) {
  p->unk_19 = n;
  p->unk_1a = 0;
}

s32 FUN_080093ec(Entity83B2* p, s32 n) {
  p->unk_19 = n;
  p->unk_1a = 1;
}

// プレイヤーが範囲内かつ対象を向いていればインタラクト可能にする
s32 FUN_080093f8(Entity83B2* p, Entity83B2Data* data, s32 idx) {
  FUN_080091d0(data);
  if (p->player != NULL) {
    u32 mask = (1 << 2) | (1 << 1);
    u32 flags = u32_03002bc0;
    if (!(flags & mask) && (flags & (1 << 0))) {
      s32 dx = data->pos.x - p->pos.x;
      s32 dz = data->pos.z - p->pos.z;
      u32 dist2 = dx * dx + dz * dz;
      s32 dir = (((((u16)ArcTan2_8(dx, dz) + 0x10) & 0xFF) >> 5) + 3) & 7;
      if (dist2 < data->unk_10) {
        s32 a, b, c;
        if (data->unk_2 != 0) {
          a = 0, b = 1, c = 2;
        } else {
          a = 6, b = 7, c = 0;
        }
        if (a == dir || b == dir || c == dir) {
          s32 facing = ((p->player)->sprite_2e4).active;
          bool32 ok = TRUE;
          if (a != facing && b != facing && c != facing) {
            ok = FALSE;
          }
          if (ok) FUN_080091c4(data, 1);
        }
      }
    }
  }
  return 0;
}

// インタラクト可能な状態でAボタンが押されたらインタラクト中にする
s32 FUN_080094ac(Entity83B2* p, Entity83B2Data* data, s32 idx) {
  s32 dx, dz;
  u32 dist2;
  s32 dir;
  s32 facing;
  s32 a, b, c;
  u32 flags;
  u32 mask;
  bool32 ok;

  FUN_080091d0(data);
  if (p->player != NULL) {
    mask = 6;
    flags = u32_03002bc0;
    if (!(flags & mask) && (flags & 1)) {
      dx = data->pos.x - p->pos.x;
      dz = data->pos.z - p->pos.z;
      dist2 = dx * dx + dz * dz;
      dir = ((((u16)ArcTan2_8(dx, dz) + 0x10) & 0xFF) >> 5) + 3;
      dir &= 7;
      if (dist2 < data->unk_10) {
        if (data->unk_2 != 0) {
          a = 0, b = 1, c = 2;
        } else {
          a = 6, b = 7, c = 0;
        }
        if (a == dir || b == dir || c == dir) {
          facing = p->player->sprite_2e4.active;
          ok = TRUE;
          if (a != facing && b != facing && c != facing) {
            ok = FALSE;
          }
          if (ok) {
            if (!(gInput[0].pressed & A_BUTTON)) {
              return 0;
            }
            if (!FUN_08009364(p, data)) {
              return 0;
            }
            data->unk_7 = 5;
            FUN_08009278(data, 0);
            FUN_080091c4(data, 2);
            FUN_080093e0(p, idx);
            return 0;
          }
        }
      }
    }
  }
  FUN_080091c4(data, 0);
  return 0;
}

// FUN_080093f8 の逆で、範囲外か対象を向いていなければインタラクト不可に戻す
s32 FUN_0800959c(Entity83B2* p, Entity83B2Data* data, s32 idx) {
  s32 dx, dz;
  u32 dist2;
  s32 angle;
  s32 dir;
  s32 facing;
  s32 a, b, c;
  u32 flags;
  u32 mask;
  bool32 ok;

  FUN_080091d0(data);
  if (p->player != NULL) {
    mask = 6;
    flags = u32_03002bc0;
    if (!(flags & mask) && (flags & 1)) {
      dx = data->pos.x - p->pos.x;
      dz = data->pos.z - p->pos.z;
      dist2 = dx * dx + dz * dz;
      angle = ArcTan2_8(dx, dz);
      dir = ((((u16)angle + 0x10) & 0xFF) >> 5) + 3;
      dir &= 7;
      if (dist2 < data->unk_10) {
        if (data->unk_2 != 0) {
          a = 0, b = 1, c = 2;
        } else {
          a = 6, b = 7, c = 0;
        }
        if (a == dir || b == dir || c == dir) {
          facing = p->player->sprite_2e4.active;
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
  FUN_080091c4(data, 0);
  return 0;
}

s32 (*const PTR_ARRAY_085aa6ac[3])(Entity83B2*, Entity83B2Data*, s32) = {
    FUN_080093f8,
    FUN_080094ac,
    FUN_0800959c,
};  // 0x085aa6ac

NON_MATCH s32 Entity83B2_Update(Entity83B2* p) {
#ifdef NONMATCHING_C
  Entity83B2Data* data;
  s32 i;
  bool32 alive;

  if (p->player != NULL) {
    p->pos = p->player->unk_24.pos;
  }
  data = p->list;
  for (i = 0; i < p->length; i++, data++) {
    if (p->unk_1c & (1 << i)) {
      if (data->id_8 >= 0) {
        alive = IsCurrentObject(data->id_8);
        if (!alive) {
          if (data->unk_4 != 1) {
            data->sprite.flags |= SPRFLAG_HIDDEN;
          }
          continue;
        }
      }
      if (data->unk_4 != 1) {
        data->sprite.flags &= ~SPRFLAG_HIDDEN;
      }
      PTR_ARRAY_085aa6ac[data->state](p, data, i);
      FUN_080092f0(p, data);
    }
  }
  if (p->unk_1a >= 0 && p->unk_19 >= 0) {
    data = &p->list[p->unk_19];
    if (p->unk_1a == 0) {
      p->unk_1a = 0xFF;
      FUN_08009398(p, data, data->unk_c);
    } else if (p->unk_1a == 1) {
      p->unk_1a |= 0xFF;
      p->unk_19 |= 0xFF;
      FUN_08009398(p, data, data->unk_e);
    }
  }
  return 0;
#else
  INCFUNC("asm/func/Entity83B2_Update.inc");
#endif
}

NON_MATCH s32 Entity83B2_Destroy(Entity83B2* p) {
#ifdef NONMATCHING_C
  Entity83B2Data* data;
  s32 i;

  for (data = p->list, i = 0; i < p->length; i++, data++) {
    AuxSprite_Remove(&data->sprite);
  }
  if (p->list != NULL) {
    Free(p->list);
  }
  gEntity83B2 = NULL;
#else
  INCFUNC("asm/func/Entity83B2_Destroy.inc");
#endif
}

s32 Entity83B2_Init(Entity83B2* p, void* _) {
  Entity83B2Data* data;
  s32 i;

  gEntity83B2 = p;
  p->length = VM_GetKeywordValue('n', 1);
  p->unk_19 = 0xFF;
  p->unk_1a = -1;
  p->unk_1c = 0;
  p->list = Malloc(p->length * sizeof(Entity83B2Data));
  if (p->list == NULL) {
    return -1;
  }
  ClearMemory(p->list, p->length * sizeof(Entity83B2Data));
  data = p->list;
  for (i = 0; i < p->length; i++, data++) {
    if (FUN_080091e8(p, data, i) < 0) {
      return -1;
    }
  }
  p->player = gPlayerPtr[0];
  if (p->player != NULL) {
    p->pos = p->player->unk_24.pos;
  } else {
    p->pos.x = 0, p->pos.y = 0, p->pos.z = 0;
  }
  return 0;
}

Entity83B2* Entity83B2_Create(void* _) {
  if (gEntity83B2 == NULL) {
    Entity83B2* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity83B2));
    if (p != NULL) {
      SetEntityRoutine(p, Entity83B2_Update, Entity83B2_Destroy);
      if (Entity83B2_Init(p, _) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity83B2;
}

// マップ切り替わり時に (多分 Entity83B2 の数だけ)　呼ばれた (銀行に入ると3回呼ばれた, 多分 ヒントパネル1個 + ATM2個 で3回と思われる)
// マップ切り替え時に呼ばれ、スクリプトの keyword から list の各要素を作る
NON_MATCH s32 VM_Sub883A(void) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 kind;
  Entity83B2* p;
  Entity83B2Data* data;
  s32 i;
  s32 n;
  u16* arg;
  s32 scriptID;
  u32 v;
  AuxSprite* sprite;

  p = gEntity83B2;
  if (p == NULL) {
    return -1;
  }
  n = VM_GetKeywordValue('n', 0);
  data = p->list;
  for (i = 0; i < p->length; i++) {
    if (p->unk_1c & (1 << i)) {
      data += 0;
    } else {
      sprite = &data->sprite;
      data->unk_0 = n;
      data->unk_2 = VM_GetKeywordValue('d', 0);
      data->unk_3 = 0;
      data->unk_4 = VM_GetKeywordValue('t', 0);
      kind = VM_GetKeywordValue('m', 0);
      data->unk_c = VM_GetKeywordValue('b', 0);
      data->unk_e = VM_GetKeywordValue('e', 0);
      scriptID = VM_GetKeywordValue('D', 0xE6);
      data->unk_10 = scriptID * scriptID;
      if (VM_SeekToKeyword('a')) {
        arg = data->unk_14;
        do {
          if (VM_GetPC() != NULL) {
            v = Script_GetValue();
          }
          *arg = v;
          arg++;
        } while (arg <= &data->unk_14[3]);
      } else {
        arg = &data->unk_14[3];
        do {
          *arg = 0;
          arg--;
        } while (arg >= data->unk_14);
      }
      if (VM_SeekToKeyword('p')) {
        pos.x = Script_GetValue();
        pos.y = Script_GetValue();
        pos.z = Script_GetValue();
      } else {
        pos.x = 0, pos.y = 0, pos.z = 0;
      }
      FUN_08009298(p, data, &pos);
      if (kind != 0) {
        data->id_8 = GetMapAreaAt(&data->pos);
      } else {
        data->id_8 = -1;
      }
      FUN_08009278(data, 2);
      p->unk_1c |= 1 << i;
      break;
    }
    data++;
  }
  if (i == p->length) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/VM_Sub883A.inc");
#endif
}

// ヒントパネルを閉じると呼ばれる, ATMを終了しても呼ばれない
s32 VM_Sub2740(void) {
  Entity83B2* p = gEntity83B2;
  if (p == NULL || p->unk_19 < 0 || p->unk_19 >= p->length) {
    return -1;
  }
  FUN_080093ec(p, p->unk_19);
  FUN_080091c4(&p->list[p->unk_19], 0);
  return 0;
}

// スクリプトから対象の座標を設定し直す
s32 VM_Sub1F65(void) {
  Vec3 pos;
  Entity83B2Data* data;

  Entity83B2* p = gEntity83B2;
  if (p == NULL) {
    return -1;
  }
  data = FUN_0800922c(p, VM_GetKeywordValue('n', 0), NULL);
  if (data == NULL) {
    return -1;
  }
  if (VM_SeekToKeyword('p')) {
    pos.x = Script_GetValue();
    pos.y = Script_GetValue();
    pos.z = Script_GetValue();
  } else {
    pos.x = 0, pos.y = 0, pos.z = 0;
  }
  FUN_08009298(p, data, &pos);
  if (data->id_8 >= 0) {
    data->id_8 = GetMapAreaAt(&data->pos);
  }
}
