	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r4, #0
	adds r1, #0x2b
	ldrb r1, [r1]
	cmp r1, #0
	beq _081DF620
	ldr r2, _081DF628 @ =FUN_081df62c
	adds r0, r4, #0
	movs r1, #0x19
	bl Entity9A9F_SetState
_081DF620:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DF628: .4byte FUN_081df62c
