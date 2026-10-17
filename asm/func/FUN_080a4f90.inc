	push {lr}
	bl FUN_080a4e94
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4FA6
	ldr r0, [r2, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x28]
_080A4FA6:
	pop {r0}
	bx r0
	.align 2, 0
