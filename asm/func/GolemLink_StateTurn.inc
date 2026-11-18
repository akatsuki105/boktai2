	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	ldr r0, _081B9E60 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B9E64
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B9E66
	.align 2, 0
_081B9E60: .4byte 0x0000046D
_081B9E64:
	movs r0, #0
_081B9E66:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _081B9E74
	b _081BA30E
_081B9E74:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r3, _081B9EC4 @ =0x0000046A
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #6
	beq _081B9EC8
	movs r1, #0x90
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _081B9EC8
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _081B9ED0
	.align 2, 0
_081B9EC4: .4byte 0x0000046A
_081B9EC8:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_081B9ED0:
	cmp r1, #0
	blt _081B9ED8
	asrs r0, r1, #1
	b _081B9EDE
_081B9ED8:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081B9EDE:
	cmp r2, r0
	bne _081B9F4A
	ldr r2, _081B9F30 @ =0x0000046B
	adds r0, r5, r2
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081B9F40
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081B9F34 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081B9F38 @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081B9F3C @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	b _081BA470
	.align 2, 0
_081B9F30: .4byte 0x0000046B
_081B9F34: .4byte 0x00000469
_081B9F38: .4byte 0x0000046A
_081B9F3C: .4byte 0x000005BC
_081B9F40:
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _081BA4D4
_081B9F4A:
	cmp r2, #1
	beq _081BA028
	cmp r2, #1
	bgt _081B9F58
	cmp r2, #0
	beq _081B9F66
	b _081BA306
_081B9F58:
	cmp r2, #2
	bne _081B9F5E
	b _081BA0F8
_081B9F5E:
	cmp r2, #3
	bne _081B9F64
	b _081BA1E4
_081B9F64:
	b _081BA306
_081B9F66:
	subs r0, r1, #2
	cmp r0, #3
	bhi _081B9FB8
	movs r2, #2
	ldr r3, _081B9F8C @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _081B9F94
	ldr r1, _081B9F90 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _081BA206
	.align 2, 0
_081B9F8C: .4byte 0x0000025D
_081B9F90: .4byte 0x000004B7
_081B9F94:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #3
	ldr r3, _081B9FB0 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081B9FB4 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	beq _081B9FAE
	b _081BA242
_081B9FAE:
	b _081BA232
	.align 2, 0
_081B9FB0: .4byte 0x000004B7
_081B9FB4: .4byte 0x0000046E
_081B9FB8:
	movs r1, #2
	ldr r2, _081B9FE0 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B9FE8
	ldr r3, _081B9FE4 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	b _081BA00E
	.align 2, 0
_081B9FE0: .4byte 0x0000025D
_081B9FE4: .4byte 0x000004B7
_081B9FE8:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r2, _081BA020 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #2
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081BA00E:
	ldr r3, _081BA024 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _081BA2FE
	.align 2, 0
_081BA020: .4byte 0x000004B7
_081BA024: .4byte 0x0000046E
_081BA028:
	subs r0, r1, #4
	cmp r0, #3
	bhi _081BA088
	movs r2, #2
	ldr r1, _081BA050 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081BA058
	ldr r1, _081BA054 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _081BA206
	.align 2, 0
_081BA050: .4byte 0x0000025D
_081BA054: .4byte 0x000004B7
_081BA058:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #4
	ldr r3, _081BA080 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081BA084 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #4
	beq _081BA072
	b _081BA242
_081BA072:
	ldrb r0, [r6]
	cmp r0, #0
	beq _081BA07A
	b _081BA242
