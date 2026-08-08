	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	cmp r0, #1
	beq _080E5576
	cmp r0, #1
	bgt _080E5562
	cmp r0, #0
	beq _080E556C
	b _080E558A
_080E5562:
	cmp r3, #2
	beq _080E5580
	cmp r3, #3
	beq _080E5580
	b _080E558A
_080E556C:
	movs r0, #0xc3
	lsls r0, r0, #1
	str r0, [r1]
	subs r0, #0x50
	b _080E5588
_080E5576:
	movs r0, #0
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	b _080E5588
_080E5580:
	movs r0, #0
	str r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
_080E5588:
	str r0, [r2]
_080E558A:
	pop {r0}
	bx r0
	.align 2, 0
