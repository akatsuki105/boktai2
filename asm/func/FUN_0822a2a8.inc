	push {r4, lr}
	ldr r1, _0822A2E4 @ =0x03003540
	movs r2, #0
	strh r2, [r1]
	strh r2, [r1, #2]
	strh r2, [r1, #4]
	movs r0, #1
	strh r0, [r1, #0xc]
	strh r2, [r1, #0x10]
	ldr r0, _0822A2E8 @ =0x03003530
	str r2, [r0]
	movs r1, #0
	ldr r4, _0822A2EC @ =0x03003568
	ldr r3, _0822A2F0 @ =0x03003570
	ldr r2, _0822A2F4 @ =0x03003560
	movs r0, #1
_0822A2C8:
	stm r2!, {r1}
	stm r3!, {r1}
	stm r4!, {r1}
	subs r0, #1
	cmp r0, #0
	bge _0822A2C8
	bl FUN_0822b238
	movs r0, #1
	bl FUN_0822b41c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822A2E4: .4byte 0x03003540
_0822A2E8: .4byte 0x03003530
_0822A2EC: .4byte 0x03003568
_0822A2F0: .4byte 0x03003570
_0822A2F4: .4byte 0x03003560
