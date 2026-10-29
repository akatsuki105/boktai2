#include "entity.h"
#include "global.h"
#include "vm.h"

typedef struct {
  u16 unk_0;  // 0x00
  u8 unk_2[2];
  u16 unk_4;  // 0x04
  u8 unk_6[16 - 0x06];
} Entity794CData;
static_assert(sizeof(Entity794CData) == 16);

typedef struct {
  Entity e;                // 0x00, ENTITY_UNK_5
  u8 unk_18[0x20 - 0x18];  // 0x18
  Entity794CData data[7];  // 0x20, FUN_08240b44 は 0xA0 まで8個ぶんまわるので最後の1個は slots[0..1] と重なる
  u8 unk_90[0x98 - 0x90];  // 0x90
  u32 slots[16];           // 0x98, FUN_08240f20 が線形探索し Cmd_79EC が全部 0 に戻す
} Entity794C;
static_assert(sizeof(Entity794C) == 216);

static Entity794C* sEntity794C;  // 0x03001700

// 2点が size1 + size2 の正方範囲に収まっているか
bool32 BoxesOverlap(s32 x1, s32 y1, s32 size1, s32 x2, s32 y2, s32 size2) {
  s32 dx = abs(x1 - x2);
  s32 dy = abs(y1 - y2);
  s32 limit = size1 + size2;
  if (dx < limit && dy < limit) {
    return TRUE;
  }
  return FALSE;
}

NAKED bool8 FUN_08240b00(Vec3* pos) { INCFUNC("asm/func/FUN_08240b00.inc"); }

NAKED void FUN_08240b44(void) { INCFUNC("asm/func/FUN_08240b44.inc"); }

NAKED u16 FUN_08240b98(Vec3* out, u8 idx) { INCFUNC("asm/func/FUN_08240b98.inc"); }

NAKED void FUN_08240bcc(u16 x, u16 z, u16 param_3, u16 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_08240bcc.inc"); }

NAKED void FUN_08240c9c(s16 x, s16 z, s16 param_3, s16 param_4) { INCFUNC("asm/func/FUN_08240c9c.inc"); }

NAKED void FUN_08240cc4(s16 x, s16 z, s16 param_3, s16 param_4, u8 param_5) { INCFUNC("asm/func/FUN_08240cc4.inc"); }

NAKED void FUN_08240cf0(s16 x, s16 z, s16 param_3, s16 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_08240cf0.inc"); }

NAKED s8 FUN_08240d20(s32 x, s32 y, s32 size, u8 mask, u16 param_5, s32 start) { INCFUNC("asm/func/FUN_08240d20.inc"); }

NAKED s8 FUN_08240dc8(s32 x, s32 y, s32 size, u8 mask, u16 param_5) { INCFUNC("asm/func/FUN_08240dc8.inc"); }

NAKED s8 FUN_08240dec(s32 x, s32 y, s32 size, u8 mask, u16 param_5, s32 start) { INCFUNC("asm/func/FUN_08240dec.inc"); }

s32 Entity794C_Update(Entity794C* p) {
  FUN_08240b44();
  return 1;
}

s32 Entity794C_Destroy(Entity794C* p) { sEntity794C = NULL; }

NAKED s32 Entity794C_Init(Entity794C* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/Entity794C_Init.inc"); }

NAKED Entity794C* Entity794C_Create(u32 param_1, u32 param_2) { INCFUNC("asm/func/Entity794C_Create.inc"); }

NAKED void Cmd_1693(void) { INCFUNC("asm/func/Cmd_1693.inc"); }

NAKED s32 FUN_08240f20(Entity794C* p, u32 val) { INCFUNC("asm/func/FUN_08240f20.inc"); }

// '.a' の値を空き枠に積む
void Cmd_1422(void) {
  Entity794C* p = sEntity794C;

  if (p == NULL) {
    return;
  }
  if (!VM_SeekToNamedArg('a')) {
    return;
  }

  while (VM_GetPC() != NULL) {
    u32 val = VM_GetValue();
    s32 idx = FUN_08240f20(p, val);

    if (idx < 0) {
      p->slots[-idx] = val;
    }
  }
}

// '.a' の値が入っている枠を空ける
void Cmd_ADB6(void) {
  Entity794C* p = sEntity794C;

  if (p == NULL) {
    return;
  }
  if (!VM_SeekToNamedArg('a')) {
    return;
  }

  while (VM_GetPC() != NULL) {
    s32 idx = FUN_08240f20(p, VM_GetValue());

    if (idx >= 0) {
      p->slots[idx] = 0;
    }
  }
}

// 枠を全部空ける
void Cmd_79EC(void) {
  Entity794C* p = sEntity794C;
  s32 i;

  if (p == NULL) {
    return;
  }

  for (i = 0; i < 16; i++) {
    p->slots[i] = 0;
  }
}

void FUN_08241000(void) { sEntity794C = NULL; }
