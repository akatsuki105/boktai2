	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r2, [r4]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r4]
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r6, [r0]
	cmp r6, #2
	bne _0821EA94
	b _0821EE9C
_0821EA94:
	cmp r6, #2
	bgt _0821EAA4
	cmp r6, #0
	beq _0821EAAC
	cmp r6, #1
	bne _0821EAA2
	b _0821EBFA
_0821EAA2:
	b _0821F0D6
_0821EAA4:
	cmp r6, #3
	bne _0821EAAA
	b _0821EFE8
_0821EAAA:
	b _0821F0D6
_0821EAAC:
	movs r1, #2
	ands r1, r2
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r4]
	cmp r1, #0
	beq _0821EADA
	movs r2, #0xed
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, r7, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	str r6, [sp]
	str r6, [sp, #4]
	adds r0, r7, #0
	movs r1, #0x11
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_0821EADA:
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	cmp r1, #0
	ble _0821EB2E
	movs r2, #0x38
	cmp r1, #0x7f
	bgt _0821EB08
	adds r0, r1, #0
	muls r0, r2, r0
	cmp r0, #0
	blt _0821EAFA
	asrs r1, r0, #6
	b _0821EB00
_0821EAFA:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0821EB00:
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r7, r2
	b _0821EB2C
_0821EB08:
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r0, #0
	muls r1, r2, r1
	movs r0, #8
	lsls r0, r0, #8
	subs r0, #8
	adds r0, r1, r0
	cmp r0, #0
	blt _0821EB20
	asrs r1, r0, #6
	b _0821EB26
_0821EB20:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0821EB26:
	movs r4, #0xef
	lsls r4, r4, #2
	adds r0, r7, r4
_0821EB2C:
	strh r1, [r0]
_0821EB2E:
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	cmp r0, #0x19
	bne _0821EB4C
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0x13
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_0821EB4C:
	ldr r0, [r4]
	cmp r0, #0x2c
	bgt _0821EBB4
	movs r1, #0x2d
	subs r1, r1, r0
	adds r4, r7, #0
	adds r4, #0x58
	movs r2, #0xed
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x80
	asrs r5, r1, #2
	ldr r2, _0821EB84 @ =0x085B0A08
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821EB88
	asrs r1, r0, #0xc
	b _0821EB8E
	.align 2, 0
_0821EB84: .4byte 0x085B0A08
_0821EB88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821EB8E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821EBAA
	asrs r0, r0, #0xc
	b _0821EBB0
_0821EBAA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821EBB0:
	strh r0, [r4, #4]
	b _0821F0D6
_0821EBB4:
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r4, #0
	strh r4, [r0]
	adds r0, r7, #0
	bl FUN_0821e5f0
	adds r2, r0, #0
	cmp r2, #0
	beq _0821EBDE
	movs r2, #2
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r7, r1
	str r2, [r0]
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r7, r3
	str r4, [r0]
	b _0821EFD4
_0821EBDE:
	movs r1, #1
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r7, r4
	str r2, [r0]
	movs r2, #2
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r7, r0
	b _0821EFDA
_0821EBFA:
	movs r1, #2
	ands r1, r2
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r4]
	cmp r1, #0
	beq _0821EC9E
	movs r2, #0xed
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, r7, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	str r6, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #9
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r4, #4
	ldrsh r3, [r0, r4]
	adds r0, r7, #0
	adds r0, #0xcc
	movs r4, #0
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0xce
	strh r2, [r1]
	adds r2, r7, #0
	adds r2, #0xd0
	strh r3, [r2]
	movs r1, #0xdc
	adds r1, r1, r7
	mov r8, r1
	strb r4, [r1]
	adds r1, r7, #0
	adds r1, #0x48
	movs r3, #0
	ldrsh r5, [r0, r3]
	movs r4, #8
	ldrsh r0, [r1, r4]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r1, r7, #0
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	mov r3, r8
	strb r6, [r3]
	ldr r0, _0821ECC8 @ =0x0000034A
	bl PlaySound_082406e0
_0821EC9E:
	adds r4, r7, #0
	adds r4, #0x58
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r3, [r0]
	movs r5, #0x28
	ldr r2, _0821ECCC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821ECD0
	asrs r1, r0, #0xc
	b _0821ECD6
	.align 2, 0
_0821ECC8: .4byte 0x0000034A
_0821ECCC: .4byte 0x085B0A08
_0821ECD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821ECD6:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821ECF2
	asrs r0, r0, #0xc
	b _0821ECF8
_0821ECF2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821ECF8:
	strh r0, [r4, #4]
	adds r0, r7, #0
	bl FUN_0821e5f0
	cmp r0, #0
	beq _0821ED26
	movs r2, #2
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r7, r3
	str r2, [r0]
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r0, #0
	str r0, [r1]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0821EE7C
_0821ED26:
	movs r5, #0xc8
	lsls r5, r5, #1
	add r4, sp, #8
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r3, [r0]
	ldr r2, _0821ED50 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821ED54
	asrs r1, r0, #0xc
	b _0821ED5A
	.align 2, 0
_0821ED50: .4byte 0x085B0A08
_0821ED54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821ED5A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821ED76
	asrs r0, r0, #0xc
	b _0821ED7C
_0821ED76:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821ED7C:
	strh r0, [r4, #4]
	adds r3, r7, #0
	adds r3, #0x50
	add r2, sp, #8
	adds r1, r2, #0
	ldrh r0, [r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r3, #4]
	ldrh r3, [r2, #4]
	adds r1, r1, r3
	strh r1, [r2, #4]
	adds r5, r2, #0
	adds r0, r2, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0821EDC6
	cmp r1, #0
	blt _0821EDC6
	ldr r0, _0821EDCC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0821EDC6
	ldr r0, _0821EDD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0821EDD4
_0821EDC6:
	movs r4, #0
	b _0821EDE2
	.align 2, 0
_0821EDCC: .4byte 0x030046A8
_0821EDD0: .4byte 0x030046AC
_0821EDD4:
	ldr r0, _0821EDF4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0821EDE2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0821EDF8
	adds r0, #4
	b _0821EE04
	.align 2, 0
_0821EDF4: .4byte 0x030046A4
_0821EDF8:
	ldr r0, _0821EE18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0821EE04:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0821EE1C
	cmp r2, #2
	beq _0821EE20
	b _0821EE24
	.align 2, 0
_0821EE18: .4byte 0x030046A4
_0821EE1C:
	ldrb r0, [r5, #4]
	b _0821EE22
_0821EE20:
	ldrb r0, [r5]
_0821EE22:
	subs r1, r1, r0
_0821EE24:
	movs r4, #0xec
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r0, [r0]
	subs r0, r1, r0
	ldr r1, _0821EE74 @ =0x000001FF
	adds r0, r0, r1
	adds r1, #0xff
	movs r2, #0
	cmp r0, r1
	bls _0821EE3C
	movs r2, #1
_0821EE3C:
	cmp r2, #0
	bne _0821EE54
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r2, r7, r3
	ldr r4, _0821EE78 @ =0x00000804
	adds r0, r7, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r2]
	cmp r0, r1
	blt _0821EE7C
_0821EE54:
	movs r1, #3
	movs r4, #0xe8
	lsls r4, r4, #2
	adds r0, r7, r4
	str r1, [r0]
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	str r0, [r1]
	movs r2, #2
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r1, r7, r3
	b _0821EFDA
	.align 2, 0
_0821EE74: .4byte 0x000001FF
_0821EE78: .4byte 0x00000804
_0821EE7C:
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r0, [r0]
	movs r1, #6
	bl Mod
	cmp r0, #0
	beq _0821EE90
	b _0821F0D6
_0821EE90:
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x14
	bl FUN_0821ddc4
	b _0821F0D6
_0821EE9C:
	ands r6, r2
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r4]
	cmp r6, #0
	beq _0821EECE
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0xb
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #0x20
	bl FUN_0823723c
	ldr r0, _0821EF10 @ =0x0000034B
	bl PlaySound_082406e0
_0821EECE:
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r5, r7, r2
	ldrh r0, [r5]
	cmp r0, #6
	bne _0821EEE6
	movs r3, #0xaf
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r1, #0x40
	bl FUN_0823723c
_0821EEE6:
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _0821EF28
	ldrh r0, [r5]
	cmp r0, #7
	bne _0821EF28
	movs r0, #0x20
	ldr r1, [r4]
	ands r0, r1
	cmp r0, #0
	bne _0821EF18
	ldr r2, _0821EF14 @ =0x00000809
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0821EF20
	.align 2, 0
_0821EF10: .4byte 0x0000034B
_0821EF14: .4byte 0x00000809
_0821EF18:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r4]
_0821EF20:
	ldr r3, _0821EF90 @ =0x000003DB
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
_0821EF28:
	movs r2, #8
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0xaf
	lsls r4, r4, #2
	adds r0, r7, r4
	ldrh r0, [r0, #0x14]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _0821EF56
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0821EF56:
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #9
	bgt _0821EFC2
	movs r1, #0xa
	subs r1, r1, r0
	adds r4, r7, #0
	adds r4, #0x58
	movs r2, #0xed
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r3, [r0]
	lsls r5, r1, #2
	ldr r2, _0821EF94 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821EF98
	asrs r1, r0, #0xc
	b _0821EF9E
	.align 2, 0
_0821EF90: .4byte 0x000003DB
_0821EF94: .4byte 0x085B0A08
_0821EF98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821EF9E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821EFBA
	asrs r0, r0, #0xc
	b _0821EFC0
_0821EFBA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821EFC0:
	strh r0, [r4, #4]
_0821EFC2:
	ldr r3, _0821EFE4 @ =0x000002D9
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0821EFD2
	b _0821F0D6
_0821EFD2:
	movs r2, #0x10
_0821EFD4:
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r1, r7, r4
_0821EFDA:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0821F0D6
	.align 2, 0
_0821EFE4: .4byte 0x000002D9
_0821EFE8:
	movs r1, #2
	ands r1, r2
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r4]
	cmp r1, #0
	beq _0821F034
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0x15
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
	movs r0, #0x20
	ldr r1, [r4]
	ands r0, r1
	cmp r0, #0
	bne _0821F024
	ldr r0, _0821F020 @ =0x00000809
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0821F02C
	.align 2, 0
_0821F020: .4byte 0x00000809
_0821F024:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r4]
_0821F02C:
	ldr r2, _0821F070 @ =0x000003DB
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
_0821F034:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	cmp r0, #0x31
	bgt _0821F0A4
	movs r1, #0x32
	subs r1, r1, r0
	adds r4, r7, #0
	adds r4, #0x58
	movs r2, #0xed
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r3, [r0]
	asrs r5, r1, #2
	ldr r2, _0821F074 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F078
	asrs r1, r0, #0xc
	b _0821F07E
	.align 2, 0
_0821F070: .4byte 0x000003DB
_0821F074: .4byte 0x085B0A08
_0821F078:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821F07E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821F09A
	asrs r0, r0, #0xc
	b _0821F0A0
_0821F09A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821F0A0:
	strh r0, [r4, #4]
	b _0821F0B6
_0821F0A4:
	cmp r0, #0x4f
	ble _0821F0B6
	movs r2, #0x10
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0821F0B6:
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, #0x27
	bgt _0821F0D6
	movs r1, #0x14
	bl Mod
	cmp r0, #0
	bne _0821F0D6
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x14
	bl FUN_0821ddc4
_0821F0D6:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
