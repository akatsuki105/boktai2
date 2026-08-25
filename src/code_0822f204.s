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

