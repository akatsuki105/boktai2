	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r3, _080B3F84 @ =0x030044E0
	ldrh r1, [r3, #2]
	movs r0, #1
	mov sb, r0
	ands r0, r1
	cmp r0, #0
	beq _080B3F90
	ldr r2, _080B3F88 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r1, [r1]
	str r1, [r0]
	ldr r0, [r2]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r2, _080B3F8C @ =0x000005D4
	adds r1, r5, r2
	ldr r1, [r1]
	strh r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b3dd0
	b _080B3FA8
	.align 2, 0
_080B3F84: .4byte 0x030044E0
_080B3F88: .4byte 0x030046A0
_080B3F8C: .4byte 0x000005D4
_080B3F90:
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080B3FAE
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b3c08
_080B3FA8:
	adds r1, r5, #0
	adds r1, #0x18
	b _080B4318
_080B3FAE:
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _080B3FBA
	b _080B40BC
_080B3FBA:
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r6, r5, r3
	ldr r1, [r6]
	ldr r0, _080B4030 @ =0x0000270E
	cmp r1, r0
	bls _080B3FCA
	b _080B41F4
_080B3FCA:
	ldr r0, _080B4034 @ =0x000005D4
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	bne _080B3FD6
	b _080B41F4
_080B3FD6:
	ldr r1, _080B4038 @ =0x000005E2
	adds r7, r5, r1
	ldrh r0, [r7]
	cmp r0, #0
	bne _080B3FE6
	adds r3, #0xc
	adds r0, r5, r3
	strh r2, [r0]
_080B3FE6:
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r0, r5, r1
	strh r2, [r0]
	ldr r2, _080B403C @ =0x000005E6
	adds r2, r2, r5
	mov r8, r2
	movs r0, #0x10
	strh r0, [r2]
	ldrh r1, [r7]
	adds r0, r1, #0
	cmp r0, #0x7f
	bls _080B4070
	ldr r0, _080B4040 @ =0x0000037D
	bl PlaySound_082406e0
	movs r7, #0xa
	ldr r0, [r4]
	cmp r0, #0xa
	bhs _080B4010
	adds r7, r0, #0
_080B4010:
	movs r2, #0xa
	ldr r1, [r6]
	adds r0, r1, #0
	adds r0, #0xa
	ldr r3, _080B4044 @ =0x0000270F
	cmp r0, r3
	bls _080B4020
	subs r2, r3, r1
_080B4020:
	cmp r7, r2
	bge _080B4048
	adds r0, r1, r7
	str r0, [r6]
	ldr r0, [r4]
	subs r0, r0, r7
	b _080B4050
	.align 2, 0
_080B4030: .4byte 0x0000270E
_080B4034: .4byte 0x000005D4
_080B4038: .4byte 0x000005E2
_080B403C: .4byte 0x000005E6
_080B4040: .4byte 0x0000037D
_080B4044: .4byte 0x0000270F
_080B4048:
	adds r0, r1, r2
	str r0, [r6]
	ldr r0, [r4]
	subs r0, r0, r2
_080B4050:
	str r0, [r4]
	adds r0, r5, #0
	bl solar_bank_080b3a10
	ldr r3, _080B4068 @ =0x000005E4
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	ldr r0, _080B406C @ =0x000005E6
	adds r1, r5, r0
	b _080B4174
	.align 2, 0
_080B4068: .4byte 0x000005E4
_080B406C: .4byte 0x000005E6
_080B4070:
	cmp r0, #0x3f
	bls _080B4094
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080B4082
	ldr r0, _080B4090 @ =0x0000037D
	bl PlaySound_082406e0
_080B4082:
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	b _080B41A2
	.align 2, 0
_080B4090: .4byte 0x0000037D
_080B4094:
	adds r0, r1, #1
	strh r0, [r7]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _080B40A2
	b _080B420A
_080B40A2:
	ldr r0, _080B40B8 @ =0x0000037D
	bl PlaySound_082406e0
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	b _080B41E6
	.align 2, 0
_080B40B8: .4byte 0x0000037D
_080B40BC:
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _080B40CC
	b _080B4204
_080B40CC:
	movs r1, #0xbb
	lsls r1, r1, #3
	adds r6, r5, r1
	ldr r0, [r6]
	cmp r0, #0
	bne _080B40DA
	b _080B41F4
_080B40DA:
	ldr r3, _080B4140 @ =0x000005D4
	adds r4, r5, r3
	ldr r1, [r4]
	ldr r0, _080B4144 @ =0x0000270E
	cmp r1, r0
	bls _080B40E8
	b _080B41F4
_080B40E8:
	ldr r0, _080B4148 @ =0x000005E2
	adds r7, r5, r0
	ldrh r1, [r7]
	cmp r1, #0
	bne _080B40F8
	adds r3, #0x10
	adds r0, r5, r3
	strh r1, [r0]
_080B40F8:
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r3, sb
	strh r3, [r0]
	ldr r0, _080B414C @ =0x000005E6
	adds r0, r0, r5
	mov r8, r0
	strh r2, [r0]
	ldrh r1, [r7]
	adds r0, r1, #0
	cmp r0, #0x7f
	bls _080B4184
	ldr r0, _080B4150 @ =0x0000037D
	bl PlaySound_082406e0
	movs r7, #0xa
	ldr r0, [r6]
	cmp r0, #0xa
	bhs _080B4122
	adds r7, r0, #0
_080B4122:
	movs r2, #0xa
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0xa
	ldr r3, _080B4154 @ =0x0000270F
	cmp r0, r3
	bls _080B4132
	subs r2, r3, r1
_080B4132:
	cmp r7, r2
	bge _080B4158
	adds r0, r1, r7
	str r0, [r4]
	ldr r0, [r6]
	subs r0, r0, r7
	b _080B4160
	.align 2, 0
_080B4140: .4byte 0x000005D4
_080B4144: .4byte 0x0000270E
_080B4148: .4byte 0x000005E2
_080B414C: .4byte 0x000005E6
_080B4150: .4byte 0x0000037D
_080B4154: .4byte 0x0000270F
_080B4158:
	adds r0, r1, r2
	str r0, [r4]
	ldr r0, [r6]
	subs r0, r0, r2
_080B4160:
	str r0, [r6]
	adds r0, r5, #0
	bl solar_bank_080b3a10
	ldr r2, _080B417C @ =0x000005E4
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	ldr r3, _080B4180 @ =0x000005E6
	adds r1, r5, r3
_080B4174:
	movs r0, #4
	strh r0, [r1]
	b _080B420A
	.align 2, 0
_080B417C: .4byte 0x000005E4
_080B4180: .4byte 0x000005E6
_080B4184:
	cmp r0, #0x3f
	bls _080B41C8
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080B4196
	ldr r0, _080B41C0 @ =0x0000037D
	bl PlaySound_082406e0
_080B4196:
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
_080B41A2:
	adds r0, r5, #0
	bl solar_bank_080b3a10
	ldr r1, _080B41C4 @ =0x000005E4
	adds r0, r5, r1
	mov r2, sb
	strh r2, [r0]
	movs r0, #4
	mov r3, r8
	strh r0, [r3]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	b _080B420A
	.align 2, 0
_080B41C0: .4byte 0x0000037D
_080B41C4: .4byte 0x000005E4
_080B41C8:
	adds r0, r1, #1
	strh r0, [r7]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080B420A
	ldr r0, _080B41F0 @ =0x0000037D
	bl PlaySound_082406e0
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
_080B41E6:
	adds r0, r5, #0
	bl solar_bank_080b3a10
	b _080B420A
	.align 2, 0
_080B41F0: .4byte 0x0000037D
_080B41F4:
	ldr r0, _080B4200 @ =0x000005E2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	b _080B420A
	.align 2, 0
_080B4200: .4byte 0x000005E2
_080B4204:
	ldr r2, _080B422C @ =0x000005E2
	adds r0, r5, r2
	strh r1, [r0]
_080B420A:
	ldr r3, _080B4230 @ =0x000005E6
	adds r0, r5, r3
	ldrh r1, [r0]
	cmp r1, #0
	beq _080B4264
	ldr r1, _080B4234 @ =0x000005E4
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _080B4238
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #4
	b _080B4252
	.align 2, 0
_080B422C: .4byte 0x000005E2
_080B4230: .4byte 0x000005E6
_080B4234: .4byte 0x000005E4
_080B4238:
	cmp r0, #1
	bne _080B4248
	movs r3, #0xbc
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #2
	b _080B4252
_080B4248:
	movs r0, #0xbc
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
_080B4252:
	strh r0, [r1]
	ldr r2, _080B4260 @ =0x000005E6
	adds r1, r5, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080B426C
	.align 2, 0
_080B4260: .4byte 0x000005E6
_080B4264:
	movs r3, #0xbc
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r1, [r0]
_080B426C:
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _080B42B0
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, _080B42A8 @ =0x0000013D
	bl Video_SetAuxSpritePltt
	ldr r3, _080B42AC @ =0x000005AC
	adds r0, r5, r3
	movs r1, #0xa0
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, r4, #0
	movs r2, #0x12
	movs r3, #1
	bl MainSprite_SetPose
	b _080B4316
	.align 2, 0
_080B42A8: .4byte 0x0000013D
_080B42AC: .4byte 0x000005AC
_080B42B0:
	movs r0, #0x1f
	ands r0, r1
	lsrs r0, r0, #3
	cmp r0, #1
	beq _080B42CA
	cmp r0, #1
	bgt _080B42C4
	cmp r0, #0
	beq _080B42CE
	b _080B42D2
_080B42C4:
	cmp r0, #2
	beq _080B42CE
	b _080B42D2
_080B42CA:
	movs r6, #2
	b _080B42D4
_080B42CE:
	movs r6, #1
	b _080B42D4
_080B42D2:
	movs r6, #0
_080B42D4:
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, _080B432C @ =0x0000013D
	adds r1, r6, r3
	bl Video_SetAuxSpritePltt
	ldr r1, _080B4330 @ =0x000005AC
	adds r0, r5, r1
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r1, r6, r1
	bl Video_SetAuxSpritePltt
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r4, r5, #0
	adds r4, #0x18
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r1, [r1]
	lsls r2, r1, #1
	adds r2, r2, r1
	adds r2, #0x13
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
_080B4316:
	adds r1, r4, #0
_080B4318:
	adds r0, r5, #0
	adds r0, #0x58
	bl MainSprite_AdvanceAnim
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B432C: .4byte 0x0000013D
_080B4330: .4byte 0x000005AC
