	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r1, _080D3B30 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _080D3B26
	b _080D3F04
_080D3B26:
	lsls r0, r0, #2
	ldr r1, _080D3B34 @ =_080D3B38
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3B30: .4byte 0x0000037D
_080D3B34: .4byte _080D3B38
_080D3B38: @ jump table
	.4byte _080D3B58 @ case 0
	.4byte _080D3B82 @ case 1
	.4byte _080D3C3C @ case 2
	.4byte _080D3F04 @ case 3
	.4byte _080D3CE0 @ case 4
	.4byte _080D3D28 @ case 5
	.4byte _080D3E54 @ case 6
	.4byte _080D3ED0 @ case 7
_080D3B58:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	bne _080D3B76
	b _080D3F04
_080D3B76:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D3F04
_080D3B82:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r2, _080D3BD8 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _080D3BB4
	b _080D3F04
_080D3BB4:
	ldr r0, _080D3BDC @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r2, #0x68
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bhi _080D3BE0
	ldr r0, [r5, #0x18]
	movs r1, #0xd5
	b _080D3D18
	.align 2, 0
_080D3BD8: .4byte 0x0000037E
_080D3BDC: .4byte 0x00000A8F
_080D3BE0:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D3C08
	ldr r0, [r5, #0x18]
	movs r1, #0xfb
	lsls r1, r1, #1
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl PlayerLink_SetAction
	b _080D3C12
_080D3C08:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl PlayerLink_SetAction
_080D3C12:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2e
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	str r1, [sp, #0xc]
	movs r0, #0x1e
	str r0, [sp, #0x10]
	movs r0, #0x11
	str r0, [sp, #0x14]
	movs r0, #0x14
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xc8
	movs r2, #0xaa
	movs r3, #8
	bl Entity08080be8_Create
	b _080D3F04
_080D3C3C:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r2, _080D3CC8 @ =0x0000037E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #6
	bne _080D3C6E
	ldr r0, [r5, #0x18]
	movs r1, #0xfa
	lsls r1, r1, #1
	bl Sound_PlayForPlayer
_080D3C6E:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3D12
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _080D3C90
	b _080D3F04
_080D3C90:
	ldr r2, _080D3CCC @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D3CD0 @ =0x000003E6
	adds r1, r5, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r2, _080D3CD4 @ =0x0000095E
	adds r1, r5, r2
	ldr r0, _080D3CD8 @ =0x00000121
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x24
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D3CDC @ =0x000001F5
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl PlayerLink_SetAction
	b _080D3F04
	.align 2, 0
_080D3CC8: .4byte 0x0000037E
_080D3CCC: .4byte 0x00000A8F
_080D3CD0: .4byte 0x000003E6
_080D3CD4: .4byte 0x0000095E
_080D3CD8: .4byte 0x00000121
_080D3CDC: .4byte 0x000001F5
_080D3CE0:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3D12
	b _080D3F04
_080D3D12:
	ldr r0, [r5, #0x18]
	movs r1, #0xfb
	lsls r1, r1, #1
_080D3D18:
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl PlayerLink_SetAction
	b _080D3F04
_080D3D28:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x28
	bl FUN_08066ee4
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
	beq _080D3D5A
	ldr r0, _080D3DD4 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D3D5A:
	ldr r1, _080D3DD8 @ =0x000003E6
	adds r6, r5, r1
	ldrh r0, [r6]
	cmp r0, #0
	beq _080D3E30
	cmp r0, #5
	bls _080D3DA6
	ldr r3, _080D3DDC @ =0xFFFF0000
	ldr r1, _080D3DE0 @ =0x0000FFFF
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
_080D3DA6:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r6]
	ldr r2, _080D3DE4 @ =gSineTable
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
	blt _080D3DE8
	asrs r0, r0, #0xc
	b _080D3DEE
	.align 2, 0
_080D3DD4: .4byte 0x00000A76
_080D3DD8: .4byte 0x000003E6
_080D3DDC: .4byte 0xFFFF0000
_080D3DE0: .4byte 0x0000FFFF
_080D3DE4: .4byte gSineTable
_080D3DE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D3DEE:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _080D3E0C @ =0x000003E6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D3E10
	asrs r0, r0, #0xc
	b _080D3E16
	.align 2, 0
_080D3E0C: .4byte 0x000003E6
_080D3E10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D3E16:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _080D3E2C @ =0x000003E6
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080D3F04
	.align 2, 0
_080D3E2C: .4byte 0x000003E6
_080D3E30:
	ldr r2, _080D3E50 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3F04
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl PlayerLink_SetAction
	b _080D3F04
	.align 2, 0
_080D3E50: .4byte 0x0000037E
_080D3E54:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
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
	beq _080D3E86
	ldr r0, _080D3EA0 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D3E86:
	ldr r1, _080D3EA0 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D3EA8
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080D3EA4 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080D3F04
	.align 2, 0
_080D3EA0: .4byte 0x00000A76
_080D3EA4: .4byte 0x0000037D
_080D3EA8:
	ldr r0, _080D3ECC @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080D3F04
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl PlayerLink_SetAction
	b _080D3F04
	.align 2, 0
_080D3ECC: .4byte 0x0000037E
_080D3ED0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r2, _080D3F14 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3F04
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D3F04:
	ldr r0, _080D3F18 @ =0x00000951
	adds r1, r5, r0
	movs r0, #4
	strb r0, [r1]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D3F14: .4byte 0x0000037E
_080D3F18: .4byte 0x00000951
