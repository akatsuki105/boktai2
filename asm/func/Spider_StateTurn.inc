	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r5, #0
	ldr r0, _0812EAD0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812EAD4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812EAD6
	.align 2, 0
_0812EAD0: .4byte 0x0000046D
_0812EAD4:
	movs r0, #0
_0812EAD6:
	cmp r0, #0
	bne _0812EADC
	b _0812ECDC
_0812EADC:
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r7, #5]
	ldrb r0, [r7, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	asrs r0, r0, #1
	cmp r2, r0
	beq _0812EB18
	subs r0, r0, r2
	cmp r0, #0
	bge _0812EB14
	rsbs r0, r0, #0
_0812EB14:
	cmp r0, #2
	beq _0812EB30
_0812EB18:
	ldr r2, _0812EB2C @ =0x0000046B
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _0812EDE8
	.align 2, 0
_0812EB2C: .4byte 0x0000046B
_0812EB30:
	cmp r2, #1
	beq _0812EB94
	cmp r2, #1
	bgt _0812EB3E
	cmp r2, #0
	beq _0812EB4A
	b _0812ECDC
_0812EB3E:
	cmp r2, #2
	beq _0812EC1C
	cmp r2, #3
	bne _0812EB48
	b _0812EC80
_0812EB48:
	b _0812ECDC
_0812EB4A:
	movs r2, #5
	ldr r1, _0812EB6C @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0812EB74
	ldr r1, _0812EB70 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
	b _0812EBB2
	.align 2, 0
_0812EB6C: .4byte 0x0000025D
_0812EB70: .4byte 0x000004B7
_0812EB74:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	ldr r1, _0812EB8C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0812EB90 @ =0x0000046E
	adds r4, r5, r0
	cmp r1, #5
	bne _0812EBF0
	b _0812EBE0
	.align 2, 0
_0812EB8C: .4byte 0x000004B7
_0812EB90: .4byte 0x0000046E
_0812EB94:
	movs r2, #5
	ldr r1, _0812EBBC @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0812EBC8
	ldr r1, _0812EBC0 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
_0812EBB2:
	bl AuxAnim_SetAnim
	ldr r2, _0812EBC4 @ =0x0000046E
	adds r4, r5, r2
	b _0812EC0C
	.align 2, 0
_0812EBBC: .4byte 0x0000025D
_0812EBC0: .4byte 0x000004B7
_0812EBC4: .4byte 0x0000046E
_0812EBC8:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	movs r2, #6
	ldr r1, _0812EC14 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0812EC18 @ =0x0000046E
	adds r4, r5, r0
	cmp r1, #6
	bne _0812EBF0
_0812EBE0:
	ldrb r0, [r4]
	cmp r0, #0
	bne _0812EBF0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0812ECDC
_0812EBF0:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
_0812EC0C:
	movs r0, #0
	strb r0, [r4]
	b _0812ECDC
	.align 2, 0
_0812EC14: .4byte 0x000004B7
_0812EC18: .4byte 0x0000046E
_0812EC1C:
	movs r1, #5
	ldr r2, _0812EC44 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812EC4C
	ldr r2, _0812EC48 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #5
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0812EC72
	.align 2, 0
_0812EC44: .4byte 0x0000025D
_0812EC48: .4byte 0x000004B7
_0812EC4C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r2, _0812EC78 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #5
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0812EC72:
	ldr r0, _0812EC7C @ =0x0000046E
	adds r1, r5, r0
	b _0812ECD8
	.align 2, 0
_0812EC78: .4byte 0x000004B7
_0812EC7C: .4byte 0x0000046E
_0812EC80:
	movs r2, #5
	ldr r1, _0812ECA8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812ECB0
	ldr r1, _0812ECAC @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #5
	movs r3, #1
	bl AuxAnim_SetAnim
	b _0812ECD4
	.align 2, 0
_0812ECA8: .4byte 0x0000025D
_0812ECAC: .4byte 0x000004B7
_0812ECB0:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r2, #6
	ldr r1, _0812ED0C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0812ECD4:
	ldr r2, _0812ED10 @ =0x0000046E
	adds r1, r5, r2
_0812ECD8:
	movs r0, #0
	strb r0, [r1]
_0812ECDC:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne _0812ED3E
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	adds r2, r4, #0
	ldrb r0, [r7, #5]
	subs r1, r0, r2
	adds r3, r1, #0
	cmp r1, #0
	bge _0812ED04
	rsbs r3, r1, #0
_0812ED04:
	cmp r3, #0x40
	bgt _0812ED14
	strb r4, [r7, #5]
	b _0812ED3E
	.align 2, 0
_0812ED0C: .4byte 0x000004B7
_0812ED10: .4byte 0x0000046E
_0812ED14:
	cmp r0, r2
	bge _0812ED28
	adds r2, r1, #0
	cmp r1, #0
	bge _0812ED20
	rsbs r2, r1, #0
_0812ED20:
	cmp r2, #0x80
	ble _0812ED3A
	subs r0, #0x40
	b _0812ED3C
_0812ED28:
	cmp r0, r2
	ble _0812ED3E
	cmp r1, #0
	bge _0812ED32
	rsbs r1, r1, #0
_0812ED32:
	cmp r1, #0x80
	bgt _0812ED3A
	subs r0, #0x40
	b _0812ED3C
_0812ED3A:
	adds r0, #0x40
_0812ED3C:
	strb r0, [r7, #5]
_0812ED3E:
	ldr r1, _0812ED5C @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812ED64
	ldr r0, _0812ED60 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0812ED74
	.align 2, 0
_0812ED5C: .4byte 0x0000A02F
_0812ED60: .4byte 0x00000482
_0812ED64:
	ldr r1, _0812ED98 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0812ED74
	movs r0, #1
	strh r0, [r2]
_0812ED74:
	ldr r1, _0812ED9C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812EDA0
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _0812EDB8
	.align 2, 0
_0812ED98: .4byte 0x00000482
_0812ED9C: .4byte 0x0000025D
_0812EDA0:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_0812EDB8:
	ldr r2, _0812EDF0 @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0812EDE8
	ldr r0, _0812EDF4 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldrb r1, [r5, #5]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
_0812EDE8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812EDF0: .4byte 0x0000046E
_0812EDF4: .4byte 0x0000046B
