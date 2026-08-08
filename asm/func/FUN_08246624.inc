	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r3, r5, #0
	adds r3, #0x24
	movs r4, #0
	movs r6, #1
	movs r1, #3
	mov ip, r1
	movs r7, #0xb3
	lsls r7, r7, #2
_08246638:
	adds r2, r6, #0
	lsls r2, r4
	ldr r1, [r5, #0x18]
	ands r1, r2
	cmp r1, #0
	beq _08246652
	ldrb r1, [r3, #1]
	cmp r1, #0
	bne _08246652
	mov r2, ip
	strb r2, [r3, #1]
	strb r6, [r3]
	strh r1, [r3, #6]
_08246652:
	adds r4, #1
	adds r3, r3, r7
	cmp r4, #7
	ble _08246638
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
