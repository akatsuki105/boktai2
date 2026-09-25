	push {r4, r5, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_080dd4fc
	adds r0, r4, #0
	bl FUN_080dd6f4
	adds r5, r4, #0
	adds r5, #0x58
	ldrh r0, [r5]
	subs r0, #0xa
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _080DD842
	adds r0, r4, #0
	bl Hitbox_Register
_080DD842:
	ldrh r0, [r5]
	cmp r0, #0x28
	bls _080DD852
	adds r1, r4, #0
	adds r1, #0x5d
	movs r0, #2
	strb r0, [r1]
	b _080DD856
_080DD852:
	adds r0, #1
	strh r0, [r5]
_080DD856:
	pop {r4, r5}
	pop {r0}
	bx r0
