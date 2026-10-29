	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _080D13DA
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl PlayerLink_SetAction
	ldr r2, _080D13F0 @ =0x00000951
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_080D13DA:
	ldr r1, _080D13F4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D13E6
	b _080D169A
_080D13E6:
	lsls r0, r0, #2
	ldr r1, _080D13F8 @ =_080D13FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D13F0: .4byte 0x00000951
_080D13F4: .4byte 0x0000037D
_080D13F8: .4byte _080D13FC
_080D13FC: @ jump table
	.4byte _080D1410 @ case 0
	.4byte _080D1434 @ case 1
	.4byte _080D150C @ case 2
	.4byte _080D15D4 @ case 3
	.4byte _080D1654 @ case 4
_080D1410:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D169A
_080D1434:
	ldr r1, _080D1460 @ =0x0000037E
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne _080D148A
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080D146C
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080D1464 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080D1468 @ =0x000002E7
	b _080D1476
	.align 2, 0
_080D1460: .4byte 0x0000037E
_080D1464: .4byte 0x000002E6
_080D1468: .4byte 0x000002E7
_080D146C:
	strb r2, [r1]
	ldr r1, _080D14F0 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
_080D1476:
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_080d1344
	ldr r2, _080D14F4 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080D148A:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	bne _080D14B2
	b _080D169A
_080D14B2:
	ldr r0, [r4, #0x18]
	movs r1, #0xcb
	bl Sound_PlayForPlayer
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D14CE
	b _080D1610
_080D14CE:
	adds r0, r4, #0
	bl FUN_080d1314
	adds r1, r0, #0
	cmp r1, #0
	beq _080D1500
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl Sound_PlayForPlayer
	ldr r0, _080D14F8 @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080D14FC @ =0x00000404
	adds r1, r4, r2
	b _080D163A
	.align 2, 0
_080D14F0: .4byte 0x000002E6
_080D14F4: .4byte 0x0000037E
_080D14F8: .4byte 0x00000409
_080D14FC: .4byte 0x00000404
_080D1500:
	ldr r2, _080D1508 @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _080D15C4
	.align 2, 0
_080D1508: .4byte 0x00000404
_080D150C:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _080D1540 @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _080D154E
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _080D154E
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D1544
	ldr r0, [r4, #0x18]
	subs r1, #0x50
	bl Sound_PlayForPlayer
	b _080D154E
	.align 2, 0
_080D1540: .4byte 0x00000404
_080D1544:
	ldr r0, [r4, #0x18]
	movs r1, #0x94
	lsls r1, r1, #1
	bl Sound_PlayForPlayer
_080D154E:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #9
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r5, #0
	movs r0, #0x1e
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080d1344
	movs r2, #0x93
	lsls r2, r2, #4
	adds r1, r4, r2
	adds r0, r4, #0
	bl FUN_080cd230
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D15AC
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl FUN_080cc410
	ldr r2, _080D15A8 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _080D1610
	.align 2, 0
_080D15A8: .4byte 0x00000409
_080D15AC:
	adds r0, r4, #0
	bl FUN_080d1314
	cmp r0, #0
	bne _080D169A
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl FUN_080cc410
	ldr r1, _080D15D0 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_080D15C4:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl PlayerLink_SetAction
	b _080D169A
	.align 2, 0
_080D15D0: .4byte 0x00000409
_080D15D4:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D161C
_080D1610:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl PlayerLink_SetAction
	b _080D169A
_080D161C:
	adds r0, r4, #0
	bl FUN_080d1314
	cmp r0, #0
	beq _080D169A
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl Sound_PlayForPlayer
	ldr r2, _080D164C @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D1650 @ =0x00000404
	adds r1, r4, r0
_080D163A:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl PlayerLink_SetAction
	b _080D169A
	.align 2, 0
_080D164C: .4byte 0x00000409
_080D1650: .4byte 0x00000404
_080D1654:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	beq _080D169A
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _080D16A0 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D169A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D16A0: .4byte 0x000002E7
