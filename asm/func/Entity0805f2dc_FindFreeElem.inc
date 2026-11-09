	push {lr}
	adds r1, r0, #0
	adds r1, #0x54
	movs r2, #0
_0805F2C4:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0805F2CE
	adds r0, r1, #0
	b _0805F2D8
_0805F2CE:
	adds r2, #1
	adds r1, #0x94
	cmp r2, #0xb
	ble _0805F2C4
	movs r0, #0
_0805F2D8:
	pop {r1}
	bx r1
