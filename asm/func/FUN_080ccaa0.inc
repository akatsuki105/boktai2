	push {lr}
	adds r3, r0, #0
	movs r0, #3
	ands r0, r3
	cmp r0, #1
	beq _080CCABC
	cmp r0, #1
	bgt _080CCAB6
	cmp r0, #0
	beq _080CCABC
	b _080CCABA
_080CCAB6:
	cmp r0, #2
	beq _080CCABC
_080CCABA:
	movs r0, #1
_080CCABC:
	str r0, [r1]
	cmp r3, #2
	bhi _080CCAC6
	movs r0, #0
	b _080CCADA
_080CCAC6:
	subs r0, r3, #3
	cmp r0, #1
	bhi _080CCAD0
	movs r0, #2
	b _080CCADA
_080CCAD0:
	cmp r3, #5
	bne _080CCAD8
	movs r0, #3
	b _080CCADA
_080CCAD8:
	movs r0, #1
_080CCADA:
	str r0, [r2]
	pop {r0}
	bx r0
