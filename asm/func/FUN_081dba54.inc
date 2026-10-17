	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	adds r0, #0x40
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0x10
	bl CpuSet
	movs r0, #0xea
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
