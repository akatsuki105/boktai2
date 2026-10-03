	push {r4, r5, lr}
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	bne _08045304
	movs r0, #1
	rsbs r0, r0, #0
	b _0804532A
_08045304:
	adds r4, r5, #0
	adds r4, #0x60
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl Mover_Unlink
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	bl ParticleShadow_Remove
	adds r0, r5, #0
	adds r0, #0xa4
	bl MainSprite_Remove
	movs r1, #0
	strb r1, [r5, #9]
_0804532A:
	pop {r4, r5}
	pop {r1}
	bx r1
