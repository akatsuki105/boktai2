	push {lr}
	adds r0, #0x38
	bl AuxSprite_Remove
	ldr r2, _08055AA8 @ =0x03000124
	movs r1, #0
	str r1, [r2]
	pop {r1}
	bx r1
	.align 2, 0
_08055AA8: .4byte 0x03000124
