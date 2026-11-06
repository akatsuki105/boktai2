	push {r4, r5, r6, lr}
	adds r5, r1, #0
	movs r0, #0x91
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081F8160
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	movs r1, #0x89
	lsls r1, r1, #1
	adds r3, r5, r1
	movs r2, #0
	movs r1, #0
	movs r0, #0xf
	strh r0, [r3]
	movs r3, #0x90
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	strb r2, [r4]
	movs r0, #1
	strb r0, [r5, #8]
	strb r0, [r5, #9]
_081F8160:
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _081F817A
	adds r0, r5, #0
	adds r0, #0x1c
	bl Entity081f8a28_SpawnTrail
_081F817A:
	movs r2, #0x89
	lsls r2, r2, #1
	adds r6, r5, r2
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #0
	ble _081F81BA
	movs r0, #8
	ldrsb r0, [r5, r0]
	movs r4, #0x40
	subs r0, r4, r0
	movs r2, #0
	ldrsh r1, [r6, r2]
	bl Div
	ldrb r1, [r5, #8]
	adds r1, r1, r0
	strb r1, [r5, #8]
	movs r0, #9
	ldrsb r0, [r5, r0]
	subs r4, r4, r0
	movs r3, #0
	ldrsh r1, [r6, r3]
	adds r0, r4, #0
	bl Div
	ldrb r1, [r5, #9]
	adds r1, r1, r0
	strb r1, [r5, #9]
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
_081F81BA:
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
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
	beq _081F81EA
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F81F2
_081F81EA:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F81F2:
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
	beq _081F8216
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F821E
_081F8216:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F821E:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F8254 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081F828C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F8258
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F824E
	ldrb r0, [r4, #5]
_081F824E:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F8268
	.align 2, 0
_081F8254: .4byte 0x0000FFFF
_081F8258:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F8268
	strh r1, [r4, #8]
_081F8268:
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
	bne _081F828C
	movs r0, #1
	strb r0, [r4, #7]
_081F828C:
	movs r3, #0x89
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _081F82B8
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r3, #0x10
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _081F82C4
_081F82B8:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081F82C4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
