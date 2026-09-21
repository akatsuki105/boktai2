	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r1, #0
	ldr r5, [r6, #0x20]
	ldr r4, [r6, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080067A2
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080067AA
_080067A2:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080067AA:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080067CE
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080067D6
_080067CE:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080067D6:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006810 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006856
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800681A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006814
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r3, #1
	b _08006830
	.align 2, 0
_08006810: .4byte 0x0000FFFF
_08006814:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800682E
_0800681A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800682E
	strh r1, [r4, #8]
	movs r3, #1
	b _08006830
_0800682E:
	movs r3, #0
_08006830:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08006858
	movs r0, #1
	strb r0, [r4, #7]
	b _08006858
_08006856:
	movs r3, #0
_08006858:
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _08006868
	ldr r0, [r6, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006868:
	cmp r3, #0
	beq _08006920
	ldr r0, [r6, #0x2c]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, [sp, #0x10]
	asrs r1, r2, #0x10
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _080068CC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, _080068D0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080068D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r2, #2
	ldrsh r1, [r6, r2]
	bl CheckEmptySlotExist
	cmp r0, #0
	bne _080068D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt _080068C6
	movs r2, #2
	ldrsh r1, [r6, r2]
	movs r3, #4
	ldrsb r3, [r6, r3]
	add r2, sp, #0x10
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	movs r2, #1
	bl FUN_080177b4
_080068C6:
	ldr r0, _080068D4 @ =FUN_08006a80
	b _080068FC
	.align 2, 0
_080068CC: .4byte 0x0000FFFF
_080068D0: .4byte 0x030047A4
_080068D4: .4byte FUN_08006a80
_080068D8:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt _080068FA
	movs r2, #2
	ldrsh r1, [r6, r2]
	movs r3, #4
	ldrsb r3, [r6, r3]
	add r2, sp, #0x10
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	movs r2, #0
	bl FUN_080177b4
_080068FA:
	ldr r0, _08006918 @ =MapItem_UpdateGive
_080068FC:
	str r0, [r6, #0x44]
	movs r2, #0
	str r2, [r6, #0x18]
	ldr r0, [r6, #0x28]
	ldr r1, _0800691C @ =0x0300002C
	ldr r1, [r1]
	ldr r1, [r1, #0x1c]
	str r2, [sp]
	movs r2, #6
	movs r3, #0
	bl FUN_08236fac
	b _08006926
	.align 2, 0
_08006918: .4byte MapItem_UpdateGive
_0800691C: .4byte 0x0300002C
_08006920:
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
_08006926:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
