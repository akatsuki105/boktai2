	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _08094576
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08092744
	b _08094584
_08094576:
	cmp r0, #1
	bne _08094584
	bl TextBox_Close
	adds r0, r4, #0
	bl FUN_08093f28
_08094584:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
