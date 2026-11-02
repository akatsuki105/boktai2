	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	movs r7, #0x91
	movs r0, #0
	bl Entity501B_GetBgMapAddr
	adds r6, r0, #0
	cmp r5, #0
	ble _081DFFFC
_081DFFD0:
	adds r0, r4, #0
	adds r1, r5, #0
	bl Div
	adds r1, r0, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r6]
	adds r6, #2
	muls r0, r5, r0
	subs r4, r4, r0
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	cmp r5, #0
	bgt _081DFFD0
_081DFFFC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
