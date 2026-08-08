	push {r4, lr}
	adds r3, r0, #0
	lsls r3, r3, #0x10
	movs r4, #0xf
	movs r0, #0xf0
	lsls r0, r0, #0xc
	ands r0, r3
	lsrs r0, r0, #0x10
	lsrs r2, r3, #0x14
	ands r2, r4
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	lsrs r1, r3, #0x18
	ands r1, r4
	movs r2, #0x64
	muls r1, r2, r1
	adds r0, r0, r1
	lsrs r3, r3, #0x1c
	ands r3, r4
	lsls r1, r3, #5
	subs r1, r1, r3
	lsls r1, r1, #2
	adds r1, r1, r3
	lsls r1, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
