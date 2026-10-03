	push {r4, r5, lr}
	adds r5, r0, #0
	cmp r5, #0
	bge _080925E0
	movs r0, #0
	b _08092600
_080925E0:
	adds r0, r5, #0
	bl FUN_08091e34
	rsbs r1, r0, #0
	orrs r1, r0
	asrs r4, r1, #0x1f
	movs r0, #0x10
	ands r4, r0
	adds r0, r5, #0
	bl FUN_08091cb8
	cmp r0, #0
	beq _080925FE
	movs r0, #1
	orrs r4, r0
_080925FE:
	adds r0, r4, #0
_08092600:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
