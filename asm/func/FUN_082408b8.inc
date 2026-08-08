	push {lr}
	ldr r1, _082408CC @ =0x03004820
	ldrh r0, [r1, #0x3c]
	cmp r0, #0
	beq _082408C6
	bl sound_08240740
_082408C6:
	pop {r0}
	bx r0
	.align 2, 0
_082408CC: .4byte 0x03004820
