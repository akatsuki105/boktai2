	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldr r2, _080D21F4 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D21F8
	asrs r1, r0, #0xc
	b _080D21FE
	.align 2, 0
_080D21F4: .4byte gSineTable
_080D21F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D21FE:
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r4, #2]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D221E
	asrs r1, r0, #0xc
	b _080D2224
_080D221E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2224:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
