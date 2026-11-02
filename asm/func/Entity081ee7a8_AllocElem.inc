	push {lr}
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0x88
	adds r2, r0, #0
	adds r2, #0x1c
_081EE308:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _081EE316
	strb r3, [r1]
	adds r0, r2, #0
	b _081EE322
_081EE316:
	adds r1, #0x70
	adds r2, #0x70
	adds r3, #1
	cmp r3, #0x2f
	ble _081EE308
	movs r0, #0
_081EE322:
	pop {r1}
	bx r1
	.align 2, 0
