	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	mov r8, r5
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov sl, r0
	ldr r2, _08152DDC @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08152DE0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08152DE2
	.align 2, 0
_08152DDC: .4byte 0x0000046D
_08152DE0:
	movs r0, #0
_08152DE2:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r3, r5
	mov sb, r3
	cmp r0, #0
	bne _08152DF0
	b _0815326A
_08152DF0:
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
	adds r3, r0, #1
	ands r3, r1
	ldr r1, _08152E3C @ =0x0000046A
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08152E68
	adds r1, #0x16
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _08152E68
	movs r1, #0x20
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08152E40
	movs r0, #1
	b _08152E42
	.align 2, 0
_08152E3C: .4byte 0x0000046A
_08152E40:
	movs r0, #0
_08152E42:
	cmp r0, #0
	bne _08152E68
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	cmp r0, #0
	blt _08152E56
	asrs r0, r0, #0xc
	b _08152E5C
_08152E56:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08152E5C:
	adds r1, r0, #0
	movs r2, #0xee
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	b _08152E70
_08152E68:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_08152E70:
	cmp r1, #0
	blt _08152E78
	asrs r0, r1, #1
	b _08152E7E
_08152E78:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08152E7E:
	cmp r3, r0
	bne _08152EC6
	ldr r2, _08152EB0 @ =0x0000046B
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
	beq _08152EBC
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r1, _08152EB4 @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	ldr r3, _08152EB8 @ =0x0000046D
	b _081533D0
	.align 2, 0
_08152EB0: .4byte 0x0000046B
_08152EB4: .4byte 0x000005BC
_08152EB8: .4byte 0x0000046D
_08152EBC:
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _08153434
_08152EC6:
	cmp r3, #1
	beq _08152FA4
	cmp r3, #1
	bgt _08152ED4
	cmp r3, #0
	beq _08152EE2
	b _08153262
_08152ED4:
	cmp r3, #2
	bne _08152EDA
	b _08153064
_08152EDA:
	cmp r3, #3
	bne _08152EE0
	b _08153144
_08152EE0:
	b _08153262
_08152EE2:
	subs r0, r1, #2
	cmp r0, #3
	bhi _08152F34
	movs r2, #1
	ldr r1, _08152F08 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08152F10
	ldr r1, _08152F0C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _08153166
	.align 2, 0
_08152F08: .4byte 0x0000025D
_08152F0C: .4byte 0x000004B7
_08152F10:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #2
	ldr r3, _08152F2C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08152F30 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #2
	beq _08152F2A
	b _081531A2
_08152F2A:
	b _08153192
	.align 2, 0
_08152F2C: .4byte 0x000004B7
_08152F30: .4byte 0x0000046E
_08152F34:
	movs r1, #1
	ldr r2, _08152F5C @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08152F64
	ldr r3, _08152F60 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
	b _08152F8A
	.align 2, 0
_08152F5C: .4byte 0x0000025D
_08152F60: .4byte 0x000004B7
_08152F64:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r2, _08152F9C @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #1
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_08152F8A:
	ldr r3, _08152FA0 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _0815325A
	.align 2, 0
_08152F9C: .4byte 0x000004B7
_08152FA0: .4byte 0x0000046E
_08152FA4:
	subs r0, r1, #4
	cmp r0, #3
	bhi _08152FF8
	ldr r1, _08152FCC @ =0x0000025D
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _08152FD4
	ldr r1, _08152FD0 @ =0x000004B7
	adds r0, r5, r1
	strb r3, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r2, [sp]
	movs r2, #1
	movs r3, #2
	b _08153166
	.align 2, 0
_08152FCC: .4byte 0x0000025D
_08152FD0: .4byte 0x000004B7
_08152FD4:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #3
	ldr r3, _08152FF0 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08152FF4 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	beq _08152FEE
	b _081531A2
_08152FEE:
	b _08153192
	.align 2, 0
_08152FF0: .4byte 0x000004B7
_08152FF4: .4byte 0x0000046E
_08152FF8:
	ldr r1, _08153020 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153028
	ldr r2, _08153024 @ =0x000004B7
	adds r0, r5, r2
	strb r3, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #1
	movs r3, #1
	bl AuxAnim_SetAnim
	b _08153050
	.align 2, 0
_08153020: .4byte 0x0000025D
_08153024: .4byte 0x000004B7
_08153028:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #2
	ldr r3, _0815305C @ =0x000004B7
	adds r0, r5, r3
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
_08153050:
	ldr r0, _08153060 @ =0x0000046E
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _08153254
	.align 2, 0
_0815305C: .4byte 0x000004B7
_08153060: .4byte 0x0000046E
_08153064:
	subs r0, r1, #1
	cmp r0, #4
	bls _081530D4
	ldr r2, _08153094 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815309C
	ldr r3, _08153098 @ =0x000004B7
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #5
	str r2, [sp]
	movs r2, #1
	movs r3, #1
	bl AuxAnim_SetAnim
	b _081530C0
	.align 2, 0
