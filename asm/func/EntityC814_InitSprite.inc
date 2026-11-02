	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x8c
	ldr r1, _080CB710 @ =0x00009DA7
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r5, r6, #0
	adds r5, #0x60
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r6, #0
	adds r0, #0x1c
	adds r1, r5, #0
	bl Mover_SetAuxSprite
	adds r2, r6, #0
	adds r2, #0x7c
	ldr r0, [r6, #0x24]
	ldr r1, [r6, #0x28]
	str r0, [r2]
	str r1, [r2, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CB710: .4byte 0x00009DA7
