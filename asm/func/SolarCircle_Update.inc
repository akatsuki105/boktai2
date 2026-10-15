	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
_080A2196:
	movs r0, #0x34
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	adds r0, #0xf0
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A21B6
	adds r0, r1, #0
	adds r0, #0xc0
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r1, [r1]
	bl FUN_080a1e28
_080A21B6:
	adds r5, #1
	cmp r5, #7
	ble _080A2196
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
