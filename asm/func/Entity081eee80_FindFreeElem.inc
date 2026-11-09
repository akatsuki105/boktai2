	push {r4, lr}
	movs r3, #0
	movs r4, #1
	adds r1, r0, #0
	adds r1, #0x76
	adds r2, r0, #0
	adds r2, #0x38
_081EEC52:
	ldrb r0, [r1, #1]
	cmp r0, #1
	beq _081EEC60
	strb r3, [r1]
	strb r4, [r1, #1]
	adds r0, r2, #0
	b _081EEC6C
_081EEC60:
	adds r1, #0x40
	adds r2, #0x40
	adds r3, #1
	cmp r3, #0x7f
	ble _081EEC52
	movs r0, #0
_081EEC6C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
