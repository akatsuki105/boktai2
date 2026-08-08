	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0822f1c0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
