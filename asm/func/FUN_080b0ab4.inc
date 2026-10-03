	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl AuxSprite_Remove
	adds r4, r6, #0
	adds r4, #0x68
	movs r5, #7
_080B0AC2:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x68
	subs r5, #1
	cmp r5, #0
	bge _080B0AC2
	movs r0, #0xea
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r5, #5
_080B0AD8:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x68
	subs r5, #1
	cmp r5, #0
	bge _080B0AD8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
