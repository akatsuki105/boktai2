	push {lr}
	adds r1, r0, #0
	adds r1, #0x54
	movs r2, #0
_0805EECC:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0805EED6
	adds r0, r1, #0
	b _0805EEE0
_0805EED6:
	adds r2, #1
	adds r1, #0x4c
	cmp r2, #7
	ble _0805EECC
	movs r0, #0
_0805EEE0:
	pop {r1}
	bx r1
