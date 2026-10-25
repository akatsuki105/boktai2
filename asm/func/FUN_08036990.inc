	push {r4, r5, lr}
	ldr r5, _080369C8 @ =0x0203B400
	ldr r4, _080369CC @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _080369D0 @ =0x000003FF
	ands r1, r3
	lsls r2, r1, #1
	adds r2, r2, r5
	ldrh r2, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #1
	ands r2, r3
	ands r1, r3
	adds r2, r2, r1
	adds r2, #1
	adds r0, r0, r2
	movs r1, #3
	ands r0, r1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080369C8: .4byte 0x0203B400
_080369CC: .4byte 0x030046B8
_080369D0: .4byte 0x000003FF
