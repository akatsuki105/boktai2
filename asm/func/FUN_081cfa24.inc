	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp, #0x1c]
	ldr r2, _081CFACC @ =0xFFFF0000
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	movs r2, #0x80
	orrs r0, r2
	str r0, [r1, #4]
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r0, r2
	str r0, [sp, #0x14]
	mov sl, r1
	add r0, sp, #0x10
	mov r8, r0
	adds r1, #8
	str r1, [sp, #0x28]
	mov r2, r8
	movs r1, #0
	mov r0, sp
	adds r0, #0x13
_081CFA5E:
	strb r1, [r0]
	subs r0, #1
	cmp r0, r2
	bge _081CFA5E
	movs r2, #0
	str r2, [sp, #0x24]
	movs r3, #0
	str r3, [sp, #0x20]
	movs r4, #0
	movs r0, #0x80
	adds r0, r0, r7
	mov sb, r0
	adds r6, r7, #0
	adds r6, #0xb8
	mov r5, sp
_081CFA7C:
	mov r0, sb
	mov r1, sl
	adds r2, r4, #0
	bl FUN_080e11a8
	str r0, [r5]
	cmp r0, #0
	beq _081CFA9C
	mov r2, r8
	adds r1, r2, r4
	movs r0, #1
	strb r0, [r1]
	ldrh r1, [r6]
	movs r0, #0x80
	orrs r0, r1
	strh r0, [r6]
_081CFA9C:
	adds r5, #4
	adds r4, #1
	cmp r4, #3
	ble _081CFA7C
	adds r0, r7, #0
	bl FUN_081cfcb8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CFAC2
	movs r3, #1
	str r3, [sp, #0x20]
	adds r2, r7, #0
	adds r2, #0xb8
	ldrh r1, [r2]
	adds r3, #0xff
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
_081CFAC2:
	movs r4, #0
	movs r5, #1
	movs r6, #3
	b _081CFB32
	.align 2, 0
_081CFACC: .4byte 0xFFFF0000
_081CFAD0:
	ldr r0, _081CFB88 @ =0x00000553
	adds r2, r1, r0
	ldrb r0, [r2]
	subs r0, #0x16
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081CFB32
	ldr r3, _081CFB8C @ =0x0000046D
	adds r0, r1, r3
	strb r5, [r0]
	subs r3, #2
	adds r0, r1, r3
	strb r4, [r0]
	movs r0, #0x16
	strb r0, [r2]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r3, _081CFB90 @ =FUN_080f54e4
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r1, r2
	strh r4, [r0]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r1, r3
	strb r6, [r0]
	ldr r2, _081CFB94 @ =0x00000469
	adds r0, r1, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r1, r3
	strb r4, [r0]
	adds r2, #0x1b
	adds r0, r1, r2
	str r4, [r0]
	adds r3, #2
	adds r0, r1, r3
	strb r5, [r0]
	adds r2, #0x3a
	adds r0, r1, r2
	strh r4, [r0]
	adds r0, r1, #0
	bl FUN_080e64e4
	movs r3, #1
	str r3, [sp, #0x24]
_081CFB32:
	mov r0, sb
	mov r1, sl
	ldr r2, [sp, #0x28]
	bl FUN_080e1100
	adds r1, r0, #0
	cmp r1, #0
	bne _081CFAD0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _081CFB5C
	ldrb r0, [r1, #1]
	cmp r0, #0
	bne _081CFB5C
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _081CFB5C
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _081CFC18
_081CFB5C:
	ldr r0, _081CFB98 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081CFB9C
	adds r0, r7, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _081CFBA4
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #5
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	b _081CFBA4
	.align 2, 0
_081CFB88: .4byte 0x00000553
_081CFB8C: .4byte 0x0000046D
_081CFB90: .4byte FUN_080f54e4
_081CFB94: .4byte 0x00000469
_081CFB98: .4byte 0x030047A4
_081CFB9C:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #7
	strh r0, [r1]
_081CFBA4:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	beq _081CFBE4
	movs r4, #0
	adds r6, r7, #0
	adds r6, #0xb8
	mov r5, sp
_081CFBB2:
	mov r3, r8
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CFBD4
	ldr r0, [r5]
	movs r1, #1
	bl FUN_0807a570
	cmp r0, #0
	beq _081CFBD4
	ldrh r1, [r6]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r6]
_081CFBD4:
	adds r5, #4
	adds r4, #1
	cmp r4, #3
	ble _081CFBB2
	movs r0, #1
	bl FUN_080868b8
	b _081CFC4E
_081CFBE4:
	movs r4, #0
	adds r6, r7, #0
	adds r6, #0xb8
	mov r5, sp
_081CFBEC:
	mov r3, r8
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CFC0E
	ldr r0, [r5]
	movs r1, #0
	bl FUN_0807a570
	cmp r0, #0
	beq _081CFC0E
	ldrh r1, [r6]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r6]
_081CFC0E:
	adds r5, #4
	adds r4, #1
	cmp r4, #3
	ble _081CFBEC
	b _081CFC4E
_081CFC18:
	ldr r3, [sp, #0x20]
	cmp r3, #0
	beq _081CFC2C
	adds r0, r7, #0
	bl FUN_081cf944
	movs r0, #0
	bl FUN_080868b8
	b _081CFC40
_081CFC2C:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _081CFC4E
	adds r0, r7, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _081CFC4E
_081CFC40:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #5
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
_081CFC4E:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
