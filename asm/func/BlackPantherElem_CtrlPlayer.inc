	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	str r2, [r0]
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0805434A
	movs r1, #0
	strb r1, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	str r1, [r4, #0x1c]
	movs r0, #0xc0
	strb r0, [r4, #0xf]
	movs r0, #1
	strb r0, [r4, #0x11]
	movs r0, #0
	strb r0, [r4, #0x10]
_0805434A:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _080543CA
	movs r2, #0
	ldr r0, [r5, #0x50]
	cmp r0, #0x1d
	bhi _08054368
	ldr r0, [r5, #0x18]
	movs r1, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _08054374
	b _08054378
_08054368:
	ldr r0, [r5, #0x18]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08054374
	movs r2, #1
_08054374:
	cmp r2, #0
	beq _080543CA
_08054378:
	ldr r2, _080543A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080543A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080543AC @ =0x0203B400
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r0, [r5, #0x4c]
	cmp r0, #0x63
	bls _080543B8
	cmp r1, #0x65
	ble _080543BC
	cmp r1, #0xa9
	bgt _080543B0
	adds r0, r5, #0
	bl BlackPanther_SpawnBee
	b _080543CA
	.align 2, 0
_080543A4: .4byte 0x030046B8
_080543A8: .4byte 0x000003FF
_080543AC: .4byte 0x0203B400
_080543B0:
	adds r0, r5, #0
	bl BlackPanther_SpawnBat
	b _080543CA
_080543B8:
	cmp r1, #0x7f
	bgt _080543C4
_080543BC:
	adds r0, r5, #0
	bl BlackPanther_SpawnBomb
	b _080543CA
_080543C4:
	adds r0, r5, #0
	bl BlackPanther_SpawnBat
_080543CA:
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	bne _0805443E
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl BlackPantherElem_CheckObjHit
	adds r3, r0, #0
	cmp r3, #0
	beq _080543EE
	movs r0, #6
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	b _0805443E
_080543EE:
	ldr r0, _08054400 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r5, #1
	movs r2, #1
	ands r2, r1
	cmp r2, #0
	beq _08054404
	movs r0, #4
	b _08054438
	.align 2, 0
_08054400: .4byte 0x030044E0
_08054404:
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _08054424
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _0805441A
	subs r0, #1
	strb r0, [r4, #9]
_0805441A:
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	str r2, [r4, #0x1c]
	b _0805443E
_08054424:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805443E
	ldrb r0, [r4, #8]
	cmp r0, #1
	bhi _08054436
	adds r0, #1
	strb r0, [r4, #9]
_08054436:
	movs r0, #5
_08054438:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	str r3, [r4, #0x1c]
_0805443E:
	pop {r4, r5}
	pop {r0}
	bx r0
