	push {r4, lr}
	movs r4, #0
_08091C7C:
	adds r0, r4, #0
	movs r1, #0
	bl SetRotCount2
	adds r4, #1
	cmp r4, #0xf
	ble _08091C7C
	pop {r4}
	pop {r0}
	bx r0
