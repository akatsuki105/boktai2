	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _08219E94 @ =0x0000C091
	ldr r1, _08219E98 @ =0x000033B2
	bl FUN_082310cc
	adds r2, r0, #0
	str r2, [r4, #0x38]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	adds r0, r4, #0
	bl FUN_08213880
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08219E94: .4byte 0x0000C091
_08219E98: .4byte 0x000033B2
