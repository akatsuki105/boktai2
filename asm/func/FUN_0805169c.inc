	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080516EE
	movs r1, #0
	strb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x2c
	strb r1, [r0]
	movs r5, #0
	movs r6, #0
	adds r2, r4, #0
	adds r2, #0xec
_080516B8:
	movs r1, #3
	ands r1, r5
	cmp r5, #3
	bgt _080516C6
	strb r1, [r2, #2]
	strb r6, [r2, #3]
	b _080516E6
_080516C6:
	adds r0, r4, #0
	adds r0, #0x24
	adds r0, r0, r1
	adds r3, r2, #0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2, #2]
	cmp r0, #0xa
	ble _080516DE
	movs r0, #0xa
	b _080516E4
_080516DE:
	cmp r0, #0
	bge _080516E4
	movs r0, #0
_080516E4:
	strb r0, [r3, #3]
_080516E6:
	adds r2, #0x7c
	adds r5, #1
	cmp r5, #7
	ble _080516B8
_080516EE:
	adds r0, r4, #0
	movs r1, #4
	bl Entity08051b70_LaunchNext
	ldr r0, [r4, #0x18]
	cmp r0, #0x4f
	bls _08051704
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08050e9c
_08051704:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
