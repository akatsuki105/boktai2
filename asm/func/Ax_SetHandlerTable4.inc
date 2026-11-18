	ldr r1, _081A1584 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _081A1588 @ =0x085ADDDC
	str r1, [r0]
	bx lr
	.align 2, 0
_081A1584: .4byte 0x0000063C
_081A1588: .4byte 0x085ADDDC
