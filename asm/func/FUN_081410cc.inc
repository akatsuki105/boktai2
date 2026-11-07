	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _081410EC @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081410F0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081410F2
	.align 2, 0
_081410EC: .4byte 0x0000046C
_081410F0:
	movs r0, #0
_081410F2:
	cmp r0, #0
	bne _081410F8
	b _0814120A
_081410F8:
	ldr r2, _08141170 @ =EnemyBat_HoldPlayer
	movs r1, #0x23
	ldr r3, _08141174 @ =0x0000046D
	adds r0, r6, r3
	movs r4, #0
	movs r5, #1
	strb r5, [r0]
	subs r3, #2
	adds r0, r6, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r6, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	movs r3, #0xd6
	lsls r3, r3, #3
	adds r1, r7, r3
	str r4, [sp]
	mov r0, sp
	ldr r2, _08141178 @ =0x05000002
	bl CpuSet
	ldr r1, _0814117C @ =0x00000667
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _08141180 @ =0x0000066C
	adds r0, r7, r2
	strh r4, [r0]
	ldr r2, _08141184 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08141188 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0814118C @ =0x0203B400
	adds r0, r0, r3
	ldrb r4, [r0]
	ldr r0, _08141190 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r1, _08141194 @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08141198
	asrs r0, r0, #3
	b _0814119E
	.align 2, 0
_08141170: .4byte EnemyBat_HoldPlayer
_08141174: .4byte 0x0000046D
_08141178: .4byte 0x05000002
_0814117C: .4byte 0x00000667
_08141180: .4byte 0x0000066C
_08141184: .4byte 0x030046B8
_08141188: .4byte 0x000003FF
_0814118C: .4byte 0x0203B400
_08141190: .4byte 0x03002BE0
_08141194: .4byte gSineTable
_08141198:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0814119E:
	add r3, sp, #4
	ldrh r1, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081411CC @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	ldr r2, _081411D0 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _081411D4
	asrs r0, r0, #3
	b _081411DA
	.align 2, 0
_081411CC: .4byte 0xFFFF0000
_081411D0: .4byte gSineTable
_081411D4:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_081411DA:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814123C @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	adds r0, r6, #0
	adds r1, r3, #0
	bl EnemyBat_StartCurve
	adds r0, r6, #0
	bl EnemyBat_StepCurve
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0814120A:
	ldr r0, _08141240 @ =0x0000066C
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08141248
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08141220
	b _081413F4
_08141220:
	ldr r0, _08141244 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r6, #0
	bl EnemyBat_BeginCurveMove
	movs r2, #8
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081413F4
	.align 2, 0
_0814123C: .4byte 0xFFFF0000
_08141240: .4byte 0x0000066C
_08141244: .4byte 0x03002BE0
_08141248:
	adds r0, r6, #0
	bl EnemyBat_UpdateCurveBend
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	adds r4, r0, #0
	ldr r2, _08141298 @ =0x000004A4
	adds r0, r6, r2
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
	bge _08141280
	rsbs r2, r2, #0
_08141280:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0814129C
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0814128E
	rsbs r2, r2, #0
_0814128E:
	cmp r2, #0x20
	bgt _0814129C
	movs r0, #1
	b _08141306
	.align 2, 0
_08141298: .4byte 0x000004A4
_0814129C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _081412A8
	cmp r1, #0
	beq _08141304
_081412A8:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r6, #5]
	ldr r2, _081412CC @ =gSineTable
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _081412D0
	asrs r1, r0, #0xc
	b _081412D6
	.align 2, 0
_081412CC: .4byte gSineTable
_081412D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081412D6:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	ldr r1, _081412F4 @ =gSineTable
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081412F8
	asrs r1, r0, #0xc
	b _081412FE
	.align 2, 0
_081412F4: .4byte gSineTable
_081412F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081412FE:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
_08141304:
	movs r0, #0
_08141306:
	cmp r0, #0
	beq _081413BE
	adds r0, r6, #0
	bl EnemyBat_StepCurve
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081413BE
	ldr r2, _0814134C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08141350 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08141354 @ =0x0203B400
	adds r0, r0, r2
	ldrb r4, [r0]
	ldr r0, _08141358 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r1, _0814135C @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r5, r1, #0
	cmp r0, #0
	blt _08141360
	asrs r0, r0, #3
	b _08141366
	.align 2, 0
_0814134C: .4byte 0x030046B8
_08141350: .4byte 0x000003FF
_08141354: .4byte 0x0203B400
_08141358: .4byte 0x03002BE0
_0814135C: .4byte gSineTable
_08141360:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_08141366:
	add r3, sp, #0xc
	ldrh r1, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08141394 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08141398
	asrs r1, r0, #3
	b _0814139E
	.align 2, 0
_08141394: .4byte 0xFFFF0000
_08141398:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_0814139E:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _081413E8 @ =0xFFFF0000
	ldr r1, [r3, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [r3, #4]
	adds r0, r6, #0
	adds r1, r3, #0
	bl EnemyBat_StartCurve
	adds r0, r6, #0
	bl EnemyBat_StepCurve
_081413BE:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r0, _081413EC @ =0x0000FDE8
	cmp r1, r0
	bls _081413F4
	adds r0, r6, #0
	bl FUN_08140904
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r6, #5]
	ldr r0, _081413F0 @ =0x0000066C
	adds r1, r7, r0
	movs r0, #0x1e
	strh r0, [r1]
	b _0814143A
	.align 2, 0
_081413E8: .4byte 0xFFFF0000
_081413EC: .4byte 0x0000FDE8
_081413F0: .4byte 0x0000066C
_081413F4:
	ldr r1, _08141428 @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08141430
	movs r2, #4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r2, [r0]
	ldr r2, _0814142C @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _0814143A
	.align 2, 0
_08141428: .4byte 0x0000046B
_0814142C: .4byte 0x00000484
_08141430:
	ldr r0, _08141444 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0814143A:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08141444: .4byte 0x00000484
