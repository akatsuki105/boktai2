	push {lr}
	ldr r1, _0824092C @ =0x03004820
	ldrh r0, [r1, #0x3c]
	cmp r0, #0
	beq _08240926
	bl m4aSongNumStop
_08240926:
	pop {r0}
	bx r0
	.align 2, 0
_0824092C: .4byte 0x03004820