_081BA07A:
	ldr r0, [r4, #8]
	ands r0, r2
	b _081BA23E
	.align 2, 0
_081BA080: .4byte 0x000004B7
_081BA084: .4byte 0x0000046E
_081BA088:
	movs r1, #2
	ldr r2, _081BA0B0 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA0B8
	ldr r3, _081BA0B4 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl AuxAnim_SetAnim
	b _081BA0E0
	.align 2, 0
_081BA0B0: .4byte 0x0000025D
_081BA0B4: .4byte 0x000004B7
_081BA0B8:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _081BA0F0 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #3
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081BA0E0:
	ldr r3, _081BA0F4 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _081BA2FE
	.align 2, 0
_081BA0F0: .4byte 0x000004B7
_081BA0F4: .4byte 0x0000046E
_081BA0F8:
	subs r0, r1, #1
	cmp r0, #4
	bls _081BA174
	movs r1, #2
	ldr r2, _081BA128 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA130
	ldr r3, _081BA12C @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #5
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl AuxAnim_SetAnim
	b _081BA156
	.align 2, 0
_081BA128: .4byte 0x0000025D
_081BA12C: .4byte 0x000004B7
_081BA130:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _081BA16C @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #3
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #8]
_081BA156:
	ldr r3, _081BA170 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	b _081BA26C
	.align 2, 0
_081BA16C: .4byte 0x000004B7
_081BA170: .4byte 0x0000046E
_081BA174:
	movs r2, #4
	ldr r1, _081BA19C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA1A4
	ldr r3, _081BA1A0 @ =0x000004B7
	adds r1, r5, r3
	movs r0, #2
	strb r0, [r1]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r2, [sp]
	movs r2, #2
	movs r3, #2
	bl AuxAnim_SetAnim
	b _081BA1CA
	.align 2, 0
_081BA19C: .4byte 0x0000025D
_081BA1A0: .4byte 0x000004B7
_081BA1A4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r1, _081BA1DC @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #4
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081BA1CA:
	ldr r2, _081BA1E0 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r5, r3
	b _081BA2FE
	.align 2, 0
_081BA1DC: .4byte 0x000004B7
_081BA1E0: .4byte 0x0000046E
_081BA1E4:
	cmp r1, #3
	bhi _081BA27C
	movs r2, #2
	ldr r1, _081BA210 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081BA21C
	ldr r1, _081BA214 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_081BA206:
	bl AuxAnim_SetAnim
	ldr r2, _081BA218 @ =0x0000046E
	adds r6, r5, r2
	b _081BA25E
	.align 2, 0
_081BA210: .4byte 0x0000025D
_081BA214: .4byte 0x000004B7
_081BA218: .4byte 0x0000046E
_081BA21C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _081BA274 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081BA278 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #2
	bne _081BA242
_081BA232:
	ldrb r0, [r6]
	cmp r0, #0
	bne _081BA242
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
_081BA23E:
	cmp r0, #0
	beq _081BA262
_081BA242:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081BA25E:
	movs r0, #0
	strb r0, [r6]
_081BA262:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
_081BA26C:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081BA306
	.align 2, 0
_081BA274: .4byte 0x000004B7
_081BA278: .4byte 0x0000046E
_081BA27C:
	movs r2, #2
	ldr r1, _081BA2A8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA2B4
	ldr r3, _081BA2AC @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl AuxAnim_SetAnim
	ldr r0, _081BA2B0 @ =0x0000046E
	adds r6, r5, r0
	b _081BA2F4
	.align 2, 0
_081BA2A8: .4byte 0x0000025D
_081BA2AC: .4byte 0x000004B7
_081BA2B0: .4byte 0x0000046E
_081BA2B4:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #3
	ldr r1, _081BA340 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081BA344 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	bne _081BA2DC
	ldrb r0, [r6]
	cmp r0, #0
	bne _081BA2DC
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BA2F8
_081BA2DC:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
_081BA2F4:
	movs r0, #0
	strb r0, [r6]
_081BA2F8:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
_081BA2FE:
	ldr r1, _081BA348 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081BA306:
	ldr r2, _081BA344 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_081BA30E:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne _081BA370
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r1, r0, #5
	adds r0, r1, #0
	mov r3, r8
	ldrb r2, [r3, #5]
	subs r0, r2, r0
	cmp r0, #0
	bge _081BA336
	rsbs r0, r0, #0
_081BA336:
	cmp r0, #0x16
	bgt _081BA34C
	mov r0, r8
	strb r1, [r0, #5]
	b _081BA370
	.align 2, 0
_081BA340: .4byte 0x000004B7
_081BA344: .4byte 0x0000046E
_081BA348: .4byte 0xFFFEFFFF
_081BA34C:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081BA368
	adds r0, r2, #0
	adds r0, #0x16
	mov r1, r8
	strb r0, [r1, #5]
	b _081BA370
_081BA368:
	adds r0, r2, #0
	subs r0, #0x16
	mov r2, r8
	strb r0, [r2, #5]
_081BA370:
	ldr r1, _081BA388 @ =0x0000A02F
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081BA390
	ldr r0, _081BA38C @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BA3A0
	.align 2, 0
_081BA388: .4byte 0x0000A02F
_081BA38C: .4byte 0x00000482
_081BA390:
	ldr r1, _081BA3C4 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BA3A0
	movs r0, #1
	strh r0, [r2]
_081BA3A0:
	ldr r3, _081BA3C8 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA3CC
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
	b _081BA3E4
	.align 2, 0
_081BA3C4: .4byte 0x00000482
_081BA3C8: .4byte 0x0000025D
_081BA3CC:
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
_081BA3E4:
	ldr r1, _081BA494 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081BA4D4
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0
	bge _081BA40E
	rsbs r1, r1, #0
_081BA40E:
	cmp r1, #0
	bgt _081BA4A4
	ldr r1, _081BA498 @ =0x0000046B
	adds r0, r5, r1
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r7, #3
	ands r0, r7
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081BA4D4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081BA49C @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081BA4A0 @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r3, #0x17
_081BA470:
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	b _081BA4D4
	.align 2, 0
_081BA494: .4byte 0x0000046E
_081BA498: .4byte 0x0000046B
_081BA49C: .4byte 0x0000046A
_081BA4A0: .4byte 0x000005BC
_081BA4A4:
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _081BA4E4 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081BA4E8 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081BA4D4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BA4E4: .4byte 0x0000046D
_081BA4E8: .4byte 0x0000046B
