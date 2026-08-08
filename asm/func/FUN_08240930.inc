	push {lr}
	ldr r1, _08240944 @ =0x03004820
	ldrh r0, [r1, #0x3c]
	cmp r0, #0
	beq _0824093E
	bl m4aSongNumStart
_0824093E:
	pop {r0}
	bx r0
	.align 2, 0
_08240944: .4byte 0x03004820
