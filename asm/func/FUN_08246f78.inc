	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r5, r2, #0
	adds r6, r5, #0
	adds r6, #0x10
	ldr r3, [r0, #0x18]
	adds r4, r5, #0
	adds r4, #0x38
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x38]
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
	beq _08246FC8
	ldr r0, [r5, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08246FD0
_08246FC8:
	ldr r0, [r5, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08246FD0:
	str r0, [r5, #0x10]
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
	beq _08246FF4
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08246FFC
_08246FF4:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08246FFC:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08247034 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0824705E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08247038
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0824702C
	ldrb r0, [r4, #5]
_0824702C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08247048
	.align 2, 0
_08247034: .4byte 0x0000FFFF
_08247038:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08247048
	strh r1, [r4, #8]
_08247048:
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
_0824705E:
	ldrh r0, [r5, #2]
	ldrb r1, [r5, #1]
	cmp r0, r1
	bne _0824707E
	ldr r0, [r5, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x10]
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _08247078
	subs r0, #1
	strb r0, [r5, #1]
_08247078:
	movs r0, #0
	strh r0, [r5, #2]
	b _08247088
_0824707E:
	ldr r0, [r5, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x10]
_08247088:
	ldrb r0, [r5, #1]
	cmp r0, #0
	bne _0824709C
	adds r0, r5, #0
	bl FUN_082469bc
	mov r2, r8
	ldrb r0, [r2, #2]
	subs r0, #1
	strb r0, [r2, #2]
_0824709C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
