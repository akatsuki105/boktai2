	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	adds r4, r1, #0
	bl Enemy_ClearDamage
	adds r0, r5, #0
	bl Enemy_UpdateJump
	adds r0, r5, #0
	bl Enemy_SnapToFloor
	ldr r0, [r5, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814E918
	b _0814EA7C
_0814E918:
	ldr r1, _0814E9B0 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_0814afc8
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r2, r5, r6
	ldrh r0, [r2]
	cmp r0, #0
	beq _0814E986
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r6, #0xa
	ldrsh r0, [r5, r6]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r6, #8
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r5]
	str r0, [sp, #0x1c]
	ldr r1, _0814E9B4 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r6, sp
	str r6, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_0814E986:
	ldr r1, _0814E9B8 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0814E9C0
	ldr r0, _0814E9BC @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe2
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r1, r4, #0
	lsls r1, r3
	b _0814E9D2
	.align 2, 0
_0814E9B0: .4byte 0x0000046B
_0814E9B4: .4byte 0xFFFF0000
_0814E9B8: .4byte 0x000001DF
_0814E9BC: .4byte 0x030046A0
_0814E9C0:
	ldr r0, _0814EA5C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0814E9D2:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0814EA3A
	ldr r3, _0814EA60 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r6, _0814EA64 @ =0x0000046D
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r2, #0
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _0814EA68 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
_0814EA3A:
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl ParticleShadow_Hide
	movs r2, #1
	ldr r1, _0814EA6C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814EA70
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0814EAC2
	.align 2, 0
_0814EA5C: .4byte 0x030046A0
_0814EA60: .4byte Enemy_ClearStateBegun
_0814EA64: .4byte 0x0000046D
_0814EA68: .4byte 0x0000046A
_0814EA6C: .4byte 0x0000025D
_0814EA70:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	b _0814EAC2
_0814EA7C:
	movs r1, #1
	ldr r2, _0814EA94 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814EA98
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0814EAA2
	b _0814EAA6
	.align 2, 0
_0814EA94: .4byte 0x0000025D
_0814EA98:
	ldr r0, [r5, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _0814EAA6
_0814EAA2:
	movs r0, #1
	b _0814EAA8
_0814EAA6:
	movs r0, #0
_0814EAA8:
	cmp r0, #0
	beq _0814EAB8
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl ParticleShadow_Hide
	b _0814EAC2
_0814EAB8:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	bl ParticleShadow_Show
_0814EAC2:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
