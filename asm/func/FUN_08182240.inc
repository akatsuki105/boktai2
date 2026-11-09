	ldr r1, _0818224C @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _08182250 @ =0x085ADB94
	str r1, [r0]
	bx lr
	.align 2, 0
_0818224C: .4byte 0x0000063C
_08182250: .4byte 0x085ADB94
