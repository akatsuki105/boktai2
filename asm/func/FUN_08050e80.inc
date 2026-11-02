	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050E92
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #5
	beq _08050E96
_08050E92:
	movs r0, #0
	b _08050E98
_08050E96:
	movs r0, #1
_08050E98:
	pop {r1}
	bx r1
