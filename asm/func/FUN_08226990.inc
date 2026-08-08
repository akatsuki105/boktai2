	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _082269FC @ =0x00000E8C
	adds r0, r7, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _08226A00 @ =0x00000DB8
	adds r0, r7, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	subs r1, r1, r0
	mov sb, r1
	movs r6, #0xe9
	lsls r6, r6, #4
	adds r0, r7, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #4
	adds r0, r7, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	subs r1, r1, r0
	mov r8, r1
	mov r0, sb
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, #0x8c
	adds r1, r7, r6
	strh r0, [r1]
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r7, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08226A08
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r2, _08226A04 @ =0x00000F14
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08226A0A
	.align 2, 0
_082269FC: .4byte 0x00000E8C
_08226A00: .4byte 0x00000DB8
_08226A04: .4byte 0x00000F14
_08226A08:
	movs r0, #0
_08226A0A:
	ldr r3, _08226A78 @ =0x00000E38
	adds r6, r7, r3
	cmp r0, #0
	beq _08226ACC
	ldr r5, _08226A7C @ =0x00000F15
	adds r0, r7, r5
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08226A80 @ =0x00000F1C
	adds r0, r7, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r5, #0xd
	adds r3, r7, r5
	ldr r0, _08226A84 @ =0x00000F27
	adds r5, r7, r0
	lsls r0, r2, #0x10
	cmp r0, #0
	bge _08226A44
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
_08226A36:
	asrs r0, r0, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r2, #0x10
	cmp r0, #0
	blt _08226A36
_08226A44:
	lsls r1, r2, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0xff
	ble _08226A60
	ldr r0, _08226A88 @ =0xFFFFFF00
	adds r4, r0, #0
_08226A50:
	asrs r0, r1, #0x10
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r2, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0xff
	bgt _08226A50
_08226A60:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r0, #0x10
	asrs r2, r0, #5
	movs r0, #7
	ands r2, r0
	adds r0, r2, #0
	cmp r0, #4
	bne _08226A8C
	movs r0, #0
	strb r0, [r3]
	b _08226AAC
	.align 2, 0
_08226A78: .4byte 0x00000E38
_08226A7C: .4byte 0x00000F15
_08226A80: .4byte 0x00000F1C
_08226A84: .4byte 0x00000F27
_08226A88: .4byte 0xFFFFFF00
_08226A8C:
	cmp r0, #0
	bne _08226A96
	movs r0, #4
	strb r0, [r3]
	b _08226AAC
_08226A96:
	cmp r0, #3
	bgt _08226AA4
	movs r0, #4
	subs r0, r0, r2
	strb r0, [r3]
	movs r0, #1
	b _08226AAA
_08226AA4:
	subs r0, r2, #4
	strb r0, [r3]
	movs r0, #0
_08226AAA:
	strb r0, [r5]
_08226AAC:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r0, #4
	movs r1, #7
	ands r0, r1
	ldr r2, _08226AFC @ =0x00000F24
	adds r1, r7, r2
	movs r2, #0
	strb r0, [r1]
	ldr r3, _08226B00 @ =0x00000F38
	adds r0, r7, r3
	strb r2, [r0]
	ldr r5, _08226B04 @ =0x00000DF4
	adds r0, r7, r5
	bl FUN_08013698
_08226ACC:
	ldr r0, _08226B08 @ =0x00000D9C
	adds r3, r7, r0
	ldrh r1, [r6]
	adds r0, r1, #1
	strh r0, [r6]
	movs r2, #3
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08226B66
	ldr r1, _08226B0C @ =0x00000DEC
	adds r0, r7, r1
	ldrh r0, [r0]
	ands r2, r0
	cmp r2, #2
	bgt _08226B14
	cmp r2, #1
	bge _08226B3C
	cmp r2, #0
	beq _08226B1C
	ldr r2, _08226B10 @ =0x00000E3A
	adds r1, r7, r2
	b _08226B5C
	.align 2, 0
_08226AFC: .4byte 0x00000F24
_08226B00: .4byte 0x00000F38
_08226B04: .4byte 0x00000DF4
_08226B08: .4byte 0x00000D9C
_08226B0C: .4byte 0x00000DEC
_08226B10: .4byte 0x00000E3A
_08226B14:
	ldr r5, _08226B30 @ =0x00000E3A
	adds r1, r7, r5
	cmp r2, #3
	bne _08226B5C
_08226B1C:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08226B34
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #1
	b _08226B5A
	.align 2, 0
_08226B30: .4byte 0x00000E3A
_08226B34:
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #0xf8
	b _08226B5A
_08226B3C:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08226B54
	ldr r6, _08226B50 @ =0x00000E3A
	adds r1, r7, r6
	movs r0, #0xff
	b _08226B5A
	.align 2, 0
_08226B50: .4byte 0x00000E3A
_08226B54:
	ldr r0, _08226BBC @ =0x00000E3A
	adds r1, r7, r0
	movs r0, #8
