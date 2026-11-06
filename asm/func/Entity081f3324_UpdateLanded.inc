	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0xf0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F29F2
	adds r2, r5, #0
	adds r2, #0x90
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r5, #0x1c]
	subs r0, #0x80
	movs r4, #0
	movs r2, #0
	strh r0, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r3, #0x34]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #2
	strb r0, [r5, #7]
	strb r4, [r6]
_081F29F2:
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
	beq _081F2A22
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F2A2A
_081F2A22:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F2A2A:
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
	beq _081F2A4E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F2A56
_081F2A4E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F2A56:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F2A8C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F2AC4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F2A90
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F2A86
	ldrb r0, [r4, #5]
_081F2A86:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F2AA0
	.align 2, 0
_081F2A8C: .4byte 0x0000FFFF
_081F2A90:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F2AA0
	strh r1, [r4, #8]
_081F2AA0:
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
	bne _081F2AC4
	movs r0, #1
	strb r0, [r4, #7]
_081F2AC4:
	adds r4, r5, #0
	adds r4, #0x98
	adds r1, r5, #0
	adds r1, #0x90
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r1, r5, #0
	adds r1, #0xf1
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F2AE8
	subs r0, #1
	b _081F2AEE
_081F2AE8:
	adds r1, r5, #0
	adds r1, #0xea
	movs r0, #4
_081F2AEE:
	strb r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
