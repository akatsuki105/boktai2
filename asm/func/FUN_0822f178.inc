	push {r4, lr}
	ldr r4, _0822F1A0 @ =0x04000050
	ldr r3, _0822F1A4 @ =0x085B0150
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r3, #0x40
	orrs r0, r3
	strh r0, [r4]
	ldr r0, _0822F1A8 @ =0x04000052
	lsls r1, r1, #8
	orrs r1, r2
	strh r1, [r0]
	ldr r1, _0822F1AC @ =0x04000054
	movs r0, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822F1A0: .4byte 0x04000050
_0822F1A4: .4byte 0x085B0150
_0822F1A8: .4byte 0x04000052
_0822F1AC: .4byte 0x04000054
