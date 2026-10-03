#include "entity.h"
#include "global.h"
#include "mover.h"
#include "registry.h"
#include "sprite_aux.h"
#include "video.h"
#include "vm.h"

// slots の1要素, FUN_08002a00 が Mover の id を種別付きで登録する
typedef struct {
  u16 kind;  // 0x00, FUN_08002a48 なら 0、FUN_08002a58 なら 1、FUN_08002fdc なら '.m' の値
  u16 id;    // 0x02, Mover.id
} EntityE28BSlot;
static_assert(sizeof(EntityE28BSlot) == 4);

// entries の1要素, FUN_0800298c / FUN_080029cc が count 個を stride 8 で走査する
typedef struct {
  u16 unk_0;     // 0x00, FUN_080029cc が unk_2 の一致で 0 を書く
  u16 unk_2;     // 0x02, 検索キー
  Mover* mover;  // 0x04, Mover_FindByID_Proxy(unk_2) の戻り値
} EntityE28BEntry;
static_assert(sizeof(EntityE28BEntry) == 8);

// "mask_test_00" という名前を使うのでデバッグ用途の可能性がある
// サイズが可変で、'.n' の値 count に対して 152 * count + 144 バイトで確保される
// 144バイトのヘッダの後ろに entries[count] (8 * count) / sprites[spriteCount] (44 * 3count) / unk_8c[spriteCount] (4 * 3count) が並ぶ
typedef struct {
  Entity e;                    // 0x00, ENTITY_UNK_9
  u16 unk_18;                  // 0x18, EntityE28B_Create の第1引数
  u16 unk_1a;                  // 0x1A, EntityE28B_Create の第2引数
  u32 unk_1c;                  // 0x1C, _Init が 0 を書く
  s32 count;                   // 0x20, '.n' の値, 引数が無ければ 8
  s32 spriteCount;             // 0x24, count * 3
  u32 slotCount;               // 0x28, _Init が 0 を書く, slots の使用件数
  EntityE28BSlot slots[16];    // 0x2C, FUN_08002a00 が末尾に積む, 上限 16 件 (slotCount > 15 を弾く)
  AuxSpriteGfx gfx;            // 0x6C, '.m'、無ければ FUN_08230860("mask_test_00") の ID
  AuxSprite* sprites;          // 0x88, &entries[count] を指す
  u32* unk_8c;                 // 0x8C, sprites の後ろを指す
  EntityE28BEntry entries[1];  // 0x90, 実際は count 個 (可変長)
} EntityE28B;

u16 FUN_08230860(const char* s);

const ALIGNED(4) char s_mask_test_00[] = "mask_test_00";  // 0x08251B2C

// 空いている entries の要素に id の Mover を結びつける
void FUN_0800298c(EntityE28B* p, u16 id) {
  EntityE28BEntry* e = p->entries;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (e->unk_0 == 0) {
      break;
    }
    e++;
  }

  if (i == p->count) {
    return;
  }

  e->mover = Mover_FindByID_Proxy(id);
  if (e->mover == NULL) {
    return;
  }

  e->unk_0 = 1;
  e->unk_2 = id;
}

// id が一致する entries の要素を丸ごと 0 に戻す
void FUN_080029cc(EntityE28B* p, u16 id) {
  EntityE28BEntry* e = p->entries;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (e->unk_2 == id) {
      e->unk_0 = 0;
      e->mover = NULL;
      e->unk_2 = 0;
      return;
    }
    e++;
  }
}

// 種別付きで Mover の id を slots の末尾に積む, 満杯か未生成なら -1
NON_MATCH s32 FUN_08002a00(s32 kind, s32 id) {
#ifdef NONMATCHING_C
  EntityE28B* p = Registry_Find(0x7BE3);

  if (p == NULL) {
    return -1;
  }

  if (p->slotCount > 15) {
    return -1;
  }

  p->slots[p->slotCount].kind = kind;
  p->slots[p->slotCount].id = id;
  p->slotCount++;
  return 0;
#else
  INCFUNC("asm/func/FUN_08002a00.inc");
#endif
}

s32 FUN_08002a48(Mover* p) { return FUN_08002a00(0, p->id); }

s32 FUN_08002a58(Mover* p) { return FUN_08002a00(1, p->id); }

NAKED s32 EntityE28B_Update(EntityE28B* p) { INCFUNC("asm/func/EntityE28B_Update.inc"); }

s32 EntityE28B_Destroy(EntityE28B* p) {
  s32 i;

  for (i = 0; i < p->spriteCount; i++) {
    if (p->sprites[i].active) {
      AuxSprite_Remove(&p->sprites[i]);
    }
  }

  return 0;
}

NON_MATCH s32 EntityE28B_Init(EntityE28B* p, u16 param_2, u16 param_3) {
#ifdef NONMATCHING_C
  s32 spriteID;
  s32 i;

  p->unk_18 = param_2;
  p->unk_1a = param_3;
  p->unk_1c = 0;
  p->slotCount = 0;

  if (VM_SeekToNamedArg('m')) {
    spriteID = VM_GetValue();
  } else {
    spriteID = FUN_08230860(s_mask_test_00);
  }

  if (!Video_GetAuxSprite(&p->gfx, spriteID)) {
    return -1;
  }

  for (i = 0; i < p->spriteCount; i++) {
    AuxSprite_Setup(&p->sprites[i], &p->gfx, 1);
    p->sprites[i].oamAttr |= OAM0_SEMI_TRANSPARENT;
  }

  Video_SetBLDCNTDirect(2, 0xC, 0x2C);
  Video_SetBLDALPHADirect(0, 0x10);
  Registry_Add(0x7BE3, p, 0);
  return 0;
#else
  INCFUNC("asm/func/EntityE28B_Init.inc");
#endif
}

EntityE28B* EntityE28B_Create(u16 param_1, u16 param_2) {
  s32 count = VM_SeekToNamedArg('n') ? VM_GetValue() : 8;
  s32 spritesSize = count * 132;
  s32 spritesOffset = count * 8 + 0x90;
  s32 size = spritesSize + spritesOffset;
  s32 spriteCount = count * 3;
  EntityE28B* p = CreateEntity(ENTITY_UNK_9, size + spriteCount * 4);

  if (p != NULL) {
    SetEntityRoutine(p, EntityE28B_Update, EntityE28B_Destroy);
    p->sprites = (AuxSprite*)((u8*)p + spritesOffset);
    p->unk_8c = (u32*)((u8*)p->sprites + spritesSize);
    p->count = count;
    p->spriteCount = spriteCount;
    if (EntityE28B_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

// '.m' の種別で '.n' の Mover を slots に登録する
s32 FUN_08002fdc(void) {
  s32 kind = VM_GetNamedArgValue('m', 0);
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id == 0) {
    return -1;
  }

  return FUN_08002a00(kind, id);
}
