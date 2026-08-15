	push {lr}
	ldr r0, _0823B87C @ =gCamera
	ldr r0, [r0]
	cmp r0, #0
	beq _0823B876
	adds r1, r0, #0
	adds r1, #0x54
	movs r0, #0
	strh r0, [r1]
_0823B876:
	pop {r0}
	bx r0
	.align 2, 0
_0823B87C: .4byte gCamera
