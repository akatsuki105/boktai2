	push {r4, r5, r6, lr}
	sub sp, #0x40
	adds r4, r0, #0
	ldr r0, _081475D0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081475D4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081475D6
	.align 2, 0
_081475D0: .4byte 0x0000046D
_081475D4:
	movs r0, #0
_081475D6:
	cmp r0, #0
	beq _081475EA
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_080efb60
_081475EA:
	ldr r0, [r4, #0x44]
	adds r0, #0x48
	movs r1, #0
	strh r1, [r0, #0xe]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r4, r1
	ldrh r0, [r5]
	cmp r0, #0x13
	bhi _08147600
	b _081477D2
_08147600:
	movs r3, #1
	ands r3, r0
	cmp r3, #0
	bne _08147646
	ldr r1, _08147750 @ =0xFFFF0000
	add r2, sp, #0x30
	ldr r0, [r2, #4]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	str r0, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #0xf
	orrs r0, r1
	str r0, [sp, #0x30]
	adds r0, r4, #0
	adds r0, #8
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	movs r3, #0
	bl EmitSmoke
	ldrh r1, [r5]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _08147646
	movs r0, #0xb7
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08147646:
	ldr r0, [r4, #0x44]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08147660
	b _0814778C
_08147660:
	ldr r3, _08147754 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	ldr r6, _08147758 @ =0x0000046D
	adds r0, r4, r6
	movs r1, #0
	movs r5, #1
	strb r5, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	movs r2, #0
	strh r1, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r2, [r0]
	ldr r2, _0814775C @ =0x0000046A
	adds r0, r4, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r4, r6
	str r1, [r0]
	ldr r1, _08147760 @ =0x0000046C
	adds r0, r4, r1
	strb r5, [r0]
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl ParticleShadow_Hide
	adds r0, r4, #0
	bl FUN_080e6658
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r2, r4, r6
	ldrh r0, [r2]
	cmp r0, #0
	beq _08147726
	movs r1, #8
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x10]
	movs r6, #0xa
	ldrsh r0, [r4, r6]
	str r0, [sp, #0x14]
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x18]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r4, r6
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	adds r6, #8
	adds r0, r4, r6
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r4]
	str r0, [sp, #0x2c]
	ldr r1, _08147750 @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x38]
	add r1, sp, #0x38
	add r6, sp, #0x10
	str r6, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_08147726:
	ldr r1, _08147764 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r4, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0814776C
	ldr r0, _08147768 @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe2
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r1, r5, #0
	lsls r1, r3
	b _0814777E
	.align 2, 0
_08147750: .4byte 0xFFFF0000
_08147754: .4byte Enemy_ClearStateBegun
_08147758: .4byte 0x0000046D
_0814775C: .4byte 0x0000046A
_08147760: .4byte 0x0000046C
_08147764: .4byte 0x000001DF
_08147768: .4byte 0x030046A0
_0814776C:
	ldr r0, _08147788 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r5, #0
	lsls r1, r0
_0814777E:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _081477D2
	.align 2, 0
_08147788: .4byte 0x030046A0
_0814778C:
	movs r1, #1
	ldr r2, _081477A4 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081477A8
	ldr r0, [r4, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081477B2
	b _081477B6
	.align 2, 0
_081477A4: .4byte 0x0000025D
_081477A8:
	ldr r0, [r4, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _081477B6
_081477B2:
	movs r0, #1
	b _081477B8
_081477B6:
	movs r0, #0
_081477B8:
	cmp r0, #0
	beq _081477C8
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r4, r6
	bl ParticleShadow_Hide
	b _081477D2
_081477C8:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ParticleShadow_Show
_081477D2:
	add sp, #0x40
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
