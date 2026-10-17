	push {lr}
	bl FUN_080a4e94
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4F8C
	ldr r0, [r2, #0x28]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x28]
_080A4F8C:
	pop {r0}
	bx r0
