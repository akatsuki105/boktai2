	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r1, _080D36C8 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _080D36BE
	b _080D3AD8
_080D36BE:
	lsls r0, r0, #2
	ldr r1, _080D36CC @ =_080D36D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D36C8: .4byte 0x0000037D
_080D36CC: .4byte _080D36D0
_080D36D0: @ jump table
	.4byte _080D36F0 @ case 0
	.4byte _080D371A @ case 1
	.4byte _080D37F6 @ case 2
	.4byte _080D3AD8 @ case 3
	.4byte _080D38A8 @ case 4
	.4byte _080D38FC @ case 5
	.4byte _080D3A28 @ case 6
	.4byte _080D3AA4 @ case 7
_080D36F0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x23
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	bne _080D370E
	b _080D3AD8
_080D370E:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D3AD8
_080D371A:
	ldr r0, _080D377C @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080D372C
	ldr r0, [r5, #0x18]
	ldr r1, _080D3780 @ =0x000001F7
	bl Sound_PlayForPlayer
_080D372C:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _080D375A
	b _080D3AD8
_080D375A:
	ldr r2, _080D3784 @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080D3788 @ =0x000003E6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x18
	bhi _080D378C
	ldr r0, [r5, #0x18]
	movs r1, #0xd5
	b _080D38E8
	.align 2, 0
_080D377C: .4byte 0x0000037E
_080D3780: .4byte 0x000001F7
_080D3784: .4byte 0x00000A8F
_080D3788: .4byte 0x000003E6
_080D378C:
	ldr r2, _080D37BC @ =0x00000A92
	adds r1, r5, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D37C0
	ldr r0, [r5, #0x18]
	movs r1, #0xcd
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl PlayerLink_SetAction
	b _080D37CA
	.align 2, 0
_080D37BC: .4byte 0x00000A92
_080D37C0:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl PlayerLink_SetAction
_080D37CA:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2c
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	movs r0, #0x1e
	str r0, [sp, #0x10]
	movs r0, #3
	str r0, [sp, #0x14]
	movs r0, #0x19
	str r0, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0xb4
	movs r3, #0
	bl Entity08080be8_Create
	b _080D3AD8
_080D37F6:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x24
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r0, _080D388C @ =0x00000A92
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _080D3890 @ =0x0000037E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #6
	bne _080D3832
	ldr r0, [r5, #0x18]
	movs r1, #0xfc
	lsls r1, r1, #1
	bl Sound_PlayForPlayer
_080D3832:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D38E4
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _080D3854
	b _080D3AD8
_080D3854:
	ldr r0, _080D3894 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080D3898 @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _080D389C @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _080D38A0 @ =0x00000121
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D38A4 @ =0x000001F9
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl PlayerLink_SetAction
	b _080D3AD8
	.align 2, 0
_080D388C: .4byte 0x00000A92
_080D3890: .4byte 0x0000037E
_080D3894: .4byte 0x00000A8F
_080D3898: .4byte 0x000003E6
_080D389C: .4byte 0x0000095E
_080D38A0: .4byte 0x00000121
_080D38A4: .4byte 0x000001F9
_080D38A8:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r2, _080D38F8 @ =0x00000A92
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D38E4
	b _080D3AD8
_080D38E4:
	ldr r0, [r5, #0x18]
	movs r1, #0xcd
_080D38E8:
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl PlayerLink_SetAction
	b _080D3AD8
	.align 2, 0
_080D38F8: .4byte 0x00000A92
_080D38FC:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x25
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D392E
	ldr r2, _080D39A8 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_080D392E:
	ldr r0, _080D39AC @ =0x000003E6
	adds r6, r5, r0
	ldrh r0, [r6]
	cmp r0, #0
	beq _080D3A04
	cmp r0, #5
	bls _080D397A
	ldr r3, _080D39B0 @ =0xFFFF0000
	ldr r1, _080D39B4 @ =0x0000FFFF
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r3
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbd08
_080D397A:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r6]
	ldr r2, _080D39B8 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D39BC
	asrs r0, r0, #0xc
	b _080D39C2
	.align 2, 0
_080D39A8: .4byte 0x00000A76
_080D39AC: .4byte 0x000003E6
_080D39B0: .4byte 0xFFFF0000
_080D39B4: .4byte 0x0000FFFF
_080D39B8: .4byte gSineTable
_080D39BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D39C2:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _080D39E0 @ =0x000003E6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D39E4
	asrs r0, r0, #0xc
	b _080D39EA
	.align 2, 0
_080D39E0: .4byte 0x000003E6
_080D39E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D39EA:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _080D3A00 @ =0x000003E6
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080D3AD8
	.align 2, 0
_080D3A00: .4byte 0x000003E6
_080D3A04:
	ldr r2, _080D3A24 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3AD8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl PlayerLink_SetAction
	b _080D3AD8
	.align 2, 0
_080D3A24: .4byte 0x0000037E
_080D3A28:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3A5A
	ldr r0, _080D3A74 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D3A5A:
	ldr r1, _080D3A74 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D3A7C
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080D3A78 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080D3AD8
	.align 2, 0
_080D3A74: .4byte 0x00000A76
_080D3A78: .4byte 0x0000037D
_080D3A7C:
	ldr r0, _080D3AA0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080D3AD8
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl PlayerLink_SetAction
	b _080D3AD8
	.align 2, 0
_080D3AA0: .4byte 0x0000037E
_080D3AA4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r2, _080D3B08 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3AD8
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D3AD8:
	ldr r0, _080D3B0C @ =0x00000A92
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0xe
	bls _080D3AF8
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D3AF4
	adds r0, r5, #0
	bl FUN_080cf684
_080D3AF4:
	movs r0, #0
	strh r0, [r4]
_080D3AF8:
	ldr r2, _080D3B10 @ =0x00000951
	adds r1, r5, r2
	movs r0, #8
	strb r0, [r1]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D3B08: .4byte 0x0000037E
_080D3B0C: .4byte 0x00000A92
_080D3B10: .4byte 0x00000951
