	push {r4, lr}
	ldr r4, _08240914 @ =0x03004820
	ldrh r0, [r4, #0x3a]
	cmp r0, #0
	beq _08240902
	bl m4aSongNumStart
_08240902:
	ldrh r0, [r4, #0x3c]
	cmp r0, #0
	beq _0824090C
	bl m4aSongNumStart
_0824090C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08240914: .4byte 0x03004820
