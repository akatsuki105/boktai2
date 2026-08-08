	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r7, r2, #0
	adds r5, r7, #0
	adds r5, #0x10
	ldr r3, [r0, #0x18]
	adds r4, r7, #0
	adds r4, #0x38
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x38]
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
	beq _08246B4C
	ldr r0, [r7, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08246B54
_08246B4C:
	ldr r0, [r7, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08246B54:
	str r0, [r7, #0x10]
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
	beq _08246B78
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08246B80
_08246B78:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08246B80:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08246BB8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08246BF0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08246BC2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08246BBC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08246BD8
	.align 2, 0
_08246BB8: .4byte 0x0000FFFF
_08246BBC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08246BD6
_08246BC2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08246BD6
	strh r1, [r4, #8]
	movs r2, #1
	b _08246BD8
_08246BD6:
	movs r2, #0
_08246BD8:
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
	b _08246BF2
_08246BF0:
	movs r2, #0
_08246BF2:
	cmp r2, #0
	beq _08246C04
	adds r0, r7, #0
	bl FUN_082469bc
	mov r1, r8
	ldrb r0, [r1, #2]
	subs r0, #1
	strb r0, [r1, #2]
_08246C04:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
