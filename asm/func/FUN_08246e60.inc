	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	mov ip, r2
	mov r5, ip
	adds r5, #0x10
	ldr r3, [r0, #0x18]
	mov r4, ip
	adds r4, #0x38
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r2, #0x38]
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
	beq _08246EB0
	mov r3, ip
	ldr r0, [r3, #0x10]
	movs r1, #4
	orrs r0, r1
	str r0, [r3, #0x10]
	b _08246EBE
_08246EB0:
	mov r1, ip
	ldr r0, [r1, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2, #0x10]
_08246EBE:
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
	beq _08246EE0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08246EE8
_08246EE0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08246EE8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08246F20 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08246F4A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08246F24
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08246F18
	ldrb r0, [r4, #5]
_08246F18:
	subs r0, #1
	strh r0, [r4, #8]
	b _08246F34
	.align 2, 0
_08246F20: .4byte 0x0000FFFF
_08246F24:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08246F34
	strh r1, [r4, #8]
_08246F34:
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
_08246F4A:
	mov r3, ip
	ldrh r1, [r3, #4]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmp r0, #0
	ble _08246F72
	subs r0, r1, #1
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bne _08246F72
	movs r0, #2
	strb r0, [r3]
	movs r0, #0xa
	strb r0, [r3, #1]
	strh r1, [r3, #2]
	ldrb r0, [r7, #3]
	subs r0, #1
	strb r0, [r7, #3]
_08246F72:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
