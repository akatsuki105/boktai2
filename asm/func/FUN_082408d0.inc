	push {r4, lr}
	ldr r4, _082408F0 @ =0x03004820
	ldrh r0, [r4, #0x3a]
	cmp r0, #0
	beq _082408DE
	bl m4aSongNumStop
_082408DE:
	ldrh r0, [r4, #0x3c]
	cmp r0, #0
	beq _082408E8
	bl m4aSongNumStop
_082408E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082408F0: .4byte 0x03004820
