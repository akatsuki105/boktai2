	push {r4, r5, r6, r7, lr}
	adds r0, #0x2c
	movs r1, #0
_0801A5B6:
	adds r6, r1, #1
	adds r7, r0, #0
	adds r7, #0x90
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #2
_0801A5C2:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge _0801A5C2
	adds r1, r6, #0
	adds r0, r7, #0
	cmp r1, #2
	ble _0801A5B6
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
