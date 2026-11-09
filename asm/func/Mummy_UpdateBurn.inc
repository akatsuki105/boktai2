	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _08129450
	b _081298F8
_08129450:
	ldr r0, _081294B4 @ =0x00000464
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0812945C
	b _081298F8
_0812945C:
	ldr r1, _081294B8 @ =0x00000553
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _081294C4
	ldr r2, _081294BC @ =0x00000494
	adds r1, r6, r2
	movs r0, #0x20
	strh r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	subs r0, #0x31
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081294C0 @ =0x00000482
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
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
	strh r5, [r4]
	b _081298F8
	.align 2, 0
_081294B4: .4byte 0x00000464
_081294B8: .4byte 0x00000553
_081294BC: .4byte 0x00000494
_081294C0: .4byte 0x00000482
_081294C4:
	ldr r1, _081294EC @ =0x00000316
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _081294F4
	ldrh r0, [r4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _08129514
	ldr r0, _081294F0 @ =0x00000121
	bl PlaySound_082406e0
	movs r0, #0x10
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r6, r3
	b _0812950E
	.align 2, 0
_081294EC: .4byte 0x00000316
_081294F0: .4byte 0x00000121
_081294F4:
	ldrh r0, [r4]
	movs r1, #0x30
	bl Mod
	cmp r0, #0
	bne _08129514
	ldr r0, _081295DC @ =0x00000121
	bl PlaySound_082406e0
	movs r0, #0x20
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r6, r4
_0812950E:
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08129514:
	movs r5, #0x8c
	lsls r5, r5, #3
	adds r1, r6, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _0812956E
	movs r7, #0
	ldrh r1, [r1]
	cmp r7, r1
	bge _0812956E
	ldr r0, _081295E0 @ =0x00000462
	adds r3, r6, r0
	adds r2, r6, r5
_0812952E:
	lsls r1, r7, #1
	movs r4, #0x8b
	lsls r4, r4, #3
	adds r0, r6, r4
	adds r5, r0, r1
	ldrh r4, [r5]
	cmp r4, #0
	bne _08129560
	adds r0, r6, #0
	movs r1, #1
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	bl Enemy_FadeParticles
	strh r4, [r5]
	movs r0, #1
	lsls r0, r7
	ldr r3, [sp, #0x18]
	ldrh r1, [r3]
	bics r1, r0
	strh r1, [r3]
	ldr r2, [sp, #0x14]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_08129560:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	adds r7, #1
	ldrh r5, [r2]
	cmp r7, r5
	blt _0812952E
_0812956E:
	ldr r0, _081295E4 @ =0x00000464
	adds r1, r6, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldrh r0, [r1]
	movs r1, #0x28
	bl Mod
	cmp r0, #0
	beq _08129586
	b _0812970E
_08129586:
	ldr r2, _081295E8 @ =0x00000316
	adds r1, r6, r2
	movs r0, #1
	ldrb r1, [r1]
	lsls r0, r1
	movs r4, #0x8b
	lsls r4, r4, #1
	adds r3, r6, r4
	strh r0, [r3]
	ldr r5, _081295EC @ =0x0000048A
	adds r1, r6, r5
	strh r0, [r1]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r2]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r2, r6, r1
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _081295C2
	b _0812970E
_081295C2:
	ldr r2, _081295F0 @ =0x0000047C
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r3, _081295F4 @ =0x0000025D
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081295F8
	ldr r0, [r6, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _08129604
	.align 2, 0
_081295DC: .4byte 0x00000121
_081295E0: .4byte 0x00000462
_081295E4: .4byte 0x00000464
_081295E8: .4byte 0x00000316
_081295EC: .4byte 0x0000048A
_081295F0: .4byte 0x0000047C
_081295F4: .4byte 0x0000025D
_081295F8:
	ldr r2, [r6, #0x44]
	ldr r0, _08129630 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08129604:
	ldr r4, _08129634 @ =0x00000492
	adds r1, r6, r4
	movs r0, #8
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #8
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08129638 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812963C
	movs r0, #1
	b _0812963E
	.align 2, 0
_08129630: .4byte 0x03003584
_08129634: .4byte 0x00000492
_08129638: .4byte 0x030047A4
_0812963C:
	movs r0, #0
_0812963E:
	cmp r0, #0
	beq _081296AC
	movs r0, #0x94
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _081296AC
	cmp r2, #0
	beq _081296AC
	ldr r0, _08129664 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _08129668
	movs r0, #1
	rsbs r0, r0, #0
	b _0812966C
	.align 2, 0
_08129664: .4byte 0x03002C68
_08129668:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_0812966C:
	cmp r0, #1
	beq _0812968E
	cmp r0, #1
	bgt _0812967A
	cmp r0, #0
	beq _08129684
	b _081296AC
_0812967A:
	cmp r0, #2
	beq _08129698
	cmp r0, #3
	beq _081296A2
	b _081296AC
_08129684:
	ldr r0, [r1]
	cmp r0, #1
	beq _081296AC
	movs r0, #0
	b _081296AE
_0812968E:
	ldr r0, [r1]
	cmp r0, #2
	beq _081296AC
	movs r0, #0
	b _081296AE
_08129698:
	ldr r0, [r1]
	cmp r0, #4
	beq _081296AC
	movs r0, #0
	b _081296AE
_081296A2:
	ldr r0, [r1]
	cmp r0, #8
	beq _081296AC
	movs r0, #0
	b _081296AE
_081296AC:
	movs r0, #1
_081296AE:
	cmp r0, #0
	beq _0812970E
	ldrh r0, [r6]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	movs r5, #0x95
	lsls r5, r5, #2
	adds r2, r6, r5
	ldrh r2, [r2]
	ldr r4, _08129784 @ =0x0000025A
	adds r3, r6, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl HUD_ShowEnemyGauge
	add r5, sp, #0xc
	str r4, [sp, #8]
	add r0, sp, #8
	adds r1, r5, #0
	ldr r2, _08129788 @ =0x05000002
	bl CpuSet
	ldr r0, _0812978C @ =0x0000048A
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _081296F8
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0812970E
_081296F8:
	adds r0, r6, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r6, #0
	adds r3, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl CreateDamageNumber
_0812970E:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _0812971E
	b _081298F8
_0812971E:
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	movs r2, #0
	strb r1, [r0]
	ldr r4, _08129790 @ =0x00000469
	adds r0, r6, r4
	strb r2, [r0]
	ldr r5, _08129794 @ =0x0000046A
	adds r0, r6, r5
	strb r2, [r0]
	ldr r1, _08129798 @ =0x00000484
	adds r0, r6, r1
	str r2, [r0]
	adds r3, #4
	adds r0, r6, r3
	movs r1, #1
	strb r1, [r0]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r4, [r0]
	movs r3, #0x11
	adds r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _0812979C @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r6, r5
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
	ldr r0, _081297A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081297A4
	movs r0, #1
	b _081297A6
	.align 2, 0
_08129784: .4byte 0x0000025A
_08129788: .4byte 0x05000002
_0812978C: .4byte 0x0000048A
_08129790: .4byte 0x00000469
_08129794: .4byte 0x0000046A
_08129798: .4byte 0x00000484
_0812979C: .4byte 0x0000046B
_081297A0: .4byte 0x030047A4
_081297A4:
	movs r0, #0
_081297A6:
	cmp r0, #0
	beq _081297C0
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r0, [r0]
	movs r5, #0x93
	lsls r5, r5, #3
	adds r1, r6, r5
	ldr r1, [r1]
	bl FUN_080ce544
	b _081298EA
_081297C0:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r2, _081297E4 @ =0x00000474
	adds r5, r6, r2
	cmp r0, #0
	beq _0812988A
	movs r1, #0x80
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081297E8
	movs r0, #1
	b _081297EA
	.align 2, 0
_081297E4: .4byte 0x00000474
_081297E8:
	movs r0, #0
_081297EA:
	cmp r0, #0
	bne _0812988A
	ldr r3, _08129828 @ =0x000001DF
	adds r0, r6, r3
	ldrb r1, [r0]
	cmp r1, #0xe
	bne _08129804
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #1
	beq _0812986C
_08129804:
	cmp r1, #5
	beq _0812986C
	cmp r1, #7
	beq _0812986C
	cmp r1, #6
	beq _0812986C
	ldr r2, _0812982C @ =0x030046A0
	ldr r0, [r2]
	ldr r1, _08129830 @ =0x00000948
	adds r3, r0, r1
	ldrh r4, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _08129834 @ =0x0000270E
	cmp r1, r0
	bgt _08129838
	adds r0, r4, #1
	b _0812983C
	.align 2, 0
_08129828: .4byte 0x000001DF
_0812982C: .4byte 0x030046A0
_08129830: .4byte 0x00000948
_08129834: .4byte 0x0000270E
_08129838:
	ldr r1, _08129858 @ =0x0000270F
	adds r0, r1, #0
_0812983C:
	strh r0, [r3]
	ldr r0, [r2]
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r0, _0812985C @ =0x0000270E
	cmp r1, r0
	bgt _08129860
	adds r0, r3, #1
	b _08129864
	.align 2, 0
_08129858: .4byte 0x0000270F
_0812985C: .4byte 0x0000270E
_08129860:
	ldr r1, _08129898 @ =0x0000270F
	adds r0, r1, #0
_08129864:
	strh r0, [r2]
	adds r0, r6, #0
	bl Enemy_AddKillCount
_0812986C:
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	bl AddPlayerExp
	movs r3, #0x93
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ldr r4, _0812989C @ =0x00000189
	adds r1, r6, r4
	ldrb r1, [r1]
	bl Player_AddWeaponExp
_0812988A:
	movs r1, #0x80
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081298A0
	movs r0, #1
	b _081298A2
	.align 2, 0
_08129898: .4byte 0x0000270F
_0812989C: .4byte 0x00000189
_081298A0:
	movs r0, #0
_081298A2:
	cmp r0, #0
	bne _081298DE
	ldr r0, _081298B8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081298BC
	movs r0, #1
	b _081298BE
	.align 2, 0
_081298B8: .4byte 0x030047A4
_081298BC:
	movs r0, #0
_081298BE:
	cmp r0, #0
	bne _081298DE
	movs r1, #0x80
	lsls r1, r1, #4
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r0, r6, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081298DE
	ldr r0, _08129900 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r6]
	bl DefeatedEnemyLog_Add
_081298DE:
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081298EA:
	ldr r1, _08129904 @ =0x00000464
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08129908 @ =0x000004BE
	adds r0, r6, r2
	strh r1, [r0]
_081298F8:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08129900: .4byte 0x03002B28
_08129904: .4byte 0x00000464
_08129908: .4byte 0x000004BE
