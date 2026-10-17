	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _080CEBBE
	movs r0, #0
	b _080CEBF0
_080CEBBE:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl GetMagicCost
	adds r2, r0, #0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bgt _080CEBEE
	movs r1, #2
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CEBEE
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
_080CEBEE:
	adds r0, r2, #0
_080CEBF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
