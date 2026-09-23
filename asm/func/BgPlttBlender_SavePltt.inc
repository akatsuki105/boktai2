	push {lr}
	adds r1, r0, #0
	ldr r0, _08019060 @ =0x03004250
	adds r1, #0x1c
	ldr r2, _08019064 @ =0x04000080
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_08019060: .4byte 0x03004250
_08019064: .4byte 0x04000080
