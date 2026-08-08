	ldr r0, _0822ECD4 @ =0x0300449C
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0822ECD8 @ =0x030044B4
	strh r1, [r0]
	ldr r0, _0822ECDC @ =0x030044B0
	strb r1, [r0]
	ldr r0, _0822ECE0 @ =0x03004498
	strb r1, [r0]
	bx lr
	.align 2, 0
_0822ECD4: .4byte 0x0300449C
_0822ECD8: .4byte 0x030044B4
_0822ECDC: .4byte 0x030044B0
_0822ECE0: .4byte 0x03004498
