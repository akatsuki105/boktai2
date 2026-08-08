	push {lr}
	ldr r0, _0822E8A8 @ =0x03000724
	ldr r0, [r0]
	cmp r0, #0
	beq _0822E8AC
	ldr r0, [r0, #8]
	b _0822E8AE
	.align 2, 0
_0822E8A8: .4byte 0x03000724
_0822E8AC:
	movs r0, #0
_0822E8AE:
	pop {r1}
	bx r1
	.align 2, 0
