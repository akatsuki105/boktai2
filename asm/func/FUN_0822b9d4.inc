	push {r4, r5, lr}
	ldr r5, _0822B9F4 @ =0x03003E60
	lsls r4, r0, #2
	adds r4, r4, r5
	str r1, [r4]
	ldr r1, _0822B9F8 @ =0x03003E80
	lsls r0, r0, #1
	adds r1, r0, r1
	strh r3, [r1]
	ldr r1, _0822B9FC @ =0x03003EA8
	adds r0, r0, r1
	strh r2, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0822B9F4: .4byte 0x03003E60
_0822B9F8: .4byte 0x03003E80
_0822B9FC: .4byte 0x03003EA8
