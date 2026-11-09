	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _081725A8 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081725AC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081725AE
	.align 2, 0
_081725A8: .4byte 0x0000046D
_081725AC:
	movs r0, #0
_081725AE:
	cmp r0, #0
	beq _08172614
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r6, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r6, #0
	movs r1, #4
	bl Enemy_FadeParticles
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _081726E8 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _081726EC @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r7, _081726F0 @ =0x00000202
	adds r0, r6, r7
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081726F4 @ =0x000001A3
	bl PlaySound_082406e0
_08172614:
	adds r0, r4, #0
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _0817262A
	adds r0, r6, #0
	adds r0, #8
	movs r1, #0xa
	bl FUN_08176530
_0817262A:
	ldr r0, [r6, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817263E
	b _08172828
_0817263E:
	adds r0, r6, #0
	adds r0, #8
	movs r1, #0x10
	bl FUN_08176530
	adds r0, r6, #0
	bl FUN_08178504
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08172666
	adds r0, r6, #0
	bl FUN_080e6658
_08172666:
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081726C6
	movs r4, #8
	ldrsh r0, [r6, r4]
	str r0, [sp]
	movs r7, #0xa
	ldrsh r0, [r6, r7]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	str r0, [sp, #8]
	adds r3, #2
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r4, #0xd0
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r7, #0xd2
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _081726F8 @ =0xFFFF0000
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
_081726C6:
	ldr r4, _081726FC @ =0x000001DF
	adds r0, r6, r4
	ldrb r0, [r0]
	movs r7, #0x90
	lsls r7, r7, #3
	adds r1, r6, r7
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
	cmp r0, #0x1f
	bgt _08172704
	ldr r3, _08172700 @ =0x030046A0
	ldr r2, [r3]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r2, r2, r1
	b _08172710
	.align 2, 0
_081726E8: .4byte 0xFFFEBE3F
_081726EC: .4byte 0x0000021E
_081726F0: .4byte 0x00000202
_081726F4: .4byte 0x000001A3
_081726F8: .4byte 0xFFFF0000
_081726FC: .4byte 0x000001DF
_08172700: .4byte 0x030046A0
_08172704:
	ldr r3, _08172730 @ =0x030046A0
	ldr r2, [r3]
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r2, r2, r4
	subs r0, #0x20
_08172710:
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r3]
	ldr r7, _08172734 @ =0x00000948
	adds r2, r0, r7
	ldrh r4, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _08172738 @ =0x0000270E
	cmp r1, r0
	bgt _0817273C
	adds r0, r4, #1
	b _08172740
	.align 2, 0
_08172730: .4byte 0x030046A0
_08172734: .4byte 0x00000948
_08172738: .4byte 0x0000270E
_0817273C:
	ldr r1, _0817275C @ =0x0000270F
	adds r0, r1, #0
_08172740:
	strh r0, [r2]
	ldr r0, [r3]
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r3, r0, r2
	ldrh r2, [r3]
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldr r0, _08172760 @ =0x0000270E
	cmp r1, r0
	bgt _08172764
	adds r0, r2, #1
	b _08172768
	.align 2, 0
_0817275C: .4byte 0x0000270F
_08172760: .4byte 0x0000270E
_08172764:
	ldr r7, _081727A0 @ =0x0000270F
	adds r0, r7, #0
_08172768:
	strh r0, [r3]
	adds r0, r6, #0
	bl Enemy_AddKillCount
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	bl AddPlayerExp
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ldr r3, _081727A4 @ =0x00000189
	adds r1, r6, r3
	ldrb r1, [r1]
	bl Player_AddWeaponExp
	ldr r0, _081727A8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081727AC
	movs r0, #1
	b _081727AE
	.align 2, 0
_081727A0: .4byte 0x0000270F
_081727A4: .4byte 0x00000189
_081727A8: .4byte 0x030047A4
_081727AC:
	movs r0, #0
_081727AE:
	cmp r0, #0
	bne _081727CE
	movs r1, #0x80
	lsls r1, r1, #4
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081727CE
	ldr r0, _08172830 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r6]
	bl DefeatedEnemyLog_Add
_081727CE:
	movs r7, #0xc9
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _08172834 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	ldr r1, _08172838 @ =0x0000046D
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r7, _0817283C @ =0x0000046B
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r3, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _08172840 @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _08172844 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #1
	adds r0, r6, r7
	strb r1, [r0]
_08172828:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08172830: .4byte 0x03002B28
_08172834: .4byte Enemy_ClearStateBegun
_08172838: .4byte 0x0000046D
_0817283C: .4byte 0x0000046B
_08172840: .4byte 0x00000469
_08172844: .4byte 0x00000484
