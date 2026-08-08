	push {lr}
	movs r2, #0
	bl FUN_08231ad0
	cmp r0, #1
	beq _08231B70
	ldr r1, _08231B6C @ =gVM
	movs r0, #0
	str r0, [r1, #4]
	b _08231B74
	.align 2, 0
_08231B6C: .4byte gVM
_08231B70:
	ldr r0, _08231B78 @ =gVM
	ldr r0, [r0, #4]
_08231B74:
	pop {r1}
	bx r1
	.align 2, 0
_08231B78: .4byte gVM
