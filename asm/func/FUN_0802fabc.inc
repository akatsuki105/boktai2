	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	mov r8, r1
	adds r7, r4, #0
	adds r5, r4, #0
	adds r5, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802FB40
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	ands r0, r1
	lsrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802FB14
	ldr r1, _0802FB10 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1f
	cmp r0, #0
	bne _0802FB24
	movs r3, #0x1a
	b _0802FB24
	.align 2, 0
_0802FB10: .4byte 0x00000824
_0802FB14:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1a
	cmp r0, #0
	beq _0802FB24
	movs r3, #0x1f
_0802FB24:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl Boss_PlayAnimDir8
_0802FB40:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802FBFC
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802FBFC
	mov r0, r8
	cmp r0, #0x13
	bgt _0802FBBE
	movs r0, #0x14
	adds r3, r5, #0
	adds r3, #0x10
	ldrb r5, [r5, #5]
	mov r1, r8
	subs r6, r0, r1
	ldr r2, _0802FB94 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802FB98
	asrs r1, r0, #0xc
	b _0802FB9E
	.align 2, 0
_0802FB94: .4byte gSineTable
_0802FB98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802FB9E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802FBB6
	asrs r0, r0, #0xc
	b _0802FBBC
_0802FBB6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802FBBC:
	strh r0, [r3, #4]
_0802FBBE:
	ldr r1, _0802FBE0 @ =0x000008E4
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0802FBEE
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802FBE4
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
	b _0802FBEE
	.align 2, 0
_0802FBE0: .4byte 0x000008E4
_0802FBE4:
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08028838
_0802FBEE:
	mov r0, r8
	cmp r0, #0x3b
	ble _0802FBFC
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802FBFC:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
