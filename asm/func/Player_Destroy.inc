	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080f8cac
	adds r0, r4, #0
	adds r0, #0x88
	bl FUN_0822f1c0
	adds r0, r4, #0
	adds r0, #0xe8
	bl FUN_0822a4e0
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0823b284
	adds r0, r4, #0
	bl FUN_08063b24
	adds r0, r4, #0
	bl FUN_0807ddd4
	adds r0, r4, #0
	bl FUN_08060c60
	ldr r0, _0807F39C @ =0x03002BA8
	movs r1, #0
	str r1, [r0]
	ldr r0, _0807F3A0 @ =0x03002BF4
	strh r1, [r0]
	ldr r2, _0807F3A4 @ =0x03002BE0
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	str r1, [r0]
	ldr r1, _0807F3A8 @ =0x03002B98
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0807F39C: .4byte 0x03002BA8
_0807F3A0: .4byte 0x03002BF4
_0807F3A4: .4byte 0x03002BE0
_0807F3A8: .4byte 0x03002B98
