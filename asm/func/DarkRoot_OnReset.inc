	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r2, #0
	str r2, [r1]
	movs r1, #0xcd
	lsls r1, r1, #3
	adds r0, r0, r1
	strh r2, [r0]
	ldrh r0, [r4, #8]
	adds r0, #0x20
	strh r0, [r4, #8]
	ldrh r0, [r4, #0xc]
	adds r0, #0x20
	strh r0, [r4, #0xc]
	ldr r2, _081A4F6C @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A4F70
	ldr r2, [r4, #0x44]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _081A4F7A
	.align 2, 0
_081A4F6C: .4byte 0x0000025D
_081A4F70:
	ldr r2, [r4, #0x44]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_081A4F7A:
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
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
	beq _081A4FB6
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081A4FBE
_081A4FB6:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081A4FBE:
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
	beq _081A4FE2
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081A4FEA
_081A4FE2:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081A4FEA:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081A5020 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081A5058
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081A5024
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081A501A
	ldrb r0, [r4, #5]
_081A501A:
	subs r0, #1
	strh r0, [r4, #8]
	b _081A5034
	.align 2, 0
_081A5020: .4byte 0x0000FFFF
_081A5024:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081A5034
	strh r1, [r4, #8]
_081A5034:
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
	bne _081A5058
	movs r0, #1
	strb r0, [r4, #7]
_081A5058:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
