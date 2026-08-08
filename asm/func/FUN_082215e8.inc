	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	adds r5, r0, #0
	adds r6, r5, #0
	movs r1, #0x80
	lsls r1, r1, #0xf
	adds r0, #0x98
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _0822162C
	ldr r1, _08221624 @ =0x000003F2
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	ldr r2, _08221628 @ =0x00000802
	movs r3, #1
	bl FUN_08236514
	b _08221642
	.align 2, 0
_08221624: .4byte 0x000003F2
_08221628: .4byte 0x00000802
_0822162C:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _082216FC @ =0x000003EA
	adds r1, r5, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	ldr r2, _08221700 @ =0x00000802
	movs r3, #1
	bl FUN_08236514
_08221642:
	movs r2, #1
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	bne _08221654
	b _082218FC
_08221654:
	movs r4, #0xfb
	lsls r4, r4, #2
	adds r0, r5, r4
	movs r1, #0
	ldrsh r4, [r0, r1]
	movs r2, #0xe4
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08221686
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08221686
	movs r4, #0
_08221686:
	cmp r4, #0
	bgt _0822168C
	b _0822189C
_0822168C:
	ldr r3, _08221704 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _08221708 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x14]
	adds r3, r5, #0
	adds r3, #0x50
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	add r2, sp, #0x10
	str r2, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805fe7c
	movs r3, #0xfc
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #0xa
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0821c238
	adds r1, r6, #0
	adds r1, #0x90
	ldrh r0, [r1]
	subs r0, r0, r4
	strh r0, [r1]
	lsls r0, r0, #0x10
	mov r8, r1
	cmp r0, #0
	bgt _08221710
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	movs r3, #1
	bl FUN_0821d870
	ldr r0, _0822170C @ =0x000003CD
	bl PlaySound_082406e0
	b _082218FC
	.align 2, 0
_082216FC: .4byte 0x000003EA
_08221700: .4byte 0x00000802
_08221704: .4byte 0xFFFF0000
_08221708: .4byte 0x0000FFFF
_0822170C: .4byte 0x000003CD
_08221710:
	movs r4, #0xff
	lsls r4, r4, #2
	adds r0, r5, r4
	movs r1, #0xf
	str r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _08221734
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08221744
_08221734:
	cmp r2, #1
	bne _082217B8
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _082217B8
_08221744:
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	add r0, sp, #0x18
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #0x18]
	str r2, [sp, #0x1c]
	ldrh r1, [r0, #2]
	adds r1, #0xc8
	strh r1, [r0, #2]
	ldr r3, _082217E4 @ =0xFFFF0000
	ldr r1, [sp, #0x20]
	ands r1, r3
	movs r2, #0x50
	orrs r1, r2
	ldr r2, _082217E8 @ =0x0000FFFF
	ands r1, r2
	movs r2, #0xf0
	lsls r2, r2, #0xe
	orrs r1, r2
	str r1, [sp, #0x20]
	add r2, sp, #0x20
	ldr r1, [r2, #4]
	ands r1, r3
	movs r3, #0x3c
	orrs r1, r3
	str r1, [r2, #4]
	ldr r4, _082217EC @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _082217F0 @ =0x000003FF
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	ldr r3, _082217F4 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	ldr r4, _082217F8 @ =0x000003EE
	adds r3, r5, r4
	movs r4, #0
	ldrsh r3, [r3, r4]
	movs r4, #4
	str r4, [sp]
	movs r4, #0x14
	str r4, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	movs r4, #1
	str r4, [sp, #0xc]
	bl FUN_080ddcc8
	ldr r0, _082217FC @ =0x00000339
	bl PlaySound_082406e0
_082217B8:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _08221840
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #8
	movs r1, #0xa
	bl Div
	cmp r0, #0
	blt _08221800
	asrs r1, r0, #8
	b _08221806
	.align 2, 0
_082217E4: .4byte 0xFFFF0000
_082217E8: .4byte 0x0000FFFF
_082217EC: .4byte 0x030046B8
_082217F0: .4byte 0x000003FF
_082217F4: .4byte 0x0203B400
_082217F8: .4byte 0x000003EE
_082217FC: .4byte 0x00000339
_08221800:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_08221806:
	movs r3, #0xfc
	lsls r3, r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	ldr r4, _08221838 @ =0x000003F2
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _08221830
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_0821d870
_08221830:
	ldr r0, _0822183C @ =0x00000362
	bl PlaySound_082406e0
	b _0822186A
	.align 2, 0
_08221838: .4byte 0x000003F2
_0822183C: .4byte 0x00000362
_08221840:
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08221862
	ldr r2, _08221898 @ =0x0000080C
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #0x64
	str r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #0x64
	str r0, [r1]
_08221862:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0822186A:
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r2, [r0]
	cmp r2, #0
	bne _082218FC
	mov r1, r8
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r4, #0x54
	adds r1, r5, r4
	ldr r1, [r1]
	cmp r0, r1
	bgt _082218FC
	str r2, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	movs r3, #6
	bl FUN_0821d870
	b _082218FC
	.align 2, 0
_08221898: .4byte 0x0000080C
_0822189C:
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	bne _082218FC
	ldr r2, _082218D8 @ =0x000003DB
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _082218DC
	movs r2, #0x20
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	str r4, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xc
	bl FUN_0821d870
	b _082218F2
	.align 2, 0
_082218D8: .4byte 0x000003DB
_082218DC:
	movs r0, #0x3c
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #5
	bl FUN_0821d870
	ldr r1, _08221908 @ =0x00000806
	adds r0, r5, r1
	strh r4, [r0]
_082218F2:
	movs r2, #0xff
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0xf
	str r0, [r1]
_082218FC:
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08221908: .4byte 0x00000806
