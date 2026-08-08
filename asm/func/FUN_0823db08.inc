	push {r4, r5, r6, lr}
	lsrs r4, r3, #0x1c
	lsls r6, r4, #5
	subs r6, r6, r4
	lsls r6, r6, #2
	adds r6, r6, r4
	lsls r6, r6, #3
	movs r4, #0xf0
	lsls r4, r4, #0x14
	ands r4, r3
	asrs r4, r4, #0x18
	movs r5, #0x64
	muls r4, r5, r4
	adds r6, r6, r4
	movs r5, #0xf0
	lsls r5, r5, #0x10
	ands r5, r3
	asrs r5, r5, #0x14
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #1
	adds r6, r6, r4
	movs r4, #0xf0
	lsls r4, r4, #0xc
	ands r4, r3
	asrs r4, r4, #0x10
	adds r6, r6, r4
	str r6, [r0]
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r3
	asrs r0, r0, #0xc
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #1
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r0, r3
	asrs r0, r0, #8
	adds r4, r4, r0
	str r4, [r1]
	movs r1, #0xf0
	ands r1, r3
	asrs r1, r1, #4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xf
	ands r1, r3
	adds r0, r0, r1
	str r0, [r2]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
