	push {lr}
	adds r2, r0, #0
	movs r0, #0
	strb r0, [r2, #0x1e]
	movs r1, #0
	strh r0, [r2, #0x22]
	adds r0, r2, #0
	adds r0, #0x35
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #6
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0x40
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0
