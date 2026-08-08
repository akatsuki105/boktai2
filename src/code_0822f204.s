	.include "asm/macros.inc"
	.syntax unified
	.text

	thumb_func_start FUN_0822f204
FUN_0822f204: @ 0x0822F204
	push {lr}
	add r1, pc, #0x4 @ =FUN_0822f20c
	bx r1
	.align 2, 0

	arm_func_start FUN_0822f20c
FUN_0822f20c: @ 0x0822F20C
	bl FUN_08230134
	add r2, pc, #0x1 @ =FUN_0822f218
	bx r2

	thumb_func_start FUN_0822f218
FUN_0822f218: @ 0x0822F218
	adds r3, #0
	adds r3, #0
	pop {r0}
	bx r0
_0822F220:
	.byte 0x00, 0x00

	non_word_aligned_thumb_func_start FUN_0822f222
FUN_0822f222: @ 0x0822F222
	bx lr

	thumb_func_start FUN_0822f224
FUN_0822f224: @ 0x0822F224
	push {lr}
	add r1, pc, #0x4 @ =FUN_0822f22c
	bx r1
	.align 2, 0

	arm_func_start FUN_0822f22c
FUN_0822f22c: @ 0x0822F22C
	bl FUN_082302e8
	add r2, pc, #0x1 @ =FUN_0822f238
	bx r2

	thumb_func_start FUN_0822f238
FUN_0822f238: @ 0x0822F238
	adds r3, #0
	adds r3, #0
	pop {r0}
	bx r0
_0822F240:
	.byte 0x00, 0x00

	non_word_aligned_thumb_func_start FUN_0822f242
FUN_0822f242: @ 0x0822F242
	bx lr

	thumb_func_start FUN_0822f244
FUN_0822f244: @ 0x0822F244
	push {lr}
	adr r1, _0822f24c
	bx r1
  .arm
_0822f24c: @ 0x0822F24C
	bl FUN_082303c8
  adr r2, _0822f258 + 1
	bx r2
  .thumb
_0822f258: @ 0x0822F258
	adds r3, #0
	adds r3, #0
	pop {r0}
	bx r0
  thumb_func_end FUN_0822f244
_0822F260:
  .byte 0x00, 0x00

	non_word_aligned_thumb_func_start FUN_0822f262
FUN_0822f262: @ 0x0822F262
	bx lr

	thumb_func_start FUN_0822f264
FUN_0822f264: @ 0x0822F264
  push {lr}
  .byte 0x01, 0xA1, 0x08, 0x47, 0x00, 0x00, 0xC8, 0x04, 0x00, 0xEB
	.byte 0x01, 0x20, 0x8F, 0xE2, 0x12, 0xFF, 0x2F, 0xE1, 0x00, 0x33, 0x00, 0x33, 0x01, 0xBC
  bx r0
  thumb_func_end FUN_0822f264
_0822F280:
  .byte 0x00, 0x00

	non_word_aligned_thumb_func_start FUN_0822f282
FUN_0822f282: @ 0x0822F282
	bx lr

	thumb_func_start FUN_0822f284
