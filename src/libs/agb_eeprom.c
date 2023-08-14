#include "gba/gba.h"

// Copy from https://github.com/jiangzhengwenjz/csm3/blob/main/src/agb_eeprom.c

extern struct EEPROMConfig gEEPROMConfig;
extern struct EEPROMConfig gEEPROMConfig512;
extern struct EEPROMConfig gEEPROMConfig8k;

u16 EEPROMConfigure(u16 unk_1) {
  u16 ret;

  ret = 0;
  if (unk_1 == 4) {
    gEEPROMConfig.unk_00 = &gEEPROMConfig512;
  } else {
    if (unk_1 == 0x40) {
      gEEPROMConfig.unk_00 = &gEEPROMConfig8k;
    } else {
      gEEPROMConfig.unk_00 = &gEEPROMConfig512;
      ret = 1;
    }
  }
  return ret;
}

void DMA3Transfer(const void* src, void* dest, u16 count) {
  struct EEPROMConfig* config;
  u32 temp;

  u16 IME_save;

  IME_save = REG_IME;
  REG_IME = 0;  // disable all interrupts
  temp = REG_WAITCNT & 0xF8FF;
  config = gEEPROMConfig.unk_00;
  temp |= config->waitcnt;  // configure wait state 2
  REG_WAITCNT = temp;
  REG_DMA3SAD = (u32)src;
  REG_DMA3DAD = (u32)dest;
  REG_DMA3CNT = count | 0x80000000;  // enable dma
  while ((REG_DMA3CNT_H & 0x8000) != 0) {
  }  // wait for dma to finish
  REG_IME = IME_save;
}

