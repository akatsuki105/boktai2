	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #4]
	mov r8, r1
	ldr r0, [sp, #0x30]
	mov sl, r0
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, #8
	adds r5, r1, r0
	adds r4, r5, #0
	adds r4, #0x28
	movs r0, #1
	ands r0, r2
	cmp r0, r3
	beq _0800BAA4
	b _0800BBB4
_0800BAA4:
	mov r2, sl
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r2, #0x18
	ldrsh r0, [r4, r2]
	subs r7, r1, r0
	mov r3, sl
	movs r1, #2
	ldrsh r0, [r3, r1]
	movs r2, #0x1a
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	adds r0, #0x80
	str r0, [sp, #8]
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #0x1c
	ldrsh r0, [r4, r2]
	subs r6, r1, r0
	adds r0, r7, #0
	adds r1, r6, #0
	bl ArcTan2_8
	strb r0, [r5, #2]
	ldr r2, _0800BB9C @ =0x085B0A08
	ldrb r0, [r5, #2]
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
	ldrb r0, [r5, #2]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #0xc]
	movs r3, #4
	mov sb, r3
	ldr r1, _0800BBA0 @ =0x03002BC0
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	bne _0800BBB4
	mov r2, r8
	ldrh r2, [r2, #6]
	mov ip, r2
	cmp r2, #0
	bne _0800BBB4
	ldr r0, [sp, #8]
	cmp r0, #0
	bge _0800BB20
	rsbs r0, r0, #0
_0800BB20:
	cmp r0, #0x81
	bgt _0800BBB4
	adds r0, r7, #0
	muls r0, r7, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r0, r1
	ldr r1, _0800BBA4 @ =0x0000018F
	cmp r0, r1
	bgt _0800BBB4
	mov r3, sb
	strb r3, [r5]
	adds r0, r5, #0
	adds r0, #0x18
	ldr r5, [sp, #4]
	ldr r1, [r5, #0x24]
	ldr r4, _0800BBA8 @ =0x085AA6E8
	ldr r3, [r5, #0x18]
	lsls r2, r3, #1
	adds r2, r2, r3
	mov r3, r8
	ldrb r3, [r3, #2]
	adds r2, r2, r3
	lsls r2, r2, #2
	adds r2, r2, r4
	ldrh r2, [r2]
	mov r5, ip
	str r5, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _0800BBA0 @ =0x03002BC0
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0800BB6C
	b _0800BCDE
_0800BB6C:
	ldr r1, _0800BBAC @ =0x085AA718
	mov r3, r8
	ldrb r0, [r3, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl PlaySound_0824078c
	ldr r0, _0800BBB0 @ =0x085AA70C
	mov r5, r8
	ldrb r2, [r5, #2]
	lsls r2, r2, #2
	adds r2, r2, r0
	ldr r1, [sp, #4]
	movs r3, #0xfb
	lsls r3, r3, #3
	adds r0, r1, r3
	ldr r0, [r0]
	ldrb r1, [r5, #3]
	ldr r2, [r2]
	bl _call_via_r2
	b _0800BCDE
	.align 2, 0
_0800BB9C: .4byte 0x085B0A08
_0800BBA0: .4byte 0x03002BC0
_0800BBA4: .4byte 0x0000018F
_0800BBA8: .4byte 0x085AA6E8
_0800BBAC: .4byte 0x085AA718
_0800BBB0: .4byte 0x085AA70C
_0800BBB4:
	ldrh r0, [r5, #8]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	mov r2, sl
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r2, #0x1a
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r1, #0x10
	ble _0800BBD2
	ldrh r0, [r4, #0x1a]
	adds r0, #0x10
	b _0800BBE4
_0800BBD2:
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800BBE0
	ldrh r0, [r4, #0x1a]
	subs r0, #0x10
	b _0800BBE4
_0800BBE0:
	mov r3, sl
	ldrh r0, [r3, #2]
_0800BBE4:
	strh r0, [r4, #0x1a]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	adds r6, r5, #0
	adds r6, #0x28
	ldr r2, [sp, #4]
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
	beq _0800BC36
	ldr r0, [r5, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800BC3E
_0800BC36:
	ldr r0, [r5, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800BC3E:
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
	beq _0800BC62
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800BC6A
_0800BC62:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800BC6A:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0800BCA0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800BCCA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800BCA4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800BC9A
	ldrb r0, [r4, #5]
_0800BC9A:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800BCB4
	.align 2, 0
_0800BCA0: .4byte 0x0000FFFF
_0800BCA4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800BCB4
	strh r1, [r4, #8]
_0800BCB4:
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
_0800BCCA:
	ldrh r0, [r5, #4]
	subs r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BCDE
	movs r0, #3
	strb r0, [r5]
	movs r0, #0xf
	strh r0, [r5, #6]
_0800BCDE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
