	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x18
	movs r5, #0
_080111AE:
	ldr r0, [r6, #0x74]
	ldrb r1, [r4]
	ldrb r2, [r4, #1]
	bl FUN_08011178
	adds r1, r0, #0
	cmp r1, #0x3f
	bls _080111C4
	movs r0, #1
	rsbs r0, r0, #0
	b _080111D2
_080111C4:
	adds r0, r6, r5
	strb r1, [r0]
	adds r5, #1
	adds r4, #2
	cmp r5, #0x17
	ble _080111AE
	movs r0, #0
_080111D2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
