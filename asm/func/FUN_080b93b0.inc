	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r4, [sp, #0x14]
	movs r0, #0
	bl GetBgTilemapAddr
	adds r7, r0, #0
	lsls r4, r4, #4
	adds r4, #0x21
	cmp r6, #0
	ble _080B93F8
_080B93CC:
	adds r0, r5, #0
	adds r1, r6, #0
	bl Div
	adds r1, r0, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r7]
	adds r7, #2
	muls r0, r6, r0
	subs r5, r5, r0
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	adds r6, r0, #0
	cmp r6, #0
	bgt _080B93CC
_080B93F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