_08153094: .4byte 0x0000025D
_08153098: .4byte 0x000004B7
_0815309C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r1, _081530CC @ =0x000004B7
	adds r0, r5, r1
	strb r3, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #2
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #8]
_081530C0:
	ldr r2, _081530D0 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	b _081531C2
	.align 2, 0
_081530CC: .4byte 0x000004B7
_081530D0: .4byte 0x0000046E
_081530D4:
	movs r1, #1
	ldr r2, _081530FC @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153104
	ldr r3, _08153100 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #1
	movs r3, #2
	bl AuxAnim_SetAnim
	b _0815312C
	.align 2, 0
_081530FC: .4byte 0x0000025D
_08153100: .4byte 0x000004B7
_08153104:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _0815313C @ =0x000004B7
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
_0815312C:
	ldr r3, _08153140 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _0815325A
	.align 2, 0
_0815313C: .4byte 0x000004B7
_08153140: .4byte 0x0000046E
_08153144:
	cmp r1, #3
	bhi _081531DC
	movs r2, #1
	ldr r1, _08153170 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0815317C
	ldr r1, _08153174 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_08153166:
	bl AuxAnim_SetAnim
	ldr r2, _08153178 @ =0x0000046E
	adds r6, r5, r2
	b _081531BE
	.align 2, 0
_08153170: .4byte 0x0000025D
_08153174: .4byte 0x000004B7
_08153178: .4byte 0x0000046E
_0815317C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _081531D4 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081531D8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #1
	bne _081531A2
_08153192:
	ldrb r0, [r6]
	cmp r0, #0
	bne _081531A2
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081531C2
_081531A2:
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
_081531BE:
	movs r0, #0
	strb r0, [r6]
_081531C2:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08153262
	.align 2, 0
_081531D4: .4byte 0x000004B7
_081531D8: .4byte 0x0000046E
_081531DC:
	movs r2, #1
	ldr r1, _08153204 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153210
	ldr r3, _08153208 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r2, [sp]
	movs r3, #1
	bl AuxAnim_SetAnim
	ldr r0, _0815320C @ =0x0000046E
	adds r6, r5, r0
	b _08153250
	.align 2, 0
_08153204: .4byte 0x0000025D
_08153208: .4byte 0x000004B7
_0815320C: .4byte 0x0000046E
_08153210:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #2
	ldr r1, _081532A0 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081532A4 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #2
	bne _08153238
	ldrb r0, [r6]
	cmp r0, #0
	bne _08153238
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08153254
_08153238:
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
_08153250:
	movs r0, #0
	strb r0, [r6]
_08153254:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
_0815325A:
	ldr r1, _081532A8 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08153262:
	ldr r2, _081532A4 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_0815326A:
	mov r3, sl
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _081532D0
	ldrh r0, [r3, #8]
	cmp r0, #0
	beq _081532D0
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
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
	bge _08153296
	rsbs r0, r0, #0
_08153296:
	cmp r0, #0x10
	bgt _081532AC
	mov r0, r8
	strb r1, [r0, #5]
	b _081532D0
	.align 2, 0
_081532A0: .4byte 0x000004B7
_081532A4: .4byte 0x0000046E
_081532A8: .4byte 0xFFFEFFFF
_081532AC:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081532C8
	adds r0, r2, #0
	adds r0, #0x10
	mov r1, r8
	strb r0, [r1, #5]
	b _081532D0
_081532C8:
	adds r0, r2, #0
	subs r0, #0x10
	mov r2, r8
	strb r0, [r2, #5]
_081532D0:
	ldr r1, _081532E8 @ =0x0000A02F
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081532F0
	ldr r0, _081532EC @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08153300
	.align 2, 0
_081532E8: .4byte 0x0000A02F
_081532EC: .4byte 0x00000482
_081532F0:
	ldr r1, _08153324 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08153300
	movs r0, #1
	strh r0, [r2]
_08153300:
	ldr r3, _08153328 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815332C
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
	b _08153344
	.align 2, 0
_08153324: .4byte 0x00000482
_08153328: .4byte 0x0000025D
_0815332C:
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
_08153344:
	ldr r1, _081533F4 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08153434
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
	bge _0815336E
	rsbs r1, r1, #0
_0815336E:
	cmp r1, #0
	bgt _08153404
	ldr r1, _081533F8 @ =0x0000046B
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
	beq _08153434
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081533FC @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _08153400 @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r3, #0x17
_081533D0:
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
	b _08153434
	.align 2, 0
_081533F4: .4byte 0x0000046E
_081533F8: .4byte 0x0000046B
_081533FC: .4byte 0x0000046A
_08153400: .4byte 0x000005BC
_08153404:
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _08153444 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08153448 @ =0x0000046B
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
_08153434:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08153444: .4byte 0x0000046D
_08153448: .4byte 0x0000046B
