	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov sb, r1
	ldr r0, _0813B15C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813B11C
	movs r0, #0
	strb r0, [r1]
_0813B11C:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Curoro_GetAnimVariant
	ldr r1, _0813B160 @ =0x000004EC
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0813B164 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813B170
	ldr r1, _0813B168 @ =0x000004B7
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
	ldr r0, _0813B16C @ =0x0000046E
	adds r7, r5, r0
	b _0813B1F2
	.align 2, 0
_0813B15C: .4byte 0x0000046D
_0813B160: .4byte 0x000004EC
_0813B164: .4byte 0x0000025D
_0813B168: .4byte 0x000004B7
_0813B16C: .4byte 0x0000046E
_0813B170:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0813B1E0 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0813B1E4 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0813B1AA
	ldrb r0, [r7]
	cmp r0, #0
	bne _0813B1AA
	cmp r4, #1
	bne _0813B19C
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0813B1F6
_0813B19C:
	cmp r4, #0
	bne _0813B1AA
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0813B1F6
_0813B1AA:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0813B1BC
	movs r3, #6
_0813B1BC:
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
	beq _0813B1E8
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _0813B1F0
	.align 2, 0
_0813B1E0: .4byte 0x000004B7
_0813B1E4: .4byte 0x0000046E
_0813B1E8:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0813B1F0:
	str r0, [r6, #8]
_0813B1F2:
	movs r0, #0
	strb r0, [r7]
_0813B1F6:
	mov r0, sb
	cmp r0, #0x1d
	bgt _0813B20A
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813B20A:
	mov r0, sb
	cmp r0, #0x3b
	ble _0813B218
	ldr r0, _0813B228 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0813B218:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813B228: .4byte 0x0000046B
