	push {r4, r5, lr}
	sub sp, #0x40
	adds r4, r0, #0
	adds r5, r1, #0
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x40
	bl memcpy
	ldr r0, [sp, #0x1c]
	adds r0, r0, r4
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x24]
	adds r0, r0, r4
	str r0, [sp, #0x24]
	ldr r0, [sp, #0xc]
	adds r0, r0, r4
	str r0, [sp, #0xc]
	ldr r1, [sp, #0x14]
	adds r1, r1, r4
	str r1, [sp, #0x14]
	ldr r1, [sp, #0x2c]
	muls r1, r5, r1
	lsls r1, r1, #1
	adds r0, r0, r1
	add sp, #0x40
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
