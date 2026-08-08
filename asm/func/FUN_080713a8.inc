	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080713C4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #6
	bls _080713B8
	b _08071590
_080713B8:
	lsls r0, r0, #2
	ldr r1, _080713C8 @ =_080713CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080713C4: .4byte 0x0000037D
_080713C8: .4byte _080713CC
_080713CC: @ jump table
	.4byte _080713E8 @ case 0
	.4byte _08071424 @ case 1
	.4byte _08071590 @ case 2
	.4byte _08071590 @ case 3
	.4byte _08071478 @ case 4
	.4byte _080714D0 @ case 5
	.4byte _08071554 @ case 6
_080713E8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x20
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08071406
	b _08071590
_08071406:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071454
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08071590
_08071424:
	adds r0, r4, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x21
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08071466
_08071454:
	adds r0, r4, #0
	bl FUN_08071218
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071590
_08071466:
	ldr r0, _08071474 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08071590
	.align 2, 0
_08071474: .4byte 0x0000037E
_08071478:
	ldr r0, _080714C8 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x22
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080714B2
	ldr r0, _080714CC @ =0x00000A76
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080714B2:
	adds r0, r4, #0
	bl FUN_080712d4
	cmp r0, #0
	beq _08071590
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071590
	.align 2, 0
_080714C8: .4byte 0x000003D1
_080714CC: .4byte 0x00000A76
_080714D0:
	ldr r1, _08071520 @ =0x000003D1
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	subs r1, #0x79
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x21
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071508
	ldr r0, _08071524 @ =0x00000A76
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08071508:
	ldr r1, _08071524 @ =0x00000A76
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _0807152C
	strb r5, [r2]
	ldr r0, _08071528 @ =0x0000037D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08071590
	.align 2, 0
_08071520: .4byte 0x000003D1
_08071524: .4byte 0x00000A76
_08071528: .4byte 0x0000037D
_0807152C:
	ldr r0, _08071550 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _08071590
	movs r0, #0
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _08071590
	.align 2, 0
_08071550: .4byte 0x0000037E
_08071554:
	ldr r0, _08071598 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x20
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0807159C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08071590
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08071590:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08071598: .4byte 0x000003D1
_0807159C: .4byte 0x0000037E
