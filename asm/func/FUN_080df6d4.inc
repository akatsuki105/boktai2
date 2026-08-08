	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_080DF6DA:
	movs r0, #0x5c
	adds r3, r4, #0
	muls r3, r0, r3
	adds r0, r5, r3
	adds r1, r0, #0
	adds r1, #0x94
	ldrh r0, [r1]
	cmp r0, #0
	beq _080DF708
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080DF708
	adds r2, r5, #0
	adds r2, #0x3c
	adds r2, r2, r3
	ldr r1, [r2]
	movs r0, #1
	orrs r1, r0
	subs r0, #4
	ands r1, r0
	str r1, [r2]
_080DF708:
	adds r4, #1
	cmp r4, #1
	ble _080DF6DA
	pop {r4, r5}
	pop {r0}
	bx r0
