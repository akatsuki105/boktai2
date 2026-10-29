	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D298A
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D298E
_080D298A:
	movs r7, #0x30
	b _080D2990
_080D298E:
	movs r7, #0x40
_080D2990:
	ldr r1, _080D29A8 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	bls _080D299C
	b _080D2BF8
_080D299C:
	lsls r0, r0, #2
	ldr r1, _080D29AC @ =_080D29B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D29A8: .4byte 0x0000037D
_080D29AC: .4byte _080D29B0
_080D29B0: @ jump table
	.4byte _080D29CC @ case 0
	.4byte _080D29FC @ case 1
	.4byte _080D2BF8 @ case 2
	.4byte _080D2BF8 @ case 3
	.4byte _080D2A64 @ case 4
	.4byte _080D2B38 @ case 5
	.4byte _080D2B8C @ case 6
_080D29CC:
	adds r0, r5, #0
	bl FUN_080d1a44
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x18
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl PlayerLink_PlayAnim
	cmp r0, #0
	bne _080D29F0
	b _080D2BF8
_080D29F0:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D2BF8
_080D29FC:
	adds r0, r5, #0
	bl FUN_080d1a44
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x19
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r2, _080D2A50 @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #6
	bls _080D2A54
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D2A54
	adds r0, r5, #0
	bl FUN_080d230c
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl PlayerLink_SetAction
	b _080D2BF8
	.align 2, 0
_080D2A50: .4byte 0x0000037E
_080D2A54:
	ldr r2, _080D2A60 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D2BF8
	.align 2, 0
_080D2A60: .4byte 0x0000037E
_080D2A64:
	ldr r0, _080D2AC0 @ =0x000003D1
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r4, r5, r1
	ldrb r0, [r4]
	ldr r2, _080D2AC4 @ =0x00000A82
	adds r6, r5, r2
	ldrh r1, [r6]
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl PlayerLink_PlayAnim
	ldrb r0, [r4]
	cmp r0, #1
	bne _080D2B22
	ldrh r0, [r6]
	cmp r0, #0x1c
	bne _080D2AC8
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2B22
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #0
	bl FUN_080ccc34
	b _080D2B22
	.align 2, 0
_080D2AC0: .4byte 0x000003D1
_080D2AC4: .4byte 0x00000A82
_080D2AC8:
	cmp r0, #0x1b
	bne _080D2AF6
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2B22
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #1
	bl FUN_080ccc34
	b _080D2B22
_080D2AF6:
	cmp r0, #0x1a
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D2B22
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #2
	bl FUN_080ccc34
_080D2B22:
	adds r0, r5, #0
	bl FUN_080d2724
	cmp r0, #0
	beq _080D2BF8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl PlayerLink_SetAction
	b _080D2BF8
_080D2B38:
	ldr r2, _080D2B84 @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D2B5A
	ldr r2, _080D2B88 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_080D2B5A:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x18
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl PlayerLink_PlayAnim
	cmp r0, #0
	beq _080D2BF8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl PlayerLink_SetAction
	b _080D2BF8
	.align 2, 0
_080D2B84: .4byte 0x000003D1
_080D2B88: .4byte 0x00000A76
_080D2B8C:
	ldr r2, _080D2BC4 @ =0x000003D1
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D2BAE
	ldr r0, _080D2BC8 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D2BAE:
	ldr r1, _080D2BC8 @ =0x00000A76
	adds r4, r5, r1
	ldrb r6, [r4]
	cmp r6, #0
	beq _080D2BD0
	strb r2, [r4]
	ldr r1, _080D2BCC @ =0x0000037D
	adds r0, r5, r1
	strb r2, [r0]
	b _080D2BF8
	.align 2, 0
_080D2BC4: .4byte 0x000003D1
_080D2BC8: .4byte 0x00000A76
_080D2BCC: .4byte 0x0000037D
_080D2BD0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x19
	bl Player_GetAnimIdx
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl PlayerLink_PlayAnim
	cmp r0, #0
	beq _080D2BF8
	strb r6, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D2BF8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
