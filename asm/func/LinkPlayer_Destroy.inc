	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x88
	bl FUN_0822f1c0
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0823b284
	adds r0, r4, #0
	bl FUN_0808168c
	ldr r1, _08084620 @ =0x000009C8
	adds r0, r4, r1
	bl FUN_0822a4e0
	ldr r1, _08084624 @ =0x03002BE0
	adds r4, #0x28
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	ldr r1, _08084628 @ =0x03002B98
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08084620: .4byte 0x000009C8
_08084624: .4byte 0x03002BE0
_08084628: .4byte 0x03002B98
