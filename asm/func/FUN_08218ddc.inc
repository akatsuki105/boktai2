	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _08218E34 @ =0x000012E8
	adds r0, r6, r1
	bl FUN_0822f1c0
	ldr r1, _08218E38 @ =0x00001348
	adds r0, r6, r1
	bl FUN_0822f1c0
	ldr r0, _08218E3C @ =0x000013A8
	adds r4, r6, r0
	movs r5, #4
_08218DF6:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _08218DF6
	ldr r1, _08218E40 @ =0x00001588
	adds r4, r6, r1
	movs r5, #1
_08218E0A:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _08218E0A
	ldr r1, _08218E44 @ =0x00001648
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0804a16c
	ldr r1, _08218E48 @ =0x0000164C
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0804a16c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08218E34: .4byte 0x000012E8
_08218E38: .4byte 0x00001348
_08218E3C: .4byte 0x000013A8
_08218E40: .4byte 0x00001588
_08218E44: .4byte 0x00001648
_08218E48: .4byte 0x0000164C
