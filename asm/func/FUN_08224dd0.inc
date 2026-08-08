	push {r4, lr}
	adds r2, r1, #0
	adds r4, r0, #0
	movs r0, #1
	adds r3, r2, #0
	adds r3, #0xad
	ldrb r1, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08224DF0
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	movs r0, #1
	b _08224DF2
_08224DF0:
	movs r0, #0
_08224DF2:
	cmp r0, #0
	beq _08224E00
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_08224E00:
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_08223470
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
