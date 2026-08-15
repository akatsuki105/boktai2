	push {lr}
	adds r2, r0, #0
	ldr r0, _0823BD10 @ =gCamera
	ldr r3, [r0]
	cmp r3, #0
	beq _0823BD0A
	adds r0, r3, #0
	adds r0, #0x9c
	str r2, [r0]
	adds r0, #4
	str r1, [r0]
	movs r2, #0
	movs r0, #1
	strh r0, [r3, #0x1c]
	adds r1, r3, #0
	adds r1, #0x68
	movs r0, #7
	strh r0, [r1]
	strh r2, [r3, #0x1e]
_0823BD0A:
	pop {r0}
	bx r0
	.align 2, 0
_0823BD10: .4byte gCamera
