#include "global.h"

// Affineスプライトかな..？

#define ACTIVE (1 << 7)

Unk_0203b000* CreateUnkStruct_08230d30(void) {
  s32 i;
  Unk_0203b000* p = &gUnk_0203b000[0];
  for (i = 0; i < gCount_Unk_0203b000; i++, p++) {
    if (!(p->unk_02 & ACTIVE)) {
      return p;
    }
  }

  gCount_Unk_0203b000++;
  if (gCount_Unk_0203b000 > 31) {
    return NULL;
  }
  return p;
}

Unk_0203b000* FindUnkStruct_08230d74(u16 id) {
  s32 i;
  Unk_0203b000* p = &gUnk_0203b000[0];
  for (i = 0; i < gCount_Unk_0203b000; i++, p++) {
    if ((p->unk_02 & ACTIVE) && (p->id == id)) {
      return p;
    }
  }
  return NULL;
}

void FUN_08230db8(void) {
  gCount_Unk_0203b000 = 0;
  return;
}

NAKED void FUN_08230dc4(bool32 val) { INCFUNC("asm/func/FUN_08230dc4.inc"); }

void FUN_08230e30(u16 id, void* r1, s32 r2) {
  Unk_0203b000* p = CreateUnkStruct_08230d30();
  if (p != NULL) {
    p->id = id;
    p->unk_04 = r1;
    p->unk_02 = ACTIVE | r2;
  }
}

void FUN_08230e58(u16 id) {
  Unk_0203b000* p = FindUnkStruct_08230d74(id);
  if (p != NULL) {
    p->unk_02 = 0;
  }
}

void* FUN_08230e70(u16 id) {
  Unk_0203b000* p = FindUnkStruct_08230d74(id);
  if (p == NULL) {
    return NULL;
  } else {
    return p->unk_04;
  }
}

u32* FUN_08230e88(void) { return u32_ARRAY_0203f400; }

NAKED void FUN_08230e90(void) { INCFUNC("asm/func/FUN_08230e90.inc"); }

NAKED void FUN_08230eb4(void) { INCFUNC("asm/func/FUN_08230eb4.inc"); }

NAKED void FUN_08230eec(UNK_PTR p) { INCFUNC("asm/func/FUN_08230eec.inc"); }

NAKED UNK_PTR FUN_08230f94(UNK_PTR a, UNK_PTR b) { INCFUNC("asm/func/FUN_08230f94.inc"); }

#undef ACTIVE
