	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov sb, r0
	mov r8, r1
	adds r7, r2, #0
	adds r5, r3, #0
	ldr r0, _080DF1B4 @ =0x03000178
	ldr r4, [r0]
	cmp r4, #0
	bne _080DF16E
	bl FUN_080df420
	adds r4, r0, #0
	cmp r4, #0
	bne _080DF16E
	b _080DF30E
_080DF16E:
	adds r0, r4, #0
	bl FUN_080de174
	adds r6, r0, #0
	cmp r6, #0
	bne _080DF17C
	b _080DF30E
_080DF17C:
	adds r0, #0xf0
	movs r1, #0
	mov ip, r1
	movs r1, #0
	strh r5, [r0]
	adds r3, r6, #0
	adds r3, #0xf4
	strh r1, [r3]
	adds r0, #8
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xdc
	mov r5, r8
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	adds r0, #0xf3
	movs r1, #1
	strb r1, [r0]
	cmp r7, #8
	bne _080DF1B8
	adds r0, #3
	strb r1, [r0]
	ldrh r0, [r3]
	b _080DF1C8
	.align 2, 0
_080DF1B4: .4byte 0x03000178
_080DF1B8:
	cmp r7, #4
	bne _080DF1CC
	adds r1, r6, #0
	adds r1, #0xf6
	movs r0, #2
	strb r0, [r1]
	ldrh r0, [r3]
	movs r1, #2
_080DF1C8:
	orrs r0, r1
	strh r0, [r3]
_080DF1CC:
	mov r8, r6
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r0, _080DF23C @ =0x0000922E
	ldr r1, _080DF240 @ =0x0000121B
	bl FUN_082310cc
	adds r5, r6, #0
	adds r5, #0xec
	str r0, [r5]
	adds r1, r4, #0
	adds r1, #0x18
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r6, #0xc]
	movs r1, #0xda
	bl FUN_0822b20c
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r1, [r5]
	lsls r2, r7, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DF244
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080DF24C
	.align 2, 0
_080DF23C: .4byte 0x0000922E
_080DF240: .4byte 0x0000121B
_080DF244:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DF24C:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DF270
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080DF278
_080DF270:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DF278:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _080DF2B0 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080DF2E8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DF2B4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DF2A8
	ldrb r0, [r4, #5]
_080DF2A8:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DF2C4
	.align 2, 0
_080DF2B0: .4byte 0x0000FFFF
_080DF2B4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DF2C4
	strh r1, [r4, #8]
_080DF2C4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _080DF2E8
	movs r0, #1
	strb r0, [r4, #7]
_080DF2E8:
	movs r1, #0
	movs r0, #1
	mov r5, r8
	strb r0, [r5, #7]
	ldr r0, [sp, #0x3c]
	str r0, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r0, r6, #0
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	bl FUN_080de6b0
	adds r1, r6, #0
	adds r1, #0xd0
	ldr r0, [sp, #0x2c]
	strh r0, [r1]
_080DF30E:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
