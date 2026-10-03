	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	strb r3, [r2]
	lsls r3, r3, #0x18
	movs r2, #5
	cmp r3, #0
	beq _080B975E
	movs r2, #4
_080B975E:
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetAnim
	adds r0, r4, #0
	adds r1, r5, #0
	bl MainSprite_AdvanceAnim
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
