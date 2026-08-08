	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _080726B0 @ =0x000004AB
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080726AA
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
	movs r0, #0
	strb r0, [r4]
_080726AA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080726B0: .4byte 0x000004AB
