	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl Mod
	adds r5, r0, #0
	adds r0, r4, #0
	movs r1, #0x64
	bl Mod
	subs r0, r0, r5
	movs r1, #0xa
	bl Div
	lsls r0, r0, #4
	orrs r0, r5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
