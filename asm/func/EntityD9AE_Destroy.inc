	push {r4, lr}
	adds r4, r0, #0
	bl EntityD9AE_ReleaseAll
	ldr r0, [r4, #0x70]
	bl Free
	ldr r1, _08004584 @ =0x03000020
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08004584: .4byte 0x03000020
