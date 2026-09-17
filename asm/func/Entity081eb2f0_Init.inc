	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081eb2b0
	ldr r0, _081EB2EC @ =0x030001C4
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081EB2EC: .4byte 0x030001C4
