	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _0806B48E
	ldr r2, _0806B470 @ =0x00000951
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #0x64
	bl FUN_08064d54
	cmp r0, #0
	beq _0806B47C
	ldr r0, _0806B474 @ =0x03002BD0
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806B47C
	ldr r3, _0806B478 @ =0x000003FA
	adds r1, r4, r3
	movs r0, #1
	b _0806B482
	.align 2, 0
_0806B470: .4byte 0x00000951
_0806B474: .4byte 0x03002BD0
_0806B478: .4byte 0x000003FA
_0806B47C:
	ldr r0, _0806B4A4 @ =0x000003FA
	adds r1, r4, r0
	movs r0, #0
_0806B482:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	movs r2, #0
	bl FUN_08060b84
_0806B48E:
	ldr r1, _0806B4A8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _0806B49A
	b _0806B5F8
_0806B49A:
	cmp r2, #1
	bgt _0806B4AC
	cmp r2, #0
	beq _0806B4BA
	b _0806B74E
	.align 2, 0
_0806B4A4: .4byte 0x000003FA
_0806B4A8: .4byte 0x0000037D
_0806B4AC:
	cmp r2, #2
	bne _0806B4B2
	b _0806B688
_0806B4B2:
	cmp r2, #3
	bne _0806B4B8
	b _0806B718
_0806B4B8:
	b _0806B74E
_0806B4BA:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0806B51C
	movs r1, #4
	strb r1, [r3]
	ldr r3, _0806B50C @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0806B510 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r0, _0806B514 @ =0x00000932
	adds r1, r4, r0
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _0806B518 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _0806B556
	.align 2, 0
_0806B50C: .4byte 0x000002E6
_0806B510: .4byte 0x000002E7
_0806B514: .4byte 0x00000932
_0806B518: .4byte 0x00000934
_0806B51C:
	strb r2, [r3]
	ldr r1, _0806B584 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _0806B588 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _0806B58C @ =0x00000932
	adds r1, r4, r2
	movs r3, #0xa5
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _0806B590 @ =0x00000934
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #0x14
_0806B556:
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bne _0806B594
	ldr r3, _0806B584 @ =0x000002E6
	adds r1, r4, r3
	movs r0, #1
	b _0806B59A
	.align 2, 0
_0806B584: .4byte 0x000002E6
_0806B588: .4byte 0x000002E7
_0806B58C: .4byte 0x00000932
_0806B590: .4byte 0x00000934
_0806B594:
	ldr r0, _0806B5E8 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #0
_0806B59A:
	strb r0, [r1]
	ldr r1, _0806B5EC @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806B5DC
	movs r0, #0xb9
	lsls r0, r0, #2
	bl PlaySound_082406e0
	ldr r2, _0806B5F0 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r3, _0806B5F4 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_080abd14
_0806B5DC:
	adds r0, r4, #0
	movs r1, #9
	movs r2, #1
	bl FUN_08060b84
	b _0806B74E
	.align 2, 0
_0806B5E8: .4byte 0x000002E6
_0806B5EC: .4byte 0x000003FA
_0806B5F0: .4byte 0x0000095E
_0806B5F4: .4byte 0x000003BA
_0806B5F8:
	ldr r1, _0806B678 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806B624
	ldr r2, _0806B67C @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806B624
	movs r0, #0x20
	strh r0, [r1]
_0806B624:
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
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _0806B64C
	b _0806B74E
_0806B64C:
	movs r0, #0xcb
	bl PlaySound_082406e0
	ldr r2, _0806B678 @ =0x000003FA
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806B66C
	ldr r3, _0806B680 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806B66C
	ldr r1, _0806B684 @ =0x03002BD0
	movs r0, #1
	strh r0, [r1]
_0806B66C:
	adds r0, r4, #0
	movs r1, #9
	movs r2, #2
	bl FUN_08060b84
	b _0806B74E
	.align 2, 0
_0806B678: .4byte 0x000003FA
_0806B67C: .4byte 0x0000095E
_0806B680: .4byte 0x000003BA
_0806B684: .4byte 0x03002BD0
_0806B688:
	ldr r1, _0806B6B8 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806B6C0
	ldr r2, _0806B6BC @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806B6D2
	movs r0, #0x20
	strh r0, [r1]
	b _0806B6D2
	.align 2, 0
_0806B6B8: .4byte 0x000003FA
_0806B6BC: .4byte 0x0000095E
_0806B6C0:
	ldr r1, _0806B714 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806B6D2
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806B6D2:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _0806B714 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _0806B74E
	adds r0, r4, #0
	movs r1, #9
	movs r2, #3
	bl FUN_08060b84
	b _0806B74E
	.align 2, 0
_0806B714: .4byte 0x0000037E
_0806B718:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806B74E
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806B74E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
