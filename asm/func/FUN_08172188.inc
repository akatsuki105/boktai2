	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _081721F0 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081721A6
	movs r0, #0
	strb r0, [r1]
_081721A6:
	ldrb r0, [r6, #5]
	add r4, sp, #8
	add r1, sp, #4
	adds r2, r4, #0
	bl Sandworm_GetAnimVariant
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r7, [sp, #8]
	ldr r1, _081721F4 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	bne _08172200
	ldr r0, _081721F8 @ =0x000004B7
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
	ldr r1, _081721FC @ =0x0000046E
	adds r1, r1, r6
	mov sb, r1
	b _08172282
	.align 2, 0
_081721F0: .4byte 0x0000046D
_081721F4: .4byte 0x0000025D
_081721F8: .4byte 0x000004B7
_081721FC: .4byte 0x0000046E
_08172200:
	ldr r0, [r6, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, r2, r3
	ldr r1, _08172270 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	mov r8, r0
	ldr r0, _08172274 @ =0x0000046E
	adds r0, r0, r6
	mov sb, r0
	cmp r1, r2
	bne _0817223C
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817223C
	cmp r7, #1
	bne _0817222E
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08172288
_0817222E:
	cmp r7, #0
	bne _0817223C
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08172288
_0817223C:
	mov r1, r8
	strb r2, [r1]
	movs r5, #4
	adds r0, r7, #0
	ands r0, r5
	movs r3, #4
	cmp r0, #0
	beq _0817224E
	movs r3, #6
_0817224E:
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
	beq _08172278
	ldr r0, [r4, #8]
	orrs r0, r5
	b _08172280
	.align 2, 0
_08172270: .4byte 0x000004B7
_08172274: .4byte 0x0000046E
_08172278:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08172280:
	str r0, [r4, #8]
_08172282:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_08172288:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_081770d0
	movs r3, #0xc8
	lsls r3, r3, #7
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_08177d34
	ldr r0, [sp, #0xc]
	cmp r0, #0x28
	ble _08172370
	ldrb r0, [r6, #5]
	add r1, sp, #4
	add r2, sp, #8
	bl Sandworm_GetAnimVariant
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _081722E4
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
	b _08172354
_081722E4:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, r2
	bne _08172318
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _08172318
	cmp r4, #1
	bne _0817230A
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0817235A
_0817230A:
	cmp r4, #0
	bne _08172318
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0817235A
_08172318:
	mov r0, r8
	strb r2, [r0]
	movs r7, #4
	adds r0, r4, #0
	ands r0, r7
	movs r3, #4
	cmp r0, #0
	beq _0817232A
	movs r3, #6
_0817232A:
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
	beq _0817234A
	ldr r0, [r5, #8]
	orrs r0, r7
	b _08172352
_0817234A:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08172352:
	str r0, [r5, #8]
_08172354:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_0817235A:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_08176ed4
	ldr r0, _08172380 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_08172370:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08172380: .4byte 0x0000046B
