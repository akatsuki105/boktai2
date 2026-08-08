	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08231D78 @ =0x030046A0
	ldr r1, [r0]
	subs r1, r3, r1
	ldr r0, _08231D7C @ =0x0300469C
	ldr r0, [r0]
	adds r0, r0, r1
	adds r1, r3, #0
	bl FUN_08230ab0
	pop {r0}
	bx r0
	.align 2, 0
_08231D78: .4byte 0x030046A0
_08231D7C: .4byte 0x0300469C
