	push {lr}
	movs r2, #1
	movs r3, #0x88
	lsls r3, r3, #2
	adds r1, r0, r3
	subs r3, #0xfc
_081F6464:
	lsls r0, r2, #5
	strb r0, [r1]
	adds r1, r1, r3
	adds r2, #1
	cmp r2, #5
	ble _081F6464
	pop {r0}
	bx r0
