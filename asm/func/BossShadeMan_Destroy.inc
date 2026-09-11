	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013c70
	adds r0, r4, #0
	bl FUN_0803c264
	adds r0, r4, #0
	bl FUN_0803c76c
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	adds r0, r4, #0
	bl FUN_08022b04
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
