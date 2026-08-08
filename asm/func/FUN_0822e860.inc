	push {lr}
	ldr r0, _0822E870 @ =0x03000724
	ldr r0, [r0]
	cmp r0, #0
	beq _0822E874
	ldrh r0, [r0, #2]
	b _0822E876
	.align 2, 0
_0822E870: .4byte 0x03000724
_0822E874:
	movs r0, #0
_0822E876:
	pop {r1}
	bx r1
	.align 2, 0
