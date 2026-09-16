	push {lr}
	adds r2, r0, #0
	movs r0, #0
	str r0, [r1, #0x78]
	ldr r0, [r2, #0x1c]
	str r0, [r1, #0x7c]
	cmp r0, #0
	beq _080160A6
	str r1, [r0, #0x78]
_080160A6:
	str r1, [r2, #0x1c]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
