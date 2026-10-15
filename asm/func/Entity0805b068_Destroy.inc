	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0805B00A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805a6c8
	adds r4, #1
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #7
	ble _0805B00A
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
