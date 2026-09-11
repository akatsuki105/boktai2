	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080277E8 @ =0x000004D4
	adds r0, r4, r1
	bl FUN_08013c70
	adds r0, r4, #0
	bl FUN_080234dc
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	adds r0, r4, #0
	bl FUN_08023ba0
	adds r0, r4, #0
	bl FUN_08022b04
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080277E8: .4byte 0x000004D4
