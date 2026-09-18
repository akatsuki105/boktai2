	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #4]
	adds r4, r1, #0
	adds r5, r2, #0
	str r3, [sp, #8]
	ldr r0, _0800ACB4 @ =0x03000044
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _0800ACBC
	ldr r0, _0800ACB8 @ =0x0000FC73
	movs r1, #0
	bl Entity0800a89c_Create
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _0800ACBC
	movs r0, #1
	rsbs r0, r0, #0
	b _0800AF6C
	.align 2, 0
_0800ACB4: .4byte 0x03000044
_0800ACB8: .4byte 0x0000FC73
_0800ACBC:
	movs r0, #0xf0
	ands r0, r4
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r3, r1, #0x1f
	movs r0, #0xf
	ands r4, r0
	ldr r0, [sp, #4]
	cmp r0, #4
	ble _0800ACD4
	movs r1, #4
	str r1, [sp, #4]
_0800ACD4:
	ldr r2, [sp, #0x4c]
	cmp r2, #0
	bne _0800ACDE
	movs r0, #1
	str r0, [sp, #0x4c]
_0800ACDE:
	ldr r0, _0800AD10 @ =0x085AA700
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r2, #0
	str r1, [sp, #0x18]
	ldr r1, [sp, #0x10]
	adds r1, #0x28
	str r1, [sp, #0x20]
	mov r8, r1
_0800ACF4:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800ACFE
	b _0800AF56
_0800ACFE:
	strb r4, [r1, #2]
	strb r5, [r1, #3]
	mov r2, sp
	ldrb r2, [r2, #4]
	strb r2, [r1, #1]
	cmp r3, #0
	beq _0800AD14
	strb r0, [r1, #4]
	b _0800AD1A
	.align 2, 0
_0800AD10: .4byte 0x085AA700
_0800AD14:
	movs r0, #0xe
	mov r3, r8
	strb r0, [r3, #4]
_0800AD1A:
	movs r0, #0
	str r0, [sp, #0x14]
	mov sb, r0
	ldr r1, [sp, #4]
	cmp sb, r1
	blt _0800AD28
	b _0800AF1C
_0800AD28:
	ldr r2, _0800AD4C @ =0x030046B8
	mov sl, r2
	ldr r7, [sp, #0x20]
	adds r7, #0x20
	ldr r5, [sp, #0x20]
	adds r5, #8
	ldr r3, [sp, #0x20]
	adds r3, #0x30
	str r3, [sp, #0x1c]
_0800AD3A:
	ldr r0, [sp, #0x44]
	cmp r0, #0
	beq _0800AD50
	mov r1, sb
	lsls r0, r1, #3
	ldr r2, [sp, #0x44]
	adds r4, r2, r0
	b _0800AD52
	.align 2, 0
_0800AD4C: .4byte 0x030046B8
_0800AD50:
	ldr r4, [sp, #8]
_0800AD52:
	movs r6, #0
	movs r3, #1
	strb r3, [r5]
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0800AE5C @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _0800AE60 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x4c]
	bl Mod
	ldr r1, [sp, #0x48]
	adds r0, r1, r0
	strh r0, [r5, #4]
	mov r2, sp
	ldrh r2, [r2, #0xc]
	strh r2, [r5, #6]
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0800AE5C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _0800AE60 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #4
	strb r0, [r5, #1]
	ldr r0, [r3]
	adds r0, #1
	ldr r3, _0800AE5C @ =0x000003FF
	ands r0, r3
	mov r1, sl
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r5, #2]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r3
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x80
	rsbs r1, r1, #0
	orrs r0, r1
	strb r0, [r5, #3]
	ldr r0, [r5, #0x28]
	adds r1, #0x7e
	ands r0, r1
	str r0, [r5, #0x28]
	ldrh r0, [r4]
	strh r0, [r7, #0x28]
	ldrh r0, [r4, #2]
	strh r0, [r7, #0x2a]
	ldrh r0, [r4, #4]
	strh r0, [r7, #0x2c]
	ldr r2, [sp, #0x10]
	ldr r1, [r2, #0x24]
	ldr r3, _0800AE64 @ =0x085AA6D0
	ldr r2, [r2, #0x18]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r2, [sp, #0x18]
	adds r0, r2, r0
	adds r0, r0, r3
	ldrh r2, [r0]
	str r6, [sp]
	adds r0, r7, #0
	movs r3, #0
	bl FUN_08236fac
	mov r3, sp
	ldrh r3, [r3, #0x14]
	strh r3, [r5, #0x20]
	ldr r0, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x14]
	cmp r0, #2
	ble _0800AE0C
	movs r1, #0
	str r1, [sp, #0x14]
_0800AE0C:
	strh r6, [r5, #8]
	strh r6, [r5, #0xa]
	strh r6, [r5, #0xc]
	ldr r0, [r5, #0x40]
	ldr r1, [r5, #0x44]
	str r0, [r5, #0x10]
	str r1, [r5, #0x14]
	ldr r2, [sp, #0x10]
	ldr r3, [r2, #0x20]
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x18]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r7, #0x1a]
	lsrs r1, r1, #3
	ldrb r0, [r7, #0x1b]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #0x30]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0800AE68
	ldr r0, [r5, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800AE70
	.align 2, 0
_0800AE5C: .4byte 0x000003FF
_0800AE60: .4byte 0x0203B400
_0800AE64: .4byte 0x085AA6D0
_0800AE68:
	ldr r0, [r5, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800AE70:
	str r0, [r5, #0x28]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800AE94
	ldr r0, [r5, #0x28]
	movs r1, #8
	orrs r0, r1
	b _0800AE9C
_0800AE94:
	ldr r0, [r5, #0x28]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800AE9C:
	str r0, [r5, #0x28]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0800AED4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0800AEFE
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800AED8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800AECC
	ldrb r0, [r4, #5]
_0800AECC:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800AEE8
	.align 2, 0
_0800AED4: .4byte 0x0000FFFF
_0800AED8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800AEE8
	strh r1, [r4, #8]
_0800AEE8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_0800AEFE:
	ldr r0, [sp, #0x1c]
	movs r1, #0
	bl FUN_0822da50
	adds r7, #0x50
	adds r5, #0x50
	ldr r3, [sp, #0x1c]
	adds r3, #0x50
	str r3, [sp, #0x1c]
	movs r0, #1
	add sb, r0
	ldr r1, [sp, #4]
	cmp sb, r1
	bge _0800AF1C
	b _0800AD3A
_0800AF1C:
	mov r2, sb
	cmp r2, #3
	bgt _0800AF4A
	lsls r0, r2, #2
	add r0, sb
	lsls r0, r0, #4
	adds r0, #0x30
	ldr r3, [sp, #0x20]
	adds r4, r0, r3
_0800AF2E:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822da50
	adds r4, #0x50
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	ble _0800AF2E
_0800AF4A:
	movs r0, #0x28
	mov r2, r8
	strh r0, [r2, #6]
	movs r0, #1
	strb r0, [r2]
	b _0800AF6A
_0800AF56:
	movs r0, #0xa4
	lsls r0, r0, #1
	add r8, r0
	ldr r1, [sp, #0x20]
	adds r1, r1, r0
	str r1, [sp, #0x20]
	adds r2, #1
	cmp r2, #5
	bgt _0800AF6A
	b _0800ACF4
_0800AF6A:
	movs r0, #0
_0800AF6C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
