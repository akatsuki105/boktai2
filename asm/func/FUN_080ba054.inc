	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _080BA074 @ =0x0000153C
	adds r0, r4, r3
	str r1, [r0]
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080ba048
	ldr r0, _080BA078 @ =0x000012F0
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BA074: .4byte 0x0000153C
_080BA078: .4byte 0x000012F0
