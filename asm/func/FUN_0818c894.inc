	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0818C8C0 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818C8C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818C8C6
	.align 2, 0
_0818C8C0: .4byte 0x0000046C
_0818C8C4:
	movs r0, #0
_0818C8C6:
	ldr r3, _0818CA14 @ =0x00000F2C
	add r3, sb
	mov r8, r3
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r5, r4, r5
	str r5, [sp, #0x10]
	cmp r0, #0
	beq _0818C92E
	ldr r1, _0818CA18 @ =0x00000472
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r3, #0
	strh r0, [r4, #0xa]
	movs r0, #0x20
	ldr r5, _0818CA1C @ =0x00000474
	adds r2, r4, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	mov r5, r8
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x18
	strh r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r3, [r0]
	ldr r1, _0818CA20 @ =0xFFEFFFFF
	ldr r3, [sp, #0x10]
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	ldr r1, _0818CA24 @ =0xFFFF7FFF
	ands r0, r1
	strh r0, [r5]
_0818C92E:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r4, #0
	movs r1, #6
	movs r2, #6
	bl FUN_0818fdd8
	movs r6, #0
	ldr r1, _0818CA28 @ =0x00000F36
	add r1, sb
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r6, r0
	bge _0818C9B8
	mov r3, sp
	adds r7, r4, #0
	adds r7, #8
	ldr r0, _0818CA18 @ =0x00000472
	adds r0, r4, r0
	str r0, [sp, #0xc]
	str r1, [sp, #8]
	mov r5, sb
	mov ip, r6
	movs r1, #0x92
	lsls r1, r1, #1
	mov sl, r1
_0818C962:
	mov r2, ip
	add r2, sb
	ldr r0, _0818CA2C @ =0x00000674
	adds r2, r2, r0
	ldrh r0, [r2]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0xfa
	lsls r0, r0, #7
	cmp r1, r0
	ble _0818C9A8
	ldr r0, [sp, #0xc]
	ldrh r1, [r0]
	ldr r2, _0818CA30 @ =0x00000676
	adds r0, r5, r2
	strh r1, [r0]
_0818C9A8:
	add r5, sl
	add ip, sl
	adds r6, #1
	ldr r1, [sp, #8]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	blt _0818C962
_0818C9B8:
	mov r0, sb
	bl FUN_0818f008
	movs r1, #0x10
	ldr r3, [sp, #0x10]
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0818CA04
	adds r0, r4, #0
	adds r0, #8
	ldr r5, _0818CA18 @ =0x00000472
	adds r1, r4, r5
	ldrh r1, [r1]
	bl FUN_08191a14
	ldr r0, _0818CA34 @ =0x000001DF
	bl PlaySound_082406e0
	ldr r0, _0818CA38 @ =0x000003E5
	bl sound_08240740
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #8
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x20
	ldr r3, _0818CA1C @ =0x00000474
	adds r2, r4, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0818CA04:
	movs r1, #8
	mov r5, r8
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0818CA3C
	movs r0, #1
	b _0818CA3E
	.align 2, 0
_0818CA14: .4byte 0x00000F2C
_0818CA18: .4byte 0x00000472
_0818CA1C: .4byte 0x00000474
_0818CA20: .4byte 0xFFEFFFFF
_0818CA24: .4byte 0xFFFF7FFF
_0818CA28: .4byte 0x00000F36
_0818CA2C: .4byte 0x00000674
_0818CA30: .4byte 0x00000676
_0818CA34: .4byte 0x000001DF
_0818CA38: .4byte 0x000003E5
_0818CA3C:
	movs r0, #0
_0818CA3E:
	cmp r0, #0
	bne _0818CA44
	b _0818CB3C
_0818CA44:
	ldrh r0, [r4, #0xa]
	subs r0, #0x80
	movs r5, #0
	movs r6, #0
	strh r0, [r4, #0xa]
	mov r0, sb
	bl FUN_0818f008
	cmp r0, #0
	bge _0818CB3C
	ldr r2, _0818CA90 @ =0x00000D4E
	add r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _0818CA9C
	movs r1, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r5, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r5, [r0]
	ldr r5, _0818CA94 @ =0x0000046A
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _0818CA98 @ =0x00000484
	adds r0, r4, r1
	str r6, [r0]
	adds r3, #3
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	b _0818CB46
	.align 2, 0
_0818CA90: .4byte 0x00000D4E
_0818CA94: .4byte 0x0000046A
_0818CA98: .4byte 0x00000484
_0818CA9C:
	ldr r3, _0818CAD0 @ =0x00000D4F
	add r3, sb
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #4
	ble _0818CAE0
	movs r1, #0xe
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	ldr r3, _0818CAD4 @ =0x00000469
	adds r0, r4, r3
	strb r5, [r0]
	ldr r5, _0818CAD8 @ =0x0000046A
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _0818CADC @ =0x00000484
	adds r0, r4, r1
	str r6, [r0]
	adds r2, #4
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _0818CB46
	.align 2, 0
_0818CAD0: .4byte 0x00000D4F
_0818CAD4: .4byte 0x00000469
_0818CAD8: .4byte 0x0000046A
_0818CADC: .4byte 0x00000484
_0818CAE0:
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	ldr r5, _0818CB30 @ =0x0000046A
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _0818CB34 @ =0x00000484
	adds r0, r4, r1
	str r6, [r0]
	adds r2, #3
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	adds r5, #8
	adds r0, r4, r5
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	ldr r0, _0818CB38 @ =0x00000474
	adds r2, r4, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	b _0818CB46
	.align 2, 0
_0818CB30: .4byte 0x0000046A
_0818CB34: .4byte 0x00000484
_0818CB38: .4byte 0x00000474
_0818CB3C:
	ldr r2, _0818CB58 @ =0x00000484
	adds r1, r4, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818CB46:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818CB58: .4byte 0x00000484
