	push {lr}
	sub sp, #0x4c
	ldr r1, _08200B88 @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x24
	ldr r2, [r0, #0x44]
	ldr r3, [r0, #0x48]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r0, #0
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	add r0, sp, #8
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_081ea540
	add sp, #0x4c
	pop {r0}
	bx r0
	.align 2, 0
_08200B88: .4byte 0x03002BE0
