	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrb r0, [r2]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #0xe
	beq _08231240
	cmp r1, #0xe
	bgt _08231232
	cmp r1, #0xd
	beq _08231238
	b _08231264
_08231232:
	cmp r1, #0xf
	beq _0823124E
	b _08231264
_08231238:
	ldrb r0, [r2, #1]
	str r0, [r3]
	adds r0, r2, #2
	b _08231268
_08231240:
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	ldrb r1, [r2, #1]
	orrs r1, r0
	str r1, [r3]
	adds r0, r2, #3
	b _08231268
_0823124E:
	adds r0, r2, #1
	ldrb r1, [r0, #2]
	lsls r1, r1, #0x10
	ldrb r0, [r0, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #1]
	orrs r1, r0
	str r1, [r3]
	adds r0, r2, #4
	b _08231268
_08231264:
	str r1, [r3]
	adds r0, r2, #1
_08231268:
	pop {r1}
	bx r1
