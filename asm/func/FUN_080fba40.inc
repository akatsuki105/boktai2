	push {lr}
	adds r2, r0, #0
	ldr r0, _080FBA60 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FBA52
	movs r0, #0
	strb r0, [r1]
_080FBA52:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_080FBA60: .4byte 0x0000046D
