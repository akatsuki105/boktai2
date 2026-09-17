	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r7, r1, #0
	adds r5, r7, #0
	adds r2, r7, #0
	adds r2, #0x44
	ldrb r0, [r2]
	cmp r0, #0
	beq _081EAFE0
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r0, #0
	strb r0, [r2]
_081EAFE0:
	ldrh r0, [r7, #0x30]
	cmp r0, #1
	bne _081EAFF2
	ldrh r0, [r7, #0x36]
	cmp r0, #0
	bne _081EAFF2
	ldrh r0, [r7, #0x1a]
	adds r0, #0x20
	strh r0, [r7, #0x1a]
_081EAFF2:
	ldr r3, [r3, #0x1c]
	adds r4, r7, #0
	adds r4, #0x28
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x28]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
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
	beq _081EB034
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081EB03C
_081EB034:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081EB03C:
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
	beq _081EB060
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081EB068
_081EB060:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081EB068:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081EB0A0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081EB0D8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081EB0AA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081EB0A4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081EB0C0
	.align 2, 0
_081EB0A0: .4byte 0x0000FFFF
_081EB0A4:
	subs r0, #1
	strh r0, [r4, #8]
	b _081EB0BE
_081EB0AA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081EB0BE
	strh r1, [r4, #8]
	movs r2, #1
	b _081EB0C0
_081EB0BE:
	movs r2, #0
_081EB0C0:
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
	b _081EB0DA
_081EB0D8:
	movs r2, #0
_081EB0DA:
	cmp r2, #0
	beq _081EB0E6
	adds r1, r7, #0
	adds r1, #0x42
	movs r0, #2
	strb r0, [r1]
_081EB0E6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
