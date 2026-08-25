	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	beq _0806F488
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0806F3E4
	movs r2, #0
	movs r0, #4
	strb r0, [r1]
	ldr r3, _0806F3DC @ =0x000002E6
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0806F3E0 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	b _0806F3F4
	.align 2, 0
_0806F3DC: .4byte 0x000002E6
_0806F3E0: .4byte 0x000002E7
_0806F3E4:
	movs r0, #0
	strb r0, [r1]
	ldr r2, _0806F460 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _0806F464 @ =0x000002E7
	adds r1, r4, r3
	strb r0, [r1]
_0806F3F4:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #1
	bls _0806F470
	adds r7, r4, #0
	adds r7, #0x2c
	adds r0, r4, #0
	adds r1, r7, #0
	bl HealingParticles_Create
	ldr r2, _0806F468 @ =0x000003FA
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r6, r4, r3
	ldr r0, _0806F46C @ =0x00000366
	adds r2, r4, r0
	ldrh r0, [r6]
	ldrh r1, [r2]
	cmp r0, r1
	bhs _0806F452
	adds r1, r0, #0
	adds r5, r1, #0
	adds r5, #0x28
	ldrh r0, [r2]
	cmp r5, r0
	blt _0806F434
	adds r5, r0, #0
_0806F434:
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r4, r2
	subs r1, r5, r1
	movs r3, #0x97
	lsls r3, r3, #4
	adds r2, r4, r3
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r2, #1
	adds r3, r7, #0
	bl FUN_0805fe7c
	strh r5, [r6]
_0806F452:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	b _0806F478
	.align 2, 0
_0806F460: .4byte 0x000002E6
_0806F464: .4byte 0x000002E7
_0806F468: .4byte 0x000003FA
_0806F46C: .4byte 0x00000366
_0806F470:
	ldr r2, _0806F49C @ =0x000003FA
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0806F478:
	ldr r0, _0806F4A0 @ =0x00000306
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	bl FUN_08060b84
_0806F488:
	ldr r3, _0806F4A4 @ =0x0000037D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806F514
	cmp r0, #1
	bgt _0806F4A8
	cmp r0, #0
	beq _0806F4B2
	b _0806F5D0
	.align 2, 0
_0806F49C: .4byte 0x000003FA
_0806F4A0: .4byte 0x00000306
_0806F4A4: .4byte 0x0000037D
_0806F4A8:
	cmp r0, #2
	beq _0806F55C
	cmp r0, #3
	beq _0806F5A4
	b _0806F5D0
_0806F4B2:
	ldr r0, _0806F500 @ =0x000003FA
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0806F4D0
	ldr r2, _0806F504 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x93
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #0x20
	strh r0, [r1]
_0806F4D0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806F5D0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0806F508
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #1
	bl FUN_08060b84
	b _0806F5D0
	.align 2, 0
_0806F500: .4byte 0x000003FA
_0806F504: .4byte 0x0000095E
_0806F508:
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	bl FUN_08060b84
	b _0806F5D0
_0806F514:
	ldr r2, _0806F554 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x93
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #0x20
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #9
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0806F558 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _0806F5D0
	b _0806F594
	.align 2, 0
_0806F554: .4byte 0x0000095E
_0806F558: .4byte 0x0000037E
_0806F55C:
	ldr r3, _0806F5A0 @ =0x0000037E
	adds r5, r4, r3
	ldrh r0, [r5]
	cmp r0, #0
	bne _0806F56E
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806F56E:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806F5D0
_0806F594:
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #3
	bl FUN_08060b84
	b _0806F5D0
	.align 2, 0
_0806F5A0: .4byte 0x0000037E
_0806F5A4:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806F5D0
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806F5D0:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
