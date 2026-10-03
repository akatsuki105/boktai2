	push {r4, lr}
	adds r4, r0, #0
	adds r0, r2, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r1, #0
	cmp r0, r3
	bne _08235970
	movs r0, #0
	b _08235994
_08235970:
	cmp r0, r3
	bgt _0823597E
	muls r1, r0, r1
	adds r1, r1, r3
	adds r2, r0, #2
	adds r0, #1
	b _08235988
_0823597E:
	adds r1, r3, #0
	muls r1, r2, r1
	adds r1, r1, r0
	adds r2, r3, #2
	adds r0, r3, #1
_08235988:
	muls r0, r2, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
_08235994:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
