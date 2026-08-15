	push {lr}
	ldr r0, _0823BAC4 @ =gCamera
	ldr r2, [r0]
	cmp r2, #0
	beq _0823BAC0
	movs r0, #0
	movs r1, #1
	strh r1, [r2, #0x1c]
	adds r1, r2, #0
	adds r1, #0x68
	strh r0, [r1]
	strh r0, [r2, #0x1e]
_0823BAC0:
	pop {r0}
	bx r0
	.align 2, 0
_0823BAC4: .4byte gCamera
