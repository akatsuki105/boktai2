	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r5, #0
	ldr r4, _081DA070 @ =0x085AE144
	movs r6, #6
_081DA042:
	ldr r0, [r4]
	bl IsMagicUnlocked
	cmp r0, #0
	beq _081DA05A
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r0, r0, r5
	ldr r1, [r4]
	strb r1, [r0]
	adds r5, #1
_081DA05A:
	adds r4, #4
	subs r6, #1
	cmp r6, #0
	bge _081DA042
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r5, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DA070: .4byte 0x085AE144
