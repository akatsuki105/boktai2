	ldr r0, _0804890C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08048910 @ =0x00000938
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0804890C: .4byte 0x030046A0
_08048910: .4byte 0x00000938
