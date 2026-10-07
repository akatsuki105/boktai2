	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r4, #0
	adds r1, #0x2a
	ldrb r1, [r1]
	cmp r1, #0
	beq _081DF55C
	ldr r2, _081DF564 @ =FUN_081df568
	adds r0, r4, #0
	movs r1, #0x17
	bl Entity9A9F_SetState
_081DF55C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DF564: .4byte FUN_081df568
