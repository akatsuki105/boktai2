	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _08215F84 @ =0x00000E8C
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _08215F88 @ =0x00000EEC
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r0, _08215F8C @ =0x0000118C
	adds r6, r4, r0
	ldr r1, _08215F90 @ =0x0000106C
	adds r5, r4, r1
	ldr r0, _08215F94 @ =0x00000F4C
	adds r4, r4, r0
	movs r7, #2
_08215F5E:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r0, r5, #0
	bl FUN_0822f1c0
	adds r0, r6, #0
	bl FUN_0822f1c0
	adds r6, #0x60
	adds r5, #0x60
	adds r4, #0x60
	subs r7, #1
	cmp r7, #0
	bge _08215F5E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08215F84: .4byte 0x00000E8C
_08215F88: .4byte 0x00000EEC
_08215F8C: .4byte 0x0000118C
_08215F90: .4byte 0x0000106C
_08215F94: .4byte 0x00000F4C
