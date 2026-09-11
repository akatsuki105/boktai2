	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013c70
	adds r0, r4, #0
	bl FUN_08028054
	adds r0, r4, #0
	bl FUN_08028818
	adds r0, r4, #0
	bl FUN_08028eb8
	adds r0, r4, #0
	bl FUN_08029de0
	adds r0, r4, #0
	bl FUN_0802a2e0
	adds r0, r4, #0
	bl FUN_08029b30
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	adds r0, r4, #0
	bl FUN_08022b04
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
