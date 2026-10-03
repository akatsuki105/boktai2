	push {lr}
	ldr r0, _0804E484 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E488
	ldrb r0, [r0, #0x19]
	b _0804E48A
	.align 2, 0
_0804E484: .4byte 0x03002B58
_0804E488:
	movs r0, #0
_0804E48A:
	pop {r1}
	bx r1
	.align 2, 0
