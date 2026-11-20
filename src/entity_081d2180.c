#include "entity.h"
#include "global.h"
#include "mover.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

// Entity081d2180Item.flags (0x80)
#define FLOORSW_RELEASED (1 << 0)   // 0x1, 上がっている
#define FLOORSW_PRESSED (1 << 1)    // 0x2, 踏まれて下がっている
#define FLOORSW_ALT_SOUND (1 << 2)  // 0x4, '.f' で立つ, 上げ下げの音を SONG_905 にする

// 踏むと下がる床スイッチ1個, 上に Mover が乗ると下がって pressScriptID を, 離れて holdDuration フレーム経つと上がって releaseScriptID を実行する
typedef struct {
  AuxSprite sprite;     // 0x00, poseIdx 0 が上がった絵, 1 が下がった絵
  AuxSpriteGfx gfx;     // 0x2C, spriteID
  u16 id;               // 0x48, '.n', スクリプトの第1引数
  u16 spriteID;         // 0x4A, '.T'
  u16 pressScriptID;    // 0x4C, '.R[0]', 下がったときに実行する
  u16 releaseScriptID;  // 0x4E, '.R[1]', 上がったときに実行する
  u8 unk_50[8];         // 0x50
  ZoneID16 zoneID;      // 0x58, 置いた位置のゾーン, gStat->zoneID と一致しなければ隠して止める
  u16 presserID;        // 0x5A, 踏んでいる Mover の id, スクリプトの第10引数, 上がると 0
  u32 scriptArgs[8];    // 0x5C, '.S' 4個と '.W' 4個, スクリプトの第2-9引数
  u16 slotIdx;          // 0x7C, items の添字
  s16 state;            // 0x7E, sEntity081d2180ItemStates の添字
  u16 flags;            // 0x80, FLOORSW_*, '.f' の値も OR される
  u8 unk_82;            // 0x82, 生成時と state 1 の毎フレームで 0 を書くだけ
  u8 unk_83;            // 0x83, 生成時に 0 を書くだけ
  u16 holdTimer;        // 0x84, 下がっている間のフレーム数, holdDuration に届くと離れたときに上がる
  u16 holdDuration;     // 0x86, '.d', 離れてから上がるまで待つフレーム数
} Entity081d2180Item;
static_assert(sizeof(Entity081d2180Item) == 136);

// 最大8個の Entity081d2180Item をビットマスクで管理するシングルトン
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  Entity081d2180Item items[8];  // 0x018
  u32 activeMask;               // 0x458, bit i が立っていれば items[i] が使用中, _Init が 0 にする
} Entity081d2180;
static_assert(sizeof(Entity081d2180) == 1116);

IWRAM_DATA Entity081d2180* gEntity081d2180 = NULL;  // 0x03000190

Entity081d2180* Entity081d2180_Create(void);

static inline bool8 IsCurrentZone(u32 zoneID) {
  if (gStat->zoneID == zoneID) return TRUE;
  return FALSE;
}

static inline bool8 Entity081d2180_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

// 空いている枠を確保して返す, 空きが無ければ NULL
Entity081d2180Item* Entity081d2180_AllocItem(Entity081d2180* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!Entity081d2180_IsActive(&p->activeMask, i)) {
      Entity081d2180Item* item = &p->items[i];

      p->activeMask |= 1 << i;
      item->slotIdx = i;
      return item;
    }
  }
  return NULL;
}

// state 0 のハンドラ, 何もしない
void Entity081d2180Item_StateIdle(Entity081d2180Item* item) {}

// 現在のエリアの要素でなければ隠す
bool8 Entity081d2180Item_UpdateVisible(Entity081d2180Item* item) {
  if (IsCurrentZone(item->zoneID)) {
    AuxSprite_Show(&item->sprite);
    return TRUE;
  }
  AuxSprite_Hide(&item->sprite);
  return FALSE;
}

// 下がったなら pressScriptID, 上がったなら releaseScriptID を id, scriptArgs, presserID を引数にして実行する
void Entity081d2180Item_RunScript(Entity081d2180Item* item) {
  u32 args[10];
  ScriptArgs sa;

  if (item->flags & FLOORSW_PRESSED) {
    if (item->pressScriptID != 0) {
      args[0] = item->id;
      args[1] = item->scriptArgs[0];
      args[2] = item->scriptArgs[1];
      args[3] = item->scriptArgs[2];
      args[4] = item->scriptArgs[3];
      args[5] = item->scriptArgs[4];
      args[6] = item->scriptArgs[5];
      args[7] = item->scriptArgs[6];
      args[8] = item->scriptArgs[7];
      args[9] = item->presserID;
      sa.argc = 10;
      sa.argv = args;
      VM_ExecByID(item->pressScriptID, &sa);
    }
  } else if (item->flags & FLOORSW_RELEASED) {
    if (item->releaseScriptID != 0) {
      args[0] = item->id;
      args[1] = item->scriptArgs[0];
      args[2] = item->scriptArgs[1];
      args[3] = item->scriptArgs[2];
      args[4] = item->scriptArgs[3];
      args[5] = item->scriptArgs[4];
      args[6] = item->scriptArgs[5];
      args[7] = item->scriptArgs[6];
      args[8] = item->scriptArgs[7];
      args[9] = item->presserID;
      sa.argc = 10;
      sa.argv = args;
      VM_ExecByID(item->releaseScriptID, &sa);
    }
  }
}

