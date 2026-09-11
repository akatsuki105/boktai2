	push {lr}
	movs r2, #0
	adds r1, r0, #0
	adds r1, #0x2c
_08009B18:
	ldrb r0, [r1, #5]
	cmp r0, #0
	bne _08009B22
	adds r0, r1, #0
	b _08009B2C
_08009B22:
	adds r1, #0x9c
	adds r2, #1
	cmp r2, #0xf
	ble _08009B18
	movs r0, #0
_08009B2C:
	pop {r1}
	bx r1
