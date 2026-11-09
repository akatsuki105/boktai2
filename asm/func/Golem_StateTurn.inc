	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	ldr r0, _08116D4C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08116D50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08116D52
	.align 2, 0
_08116D4C: .4byte 0x0000046D
_08116D50:
	movs r0, #0
_08116D52:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _08116D60
	b _081171FA
_08116D60:
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
	ldr r3, _08116DB0 @ =0x0000046A
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #6
	beq _08116DB4
	movs r1, #0x90
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _08116DB4
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _08116DBC
	.align 2, 0
_08116DB0: .4byte 0x0000046A
_08116DB4:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_08116DBC:
	cmp r1, #0
	blt _08116DC4
	asrs r0, r1, #1
	b _08116DCA
_08116DC4:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08116DCA:
	cmp r2, r0
	bne _08116E36
	ldr r2, _08116E1C @ =0x0000046B
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
	beq _08116E2C
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08116E20 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _08116E24 @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _08116E28 @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	b _0811735C
	.align 2, 0
_08116E1C: .4byte 0x0000046B
_08116E20: .4byte 0x00000469
_08116E24: .4byte 0x0000046A
_08116E28: .4byte 0x000005BC
_08116E2C:
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _081173C0
_08116E36:
	cmp r2, #1
	beq _08116F14
	cmp r2, #1
	bgt _08116E44
	cmp r2, #0
	beq _08116E52
	b _081171F2
_08116E44:
	cmp r2, #2
	bne _08116E4A
	b _08116FE4
_08116E4A:
	cmp r2, #3
	bne _08116E50
	b _081170D0
_08116E50:
	b _081171F2
_08116E52:
	subs r0, r1, #2
	cmp r0, #3
	bhi _08116EA4
	movs r2, #2
	ldr r3, _08116E78 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _08116E80
	ldr r1, _08116E7C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _081170F2
	.align 2, 0
_08116E78: .4byte 0x0000025D
_08116E7C: .4byte 0x000004B7
_08116E80:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #3
	ldr r3, _08116E9C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08116EA0 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	beq _08116E9A
	b _0811712E
_08116E9A:
	b _0811711E
	.align 2, 0
_08116E9C: .4byte 0x000004B7
_08116EA0: .4byte 0x0000046E
_08116EA4:
	movs r1, #2
	ldr r2, _08116ECC @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08116ED4
	ldr r3, _08116ED0 @ =0x000004B7
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
	b _08116EFA
	.align 2, 0
_08116ECC: .4byte 0x0000025D
_08116ED0: .4byte 0x000004B7
_08116ED4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r2, _08116F0C @ =0x000004B7
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
_08116EFA:
	ldr r3, _08116F10 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _081171EA
	.align 2, 0
_08116F0C: .4byte 0x000004B7
_08116F10: .4byte 0x0000046E
_08116F14:
	subs r0, r1, #4
	cmp r0, #3
	bhi _08116F74
	movs r2, #2
	ldr r1, _08116F3C @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08116F44
	ldr r1, _08116F40 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _081170F2
	.align 2, 0
_08116F3C: .4byte 0x0000025D
_08116F40: .4byte 0x000004B7
_08116F44:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #4
	ldr r3, _08116F6C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08116F70 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #4
	beq _08116F5E
	b _0811712E
_08116F5E:
	ldrb r0, [r6]
	cmp r0, #0
	beq _08116F66
	b _0811712E
