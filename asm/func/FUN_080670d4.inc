	push {lr}
	adds r1, r0, #0
	cmp r1, #0xc
	bne _080670E0
	movs r0, #0x40
	b _080670F6
_080670E0:
	cmp r1, #0xb
	ble _080670EE
	subs r1, #0xc
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	b _080670F6
_080670EE:
	movs r0, #0xc
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x40
_080670F6:
	pop {r1}
	bx r1
	.align 2, 0
