	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0xb4
	bl AuxSprite_Remove
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080A3DDC
	adds r0, r4, #0
	adds r0, #0x20
	bl Mover_Unlink
_080A3DDC:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
