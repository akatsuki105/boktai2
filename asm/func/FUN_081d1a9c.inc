	push {r4, r5, r6, lr}
	movs r2, #0
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r3, r0, r1
	movs r6, #1
	adds r4, r0, #0
	adds r4, #0x94
	adds r5, r0, #0
	adds r5, #0x18
_081D1AB0:
	adds r1, r6, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081D1AC0
	movs r0, #1
	b _081D1AC2
_081D1AC0:
	movs r0, #0
_081D1AC2:
	cmp r0, #0
	bne _081D1AD6
	adds r1, r6, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	strh r2, [r4]
	adds r0, r5, #0
	b _081D1AE2
_081D1AD6:
	adds r4, #0x88
	adds r5, #0x88
	adds r2, #1
	cmp r2, #7
	ble _081D1AB0
	movs r0, #0
_081D1AE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
