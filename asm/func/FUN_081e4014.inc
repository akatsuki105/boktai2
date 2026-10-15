	push {lr}
	sub sp, #0x18
	adds r1, r0, #0
	ldr r2, _081E404C @ =0xFFFF0000
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r2, _081E4050 @ =0x0000150C
	adds r0, r1, r2
	adds r2, #0x60
	adds r1, r1, r2
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0xd0
	movs r3, #0x11
	bl MainSprite_Add
	add sp, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_081E404C: .4byte 0xFFFF0000
_081E4050: .4byte 0x0000150C
