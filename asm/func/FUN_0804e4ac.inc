	push {lr}
	ldr r0, _0804E4C0 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E4BA
	movs r0, #1
	strb r0, [r1, #0x1b]
_0804E4BA:
	pop {r0}
	bx r0
	.align 2, 0
_0804E4C0: .4byte 0x03002B58
