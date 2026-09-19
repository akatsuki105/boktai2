	push {lr}
	adds r3, r0, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _080CC1CC
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _080CC1C4 @ =0x000002E6
	adds r1, r3, r2
	strb r0, [r1]
	ldr r0, _080CC1C8 @ =0x000002E7
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	b _080CC1DA
	.align 2, 0
_080CC1C4: .4byte 0x000002E6
_080CC1C8: .4byte 0x000002E7
_080CC1CC:
	ldr r1, _080CC1E0 @ =0x000002E6
	adds r0, r3, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _080CC1E4 @ =0x000002E7
	adds r0, r3, r2
	strb r1, [r0]
_080CC1DA:
	pop {r0}
	bx r0
	.align 2, 0
_080CC1E0: .4byte 0x000002E6
_080CC1E4: .4byte 0x000002E7
