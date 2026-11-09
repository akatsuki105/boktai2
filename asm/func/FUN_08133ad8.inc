	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _08133B00 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08133B04
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08133B06
	.align 2, 0
_08133B00: .4byte 0x0000046D
_08133B04:
	movs r0, #0
_08133B06:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r6
	mov sb, r1
	cmp r0, #0
	beq _08133B64
	adds r0, r6, #0
	bl FUN_0813a160
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, #4
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	strb r0, [r6, #5]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08133BA8 @ =0xFFEFFFFF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb3
	lsls r0, r0, #4
	adds r2, r4, r0
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08133BAC @ =0x000003D6
	bl PlaySound_082406e0
_08133B64:
	ldrb r0, [r6, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Centipede_GetAnimVariant
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08133BB0 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08133BBC
	ldr r1, _08133BB4 @ =0x000004B7
	adds r0, r6, r1
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
	ldr r2, _08133BB8 @ =0x0000046E
	adds r7, r6, r2
	b _08133C3E
	.align 2, 0
_08133BA8: .4byte 0xFFEFFFFF
_08133BAC: .4byte 0x000003D6
_08133BB0: .4byte 0x0000025D
_08133BB4: .4byte 0x000004B7
_08133BB8: .4byte 0x0000046E
_08133BBC:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, _08133C2C @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08133C30 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, r2
	bne _08133BF6
	ldrb r0, [r7]
	cmp r0, #0
	bne _08133BF6
	cmp r4, #1
	bne _08133BE8
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08133C42
_08133BE8:
	cmp r4, #0
	bne _08133BF6
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08133C42
_08133BF6:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08133C08
	movs r3, #6
_08133C08:
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
	beq _08133C34
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _08133C3C
	.align 2, 0
_08133C2C: .4byte 0x000004B7
_08133C30: .4byte 0x0000046E
_08133C34:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08133C3C:
	str r0, [r5, #8]
_08133C3E:
	movs r0, #0
	strb r0, [r7]
_08133C42:
	adds r0, r6, #0
	movs r1, #0x12
	movs r2, #6
	movs r3, #0
	bl FUN_08136de4
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0813632c
	movs r1, #0x10
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08133CB4
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08133CA4 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r4, _08133CA8 @ =FUN_08133cd4
	movs r2, #0x24
	ldr r0, _08133CAC @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08133CB0 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	b _08133CC4
	.align 2, 0
_08133CA4: .4byte 0xFFFFFEFF
_08133CA8: .4byte FUN_08133cd4
_08133CAC: .4byte 0x0000046D
_08133CB0: .4byte 0x0000046B
_08133CB4:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08133CC4:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
