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
	beq _081B9300
	b _081B9458
_081B9300:
	ldr r0, _081B9364 @ =0x0000A027
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _081B9312
	b _081B9458
_081B9312:
	movs r2, #0x10
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081B9370
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0x20
	strh r1, [r0, #0xa]
	ldr r1, _081B9368 @ =0x00002001
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
	ldr r4, _081B936C @ =0x00200004
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
	b _081B940C
	.align 2, 0
_081B9364: .4byte 0x0000A027
_081B9368: .4byte 0x00002001
_081B936C: .4byte 0x00200004
_081B9370:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	beq _081B9424
	ldr r2, _081B938C @ =0x000006B6
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _081B9390
	asrs r0, r0, #5
	b _081B9396
	.align 2, 0
_081B938C: .4byte 0x000006B6
_081B9390:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081B9396:
	adds r5, r0, #0
	cmp r5, #0x14
	ble _081B93A0
	movs r5, #0x14
	b _081B93A6
_081B93A0:
	cmp r5, #9
	bgt _081B93A6
	movs r5, #0xa
_081B93A6:
	ldr r4, _081B9414 @ =0x00000226
	adds r0, r6, r4
	ldrh r0, [r0]
	muls r0, r5, r0
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
	ldr r1, _081B9418 @ =0x0000022E
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
	ldr r1, _081B941C @ =0x00002301
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
	ldr r3, _081B9420 @ =0x00000236
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
_081B940C:
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081B9458
	.align 2, 0
_081B9414: .4byte 0x00000226
_081B9418: .4byte 0x0000022E
_081B941C: .4byte 0x00002301
_081B9420: .4byte 0x00000236
_081B9424:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, _081B9460 @ =0x00002001
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
_081B9458:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B9460: .4byte 0x00002001
