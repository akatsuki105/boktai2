	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D7AC8 @ =0x0300019C
	ldr r4, [r0]
	cmp r4, #0
	bne _081D7A70
	b _081D7C9E
_081D7A70:
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r7, r5, #0
	adds r7, #0x8c
	cmp r0, #0
	bne _081D7A82
	b _081D7B96
_081D7A82:
	adds r0, r5, #0
	bl FUN_081d7814
	ldr r1, [r4, #0x1c]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r7, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7ACC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7AD4
	.align 2, 0
_081D7AC8: .4byte 0x0300019C
_081D7ACC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7AD4:
	str r0, [r5]
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
	beq _081D7AF8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7B00
_081D7AF8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7B00:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7B38 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7B70
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7B3C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7B30
	ldrb r0, [r4, #5]
_081D7B30:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7B4C
	.align 2, 0
_081D7B38: .4byte 0x0000FFFF
_081D7B3C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7B4C
	strh r1, [r4, #8]
_081D7B4C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _081D7B70
	movs r0, #1
	strb r0, [r4, #7]
_081D7B70:
	movs r0, #0x83
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x1c
	str r0, [sp]
	movs r0, #1
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7B96:
	adds r4, r7, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7BC4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7BCC
_081D7BC4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7BCC:
	str r0, [r5]
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
	beq _081D7BF0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7BF8
_081D7BF0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7BF8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7C30 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7C76
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7C3A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7C34
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D7C50
	.align 2, 0
_081D7C30: .4byte 0x0000FFFF
_081D7C34:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7C4E
_081D7C3A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7C4E
	strh r1, [r4, #8]
	movs r2, #1
	b _081D7C50
_081D7C4E:
	movs r2, #0
_081D7C50:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _081D7C78
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7C78
_081D7C76:
	movs r2, #0
_081D7C78:
	cmp r2, #0
	beq _081D7C9E
	adds r1, r5, #0
	adds r1, #0xfe
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r0, r5, #0
	adds r0, #0x1c
	str r0, [sp]
	movs r0, #3
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7C9E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
