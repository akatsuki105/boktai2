	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x98
	bl FUN_0822f1c0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a16c
	pop {r4}
	pop {r0}
	bx r0
