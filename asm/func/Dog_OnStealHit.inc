	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x28
	mov sb, r0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r6, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814B8C6
	b _0814BBB6
_0814B8C6:
	mov r2, sb
	ldr r0, [r2, #0x24]
	ldr r1, [r2, #0x28]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrb r0, [r6, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0814B900
	cmp r0, #1
	bgt _0814B8E8
	cmp r0, #0
	beq _0814B8F2
	b _0814B948
_0814B8E8:
	cmp r0, #2
	beq _0814B910
	cmp r0, #3
	beq _0814B930
	b _0814B948
_0814B8F2:
	add r0, sp, #0x10
	ldrh r1, [r0]
	ldr r3, _0814B8FC @ =0xFFFFFF00
	adds r1, r1, r3
	b _0814B91A
	.align 2, 0
_0814B8FC: .4byte 0xFFFFFF00
_0814B900:
	add r0, sp, #0x10
	ldrh r1, [r0, #4]
	ldr r0, _0814B90C @ =0xFFFFFF00
	adds r1, r1, r0
	b _0814B93A
	.align 2, 0
_0814B90C: .4byte 0xFFFFFF00
_0814B910:
	add r0, sp, #0x10
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0814B91A:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814B92C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	b _0814B948
	.align 2, 0
_0814B92C: .4byte 0xFFFF0000
_0814B930:
	add r0, sp, #0x10
	ldrh r1, [r0, #4]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
_0814B93A:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814B9BC @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
_0814B948:
	add r2, sp, #0x18
	add r4, sp, #0x10
	adds r3, r5, #0
	adds r3, #0x24
	ldrh r0, [r5, #0x24]
	adds r1, r4, #0
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	mov r1, sb
	adds r1, #0x42
	strb r0, [r1]
	adds r0, r7, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814B9AA
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0814B9AA
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, _0814B9C0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0814B9AA:
	ldr r0, _0814B9C4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814B9C8
	movs r0, #1
	b _0814B9CA
	.align 2, 0
_0814B9BC: .4byte 0xFFFF0000
_0814B9C0: .4byte 0xFEFFFFFF
_0814B9C4: .4byte 0x030047A4
_0814B9C8:
	movs r0, #0
_0814B9CA:
	cmp r0, #0
	beq _0814B9D0
	b _0814BBB6
_0814B9D0:
	ldrh r0, [r5, #0xa]
	cmp r0, #1
	beq _0814B9D8
	b _0814BBB6
_0814B9D8:
	movs r5, #0xda
	lsls r5, r5, #3
	add r5, r8
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0
	blt _0814B9E8
	b _0814BBB6
_0814B9E8:
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0814B9FA
	cmp r0, #4
	beq _0814B9FA
	b _0814BBB6
_0814B9FA:
	ldr r0, _0814BA5C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r2, [sp, #0x20]
	asrs r1, r2, #0x10
	adds r1, #0xc8
	lsls r1, r1, #0x10
	ldr r0, _0814BA60 @ =0x0000FFFF
	mov sb, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r4, _0814BA64 @ =0x000006D2
	add r4, r8
	ldr r2, _0814BA68 @ =0x000006D4
	add r2, r8
	adds r0, r5, #0
	adds r1, r4, #0
	bl PickItemToSteal
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814BA30
	b _0814BBB6
_0814BA30:
	movs r2, #0
	ldrsh r1, [r4, r2]
	add r0, sp, #0x20
	str r0, [sp]
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	movs r0, #0
	movs r2, #3
	movs r3, #0
	bl ItemIconPopupManager_AddIcon
	cmp r0, #0
	bge _0814BA6C
	ldrh r1, [r5]
	mov r0, sb
	orrs r0, r1
	strh r0, [r5]
	b _0814BBB6
	.align 2, 0
_0814BA5C: .4byte 0x03002BE0
_0814BA60: .4byte 0x0000FFFF
_0814BA64: .4byte 0x000006D2
_0814BA68: .4byte 0x000006D4
_0814BA6C:
	movs r3, #0
	ldrsh r0, [r5, r3]
	bl RemoveItem
	movs r0, #0
	ldrsh r1, [r4, r0]
	cmp r1, #0xb
	beq _0814BA90
	cmp r1, #0xb
	bgt _0814BA86
	cmp r1, #8
	beq _0814BA90
	b _0814BBB6
_0814BA86:
	cmp r1, #0xe
	beq _0814BA90
	cmp r1, #0x11
	beq _0814BA90
	b _0814BBB6
_0814BA90:
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r0, _0814BAC0 @ =0x000006D9
	add r0, r8
	ldrb r0, [r0]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	adds r1, r0, #0
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r0, r0, r1
	cmp r0, #0
	bgt _0814BAC8
	ldrh r1, [r2]
	ldr r2, _0814BAC4 @ =0x0000048A
	adds r0, r6, r2
	b _0814BACC
	.align 2, 0
_0814BAC0: .4byte 0x000006D9
_0814BAC4: .4byte 0x0000048A
_0814BAC8:
	ldr r3, _0814BB48 @ =0x0000048A
	adds r0, r6, r3
_0814BACC:
	strh r1, [r0]
	movs r1, #0xda
	lsls r1, r1, #3
	add r1, r8
	ldr r0, _0814BB4C @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r4, _0814BB50 @ =0x03002BE0
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r3, #1
	str r3, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r1, #0
	str r1, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	subs r2, #4
	adds r0, r6, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	ldr r1, _0814BB48 @ =0x0000048A
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #1
	strh r3, [r0]
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0x1e
	strh r0, [r1]
	ldr r1, _0814BB54 @ =0x0000048C
	adds r0, r6, r1
	strb r2, [r0]
	movs r1, #2
	ldr r2, _0814BB58 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814BB5C
	movs r0, #1
	b _0814BB5E
	.align 2, 0
_0814BB48: .4byte 0x0000048A
_0814BB4C: .4byte 0x0000FFFF
_0814BB50: .4byte 0x03002BE0
_0814BB54: .4byte 0x0000048C
_0814BB58: .4byte 0x00000474
_0814BB5C:
	movs r0, #0
_0814BB5E:
	cmp r0, #0
	beq _0814BB72
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0814BB7E
_0814BB72:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0814BBB6
_0814BB7E:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0814BBB6:
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
