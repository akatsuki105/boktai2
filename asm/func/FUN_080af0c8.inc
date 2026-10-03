	push {lr}
	adds r1, r0, #0
	ldr r2, _080AF0DC @ =0x00001336
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #3
	beq _080AF0E0
	cmp r0, #4
	beq _080AF0E6
	b _080AF0F2
	.align 2, 0
_080AF0DC: .4byte 0x00001336
_080AF0E0:
	bl FUN_080df478
	b _080AF0F2
_080AF0E6:
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r0, r1, r2
	ldr r0, [r0]
	bl FUN_0805b1a0
_080AF0F2:
	pop {r0}
	bx r0
	.align 2, 0
