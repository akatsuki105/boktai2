	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	adds r0, r2, #0
	adds r0, #0xec
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	ldr r1, [r3, #0x1c]
	str r1, [r0]
	cmp r1, #0
	beq _0800E4FA
	adds r0, r1, #0
	adds r0, #0xec
	str r2, [r0]
_0800E4FA:
	str r2, [r3, #0x1c]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
