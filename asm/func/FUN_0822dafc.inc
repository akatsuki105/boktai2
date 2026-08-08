	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, _0822DB58 @ =0x085B0130
	ldrb r0, [r5, #3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r4, #0xa]
	ldrb r0, [r5, #3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsrs r0, r0, #8
	strb r0, [r4, #0xb]
	ldrb r1, [r5, #3]
	movs r0, #3
	ands r0, r1
	lsls r3, r0, #0xe
	movs r0, #0xc
	ands r0, r1
	lsls r0, r0, #0x1c
	orrs r3, r0
	str r3, [r4, #0x14]
	ldrb r1, [r5, #2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0822DB3E
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r3, r0
	str r3, [r4, #0x14]
_0822DB3E:
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r5, [r5, #4]
	adds r0, r0, r5
	strh r0, [r4, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0822DB58: .4byte 0x085B0130
