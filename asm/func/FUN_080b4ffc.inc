	push {lr}
	asrs r0, r0, #2
	cmp r0, #1
	beq _080B5016
	cmp r0, #1
	ble _080B501A
	cmp r0, #2
	beq _080B5012
	cmp r0, #3
	beq _080B5016
	b _080B501A
_080B5012:
	movs r0, #2
	b _080B501C
_080B5016:
	movs r0, #1
	b _080B501C
_080B501A:
	movs r0, #0
_080B501C:
	pop {r1}
	bx r1
