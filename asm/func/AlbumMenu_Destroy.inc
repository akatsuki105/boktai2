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
_082119EA:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _082119EA
	movs r1, #0xba
	lsls r1, r1, #2
	adds r5, r6, r1
	movs r4, #1
_08211A00:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08211A00
	movs r0, #0x91
	lsls r0, r0, #3
	adds r5, r6, r0
	movs r4, #9
_08211A16:
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08211A16
	movs r1, #0xea
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_0822f1c0
	movs r1, #0x81
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_0822f1c0
	ldr r1, _08211A58 @ =0x0000086C
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0804a210
	bl FUN_08049fa8
	movs r0, #0
	movs r1, #0
	bl SetBGPrioDirect
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08211A58: .4byte 0x0000086C
