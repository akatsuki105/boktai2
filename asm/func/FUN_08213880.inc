	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08213898 @ =0x0000C091
	ldr r1, _0821389C @ =0x0000A413
	bl FUN_082310cc
	adds r4, #0xf8
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08213898: .4byte 0x0000C091
_0821389C: .4byte 0x0000A413
