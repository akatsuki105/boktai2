	push {lr}
	bl FUN_08241044
	ldr r1, _08241088 @ =0x030046A0
	ldr r1, [r1]
	subs r0, r0, r1
	pop {r1}
	bx r1
	.align 2, 0
_08241088: .4byte 0x030046A0
