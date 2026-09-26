	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	movs r0, #0xe4
	lsls r0, r0, #3
	adds r7, r6, r0
	adds r0, #8
	adds r4, r6, r0
_080DBDD0:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DBDE0
	movs r0, #1
	b _080DBDE2
_080DBDE0:
	movs r0, #0
_080DBDE2:
	cmp r0, #0
	beq _080DBDF8
	movs r1, #0x13
	ldrsb r1, [r4, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r6, r0
	bl Particle_Remove
_080DBDF8:
	adds r4, #0x18
	adds r5, #1
	cmp r5, #0x1f
	ble _080DBDD0
	movs r1, #0
	ldr r0, _080DBE10 @ =0x03000164
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DBE10: .4byte 0x03000164
