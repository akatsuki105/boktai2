	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	adds r0, #0x42
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _080CEEEA
	movs r0, #0xff
	strb r0, [r4, #1]
	strb r6, [r4, #4]
	strb r6, [r4, #2]
	b _080CEF0A
_080CEEEA:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl GetMagicCategory
	strb r0, [r4, #1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl GetMagicCost
	strb r0, [r4, #4]
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, r5, #0
	bl FUN_080cec70
	strb r0, [r4, #2]
_080CEF0A:
	strb r6, [r4, #3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
