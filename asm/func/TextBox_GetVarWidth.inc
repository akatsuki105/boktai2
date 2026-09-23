	push {lr}
	adds r1, r0, #0
	ldr r0, _080488B0 @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _080488B4
	adds r0, #0x18
	bl TextRenderer_GetVarWidth
	b _080488B6
	.align 2, 0
_080488B0: .4byte 0x030000C4
_080488B4:
	movs r0, #0
_080488B6:
	pop {r1}
	bx r1
	.align 2, 0
