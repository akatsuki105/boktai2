	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x38
	bl FUN_0822f1c0
	adds r0, r4, #0
	adds r0, #0x98
	bl FUN_0822f1c0
	adds r0, r4, #0
	adds r0, #0xf8
	bl FUN_0822f1c0
	pop {r4}
	pop {r0}
	bx r0
