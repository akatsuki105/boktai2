	push {r4, lr}
	adds r4, r1, #0
	movs r3, #0
	adds r2, r0, #0
	ldr r0, [r2]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _08231874
_0823186A:
	adds r2, #4
	adds r3, #1
	ldr r0, [r2]
	cmp r0, r1
	bne _0823186A
_08231874:
	str r3, [r4]
	adds r0, r2, #4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
