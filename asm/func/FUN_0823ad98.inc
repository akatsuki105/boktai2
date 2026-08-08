	push {lr}
	bl FUN_082316bc
	adds r1, r0, #0
	cmp r1, #0
	bne _0823ADB2
	bl FUN_08231cec
	b _0823ADB8
_0823ADAA:
	adds r0, r1, #0
	bl FUN_08232160
	adds r1, r0, #0
_0823ADB2:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0823ADAA
_0823ADB8:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
