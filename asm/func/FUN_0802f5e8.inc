	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov r8, r0
	mov r5, r8
	mov r1, r8
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	bne _0802F604
	b _0802F894
_0802F604:
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0xb5
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, r8
	movs r3, #0x2c
	bl Boss_PlayAnimFlip
	mov sl, r8
	movs r0, #0xbd
	lsls r0, r0, #2
	add r0, r8
	str r0, [sp, #0x24]
	movs r6, #0xa4
	lsls r6, r6, #4
	add r6, r8
	mov r0, r8
	bl FUN_08028ec8
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0xa2
	lsls r1, r1, #4
	add r1, r8
	str r4, [sp]
	adds r0, r6, #0
	movs r3, #1
	bl MainSprite_SetAnim
	mov r0, r8
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802F660
	ldr r0, [r6, #8]
	orrs r0, r4
	b _0802F668
_0802F660:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0802F668:
	str r0, [r6, #8]
	ldr r1, _0802F6C0 @ =0x00000173
	adds r4, r5, r1
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r1, r1, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sl
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _0802F6C4 @ =0x00000A18
	adds r2, r5, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, [sp, #0x24]
	ldr r0, [r2, #0x20]
	ldr r1, [r2, #0x24]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	adds r7, r6, #0
	adds r7, #0x20
	add r3, sp, #0x14
	mov ip, r3
	add r0, sp, #0x14
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	mov r1, ip
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov sb, r4
	cmp r0, #0
	blt _0802F6C8
	asrs r0, r0, #8
	b _0802F6CE
	.align 2, 0
_0802F6C0: .4byte 0x00000173
_0802F6C4: .4byte 0x00000A18
_0802F6C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802F6CE:
	strh r0, [r7]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0802F6E0
	asrs r0, r0, #8
	b _0802F6E6
_0802F6E0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802F6E6:
	adds r4, r0, #0
	mov r2, ip
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0802F6FC
	asrs r0, r0, #8
	b _0802F702
_0802F6FC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802F702:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0802F744 @ =0x030047C8
	ldrh r0, [r7]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r7]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r7, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r7, #4]
	mov r0, sl
	adds r0, #0xaf
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _0802F74C
	ldr r0, _0802F748 @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r6, #0x20]
	adds r1, r1, r2
	strh r1, [r6, #0x20]
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r6, #0x22]
	adds r0, r0, r1
	b _0802F760
	.align 2, 0
_0802F744: .4byte 0x030047C8
_0802F748: .4byte 0x085AABBC
_0802F74C:
	ldr r2, _0802F790 @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldrh r0, [r6, #0x20]
	subs r0, r0, r1
	strh r0, [r6, #0x20]
	movs r0, #1
	ldrsb r0, [r2, r0]
	ldrh r2, [r6, #0x22]
	adds r0, r0, r2
_0802F760:
	strh r0, [r6, #0x22]
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r0, _0802F794 @ =0x00000A14
	adds r1, r5, r0
	ldr r0, _0802F798 @ =0x0000FFFF
	strh r0, [r1]
	ldr r2, [sp, #0x24]
	ldrh r1, [r2, #0x14]
	ldr r2, _0802F79C @ =0x00000A16
	adds r0, r5, r2
	strh r1, [r0]
	ldrb r0, [r3]
	cmp r0, #0
	bne _0802F7A4
	ldr r3, _0802F7A0 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r3
	movs r1, #0x20
	b _0802F7AC
	.align 2, 0
_0802F790: .4byte 0x085AABBC
_0802F794: .4byte 0x00000A14
_0802F798: .4byte 0x0000FFFF
_0802F79C: .4byte 0x00000A16
_0802F7A0: .4byte 0xFFFF0000
_0802F7A4:
	ldr r3, _0802F824 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r3
	ldr r1, _0802F828 @ =0x0000FFE0
_0802F7AC:
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r2, sp, #0x1c
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r1, _0802F82C @ =0x0000FFFF
	ldr r0, [sp, #0x1c]
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	adds r4, r2, #0
	mov r0, sl
	adds r0, #0xab
	ldrb r3, [r0]
	cmp r3, #0
	bne _0802F7FC
	mov r1, sb
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _0802F830 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [sp, #0x24]
	adds r1, #0x20
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #1
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #2
	str r2, [sp, #0x10]
	adds r2, r4, #0
	movs r3, #0
	bl FUN_0807ab64
_0802F7FC:
	movs r0, #0x84
	lsls r0, r0, #7
	strh r0, [r6, #0x3a]
	mov r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	ldr r1, _0802F830 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r3, _0802F834 @ =0x00000359
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802F838
	adds r0, r1, #0
	adds r0, #0xd0
	ldr r0, [r0]
	b _0802F842
	.align 2, 0
_0802F824: .4byte 0xFFFF0000
_0802F828: .4byte 0x0000FFE0
_0802F82C: .4byte 0x0000FFFF
_0802F830: .4byte 0x03002BE0
_0802F834: .4byte 0x00000359
_0802F838:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
_0802F842:
	str r0, [r6, #0x48]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0802F8F4 @ =0x00000874
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	adds r3, #0x17
	adds r1, r5, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0802F886
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r3, _0802F8F8 @ =0x00000876
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
_0802F886:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _0802F8FC @ =0x0000016D
	adds r0, r5, r3
	strb r2, [r0]
_0802F894:
	mov r0, r8
	adds r0, #0xfc
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802F90C
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r4, [r0]
	ldr r2, _0802F900 @ =0x00000173
	adds r2, r2, r5
	mov sb, r2
	cmp r4, #0
	bne _0802F8EC
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _0802F8EC
	ldr r1, _0802F904 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _0802F908 @ =0x00000A18
	adds r1, r5, r3
	adds r2, r5, #0
	adds r2, #0x4d
	ldrb r3, [r2]
	movs r2, #0x32
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_0807ac74
_0802F8EC:
	movs r0, #0xff
	mov r1, sb
	b _0802FA88
	.align 2, 0
_0802F8F4: .4byte 0x00000874
_0802F8F8: .4byte 0x00000876
_0802F8FC: .4byte 0x0000016D
_0802F900: .4byte 0x00000173
_0802F904: .4byte 0x03002BE0
_0802F908: .4byte 0x00000A18
_0802F90C:
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, r8
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _0802F97C
	movs r2, #0xa4
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r4, [r0]
	ldr r3, _0802F970 @ =0x00000173
	adds r3, r3, r5
	mov sb, r3
	cmp r4, #0
	bne _0802F968
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _0802F968
	ldr r1, _0802F974 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _0802F978 @ =0x00000A18
	adds r1, r5, r2
	adds r2, r5, #0
	adds r2, #0x4d
	ldrb r3, [r2]
	movs r2, #0x32
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_0807ac74
_0802F968:
	movs r0, #0xff
	mov r3, sb
	strb r0, [r3]
	b _0802FA8A
	.align 2, 0
_0802F970: .4byte 0x00000173
_0802F974: .4byte 0x03002BE0
_0802F978: .4byte 0x00000A18
_0802F97C:
	ldr r0, _0802FA9C @ =0x00000173
	adds r0, r0, r5
	mov sb, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	movs r7, #0x82
	lsls r7, r7, #1
	add r7, r8
	adds r0, r7, r0
	ldr r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrb r2, [r0]
	ldr r0, _0802FAA0 @ =0x00000877
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, r2
	beq _0802F9B2
	strb r2, [r1]
	ldr r2, _0802FAA4 @ =0x0000016D
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802F9B2:
	ldr r0, _0802FAA4 @ =0x0000016D
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #3
	bls _0802F9E0
	adds r0, r3, #0
	bl Player_GetDpadFacing
	lsls r0, r0, #0x1d
	movs r1, #0xa0
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0x10
	strb r0, [r1]
	strb r6, [r4]
_0802F9E0:
	mov r1, sb
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r0, [r0]
	ldr r2, _0802FAA8 @ =0x00000876
	adds r1, r5, r2
	ldrb r1, [r1]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r0, [r0]
	ldr r2, _0802FAAC @ =0xFFFFFF00
	adds r1, r1, r2
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0xf
	ble _0802FA0E
	ldr r3, _0802FAB0 @ =0x00000874
	adds r0, r5, r3
	strh r6, [r0]
_0802FA0E:
	ldr r1, _0802FAB4 @ =0x00000311
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802FA50
	movs r1, #4
	ldr r0, _0802FAB8 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0802FA50
	ldr r2, _0802FAB0 @ =0x00000874
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	ble _0802FA50
	movs r0, #0xae
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #3
	bhi _0802FA50
	movs r3, #0xc2
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
_0802FA50:
	ldr r1, _0802FAB4 @ =0x00000311
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802FA8A
	movs r1, #4
	ldr r0, _0802FAB8 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0802FA82
	ldr r2, _0802FAB0 @ =0x00000874
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _0802FA82
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0802FA8A
_0802FA82:
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
_0802FA88:
	strb r0, [r1]
_0802FA8A:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802FA9C: .4byte 0x00000173
_0802FAA0: .4byte 0x00000877
_0802FAA4: .4byte 0x0000016D
_0802FAA8: .4byte 0x00000876
_0802FAAC: .4byte 0xFFFFFF00
_0802FAB0: .4byte 0x00000874
_0802FAB4: .4byte 0x00000311
_0802FAB8: .4byte 0x03002BC0
