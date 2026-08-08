	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	cmp r0, #1
	beq _080E5416
	cmp r0, #1
	bgt _080E5402
	cmp r0, #0
	beq _080E540C
	b _080E5432
_080E5402:
	cmp r3, #2
	beq _080E5420
	cmp r3, #3
	beq _080E542A
	b _080E5432
_080E540C:
	movs r0, #0xeb
	lsls r0, r0, #1
	str r0, [r1]
	subs r0, #0x50
	b _080E5430
_080E5416:
	movs r0, #0
	str r0, [r1]
	movs r0, #0x9b
	lsls r0, r0, #1
	b _080E5430
_080E5420:
	movs r0, #0
	str r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
	b _080E5430
_080E542A:
	movs r0, #0
	str r0, [r1]
	movs r0, #0xf0
_080E5430:
	str r0, [r2]
_080E5432:
	pop {r0}
	bx r0
	.align 2, 0
