	adds r1, r0, #0
	b _080EAFC6
	.align 2, 0
_080EAFB8: .4byte 0x030046A0
_080EAFBC: .4byte 0x0000270F
_080EAFC0:
	cmp r1, #0
	bge _080EAFC6
	movs r1, #0
_080EAFC6:
	ldr r2, _080EAFD8 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8c
	lsls r2, r2, #2
_080EAFCE:
	adds r0, r0, r2
	strh r1, [r0]
_080EAFD2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080EAFD8: .4byte 0x030046A0
