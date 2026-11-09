	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08192352
	movs r2, #0x20
	ldr r3, _081922A8 @ =0x00000F2C
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081922AC
	movs r0, #1
	b _081922AE
	.align 2, 0
_081922A8: .4byte 0x00000F2C
_081922AC:
	movs r0, #0
_081922AE:
	cmp r0, #0
	bne _08192352
	ldr r1, _081922D0 @ =0x0000A027
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08192352
	movs r1, #4
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081922D4
	movs r0, #1
	b _081922D6
	.align 2, 0
_081922D0: .4byte 0x0000A027
_081922D4:
	movs r0, #0
_081922D6:
	cmp r0, #0
	beq _0819231C
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, _08192310 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	ldr r2, _08192314 @ =0x00000226
	adds r1, r4, r2
	ldrh r1, [r1]
	ldr r3, _08192318 @ =0x0000022E
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
	b _08192352
	.align 2, 0
_08192310: .4byte 0xFFFFFEFF
_08192314: .4byte 0x00000226
_08192318: .4byte 0x0000022E
_0819231C:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r4, r1
	subs r1, #0x28
	ldrh r2, [r0, #6]
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
_08192352:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
