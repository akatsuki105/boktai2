	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081477F4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081477F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081477FA
	.align 2, 0
_081477F4: .4byte 0x0000046D
_081477F8:
	movs r0, #0
_081477FA:
	cmp r0, #0
	beq _0814781C
	ldrb r0, [r5, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080efb60
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0814781C:
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r5, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0814783C
	asrs r0, r0, #2
	b _08147842
_0814783C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08147842:
	adds r3, r0, #0
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r5, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r6, #8
	adds r1, r5, r6
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _08147860
	asrs r0, r0, #2
	b _08147866
_08147860:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08147866:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _08147870
	movs r3, #0xc8
	b _0814787A
_08147870:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0814787A
	adds r3, r0, #0
_0814787A:
	cmp r2, #0xc8
	ble _08147882
	movs r2, #0xc8
	b _0814788C
_08147882:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0814788C
	adds r2, r0, #0
_0814788C:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _081478B0
	cmp r2, #0
	bne _081478B0
	movs r0, #1
	b _081478B2
_081478B0:
	movs r0, #0
_081478B2:
	cmp r0, #0
	bne _081478B8
	b _08147A16
_081478B8:
	ldr r1, _081478E8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081478C4
	b _08147A16
_081478C4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081478EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	beq _081478F0
	movs r0, #1
	b _081478F2
	.align 2, 0
_081478E8: .4byte 0x0000046E
_081478EC: .4byte 0x030047A4
_081478F0:
	movs r0, #0
_081478F2:
	cmp r0, #0
	beq _0814790A
	adds r0, r5, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08147918
	adds r0, r5, #0
	bl FUN_081489f0
	b _08147A26
_0814790A:
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _081479DC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_08147918:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081479F4
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	adds r3, r1, #0
	adds r3, #8
	ldrh r1, [r1, #8]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	movs r7, #0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	strb r0, [r5, #5]
	ldr r3, _081479E0 @ =0x000001DF
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _08147978
	movs r0, #4
	ldr r1, _081479E4 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08147978:
	movs r0, #0x80
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _081479E8 @ =0x0000024E
	adds r0, r5, r3
	strh r1, [r0]
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r2, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r2, r2, r0
	movs r3, #1
	mvns r0, r3
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x13
	subs r6, #0x54
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r7, [r0]
	ldr r6, _081479EC @ =0x00000469
	adds r0, r5, r6
	strb r7, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r1, r5, r6
	movs r0, #0
	str r0, [r1]
	ldr r1, _081479F0 @ =0x0000046C
	adds r0, r5, r1
	strb r3, [r0]
	b _08147A16
	.align 2, 0
_081479DC: .4byte 0x03002BE0
_081479E0: .4byte 0x000001DF
_081479E4: .4byte 0x00000222
_081479E8: .4byte 0x0000024E
_081479EC: .4byte 0x00000469
_081479F0: .4byte 0x0000046C
_081479F4:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08147A30 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _08147A34 @ =0x0000046A
	adds r0, r5, r6
	strb r1, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_08147A16:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08147A26:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08147A30: .4byte 0x00000469
_08147A34: .4byte 0x0000046A
