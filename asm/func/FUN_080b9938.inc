	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _080B995C
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r3]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	b _080B999A
_080B995C:
	cmp r2, #0x1f
	bgt _080B997C
	subs r2, #0x10
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r3]
	asrs r2, r2, #2
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, #0x20
	b _080B999A
_080B997C:
	cmp r2, #0x20
	bne _080B9988
	movs r0, #0x70
	strh r0, [r3]
	movs r0, #0x40
	b _080B999A
_080B9988:
	cmp r2, #0x21
	bne _080B9994
	movs r0, #0x78
	strh r0, [r3]
	movs r0, #0x68
	b _080B999A
_080B9994:
	movs r0, #0x68
	strh r0, [r3]
	movs r0, #0x20
_080B999A:
	strh r0, [r3, #2]
	pop {r0}
	bx r0
