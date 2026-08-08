	push {lr}
	adds r1, r0, #0
	ldr r0, _08218B30 @ =0x085AFF78
	movs r2, #5
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_08218B30: .4byte 0x085AFF78
