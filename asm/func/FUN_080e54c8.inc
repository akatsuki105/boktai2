	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	cmp r0, #1
	beq _080E54FA
	cmp r0, #1
	bgt _080E54DE
	cmp r0, #0
	beq _080E54E8
	b _080E5504
_080E54DE:
	cmp r3, #2
	beq _080E54F2
	cmp r3, #3
	beq _080E54FA
	b _080E5504
_080E54E8:
	movs r0, #0xb4
	lsls r0, r0, #1
	str r0, [r1]
	subs r0, #0x50
	b _080E5502
_080E54F2:
	movs r0, #0
	str r0, [r1]
	movs r0, #0xd2
	b _080E5502
_080E54FA:
	movs r0, #0
	str r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
_080E5502:
	str r0, [r2]
_080E5504:
	pop {r0}
	bx r0
