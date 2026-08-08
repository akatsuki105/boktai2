	adds r1, r0, #0
	ldr r0, _08231D90 @ =0x030046A0
	ldr r0, [r0]
	subs r1, r1, r0
	ldr r0, _08231D94 @ =0x0300469C
	ldr r0, [r0]
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08231D90: .4byte 0x030046A0
_08231D94: .4byte 0x0300469C
