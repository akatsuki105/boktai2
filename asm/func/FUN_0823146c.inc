	push {lr}
	adds r1, r0, #0
	cmp r1, #0
	beq _08231478
	ldr r0, _0823147C @ =gVM
	str r1, [r0, #0x6c]
_08231478:
	pop {r0}
	bx r0
	.align 2, 0
_0823147C: .4byte gVM
