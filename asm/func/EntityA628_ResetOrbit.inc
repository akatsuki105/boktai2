	ldr r1, _080A085C @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _080A0860 @ =0x00000932
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0
	strh r1, [r0, #0x30]
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	bx lr
	.align 2, 0
_080A085C: .4byte 0x030046A0
_080A0860: .4byte 0x00000932
