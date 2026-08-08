	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	cmp r0, #1
	beq _080E53D2
	cmp r0, #1
	bgt _080E53BE
	cmp r0, #0
	beq _080E53C8
	b _080E53E6
_080E53BE:
	cmp r3, #2
	beq _080E53DC
	cmp r3, #3
	beq _080E53DC
	b _080E53E6
_080E53C8:
	movs r0, #0xc8
	lsls r0, r0, #1
	str r0, [r1]
	subs r0, #0x50
	b _080E53E4
_080E53D2:
	movs r0, #0
	str r0, [r1]
	movs r0, #0xaa
	lsls r0, r0, #1
	b _080E53E4
_080E53DC:
	movs r0, #0
	str r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
_080E53E4:
	str r0, [r2]
_080E53E6:
	pop {r0}
	bx r0
	.align 2, 0
