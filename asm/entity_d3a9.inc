	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c0ae4
FUN_080c0ae4: @ 0x080C0AE4
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b00
FUN_080c0b00: @ 0x080C0B00
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl PlaySound_08240718
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b1c
FUN_080c0b1c: @ 0x080C0B1C
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl sound_08240264
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b38
FUN_080c0b38: @ 0x080C0B38
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_08240360
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b54
FUN_080c0b54: @ 0x080C0B54
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082403d0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b70
FUN_080c0b70: @ 0x080C0B70
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl sound_fadeout_08240440
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b8c
FUN_080c0b8c: @ 0x080C0B8C
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082404b0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0ba8
FUN_080c0ba8: @ 0x080C0BA8
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082404fc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0bc4
FUN_080c0bc4: @ 0x080C0BC4
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_08240568
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0be0
FUN_080c0be0: @ 0x080C0BE0
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082405c0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

