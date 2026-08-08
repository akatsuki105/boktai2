	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r3, #0
	beq _08231464
	ldr r1, _08231460 @ =gVM
	ldr r0, [r1, #0x6c]
	lsls r2, r2, #2
	adds r2, r0, r2
	stm r2!, {r3}
	str r2, [r1, #0x6c]
	b _08231466
	.align 2, 0
_08231460: .4byte gVM
_08231464:
	movs r0, #0
_08231466:
	pop {r1}
	bx r1
	.align 2, 0
