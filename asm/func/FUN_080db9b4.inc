	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r3, #0
	movs r0, #0xe4
	lsls r0, r0, #3
	adds r4, r5, r0
	movs r6, #1
	movs r2, #0
_080DB9C4:
	adds r1, r6, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080DB9D4
	movs r0, #1
	b _080DB9D6
_080DB9D4:
	movs r0, #0
_080DB9D6:
	cmp r0, #0
	bne _080DB9F0
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r2, r1
	adds r0, r5, r0
	strb r3, [r0, #0x13]
	adds r2, r6, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _080DB9FA
_080DB9F0:
	adds r2, #0x18
	adds r3, #1
	cmp r3, #0x1f
	ble _080DB9C4
	movs r0, #0
_080DB9FA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
