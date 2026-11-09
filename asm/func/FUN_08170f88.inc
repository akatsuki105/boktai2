	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _08170FA4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08170FA8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08170FAA
	.align 2, 0
_08170FA4: .4byte 0x0000046D
_08170FA8:
	movs r0, #0
_08170FAA:
	cmp r0, #0
	beq _08171096
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Sandworm_GetAnimVariant
	ldr r1, _08170FF0 @ =0x00000504
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08170FF4 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08171000
	ldr r1, _08170FF8 @ =0x000004B7
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
	ldr r0, _08170FFC @ =0x0000046E
	adds r7, r5, r0
	b _08171082
	.align 2, 0
_08170FF0: .4byte 0x00000504
_08170FF4: .4byte 0x0000025D
_08170FF8: .4byte 0x000004B7
_08170FFC: .4byte 0x0000046E
_08171000:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08171070 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08171074 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0817103A
	ldrb r0, [r7]
	cmp r0, #0
	bne _0817103A
	cmp r4, #1
	bne _0817102C
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08171086
_0817102C:
	cmp r4, #0
	bne _0817103A
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08171086
_0817103A:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0817104C
	movs r3, #6
_0817104C:
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
	beq _08171078
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08171080
	.align 2, 0
_08171070: .4byte 0x000004B7
_08171074: .4byte 0x0000046E
_08171078:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08171080:
	str r0, [r6, #8]
_08171082:
	movs r0, #0
	strb r0, [r7]
_08171086:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	b _0817117C
_08171096:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Sandworm_GetAnimVariant
	ldr r1, _081710D8 @ =0x00000504
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _081710DC @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081710E8
	ldr r1, _081710E0 @ =0x000004B7
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
	ldr r0, _081710E4 @ =0x0000046E
	adds r7, r5, r0
	b _0817116A
	.align 2, 0
_081710D8: .4byte 0x00000504
_081710DC: .4byte 0x0000025D
_081710E0: .4byte 0x000004B7
_081710E4: .4byte 0x0000046E
_081710E8:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08171158 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0817115C @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08171122
	ldrb r0, [r7]
	cmp r0, #0
	bne _08171122
	cmp r4, #1
	bne _08171114
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0817116E
_08171114:
	cmp r4, #0
	bne _08171122
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0817116E
_08171122:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08171134
	movs r3, #6
_08171134:
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
	beq _08171160
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08171168
	.align 2, 0
_08171158: .4byte 0x000004B7
_0817115C: .4byte 0x0000046E
_08171160:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08171168:
	str r0, [r6, #8]
_0817116A:
	movs r0, #0
	strb r0, [r7]
_0817116E:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
_0817117C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
