	push {r4, lr}
	movs r3, #0
	ldrb r1, [r0, #0x1e]
	cmp r3, r1
	bge _080B2496
	ldr r4, _080B24A0 @ =0x00000BE8
	adds r2, r0, r4
_080B2482:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B248E
	adds r3, #1
_080B248E:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B2482
_080B2496:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B24A0: .4byte 0x00000BE8