_08116F66:
	ldr r0, [r4, #8]
	ands r0, r2
	b _0811712A
	.align 2, 0
_08116F6C: .4byte 0x000004B7
_08116F70: .4byte 0x0000046E
_08116F74:
	movs r1, #2
	ldr r2, _08116F9C @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08116FA4
	ldr r3, _08116FA0 @ =0x000004B7
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
	b _08116FCC
	.align 2, 0
_08116F9C: .4byte 0x0000025D
_08116FA0: .4byte 0x000004B7
_08116FA4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _08116FDC @ =0x000004B7
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
_08116FCC:
	ldr r3, _08116FE0 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _081171EA
	.align 2, 0
_08116FDC: .4byte 0x000004B7
_08116FE0: .4byte 0x0000046E
_08116FE4:
	subs r0, r1, #1
	cmp r0, #4
	bls _08117060
	movs r1, #2
	ldr r2, _08117014 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811701C
	ldr r3, _08117018 @ =0x000004B7
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
	b _08117042
	.align 2, 0
_08117014: .4byte 0x0000025D
_08117018: .4byte 0x000004B7
_0811701C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _08117058 @ =0x000004B7
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
_08117042:
	ldr r3, _0811705C @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	b _08117158
	.align 2, 0
_08117058: .4byte 0x000004B7
_0811705C: .4byte 0x0000046E
_08117060:
	movs r2, #4
	ldr r1, _08117088 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08117090
	ldr r3, _0811708C @ =0x000004B7
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
	b _081170B6
	.align 2, 0
_08117088: .4byte 0x0000025D
_0811708C: .4byte 0x000004B7
_08117090:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r1, _081170C8 @ =0x000004B7
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
_081170B6:
	ldr r2, _081170CC @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r5, r3
	b _081171EA
	.align 2, 0
_081170C8: .4byte 0x000004B7
_081170CC: .4byte 0x0000046E
_081170D0:
	cmp r1, #3
	bhi _08117168
	movs r2, #2
	ldr r1, _081170FC @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08117108
	ldr r1, _08117100 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_081170F2:
	bl AuxAnim_SetAnim
	ldr r2, _08117104 @ =0x0000046E
	adds r6, r5, r2
	b _0811714A
	.align 2, 0
_081170FC: .4byte 0x0000025D
_08117100: .4byte 0x000004B7
_08117104: .4byte 0x0000046E
_08117108:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _08117160 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08117164 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #2
	bne _0811712E
_0811711E:
	ldrb r0, [r6]
	cmp r0, #0
	bne _0811712E
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
_0811712A:
	cmp r0, #0
	beq _0811714E
_0811712E:
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
_0811714A:
	movs r0, #0
	strb r0, [r6]
_0811714E:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
_08117158:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081171F2
	.align 2, 0
_08117160: .4byte 0x000004B7
_08117164: .4byte 0x0000046E
_08117168:
	movs r2, #2
	ldr r1, _08117194 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081171A0
	ldr r3, _08117198 @ =0x000004B7
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
	ldr r0, _0811719C @ =0x0000046E
	adds r6, r5, r0
	b _081171E0
	.align 2, 0
_08117194: .4byte 0x0000025D
_08117198: .4byte 0x000004B7
_0811719C: .4byte 0x0000046E
_081171A0:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #3
	ldr r1, _0811722C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08117230 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	bne _081171C8
	ldrb r0, [r6]
	cmp r0, #0
	bne _081171C8
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081171E4
_081171C8:
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
_081171E0:
	movs r0, #0
	strb r0, [r6]
_081171E4:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
_081171EA:
	ldr r1, _08117234 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081171F2:
	ldr r2, _08117230 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_081171FA:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne _0811725C
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
	bge _08117222
	rsbs r0, r0, #0
_08117222:
	cmp r0, #0x16
	bgt _08117238
	mov r0, r8
	strb r1, [r0, #5]
	b _0811725C
	.align 2, 0
_0811722C: .4byte 0x000004B7
_08117230: .4byte 0x0000046E
_08117234: .4byte 0xFFFEFFFF
_08117238:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08117254
	adds r0, r2, #0
	adds r0, #0x16
	mov r1, r8
	strb r0, [r1, #5]
	b _0811725C
_08117254:
	adds r0, r2, #0
	subs r0, #0x16
	mov r2, r8
	strb r0, [r2, #5]
_0811725C:
	ldr r1, _08117274 @ =0x0000A02F
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0811727C
	ldr r0, _08117278 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0811728C
	.align 2, 0
_08117274: .4byte 0x0000A02F
_08117278: .4byte 0x00000482
_0811727C:
	ldr r1, _081172B0 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0811728C
	movs r0, #1
	strh r0, [r2]
_0811728C:
	ldr r3, _081172B4 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081172B8
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
	b _081172D0
	.align 2, 0
_081172B0: .4byte 0x00000482
_081172B4: .4byte 0x0000025D
_081172B8:
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
_081172D0:
	ldr r1, _08117380 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081173C0
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
	bge _081172FA
	rsbs r1, r1, #0
_081172FA:
	cmp r1, #0
	bgt _08117390
	ldr r1, _08117384 @ =0x0000046B
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
	beq _081173C0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _08117388 @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _0811738C @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r3, #0x17
_0811735C:
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
	b _081173C0
	.align 2, 0
_08117380: .4byte 0x0000046E
_08117384: .4byte 0x0000046B
_08117388: .4byte 0x0000046A
_0811738C: .4byte 0x000005BC
_08117390:
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _081173D0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081173D4 @ =0x0000046B
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
_081173C0:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081173D0: .4byte 0x0000046D
_081173D4: .4byte 0x0000046B
