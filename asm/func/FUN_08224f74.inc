	push {r4, lr}
	adds r4, r1, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0xad
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08224F92
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #1
	b _08224F94
_08224F92:
	movs r0, #0
_08224F94:
	cmp r0, #0
	beq _08224FB2
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0xcc
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
_08224FB2:
	pop {r4}
	pop {r0}
	bx r0
