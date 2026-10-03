	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xb4
	ldrh r0, [r3]
	lsrs r0, r0, #3
	adds r1, r2, #0
	adds r1, #0x6c
	strh r0, [r1, #0x10]
	adds r0, r2, #0
	adds r0, #0xb6
	ldrh r0, [r0]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080BFB9E
	movs r0, #0
	strh r0, [r3]
_080BFB9E:
	pop {r0}
	bx r0
	.align 2, 0