// 上がっていれば下げて pressScriptID を実行し, 絵と色を下がった状態にして音を鳴らす
void Entity081d2180Item_Press(Entity081d2180Item* item, s32 presserID) {
  item->presserID = presserID;
  if (item->flags & FLOORSW_RELEASED) {
    item->flags |= FLOORSW_PRESSED;
    item->flags &= ~FLOORSW_RELEASED;
    item->holdTimer = 0;
    Entity081d2180Item_RunScript(item);
    AuxSprite_SetPoseIdx(&item->sprite, 1);
    Video_SetAuxSpritePltt(item->sprite.gfx, 288);
    if (item->flags & FLOORSW_ALT_SOUND) {
      PlaySound_082406e0(SONG_905);
    } else {
      PlaySound_082406e0(SONG_341);
    }
  }
}

// 下がっていれば上げて releaseScriptID を実行し, 絵と色を戻して通信中でなければ音を鳴らす
void Entity081d2180Item_Release(Entity081d2180Item* item) {
  if (item->flags & FLOORSW_PRESSED) {
    item->flags |= FLOORSW_RELEASED;
    item->flags &= ~FLOORSW_PRESSED;
    Entity081d2180Item_RunScript(item);
    AuxSprite_SetPoseIdx(&item->sprite, 0);
    Video_SetAuxSpritePltt(item->sprite.gfx, 287);
    if (!(gGameFlags & GAMEFLAG_LINK)) {
      if (item->flags & FLOORSW_ALT_SOUND) {
        PlaySound_082406e0(SONG_905);
      } else {
        PlaySound_082406e0(SONG_341);
      }
    }
    item->presserID = 0;
  }
}

// state 1, 上に Mover が乗っていれば下げて holdTimer を進め, 誰も乗っていなければ holdTimer が holdDuration に届いたところで上げる
void Entity081d2180Item_StateActive(Entity081d2180Item* item) {
  MoverList* list = MoverList_Get();
  bool32 pressed;
  Mover* m;
  Vec3 d;

  if (list == NULL) {
    return;
  }
  pressed = FALSE;
  if (item->unk_82) {
    item->unk_82 = 0;
  }
  for (m = list->head; m != NULL; m = m->next) {
    if (m->flags & 2) {
      continue;
    }
    if (!(gGameFlags & GAMEFLAG_LINK) && m->kind == 0) {
      if (gPlayerPtr[0] == NULL || gPlayerPtr[0]->kind == PLAYER_BAT) {
        continue;
      }
    }
    Vec3_Diff(&d, &m->pos, &item->sprite.pos);
    if (d.x >= 0 && d.x <= 256 && d.y <= 32 && d.y >= 0 && d.z <= 256 && d.z >= 0) {
      Entity081d2180Item_Press(item, m->id);
      if (item->holdTimer < item->holdDuration - 1) {
        item->holdTimer++;
      }
      pressed = TRUE;
      break;
    }
  }
  if (!pressed) {
    if (item->holdTimer >= item->holdDuration) {
      Entity081d2180Item_Release(item);
    } else {
      item->holdTimer++;
    }
  }
}

