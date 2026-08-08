	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r5, r7, r0
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r3, r7, r1
	ldr r0, [r3]
	cmp r0, #2
	bgt _0821E766
	movs r2, #0xc
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0821E766:
	ldr r4, [r3]
	cmp r4, #2
	beq _0821E838
	cmp r4, #2
	bgt _0821E77A
	cmp r4, #0
	beq _0821E788
	cmp r4, #1
	beq _0821E7E0
	b _0821EA62
_0821E77A:
	cmp r4, #3
	bne _0821E780
	b _0821E952
_0821E780:
	cmp r4, #0x63
	bne _0821E786
	b _0821EA58
_0821E786:
	b _0821EA62
_0821E788:
	movs r6, #2
	ldr r0, [r5]
	adds r2, r0, #0
	ands r2, r6
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	cmp r2, #0
	beq _0821E7AC
	movs r2, #0xfd
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r1, #0xf
	str r1, [r0]
	ldr r0, _0821E7C4 @ =0x0000035F
	bl PlaySound_082406e0
_0821E7AC:
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	movs r2, #0xfd
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r2, [r0]
	cmp r2, #0
	ble _0821E7C8
	subs r2, #1
	b _0821E926
	.align 2, 0
_0821E7C4: .4byte 0x0000035F
_0821E7C8:
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #1
	str r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [r0]
	ldr r0, [r5]
	orrs r0, r6
	b _0821EA60
_0821E7E0:
	movs r4, #2
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	strh r3, [r0]
	ldr r2, _0821E830 @ =0x00010010
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0xe9
	lsls r6, r6, #2
	adds r2, r7, r6
	ldr r1, _0821E834 @ =0x00000804
	adds r0, r7, r1
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, [r2]
	cmp r0, r1
	bge _0821E818
	b _0821EA62
_0821E818:
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [r0]
	movs r2, #0xe9
	lsls r2, r2, #2
	adds r0, r7, r2
	str r3, [r0]
	ldr r0, [r5]
	orrs r0, r4
	b _0821EA60
	.align 2, 0
_0821E830: .4byte 0x00010010
_0821E834: .4byte 0x00000804
_0821E838:
	ldr r0, [r5]
	ands r4, r0
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	cmp r4, #0
	beq _0821E918
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	adds r1, #0x29
	ldr r6, _0821E880 @ =0x00000806
	adds r0, r7, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	add r4, sp, #8
	ldrb r1, [r1]
	adds r3, r0, r1
	movs r5, #0xfa
	lsls r5, r5, #1
	ldr r2, _0821E884 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821E888
	asrs r1, r0, #0xc
	b _0821E88E
	.align 2, 0
_0821E880: .4byte 0x00000806
_0821E884: .4byte 0x085B0A08
_0821E888:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821E88E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821E8AA
	asrs r0, r0, #0xc
	b _0821E8B0
_0821E8AA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821E8B0:
	movs r6, #0
	strh r0, [r4, #4]
	adds r3, r7, #0
	adds r3, #0x50
	movs r2, #0x86
	lsls r2, r2, #1
	adds r5, r7, r2
	ldr r2, [r5]
	add r4, sp, #8
	adds r1, r4, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r4, [r4, #4]
	adds r0, r0, r4
	strh r0, [r3, #4]
	ldr r1, [r5]
	movs r4, #0
	ldrsh r2, [r3, r4]
	movs r0, #4
	ldrsh r3, [r3, r0]
	movs r4, #0
	ldrsh r0, [r1, r4]
	movs r4, #4
	ldrsh r1, [r1, r4]
	subs r0, r0, r2
	subs r1, r1, r3
	bl FUN_0823785c
	movs r2, #0xed
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	movs r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_0821c400
	movs r4, #0xef
	lsls r4, r4, #2
	adds r0, r7, r4
	strh r6, [r0]
_0821E918:
	movs r6, #0xfd
	lsls r6, r6, #2
	adds r0, r7, r6
	ldr r2, [r0]
	cmp r2, #0xe
	bgt _0821E934
	adds r2, #1
_0821E926:
	str r2, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0xf
	bl FUN_0821c2a0
	b _0821EA62
_0821E934:
	movs r1, #3
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r7, r2
	str r1, [r0]
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r0, #0
	str r0, [r1]
	movs r2, #2
	movs r6, #0xe3
	lsls r6, r6, #2
	adds r1, r7, r6
	b _0821EA4C
_0821E952:
	movs r0, #2
	ldr r1, [r5]
	ands r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r5]
	cmp r0, #0
	beq _0821E988
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
	ldr r0, _0821EA04 @ =0x0000034B
	bl PlaySound_082406e0
_0821E988:
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #6
	bne _0821E9A0
	movs r4, #0xaf
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r1, #0x40
	bl FUN_0823723c
_0821E9A0:
	movs r2, #8
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0xaf
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrh r0, [r0, #0x14]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _0821E9C8
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0821E9C8:
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #9
	bgt _0821EA36
	movs r1, #0xa
	subs r1, r1, r0
	adds r4, r7, #0
	adds r4, #0x58
	movs r2, #0xed
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r3, [r0]
	lsls r5, r1, #2
	ldr r2, _0821EA08 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821EA0C
	asrs r1, r0, #0xc
	b _0821EA12
	.align 2, 0
_0821EA04: .4byte 0x0000034B
_0821EA08: .4byte 0x085B0A08
_0821EA0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821EA12:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0821EA2E
	asrs r0, r0, #0xc
	b _0821EA34
_0821EA2E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821EA34:
	strh r0, [r4, #4]
_0821EA36:
	ldr r2, _0821EA54 @ =0x000002D9
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0821EA62
	movs r2, #0x10
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r1, r7, r4
_0821EA4C:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0821EA62
	.align 2, 0
_0821EA54: .4byte 0x000002D9
_0821EA58:
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
_0821EA60:
	str r0, [r5]
_0821EA62:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
