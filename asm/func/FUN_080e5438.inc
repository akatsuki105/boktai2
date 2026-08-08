	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	cmp r0, #1
	beq _080E5462
	cmp r0, #1
	bgt _080E544E
	cmp r0, #0
	beq _080E5458
	b _080E5476
_080E544E:
	cmp r3, #2
	beq _080E546C
	cmp r3, #3
	beq _080E546C
	b _080E5476
_080E5458:
	movs r0, #0xc8
	lsls r0, r0, #1
	str r0, [r1]
	subs r0, #0x50
	b _080E5474
_080E5462:
	movs r0, #0
	str r0, [r1]
	movs r0, #0xaa
	lsls r0, r0, #1
	b _080E5474
_080E546C:
	movs r0, #0
	str r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
_080E5474:
	str r0, [r2]
_080E5476:
	pop {r0}
	bx r0
	.align 2, 0
