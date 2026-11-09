	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x54
	movs r4, #0
_0805EE02:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity0805ee80_RemoveElem
	adds r4, #1
	adds r5, #0x4c
	cmp r4, #7
	ble _0805EE02
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
