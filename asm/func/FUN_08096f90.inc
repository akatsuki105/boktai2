	push {lr}
	adds r1, r0, #0
	ldr r2, _08096FA4 @ =0x00001444
	adds r0, r1, r2
	adds r1, #0x60
	bl MainSprite_AdvanceAnim
	pop {r0}
	bx r0
	.align 2, 0
_08096FA4: .4byte 0x00001444