// 0xAB8E, 床スイッチを1つ置く, '.s' なら下がった状態で始め, 置いた時点で上に Mover が乗っていても下げる
// 残差は 312 対 312 命令 (ハンク29), 原典は乗っている Mover を見つけたときの処理をループの前に置き, m->flags & 2 の u16 値を ip に残して holdTimer = 0 に使う
// 見つけた処理をループ内で break / ループ後の m != NULL / while で書く形, TEST_FLAGS の有無, sprite ローカルの使い分けは試済
NON_MATCH void Cmd_AddFloorSwitch(void) {
#ifdef NONMATCHING_C
  Entity081d2180* p = gEntity081d2180;
  Entity081d2180Item* item;
  AuxSprite* sprite;
  u32* dst;
  s32 flags;
  s32 i;

  if (p == NULL) {
    p = Entity081d2180_Create();
    if (p == NULL) {
      return;
    }
  }
  item = Entity081d2180_AllocItem(p);
  if (item == NULL) {
    return;
  }
  item->state = 1;
  sprite = &item->sprite;
  if (VM_SeekToNamedArg('p')) {
    item->sprite.pos.x = VM_GetValue();
    item->sprite.pos.y = VM_GetValue();
    item->sprite.pos.z = VM_GetValue();
  }
  item->id = VM_GetNamedArgValue('n', 0);
  if (VM_SeekToNamedArg('R')) {
    item->pressScriptID = (VM_GetPC() != NULL) ? VM_GetValue() : 0;
    item->releaseScriptID = (VM_GetPC() != NULL) ? VM_GetValue() : 0;
  }
  if (VM_SeekToNamedArg('S')) {
    dst = &item->scriptArgs[0];
    for (i = 0; i < 4; i++) {
      *dst = (VM_GetPC() != NULL) ? VM_GetValue() : 0;
      dst++;
    }
  }
  if (VM_SeekToNamedArg('W')) {
    dst = &item->scriptArgs[4];
    for (i = 0; i < 4; i++) {
      *dst = (VM_GetPC() != NULL) ? VM_GetValue() : 0;
      dst++;
    }
  }
  item->spriteID = VM_GetNamedArgValue('T', 0);
  Video_GetAuxSprite(&item->gfx, item->spriteID);
  item->flags = 0;
  if (VM_GetNamedArgValue('s', 0) == 0) {
    item->flags |= FLOORSW_RELEASED;
  } else {
    item->flags |= FLOORSW_PRESSED;
  }
  flags = VM_GetNamedArgValue('f', 0);
  if (flags != 0) {
    item->flags |= flags;
  }
  AuxSprite_Add(sprite, &item->gfx, 0);
  if (item->flags & FLOORSW_PRESSED) {
    AuxSprite_SetPoseIdx(sprite, 1);
    Video_SetAuxSpritePltt(item->sprite.gfx, 288);
  } else {
    AuxSprite_SetPoseIdx(sprite, 0);
    Video_SetAuxSpritePltt(item->sprite.gfx, 287);
  }
  if (MoverList_Get() != NULL) {
    Mover* m;

    for (m = MoverList_Get()->head; m != NULL; m = m->next) {
      Vec3 d;

      if (m->flags & 2) {
        continue;
      }
      Vec3_Diff(&d, &m->pos, &item->sprite.pos);
      if (d.x >= 0 && d.x <= 256 && d.y <= 32 && d.y >= 0 && d.z <= 256 && d.z >= 0) {
        break;
      }
    }
    if (m != NULL) {
      item->presserID = m->id;
      item->flags |= FLOORSW_PRESSED;
      item->flags &= ~FLOORSW_RELEASED;
      item->holdTimer = 0;
      AuxSprite_SetPoseIdx(sprite, 1);
      Video_SetAuxSpritePltt(item->sprite.gfx, 288);
    }
  }
  item->holdDuration = VM_GetNamedArgValue('d', 0);
  item->holdTimer = 0;
  item->zoneID = GetZoneAt(&sprite->pos);
  if (IsCurrentZone(item->zoneID)) {
    AuxSprite_Show(sprite);
  } else {
    AuxSprite_Hide(sprite);
  }
  item->unk_83 = 0;
  item->unk_82 = 0;
#else
  INCFUNC("asm/func/Cmd_AddFloorSwitch.inc");
#endif
}

void (*const sEntity081d2180ItemStates[2])(Entity081d2180Item*) = {
    Entity081d2180Item_StateIdle,
    Entity081d2180Item_StateActive,
};  // 0x085AE0C8

// 使用中のスイッチのうち今いるゾーンのものだけ state ごとに動かす
s32 Entity081d2180_Update(Entity081d2180* p) {
  Entity081d2180Item* items = p->items;
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  for (i = 0; i < 8; i++) {
    if (Entity081d2180_IsActive(&p->activeMask, i) && Entity081d2180Item_UpdateVisible(&items[i])) {
      sEntity081d2180ItemStates[items[i].state](&items[i]);
    }
  }
  return 0;
}

s32 Entity081d2180_Destroy(Entity081d2180* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (Entity081d2180_IsActive(&p->activeMask, i)) {
      AuxSprite_Remove(&p->items[i].sprite);
    }
  }
  gEntity081d2180 = NULL;
  return 0;
}

s32 Entity081d2180_Init(Entity081d2180* p) {
  gEntity081d2180 = p;
  p->activeMask = 0;
  return 0;
}

Entity081d2180* Entity081d2180_Create(void) {
  Entity081d2180* p;

  if (gEntity081d2180 != NULL) {
    return gEntity081d2180;
  }
  p = CreateEntity(ENTITY_UNK_8, sizeof(Entity081d2180));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081d2180_Update, Entity081d2180_Destroy);
    if (Entity081d2180_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081d2180_ClearGlobal(void) { gEntity081d2180 = NULL; }
