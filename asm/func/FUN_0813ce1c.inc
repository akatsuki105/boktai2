	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _0813CE3C @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813CE40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813CE42
	.align 2, 0
_0813CE3C: .4byte 0x0000046C
_0813CE40:
	movs r0, #0
_0813CE42:
	cmp r0, #0
	beq _0813CE88
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r1, [r0]
	movs r4, #1
	ldr r2, _0813CEC4 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	strb r4, [r0]
	ldr r3, _0813CEC8 @ =0x0000046B
	adds r0, r6, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r6, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r6, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r1, r5, r3
	str r2, [sp]
	mov r0, sp
	ldr r2, _0813CECC @ =0x05000002
	bl CpuSet
	ldr r1, _0813CED0 @ =0x00000667
	adds r0, r5, r1
	strb r4, [r0]
_0813CE88:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	adds r5, r0, #0
	ldr r1, _0813CED4 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813CEDC
	ldr r3, _0813CED8 @ =0x00000482
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0813CEEC
	.align 2, 0
_0813CEC4: .4byte 0x0000046D
_0813CEC8: .4byte 0x0000046B
_0813CECC: .4byte 0x05000002
_0813CED0: .4byte 0x00000667
_0813CED4: .4byte 0x0000A02F
_0813CED8: .4byte 0x00000482
_0813CEDC:
	ldr r1, _0813CF10 @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0813CEEC
	movs r0, #1
	strh r0, [r2]
_0813CEEC:
	ldr r3, _0813CF14 @ =0x0000025D
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813CF18
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _0813CF30
	.align 2, 0
_0813CF10: .4byte 0x00000482
_0813CF14: .4byte 0x0000025D
_0813CF18:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_0813CF30:
	adds r0, r6, #0
	bl FUN_0813c38c
	ldr r1, _0813CF70 @ =0x000004A4
	adds r0, r6, r1
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r6, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r6, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _0813CF58
	rsbs r2, r2, #0
_0813CF58:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0813CF74
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0813CF66
	rsbs r2, r2, #0
_0813CF66:
	cmp r2, #0x20
	bgt _0813CF74
	movs r0, #1
	b _0813CFDE
	.align 2, 0
_0813CF70: .4byte 0x000004A4
_0813CF74:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0813CF80
	cmp r1, #0
	beq _0813CFDC
_0813CF80:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r6, #5]
	ldr r2, _0813CFA4 @ =gSineTable
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0813CFA8
	asrs r1, r0, #0xc
	b _0813CFAE
	.align 2, 0
_0813CFA4: .4byte gSineTable
_0813CFA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813CFAE:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	ldr r1, _0813CFCC @ =gSineTable
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _0813CFD0
	asrs r1, r0, #0xc
	b _0813CFD6
	.align 2, 0
_0813CFCC: .4byte gSineTable
_0813CFD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813CFD6:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
_0813CFDC:
	movs r0, #0
_0813CFDE:
	cmp r0, #0
	beq _0813D05C
	adds r0, r6, #0
	bl Curoro_StepCurve
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813D05C
	ldr r5, _0813D070 @ =0x03002BE0
	ldr r1, [r5]
	adds r1, #0x2c
	adds r0, r6, #0
	bl Curoro_StartCurve
	adds r0, r6, #0
	bl Curoro_StepCurve
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0813D074 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r2, [r0]
	adds r3, #0x1a
	adds r0, r6, r3
	str r1, [r0]
	ldr r1, _0813D078 @ =0x0000046C
	adds r0, r6, r1
	strb r2, [r0]
	add r2, sp, #4
	adds r4, r6, #0
	adds r4, #8
	ldr r0, [r5]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
_0813D05C:
	ldr r3, _0813D07C @ =0x00000484
	adds r1, r6, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813D070: .4byte 0x03002BE0
_0813D074: .4byte 0x00000469
_0813D078: .4byte 0x0000046C
_0813D07C: .4byte 0x00000484
