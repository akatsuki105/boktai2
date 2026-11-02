	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r1, _081EE248 @ =0x0000069C
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081EE238:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081EE24C
	movs r0, #1
	b _081EE24E
	.align 2, 0
_081EE248: .4byte 0x0000069C
_081EE24C:
	movs r0, #0
_081EE24E:
	cmp r0, #0
	beq _081EE258
	adds r0, r4, #0
	bl Particle_Remove
_081EE258:
	adds r4, #0x40
	adds r5, #1
	cmp r5, #0x19
	ble _081EE238
	movs r1, #0
	ldr r0, _081EE270 @ =0x030001CC
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EE270: .4byte 0x030001CC
