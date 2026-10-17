	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D0B30
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ced68
	cmp r0, #0
	beq _080D0B1C
	ldr r0, [r4, #0x18]
	ldr r1, _080D0AD4 @ =0x00000392
	bl Sound_PlayForPlayer
	ldr r1, [r4, #0x18]
	ldr r0, _080D0AD8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D0ADC
	movs r0, #0
	b _080D0AE2
	.align 2, 0
_080D0AD4: .4byte 0x00000392
_080D0AD8: .4byte 0x03002C68
_080D0ADC:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D0AE2:
	lsls r0, r0, #1
	adds r0, #0xe
	movs r2, #0xff
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls _080D0AFA
	movs r0, #0x20
	strb r0, [r1]
_080D0AFA:
	movs r0, #0x80
	lsls r0, r0, #2
	ldrb r1, [r1]
	bl Div
	ldr r3, _080D0B18 @ =0x000003FD
	adds r1, r4, r3
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl PlayerLink_SetAction
	b _080D0B30
	.align 2, 0
_080D0B18: .4byte 0x000003FD
_080D0B1C:
	ldr r0, [r4, #0x18]
	movs r1, #0xc9
	lsls r1, r1, #1
	bl Sound_PlayForPlayer
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	bl PlayerLink_SetAction
_080D0B30:
	ldr r1, _080D0B40 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0B44
	cmp r0, #1
	beq _080D0BF8
	b _080D0C2C
	.align 2, 0
_080D0B40: .4byte 0x0000037D
_080D0B44:
	ldr r3, _080D0B68 @ =0x0000037E
	adds r2, r4, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r3, #0x7f
	adds r1, r4, r3
	ldrb r3, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	blo _080D0B6C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
	b _080D0C2C
	.align 2, 0
_080D0B68: .4byte 0x0000037E
_080D0B6C:
	ldrh r1, [r2]
	adds r0, r3, #0
	subs r0, #8
	cmp r1, r0
	bge _080D0B88
	ldr r0, _080D0BEC @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _080D0BF0 @ =0x00000125
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
_080D0B88:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D0BB4
	ldr r3, _080D0BF4 @ =0x000003CE
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080D0BB4
	adds r0, r4, #0
	bl FUN_080d0824
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
_080D0BB4:
	movs r3, #0xff
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080cc268
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080d08b8
	adds r0, r4, #0
	bl PlayerLink_SetAnimFacing
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x20
	bl PlayerLink_PlayAnim
	b _080D0C2C
	.align 2, 0
_080D0BEC: .4byte 0x0000095E
_080D0BF0: .4byte 0x00000125
_080D0BF4: .4byte 0x000003CE
_080D0BF8:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r3, _080D0C34 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080D0C2C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D0C2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D0C34: .4byte 0x0000037E
