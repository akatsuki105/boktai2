	push {r4, lr}
	adds r3, r0, #0
	movs r4, #0
	adds r2, r3, #0
	adds r2, #0xd
	ldrb r0, [r3, #9]
	cmp r0, #1
	ble _08238246
	subs r1, r0, #1
_0823823A:
	ldrb r0, [r2]
	eors r4, r0
	adds r2, #1
	subs r1, #1
	cmp r1, #0
	bne _0823823A
_08238246:
	strb r4, [r3, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
