	push {r4, lr}
	movs r4, #0xd5
	lsls r4, r4, #2
	adds r3, r0, r4
	movs r4, #0
	strh r1, [r3]
	ldr r3, _0820FED8 @ =0x00000356
	adds r1, r0, r3
	strh r2, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820FED8: .4byte 0x00000356
