	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r6, #0x34
	str r6, [r0, #0x30]
	movs r4, #0
	movs r5, #0xd0
	ldr r1, [r0, #0x24]
	ldr r2, [r0, #0x28]
	movs r3, #0xc8
	lsls r3, r3, #3
	adds r7, r0, r3
	ldrb r3, [r7]
	str r4, [sp]
	str r5, [sp, #4]
	adds r0, r6, #0
	bl FUN_08001884
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3f
	bls _08001C06
	movs r0, #0x40
	strb r0, [r7]
_08001C06:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
