	push {r4, lr}
	ldr r4, _0822ED00 @ =0x0300449C
	movs r3, #1
	strh r3, [r4]
	ldr r3, _0822ED04 @ =0x030044B4
	strh r0, [r3]
	ldr r0, _0822ED08 @ =0x030044B0
	strb r1, [r0]
	ldr r0, _0822ED0C @ =0x03004498
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822ED00: .4byte 0x0300449C
_0822ED04: .4byte 0x030044B4
_0822ED08: .4byte 0x030044B0
_0822ED0C: .4byte 0x03004498
