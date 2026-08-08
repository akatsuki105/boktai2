	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r0, _080F5C2C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F5C30
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F5C32
	.align 2, 0
_080F5C2C: .4byte 0x0000046D
_080F5C30:
	movs r0, #0
_080F5C32:
	cmp r0, #0
	bne _080F5C38
	b _080F5DB0
_080F5C38:
	ldrb r0, [r7, #5]
	adds r0, #0x20
	asrs r0, r0, #6
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	movs r6, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	ldr r1, _080F5D48 @ =0x00000482
	adds r2, r7, r1
	movs r1, #1
	strh r1, [r2]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r4, r7, r3
	ldr r0, _080F5D4C @ =0xF3FFFFFF
	mov r8, r0
	ldr r0, [r4]
	mov r3, r8
	ands r0, r3
	str r0, [r4]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r5, r7, r0
	ldr r3, _080F5D50 @ =0xFEFFFFFF
	mov sb, r3
	ldr r0, [r5]
	ands r0, r3
	str r0, [r5]
	strh r1, [r2]
	ldr r1, _080F5D54 @ =0x00000222
	adds r0, r7, r1
	strh r6, [r0]
	ldr r2, _080F5D58 @ =0x0000024E
	adds r0, r7, r2
	strh r6, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, _080F5D5C @ =0xFFFFFC7F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, [r4]
	mov r1, r8
	ands r0, r1
	str r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	ldr r1, _080F5D60 @ =0x0000021E
	adds r3, r7, r1
	subs r1, #0x1c
	adds r1, r1, r7
	mov r8, r1
	cmp r0, #0
	beq _080F5CD2
	ldr r0, [r5]
	mov r1, sb
	ands r0, r1
	str r0, [r5]
	ldr r0, _080F5D64 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x87
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	strh r6, [r3]
	mov r1, r8
	strh r6, [r1]
_080F5CD2:
	ldr r0, _080F5D68 @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, _080F5D6C @ =0x00000542
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080F5D70 @ =0xFFFEBE3F
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	strh r6, [r3]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r7, r3
	strh r6, [r0]
	mov r0, r8
	strh r6, [r0]
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_08246790
	movs r0, #0x14
	str r0, [sp]
	movs r0, #0xe1
	lsls r0, r0, #4
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #3
	movs r2, #2
	movs r3, #0xa
	bl FUN_080e6408
	movs r1, #0x80
	lsls r1, r1, #0x12
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #7
	ldr r0, [r5]
	orrs r0, r2
	ldr r1, _080F5D74 @ =0xFFFFFEBF
	ands r0, r1
	str r0, [r5]
	ands r0, r2
	cmp r0, #0
	beq _080F5D80
	ldr r2, _080F5D78 @ =0x00000476
	adds r0, r7, r2
	ldrh r1, [r0]
	ldr r3, _080F5D7C @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080F5D90
	b _080F5DA4
	.align 2, 0
_080F5D48: .4byte 0x00000482
_080F5D4C: .4byte 0xF3FFFFFF
_080F5D50: .4byte 0xFEFFFFFF
_080F5D54: .4byte 0x00000222
_080F5D58: .4byte 0x0000024E
_080F5D5C: .4byte 0xFFFFFC7F
_080F5D60: .4byte 0x0000021E
_080F5D64: .4byte 0xFFFFFDFF
_080F5D68: .4byte 0xFFFFFBFF
_080F5D6C: .4byte 0x00000542
_080F5D70: .4byte 0xFFFEBE3F
_080F5D74: .4byte 0xFFFFFEBF
_080F5D78: .4byte 0x00000476
_080F5D7C: .4byte 0x0000025D
_080F5D80:
	ldr r6, _080F5D9C @ =0x0000047E
	adds r0, r7, r6
	ldrh r1, [r0]
	ldr r2, _080F5DA0 @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F5DA4
_080F5D90:
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080F5DB0
	.align 2, 0
_080F5D9C: .4byte 0x0000047E
_080F5DA0: .4byte 0x0000025D
_080F5DA4:
	ldr r2, [r7, #0x44]
	ldr r0, _080F5F48 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080F5DB0:
	ldr r3, _080F5F4C @ =0x0000044E
	adds r0, r7, r3
	ldrh r2, [r0]
	lsls r1, r2, #1
	ldr r6, _080F5F50 @ =0x000004BE
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r1, r0
	beq _080F5DC6
	cmp r2, r0
	bne _080F5E9A
_080F5DC6:
	ldr r0, _080F5F54 @ =0x0203B400
	mov r8, r0
	ldr r1, _080F5F58 @ =0x030046B8
	mov sl, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r5, _080F5F5C @ =0x000003FF
	ands r2, r5
	lsls r0, r2, #1
	add r0, r8
	ldrh r0, [r0]
	movs r3, #0xf
	mov sb, r3
	mov r6, sb
	ands r0, r6
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r6, _080F5F60 @ =0xFFFF0000
	ldr r3, [sp, #0xc]
	ands r3, r6
	orrs r3, r0
	str r3, [sp, #0xc]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	add r0, r8
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	subs r1, #0x10
	lsls r1, r1, #0x10
	ldr r4, _080F5F64 @ =0x0000FFFF
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r2, #1
	ands r2, r5
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	add r2, r8
	ldrh r0, [r2]
	mov r1, sb
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r6
	orrs r1, r0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r6
	movs r2, #5
	orrs r0, r2
	ands r0, r4
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r2
	str r0, [r3, #4]
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r2, [r0]
	ldrh r0, [r2]
	ldr r1, [sp, #0x1c]
	ands r1, r6
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r0, [r2, #2]
	adds r0, #0x80
	lsls r0, r0, #0x10
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #0x1c]
	ldrh r1, [r2, #4]
	add r2, sp, #0x1c
	ldr r0, [r2, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r2, #4]
	movs r6, #0xc5
	lsls r6, r6, #2
	adds r0, r7, r6
	str r3, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #3
	add r3, sp, #0xc
	bl FUN_08246728
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080F5E9A:
	ldr r2, _080F5F50 @ =0x000004BE
	adds r3, r7, r2
	ldrh r0, [r3]
	cmp r0, #0xa
	bhi _080F5EB2
	movs r0, #0x20
	movs r6, #0xc1
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080F5EB2:
	ldr r0, _080F5F68 @ =0x00000494
	adds r1, r7, r0
	movs r5, #0
	movs r0, #0x41
	strh r0, [r1]
	ldrh r0, [r3]
	adds r4, r0, #0
	cmp r4, #0
	bne _080F5F98
	adds r2, r7, #0
	adds r2, #0xd8
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r7, #0
	bl FUN_080e64e4
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r0, _080F5F6C @ =0xFFFFDFFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r6, _080F5F70 @ =0x00000469
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _080F5F74 @ =0x0000046A
	adds r0, r7, r1
	strb r5, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _080F5F78 @ =0x0000059C
	adds r0, r7, r1
	ldr r3, [r0]
	movs r1, #0xf
	adds r6, #1
	adds r0, r7, r6
	strb r2, [r0]
	ldr r2, _080F5F7C @ =0x0000046B
	adds r0, r7, r2
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	ldrb r0, [r7, #5]
	adds r1, r0, #0
	adds r1, #0x80
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _080F5F80
	asrs r0, r1, #5
	b _080F5F86
	.align 2, 0
_080F5F48: .4byte 0x03003584
_080F5F4C: .4byte 0x0000044E
_080F5F50: .4byte 0x000004BE
_080F5F54: .4byte 0x0203B400
_080F5F58: .4byte 0x030046B8
_080F5F5C: .4byte 0x000003FF
_080F5F60: .4byte 0xFFFF0000
_080F5F64: .4byte 0x0000FFFF
_080F5F68: .4byte 0x00000494
_080F5F6C: .4byte 0xFFFFDFFF
_080F5F70: .4byte 0x00000469
_080F5F74: .4byte 0x0000046A
_080F5F78: .4byte 0x0000059C
_080F5F7C: .4byte 0x0000046B
_080F5F80:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080F5F86:
	adds r0, #7
	movs r1, #7
	ands r0, r1
	ldr r3, _080F5F94 @ =0x000001DD
	adds r1, r7, r3
	strb r0, [r1]
	b _080F5F9C
	.align 2, 0
_080F5F94: .4byte 0x000001DD
_080F5F98:
	subs r0, #1
	strh r0, [r3]
_080F5F9C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
