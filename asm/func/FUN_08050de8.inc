	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050DF6
	ldrh r0, [r0, #0x1e]
	b _08050DF8
_08050DF6:
	movs r0, #0
_08050DF8:
	pop {r1}
	bx r1
