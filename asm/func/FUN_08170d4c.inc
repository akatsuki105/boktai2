	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _08170D68 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08170D6C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08170D6E
	.align 2, 0
_08170D68: .4byte 0x0000046D
_08170D6C:
	movs r0, #0
_08170D6E:
	cmp r0, #0
	beq _08170E56
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Sandworm_GetAnimVariant
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08170DB4 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08170DC0
	ldr r1, _08170DB8 @ =0x000004B7
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
	ldr r0, _08170DBC @ =0x0000046E
	adds r7, r5, r0
	b _08170E42
	.align 2, 0
_08170DB4: .4byte 0x0000025D
_08170DB8: .4byte 0x000004B7
_08170DBC: .4byte 0x0000046E
_08170DC0:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08170E30 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08170E34 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08170DFA
	ldrb r0, [r7]
	cmp r0, #0
	bne _08170DFA
	cmp r4, #1
	bne _08170DEC
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08170E46
_08170DEC:
	cmp r4, #0
	bne _08170DFA
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08170E46
_08170DFA:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08170E0C
	movs r3, #6
_08170E0C:
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
	beq _08170E38
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08170E40
	.align 2, 0
_08170E30: .4byte 0x000004B7
_08170E34: .4byte 0x0000046E
_08170E38:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08170E40:
	str r0, [r6, #8]
_08170E42:
	movs r0, #0
	strb r0, [r7]
_08170E46:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	b _08170F6E
_08170E56:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Sandworm_GetAnimVariant
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08170E98 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08170EA4
	ldr r1, _08170E9C @ =0x000004B7
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
	ldr r0, _08170EA0 @ =0x0000046E
	adds r7, r5, r0
	b _08170F26
	.align 2, 0
_08170E98: .4byte 0x0000025D
_08170E9C: .4byte 0x000004B7
_08170EA0: .4byte 0x0000046E
_08170EA4:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08170F14 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08170F18 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08170EDE
	ldrb r0, [r7]
	cmp r0, #0
	bne _08170EDE
	cmp r4, #1
	bne _08170ED0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08170F2A
_08170ED0:
	cmp r4, #0
	bne _08170EDE
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08170F2A
_08170EDE:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08170EF0
	movs r3, #6
_08170EF0:
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
	beq _08170F1C
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08170F24
	.align 2, 0
_08170F14: .4byte 0x000004B7
_08170F18: .4byte 0x0000046E
_08170F1C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08170F24:
	str r0, [r6, #8]
_08170F26:
	movs r0, #0
	strb r0, [r7]
_08170F2A:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _08170F6E
	ldr r4, _08170F7C @ =FUN_08170f88
	movs r3, #0x28
	ldr r0, _08170F80 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08170F84 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08170F6E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08170F7C: .4byte FUN_08170f88
_08170F80: .4byte 0x0000046D
_08170F84: .4byte 0x0000046B