_08226B5A:
	strb r0, [r1]
_08226B5C:
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
_08226B66:
	ldr r2, _08226BC0 @ =0x00000DE4
	adds r4, r7, r2
	ldr r3, _08226BC4 @ =0x00000E34
	adds r0, r7, r3
	ldr r1, [r0]
	ldr r5, _08226BC8 @ =0x00000F15
	adds r0, r7, r5
	ldrb r2, [r0]
	ldr r6, _08226BCC @ =0x00000F22
	adds r0, r7, r6
	ldrb r3, [r0]
	adds r5, #0x12
	adds r0, r7, r5
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	ldr r6, _08226BD0 @ =0x00000D9C
	adds r5, r7, r6
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08226BD4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08226BDC
	.align 2, 0
_08226BBC: .4byte 0x00000E3A
_08226BC0: .4byte 0x00000DE4
_08226BC4: .4byte 0x00000E34
_08226BC8: .4byte 0x00000F15
_08226BCC: .4byte 0x00000F22
_08226BD0: .4byte 0x00000D9C
_08226BD4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08226BDC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08226C00
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08226C08
_08226C00:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08226C08:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08226C40 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08226C86
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08226C4A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08226C44
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08226C60
	.align 2, 0
_08226C40: .4byte 0x0000FFFF
_08226C44:
	subs r0, #1
	strh r0, [r4, #8]
	b _08226C5E
_08226C4A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r5, [r4, #5]
	cmp r0, r5
	blo _08226C5E
	strh r1, [r4, #8]
	movs r2, #1
	b _08226C60
_08226C5E:
	movs r2, #0
_08226C60:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08226C88
	movs r0, #1
	strb r0, [r4, #7]
	b _08226C88
_08226C86:
	movs r2, #0
_08226C88:
	ldr r6, _08226D48 @ =0x00000F14
	adds r0, r7, r6
	strb r2, [r0]
	mov r1, sb
	cmp r1, #0
	bge _08226C96
	rsbs r1, r1, #0
_08226C96:
	mov r0, r8
	cmp r0, #0
	bge _08226C9E
	rsbs r0, r0, #0
_08226C9E:
	adds r0, r1, r0
	cmp r0, #9
	ble _08226CA6
	b _08226EA8
_08226CA6:
	ldr r1, _08226D4C @ =0x00000F38
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08226CB2
	b _08226EB2
_08226CB2:
	ldr r2, _08226D50 @ =0x00000E8C
	adds r0, r7, r2
	ldrh r1, [r0]
	ldr r3, _08226D54 @ =0x00000DB8
	adds r0, r7, r3
	strh r1, [r0]
	movs r5, #0xe9
	lsls r5, r5, #4
	adds r0, r7, r5
	ldrh r1, [r0]
	ldr r6, _08226D58 @ =0x00000DBC
	adds r0, r7, r6
	strh r1, [r0]
	ldr r0, _08226D5C @ =0x00000F23
	adds r3, r7, r0
	ldrb r1, [r3]
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _08226CDC
	b _08226E2A
_08226CDC:
	movs r5, #0
	adds r2, #0x98
	adds r0, r7, r2
	strb r1, [r0]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r0, #7
	ands r3, r0
	adds r1, r3, #0
	cmp r1, #4
	ble _08226CFE
	movs r0, #8
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r5, #1
_08226CFE:
	ldr r6, _08226D60 @ =0x00000DE4
	adds r4, r7, r6
	ldr r1, _08226D64 @ =0x00000E34
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _08226D68 @ =0x00000F15
	adds r0, r7, r2
	ldrb r2, [r0]
	str r5, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	ldr r3, _08226D6C @ =0x00000D9C
	adds r5, r7, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08226D70
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08226D78
	.align 2, 0
_08226D48: .4byte 0x00000F14
_08226D4C: .4byte 0x00000F38
_08226D50: .4byte 0x00000E8C
_08226D54: .4byte 0x00000DB8
_08226D58: .4byte 0x00000DBC
_08226D5C: .4byte 0x00000F23
_08226D60: .4byte 0x00000DE4
_08226D64: .4byte 0x00000E34
_08226D68: .4byte 0x00000F15
_08226D6C: .4byte 0x00000D9C
_08226D70:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08226D78:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08226D9C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08226DA4
_08226D9C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08226DA4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _08226DDC @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _08226E22
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08226DE6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08226DE0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08226DFC
	.align 2, 0
_08226DDC: .4byte 0x0000FFFF
_08226DE0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08226DFA
_08226DE6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08226DFA
	strh r1, [r4, #8]
	movs r2, #1
	b _08226DFC
_08226DFA:
	movs r2, #0
_08226DFC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08226E24
	movs r0, #1
	strb r0, [r4, #7]
	b _08226E24
_08226E22:
	movs r2, #0
_08226E24:
	ldr r3, _08226E8C @ =0x00000F14
	adds r0, r7, r3
	strb r2, [r0]
_08226E2A:
	ldr r5, _08226E90 @ =0x00000F16
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r2]
	ldr r6, _08226E94 @ =0x00000F18
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r0, #3
	bne _08226E64
	ldrb r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #3
	bne _08226E64
	ldr r1, _08226E98 @ =0x00000DEC
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _08226E9C @ =0x00000F42
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08226EA0 @ =0x00000DF2
	adds r0, r7, r3
	ldrh r1, [r0]
	adds r5, #0x2d
	adds r0, r7, r5
	strb r1, [r0]
_08226E64:
	movs r0, #1
	movs r6, #0xf2
	lsls r6, r6, #4
	adds r2, r7, r6
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08226EA4 @ =0x00000F0C
	adds r1, r7, r0
	ldr r2, [r1]
	cmp r2, #0
	bne _08226E7E
	b _08226FA0
_08226E7E:
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl FUN_082318ac
	b _08226FA0
	.align 2, 0
_08226E8C: .4byte 0x00000F14
_08226E90: .4byte 0x00000F16
_08226E94: .4byte 0x00000F18
_08226E98: .4byte 0x00000DEC
_08226E9C: .4byte 0x00000F42
_08226EA0: .4byte 0x00000DF2
_08226EA4: .4byte 0x00000F0C
_08226EA8:
	ldr r1, _08226EE8 @ =0x00000F38
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08226F26
_08226EB2:
	ldr r2, _08226EEC @ =0x00000E8E
	adds r4, r7, r2
	ldr r3, _08226EF0 @ =0x00000DBA
	adds r2, r7, r3
	movs r5, #0
	ldrsh r3, [r4, r5]
	ldrh r0, [r2]
	movs r6, #0
	ldrsh r1, [r2, r6]
	cmp r3, r1
	ble _08226EF8
	adds r0, #7
	strh r0, [r2]
	ldr r0, _08226EF4 @ =0x00000E9E
	adds r3, r7, r0
	ldrh r0, [r3]
	adds r0, #7
	strh r0, [r3]
	ldrh r5, [r4]
	movs r6, #0
	ldrsh r1, [r4, r6]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bge _08226F26
	b _08226F18
	.align 2, 0
_08226EE8: .4byte 0x00000F38
_08226EEC: .4byte 0x00000E8E
_08226EF0: .4byte 0x00000DBA
_08226EF4: .4byte 0x00000E9E
_08226EF8:
	cmp r3, r1
	bge _08226F26
	subs r0, #7
	strh r0, [r2]
	ldr r1, _08226FB0 @ =0x00000E9E
	adds r3, r7, r1
	ldrh r0, [r3]
	subs r0, #7
	strh r0, [r3]
	ldrh r5, [r4]
	movs r6, #0
	ldrsh r1, [r4, r6]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	ble _08226F26
_08226F18:
	strh r5, [r2]
	ldrh r0, [r4]
	strh r0, [r3]
	ldr r0, _08226FB4 @ =0x00000F38
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_08226F26:
	mov r1, sb
	cmp r1, #0
	bne _08226F32
	mov r2, r8
	cmp r2, #0
	beq _08226FA0
_08226F32:
	ldr r3, _08226FB8 @ =0x085B0A08
	mov sb, r3
	ldr r5, _08226FBC @ =0x00000F1C
	adds r6, r7, r5
	movs r1, #0
	ldrsh r0, [r6, r1]
	adds r0, #0x40
	movs r4, #0xff
	ands r0, r4
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r5, #0xfa
	lsls r5, r5, #1
	adds r1, r5, #0
	bl Div
	ldr r3, _08226FC0 @ =0x00000E84
	adds r3, r3, r7
	mov r8, r3
	strh r0, [r3]
	ldrh r0, [r6]
	ands r4, r0
	lsls r4, r4, #1
	add r4, sb
	movs r6, #0
	ldrsh r0, [r4, r6]
	adds r1, r5, #0
	bl Div
	ldr r1, _08226FC4 @ =0x00000E88
	adds r3, r7, r1
	strh r0, [r3]
	ldr r5, _08226FC8 @ =0x00000DB8
	adds r2, r7, r5
	mov r6, r8
	ldrh r0, [r6]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r5, #4
	adds r1, r7, r5
	ldrh r0, [r3]
	ldrh r6, [r1]
	adds r0, r0, r6
	strh r0, [r1]
	ldrh r2, [r2]
	ldr r3, _08226FCC @ =0x00000E9C
	adds r0, r7, r3
	strh r2, [r0]
	ldrh r1, [r1]
	adds r5, #0xe4
	adds r0, r7, r5
	strh r1, [r0]
_08226FA0:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08226FB0: .4byte 0x00000E9E
_08226FB4: .4byte 0x00000F38
_08226FB8: .4byte 0x085B0A08
_08226FBC: .4byte 0x00000F1C
_08226FC0: .4byte 0x00000E84
_08226FC4: .4byte 0x00000E88
_08226FC8: .4byte 0x00000DB8
_08226FCC: .4byte 0x00000E9C
