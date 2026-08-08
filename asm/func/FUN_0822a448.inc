	push {r4, lr}
	ldr r4, _0822A460 @ =0x03003540
	strh r0, [r4, #0x12]
	ldr r0, _0822A464 @ =0x03003554
	str r1, [r0]
	ldr r0, _0822A468 @ =0x03003534
	str r2, [r0]
	ldr r0, _0822A46C @ =0x03003558
	str r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822A460: .4byte 0x03003540
_0822A464: .4byte 0x03003554
_0822A468: .4byte 0x03003534
_0822A46C: .4byte 0x03003558
