	push {lr}
	ldr r0, _0822E854 @ =0x03000724
	ldr r0, [r0]
	cmp r0, #0
	beq _0822E858
	ldrh r0, [r0]
	b _0822E85A
	.align 2, 0
_0822E854: .4byte 0x03000724
_0822E858:
	movs r0, #0
_0822E85A:
	pop {r1}
	bx r1
	.align 2, 0
