	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _08189318 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818931C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818931E
	.align 2, 0
_08189318: .4byte 0x0000046D
_0818931C:
	movs r0, #0
_0818931E:
	cmp r0, #0
	beq _0818940A
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Serpent_GetAnimVariant
	ldr r1, _08189364 @ =0x00000504
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08189368 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08189374
	ldr r1, _0818936C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r0, _08189370 @ =0x0000046E
	adds r7, r5, r0
	b _081893F6
	.align 2, 0
_08189364: .4byte 0x00000504
_08189368: .4byte 0x0000025D
_0818936C: .4byte 0x000004B7
_08189370: .4byte 0x0000046E
_08189374:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081893E4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081893E8 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081893AE
	ldrb r0, [r7]
	cmp r0, #0
	bne _081893AE
	cmp r4, #1
	bne _081893A0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081893FA
_081893A0:
	cmp r4, #0
	bne _081893AE
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081893FA
_081893AE:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081893C0
	movs r3, #6
_081893C0:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081893EC
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081893F4
	.align 2, 0
_081893E4: .4byte 0x000004B7
_081893E8: .4byte 0x0000046E
_081893EC:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081893F4:
	str r0, [r6, #8]
_081893F6:
	movs r0, #0
	strb r0, [r7]
_081893FA:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
	b _081894F0
_0818940A:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Serpent_GetAnimVariant
	ldr r1, _0818944C @ =0x00000504
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08189450 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818945C
	ldr r1, _08189454 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r0, _08189458 @ =0x0000046E
	adds r7, r5, r0
	b _081894DE
	.align 2, 0
_0818944C: .4byte 0x00000504
_08189450: .4byte 0x0000025D
_08189454: .4byte 0x000004B7
_08189458: .4byte 0x0000046E
_0818945C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081894CC @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081894D0 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08189496
	ldrb r0, [r7]
	cmp r0, #0
	bne _08189496
	cmp r4, #1
	bne _08189488
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081894E2
_08189488:
	cmp r4, #0
	bne _08189496
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081894E2
_08189496:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081894A8
	movs r3, #6
_081894A8:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081894D4
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081894DC
	.align 2, 0
_081894CC: .4byte 0x000004B7
_081894D0: .4byte 0x0000046E
_081894D4:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081894DC:
	str r0, [r6, #8]
_081894DE:
	movs r0, #0
	strb r0, [r7]
_081894E2:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
_081894F0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
