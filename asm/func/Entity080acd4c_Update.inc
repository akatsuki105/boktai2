	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r5, #0x18
	adds r4, r0, #0
	adds r4, #0x44
	movs r6, #7
_080ACC68:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080ACC74
	adds r0, r5, #0
	bl Entity080acd4cElem_Update
_080ACC74:
	adds r5, #0x30
	adds r4, #0x30
	subs r6, #1
	cmp r6, #0
	bge _080ACC68
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
