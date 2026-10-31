	push {r4, r5, lr}
	ldr r5, _08086264 @ =0x030046A0
	ldr r0, [r5]
	ldr r4, _08086268 @ =0x00000252
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0x38
	movs r1, #0
	bl TryAddItem
	ldr r0, [r5]
	adds r0, r0, r4
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086264: .4byte 0x030046A0
_08086268: .4byte 0x00000252
