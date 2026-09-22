	push {lr}
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, #0xc
	adds r0, r0, r1
	ldr r1, _08047784 @ =0x03004430
	ldr r2, _08047788 @ =0x04000008
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_08047784: .4byte 0x03004430
_08047788: .4byte 0x04000008
