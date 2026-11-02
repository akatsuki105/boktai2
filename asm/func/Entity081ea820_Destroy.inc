	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_081EA7BA:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081EA7CA
	movs r0, #1
	b _081EA7CC
_081EA7CA:
	movs r0, #0
_081EA7CC:
	cmp r0, #0
	beq _081EA7E8
	movs r0, #0xd4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x38
	adds r4, r6, r4
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x8c
	adds r0, r4, #0
	bl ParticleShadow_Remove
_081EA7E8:
	adds r5, #1
	cmp r5, #7
	ble _081EA7BA
	ldr r1, _081EA7FC @ =0x030001BC
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EA7FC: .4byte 0x030001BC
