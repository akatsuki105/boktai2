	push {r4, r5, lr}
	ldr r2, _08231AC8 @ =0x03000748
	adds r1, r0, #0
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r1, [r1]
	str r1, [r2]
	ldr r1, _08231ACC @ =0x03000758
	adds r0, #0x10
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08231AC8: .4byte 0x03000748
_08231ACC: .4byte 0x03000758
