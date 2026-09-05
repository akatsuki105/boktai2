	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0xec
	movs r5, #1
_08050852:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _08050852
	movs r4, #0
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	bl FUN_0804a16c
	ldr r0, _08050878 @ =0x030000F0
	str r4, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08050878: .4byte 0x030000F0
