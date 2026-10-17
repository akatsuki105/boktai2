	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x19
	beq _080D4AA2
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0
	bl PlayerLink_SetAction
	movs r5, #0xba
	lsls r5, r5, #2
	adds r2, r4, r5
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4A7C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D4A78 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r5, #1
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _080D4A8C
	.align 2, 0
_080D4A78: .4byte 0x000002E6
_080D4A7C:
	lsrs r1, r1, #0x19
	ldr r2, _080D4AB8 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _080D4ABC @ =0x000002E7
	adds r0, r4, r5
	strb r2, [r0]
_080D4A8C:
	ldr r0, _080D4AC0 @ =0x000003D6
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _080D4AA2
	ldr r0, [r4, #0x18]
	ldrh r1, [r5]
	bl Sound_PlayForPlayer
	movs r0, #0
	strh r0, [r5]
_080D4AA2:
	ldr r1, _080D4AC4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D4AAE
	b _080D4D28
_080D4AAE:
	lsls r0, r0, #2
	ldr r1, _080D4AC8 @ =_080D4ACC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4AB8: .4byte 0x000002E6
_080D4ABC: .4byte 0x000002E7
_080D4AC0: .4byte 0x000003D6
_080D4AC4: .4byte 0x0000037D
_080D4AC8: .4byte _080D4ACC
_080D4ACC: @ jump table
	.4byte _080D4AE0 @ case 0
	.4byte _080D4B1C @ case 1
	.4byte _080D4C38 @ case 2
	.4byte _080D4CD0 @ case 3
	.4byte _080D4CF4 @ case 4
_080D4AE0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r5, _080D4B18 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _080D4B0C
	b _080D4D28
_080D4B0C:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D4D28
	.align 2, 0
_080D4B18: .4byte 0x0000037E
_080D4B1C:
	ldr r1, _080D4B7C @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D4B30
	ldr r2, _080D4B80 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
_080D4B30:
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	movs r1, #0x2b
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D4B84 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4B88
	asrs r0, r0, #0xc
	b _080D4B8E
	.align 2, 0
_080D4B7C: .4byte 0x0000037E
_080D4B80: .4byte 0x000003F6
_080D4B84: .4byte gSineTable
_080D4B88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4B8E:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _080D4BB0 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4BB4
	asrs r0, r0, #0xc
	b _080D4BBA
	.align 2, 0
_080D4BB0: .4byte gSineTable
_080D4BB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4BBA:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r1, _080D4BE8 @ =0x0000037E
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #3
	bls _080D4BF4
	ldr r2, _080D4BEC @ =0x000003F6
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	blt _080D4BF0
	subs r0, r2, r0
	b _080D4BF2
	.align 2, 0
_080D4BE8: .4byte 0x0000037E
_080D4BEC: .4byte 0x000003F6
_080D4BF0:
	movs r0, #0
_080D4BF2:
	strh r0, [r1]
_080D4BF4:
	ldr r5, _080D4C30 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _080D4C0C
	b _080D4D28
_080D4C0C:
	ldr r2, _080D4C34 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080D4C18
	b _080D4D28
_080D4C18:
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	movs r1, #0xaa
	lsls r1, r1, #2
	bl Sound_PlayForPlayer
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	bl PlayerLink_SetAction
	b _080D4D28
	.align 2, 0
_080D4C30: .4byte 0x0000037E
_080D4C34: .4byte 0x000003F6
_080D4C38:
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D4C6C @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4C70
	asrs r0, r0, #0xc
	b _080D4C76
	.align 2, 0
_080D4C6C: .4byte gSineTable
_080D4C70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4C76:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4C94
	asrs r0, r0, #0xc
	b _080D4C9A
_080D4C94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4C9A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	beq _080D4D28
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #3
	bl PlayerLink_SetAction
	b _080D4D28
_080D4CD0:
	ldr r5, _080D4CF0 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _080D4D28
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #4
	bl PlayerLink_SetAction
	b _080D4D28
	.align 2, 0
_080D4CF0: .4byte 0x0000037E
_080D4CF4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	beq _080D4D28
	ldr r2, _080D4D30 @ =0x000003D2
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl PlayerLink_SetAnimFacing
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D4D28:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D4D30: .4byte 0x000003D2
