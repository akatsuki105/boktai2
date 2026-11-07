	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0812F610 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812F614
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812F616
	.align 2, 0
_0812F610: .4byte 0x0000046D
_0812F614:
	movs r0, #0
_0812F616:
	cmp r0, #0
	beq _0812F654
	adds r0, r5, #0
	movs r1, #3
	bl Enemy_PlayAnim
	adds r0, r5, #0
	bl PlayEnemyDeathCry
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r0, #0x3c
	strh r0, [r1]
	ldr r2, _0812F710 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0812F714 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0812F718 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r6, _0812F71C @ =0x00000452
	adds r0, r5, r6
	strb r1, [r0]
	ldr r0, _0812F720 @ =0x00000453
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0812F654:
	movs r2, #0x80
	lsls r2, r2, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0812F66A
	b _0812F80E
_0812F66A:
	ldr r0, [r5, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0812F67E
	b _0812F7C8
_0812F67E:
	ldr r1, _0812F724 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0812F6E6
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r5, r3]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r3, #8
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r5]
	str r0, [sp, #0x1c]
	ldr r1, _0812F728 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r3, sp
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_0812F6E6:
	ldr r1, _0812F72C @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0812F734
	ldr r0, _0812F730 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r4, #0
	lsls r1, r3
	b _0812F746
	.align 2, 0
_0812F710: .4byte 0x030046B8
_0812F714: .4byte 0x000003FF
_0812F718: .4byte 0x0203B400
_0812F71C: .4byte 0x00000452
_0812F720: .4byte 0x00000453
_0812F724: .4byte 0x0000046B
_0812F728: .4byte 0xFFFF0000
_0812F72C: .4byte 0x000001DF
_0812F730: .4byte 0x030046A0
_0812F734:
	ldr r0, _0812F7B0 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0812F746:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _0812F75E
	adds r0, r5, #0
	bl FUN_080e6658
_0812F75E:
	ldr r4, _0812F7B4 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	ldr r2, _0812F7B8 @ =0x0000046D
	adds r0, r5, r2
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	ldr r6, _0812F7BC @ =0x0000046B
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r1, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r3, [r0]
	ldr r3, _0812F7C0 @ =0x0000046A
	adds r0, r5, r3
	strb r4, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r1, _0812F7C4 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _0812F80E
	.align 2, 0
_0812F7B0: .4byte 0x030046A0
_0812F7B4: .4byte Enemy_ClearStateBegun
_0812F7B8: .4byte 0x0000046D
_0812F7BC: .4byte 0x0000046B
_0812F7C0: .4byte 0x0000046A
_0812F7C4: .4byte 0x0000046C
_0812F7C8:
	movs r1, #1
	ldr r2, _0812F7E0 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812F7E4
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0812F7EE
	b _0812F7F2
	.align 2, 0
_0812F7E0: .4byte 0x0000025D
_0812F7E4:
	ldr r0, [r5, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _0812F7F2
_0812F7EE:
	movs r0, #1
	b _0812F7F4
_0812F7F2:
	movs r0, #0
_0812F7F4:
	cmp r0, #0
	beq _0812F804
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r5, r3
	bl ParticleShadow_Hide
	b _0812F80E
_0812F804:
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl ParticleShadow_Show
_0812F80E:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
