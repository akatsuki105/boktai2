	push {lr}
	ldr r0, _0804E4D8 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E4D2
	movs r0, #1
	strb r0, [r1, #0x1c]
_0804E4D2:
	pop {r0}
	bx r0
	.align 2, 0
_0804E4D8: .4byte 0x03002B58
