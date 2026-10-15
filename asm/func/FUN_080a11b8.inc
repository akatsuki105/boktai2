	push {lr}
	ldr r0, _080A11D0 @ =0x03000148
	ldr r1, [r0]
	cmp r1, #0
	beq _080A11CC
	movs r0, #0
	strh r0, [r1, #0x1a]
	strh r0, [r1, #0x2a]
	strh r0, [r1, #0x26]
	strh r0, [r1, #0x2c]
_080A11CC:
	pop {r0}
	bx r0
	.align 2, 0
_080A11D0: .4byte 0x03000148
