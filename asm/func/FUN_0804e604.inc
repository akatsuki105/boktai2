	push {lr}
	ldr r0, _0804E618 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E612
	movs r0, #1
	strb r0, [r1, #0x1d]
_0804E612:
	pop {r0}
	bx r0
	.align 2, 0
_0804E618: .4byte 0x03002B58
