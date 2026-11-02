	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050DA4
	adds r0, #0x32
	ldrb r0, [r0]
	b _08050DA6
_08050DA4:
	movs r0, #0
_08050DA6:
	pop {r1}
	bx r1
	.align 2, 0
