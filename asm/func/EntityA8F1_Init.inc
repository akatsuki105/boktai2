	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	str r1, [sp]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A36BC
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0x98
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0x9a
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x9c
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xc]
	cmp r2, #0
	blt _080A365C
	cmp r1, #0
	blt _080A365C
	ldr r0, _080A3660 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A365C
	ldr r0, _080A3664 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A3668
_080A365C:
	movs r6, #0
	b _080A3676
	.align 2, 0
_080A3660: .4byte 0x030046A8
_080A3664: .4byte 0x030046AC
_080A3668:
	ldr r0, _080A3688 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A3676:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A368C
	adds r0, #4
	b _080A3698
	.align 2, 0
_080A3688: .4byte 0x030046A4
_080A368C:
	ldr r0, _080A36AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A3698:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A36B0
	cmp r2, #2
	beq _080A36B4
	b _080A36B8
	.align 2, 0
_080A36AC: .4byte 0x030046A4
_080A36B0:
	ldrb r0, [r4, #4]
	b _080A36B6
_080A36B4:
	ldrb r0, [r4]
_080A36B6:
	subs r1, r1, r0
_080A36B8:
	strh r1, [r5]
	b _080A36CE
_080A36BC:
	adds r1, r7, #0
	adds r1, #0x98
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0x9a
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	str r1, [sp, #0xc]
_080A36CE:
	movs r0, #0x43
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A36E8
	bl VM_GetValue
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A36F0
_080A36E8:
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A36F0:
	movs r0, #0x63
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A370A
	bl VM_GetValue
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3712
_080A370A:
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3712:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A372C
	bl VM_GetValue
	movs r2, #0xdc
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3734
_080A372C:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3734:
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A374E
	bl VM_GetValue
	movs r2, #0xdd
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3756
_080A374E:
	movs r3, #0xdd
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3756:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A376A
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x4e
	b _080A3770
_080A376A:
	adds r1, r7, #0
	adds r1, #0x4e
	movs r0, #6
_080A3770:
	strh r0, [r1]
	mov sl, r1
	movs r0, #0x61
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3790
	bl VM_GetValue
	ldr r2, _080A378C @ =0x00000369
	adds r1, r7, r2
	strb r0, [r1]
	b _080A3796
	.align 2, 0
_080A378C: .4byte 0x00000369
_080A3790:
	ldr r3, _080A37B0 @ =0x00000369
	adds r0, r7, r3
	strb r1, [r0]
_080A3796:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A37B4
	bl VM_GetValue
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A37BC
	.align 2, 0
_080A37B0: .4byte 0x00000369
_080A37B4:
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A37BC:
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #0x61
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r6, r7, r2
	strh r1, [r6]
	movs r3, #0x7c
	adds r3, r3, r7
	mov r8, r3
	ldr r5, _080A3930 @ =0x00000BA8
	mov r0, r8
	adds r1, r5, #0
	bl Video_GetAuxSprite
	adds r4, r7, #0
	adds r4, #0x50
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	mov r1, sl
	ldrh r0, [r1]
	strh r0, [r4, #0x10]
	ldrh r1, [r6]
	mov r0, r8
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x50]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x50]
	adds r0, r7, #0
	adds r0, #0x57
	movs r2, #3
	mov sb, r2
	mov r3, sb
	strb r3, [r0]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x6c]
	str r1, [r7, #0x70]
	adds r4, #0x7c
	adds r0, r4, #0
	adds r1, r5, #0
	bl Video_GetAuxSprite
	adds r5, r7, #0
	adds r5, #0xa0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r3, sl
	ldrh r0, [r3]
	strh r0, [r5, #0x10]
	ldrh r1, [r6]
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r5]
	adds r0, r7, #0
	adds r0, #0xa7
	mov r1, sb
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0xbc
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	mov sb, r0
	mov r1, r8
	str r1, [sp, #8]
	mov r8, r5
	adds r2, #0x2c
	str r2, [sp, #0x10]
	adds r3, r7, #0
	adds r3, #0x18
	str r3, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x4c
	str r0, [sp, #4]
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r6, r7, r1
_080A3882:
	adds r0, r6, #0
	ldr r1, _080A3930 @ =0x00000BA8
	bl Video_GetAuxSprite
	movs r0, #0x2c
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0xe8
	adds r0, r7, r0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r2, sl
	ldrh r0, [r2]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r0
	adds r0, r4, r7
	adds r0, #0xe8
	adds r1, #0x10
	strh r1, [r0, #0x10]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	adds r1, #2
	adds r0, r6, #0
	bl Video_SetAuxSpritePltt
	ldr r0, [sp, #0x10]
	adds r2, r0, r4
	ldr r0, [r2]
	ldr r1, _080A3934 @ =0x00000201
	orrs r0, r1
	str r0, [r2]
	adds r1, r7, r4
	adds r0, r1, #0
	adds r0, #0xef
	movs r2, #1
	strb r2, [r0]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r2, r1, r3
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, #0x1c
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #2
	ble _080A3882
	adds r0, r7, #0
	bl FUN_080a3568
	ldr r0, [sp, #0x14]
	ldr r1, [sp]
	movs r2, #0xa
	bl MsgQueue_Register
	movs r0, #0x44
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3940
	movs r2, #0
	movs r1, #0
	ldr r3, [sp, #4]
	strh r1, [r3]
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	ldr r3, _080A3938 @ =0x0000036A
	adds r0, r7, r3
	strh r1, [r0]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, _080A393C @ =FUN_080a2a2c
	b _080A3A70
	.align 2, 0
_080A3930: .4byte 0x00000BA8
_080A3934: .4byte 0x00000201
_080A3938: .4byte 0x0000036A
_080A393C: .4byte FUN_080a2a2c
_080A3940:
	movs r4, #0
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3952
	bl VM_GetValue
	adds r4, r0, #0
_080A3952:
	movs r6, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3964
	bl VM_GetValue
	adds r6, r0, #0
_080A3964:
	cmp r4, #0
	beq _080A3A24
	movs r0, #0xb0
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r5, [r0]
	movs r0, #0
	bl FUN_080a6e88
	ldr r4, _080A3A18 @ =0x03002BE0
	ldr r0, [r4]
	ldr r1, [sp, #0xc]
	bl FUN_0807a91c
	ldr r0, [r4]
	bl FUN_0807b8dc
	ldr r0, [r7, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x50]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	adds r1, #2
	ldr r0, [sp, #8]
	bl Video_SetAuxSpritePltt
	mov r1, r8
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #7
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080a2804
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #8
	strh r0, [r1]
	ldr r0, [sp, #4]
	strh r5, [r0]
	ldr r2, _080A3A1C @ =0x0000036A
	adds r1, r7, r2
	movs r0, #0xa
	strh r0, [r1]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0x18
	strb r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r6, [r0]
	ldr r1, _080A3A20 @ =FUN_080a31dc
	adds r0, r7, #0
	bl FUN_080a2a14
	movs r4, #0
	movs r0, #0x77
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3A02
	bl VM_GetValue
	adds r4, r0, #0
_080A3A02:
	cmp r4, #0
	beq _080A3A88
	bl FUN_08086af0
	cmp r0, #0
	beq _080A3A88
	ldr r0, [sp, #0xc]
	bl FUN_08086a4c
	b _080A3A88
	.align 2, 0
_080A3A18: .4byte 0x03002BE0
_080A3A1C: .4byte 0x0000036A
_080A3A20: .4byte FUN_080a31dc
_080A3A24:
	movs r0, #0
	ldr r2, [sp, #4]
	strh r4, [r2]
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r4, [r1]
	ldr r2, _080A3A78 @ =0x0000036A
	adds r1, r7, r2
	strh r4, [r1]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r1, r7, r3
	strb r0, [r1]
	cmp r6, #0
	beq _080A3A80
	movs r0, #0xaf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, [r7, #0x50]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x50]
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0x58
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #0x4f
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r1, _080A3A7C @ =FUN_080a2d18
_080A3A70:
	adds r0, r7, #0
	bl FUN_080a2a14
	b _080A3A88
	.align 2, 0
_080A3A78: .4byte 0x0000036A
_080A3A7C: .4byte FUN_080a2d18
_080A3A80:
	ldr r1, _080A3A9C @ =FUN_080a2e20
	adds r0, r7, #0
	bl FUN_080a2a14
_080A3A88:
	movs r0, #0
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A3A9C: .4byte FUN_080a2e20
