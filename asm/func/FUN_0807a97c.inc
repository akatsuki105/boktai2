	push {r4, lr}
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r4, r0, r3
	ldrh r3, [r4]
	orrs r1, r3
	strh r1, [r4]
	ldr r1, _0807A998 @ =0x00000392
	adds r0, r0, r1
	strh r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807A998: .4byte 0x00000392
