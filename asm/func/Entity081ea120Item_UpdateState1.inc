	push {r4, r5, r6, r7, lr}
	mov ip, r1
	movs r2, #0xb
	ldrsb r2, [r1, r2]
	movs r1, #0x2c
	muls r1, r2, r1
	adds r1, #0x1c
	adds r6, r0, r1
	mov r3, ip
	ldr r1, [r3]
	ldr r2, [r3, #4]
	str r1, [r6, #0x1c]
	str r2, [r6, #0x20]
	ldr r5, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r5, r1
	str r5, [r6]
	movs r1, #0xb
	ldrsb r1, [r3, r1]
	lsls r1, r1, #4
	adds r4, r1, r0
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _081E9E24
	movs r0, #4
	orrs r5, r0
	b _081E9E2A
_081E9E24:
	movs r0, #5
	rsbs r0, r0, #0
	ands r5, r0
_081E9E2A:
	str r5, [r6]
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
	beq _081E9E4E
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081E9E56
_081E9E4E:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9E56:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E9E90 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081E9ED6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9E9A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E9E94
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E9EB0
	.align 2, 0
_081E9E90: .4byte 0x0000FFFF
_081E9E94:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9EAE
_081E9E9A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9EAE
	strh r1, [r4, #8]
	movs r2, #1
	b _081E9EB0
_081E9EAE:
	movs r2, #0
_081E9EB0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _081E9ED8
	movs r0, #1
	strb r0, [r4, #7]
	b _081E9ED8
_081E9ED6:
	movs r2, #0
_081E9ED8:
	cmp r2, #0
	beq _081E9EE2
	movs r0, #2
	mov r3, ip
	strb r0, [r3, #0xa]
_081E9EE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
