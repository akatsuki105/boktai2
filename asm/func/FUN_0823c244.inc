	push {lr}
	ldr r0, _0823C25C @ =gCamera
	ldr r0, [r0]
	cmp r0, #0
	beq _0823C256
	adds r1, r0, #0
	adds r1, #0x8c
	movs r0, #0
	strh r0, [r1]
_0823C256:
	pop {r0}
	bx r0
	.align 2, 0
_0823C25C: .4byte gCamera
