	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov sl, r0
	adds r5, r1, #0
	add r7, sp, #0x10
	ldr r3, [r5, #0x2c]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r6, r1, #0x11
	ldrh r1, [r3, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x11
	subs r2, r6, r4
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	cmp r1, #0
	blt _08005F84
	asrs r1, r1, #8
	b _08005F8A
_08005F84:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r1, r1, #0
_08005F8A:
	strh r1, [r7]
	adds r2, r6, r4
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	cmp r1, #0
	blt _08005F9C
	asrs r1, r1, #8
	b _08005FA2
_08005F9C:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r1, r1, #0
_08005FA2:
	adds r4, r1, #0
	movs r1, #2
	ldrsh r2, [r3, r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	cmp r1, #0
	blt _08005FB6
	asrs r2, r1, #8
	b _08005FBC
_08005FB6:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r2, r1, #0
_08005FBC:
	subs r1, r4, r2
	strh r1, [r7, #2]
	adds r1, r4, r2
	strh r1, [r7, #4]
	ldrb r1, [r5, #0xd]
	cmp r1, #0
	beq _08005FE2
	subs r1, #1
	strb r1, [r5, #0xd]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08005FE2
	movs r1, #4
	strb r1, [r5, #0xf]
	ldr r2, [r5, #0x2c]
	ldrh r1, [r2]
	strh r1, [r5, #0x10]
	ldrh r1, [r2, #4]
	strh r1, [r5, #0x12]
_08005FE2:
	movs r2, #1
	str r2, [sp, #0x20]
	movs r6, #0
	mov r8, r6
	mov r7, sl
	adds r7, #0x2c
	str r7, [sp, #0x24]
	add r1, sp, #0x10
	mov sb, r1
_08005FF4:
	mov r2, r8
	lsls r3, r2, #2
	ldr r6, [sp, #0x24]
	adds r1, r6, r3
	ldr r6, [r1]
	cmp r6, #0
	bne _08006004
	b _08006170
_08006004:
	movs r1, #0xc
	ldr r2, _080060F4 @ =0x03002BC0
	adds r2, r3, r2
	ldr r2, [r2]
	ands r2, r1
	cmp r2, #0
	beq _08006014
	b _08006170
_08006014:
	ldr r3, [r5, #0x2c]
	mov r7, r8
	lsls r1, r7, #3
	mov r2, sl
	adds r4, r1, r2
	adds r4, #0x3c
	mov r7, sb
	movs r1, #2
	ldrsh r2, [r7, r1]
	movs r7, #2
	ldrsh r1, [r4, r7]
	subs r2, r2, r1
	mov ip, r2
	movs r1, #2
	ldrsh r2, [r3, r1]
	movs r7, #0x2e
	ldrsh r1, [r6, r7]
	subs r1, r2, r1
	cmp r1, #0
	bge _0800603E
	rsbs r1, r1, #0
_0800603E:
	cmp r1, #0x7f
	bgt _08006068
	mov r1, sb
	movs r6, #0
	ldrsh r2, [r1, r6]
	movs r7, #0
	ldrsh r1, [r4, r7]
	subs r1, r2, r1
	cmp r1, #0
	bge _08006054
	rsbs r1, r1, #0
_08006054:
	cmp r1, #0xe
	bgt _08006068
	movs r1, #0x18
	rsbs r1, r1, #0
	cmp ip, r1
	blt _08006068
	movs r1, #1
	mov r2, ip
	cmp r2, #4
	ble _0800606A
_08006068:
	movs r1, #0
_0800606A:
	cmp r1, #0
	bne _08006070
	b _08006170
_08006070:
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _080060F8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, _080060FC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08006100
	movs r6, #0
	ldrsh r0, [r5, r6]
	movs r7, #2
	ldrsh r1, [r5, r7]
	bl CheckEmptySlotExist
	adds r1, r0, #0
	cmp r1, #0
	bne _08006100
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _0800616C
	ldrb r1, [r5, #0xd]
	cmp r1, #0
	bne _0800616C
	movs r2, #0
	ldrsh r1, [r5, r2]
	cmp r1, #3
	bgt _080060DE
	adds r0, r1, #0
	movs r7, #2
	ldrsh r1, [r5, r7]
	add r2, sp, #0x18
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	movs r2, #1
	mov r3, r8
	bl FUN_080177b4
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
_080060DE:
	movs r1, #0x24
	strb r1, [r5, #0xd]
	movs r1, #4
	strb r1, [r5, #0xf]
	ldr r2, [r5, #0x2c]
	ldrh r1, [r2]
	strh r1, [r5, #0x10]
	ldrh r1, [r2, #4]
	strh r1, [r5, #0x12]
	b _0800616C
	.align 2, 0
_080060F4: .4byte 0x03002BC0
_080060F8: .4byte 0x0000FFFF
_080060FC: .4byte 0x030047A4
_08006100:
	mov r0, r8
	strb r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #3
	bgt _08006124
	movs r6, #2
	ldrsh r1, [r5, r6]
	add r2, sp, #0x18
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	movs r2, #0
	mov r3, r8
	bl FUN_080177b4
_08006124:
	ldr r6, _08006168 @ =0x030047A4
	ldr r0, [r6]
	movs r4, #0x80
	lsls r4, r4, #4
	ands r0, r4
	cmp r0, #0
	bne _08006154
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
	ldr r0, [r6]
	ands r0, r4
	cmp r0, #0
	bne _08006154
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r2, #2
	ldrsh r1, [r5, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _08006156
_08006154:
	movs r2, #1
_08006156:
	ldrh r1, [r5, #0x34]
	adds r0, r5, #0
	bl MapItem_ExecScript
	ldrb r2, [r5, #6]
	movs r1, #1
	orrs r1, r2
	strb r1, [r5, #6]
	b _0800617C
	.align 2, 0
_08006168: .4byte 0x030047A4
_0800616C:
	movs r6, #0
	str r6, [sp, #0x20]
_08006170:
	movs r7, #1
	add r8, r7
	mov r1, r8
	cmp r1, #3
	bgt _0800617C
	b _08005FF4
_0800617C:
	add r2, sp, #0x20
	ldrb r2, [r2]
	strb r2, [r5, #0xe]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
