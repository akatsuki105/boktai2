	push {lr}
	adds r1, r0, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x81
	bls _080AD51C
	movs r0, #0
	strh r0, [r1]
_080AD51C:
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _080AD526
	movs r0, #0
	b _080AD540
_080AD526:
	cmp r0, #0x27
	bls _080AD53A
	cmp r0, #0x31
	bls _080AD53E
	cmp r0, #0x6d
	bhi _080AD536
	movs r0, #3
	b _080AD540
_080AD536:
	cmp r0, #0x77
	bls _080AD53E
_080AD53A:
	movs r0, #1
	b _080AD540
_080AD53E:
	movs r0, #2
_080AD540:
	pop {r1}
	bx r1
