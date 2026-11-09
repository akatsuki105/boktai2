	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	str r0, [sp, #0x20]
	mov r8, r1
	mov sl, r2
	str r3, [sp, #0x24]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	ldr r2, _0818FE30 @ =0x00000ECA
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0818FE00
	b _0818FF0A
_0818FE00:
	ldr r3, [sp, #0x20]
	ldr r0, [r3, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r4, #0
	mov sb, r4
	ldr r1, _0818FE34 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	bge _0818FF0A
	ldr r3, _0818FE38 @ =0x00000764
	adds r6, r7, r3
	str r4, [sp, #0x2c]
_0818FE22:
	movs r1, #2
	ldrh r0, [r6, #0x16]
	ands r0, r1
	cmp r0, #0
	beq _0818FE3C
	movs r0, #1
	b _0818FE3E
	.align 2, 0
_0818FE30: .4byte 0x00000ECA
_0818FE34: .4byte 0x00000F36
_0818FE38: .4byte 0x00000764
_0818FE3C:
	movs r0, #0
_0818FE3E:
	cmp r0, #0
	beq _0818FEEE
	movs r1, #1
	ldrh r0, [r6, #0x16]
	ands r0, r1
	cmp r0, #0
	beq _0818FE50
	movs r0, #1
	b _0818FE52
_0818FE50:
	movs r0, #0
_0818FE52:
	cmp r0, #0
	bne _0818FEEE
	mov r5, sp
	ldr r0, [sp, #0x2c]
	adds r2, r0, r7
	ldr r3, _0818FFC8 @ =0x00000674
	adds r2, r2, r3
	ldrh r1, [r6]
	ldrh r0, [r2]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r4, #2
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	movs r4, #4
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, [sp, #0x24]
	cmp r1, r0
	ble _0818FEEE
	mov r1, r8
	cmp r1, #1
	bge _0818FEAC
	movs r4, #1
	mov r8, r4
_0818FEAC:
	adds r0, r2, #0
	mov r1, r8
	str r3, [sp, #0x30]
	bl Div
	ldr r1, [sp, #0x2c]
	adds r4, r7, r1
	ldr r3, [sp, #0x30]
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r2, #2
	ldrsh r0, [r5, r2]
	mov r1, r8
	bl Div
	ldr r3, _0818FFCC @ =0x00000676
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	mov r1, r8
	bl Div
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r4, r4, r2
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
_0818FEEE:
	movs r3, #0x92
	lsls r3, r3, #1
	adds r6, r6, r3
	ldr r4, [sp, #0x2c]
	adds r4, r4, r3
	str r4, [sp, #0x2c]
	movs r0, #1
	add sb, r0
	ldr r1, _0818FFD0 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	blt _0818FE22
_0818FF0A:
	ldr r3, _0818FFD4 @ =0x00000ECA
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	bne _0818FFDC
	ldr r4, [sp, #0x20]
	ldr r0, [r4, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r0, #0
	mov sb, r0
	ldr r1, _0818FFD0 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	blt _0818FF32
	b _08190128
_0818FF32:
	add r5, sp, #8
	add r6, sp, #0x10
	ldr r3, _0818FFC8 @ =0x00000674
	adds r4, r7, r3
_0818FF3A:
	ldrh r0, [r6]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r0, #0
	ldrsh r2, [r5, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _0818FFD8 @ =0x000031B4
	cmp r1, r0
	ble _0818FFA6
	adds r0, r2, #0
	mov r1, sl
	bl Div
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	movs r1, #2
	ldrsh r0, [r5, r1]
	mov r1, sl
	bl Div
	ldrh r1, [r4, #2]
	adds r1, r1, r0
	strh r1, [r4, #2]
	movs r2, #4
	ldrsh r0, [r5, r2]
	mov r1, sl
	bl Div
	ldrh r1, [r4, #4]
	adds r1, r1, r0
	strh r1, [r4, #4]
_0818FFA6:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r3, #0x92
	lsls r3, r3, #1
	adds r4, r4, r3
	movs r0, #1
	add sb, r0
	ldr r1, _0818FFD0 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	blt _0818FF3A
	b _08190128
	.align 2, 0
_0818FFC8: .4byte 0x00000674
_0818FFCC: .4byte 0x00000676
_0818FFD0: .4byte 0x00000F36
_0818FFD4: .4byte 0x00000ECA
_0818FFD8: .4byte 0x000031B4
_0818FFDC:
	ldrh r1, [r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r3, _08190140 @ =0x00000674
	adds r0, r0, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r0, [r2]
	subs r0, #1
	mov sb, r0
	add r4, sp, #0x10
	mov r8, r4
	add r6, sp, #0x18
	ldr r0, [sp, #0x20]
	adds r0, #8
	str r0, [sp, #0x28]
	mov r1, sb
	cmp r1, #0
	blt _081900A8
	adds r5, r6, #0
	lsls r0, r1, #3
	add r0, sb
	lsls r0, r0, #3
	add r0, sb
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r4, r0, r7
_0819001E:
	add r0, sp, #0x10
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	add r2, sp, #0x18
	strh r1, [r2]
	mov r3, sp
	ldrh r0, [r3, #0x12]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #0x14]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r0, #0
	ldrsh r2, [r2, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _08190144 @ =0x000031B4
	cmp r1, r0
	ble _08190090
	adds r0, r2, #0
	mov r1, sl
	bl Div
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	movs r1, #2
	ldrsh r0, [r5, r1]
	mov r1, sl
	bl Div
	ldrh r1, [r4, #2]
	adds r1, r1, r0
	strh r1, [r4, #2]
	movs r2, #4
	ldrsh r0, [r5, r2]
	mov r1, sl
	bl Div
	ldrh r1, [r4, #4]
	adds r1, r1, r0
	strh r1, [r4, #4]
_08190090:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r3, _08190148 @ =0xFFFFFEDC
	adds r4, r4, r3
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _0819001E
_081900A8:
	add r0, sp, #0x10
	ldrh r0, [r0]
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #8]
	subs r0, r0, r1
	add r2, sp, #0x18
	strh r0, [r2]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldr r4, [sp, #0x28]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldrsh r2, [r2, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r6, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _08190144 @ =0x000031B4
	cmp r1, r0
	ble _08190128
	adds r0, r2, #0
	mov r1, sl
	bl Div
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #0x10]
	adds r1, r1, r0
	strh r1, [r2, #0x10]
	movs r3, #2
	ldrsh r0, [r6, r3]
	mov r1, sl
	bl Div
	ldr r4, [sp, #0x20]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	movs r2, #4
	ldrsh r0, [r6, r2]
	mov r1, sl
	bl Div
	ldrh r1, [r4, #0x14]
	adds r1, r1, r0
	strh r1, [r4, #0x14]
_08190128:
	ldr r0, [sp, #0x20]
	bl FUN_0818f864
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190140: .4byte 0x00000674
_08190144: .4byte 0x000031B4
_08190148: .4byte 0xFFFFFEDC
