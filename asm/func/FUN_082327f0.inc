	push {lr}
	ldr r1, _08232808 @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #4]
	bl FUN_0823273c
	bl FUN_08232760
	bl UpdateMapSize_0823279c
	pop {r0}
	bx r0
	.align 2, 0
_08232808: .4byte 0x030046A4
