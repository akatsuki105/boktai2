	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r1, [r5]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r5]
	adds r4, r5, #0
	adds r4, #0x70
	ldr r1, [r0, #0x18]
	adds r0, r5, #0
	adds r0, #0xb0
	ldrb r3, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r0, r5, #0
	adds r0, #0x78
	movs r3, #1
	strh r3, [r0]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x70]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0772
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D077A
_081D0772:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D077A:
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
	beq _081D079E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D07A6
_081D079E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D07A6:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D07DC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D0814
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D07E0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D07D6
	ldrb r0, [r4, #5]
_081D07D6:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D07F0
	.align 2, 0
_081D07DC: .4byte 0x0000FFFF
_081D07E0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D07F0
	strh r1, [r4, #8]
_081D07F0:
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
	bne _081D0814
	movs r0, #1
	strb r0, [r4, #7]
_081D0814:
	adds r1, r5, #0
	adds r1, #0xb6
	movs r0, #6
	strh r0, [r1]
	adds r2, r5, #0
	adds r2, #0xb8
	ldrh r1, [r2]
	ldr r0, _081D0834 @ =0x0000FFDF
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D0834: .4byte 0x0000FFDF
