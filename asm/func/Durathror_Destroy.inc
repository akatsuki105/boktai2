	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xd7
	lsls r1, r1, #4
	adds r0, r4, r1
	bl FUN_08013c70
	adds r0, r4, #0
	bl FUN_08038a60
	adds r0, r4, #0
	bl FUN_08036848
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0x9d
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _0803BA00 @ =0x00000E14
	adds r0, r4, r1
	bl FUN_0807f598
	adds r0, r4, #0
	bl FUN_08022b04
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0803BA00: .4byte 0x00000E14
