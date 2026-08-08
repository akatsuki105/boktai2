	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _0821C948 @ =0x00000B54
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r0, _0821C94C @ =0x00000814
	adds r4, r4, r0
	movs r5, #7
_0821C934:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x64
	subs r5, #1
	cmp r5, #0
	bge _0821C934
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0821C948: .4byte 0x00000B54
_0821C94C: .4byte 0x00000814
