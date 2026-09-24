	ldr r0, _0801B2DC @ =0x03004460
	movs r3, #0x40
	str r3, [r0]
	ldr r1, _0801B2E0 @ =0x03004454
	ldr r2, _0801B2E4 @ =0x00001FFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0801B2E8 @ =0x03004494
	ldr r1, _0801B2EC @ =0x00001084
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, _0801B2F0 @ =0x0300445C
	str r3, [r0]
	ldr r1, _0801B2F4 @ =0x03004490
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0801B2F8 @ =0x03004464
	strh r2, [r0]
	movs r0, #0
	bx lr
	.align 2, 0
_0801B2DC: .4byte 0x03004460
_0801B2E0: .4byte 0x03004454
_0801B2E4: .4byte 0x00001FFF
_0801B2E8: .4byte 0x03004494
_0801B2EC: .4byte 0x00001084
_0801B2F0: .4byte 0x0300445C
_0801B2F4: .4byte 0x03004490
_0801B2F8: .4byte 0x03004464
