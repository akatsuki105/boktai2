	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08212590 @ =0x000092B3
	ldr r1, _08212594 @ =0x0000F0DC
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x3c]
	ldr r1, _08212598 @ =0x03004250
	ldr r2, _0821259C @ =0x04000048
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08212590: .4byte 0x000092B3
_08212594: .4byte 0x0000F0DC
_08212598: .4byte 0x03004250
_0821259C: .4byte 0x04000048
