	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	cmp r0, #1
	beq _080E5532
	cmp r0, #1
	bgt _080E551E
	cmp r0, #0
	beq _080E5528
	b _080E5546
_080E551E:
	cmp r3, #2
	beq _080E553C
	cmp r3, #3
	beq _080E553C
	b _080E5546
_080E5528:
	movs r0, #0xc3
	lsls r0, r0, #1
	str r0, [r1]
	subs r0, #0x50
	b _080E5544
_080E5532:
	movs r0, #0
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	b _080E5544
_080E553C:
	movs r0, #0
	str r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
_080E5544:
	str r0, [r2]
_080E5546:
	pop {r0}
	bx r0
	.align 2, 0
