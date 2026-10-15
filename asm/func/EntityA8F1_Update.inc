	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080a3448
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r5, #0
_080A34EC:
	movs r0, #0x34
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A350A
	subs r2, #0x28
	adds r0, r1, r2
	adds r0, r4, r0
	bl FUN_080a251c
_080A350A:
	adds r5, #1
	cmp r5, #7
	ble _080A34EC
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
