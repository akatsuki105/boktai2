	push {r4, lr}
	ldr r4, _0822CE48 @ =0x04000048
	lsls r1, r1, #8
	orrs r1, r0
	strh r1, [r4]
	ldr r0, _0822CE4C @ =0x0400004A
	lsls r3, r3, #8
	orrs r3, r2
	strh r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822CE48: .4byte 0x04000048
_0822CE4C: .4byte 0x0400004A
