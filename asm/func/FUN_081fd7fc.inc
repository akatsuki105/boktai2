	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r5, r0, #0
	adds r6, r5, #0
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r8, r0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FD8E6
	movs r3, #0
	strb r3, [r1]
	add r2, sp, #0x14
	movs r1, #0xf0
	lsls r1, r1, #3
	adds r0, r2, #0
	strh r1, [r0]
	strh r3, [r2, #2]
	strh r1, [r2, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r2, #0
	blt _081FD84C
	ldr r0, _081FD850 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FD84C
	ldr r0, _081FD854 @ =0x030046AC
	ldr r1, [r0]
	movs r0, #7
	cmp r0, r1
	blo _081FD858
_081FD84C:
	movs r4, #0
	b _081FD860
	.align 2, 0
_081FD850: .4byte 0x030046A8
_081FD854: .4byte 0x030046AC
_081FD858:
	ldr r0, _081FD870 @ =0x030046A4
	ldr r0, [r0]
	ldrh r0, [r0, #0x32]
	adds r4, r0, r2
_081FD860:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FD874
	adds r0, #4
	b _081FD880
	.align 2, 0
_081FD870: .4byte 0x030046A4
_081FD874:
	ldr r0, _081FD908 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FD880:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	add r1, sp, #0x14
	strh r0, [r1, #2]
	adds r2, r5, #0
	adds r2, #0x50
	adds r3, r1, #0
	adds r0, r1, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r3, r4]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r6, r4
	bl NestedState_Reset0
_081FD8E6:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #8
	bls _081FD8FC
	b _081FDD08
_081FD8FC:
	lsls r0, r0, #2
	ldr r1, _081FD90C @ =_081FD910
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FD908: .4byte 0x030046A4
_081FD90C: .4byte _081FD910
_081FD910: @ jump table
	.4byte _081FD934 @ case 0
	.4byte _081FD980 @ case 1
	.4byte _081FD9D0 @ case 2
	.4byte _081FDA0A @ case 3
	.4byte _081FDC12 @ case 4
	.4byte _081FDC5C @ case 5
	.4byte _081FDCA8 @ case 6
	.4byte _081FDCE6 @ case 7
	.4byte _081FDD00 @ case 8
_081FD934:
	mov r2, r8
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _081FD968
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0x87
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #2
	bl Boss_PlayAnimFacing
	mov r0, r8
	str r4, [r0, #4]
	ldr r1, _081FD97C @ =0x000007CC
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #1
	bl FUN_08203d0c
_081FD968:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl Boss_AdvanceAnim
	b _081FDCEE
	.align 2, 0
_081FD97C: .4byte 0x000007CC
_081FD980:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FD9A8
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #4
	bl Boss_PlayAnimFacing
	mov r0, r8
	str r4, [r0, #4]
_081FD9A8:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl Boss_AdvanceAnim
	adds r0, r5, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	bne _081FD9C6
	b _081FDD08
_081FD9C6:
	mov r0, r8
	movs r1, #2
	bl NestedState_Set0
	b _081FDD08
_081FD9D0:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FD9F6
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r4, #1
	str r4, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #8
	bl Boss_PlayAnimFlip
	mov r0, r8
	str r4, [r0, #4]
_081FD9F6:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl Boss_AdvanceAnim
	b _081FDCEE
_081FDA0A:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FDA36
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r4, #1
	str r4, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #9
	bl Boss_PlayAnimFlip
	mov r0, r8
	str r4, [r0, #4]
	ldr r0, _081FDAB0 @ =0x000001B9
	bl PlaySound_082406e0
_081FDA36:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl Boss_AdvanceAnim
	ldr r0, _081FDAB4 @ =0x03002BE0
	ldr r2, [r0]
	adds r4, r5, #0
	adds r4, #0x50
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r0, #0
	subs r3, #0x1f
	ldr r2, _081FDAB8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FDABC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FDAC0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r3, r3, r0
	add r7, sp, #0x1c
	movs r2, #0xa
	mov ip, r2
	ldr r2, _081FDAC4 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	mov sl, r7
	cmp r0, #0
	blt _081FDAC8
	asrs r1, r0, #0xc
	b _081FDACE
	.align 2, 0
_081FDAB0: .4byte 0x000001B9
_081FDAB4: .4byte 0x03002BE0
_081FDAB8: .4byte 0x030046B8
_081FDABC: .4byte 0x000003FF
_081FDAC0: .4byte 0x0203B400
_081FDAC4: .4byte gSineTable
_081FDAC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FDACE:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	ldr r1, _081FDAF4 @ =gSineTable
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	mov sb, r1
	cmp r0, #0
	blt _081FDAF8
	asrs r0, r0, #0xc
	b _081FDAFE
	.align 2, 0
_081FDAF4: .4byte gSineTable
_081FDAF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FDAFE:
	strh r0, [r7, #4]
	ldr r0, _081FDB48 @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081FDBFE
	ldr r2, _081FDB4C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FDB50 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081FDB54 @ =0x0203B400
	adds r0, r0, r3
	movs r1, #0xff
	ldrb r0, [r0]
	mov ip, r0
	adds r0, r5, #0
	adds r0, #0x4d
	add r3, sp, #0x24
	ldrb r2, [r0]
	movs r5, #0x50
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r7, r3, #0
	cmp r0, #0
	blt _081FDB58
	asrs r1, r0, #0xc
	b _081FDB5E
	.align 2, 0
_081FDB48: .4byte 0x03002CF0
_081FDB4C: .4byte 0x030046B8
_081FDB50: .4byte 0x000003FF
_081FDB54: .4byte 0x0203B400
_081FDB58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FDB5E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r2, #1
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FDB76
	asrs r0, r0, #0xc
	b _081FDB7C
_081FDB76:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FDB7C:
	strh r0, [r3, #4]
	ldrh r2, [r7]
	subs r2, #0x20
	add r5, sp, #0x24
	strh r2, [r5]
	adds r7, r5, #0
	ldrh r1, [r7, #2]
	ldrh r3, [r7, #4]
	ldrh r0, [r4]
	adds r2, r2, r0
	strh r2, [r7]
	adds r1, #0x20
	ldrh r0, [r4, #2]
	adds r1, r1, r0
	strh r1, [r7, #2]
	subs r3, #0x20
	ldrh r4, [r4, #4]
	adds r3, r3, r4
	strh r3, [r7, #4]
	mov r1, ip
	cmp r1, #0x7f
	bgt _081FDBCE
	movs r3, #0x96
	lsls r3, r3, #1
	movs r1, #0xa
	str r1, [sp]
	movs r2, #0xfd
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #4
	b _081FDBF2
_081FDBCE:
	movs r3, #0x96
	lsls r3, r3, #1
	movs r1, #0xa
	str r1, [sp]
	movs r2, #0xfd
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #8
_081FDBF2:
	bl FUN_080df148
	mov r1, r8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
_081FDBFE:
	mov r2, r8
	ldr r0, [r2, #4]
	cmp r0, #0x1e
	bhi _081FDC08
	b _081FDD08
_081FDC08:
	mov r0, r8
	movs r1, #4
	bl NestedState_Set0
	b _081FDD08
_081FDC12:
	mov r3, r8
	ldr r0, [r3, #4]
	cmp r0, #0
	bne _081FDC3C
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #8
	bl Boss_PlayAnimFacing
	mov r1, r8
	str r4, [r1, #4]
_081FDC3C:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl Boss_AdvanceAnim
	mov r4, r8
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #0x64
	bls _081FDD08
	b _081FDCF8
_081FDC5C:
	mov r1, r8
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _081FDC90
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #4
	bl Boss_PlayAnimFacing
	mov r0, r8
	str r4, [r0, #4]
	ldr r1, _081FDCA4 @ =0x000007CC
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_08203d38
_081FDC90:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl Boss_AdvanceAnim
	b _081FDCEE
	.align 2, 0
_081FDCA4: .4byte 0x000007CC
_081FDCA8:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FDCD2
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #2
	bl Boss_PlayAnimFacing
	mov r0, r8
	str r4, [r0, #4]
_081FDCD2:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl Boss_AdvanceAnim
	b _081FDCEE
_081FDCE6:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081fa628
_081FDCEE:
	adds r0, r5, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FDD08
_081FDCF8:
	mov r0, r8
	bl NestedState_Advance0
	b _081FDD08
_081FDD00:
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FDD08:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
