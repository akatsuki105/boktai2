	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x32
	ldrb r0, [r6]
	cmp r0, #0
	beq _0804CC5A
	movs r4, #0
	strb r4, [r6]
	movs r0, #2
	bl FUN_0804e584
	movs r0, #1
	bl rfu_LMAN_stopManager
	strb r4, [r5, #0x1b]
	strb r4, [r5, #0x1c]
_0804CC5A:
	adds r0, r5, #0
	bl FUN_0804bc10
	cmp r0, #0
	beq _0804CC72
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
	movs r0, #1
	strb r0, [r6]
_0804CC72:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
