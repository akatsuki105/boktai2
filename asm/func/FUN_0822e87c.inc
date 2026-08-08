	push {lr}
	ldr r0, _0822E88C @ =0x03000724
	ldr r0, [r0]
	cmp r0, #0
	beq _0822E890
	ldr r0, [r0, #4]
	b _0822E892
	.align 2, 0
_0822E88C: .4byte 0x03000724
_0822E890:
	movs r0, #0
_0822E892:
	pop {r1}
	bx r1
	.align 2, 0
