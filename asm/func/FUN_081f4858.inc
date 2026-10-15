	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x58
	adds r4, r6, #0
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r7, r6, #0
	adds r7, #0xa8
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	adds r0, r7, #0
	bl Hitbox_Register
	adds r4, #0xd0
	ldrh r0, [r4]
	cmp r0, #0
	beq _081F489C
	subs r0, #1
	strh r0, [r4]
	ldrh r1, [r7, #6]
	movs r0, #4
	orrs r0, r1
	b _081F48A4
_081F489C:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r7, #6]
	ands r0, r1
_081F48A4:
	strh r0, [r7, #6]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
