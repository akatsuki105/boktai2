	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	cmp r0, #1
	beq _080E55F8
	cmp r0, #1
	bgt _080E55E6
	cmp r0, #0
	beq _080E55F0
	b _080E560C
_080E55E6:
	cmp r3, #2
	beq _080E5602
	cmp r3, #3
	beq _080E5602
	b _080E560C
_080E55F0:
	movs r0, #0xbe
	str r0, [r1]
	movs r0, #0x78
	b _080E560A
_080E55F8:
	movs r0, #0
	str r0, [r1]
	movs r0, #0xaa
	lsls r0, r0, #1
	b _080E560A
_080E5602:
	movs r0, #0
	str r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
_080E560A:
	str r0, [r2]
_080E560C:
	pop {r0}
	bx r0
