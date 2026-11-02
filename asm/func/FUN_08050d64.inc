	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D74
	adds r0, #0x48
	ldrb r0, [r0, #4]
	b _08050D76
_08050D74:
	movs r0, #0
_08050D76:
	pop {r1}
	bx r1
	.align 2, 0
