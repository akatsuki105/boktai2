	push {r4, lr}
	ldr r3, _0823CE60 @ =0x08DBD798
	ldr r4, _0823CE64 @ =gClock
	ldrb r2, [r4, #0xe]
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrb r2, [r2]
	strh r2, [r0]
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #1
	adds r3, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823CE60: .4byte 0x08DBD798
_0823CE64: .4byte gClock
