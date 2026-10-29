	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080D34D0 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #6
	bls _080D34C4
	b _080D369C
_080D34C4:
	lsls r0, r0, #2
	ldr r1, _080D34D4 @ =_080D34D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D34D0: .4byte 0x0000037D
_080D34D4: .4byte _080D34D8
_080D34D8: @ jump table
	.4byte _080D34F4 @ case 0
	.4byte _080D3530 @ case 1
	.4byte _080D369C @ case 2
	.4byte _080D369C @ case 3
	.4byte _080D3584 @ case 4
	.4byte _080D35DC @ case 5
	.4byte _080D3660 @ case 6
_080D34F4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x20
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	bne _080D3512
	b _080D369C
_080D3512:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3560
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D369C
_080D3530:
	adds r0, r4, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x21
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D3572
_080D3560:
	adds r0, r4, #0
	bl FUN_080d3338
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl PlayerLink_SetAction
	b _080D369C
_080D3572:
	ldr r0, _080D3580 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D369C
	.align 2, 0
_080D3580: .4byte 0x0000037E
_080D3584:
	ldr r0, _080D35D4 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x22
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D35BE
	ldr r0, _080D35D8 @ =0x00000A76
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080D35BE:
	adds r0, r4, #0
	bl FUN_080d33dc
	cmp r0, #0
	beq _080D369C
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl PlayerLink_SetAction
	b _080D369C
	.align 2, 0
_080D35D4: .4byte 0x000003D1
_080D35D8: .4byte 0x00000A76
_080D35DC:
	ldr r1, _080D362C @ =0x000003D1
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	subs r1, #0x79
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x21
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3614
	ldr r0, _080D3630 @ =0x00000A76
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080D3614:
	ldr r1, _080D3630 @ =0x00000A76
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D3638
	strb r5, [r2]
	ldr r0, _080D3634 @ =0x0000037D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080D369C
	.align 2, 0
_080D362C: .4byte 0x000003D1
_080D3630: .4byte 0x00000A76
_080D3634: .4byte 0x0000037D
_080D3638:
	ldr r0, _080D365C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080D369C
	movs r0, #0
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #6
	bl PlayerLink_SetAction
	b _080D369C
	.align 2, 0
_080D365C: .4byte 0x0000037E
_080D3660:
	ldr r0, _080D36A4 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x20
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r0, _080D36A8 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D369C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D369C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D36A4: .4byte 0x000003D1
_080D36A8: .4byte 0x0000037E
