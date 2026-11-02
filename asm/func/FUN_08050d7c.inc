	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D8C
	adds r0, #0x48
	ldrb r0, [r0, #5]
	b _08050D8E
_08050D8C:
	movs r0, #0
_08050D8E:
	pop {r1}
	bx r1
	.align 2, 0
