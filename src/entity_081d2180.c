#include "entity.h"
#include "global.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

typedef struct {
  AuxSprite sprite;        // 0x00
  u8 unk_2c[44];           // 0x2C
  ZoneID16 zoneID;         // 0x58, gStat->zoneID と一致しなければ要素を隠す
  u16 unk_5a;              // 0x5A, FUN_081d1bf8 の第2引数
  u8 unk_5c[0x7C - 0x5C];  // 0x5C
  u16 unk_7c;              // 0x7C, 枠を確保したときに自分の添字を入れる
  s16 state;               // 0x7E, _Update が PTR_FUN_081D1AE8_085AE0C8[state](item) を呼ぶ
  u16 flags;               // 0x80
  u16 unk_82;              // 0x82
  u16 unk_84;              // 0x84, FUN_081d1bf8 が 0 を入れる
  u16 unk_86;              // 0x86
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

static inline bool8 IsCurrentZone(u32 zoneID) {
  if (gStat->zoneID == zoneID) return TRUE;
  return FALSE;
}

static inline bool8 Entity081d2180_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

// 空いている枠を確保して返す, 空きが無ければ NULL
Entity081d2180Item* FUN_081d1a9c(Entity081d2180* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!Entity081d2180_IsActive(&p->activeMask, i)) {
      Entity081d2180Item* item = &p->items[i];

      p->activeMask |= 1 << i;
      item->unk_7c = i;
      return item;
    }
  }
  return NULL;
}

// state 0 のハンドラ, 何もしない
void FUN_081d1ae8(Entity081d2180Item* item) {}

// 現在のエリアの要素でなければ隠す
bool32 FUN_081d1aec(Entity081d2180Item* item) {
  if (IsCurrentZone(item->zoneID)) {
    AuxSprite_Show(&item->sprite);
    return TRUE;
  }
  AuxSprite_Hide(&item->sprite);
  return FALSE;
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
      PlaySound_082406e0(SONG_905);
    } else {
      PlaySound_082406e0(SONG_341);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d1bf8.inc");
#endif
}

NAKED void FUN_081d1c64(unknown* p) { INCFUNC("asm/func/FUN_081d1c64.inc"); }

NAKED void FUN_081d1cdc(Entity081d2180Item* item) { INCFUNC("asm/func/FUN_081d1cdc.inc"); }

NAKED void Cmd_AB8E(unknown* p) { INCFUNC("asm/func/Cmd_AB8E.inc"); }

void (*const PTR_ARRAY_085ae0c8[2])(Entity081d2180Item*) = {
    FUN_081d1ae8,
    FUN_081d1cdc,
};  // 0x085AE0C8

NAKED s32 Entity081d2180_Update(Entity081d2180* p) { INCFUNC("asm/func/Entity081d2180_Update.inc"); }

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

void FUN_081d21cc(void) { gEntity081d2180 = NULL; }
