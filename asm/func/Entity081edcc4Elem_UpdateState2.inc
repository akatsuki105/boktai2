	push {r4, r5, lr}
	adds r4, r1, #0
	adds r2, r4, #0
	adds r2, #0xd7
	movs r1, #0
	strb r1, [r2]
	adds r5, r4, #0
	adds r5, #0xd6
	movs r1, #0
	ldrsb r1, [r5, r1]
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #1
	lsls r2, r1
	ldr r1, [r0]
	bics r1, r2
	str r1, [r0]
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl Mover_Unlink
	adds r0, r4, #0
	movs r1, #0xdc
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
