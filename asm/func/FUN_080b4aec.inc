	ldr r3, _080B4AFC @ =0x0000084C
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080B4B00 @ =0x00000844
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080B4AFC: .4byte 0x0000084C
_080B4B00: .4byte 0x00000844
