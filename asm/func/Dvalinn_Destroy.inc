	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	adds r0, r4, #0
	bl FUN_08022b04
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822a4e0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
