	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0813898E
	ldr r0, _08138950 @ =0x0000A027
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0813898E
	movs r3, #0x80
	lsls r3, r3, #1
	ands r1, r3
	cmp r1, #0
	beq _08138958
	movs r5, #0x94
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r1, [r0, #6]
	bics r1, r3
	strh r1, [r0, #6]
	adds r2, #0xa6
	adds r1, r4, r2
	ldrh r1, [r1]
	ldr r3, _08138954 @ =0x0000022E
	adds r2, r4, r3
	ldrh r2, [r2]
	movs r5, #0x90
	lsls r5, r5, #2
	adds r3, r4, r5
	ldr r3, [r3]
	str r3, [sp]
	subs r5, #0xa
	adds r3, r4, r5
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	b _0813898E
	.align 2, 0
_08138950: .4byte 0x0000A027
_08138954: .4byte 0x0000022E
_08138958:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r2, [r0, #6]
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0, #6]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrh r2, [r2]
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r3, r4, r5
	ldr r3, [r3]
	str r3, [sp]
	subs r5, #8
	adds r3, r4, r5
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
_0813898E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
