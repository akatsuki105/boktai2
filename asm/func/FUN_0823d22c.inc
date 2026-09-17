	push {r4, r5, lr}
	movs r4, #0x80
	lsls r4, r4, #0x13
	ldrh r0, [r4]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r4]
	bl WaitForVBlank
	bl WaitForVBlank
	ldr r5, _0823D270 @ =0x04000132
	ldr r1, _0823D274 @ =0x0000C304
	adds r0, r1, #0
	strh r0, [r5]
	bl SoundBias_0
	svc #3
	bl SoundBias_200
	ldr r1, _0823D278 @ =0x030047B4
	movs r0, #1
	str r0, [r1]
	ldrh r1, [r4]
	ldr r0, _0823D27C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r4]
	movs r0, #0
	strh r0, [r5]
	bl WaitForVBlank
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823D270: .4byte 0x04000132
_0823D274: .4byte 0x0000C304
_0823D278: .4byte 0x030047B4
_0823D27C: .4byte 0x0000FF7F
