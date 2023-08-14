#include "global.h"

// Affineスプライトかな..？

#define ACTIVE (1 << 7)

struct Unk_0203b000* CreateUnkStruct_08230d30(void) {
  s32 i;
  struct Unk_0203b000* p = &gUnk_0203b000[0];
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

struct Unk_0203b000* FindUnkStruct_08230d74(u16 id) {
  s32 i;
  struct Unk_0203b000* p = &gUnk_0203b000[0];
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

NAKED void FUN_08230dc4(bool32 r0) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	movs r6, #0\n\
	ldr r4, _08230DF8 @ =0x0203B000\n\
	movs r5, #0\n\
	ldr r0, _08230DFC @ =0x03004590\n\
	ldr r1, [r0]\n\
	adds r3, r0, #0\n\
	cmp r6, r1\n\
	bge _08230E22\n\
_08230DD8:\n\
	ldrb r1, [r4, #2]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08230E18\n\
	movs r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08230E00\n\
	adds r0, r7, #0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _08230E00\n\
	adds r6, r5, #0\n\
	b _08230E18\n\
	.align 2, 0\n\
_08230DF8: .4byte 0x0203B000\n\
_08230DFC: .4byte 0x03004590\n\
_08230E00:\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08230E0E\n\
	ldr r0, [r4, #4]\n\
	bl FUN_0823092c\n\
_08230E0E:\n\
	movs r1, #0\n\
	movs r0, #0\n\
	strh r0, [r4]\n\
	strb r1, [r4, #2]\n\
	ldr r3, _08230E2C @ =0x03004590\n\
_08230E18:\n\
	adds r5, #1\n\
	adds r4, #8\n\
	ldr r0, [r3]\n\
	cmp r5, r0\n\
	blt _08230DD8\n\
_08230E22:\n\
	adds r0, r6, #1\n\
	str r0, [r3]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08230E2C: .4byte 0x03004590\n\
 .syntax divided\n");
}

void FUN_08230e30(u16 id, void* r1, s32 r2) {
  struct Unk_0203b000* p = CreateUnkStruct_08230d30();
  if (p != NULL) {
    p->id = id;
    p->unk_04 = r1;
    p->unk_02 = ACTIVE | r2;
  }
}

void FUN_08230e58(u16 id) {
  struct Unk_0203b000* p = FindUnkStruct_08230d74(id);
  if (p != NULL) {
    p->unk_02 = 0;
  }
}

void* FUN_08230e70(u16 id) {
  struct Unk_0203b000* p = FindUnkStruct_08230d74(id);
  if (p == NULL) {
    return NULL;
  } else {
    return p->unk_04;
  }
}

u32* FUN_08230e88(void) { return u32_ARRAY_0203f400; }

#undef ACTIVE
