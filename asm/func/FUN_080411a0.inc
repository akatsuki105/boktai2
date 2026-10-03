	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _080411B2
	movs r0, #1
	rsbs r0, r0, #0
	b _080411D2
_080411B2:
	movs r6, #0
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r4, r5, r0
_080411BA:
	ldr r2, [r4]
	cmp r2, #0
	beq _080411C8
	adds r0, r7, #0
	adds r1, r5, #0
	bl _call_via_r2
_080411C8:
	adds r4, #4
	adds r6, #1
	cmp r6, #3
	ble _080411BA
	movs r0, #0
_080411D2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
