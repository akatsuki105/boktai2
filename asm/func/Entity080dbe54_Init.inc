	push {lr}
	ldr r3, _080DBE50 @ =0x00000724
	adds r2, r0, r3
	str r1, [r2]
	bl FUN_080dbe14
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080DBE50: .4byte 0x00000724
