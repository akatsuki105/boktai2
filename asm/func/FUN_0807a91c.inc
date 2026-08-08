	push {r4, r5, lr}
	ldr r2, [r1]
	ldr r3, [r1, #4]
	str r2, [r0, #0x2c]
	str r3, [r0, #0x30]
	movs r5, #0x82
	lsls r5, r5, #1
	adds r4, r0, r5
	str r2, [r4]
	str r3, [r4, #4]
	adds r0, #0xa8
	str r2, [r0]
	str r3, [r0, #4]
	ldr r2, _0807A950 @ =0x030046A0
	ldr r3, [r2]
	ldrh r0, [r1]
	strh r0, [r3, #0x30]
	ldr r3, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r3, #0x32]
	ldr r2, [r2]
	ldrh r0, [r1, #4]
	strh r0, [r2, #0x34]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A950: .4byte 0x030046A0
