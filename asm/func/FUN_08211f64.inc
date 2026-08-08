	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08211F84 @ =0x000092B3
	ldr r1, _08211F88 @ =0x0000D8C3
	bl FUN_082310cc
	adds r0, #0x14
	str r0, [r4, #0x3c]
	ldr r1, _08211F8C @ =0x03004250
	ldr r2, _08211F90 @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08211F84: .4byte 0x000092B3
_08211F88: .4byte 0x0000D8C3
_08211F8C: .4byte 0x03004250
_08211F90: .4byte 0x04000018
