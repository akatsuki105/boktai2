	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r0, r5, #0
	bl Entity2D2BElem_ConsumeStateEntered
	cmp r0, #0
	beq _080080EE
	adds r4, r5, #0
	adds r4, #0x34
	adds r0, r5, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _080080F8 @ =0x085AA670
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _080080FC @ =0x085AA678
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r4, #0
	bl MainSprite_SetPlttID
_080080EE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080080F8: .4byte 0x085AA670
_080080FC: .4byte 0x085AA678
