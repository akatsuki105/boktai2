	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x14]
	lsls r0, r0, #2
	ldr r2, [r3, #0x54]
	adds r2, r2, r0
	strh r1, [r3, #0x10]
	ldrh r1, [r2, #2]
	ldrh r0, [r3, #0x10]
	muls r0, r1, r0
	cmp r0, #0
	blt _08237258
	asrs r0, r0, #6
	b _0823725E
_08237258:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0823725E:
	strh r0, [r3, #0xe]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0823726A
	movs r0, #1
	strh r0, [r3, #0xe]
_0823726A:
	ldrb r0, [r3, #0x1d]
	movs r2, #0xfe
	ands r2, r0
	movs r4, #0
	strb r2, [r3, #0x1d]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	ldrh r1, [r3, #0xe]
	cmp r0, r1
	blt _082372A2
	ldrh r1, [r3, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08237290
	ldrh r0, [r3, #0x14]
	cmp r0, #0
	bne _082372A2
	b _0823729A
_08237290:
	ldrh r0, [r3, #0x14]
	adds r0, #1
	ldrh r1, [r3, #0x16]
	cmp r0, r1
	blt _082372A2
_0823729A:
	movs r1, #1
	adds r0, r2, #0
	orrs r0, r1
	strb r0, [r3, #0x1d]
_082372A2:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
