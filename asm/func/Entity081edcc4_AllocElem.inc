	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r4, r2, r0
	movs r5, #1
_081EDAA6:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081EDAB6
	movs r0, #1
	b _081EDAB8
_081EDAB6:
	movs r0, #0
_081EDAB8:
	cmp r0, #0
	bne _081EDAD6
	movs r0, #0xdc
	muls r0, r3, r0
	adds r0, #0x18
	adds r0, r2, r0
	adds r1, r0, #0
	adds r1, #0xd6
	strb r3, [r1]
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _081EDADE
_081EDAD6:
	adds r3, #1
	cmp r3, #1
	ble _081EDAA6
	movs r0, #0
_081EDADE:
	pop {r4, r5}
	pop {r1}
	bx r1
