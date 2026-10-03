	push {lr}
	adds r1, r0, #0
	ldr r0, _0804E598 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E594
	adds r0, #0x33
	strb r1, [r0]
_0804E594:
	pop {r0}
	bx r0
	.align 2, 0
_0804E598: .4byte 0x03002B58
