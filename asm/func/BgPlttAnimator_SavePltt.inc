	push {lr}
	adds r1, r0, #0
	ldr r0, _0801B5B4 @ =0x03004250
	adds r1, #0x20
	ldr r2, _0801B5B8 @ =0x04000080
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_0801B5B4: .4byte 0x03004250
_0801B5B8: .4byte 0x04000080
