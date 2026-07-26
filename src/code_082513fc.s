.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start FUN_082513fc
FUN_082513fc: @ 0x082513FC
	push {lr}
	ldr r2, [r0, #8]
	ldr r3, [r0, #0xc]
	adds r1, r3, #0
	adds r0, r2, #0
	bl __nedf2
	movs r0, #0
	pop {pc}
	.align 2, 0
