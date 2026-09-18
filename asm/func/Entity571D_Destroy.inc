	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x78
	movs r5, #0x25
_080BF966:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BF966
	ldr r1, _080BF990 @ =0x00000EDC
	adds r0, r6, r1
	bl FUN_080b9a0c
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r6, r1
	bl FUN_080b9894
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BF990: .4byte 0x00000EDC
