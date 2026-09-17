	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_0822dabc
	adds r1, r5, #0
	adds r1, #0x42
	movs r0, #0
	strb r0, [r1]
	adds r6, r5, #0
	adds r6, #0x43
	movs r0, #0
	ldrsb r0, [r6, r0]
	movs r1, #0x92
	lsls r1, r1, #4
	adds r4, r4, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x48
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
