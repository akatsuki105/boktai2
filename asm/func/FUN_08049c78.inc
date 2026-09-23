	push {r4, lr}
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _08049C98
	bl FUN_08049e5c
	ldr r1, _08049C94 @ =0x03003520
	movs r0, #0
	str r0, [r1]
	strb r0, [r4]
	b _08049C9C
	.align 2, 0
_08049C94: .4byte 0x03003520
_08049C98:
	movs r0, #1
	rsbs r0, r0, #0
_08049C9C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
