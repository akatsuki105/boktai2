	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldrh r2, [r1, #0x1c]
	ldrh r0, [r4, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x20]
	ldrh r1, [r4, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _080E60DC
	rsbs r2, r2, #0
_080E60DC:
	lsls r1, r0, #0x10
	cmp r2, r5
	bhi _080E60EE
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _080E60EA
	rsbs r2, r2, #0
_080E60EA:
	cmp r2, r6
	bls _080E6140
_080E60EE:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _080E60FA
	cmp r1, #0
	beq _080E6140
_080E60FA:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	lsrs r2, r0, #6
	ldrb r0, [r4, #5]
	adds r0, #0x20
	ands r0, r1
	asrs r0, r0, #6
	subs r0, r2, r0
	cmp r0, #0
	bge _080E6118
	rsbs r0, r0, #0
_080E6118:
	cmp r0, #0
	beq _080E6140
	lsls r0, r2, #0x1e
	lsrs r2, r0, #0x18
	cmp r2, #0
	blt _080E6128
	asrs r0, r2, #5
	b _080E612E
_080E6128:
	rsbs r0, r2, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080E612E:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #1
	b _080E6142
_080E6140:
	movs r0, #0
_080E6142:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
