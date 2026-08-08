	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08060c60
	ldr r1, _08078568 @ =0x000003CE
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _08078562
	adds r0, r4, #0
	bl FUN_08066d10
_08078562:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08078568: .4byte 0x000003CE
