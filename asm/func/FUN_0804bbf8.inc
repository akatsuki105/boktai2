	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x1b]
	cmp r0, #0
	bne _0804BC06
	movs r0, #0
	b _0804BC0C
_0804BC06:
	movs r0, #0
	strb r0, [r1, #0x1b]
	movs r0, #1
_0804BC0C:
	pop {r1}
	bx r1