NAKED u16 EEPROMRead(u16 address, u16* data) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #0x88\n\
	adds r5, r1, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	ldr r0, _0824C2F4 @ =gEEPROMConfig\n\
	ldr r0, [r0]\n\
	ldrh r0, [r0, #4]\n\
	cmp r3, r0\n\
	blo _0824C2FC\n\
	ldr r0, _0824C2F8 @ =0x000080FF\n\
	b _0824C37E\n\
	.align 2, 0\n\
_0824C2F4: .4byte gEEPROMConfig\n\
_0824C2F8: .4byte 0x000080FF\n\
_0824C2FC:\n\
	ldr r0, _0824C388 @ =gEEPROMConfig\n\
	adds r6, r0, #0\n\
	ldr r0, [r0]\n\
	ldrb r1, [r0, #8]\n\
	lsls r0, r1, #1\n\
	mov r4, sp\n\
	adds r2, r0, r4\n\
	adds r2, #2\n\
	movs r4, #0\n\
	cmp r4, r1\n\
	bhs _0824C326\n\
_0824C312:\n\
	strh r3, [r2]\n\
	subs r2, #2\n\
	lsrs r3, r3, #1\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	ldr r0, [r6]\n\
	ldrb r0, [r0, #8]\n\
	cmp r4, r0\n\
	blo _0824C312\n\
_0824C326:\n\
	movs r0, #1\n\
	strh r0, [r2]\n\
	subs r2, #2\n\
	strh r0, [r2]\n\
	movs r4, #0xd0\n\
	lsls r4, r4, #0x14\n\
	ldr r0, _0824C388 @ =gEEPROMConfig\n\
	ldr r0, [r0]\n\
	ldrb r2, [r0, #8]\n\
	adds r2, #3\n\
	mov r0, sp\n\
	adds r1, r4, #0\n\
	bl DMA3Transfer\n\
	adds r0, r4, #0\n\
	mov r1, sp\n\
	movs r2, #0x44\n\
	bl DMA3Transfer\n\
	add r2, sp, #8\n\
	adds r5, #6\n\
	movs r4, #0\n\
	movs r6, #1\n\
_0824C354:\n\
	movs r1, #0\n\
	movs r3, #0\n\
_0824C358:\n\
	lsls r1, r1, #0x11\n\
	ldrh r0, [r2]\n\
	ands r0, r6\n\
	lsrs r1, r1, #0x10\n\
	orrs r1, r0\n\
	adds r2, #2\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #0xf\n\
	bls _0824C358\n\
	strh r1, [r5]\n\
	subs r5, #2\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #3\n\
	bls _0824C354\n\
	movs r0, #0\n\
_0824C37E:\n\
	add sp, #0x88\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0824C388: .4byte gEEPROMConfig\n\
 .syntax divided\n");
}

u16 EEPROMWrite(u16 address, const u16* data, u8 unk_3);

u16 EEPROMWrite1(u16 address, const u16* data) { return EEPROMWrite(address, data, 1); }

NAKED u16 EEPROMWrite(u16 address, const u16* data, u8 unk_3) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #0xb0\n\
	adds r5, r1, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	lsls r2, r2, #0x18\n\
	lsrs r7, r2, #0x18\n\
	ldr r0, _0824C3BC @ =gEEPROMConfig\n\
	ldr r0, [r0]\n\
	ldrh r0, [r0, #4]\n\
	cmp r1, r0\n\
	blo _0824C3C4\n\
	ldr r0, _0824C3C0 @ =0x000080FF\n\
	b _0824C4F8\n\
	.align 2, 0\n\
_0824C3BC: .4byte gEEPROMConfig\n\
_0824C3C0: .4byte 0x000080FF\n\
_0824C3C4:\n\
	ldr r0, _0824C404 @ =gEEPROMConfig\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, #8]\n\
	lsls r0, r0, #1\n\
	mov r2, sp\n\
	adds r3, r0, r2\n\
	adds r3, #0x84\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	subs r3, #2\n\
	movs r4, #0\n\
_0824C3DA:\n\
	ldrh r2, [r5]\n\
	adds r5, #2\n\
	movs r0, #0\n\
_0824C3E0:\n\
	strh r2, [r3]\n\
	subs r3, #2\n\
	lsrs r2, r2, #1\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xf\n\
	bls _0824C3E0\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #3\n\
	bls _0824C3DA\n\
	movs r4, #0\n\
	ldr r0, _0824C404 @ =gEEPROMConfig\n\
	adds r2, r0, #0\n\
	ldr r0, [r0]\n\
	b _0824C416\n\
	.align 2, 0\n\
_0824C404: .4byte gEEPROMConfig\n\
_0824C408:\n\
	strh r1, [r3]\n\
	subs r3, #2\n\
	lsrs r1, r1, #1\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	ldr r0, [r2]\n\
_0824C416:\n\
	ldrb r0, [r0, #8]\n\
	cmp r4, r0\n\
	blo _0824C408\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	subs r3, #2\n\
	movs r6, #1\n\
	strh r6, [r3]\n\
	movs r4, #0xd0\n\
	lsls r4, r4, #0x14\n\
	ldr r0, _0824C488 @ =gEEPROMConfig\n\
	ldr r0, [r0]\n\
	ldrb r2, [r0, #8]\n\
	adds r2, #0x43\n\
	mov r0, sp\n\
	adds r1, r4, #0\n\
	bl DMA3Transfer\n\
	movs r5, #0\n\
	add r2, sp, #0xa4\n\
	strh r5, [r2]\n\
	mov r1, sp\n\
	adds r1, #0xa6\n\
	ldr r0, _0824C48C @ =0x04000006\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	add r0, sp, #0xac\n\
	str r5, [r0]\n\
	ldrh r0, [r2]\n\
	cmp r0, #0\n\
	bne _0824C45C\n\
	ldrh r0, [r4]\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	bne _0824C4EC\n\
_0824C45C:\n\
	add r3, sp, #0xa8\n\
	ldr r0, _0824C48C @ =0x04000006\n\
	ldrh r0, [r0]\n\
	strh r0, [r3]\n\
	mov r4, sp\n\
	adds r4, #0xa6\n\
	ldrh r1, [r3]\n\
	ldrh r0, [r4]\n\
	cmp r1, r0\n\
	beq _0824C4D6\n\
	ldrh r1, [r3]\n\
	ldrh r0, [r4]\n\
	cmp r1, r0\n\
	bls _0824C490\n\
	add r2, sp, #0xac\n\
	ldrh r1, [r3]\n\
	ldrh r0, [r4]\n\
	subs r1, r1, r0\n\
	ldr r0, [r2]\n\
	adds r1, r1, r0\n\
	str r1, [r2]\n\
	b _0824C4A6\n\
	.align 2, 0\n\
_0824C488: .4byte gEEPROMConfig\n\
_0824C48C: .4byte 0x04000006\n\
_0824C490:\n\
	add r2, sp, #0xac\n\
	add r0, sp, #0xa8\n\
	ldrh r0, [r0]\n\
	adds r0, #0xe4\n\
	mov r1, sp\n\
	adds r1, #0xa6\n\
	ldrh r1, [r1]\n\
	subs r0, r0, r1\n\
	ldr r1, [r2]\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
_0824C4A6:\n\
	add r0, sp, #0xac\n\
	ldr r0, [r0]\n\
	cmp r0, #0x88\n\
	bls _0824C4CC\n\
	add r0, sp, #0xa4\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _0824C4F6\n\
	movs r0, #0xd0\n\
	lsls r0, r0, #0x14\n\
	ldrh r0, [r0]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0824C4F6\n\
	ldr r5, _0824C4C8 @ =0x0000C001\n\
	b _0824C4F6\n\
	.align 2, 0\n\
_0824C4C8: .4byte 0x0000C001\n\
_0824C4CC:\n\
	mov r0, sp\n\
	adds r0, #0xa6\n\
	add r1, sp, #0xa8\n\
	ldrh r1, [r1]\n\
	strh r1, [r0]\n\
_0824C4D6:\n\
	add r2, sp, #0xa4\n\
	ldrh r0, [r2]\n\
	cmp r0, #0\n\
	bne _0824C45C\n\
	movs r0, #0xd0\n\
	lsls r0, r0, #0x14\n\
	movs r1, #1\n\
	ldrh r0, [r0]\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0824C45C\n\
_0824C4EC:\n\
	ldrh r0, [r2]\n\
	adds r0, #1\n\
	strh r0, [r2]\n\
	cmp r7, #0\n\
	bne _0824C45C\n\
_0824C4F6:\n\
	adds r0, r5, #0\n\
_0824C4F8:\n\
	add sp, #0xb0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
   .syntax divided\n");
}

u16 EEPROMCompare(u16 address, const u16* data) {
  u16 ret;

  u16 buffer[4];
  u16* ptr;

  u8 i;

  ret = 0;
  if (address >= (gEEPROMConfig.unk_00)->size) {
    return EEPROM_OUT_OF_RANGE;
  }
  EEPROMRead(address, buffer);
  ptr = buffer;
  for (i = 0; i < ARRAY_COUNT(buffer); i++) {
    if (*data++ != *ptr++) {
      ret = EEPROM_COMPARE_FAILED;
      break;
    }
  }
  return ret;
}

u16 EEPROMWrite1_check(u16 address, const u16* data) {
  u8 i;
  u16 ret;

  for (i = 0; i < 3; i++) {
    ret = EEPROMWrite1(address, data);
    if (ret == 0) {
      ret = EEPROMCompare(address, data);
      if (ret == 0) break;
    }
  }
  return ret;
}
