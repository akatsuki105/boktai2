	push {r4, r5, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CC1E
	movs r4, #0
	strb r4, [r1]
	movs r0, #1
	bl FUN_0804e584
	movs r0, #1
	bl rfu_LMAN_stopManager
	strb r4, [r5, #0x1b]
	strb r4, [r5, #0x1c]
_0804CC1E:
	adds r0, r5, #0
	bl FUN_0804bc10
	cmp r0, #0
	beq _0804CC2E
	adds r0, r5, #0
	bl FUN_0804ba64
_0804CC2E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
