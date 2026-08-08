	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #0xb
_08214254:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _08214254
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_0822f1c0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
