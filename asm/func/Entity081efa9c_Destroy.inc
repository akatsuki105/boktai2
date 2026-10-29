	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r0, _081EFA58 @ =0x00000838
	adds r6, r5, r0
_081EFA46:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081EFA5C
	movs r0, #1
	b _081EFA5E
	.align 2, 0
_081EFA58: .4byte 0x00000838
_081EFA5C:
	movs r0, #0
_081EFA5E:
	cmp r0, #0
	beq _081EFA6E
	movs r0, #0xd0
	muls r0, r4, r0
	adds r0, #0x18
	adds r0, r5, r0
	bl AuxSprite_Remove
_081EFA6E:
	adds r4, #1
	cmp r4, #9
	ble _081EFA46
	ldr r1, _081EFA80 @ =0x030001DC
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EFA80: .4byte 0x030001DC