FUN_0822f284: @ 0x0822F284
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldm r2!, {r4, r5, r6}
	stm r3!, {r4, r5, r6}
	ldm r2!, {r4, r5, r6}
	stm r3!, {r4, r5, r6}
	ldm r2!, {r4, r5}
	stm r3!, {r4, r5}
	ldr r2, [r0, #0xc]
	adds r2, r2, r1
	str r2, [r0, #0xc]
	ldr r2, [r0, #0x10]
	adds r2, r2, r1
	str r2, [r0, #0x10]
	ldr r2, [r0, #0x14]
	adds r2, r2, r1
	str r2, [r0, #0x14]
	ldr r2, [r0, #0x18]
	adds r2, r2, r1
	str r2, [r0, #0x18]
	ldr r2, [r0, #0x1c]
	adds r2, r2, r1
	str r2, [r0, #0x1c]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_0822F2BC:
	.byte 0x10, 0xB5, 0x09, 0x04
	.byte 0x0C, 0x0C, 0xC2, 0x68, 0x00, 0x23, 0x40, 0x88, 0x83, 0x42, 0x09, 0xDA, 0x01, 0x1C, 0x10, 0x88
	.byte 0xA0, 0x42, 0x01, 0xD1, 0x10, 0x1C, 0x04, 0xE0, 0x14, 0x32, 0x01, 0x33, 0x8B, 0x42, 0xF6, 0xDB
	.byte 0x00, 0x20, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_0822f2e8
FUN_0822f2e8: @ 0x0822F2E8
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r1, [r5, #0xc]
	adds r4, r1, r0
	cmp r4, #0
	bne _0822F306
	movs r0, #1
	rsbs r0, r0, #0
	b _0822F35A
_0822F306:
	ldrh r0, [r4]
	movs r2, #0
	strh r0, [r3]
	ldrh r0, [r4, #4]
	strh r0, [r3, #0x28]
	ldrh r0, [r4, #6]
	strh r0, [r3, #0x2a]
	ldrh r0, [r4, #8]
	strh r0, [r3, #0x2c]
	ldrh r0, [r4, #0xa]
	strh r0, [r3, #0x2e]
	ldrh r0, [r4, #0xc]
	strh r0, [r3, #0x30]
	ldrh r0, [r4, #0xe]
	strh r0, [r3, #0x32]
	adds r0, r3, #0
	adds r0, #0x34
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	strh r2, [r3, #0x36]
	ldr r0, [r3, #0x48]
	cmp r0, #0
	bne _0822F348
	ldrh r0, [r5]
	strh r0, [r3, #0x3a]
	ldr r0, _0822F360 @ =0x03003584
	ldrh r1, [r3, #0x3a]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r3, #0x48]
_0822F348:
	ldrh r0, [r4, #2]
	strh r0, [r3, #0x38]
	ldr r0, [r5, #0x14]
	ldr r1, [r4, #0x10]
	adds r0, r0, r1
	str r0, [r3, #0x4c]
	ldr r0, [r5, #0x1c]
	str r0, [r3, #0x50]
	movs r0, #0
_0822F35A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0822F360: .4byte 0x03003584

	thumb_func_start FUN_0822f364
FUN_0822f364: @ 0x0822F364
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r3
	ldr r0, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	ldr r4, [sp, #0x20]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	bl FUN_0822f2e8
	cmp r0, #0
	blt _0822F3BC
	ldr r0, _0822F3B8 @ =0x030044B8
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r5, #2]
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	str r0, [r5, #8]
	strh r1, [r5, #0xc]
	movs r0, #0x40
	strh r0, [r5, #0x10]
	strh r4, [r5, #0xe]
	strb r7, [r5, #0x1a]
	strb r6, [r5, #0x1b]
	ldr r0, [sp, #0x24]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x20]
	str r1, [r5, #0x24]
	movs r0, #0
	b _0822F3C0
	.align 2, 0
_0822F3B8: .4byte 0x030044B8
_0822F3BC:
	movs r0, #1
	rsbs r0, r0, #0
_0822F3C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0822f3cc
FUN_0822f3cc: @ 0x0822F3CC
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	bl FUN_0822f2e8
	cmp r0, #0
	blt _0822F3F0
	ldr r0, _0822F3EC @ =0x030044B8
	ldrh r0, [r0]
	strh r0, [r4, #2]
	strb r5, [r4, #0x1b]
	movs r0, #0
	b _0822F3F4
	.align 2, 0
_0822F3EC: .4byte 0x030044B8
_0822F3F0:
	movs r0, #1
	rsbs r0, r0, #0
_0822F3F4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0822f3fc
FUN_0822f3fc: @ 0x0822F3FC
  .include "asm/func/FUN_0822f3fc.inc"

	thumb_func_start FUN_0822f4d8
FUN_0822f4d8: @ 0x0822F4D8
  .include "asm/func/FUN_0822f4d8.inc"

	thumb_func_start FUN_0822f584
FUN_0822f584: @ 0x0822F584
  .include "asm/func/FUN_0822f584.inc"

	thumb_func_start FUN_0822f588
FUN_0822f588: @ 0x0822F588
  .include "asm/func/FUN_0822f588.inc"

	thumb_func_start FUN_0822f63c
FUN_0822f63c: @ 0x0822F63C
  .include "asm/func/FUN_0822f63c.inc"

