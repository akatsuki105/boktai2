	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r1, _08231AA0 @ =0x03000748
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r1, [r1]
	str r1, [r2]
	adds r0, #0x10
	ldr r1, _08231AA4 @ =0x03000758
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1]
	str r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08231AA0: .4byte 0x03000748
_08231AA4: .4byte 0x03000758
