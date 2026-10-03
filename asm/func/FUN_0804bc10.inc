	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	bne _0804BC1E
	movs r0, #0
	b _0804BC24
_0804BC1E:
	movs r0, #0
	strb r0, [r1, #0x1c]
	movs r0, #1
_0804BC24:
	pop {r1}
	bx r1
