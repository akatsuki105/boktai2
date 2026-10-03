	push {lr}
	ldr r0, _0804BA58 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	bne _0804BA5C
	movs r0, #0
	b _0804BA5E
	.align 2, 0
_0804BA58: .4byte 0x03002B58
_0804BA5C:
	movs r0, #1
_0804BA5E:
	pop {r1}
	bx r1
	.align 2, 0
