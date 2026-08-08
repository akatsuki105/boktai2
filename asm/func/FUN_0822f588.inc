	push {r4, lr}
	mov ip, r0
	adds r3, r1, #0
	ldrh r0, [r3]
	mov r1, ip
	strh r0, [r1]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0822F5A0
	ldr r0, [r3, #8]
	str r0, [r1, #8]
_0822F5A0:
	ldrh r0, [r3, #0xc]
	mov r4, ip
	strh r0, [r4, #0xc]
	ldrh r0, [r3, #0xe]
	strh r0, [r4, #0xe]
	ldrh r0, [r3, #0x10]
	strh r0, [r4, #0x10]
	ldrh r0, [r3, #0x12]
	strh r0, [r4, #0x12]
	ldrh r0, [r3, #0x14]
	strh r0, [r4, #0x14]
	ldrh r0, [r3, #0x16]
	strh r0, [r4, #0x16]
	ldrh r0, [r3, #0x18]
	strh r0, [r4, #0x18]
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0822F5CA
	ldrb r0, [r3, #0x1a]
	strb r0, [r4, #0x1a]
_0822F5CA:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0822F5D8
	ldrb r0, [r3, #0x1b]
	mov r1, ip
	strb r0, [r1, #0x1b]
_0822F5D8:
	ldrb r0, [r3, #0x1d]
	mov r4, ip
	strb r0, [r4, #0x1d]
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0822F5EE
	ldr r0, [r3, #0x20]
	ldr r1, [r3, #0x24]
	str r0, [r4, #0x20]
	str r1, [r4, #0x24]
_0822F5EE:
	ldrh r0, [r3, #0x28]
	mov r1, ip
	strh r0, [r1, #0x28]
	ldrh r0, [r3, #0x2a]
	strh r0, [r1, #0x2a]
	adds r0, r3, #0
	adds r0, #0x34
	ldrb r1, [r0]
	mov r0, ip
	adds r0, #0x34
	strb r1, [r0]
	adds r0, r3, #0
	adds r0, #0x35
	ldrb r0, [r0]
	mov r1, ip
	adds r1, #0x35
	strb r0, [r1]
	ldrh r0, [r3, #0x36]
	mov r4, ip
	strh r0, [r4, #0x36]
	ldrh r0, [r3, #0x38]
	strh r0, [r4, #0x38]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0822F626
	ldrh r0, [r3, #0x3a]
	strh r0, [r4, #0x3a]
_0822F626:
	ldr r0, [r3, #0x4c]
	mov r1, ip
	str r0, [r1, #0x4c]
	ldr r0, [r3, #0x50]
	str r0, [r1, #0x50]
	ldr r0, [r3, #0x54]
	str r0, [r1, #0x54]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
