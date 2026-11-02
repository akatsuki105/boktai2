	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #0
	beq _081EE03C
	movs r0, #0
	strb r0, [r1]
_081EE03C:
	ldr r0, _081EE074 @ =0x030001CC
	ldr r2, [r0]
	adds r6, r5, #0
	adds r6, #0x33
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r1, _081EE078 @ =0x0000069C
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r5, #0
	adds r0, #0x32
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl Particle_Remove
	movs r0, #0xff
	strb r0, [r6]
	strh r4, [r5, #0x30]
	strh r4, [r5, #0x38]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081EE074: .4byte 0x030001CC
_081EE078: .4byte 0x0000069C
