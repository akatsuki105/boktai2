	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	beq _0822A558
	movs r2, #0
	movs r0, #0
	strh r0, [r4, #0x10]
	strb r2, [r4, #0x12]
	strb r2, [r4, #0x13]
	ldr r1, _0822A560 @ =0x03004030
	ldrb r0, [r5, #1]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0x14]
	ldr r1, _0822A564 @ =0x03003FC0
	ldrb r0, [r5, #1]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0x15]
	strb r2, [r4, #0x16]
	strb r2, [r4, #0x17]
	ldr r3, [r4, #0x18]
	movs r0, #0xe0
	lsls r0, r0, #5
	ands r3, r0
	ldrb r2, [r5, #1]
	movs r1, #3
	ands r1, r2
	lsls r1, r1, #0xe
	movs r0, #0xc
	ands r0, r2
	lsls r0, r0, #0x1c
	orrs r1, r0
	orrs r3, r1
	str r3, [r4, #0x18]
	ldrb r1, [r5]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0822A556
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r3, r0
	str r3, [r4, #0x18]
_0822A556:
	str r5, [r4, #0xc]
_0822A558:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0822A560: .4byte 0x03004030
_0822A564: .4byte 0x03003FC0
