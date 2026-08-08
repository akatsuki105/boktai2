	push {lr}
	bl FUN_08230e88
	ldr r2, _08230EB0 @ =0x03000740
	movs r1, #0
	str r1, [r2]
	str r1, [r0]
	str r1, [r0, #4]
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r0, r2
	str r1, [r0]
	str r1, [r0, #4]
	pop {r0}
	bx r0
	.align 2, 0
_08230EB0: .4byte 0x03000740
