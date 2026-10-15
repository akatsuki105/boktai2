	push {r4, r5, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805A9C8
	movs r2, #0
	strb r2, [r5]
	adds r4, r5, #0
	adds r4, #0x98
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r3, #0x20]
	str r2, [sp]
	movs r3, #0
	bl AuxAnim_SetAnim
	adds r0, r5, #0
	bl FUN_0805a8b0
	adds r1, r5, #0
	adds r1, #0x14
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
_0805A9C8:
	ldrh r0, [r5, #6]
	cmp r0, #0x1f
	bls _0805A9DA
	movs r0, #2
	movs r1, #0
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	strh r1, [r5, #6]
_0805A9DA:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
