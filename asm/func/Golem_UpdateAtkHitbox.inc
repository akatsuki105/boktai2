	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081161EC
	b _08116344
_081161EC:
	ldr r0, _08116250 @ =0x0000A027
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _081161FE
	b _08116344
_081161FE:
	movs r2, #0x10
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0811625C
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0x20
	strh r1, [r0, #0xa]
	ldr r1, _08116254 @ =0x00002001
	strh r1, [r0, #6]
	movs r4, #0x8a
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	movs r3, #0x8c
	lsls r3, r3, #2
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r4, #0x1c
	adds r3, r6, r4
	ldr r3, [r3]
	ldr r4, _08116258 @ =0x00200004
	orrs r3, r4
	str r3, [sp]
	movs r4, #0x8e
	lsls r4, r4, #2
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	movs r0, #0x80
	lsls r0, r0, #7
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r6, r1
	b _081162F8
	.align 2, 0
_08116250: .4byte 0x0000A027
_08116254: .4byte 0x00002001
_08116258: .4byte 0x00200004
_0811625C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	beq _08116310
	ldr r2, _08116278 @ =0x000006B6
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _0811627C
	asrs r0, r0, #5
	b _08116282
	.align 2, 0
_08116278: .4byte 0x000006B6
_0811627C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_08116282:
	adds r5, r0, #0
	cmp r5, #0x14
	ble _0811628C
	movs r5, #0x14
	b _08116292
_0811628C:
	cmp r5, #9
	bgt _08116292
	movs r5, #0xa
_08116292:
	ldr r4, _08116300 @ =0x00000226
	adds r0, r6, r4
	ldrh r0, [r0]
	muls r0, r5, r0
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
	ldr r1, _08116304 @ =0x0000022E
	adds r0, r6, r1
	ldrh r1, [r0]
	asrs r0, r5, #1
	muls r0, r1, r0
	movs r1, #0xa
	bl Div
	adds r2, r0, #0
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r1, _08116308 @ =0x00002301
	movs r3, #0
	strh r1, [r0, #6]
	strh r3, [r0, #0xa]
	movs r3, #0x90
	lsls r3, r3, #2
	adds r1, r6, r3
	ldr r1, [r1]
	movs r3, #0x80
	lsls r3, r3, #0xb
	orrs r1, r3
	str r1, [sp]
	ldr r3, _0811630C @ =0x00000236
	adds r1, r6, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r4, #0
	movs r3, #0x80
	bl Hitbox_SetAttack
	adds r2, r6, #0
	adds r2, #0x7c
	movs r1, #1
	ldr r0, [r2, #4]
	orrs r0, r1
	str r0, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #7
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r6, r4
_081162F8:
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08116344
	.align 2, 0
_08116300: .4byte 0x00000226
_08116304: .4byte 0x0000022E
_08116308: .4byte 0x00002301
_0811630C: .4byte 0x00000236
_08116310:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, _0811634C @ =0x00002001
	strh r1, [r0, #6]
	strh r2, [r0, #0xa]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r1, [r1]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r2, r6, r3
	ldrh r2, [r2]
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r3, r6, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #8
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
_08116344:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0811634C: .4byte 0x00002001
