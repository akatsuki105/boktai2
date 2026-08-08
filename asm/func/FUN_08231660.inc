	adds r2, r0, #0
	ldrb r1, [r2, #2]
	lsls r1, r1, #8
	ldrb r0, [r2, #1]
	orrs r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, _08231678 @ =gVM
	adds r2, #3
	str r2, [r1]
	bx lr
	.align 2, 0
_08231678: .4byte gVM
