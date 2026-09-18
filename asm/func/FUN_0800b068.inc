	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	mov sb, r1
	ldr r0, [sp, #0x34]
	mov sl, r0
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, #8
	adds r5, r1, r0
	adds r4, r5, #0
	adds r4, #0x10
	adds r7, r5, #0
	adds r7, #0x28
	adds r6, r5, #2
	movs r0, #1
	ands r0, r2
	cmp r0, r3
	bne _0800B180
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	movs r2, #0x18
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #0x1c
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	ldrb r2, [r5, #2]
	subs r1, r0, r2
	movs r0, #3
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _0800B104
	adds r0, r1, #0
	cmp r1, #0
	bge _0800B0C4
	rsbs r0, r1, #0
_0800B0C4:
	cmp r0, #4
	bgt _0800B0CC
	adds r0, r2, r1
	b _0800B0CE
_0800B0CC:
	adds r0, r2, #4
_0800B0CE:
	strb r0, [r6]
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800B142
	ldr r2, _0800B0F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800B0FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800B100 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	b _0800B140
	.align 2, 0
_0800B0F8: .4byte 0x030046B8
_0800B0FC: .4byte 0x000003FF
_0800B100: .4byte 0x0203B400
_0800B104:
	adds r0, r1, #0
	cmp r1, #0
	bge _0800B10C
	rsbs r0, r1, #0
_0800B10C:
	cmp r0, #4
	bgt _0800B114
	subs r0, r2, r1
	b _0800B116
_0800B114:
	subs r0, r2, #4
_0800B116:
	strb r0, [r6]
	ldrb r0, [r5, #3]
	subs r0, #1
	strb r0, [r5, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800B142
	ldr r2, _0800B170 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800B174 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0800B178 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	rsbs r0, r0, #0
	subs r0, #0x40
_0800B140:
	strb r0, [r5, #3]
_0800B142:
	ldr r2, _0800B17C @ =0x085B0A08
	ldrb r0, [r6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #8]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #0xc]
	b _0800B2A4
	.align 2, 0
_0800B170: .4byte 0x030046B8
_0800B174: .4byte 0x000003FF
_0800B178: .4byte 0x0203B400
_0800B17C: .4byte 0x085B0A08
_0800B180:
	mov r3, sb
	ldrh r0, [r3, #6]
	cmp r0, #0
	beq _0800B18A
	b _0800B2A4
_0800B18A:
	add r6, sp, #4
	adds r2, r5, #0
	adds r2, #0x40
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800B1AC
	asrs r0, r0, #8
	b _0800B1B2
_0800B1AC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800B1B2:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800B1C4
	asrs r0, r0, #8
	b _0800B1CA
_0800B1C4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800B1CA:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800B1DE
	asrs r1, r0, #8
	b _0800B1E4
_0800B1DE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0800B1E4:
	subs r0, r3, r1
	strh r0, [r6, #2]
	adds r0, r3, r1
	strh r0, [r6, #4]
	movs r1, #4
	mov r8, r1
	ldr r2, _0800B294 @ =0x03002BC0
	ldr r6, [r2]
	ands r6, r1
	cmp r6, #0
	bne _0800B2A4
	add r0, sp, #4
	mov r3, sl
	movs r2, #0x18
	ldrsh r1, [r3, r2]
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r1, r2
	bgt _0800B2A4
	mov r1, sl
	movs r3, #0x20
	ldrsh r0, [r1, r3]
	cmp r0, r2
	blt _0800B2A4
	add r0, sp, #4
	ldrh r0, [r0, #2]
	movs r2, #0x1a
	ldrsh r1, [r1, r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r1, r2
	bgt _0800B2A4
	mov r3, sl
	movs r1, #0x22
	ldrsh r0, [r3, r1]
	cmp r0, r2
	blt _0800B2A4
	mov r2, r8
	strb r2, [r5]
	adds r0, r5, #0
	adds r0, #0x18
	ldr r3, [sp, #0xc]
	ldr r1, [r3, #0x24]
	ldr r4, _0800B298 @ =0x085AA6E8
	ldr r3, [r3, #0x18]
	lsls r2, r3, #1
	adds r2, r2, r3
	mov r5, sb
	ldrb r5, [r5, #2]
	adds r2, r2, r5
	lsls r2, r2, #2
	adds r2, r2, r4
	ldrh r2, [r2]
	str r6, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _0800B294 @ =0x03002BC0
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _0800B264
	b _0800B3F2
_0800B264:
	ldr r1, _0800B29C @ =0x085AA718
	mov r3, sb
	ldrb r0, [r3, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl PlaySound_0824078c
	ldr r0, _0800B2A0 @ =0x085AA70C
	mov r5, sb
	ldrb r2, [r5, #2]
	lsls r2, r2, #2
	adds r2, r2, r0
	ldr r1, [sp, #0xc]
	movs r3, #0xfb
	lsls r3, r3, #3
	adds r0, r1, r3
	ldr r0, [r0]
	ldrb r1, [r5, #3]
	ldr r2, [r2]
	bl _call_via_r2
	b _0800B3F2
	.align 2, 0
_0800B294: .4byte 0x03002BC0
_0800B298: .4byte 0x085AA6E8
_0800B29C: .4byte 0x085AA718
_0800B2A0: .4byte 0x085AA70C
_0800B2A4:
	ldrh r0, [r5, #8]
	ldrh r1, [r7, #0x18]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	mov r2, sl
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r2, #0x1a
	ldrsh r0, [r7, r2]
	subs r1, r1, r0
	cmp r1, #0x10
	ble _0800B2C2
	ldrh r0, [r7, #0x1a]
	adds r0, #0x10
	b _0800B2D4
_0800B2C2:
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800B2D0
	ldrh r0, [r7, #0x1a]
	subs r0, #0x10
	b _0800B2D4
_0800B2D0:
	mov r3, sl
	ldrh r0, [r3, #2]
_0800B2D4:
	strh r0, [r7, #0x1a]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	adds r6, r5, #0
	adds r6, #0x28
	ldr r2, [sp, #0xc]
	ldr r3, [r2, #0x20]
	adds r4, r5, #0
	adds r4, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x18]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
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
	beq _0800B326
	ldr r0, [r5, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800B32E
_0800B326:
	ldr r0, [r5, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800B32E:
	str r0, [r5, #0x28]
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
	beq _0800B352
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800B35A
_0800B352:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800B35A:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0800B390 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800B3BA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800B394
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800B38A
	ldrb r0, [r4, #5]
_0800B38A:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800B3A4
	.align 2, 0
_0800B390: .4byte 0x0000FFFF
_0800B394:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800B3A4
	strh r1, [r4, #8]
_0800B3A4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_0800B3BA:
	mov r3, sb
	ldrh r0, [r3, #6]
	cmp r0, #0
	bne _0800B3DE
	ldr r1, [sp, #0xc]
	movs r2, #0xfb
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r0, [r0]
	movs r1, #0x80
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0800B3DE
	movs r0, #2
	strb r0, [r5]
	movs r0, #0x12
	strb r0, [r5, #1]
_0800B3DE:
	ldrh r0, [r5, #4]
	subs r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800B3F2
	movs r0, #3
	strb r0, [r5]
	movs r0, #0xa
	strh r0, [r5, #6]
_0800B3F2:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
