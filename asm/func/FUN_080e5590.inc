	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	cmp r0, #1
	beq _080E55B8
	cmp r0, #1
	bgt _080E55A6
	cmp r0, #0
	beq _080E55B0
	b _080E55CC
_080E55A6:
	cmp r3, #2
	beq _080E55C2
	cmp r3, #3
	beq _080E55C2
	b _080E55CC
_080E55B0:
	movs r0, #0xfa
	str r0, [r1]
	movs r0, #0xc8
	b _080E55CA
_080E55B8:
	movs r0, #0
	str r0, [r1]
	movs r0, #0xaa
	lsls r0, r0, #1
	b _080E55CA
_080E55C2:
	movs r0, #0
	str r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
_080E55CA:
	str r0, [r2]
_080E55CC:
	pop {r0}
	bx r0
