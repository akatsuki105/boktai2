	push {r4, lr}
	ldr r4, _08240A1C @ =0x030016FC
	ldr r0, [r4]
	bl Free
	movs r0, #0
	str r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08240A1C: .4byte 0x030016FC
