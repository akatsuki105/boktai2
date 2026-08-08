	ldr r1, _0822ED28 @ =0x0300449C
	movs r0, #1
	strh r0, [r1]
	ldr r0, _0822ED2C @ =0x030044B4
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0822ED30 @ =0x030044B0
	strb r1, [r0]
	ldr r0, _0822ED34 @ =0x03004498
	strb r1, [r0]
	bx lr
	.align 2, 0
_0822ED28: .4byte 0x0300449C
_0822ED2C: .4byte 0x030044B4
_0822ED30: .4byte 0x030044B0
_0822ED34: .4byte 0x03004498
