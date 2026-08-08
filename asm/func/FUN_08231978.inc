	ldr r3, _082319A0 @ =0x03000758
	lsls r0, r0, #2
	ldr r1, [r3, #4]
	adds r0, r0, r1
	ldrb r2, [r0, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r0, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r0, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r0, [r0]
	orrs r2, r0
	ldr r0, _082319A4 @ =0x7FFFFFFF
	ands r2, r0
	ldr r0, [r3, #8]
	adds r0, r0, r2
	bx lr
	.align 2, 0
_082319A0: .4byte 0x03000758
_082319A4: .4byte 0x7FFFFFFF
