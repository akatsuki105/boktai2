	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl MsgQueue_Unregister
	ldr r2, _082059D4 @ =0x03002C90
	movs r1, #0
	str r1, [r2]
	pop {r1}
	bx r1
	.align 2, 0
_082059D4: .4byte 0x03002C90
