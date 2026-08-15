	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldrh r0, [r0]
	cmp r0, #1
	bne _0823B854
	adds r0, r2, #0
	bl Camera_ApplyBounds1
	b _0823B85E
_0823B854:
	cmp r0, #2
	bne _0823B85E
	adds r0, r2, #0
	bl Camera_ApplyBounds2
_0823B85E:
	pop {r0}
	bx r0
	.align 2, 0
