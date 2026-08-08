	ldr r0, _0807B574 @ =0x03002BD0
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0807B578 @ =0x03002B80
	strh r1, [r0]
	ldr r0, _0807B57C @ =0x03002B78
	strh r1, [r0]
	bx lr
	.align 2, 0
_0807B574: .4byte 0x03002BD0
_0807B578: .4byte 0x03002B80
_0807B57C: .4byte 0x03002B78
