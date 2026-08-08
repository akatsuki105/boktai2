	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0821b06c
	ldr r1, _0821B104 @ =0x03002C98
	adds r4, #0xf4
	ldr r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0821B104: .4byte 0x03002C98
