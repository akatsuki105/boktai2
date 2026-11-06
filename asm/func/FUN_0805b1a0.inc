	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r3, r5, #0
	adds r3, #0x24
	movs r4, #0
	movs r6, #1
	movs r1, #3
	mov r8, r1
	mov ip, r4
	movs r7, #0xe2
	lsls r7, r7, #1
_0805B1BA:
	adds r2, r6, #0
	lsls r2, r4
	ldr r1, [r5, #0x18]
	ands r1, r2
	cmp r1, #0
	beq _0805B1D6
	ldrb r1, [r3, #1]
	cmp r1, #2
	bhi _0805B1D6
	mov r1, r8
	strb r1, [r3, #1]
	strb r6, [r3]
	mov r1, ip
	strh r1, [r3, #6]
_0805B1D6:
	adds r4, #1
	adds r3, r3, r7
	cmp r4, #7
	ble _0805B1BA
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
