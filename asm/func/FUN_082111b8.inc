	push {lr}
	bl FUN_08211120
	movs r1, #0
	cmp r0, #0x1a
	ble _082111C6
	movs r1, #1
_082111C6:
	adds r0, r1, #0
	pop {r1}
	bx r1
