	push {lr}
	adds r1, r0, #0
	movs r2, #8
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _08094E84
	ldrh r0, [r1, #6]
	lsls r0, r0, #2
	movs r1, #0xc8
	b _08094E9C
_08094E84:
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	bne _08094E94
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _08094EAA
_08094E94:
	ldrh r0, [r1, #6]
	lsls r0, r0, #2
	movs r1, #0xfa
	lsls r1, r1, #3
_08094E9C:
	bl Div
	cmp r0, #3
	ble _08094EA6
	movs r0, #3
_08094EA6:
	adds r0, #0xd0
	b _08094EAC
_08094EAA:
	movs r0, #0xcf
_08094EAC:
	pop {r1}
	bx r1
