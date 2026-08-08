	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x48
	bl FUN_0822f1c0
	adds r0, r6, #0
	adds r0, #0xa8
	bl FUN_0822f1c0
	movs r0, #0x84
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r4, #4
_08210EBA:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08210EBA
	movs r1, #0x91
	lsls r1, r1, #3
	adds r5, r6, r1
	movs r4, #0x13
_08210ED0:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08210ED0
	movs r0, #0xba
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r4, #1
_08210EE6:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08210EE6
	ldr r1, _08210F34 @ =0x00000C8C
	adds r0, r6, r1
	bl FUN_0822a4e0
	movs r1, #0xea
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_0822f1c0
	movs r1, #0x81
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_0822f1c0
	ldr r1, _08210F38 @ =0x00000CD4
	adds r0, r6, r1
	bl FUN_08055d7c
	ldr r1, _08210F3C @ =0x00000C08
	adds r0, r6, r1
	bl FUN_0822f1c0
	movs r0, #0
	movs r1, #0
	bl FUN_0822ba00
	bl FUN_08049fa8
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08210F34: .4byte 0x00000C8C
_08210F38: .4byte 0x00000CD4
_08210F3C: .4byte 0x00000C08
