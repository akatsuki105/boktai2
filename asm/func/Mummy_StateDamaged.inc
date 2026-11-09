	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xd8
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _08123AB0 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08123AB4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08123AB6
	.align 2, 0
_08123AB0: .4byte 0x0000046D
_08123AB4:
	movs r0, #0
_08123AB6:
	cmp r0, #0
	beq _08123B32
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _08123ACC
	asrs r1, r0, #2
	b _08123AD2
_08123ACC:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_08123AD2:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08123AEC
	asrs r1, r0, #2
	b _08123AF2
_08123AEC:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_08123AF2:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r1, #8
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r4, r7, r3
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08123B20
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0xfd
	bl PlaySound_082406e0
_08123B20:
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r4, _08123C04 @ =0x0000046E
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
_08123B32:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #9
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	str r2, [sp, #0x94]
	cmp r6, #0x11
	bgt _08123B72
	ldrh r3, [r5, #8]
	cmp r3, #0
	bne _08123B72
	ldrh r1, [r5, #0xe]
	ldrb r2, [r5, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _08123B72
	cmp r2, #1
	beq _08123B72
	strh r3, [r5, #0xe]
_08123B72:
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _08123BE4
	movs r1, #8
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08123BE4
	ldr r2, _08123C08 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _08123C0C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r2, _08123C10 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08123C14 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _08123C18 @ =0x0203B400
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r2, #0xa
	str r2, [sp]
	movs r2, #6
	str r2, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	add r2, sp, #0x10
	bl EmitSmoke
_08123BE4:
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r4, #0x85
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _08123C1C
	asrs r0, r0, #2
	b _08123C22
	.align 2, 0
_08123C04: .4byte 0x0000046E
_08123C08: .4byte 0xFFFF0000
_08123C0C: .4byte 0x0000FFFF
_08123C10: .4byte 0x030046B8
_08123C14: .4byte 0x000003FF
_08123C18: .4byte 0x0203B400
_08123C1C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08123C22:
	adds r3, r0, #0
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r5, #0x86
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _08123C42
	asrs r0, r0, #2
	b _08123C48
_08123C42:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08123C48:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _08123C52
	movs r3, #0xc8
	b _08123C5C
_08123C52:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08123C5C
	adds r3, r0, #0
_08123C5C:
	cmp r2, #0xc8
	ble _08123C64
	movs r2, #0xc8
	b _08123C6E
_08123C64:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08123C6E
	adds r2, r0, #0
_08123C6E:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _08123C92
	cmp r2, #0
	bne _08123C92
	movs r0, #1
	b _08123C94
_08123C92:
	movs r0, #0
_08123C94:
	cmp r0, #0
	bne _08123C9C
	bl _08124CD4
_08123C9C:
	ldr r1, _08123DA4 @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08123CAA
	bl _08124CD4
_08123CAA:
	ldr r2, _08123DA8 @ =0x0000046B
	adds r0, r7, r2
	movs r3, #0
	mov sl, r3
	movs r4, #1
	mov r8, r4
	mov r5, r8
	strb r5, [r0]
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	ldr r0, _08123DAC @ =0xFFFFFEDF
	ldrh r1, [r2]
	ands r0, r1
	movs r6, #0
	strh r0, [r2]
	ldr r5, [sp, #0x94]
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r1, [r5]
	ands r1, r0
	str r1, [r5]
	movs r0, #0x10
	mov sb, r0
	ldrh r3, [r2]
	adds r0, r3, #0
	mov r4, sb
	ands r0, r4
	str r2, [sp, #0x98]
	cmp r0, #0
	beq _08123DCC
	ldr r4, [r7, #0x24]
	ldr r2, _08123DB0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08123DB4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _08123DB8 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	asrs r0, r0, #3
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #2]
	cmp r0, r1
	bne _08123D20
	adds r0, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08123D20:
	strb r0, [r4, #2]
	strb r6, [r4, #3]
	ldr r0, _08123DBC @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, [r4, #4]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #8]
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	movs r1, #8
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r6, [r0]
	ldr r3, _08123DC0 @ =0x00000469
	adds r0, r7, r3
	strb r6, [r0]
	ldr r4, _08123DC4 @ =0x0000046A
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _08123DC8 @ =0x00000484
	adds r0, r7, r5
	mov r1, sl
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	mov r3, r8
	strb r3, [r0]
	movs r4, #0xb5
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r2, [r0]
	movs r1, #0x13
	subs r5, #0x17
	adds r0, r7, r5
	strb r3, [r0]
	ldr r3, _08123DA8 @ =0x0000046B
	adds r0, r7, r3
	strb r6, [r0]
	subs r4, #0x55
	adds r0, r7, r4
	strb r1, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r7, r5
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	mov r1, sl
	strh r1, [r0]
	movs r0, #9
	rsbs r0, r0, #0
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	bl _08124CD4
	.align 2, 0
_08123DA4: .4byte 0x0000046E
_08123DA8: .4byte 0x0000046B
_08123DAC: .4byte 0xFFFFFEDF
_08123DB0: .4byte 0x030046B8
_08123DB4: .4byte 0x000003FF
_08123DB8: .4byte 0x0203B400
_08123DBC: .4byte 0x030046A4
_08123DC0: .4byte 0x00000469
_08123DC4: .4byte 0x0000046A
_08123DC8: .4byte 0x00000484
_08123DCC:
	ldr r4, _08123DF0 @ =0x0000049C
	adds r0, r7, r4
	ldr r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xc
	ands r4, r0
	cmp r4, #0
	beq _08123DF4
	movs r0, #2
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _08124CD4
	.align 2, 0
_08123DF0: .4byte 0x0000049C
_08123DF4:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _08123E74
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08123E60 @ =0x00000469
	adds r0, r7, r3
	strb r6, [r0]
	ldr r5, _08123E64 @ =0x0000046A
	adds r0, r7, r5
	strb r6, [r0]
	ldr r1, _08123E68 @ =0x00000484
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r7, r2
	mov r3, r8
	strb r3, [r0]
	ldr r2, _08123E6C @ =Mummy_StateRecover
	movs r1, #0x14
	adds r5, #3
	adds r0, r7, r5
	strb r3, [r0]
	ldr r3, _08123E70 @ =0x0000046B
	adds r0, r7, r3
	strb r6, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #9
	rsbs r0, r0, #0
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r3, #0x17
	adds r0, r7, r3
	mov r4, r8
	strh r4, [r0]
	bl _08124CD4
	.align 2, 0
_08123E60: .4byte 0x00000469
_08123E64: .4byte 0x0000046A
_08123E68: .4byte 0x00000484
_08123E6C: .4byte Mummy_StateRecover
_08123E70: .4byte 0x0000046B
_08123E74:
	movs r4, #0x80
	ands r3, r4
	lsls r0, r3, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _08123E82
	b _081245AC
_08123E82:
	orrs r1, r4
	str r1, [r5]
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, _08123ED4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r3, r7, r6
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x90]
	str r2, [sp, #0xb8]
	cmp r4, #0
	blt _08123ED0
	cmp r1, #0
	blt _08123ED0
	ldr r0, _08123ED8 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08123ED0
	ldr r0, _08123EDC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08123EE0
_08123ED0:
	movs r4, #0
	b _08123EEE
	.align 2, 0
_08123ED4: .4byte 0x03002BE0
_08123ED8: .4byte 0x030046A8
_08123EDC: .4byte 0x030046AC
_08123EE0:
	ldr r0, _08123F00 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08123EEE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08123F04
	adds r0, #4
	b _08123F10
	.align 2, 0
_08123F00: .4byte 0x030046A4
_08123F04:
	ldr r0, _08123F24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08123F10:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08123F28
	cmp r2, #2
	beq _08123F2C
	b _08123F30
	.align 2, 0
_08123F24: .4byte 0x030046A4
_08123F28:
	ldrb r0, [r5, #4]
	b _08123F2E
_08123F2C:
	ldrb r0, [r5]
_08123F2E:
	subs r1, r1, r0
_08123F30:
	strh r1, [r5, #2]
	ldr r0, _08123F44 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08123F48
	movs r0, #1
	b _08123F4A
	.align 2, 0
_08123F44: .4byte 0x030047A4
_08123F48:
	movs r0, #0
_08123F4A:
	cmp r0, #0
	beq _08123F88
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08123F6A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08123F66
	adds r2, r0, #0
_08123F66:
	cmp r2, #0
	bge _08123F74
_08123F6A:
	ldr r2, _08123F70 @ =0x000005C4
	adds r0, r7, r2
	b _081244A8
	.align 2, 0
_08123F70: .4byte 0x000005C4
_08123F74:
	ldr r1, _08123F84 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08123FD0
	.align 2, 0
_08123F84: .4byte 0x03002BE0
_08123F88:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08123FB4
	cmp r1, #0
	blt _08123FB4
	ldr r0, _08123FB8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08123FB4
	ldr r0, _08123FBC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08123FC0
_08123FB4:
	movs r5, #0
	b _08123FCE
	.align 2, 0
_08123FB8: .4byte 0x030046A8
_08123FBC: .4byte 0x030046AC
_08123FC0:
	ldr r0, _08124008 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08123FCE:
	movs r2, #0
_08123FD0:
	ldr r4, _0812400C @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08123FF0
	ldr r1, _08124010 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08123FF0
	b _081243E4
_08123FF0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x98]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x28]
	cmp r0, #0
	beq _08124014
	movs r0, #0
	b _081244BE
	.align 2, 0
_08124008: .4byte 0x030046A4
_0812400C: .4byte 0x00000256
_08124010: .4byte 0x03002BE0
_08124014:
	ldr r6, _081240BC @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x98]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xb4]
	cmp r6, #0
	beq _081240D4
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _081240C0 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x2c]
	movs r5, #1
	ldr r6, [sp, #0x2c]
	strb r5, [r6]
	ldr r2, _081240C4 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x30]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x34]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x38]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	mov r1, sp
	ldrh r1, [r1, #0x28]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081240C8 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081240CC @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x28]
	str r6, [r1]
	ldr r6, _081240D0 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x2c]
	str r5, [sp, #0xd0]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xc0]
	str r2, [sp, #0xc4]
	str r1, [sp, #0x8c]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0xc8]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xa4]
	ldr r1, [sp, #0x38]
	str r1, [sp, #0xac]
	mov r2, r8
	str r2, [sp, #0xa8]
	b _081242A2
	.align 2, 0
_081240BC: .4byte 0x00000222
_081240C0: .4byte 0x0000046D
_081240C4: .4byte 0x0000046B
_081240C8: .4byte 0x00000469
_081240CC: .4byte 0x00000484
_081240D0: .4byte 0x0000046C
_081240D4:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _08124194 @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _08124198 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x3c]
	movs r2, #0
	strb r2, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x40]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x44]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x48]
	strh r6, [r5]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x4c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _0812419C @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _081241A0 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081241A4 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081241A8 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x90]
	ldr r0, [r0]
	str r0, [sp, #0x50]
	ldr r1, [sp, #0xb8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x50]
	strh r1, [r6]
	ldr r6, [sp, #0xb8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x50]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0xd0]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xbc]
	str r5, [sp, #0xc0]
	str r4, [sp, #0xc4]
	str r3, [sp, #0x8c]
	str r2, [sp, #0xcc]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0xc8]
	ldr r2, [sp, #0x40]
	str r2, [sp, #0xa4]
	ldr r3, [sp, #0x44]
	str r3, [sp, #0xac]
	ldr r4, [sp, #0x48]
	str r4, [sp, #0xa8]
	mov r5, sl
	cmp r5, #0
	blt _08124190
	cmp r1, #0
	blt _08124190
	ldr r0, _081241AC @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _08124190
	ldr r0, _081241B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081241B4
_08124190:
	movs r4, #0
	b _081241C4
	.align 2, 0
_08124194: .4byte 0x0000046D
_08124198: .4byte 0x0000046B
_0812419C: .4byte 0x00000469
_081241A0: .4byte 0x0000046A
_081241A4: .4byte 0x00000484
_081241A8: .4byte 0x0000046C
_081241AC: .4byte 0x030046A8
_081241B0: .4byte 0x030046AC
_081241B4:
	ldr r0, _081241D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, sl
	adds r4, r0, r6
_081241C4:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081241D8
	adds r0, #4
	b _081241E4
	.align 2, 0
_081241D4: .4byte 0x030046A4
_081241D8:
	ldr r0, _081241F8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081241E4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081241FC
	cmp r2, #2
	beq _08124202
	b _08124208
	.align 2, 0
_081241F8: .4byte 0x030046A4
_081241FC:
	ldr r2, [sp, #0x50]
	ldrb r0, [r2, #4]
	b _08124206
_08124202:
	ldr r3, [sp, #0x50]
	ldrb r0, [r3]
_08124206:
	subs r1, r1, r0
_08124208:
	ldr r4, [sp, #0x50]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x90]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08124234
	cmp r1, #0
	blt _08124234
	ldr r0, _08124238 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08124234
	ldr r0, _0812423C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08124240
_08124234:
	movs r4, #0
	b _0812424E
	.align 2, 0
_08124238: .4byte 0x030046A8
_0812423C: .4byte 0x030046AC
_08124240:
	ldr r0, _08124264 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812424E:
	ldr r6, [sp, #0x90]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08124268
	adds r0, #4
	b _08124274
	.align 2, 0
_08124264: .4byte 0x030046A4
_08124268:
	ldr r0, _08124288 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08124274:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0812428C
	cmp r3, #2
	beq _08124290
	b _08124294
	.align 2, 0
_08124288: .4byte 0x030046A4
_0812428C:
	ldrb r0, [r5, #4]
	b _08124292
_08124290:
	ldrb r0, [r5]
_08124292:
	subs r2, r2, r0
_08124294:
	ldr r1, [sp, #0x90]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x90]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081242A2:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081242CC @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x88]
	cmp r0, #0
	bne _081243AC
	movs r1, #4
	ldr r2, [sp, #0xb4]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081242D0
	movs r0, #1
	b _081242D2
	.align 2, 0
_081242CC: .4byte 0x00000482
_081242D0:
	movs r0, #0
_081242D2:
	ldr r3, _081243BC @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x88]
	cmp r0, #0
	bne _081243AC
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xd4]
	ldr r1, _081243C0 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081243C4 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081243C8 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _081243CC @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081243D0 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	ldr r6, _081243D4 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	ldr r1, _081243D8 @ =0x030046B8
	adds r2, r5, #0
_0812431A:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081243DC @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081243E0 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0812433E
	adds r3, #1
	cmp r3, #3
	ble _0812431A
	adds r0, r5, #0
_0812433E:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xac]
	ldr r0, [r1]
	ldr r2, [sp, #0xd4]
	str r0, [r2]
	ldr r4, [sp, #0xa4]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0xbc]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0xc0]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0xc4]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa0]
	strb r0, [r6]
	add r0, sp, #0x54
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xd0]
	strb r1, [r4]
	ldr r5, [sp, #0xc8]
	strb r3, [r5]
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	ldr r0, [sp, #0xac]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa8]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0xbc]
	strb r0, [r5]
	ldr r6, [sp, #0xc0]
	strb r1, [r6]
	ldr r0, [sp, #0xc4]
	strb r2, [r0]
	ldr r2, [sp, #0x8c]
	str r3, [r2]
	ldr r3, [sp, #0xcc]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x9c]
	strb r0, [r4]
_081243AC:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x88]
	strh r0, [r5]
	movs r0, #0
	b _081244BE
	.align 2, 0
_081243BC: .4byte 0x00000482
_081243C0: .4byte 0x0000054F
_081243C4: .4byte 0x0000054C
_081243C8: .4byte 0x0000054E
_081243CC: .4byte 0x00000541
_081243D0: .4byte 0x000005BC
_081243D4: .4byte 0x00000542
_081243D8: .4byte 0x030046B8
_081243DC: .4byte 0x000003FF
_081243E0: .4byte 0x0203B400
_081243E4:
	add r6, sp, #0x18
	ldr r0, _08124424 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _08124428
	adds r0, #4
	b _08124434
	.align 2, 0
_08124424: .4byte 0x030046A4
_08124428:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08124434:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0812446C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08124474
	ldr r0, _08124470 @ =0xFFFFFDFF
	ldr r6, [sp, #0x98]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0812449E
	.align 2, 0
_0812446C: .4byte 0x000004A4
_08124470: .4byte 0xFFFFFDFF
_08124474:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08124494
	cmp r0, #2
	beq _08124490
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08124490:
	movs r0, #1
	b _081244A0
_08124494:
	ldr r0, _081244B4 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0812449E:
	movs r0, #0
_081244A0:
	cmp r0, #0
	bne _081244BC
	ldr r3, _081244B8 @ =0x000005C4
	adds r0, r7, r3
_081244A8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081244BE
	.align 2, 0
_081244B4: .4byte 0xFFFFFDFF
_081244B8: .4byte 0x000005C4
_081244BC:
	movs r0, #1
_081244BE:
	cmp r0, #0
	bne _0812452E
	ldr r4, _081244F4 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081244FC
	ldr r0, _081244F8 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08124526
	.align 2, 0
_081244F4: .4byte 0x000004A4
_081244F8: .4byte 0xFFFFFDFF
_081244FC:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0812451C
	cmp r0, #2
	beq _08124518
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08124518:
	movs r0, #1
	b _08124528
_0812451C:
	ldr r0, _08124590 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08124526:
	movs r0, #0
_08124528:
	cmp r0, #0
	bne _0812452E
	b _08124C64
_0812452E:
	movs r0, #4
	ldr r5, _08124594 @ =0x00000222
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r4, _08124598 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0812459C @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #0xc
	subs r6, #0xeb
	adds r0, r7, r6
	strb r3, [r0]
	ldr r2, _081245A0 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081245A4 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _081245A8 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _08124CD4
	.align 2, 0
_08124590: .4byte 0xFFFFFDFF
_08124594: .4byte 0x00000222
_08124598: .4byte 0x0000046D
_0812459C: .4byte 0x0000046B
_081245A0: .4byte 0x00000469
_081245A4: .4byte 0x0000046A
_081245A8: .4byte 0x0000046C
_081245AC:
	mov r3, sb
	orrs r1, r3
	ldr r4, [sp, #0x94]
	str r1, [r4]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r2, [r0, #6]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _08124608 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r3, r7, r5
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x90]
	str r2, [sp, #0xb8]
	cmp r4, #0
	blt _08124604
	cmp r1, #0
	blt _08124604
	ldr r0, _0812460C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08124604
	ldr r0, _08124610 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08124614
_08124604:
	movs r4, #0
	b _08124622
	.align 2, 0
_08124608: .4byte 0x03002BE0
_0812460C: .4byte 0x030046A8
_08124610: .4byte 0x030046AC
_08124614:
	ldr r0, _08124634 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08124622:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08124638
	adds r0, #4
	b _08124644
	.align 2, 0
_08124634: .4byte 0x030046A4
_08124638:
	ldr r0, _08124658 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08124644:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812465C
	cmp r2, #2
	beq _08124660
	b _08124664
	.align 2, 0
_08124658: .4byte 0x030046A4
_0812465C:
	ldrb r0, [r5, #4]
	b _08124662
_08124660:
	ldrb r0, [r5]
_08124662:
	subs r1, r1, r0
_08124664:
	strh r1, [r5, #2]
	ldr r0, _08124678 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812467C
	movs r0, #1
	b _0812467E
	.align 2, 0
_08124678: .4byte 0x030047A4
_0812467C:
	movs r0, #0
_0812467E:
	cmp r0, #0
	beq _081246BC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0812469E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0812469A
	adds r2, r0, #0
_0812469A:
	cmp r2, #0
	bge _081246A8
_0812469E:
	ldr r2, _081246A4 @ =0x000005C4
	adds r0, r7, r2
	b _08124BE0
	.align 2, 0
_081246A4: .4byte 0x000005C4
_081246A8:
	ldr r1, _081246B8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08124704
	.align 2, 0
_081246B8: .4byte 0x03002BE0
_081246BC:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081246E8
	cmp r1, #0
	blt _081246E8
	ldr r0, _081246EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081246E8
	ldr r0, _081246F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081246F4
_081246E8:
	movs r5, #0
	b _08124702
	.align 2, 0
_081246EC: .4byte 0x030046A8
_081246F0: .4byte 0x030046AC
_081246F4:
	ldr r0, _0812473C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08124702:
	movs r2, #0
_08124704:
	ldr r4, _08124740 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08124724
	ldr r1, _08124744 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08124724
	b _08124B1C
_08124724:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x98]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x58]
	cmp r0, #0
	beq _08124748
	movs r0, #0
	b _08124BF6
	.align 2, 0
_0812473C: .4byte 0x030046A4
_08124740: .4byte 0x00000256
_08124744: .4byte 0x03002BE0
_08124748:
	ldr r6, _081247F0 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x98]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xb4]
	cmp r0, #0
	beq _08124808
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _081247F4 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	movs r5, #1
	ldr r6, [sp, #0x5c]
	strb r5, [r6]
	ldr r2, _081247F8 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x60]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x64]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x68]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	add r1, sp, #0x58
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081247FC @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08124800 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x58]
	str r6, [r1]
	ldr r6, _08124804 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x5c]
	str r5, [sp, #0xd0]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xc0]
	str r2, [sp, #0xc4]
	str r1, [sp, #0x8c]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xc8]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xa4]
	ldr r1, [sp, #0x68]
	str r1, [sp, #0xac]
	mov r2, r8
	str r2, [sp, #0xa8]
	b _081249DA
	.align 2, 0
_081247F0: .4byte 0x00000222
_081247F4: .4byte 0x0000046D
_081247F8: .4byte 0x0000046B
_081247FC: .4byte 0x00000469
_08124800: .4byte 0x00000484
_08124804: .4byte 0x0000046C
_08124808:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081248CC @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _081248D0 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x6c]
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081248D4 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x70]
	strb r0, [r2]
	subs r3, #0x28
	adds r3, r7, r3
	str r3, [sp, #0x74]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x78]
	mov r5, ip
	strh r5, [r4]
	movs r1, #5
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x7c]
	movs r2, #0
	strb r2, [r6]
	ldr r3, _081248D8 @ =0x00000469
	adds r5, r7, r3
	strb r2, [r5]
	ldr r6, _081248DC @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081248E0 @ =0x00000484
	adds r3, r7, r1
	mov r2, ip
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x90]
	ldr r0, [r0]
	str r0, [sp, #0x80]
	ldr r1, [sp, #0xb8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x80]
	strh r1, [r6]
	ldr r6, [sp, #0xb8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x80]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0xd0]
	ldr r6, [sp, #0x7c]
	str r6, [sp, #0xbc]
	str r5, [sp, #0xc0]
	str r4, [sp, #0xc4]
	str r3, [sp, #0x8c]
	str r2, [sp, #0xcc]
	ldr r0, [sp, #0x6c]
	str r0, [sp, #0xc8]
	ldr r2, [sp, #0x70]
	str r2, [sp, #0xa4]
	ldr r3, [sp, #0x74]
	str r3, [sp, #0xac]
	ldr r4, [sp, #0x78]
	str r4, [sp, #0xa8]
	mov r5, sb
	cmp r5, #0
	blt _081248C6
	cmp r1, #0
	blt _081248C6
	ldr r0, _081248E4 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081248C6
	ldr r0, _081248E8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081248EC
_081248C6:
	movs r4, #0
	b _081248FC
	.align 2, 0
_081248CC: .4byte 0x0000046D
_081248D0: .4byte 0x0000046B
_081248D4: .4byte 0x00000553
_081248D8: .4byte 0x00000469
_081248DC: .4byte 0x0000046A
_081248E0: .4byte 0x00000484
_081248E4: .4byte 0x030046A8
_081248E8: .4byte 0x030046AC
_081248EC:
	ldr r0, _0812490C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, sb
	adds r4, r0, r6
_081248FC:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08124910
	adds r0, #4
	b _0812491C
	.align 2, 0
_0812490C: .4byte 0x030046A4
_08124910:
	ldr r0, _08124930 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812491C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08124934
	cmp r2, #2
	beq _0812493A
	b _08124940
	.align 2, 0
_08124930: .4byte 0x030046A4
_08124934:
	ldr r2, [sp, #0x80]
	ldrb r0, [r2, #4]
	b _0812493E
_0812493A:
	ldr r3, [sp, #0x80]
	ldrb r0, [r3]
_0812493E:
	subs r1, r1, r0
_08124940:
	ldr r4, [sp, #0x80]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x90]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812496C
	cmp r1, #0
	blt _0812496C
	ldr r0, _08124970 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812496C
	ldr r0, _08124974 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08124978
_0812496C:
	movs r4, #0
	b _08124986
	.align 2, 0
_08124970: .4byte 0x030046A8
_08124974: .4byte 0x030046AC
_08124978:
	ldr r0, _0812499C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08124986:
	ldr r6, [sp, #0x90]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081249A0
	adds r0, #4
	b _081249AC
	.align 2, 0
_0812499C: .4byte 0x030046A4
_081249A0:
	ldr r0, _081249C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081249AC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081249C4
	cmp r3, #2
	beq _081249C8
	b _081249CC
	.align 2, 0
_081249C0: .4byte 0x030046A4
_081249C4:
	ldrb r0, [r5, #4]
	b _081249CA
_081249C8:
	ldrb r0, [r5]
_081249CA:
	subs r2, r2, r0
_081249CC:
	ldr r1, [sp, #0x90]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x90]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081249DA:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x84]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _08124A04 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x88]
	cmp r0, #0
	bne _08124AE4
	movs r1, #4
	ldr r2, [sp, #0xb4]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08124A08
	movs r0, #1
	b _08124A0A
	.align 2, 0
_08124A04: .4byte 0x00000482
_08124A08:
	movs r0, #0
_08124A0A:
	ldr r3, _08124AF4 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x88]
	cmp r0, #0
	bne _08124AE4
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xd4]
	ldr r1, _08124AF8 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08124AFC @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _08124B00 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _08124B04 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08124B08 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	ldr r6, _08124B0C @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	ldr r1, _08124B10 @ =0x030046B8
	adds r2, r5, #0
_08124A52:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _08124B14 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _08124B18 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _08124A76
	adds r3, #1
	cmp r3, #3
	ble _08124A52
	adds r0, r5, #0
_08124A76:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xac]
	ldr r0, [r1]
	ldr r2, [sp, #0xd4]
	str r0, [r2]
	ldr r4, [sp, #0xa4]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0xbc]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0xc0]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0xc4]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa0]
	strb r0, [r6]
	add r0, sp, #0x84
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xd0]
	strb r1, [r4]
	ldr r5, [sp, #0xc8]
	strb r3, [r5]
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	ldr r0, [sp, #0xac]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa8]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0xbc]
	strb r0, [r5]
	ldr r6, [sp, #0xc0]
	strb r1, [r6]
	ldr r0, [sp, #0xc4]
	strb r2, [r0]
	ldr r2, [sp, #0x8c]
	str r3, [r2]
	ldr r3, [sp, #0xcc]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x9c]
	strb r0, [r4]
_08124AE4:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x88]
	strh r0, [r5]
	movs r0, #0
	b _08124BF6
	.align 2, 0
_08124AF4: .4byte 0x00000482
_08124AF8: .4byte 0x0000054F
_08124AFC: .4byte 0x0000054C
_08124B00: .4byte 0x0000054E
_08124B04: .4byte 0x00000541
_08124B08: .4byte 0x000005BC
_08124B0C: .4byte 0x00000542
_08124B10: .4byte 0x030046B8
_08124B14: .4byte 0x000003FF
_08124B18: .4byte 0x0203B400
_08124B1C:
	add r6, sp, #0x20
	ldr r0, _08124B5C @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _08124B60
	adds r0, #4
	b _08124B6C
	.align 2, 0
_08124B5C: .4byte 0x030046A4
_08124B60:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08124B6C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _08124BA4 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08124BAC
	ldr r0, _08124BA8 @ =0xFFFFFDFF
	ldr r6, [sp, #0x98]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _08124BD6
	.align 2, 0
_08124BA4: .4byte 0x000004A4
_08124BA8: .4byte 0xFFFFFDFF
_08124BAC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08124BCC
	cmp r0, #2
	beq _08124BC8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08124BC8:
	movs r0, #1
	b _08124BD8
_08124BCC:
	ldr r0, _08124BEC @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08124BD6:
	movs r0, #0
_08124BD8:
	cmp r0, #0
	bne _08124BF4
	ldr r3, _08124BF0 @ =0x000005C4
	adds r0, r7, r3
_08124BE0:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08124BF6
	.align 2, 0
_08124BEC: .4byte 0xFFFFFDFF
_08124BF0: .4byte 0x000005C4
_08124BF4:
	movs r0, #1
_08124BF6:
	cmp r0, #0
	bne _08124C7C
	ldr r4, _08124C2C @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08124C34
	ldr r0, _08124C30 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08124C5E
	.align 2, 0
_08124C2C: .4byte 0x000004A4
_08124C30: .4byte 0xFFFFFDFF
_08124C34:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08124C54
	cmp r0, #2
	beq _08124C50
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08124C50:
	movs r0, #1
	b _08124C60
_08124C54:
	ldr r0, _08124C74 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08124C5E:
	movs r0, #0
_08124C60:
	cmp r0, #0
	bne _08124C7C
_08124C64:
	ldr r4, _08124C78 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08124CD4
	.align 2, 0
_08124C74: .4byte 0xFFFFFDFF
_08124C78: .4byte 0x000005C4
_08124C7C:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08124CE4 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08124CE8 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08124CEC @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08124CF0 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _08124CF4 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #3
	strh r0, [r1]
_08124CD4:
	add sp, #0xd8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08124CE4: .4byte 0x0000046D
_08124CE8: .4byte 0x0000046B
_08124CEC: .4byte 0x00000469
_08124CF0: .4byte 0x0000046A
_08124CF4: .4byte 0x00000484
