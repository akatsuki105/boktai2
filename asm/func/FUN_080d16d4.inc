	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _080D16EE
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl PlayerLink_SetAction
_080D16EE:
	ldr r2, _080D1704 @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D16FA
	b _080D19F2
_080D16FA:
	lsls r0, r0, #2
	ldr r1, _080D1708 @ =_080D170C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D1704: .4byte 0x0000037D
_080D1708: .4byte _080D170C
_080D170C: @ jump table
	.4byte _080D1720 @ case 0
	.4byte _080D1744 @ case 1
	.4byte _080D1820 @ case 2
	.4byte _080D1928 @ case 3
	.4byte _080D19AC @ case 4
_080D1720:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
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
	b _080D19F2
_080D1744:
	ldr r2, _080D1770 @ =0x0000037E
	adds r0, r4, r2
	ldrh r2, [r0]
	cmp r2, #0
	bne _080D179A
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080D177C
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080D1774 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080D1778 @ =0x000002E7
	b _080D1786
	.align 2, 0
_080D1770: .4byte 0x0000037E
_080D1774: .4byte 0x000002E6
_080D1778: .4byte 0x000002E7
_080D177C:
	strb r2, [r1]
	ldr r1, _080D1804 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
_080D1786:
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_080d1344
	ldr r2, _080D1808 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080D179A:
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
	bne _080D17C2
	b _080D19F2
_080D17C2:
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
	bne _080D17DE
	b _080D1964
_080D17DE:
	adds r0, r4, #0
	bl FUN_080d16a4
	adds r1, r0, #0
	cmp r1, #0
	beq _080D1814
	ldr r0, [r4, #0x18]
	movs r1, #0xb9
	lsls r1, r1, #2
	bl Sound_PlayForPlayer
	ldr r0, _080D180C @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080D1810 @ =0x00000404
	adds r1, r4, r2
	b _080D198E
	.align 2, 0
_080D1804: .4byte 0x000002E6
_080D1808: .4byte 0x0000037E
_080D180C: .4byte 0x00000409
_080D1810: .4byte 0x00000404
_080D1814:
	ldr r2, _080D181C @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _080D1914
	.align 2, 0
_080D181C: .4byte 0x00000404
_080D1820:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _080D1898 @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _080D1846
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _080D1846
	ldr r0, [r4, #0x18]
	ldr r1, _080D189C @ =0x00000239
	bl Sound_PlayForPlayer
_080D1846:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #9
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080d1344
	movs r0, #0x93
	lsls r0, r0, #4
	adds r1, r4, r0
	adds r0, r4, #0
	bl FUN_080cd3c0
	ldr r2, _080D18A0 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _080D18A4 @ =0x0000037E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080D18A8
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _080D18B4
	.align 2, 0
_080D1898: .4byte 0x00000404
_080D189C: .4byte 0x00000239
_080D18A0: .4byte 0x0000095E
_080D18A4: .4byte 0x0000037E
_080D18A8:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_080D18B4:
	ldr r0, _080D18F0 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _080D18CC
	movs r0, #0
	strh r0, [r1]
_080D18CC:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D18FC
	ldr r0, [r4, #0x18]
	ldr r1, _080D18F4 @ =0x00000239
	bl FUN_080cc410
	ldr r2, _080D18F8 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _080D1964
	.align 2, 0
_080D18F0: .4byte 0x0000037E
_080D18F4: .4byte 0x00000239
_080D18F8: .4byte 0x00000409
_080D18FC:
	adds r0, r4, #0
	bl FUN_080d16a4
	cmp r0, #0
	bne _080D19F2
	ldr r0, [r4, #0x18]
	ldr r1, _080D1920 @ =0x00000239
	bl FUN_080cc410
	ldr r1, _080D1924 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_080D1914:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl PlayerLink_SetAction
	b _080D19F2
	.align 2, 0
_080D1920: .4byte 0x00000239
_080D1924: .4byte 0x00000409
_080D1928:
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
	bne _080D1970
_080D1964:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl PlayerLink_SetAction
	b _080D19F2
_080D1970:
	adds r0, r4, #0
	bl FUN_080d16a4
	cmp r0, #0
	beq _080D19F2
	ldr r0, [r4, #0x18]
	ldr r1, _080D19A0 @ =0x00000239
	bl Sound_PlayForPlayer
	ldr r2, _080D19A4 @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D19A8 @ =0x00000404
	adds r1, r4, r0
_080D198E:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl PlayerLink_SetAction
	b _080D19F2
	.align 2, 0
_080D19A0: .4byte 0x00000239
_080D19A4: .4byte 0x00000409
_080D19A8: .4byte 0x00000404
_080D19AC:
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
	beq _080D19F2
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _080D19F8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D19F2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D19F8: .4byte 0x000002E7
