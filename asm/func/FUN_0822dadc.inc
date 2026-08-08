	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	ldr r1, _0822DAF8 @ =0x03003584
	lsls r2, r0, #5
	ldr r1, [r1]
	adds r1, r1, r2
	bl FUN_0822d12c
	strb r0, [r4, #0xe]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822DAF8: .4byte 0x03003584
