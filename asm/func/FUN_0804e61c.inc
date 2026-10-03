	push {lr}
	ldr r0, _0804E62C @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E630
	adds r0, #0x50
	b _0804E632
	.align 2, 0
_0804E62C: .4byte 0x03002B58
_0804E630:
	movs r0, #0
_0804E632:
	pop {r1}
	bx r1
	.align 2, 0
