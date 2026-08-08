	ldr r1, _080FF468 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _080FF46C @ =0x085AD490
	str r1, [r0]
	bx lr
	.align 2, 0
_080FF468: .4byte 0x00000634
_080FF46C: .4byte 0x085AD490
