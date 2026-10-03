	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xe7
	ldr r0, _0804CD00 @ =0x03004740
	ldrb r0, [r0, #3]
	lsls r0, r0, #1
	ldrb r1, [r3]
	orrs r0, r1
	movs r4, #0
	strb r0, [r3]
	movs r3, #0x9b
	lsls r3, r3, #1
	adds r1, r2, r3
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, r1
	bne _0804CD04
	adds r0, r2, #0
	adds r0, #0xe8
	strb r4, [r0]
	subs r0, #0xb2
	strb r4, [r0]
	b _0804CD14
	.align 2, 0
_0804CD00: .4byte 0x03004740
_0804CD04:
	adds r1, r2, #0
	adds r1, #0xe8
	movs r0, #1
	strb r0, [r1]
	subs r1, #8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0804CD14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
