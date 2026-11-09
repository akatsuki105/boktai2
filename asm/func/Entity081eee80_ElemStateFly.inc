	push {r4, r5, r6, lr}
	adds r4, r1, #0
	adds r5, r4, #0
	adds r1, #0x35
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _081EEB9C
	subs r0, r2, #1
	strb r0, [r1]
	b _081EEC14
_081EEB9C:
	cmp r0, #0
	bne _081EEBA6
	movs r0, #0xff
	orrs r0, r2
	strb r0, [r1]
_081EEBA6:
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
	ldrh r0, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0x3d
	adds r6, r0, #0
	ldrb r1, [r1]
	asrs r6, r1
	cmp r6, #6
	bne _081EEBC6
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #2
	strb r0, [r1]
	b _081EEC14
_081EEBC6:
	ldrh r1, [r4, #0x36]
	bl Mod
	cmp r0, #0
	beq _081EEBE0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081EEC14
	adds r0, r4, #0
	movs r1, #0
	bl Video_RemoveAuxSpriteFromDrawList
	b _081EEC14
_081EEBE0:
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _081EEBEE
	adds r0, r4, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
_081EEBEE:
	ldrh r2, [r5, #0x2c]
	ldrh r1, [r5, #0x1c]
	adds r0, r2, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x2e]
	ldrh r3, [r5, #0x1e]
	adds r0, r0, r3
	strh r0, [r5, #0x1e]
	ldrh r1, [r5, #0x30]
	ldrh r3, [r5, #0x20]
	adds r0, r1, r3
	strh r0, [r5, #0x20]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x11
	strh r2, [r5, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	strh r1, [r5, #0x30]
	strh r6, [r5, #0x10]
_081EEC14:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
