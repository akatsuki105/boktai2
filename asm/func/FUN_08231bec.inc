	push {lr}
	bl FUN_08231770
	bl FUN_08231c80
	bl FUN_08231780
	bl FUN_082324b0
	ldr r0, _08231C14 @ =0x0000A8D9
	ldr r1, _08231C18 @ =0x0000A41E
	bl FUN_082310cc
	bl FUN_082319a8
	movs r0, #0
	bl FUN_08231be0
	pop {r0}
	bx r0
	.align 2, 0
_08231C14: .4byte 0x0000A8D9
_08231C18: .4byte 0x0000A41E
