	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CCB4
	movs r0, #0
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	bl rfu_LMAN_stopManager
_0804CCB4:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
