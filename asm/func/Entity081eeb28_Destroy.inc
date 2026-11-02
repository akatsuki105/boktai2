	push {r4, r5, r6, lr}
	movs r5, #0
	movs r1, #0x97
	lsls r1, r1, #2
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081EEAC6:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081EEAD6
	movs r0, #1
	b _081EEAD8
_081EEAD6:
	movs r0, #0
_081EEAD8:
	cmp r0, #0
	beq _081EEAE2
	adds r0, r4, #0
	bl Particle_Remove
_081EEAE2:
	adds r4, #0x30
	adds r5, #1
	cmp r5, #0xb
	ble _081EEAC6
	movs r1, #0
	ldr r0, _081EEAF8 @ =0x030001D4
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EEAF8: .4byte 0x030001D4
