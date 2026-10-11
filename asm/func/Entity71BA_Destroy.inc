	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0x1d]
	cmp r1, #0
	beq _080A061C
	adds r0, #0x24
	bl Map_RemoveTileOverride
_080A061C:
	pop {r1}
	bx r1
