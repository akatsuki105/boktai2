	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r2, [r4, #0x1d]
	lsls r6, r2, #4
	ldrb r1, [r4, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08001E3A
	lsls r1, r2, #5
	ldr r0, [r4, #0x30]
	b _08001E3E
_08001E3A:
	lsls r1, r2, #5
	ldr r0, [r4, #0x24]
_08001E3E:
	adds r5, r0, r1
	ldrb r3, [r4, #0x1d]
	ldrb r2, [r4, #0x1f]
	adds r0, r3, r2
	cmp r0, #0xd
	bgt _08001E4E
	lsls r1, r2, #4
	b _08001E54
_08001E4E:
	movs r0, #0xd
	subs r0, r0, r3
	lsls r1, r0, #4
_08001E54:
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0x28]
	movs r3, #0x1c
	ldrsb r3, [r4, r3]
	str r6, [sp]
	str r1, [sp, #4]
	adds r1, r5, #0
	bl FUN_08001884
	ldrb r0, [r4, #0x1f]
	ldrb r1, [r4, #0x1d]
	adds r0, r0, r1
	movs r1, #0
	strb r0, [r4, #0x1d]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bls _08001E92
	strb r1, [r4, #0x1d]
	ldrb r0, [r4, #0x1e]
	ldrb r2, [r4, #0x1c]
	adds r0, r0, r2
	strb r0, [r4, #0x1c]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x40
	ble _08001E92
	strb r1, [r4, #0x1c]
	ldr r0, [r4, #0x28]
	str r0, [r4, #0x24]
	strb r1, [r4, #0x1b]
_08001E92:
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
