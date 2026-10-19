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
  u32 slots[16];           // 0x98, FUN_08240f20 が線形探索し FUN_08240fdc が全部 0 に戻す
} Entity794C;
static_assert(sizeof(Entity794C) == 216);

static Entity794C* sEntity794C;  // 0x03001700

// 2点が size1 + size2 の正方範囲に収まっているか
bool32 BoxesOverlap(s32 x1, s32 y1, s32 size1, s32 x2, s32 y2, s32 size2) {
  s32 dx, dy, limit;

  dx = x1 - x2;
  if (dx < 0) {
    dx = -dx;
  }

  dy = y1 - y2;
  if (dy < 0) {
    dy = -dy;
  }

  limit = size1 + size2;
  if (dx < limit && dy < limit) {
    return TRUE;
  }

  return FALSE;
}

s32 FUN_08240f20(Entity794C* p, u32 val);

INCASM("asm/entity_794c.inc");

// '.a' の値を空き枠に積む
void FUN_08240f4c(void) {
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
void FUN_08240f94(void) {
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
void FUN_08240fdc(void) {
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
