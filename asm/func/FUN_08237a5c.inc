	push {r4, lr}
	ldr r4, _08237A90 @ =0x04000208
	movs r1, #0
	strh r1, [r4]
	ldr r2, _08237A94 @ =0x04000200
	ldrh r3, [r2]
	strh r1, [r2]
	ldr r0, _08237A98 @ =0x0400010E
	strh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	ldr r1, _08237A9C @ =0x03002CB0
	ldr r0, _08237AA0 @ =IntrDummy
	str r0, [r1, #8]
	ldr r0, _08237AA4 @ =0x0000FFBF
	ands r0, r3
	strh r0, [r2]
	movs r0, #1
	strh r0, [r4]
	ldr r1, _08237AA8 @ =0x04000202
	movs r0, #0x40
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08237A90: .4byte 0x04000208
_08237A94: .4byte 0x04000200
_08237A98: .4byte 0x0400010E
_08237A9C: .4byte 0x03002CB0
_08237AA0: .4byte IntrDummy
_08237AA4: .4byte 0x0000FFBF
_08237AA8: .4byte 0x04000202
