	push {lr}
	ldr r0, _080A0804 @ =0x03002C3C
	ldr r1, [r0]
	cmp r1, #0
	beq _080A07FE
	movs r0, #0
	strb r0, [r1, #0x1f]
_080A07FE:
	pop {r0}
	bx r0
	.align 2, 0
_080A0804: .4byte 0x03002C3C
