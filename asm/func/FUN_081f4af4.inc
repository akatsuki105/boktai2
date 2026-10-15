	push {r4, r5, r6, lr}
	adds r5, r1, #0
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F4BEE
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	movs r2, #0xba
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	ldr r6, _081F4B5C @ =0x00000175
	adds r0, r5, r6
	ldrb r3, [r0]
	ldr r2, _081F4B60 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081F4B64 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081F4B68 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r0, [r0]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r6, r5, r1
	adds r4, r0, #0
	adds r4, #0x40
	ldr r1, _081F4B6C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081F4B70
	asrs r2, r0, #0xc
	b _081F4B76
	.align 2, 0
_081F4B5C: .4byte 0x00000175
_081F4B60: .4byte 0x030046B8
_081F4B64: .4byte 0x000003FF
_081F4B68: .4byte 0x0203B400
_081F4B6C: .4byte 0x085B0A08
_081F4B70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F4B76:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081F4B8E
	asrs r0, r0, #0xc
	b _081F4B94
_081F4B8E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F4B94:
	movs r4, #0
	movs r3, #0
	strh r0, [r6, #4]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r2, r5, #0
	adds r2, #0x1c
	ldrh r0, [r1]
	ldrh r6, [r5, #0x1c]
	adds r0, r0, r6
	strh r0, [r1]
	ldrh r0, [r1, #2]
	ldrh r6, [r2, #2]
	adds r0, r0, r6
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r1, #0
	ldrh r2, [r5, #0x1e]
	adds r0, r0, r2
	movs r6, #0xb3
	lsls r6, r6, #1
	adds r1, r5, r6
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r4, [r0]
	movs r0, #1
	strb r0, [r5, #8]
	strb r0, [r5, #9]
_081F4BEE:
	movs r6, #0xb8
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrh r0, [r0]
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _081F4C14
	adds r0, r5, #0
	adds r0, #0x1c
	ldr r2, _081F4C80 @ =0x00000175
	adds r1, r5, r2
	ldrb r1, [r1]
	adds r1, #0x80
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl FUN_081f4a08
_081F4C14:
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	cmp r0, #0
	beq _081F4C4E
	movs r0, #8
	ldrsb r0, [r5, r0]
	movs r4, #0x40
	subs r0, r4, r0
	ldrh r1, [r6]
	bl Div
	ldrb r1, [r5, #8]
	adds r1, r1, r0
	strb r1, [r5, #8]
	movs r0, #9
	ldrsb r0, [r5, r0]
	subs r4, r4, r0
	ldrh r1, [r6]
	adds r0, r4, #0
	bl Div
	ldrb r1, [r5, #9]
	adds r1, r1, r0
	strb r1, [r5, #9]
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
_081F4C4E:
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
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
	beq _081F4C84
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F4C8C
	.align 2, 0
_081F4C80: .4byte 0x00000175
_081F4C84:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F4C8C:
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
	beq _081F4CB0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F4CB8
_081F4CB0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F4CB8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F4CF0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _081F4D36
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F4CFA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F4CF4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081F4D10
	.align 2, 0
_081F4CF0: .4byte 0x0000FFFF
_081F4CF4:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F4D0E
_081F4CFA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F4D0E
	strh r1, [r4, #8]
	movs r2, #1
	b _081F4D10
_081F4D0E:
	movs r2, #0
_081F4D10:
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
	bne _081F4D38
	movs r0, #1
	strb r0, [r4, #7]
	b _081F4D38
_081F4D36:
	movs r2, #0
_081F4D38:
	movs r6, #0xba
	lsls r6, r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	cmp r2, #0
	beq _081F4D6E
	movs r1, #0xbd
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081F4D6E
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	subs r6, #2
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	b _081F4D7A
_081F4D6E:
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081F4D7A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
