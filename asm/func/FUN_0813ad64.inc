	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _0813ADC4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813AD7C
	movs r0, #0
	strb r0, [r1]
_0813AD7C:
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Curoro_GetAnimVariant
	ldr r1, _0813ADC8 @ =0x000004C4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0813ADCC @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813ADD8
	ldr r1, _0813ADD0 @ =0x000004B7
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
	ldr r0, _0813ADD4 @ =0x0000046E
	adds r7, r5, r0
	b _0813AE5A
	.align 2, 0
_0813ADC4: .4byte 0x0000046D
_0813ADC8: .4byte 0x000004C4
_0813ADCC: .4byte 0x0000025D
_0813ADD0: .4byte 0x000004B7
_0813ADD4: .4byte 0x0000046E
_0813ADD8:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0813AE48 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0813AE4C @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0813AE12
	ldrb r0, [r7]
	cmp r0, #0
	bne _0813AE12
	cmp r4, #1
	bne _0813AE04
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0813AE5E
_0813AE04:
	cmp r4, #0
	bne _0813AE12
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0813AE5E
_0813AE12:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0813AE24
	movs r3, #6
_0813AE24:
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
	beq _0813AE50
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _0813AE58
	.align 2, 0
_0813AE48: .4byte 0x000004B7
_0813AE4C: .4byte 0x0000046E
_0813AE50:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0813AE58:
	str r0, [r6, #8]
_0813AE5A:
	movs r0, #0
	strb r0, [r7]
_0813AE5E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
