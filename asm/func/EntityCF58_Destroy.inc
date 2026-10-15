	push {lr}
	adds r0, #0x38
	bl MainSprite_Remove
	ldr r1, _080A6044 @ =0x0300014C
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_080A6044: .4byte 0x0300014C
