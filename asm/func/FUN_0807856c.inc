	push {lr}
	adds r1, r0, #0
	ldr r2, _08078588 @ =0x000003CE
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08078582
	adds r0, r1, #0
	bl FUN_08066d10
_08078582:
	pop {r0}
	bx r0
	.align 2, 0
_08078588: .4byte 0x000003CE
