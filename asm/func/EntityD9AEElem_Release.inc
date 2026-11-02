	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0xb8
	bl Map_RemoveTileOverride
	adds r0, r4, #0
	adds r0, #0xc8
	bl Hitbox_Unregister
	ldrb r1, [r4, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080036CC
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_08002a58
_080036CC:
	adds r0, r4, #0
	adds r0, #0x2c
	bl Mover_Unlink
	movs r0, #0
	strb r0, [r4, #0x1e]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
