#include "entity.h"
#include "global.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

typedef struct {
  AuxSprite sprite;  // 0x00
  u8 unk_2c[44];     // 0x2C
  u16 unk_58;        // 0x58, gStat->unk_248 と一致しなければ要素を隠す
  u16 unk_5a;        // 0x5A, FUN_081d1bf8 の第2引数
  u8 unk_5c[34];     // 0x5C
  s16 state;         // 0x7E, _Update が PTR_FUN_081D1AE8_085AE0C8[state](item) を呼ぶ
  u16 flags;         // 0x80
  u16 unk_82;        // 0x82
  u16 unk_84;        // 0x84, FUN_081d1bf8 が 0 を入れる
  u16 unk_86;        // 0x86
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

NAKED s32 FUN_081d1a9c(unknown* p) { INCFUNC("asm/func/FUN_081d1a9c.inc"); }

// state 0 のハンドラ, 何もしない
void FUN_081d1ae8(Entity081d2180Item* item) {}

// 現在のエリアの要素でなければ隠す
NON_MATCH bool32 FUN_081d1aec(Entity081d2180Item* item) {
#ifdef NONMATCHING_C
  if (gStat->unk_248 == item->unk_58) {
    AuxSprite_Show(&item->sprite);
    return TRUE;
  }
  AuxSprite_Hide(&item->sprite);
  return FALSE;
#else
  INCFUNC("asm/func/FUN_081d1aec.inc");
#endif
}

NAKED void FUN_081d1b34(unknown* p) { INCFUNC("asm/func/FUN_081d1b34.inc"); }

NON_MATCH void FUN_081d1bf8(Entity081d2180Item* item, s32 param_2) {
#ifdef NONMATCHING_C
  item->unk_5a = param_2;
  if (item->flags & 1) {
    item->flags = (item->flags | 2) & ~1;
    item->unk_84 = 0;
    FUN_081d1b34(item);
    AuxSprite_SetPoseIdx(&item->sprite, 1);
    Video_SetAuxSpritePltt(item->sprite.gfx, 288);
    if (item->flags & 4) {
      PlaySound_082406e0(0x389);
    } else {
      PlaySound_082406e0(0x155);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d1bf8.inc");
#endif
}

NAKED void FUN_081d1c64(unknown* p) { INCFUNC("asm/func/FUN_081d1c64.inc"); }

NAKED void FUN_081d1cdc(Entity081d2180Item* item) { INCFUNC("asm/func/FUN_081d1cdc.inc"); }

NAKED void FUN_081d1dec(unknown* p) { INCFUNC("asm/func/FUN_081d1dec.inc"); }

void (*const PTR_ARRAY_085ae0c8[2])(Entity081d2180Item*) = {
    FUN_081d1ae8,
    FUN_081d1cdc,
};  // 0x085AE0C8

NAKED s32 Entity081d2180_Update(Entity081d2180* p) { INCFUNC("asm/func/Entity081d2180_Update.inc"); }

NON_MATCH s32 Entity081d2180_Destroy(Entity081d2180* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 8; i++) {
    if (p->activeMask & (1 << i)) {
      AuxSprite_Remove(&p->items[i].sprite);
    }
  }
  gEntity081d2180 = NULL;
  return 0;
#else
  INCFUNC("asm/func/Entity081d2180_Destroy.inc");
#endif
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

void FUN_081d21cc(void) { gEntity081d2180 = NULL; }
