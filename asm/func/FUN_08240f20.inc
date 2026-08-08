	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0x10
	movs r3, #0
	adds r0, #0x98
_08240F2A:
	ldr r2, [r0]
	cmp r2, r4
	bne _08240F34
	adds r0, r3, #0
	b _08240F44
_08240F34:
	cmp r2, #0
	bne _08240F3A
	adds r1, r3, #0
_08240F3A:
	adds r0, #4
	adds r3, #1
	cmp r3, #0xf
	ble _08240F2A
	rsbs r0, r1, #0
_08240F44:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
