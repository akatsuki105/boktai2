	push {lr}
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _080F8AD6
	cmp r0, #1
	ble _080F8ADA
	cmp r0, #3
	beq _080F8AD6
	cmp r0, #5
	bne _080F8ADA
_080F8AD6:
	movs r0, #3
	b _080F8ADC
_080F8ADA:
	movs r0, #4
_080F8ADC:
	pop {r1}
	bx r1
