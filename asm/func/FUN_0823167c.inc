	push {r4, lr}
	adds r4, r0, #0
	bl FUN_082316bc
	adds r1, r4, #0
	bl FUN_0823201c
	ldr r1, _08231694 @ =gVM
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08231694: .4byte gVM
