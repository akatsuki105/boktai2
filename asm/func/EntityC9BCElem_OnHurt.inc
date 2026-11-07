	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	cmp r0, r1
	beq _0800CBFE
	movs r0, #7
	ldr r1, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800CBFE
	adds r4, r2, #0
	adds r4, #0x40
	ldrb r0, [r4]
	cmp r0, #0
	bne _0800CBFE
	movs r0, #1
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r3, #0x38]
	str r0, [r2, #0x24]
	movs r0, #0xa
	strb r0, [r4]
_0800CBFE:
	pop {r4}
	pop {r0}
	bx r0
