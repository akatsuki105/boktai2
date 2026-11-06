	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805D10C
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805D10C:
	adds r0, r3, #0
	adds r1, r4, #0
	movs r2, #0
	bl Entity0805d364_SetElemAnim
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
