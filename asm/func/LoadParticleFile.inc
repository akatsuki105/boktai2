	push {lr}
	ldr r1, _0822B0FC @ =0x0300358C
	str r0, [r1]
	ldr r2, _0822B100 @ =0x03003594
	ldrh r1, [r0, #4]
	strh r1, [r2]
	ldr r2, _0822B104 @ =0x040000D4
	ldr r1, [r0, #8]
	adds r1, r0, r1
	str r1, [r2]
	ldr r1, _0822B108 @ =0x06010000
	str r1, [r2, #4]
	ldrh r0, [r0, #4]
	lsls r0, r0, #5
	asrs r0, r0, #2
	movs r1, #0x84
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	pop {r0}
	bx r0
	.align 2, 0
_0822B0FC: .4byte 0x0300358C
_0822B100: .4byte 0x03003594
_0822B104: .4byte 0x040000D4
_0822B108: .4byte 0x06010000
