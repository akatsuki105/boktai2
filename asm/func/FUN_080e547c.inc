	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	cmp r0, #1
	beq _080E54A6
	cmp r0, #1
	bgt _080E5492
	cmp r0, #0
	beq _080E549C
	b _080E54C4
_080E5492:
	cmp r3, #2
	beq _080E54B0
	cmp r3, #3
	beq _080E54BA
	b _080E54C4
_080E549C:
	movs r0, #0xc8
	lsls r0, r0, #1
	str r0, [r1]
	subs r0, #0x50
	b _080E54C2
_080E54A6:
	movs r0, #0
	str r0, [r1]
	movs r0, #0xaa
	lsls r0, r0, #1
	b _080E54C2
_080E54B0:
	movs r0, #0
	str r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
	b _080E54C2
_080E54BA:
	movs r0, #0
	str r0, [r1]
	movs r0, #0xc3
	lsls r0, r0, #1
_080E54C2:
	str r0, [r2]
_080E54C4:
	pop {r0}
	bx r0
