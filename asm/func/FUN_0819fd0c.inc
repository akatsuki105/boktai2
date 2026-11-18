	push {r4, lr}
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, _0819FD28 @ =0x00000A92
	adds r3, r0, r4
	strh r2, [r3]
	ldr r2, _0819FD2C @ =0x00000A98
	adds r0, r0, r2
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0819FD28: .4byte 0x00000A92
_0819FD2C: .4byte 0x00000A98
