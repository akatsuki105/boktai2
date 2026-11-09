	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _08133D3C @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08133CF2
	movs r0, #0
	strb r0, [r1]
_08133CF2:
	ldrb r0, [r6, #5]
	add r4, sp, #8
	add r1, sp, #4
	adds r2, r4, #0
	bl Centipede_GetAnimVariant
	ldr r1, _08133D40 @ =0x00000504
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r7, [sp, #8]
	ldr r1, _08133D44 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	bne _08133D50
	ldr r0, _08133D48 @ =0x000004B7
	adds r5, r6, r0
	strb r2, [r5]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r7, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	mov r8, r5
	ldr r1, _08133D4C @ =0x0000046E
	adds r1, r1, r6
	mov sb, r1
	b _08133DD2
	.align 2, 0
_08133D3C: .4byte 0x0000046D
_08133D40: .4byte 0x00000504
_08133D44: .4byte 0x0000025D
_08133D48: .4byte 0x000004B7
_08133D4C: .4byte 0x0000046E
_08133D50:
	ldr r0, [r6, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, r2, r3
	ldr r1, _08133DC0 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	mov r8, r0
	ldr r0, _08133DC4 @ =0x0000046E
	adds r0, r0, r6
	mov sb, r0
	cmp r1, r2
	bne _08133D8C
	ldrb r0, [r0]
	cmp r0, #0
	bne _08133D8C
	cmp r7, #1
	bne _08133D7E
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08133DD8
_08133D7E:
	cmp r7, #0
	bne _08133D8C
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08133DD8
_08133D8C:
	mov r1, r8
	strb r2, [r1]
	movs r5, #4
	adds r0, r7, #0
	ands r0, r5
	movs r3, #4
	cmp r0, #0
	beq _08133D9E
	movs r3, #6
_08133D9E:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r7, r0
	cmp r7, #0
	beq _08133DC8
	ldr r0, [r4, #8]
	orrs r0, r5
	b _08133DD0
	.align 2, 0
_08133DC0: .4byte 0x000004B7
_08133DC4: .4byte 0x0000046E
_08133DC8:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08133DD0:
	str r0, [r4, #8]
_08133DD2:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_08133DD8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x12
	bl FUN_0813652c
	movs r2, #0xc8
	lsls r2, r2, #7
	adds r0, r6, #0
	movs r1, #0x14
	bl FUN_081370f4
	ldr r0, [sp, #0xc]
	cmp r0, #0x28
	ble _08133EBE
	ldrb r0, [r6, #5]
	add r1, sp, #4
	add r2, sp, #8
	bl Centipede_GetAnimVariant
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08133E32
	mov r0, r8
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	b _08133EA2
_08133E32:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, r2
	bne _08133E66
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _08133E66
	cmp r4, #1
	bne _08133E58
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08133EA8
_08133E58:
	cmp r4, #0
	bne _08133E66
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08133EA8
_08133E66:
	mov r0, r8
	strb r2, [r0]
	movs r7, #4
	adds r0, r4, #0
	ands r0, r7
	movs r3, #4
	cmp r0, #0
	beq _08133E78
	movs r3, #6
_08133E78:
	ldr r1, [r6, #0x44]
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
	beq _08133E98
	ldr r0, [r5, #8]
	orrs r0, r7
	b _08133EA0
_08133E98:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08133EA0:
	str r0, [r5, #8]
_08133EA2:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_08133EA8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0813632c
	ldr r0, _08133ED0 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_08133EBE:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08133ED0: .4byte 0x0000046B
