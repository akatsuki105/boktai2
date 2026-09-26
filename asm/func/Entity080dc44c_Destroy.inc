	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r7, r6, r0
	adds r0, #4
	adds r4, r6, r0
_080DC3D4:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DC3E4
	movs r0, #1
	b _080DC3E6
_080DC3E4:
	movs r0, #0
_080DC3E6:
	cmp r0, #0
	beq _080DC3FC
	movs r1, #0x17
	ldrsb r1, [r4, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r6, r0
	bl Particle_Remove
_080DC3FC:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #7
	ble _080DC3D4
	movs r1, #0
	ldr r0, _080DC414 @ =0x03000168
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DC414: .4byte 0x03000168
