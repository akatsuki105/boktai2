	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08216A84 @ =0x0000166C
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _08216A88 @ =0x000016CC
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r0, _08216A8C @ =0x0000172C
	adds r4, r4, r0
	adds r0, r4, #0
	bl FUN_0822f1c0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08216A84: .4byte 0x0000166C
_08216A88: .4byte 0x000016CC
_08216A8C: .4byte 0x0000172C
