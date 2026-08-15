	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _082138C4 @ =0x000092B3
	ldr r1, _082138C8 @ =0x0000EFDA
	bl GetFile
	adds r4, #0xfc
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _082138CC @ =0x030043F0
	ldr r2, _082138D0 @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082138C4: .4byte 0x000092B3
_082138C8: .4byte 0x0000EFDA
_082138CC: .4byte 0x030043F0
_082138D0: .4byte 0x04000018
