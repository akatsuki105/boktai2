	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	ldr r0, _080F9B98 @ =0x03000184
	str r5, [r0]
	bl FUN_080f8c10
	strh r4, [r5, #0x24]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080F9B98: .4byte 0x03000184
