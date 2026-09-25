	push {lr}
	adds r3, r1, #0
	adds r3, #0x5d
	movs r2, #0
	strb r2, [r3]
	movs r2, #0x5e
	adds r2, r2, r1
	mov ip, r2
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r3, #1
	lsls r3, r2
	ldr r2, [r0, #0x18]
	bics r2, r3
	str r2, [r0, #0x18]
	movs r0, #0xff
	mov r3, ip
	strb r0, [r3]
	adds r0, r1, #0
	movs r1, #0x64
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0
