	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd8
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r0, _082151D4 @ =0x00000D98
	adds r5, r4, r0
	movs r4, #4
_082151C2:
	ldm r5!, {r0}
	bl FUN_0804a16c
	subs r4, #1
	cmp r4, #0
	bge _082151C2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082151D4: .4byte 0x00000D98
