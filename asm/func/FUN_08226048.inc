	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08226078
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08226074 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _0822607A
	.align 2, 0
_08226074: .4byte 0x00000F14
_08226078:
	movs r0, #0
_0822607A:
	cmp r0, #0
	bne _08226080
	b _082261AE
_08226080:
	ldr r3, _08226120 @ =0x00000F58
	adds r1, r6, r3
	movs r0, #0
	str r0, [r1]
	ldr r4, _08226124 @ =0x00000DB8
	adds r0, r6, r4
	ldrh r1, [r0]
	ldr r5, _08226128 @ =0x00000E94
	adds r0, r6, r5
	movs r2, #0
	strh r1, [r0]
	ldr r1, _0822612C @ =0x00000DBA
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r3, #0xc2
	adds r0, r6, r3
	strh r1, [r0]
	adds r4, #4
	adds r0, r6, r4
	ldrh r1, [r0]
	adds r5, #4
	adds r0, r6, r5
	strh r1, [r0]
	ldr r1, _08226130 @ =0x00000F15
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _08226134 @ =0x00000F5C
	adds r0, r6, r2
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	movs r3, #1
	rsbs r3, r3, #0
	adds r1, r3, #0
	cmp r0, #0
	beq _082260CA
	movs r1, #1
_082260CA:
	ldr r4, _08226138 @ =0x00000F25
	adds r0, r6, r4
	strb r1, [r0]
	ldr r5, _0822613C @ =0x00000DF4
	adds r0, r6, r5
	bl FUN_080136b4
	ldr r1, _08226140 @ =0x00000F2B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08226106
	ldr r2, _08226144 @ =0x00000DA4
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x7f
	beq _08226106
	ldr r3, _08226148 @ =0x00000D9C
	adds r0, r6, r3
	ldr r0, [r0]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08226106
	adds r4, #0x2b
	adds r1, r6, r4
	ldr r0, _0822614C @ =FUN_082239c0
	str r0, [r1]
_08226106:
	ldr r5, _08226150 @ =0x00000F33
	adds r0, r6, r5
	ldrb r2, [r0]
	cmp r2, #0
	bne _0822615C
	ldr r0, _08226154 @ =0x00000E8C
	adds r1, r6, r0
	movs r0, #0x19
	strh r0, [r1]
	ldr r3, _08226158 @ =0x00000E8E
	adds r1, r6, r3
	movs r0, #0x66
	b _082261A4
	.align 2, 0
_08226120: .4byte 0x00000F58
_08226124: .4byte 0x00000DB8
_08226128: .4byte 0x00000E94
_0822612C: .4byte 0x00000DBA
_08226130: .4byte 0x00000F15
_08226134: .4byte 0x00000F5C
_08226138: .4byte 0x00000F25
_0822613C: .4byte 0x00000DF4
_08226140: .4byte 0x00000F2B
_08226144: .4byte 0x00000DA4
_08226148: .4byte 0x00000D9C
_0822614C: .4byte FUN_082239c0
_08226150: .4byte 0x00000F33
_08226154: .4byte 0x00000E8C
_08226158: .4byte 0x00000E8E
_0822615C:
	ldr r0, _08226188 @ =gClock
	ldrb r0, [r0, #0xe]
	cmp r0, #5
	beq _08226194
	cmp r0, #0
	beq _08226194
	cmp r0, #4
	beq _08226194
	ldr r5, _0822618C @ =0x00000E8C
	adds r1, r6, r5
	movs r2, #0
	movs r0, #0x19
	strh r0, [r1]
	ldr r0, _08226190 @ =0x00000E8E
	adds r1, r6, r0
	movs r0, #0x5c
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #4
	adds r0, r6, r1
	b _082261AC
	.align 2, 0
_08226188: .4byte gClock
_0822618C: .4byte 0x00000E8C
_08226190: .4byte 0x00000E8E
_08226194:
	ldr r2, _08226214 @ =0x00000E8C
	adds r1, r6, r2
	movs r2, #0
	movs r0, #0x19
	strh r0, [r1]
	ldr r3, _08226218 @ =0x00000E8E
	adds r1, r6, r3
	movs r0, #0x4b
_082261A4:
	strh r0, [r1]
	movs r4, #0xe9
	lsls r4, r4, #4
	adds r0, r6, r4
_082261AC:
	strh r2, [r0]
_082261AE:
	ldr r5, _08226214 @ =0x00000E8C
	adds r0, r6, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, _0822621C @ =0x00000DB8
	adds r1, r6, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	ldr r4, _08226218 @ =0x00000E8E
	adds r1, r6, r4
	movs r5, #0
	ldrsh r1, [r1, r5]
	ldr r3, _08226220 @ =0x00000DBA
	adds r2, r6, r3
	movs r4, #0
	ldrsh r2, [r2, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _08226224 @ =0x00000F1C
	adds r1, r6, r5
	strh r0, [r1]
	ldr r0, _08226228 @ =0x00000D9C
	adds r5, r6, r0
	ldr r1, _0822622C @ =0x00000DE4
	adds r4, r6, r1
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08226230
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08226238
	.align 2, 0
_08226214: .4byte 0x00000E8C
_08226218: .4byte 0x00000E8E
_0822621C: .4byte 0x00000DB8
_08226220: .4byte 0x00000DBA
_08226224: .4byte 0x00000F1C
_08226228: .4byte 0x00000D9C
_0822622C: .4byte 0x00000DE4
_08226230:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08226238:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0822625C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08226264
_0822625C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08226264:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0822629C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _082262E2
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082262A6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082262A0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _082262BC
	.align 2, 0
_0822629C: .4byte 0x0000FFFF
_082262A0:
	subs r0, #1
	strh r0, [r4, #8]
	b _082262BA
_082262A6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _082262BA
	strh r1, [r4, #8]
	movs r2, #1
	b _082262BC
_082262BA:
	movs r2, #0
_082262BC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _082262E4
	movs r0, #1
	strb r0, [r4, #7]
	b _082262E4
_082262E2:
	movs r2, #0
_082262E4:
	ldr r3, _08226390 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	ldr r4, _08226394 @ =0x00000F58
	adds r1, r6, r4
	ldr r0, [r1]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r1]
	cmp r2, #0x1f
	ble _082263B8
	ldr r5, _08226398 @ =0x00000E8C
	adds r0, r6, r5
	ldrh r1, [r0]
	ldr r2, _0822639C @ =0x00000DB8
	adds r0, r6, r2
	strh r1, [r0]
	subs r3, #0x86
	adds r0, r6, r3
	ldrh r1, [r0]
	ldr r4, _082263A0 @ =0x00000DBA
	adds r0, r6, r4
	strh r1, [r0]
	adds r5, #0x8a
	adds r4, r6, r5
	ldrb r0, [r4]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _082263A4 @ =0x00000F18
	adds r3, r6, r1
	strh r0, [r3]
	movs r2, #3
	ldrb r1, [r4]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	ldrh r1, [r4]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	cmp r0, #3
	bne _08226366
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08226366
	ldr r2, _082263A8 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r3, _082263AC @ =0x00000F42
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, _082263B0 @ =0x00000DF2
	adds r0, r6, r4
	ldrh r1, [r0]
	adds r5, #0x2d
	adds r0, r6, r5
	strb r1, [r0]
_08226366:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, _082263B4 @ =0x00000F0C
	adds r1, r6, r2
	ldr r2, [r1]
	cmp r2, #0
	bne _08226380
	b _082264DE
_08226380:
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl Script_ExecById
	b _082264DE
	.align 2, 0
_08226390: .4byte 0x00000F14
_08226394: .4byte 0x00000F58
_08226398: .4byte 0x00000E8C
_0822639C: .4byte 0x00000DB8
_082263A0: .4byte 0x00000DBA
_082263A4: .4byte 0x00000F18
_082263A8: .4byte 0x00000DEC
_082263AC: .4byte 0x00000F42
_082263B0: .4byte 0x00000DF2
_082263B4: .4byte 0x00000F0C
_082263B8:
	ldr r3, _0822641C @ =0x00000F1C
	adds r0, r6, r3
	ldrh r0, [r0]
	subs r0, #0x10
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	ldr r4, _08226420 @ =0x00000F22
	adds r3, r6, r4
	ldr r0, _08226424 @ =0x00000F27
	adds r5, r6, r0
	lsls r0, r2, #0x10
	cmp r0, #0
	bge _082263E6
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
_082263D8:
	asrs r0, r0, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r2, #0x10
	cmp r0, #0
	blt _082263D8
_082263E6:
	lsls r1, r2, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0xff
	ble _08226402
	ldr r0, _08226428 @ =0xFFFFFF00
	adds r4, r0, #0
_082263F2:
	asrs r0, r1, #0x10
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r2, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0xff
	bgt _082263F2
_08226402:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r0, #0x10
	asrs r2, r0, #5
	movs r0, #7
	ands r2, r0
	adds r0, r2, #0
	cmp r0, #4
	bne _0822642C
	movs r0, #0
	strb r0, [r3]
	b _0822644C
	.align 2, 0
_0822641C: .4byte 0x00000F1C
_08226420: .4byte 0x00000F22
_08226424: .4byte 0x00000F27
_08226428: .4byte 0xFFFFFF00
_0822642C:
	cmp r0, #0
	bne _08226436
	movs r0, #4
	strb r0, [r3]
	b _0822644C
_08226436:
	cmp r0, #3
	bgt _08226444
	movs r0, #4
	subs r0, r0, r2
	strb r0, [r3]
	movs r0, #1
	b _0822644A
_08226444:
	subs r0, r2, #4
	strb r0, [r3]
	movs r0, #0
_0822644A:
	strb r0, [r5]
_0822644C:
	ldr r1, _082264E8 @ =0x00000DE4
	adds r0, r6, r1
	ldr r2, _082264EC @ =0x00000E34
	adds r1, r6, r2
	ldr r1, [r1]
	ldr r3, _082264F0 @ =0x00000F15
	adds r2, r6, r3
	ldrb r2, [r2]
	ldr r4, _082264F4 @ =0x00000F22
	adds r3, r6, r4
	ldrb r3, [r3]
	ldr r5, _082264F8 @ =0x00000F27
	adds r4, r6, r5
	ldrb r4, [r4]
	str r4, [sp]
	bl FUN_08236fac
	ldr r1, _082264FC @ =0x00000E8C
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _08226500 @ =0x00000E94
	adds r4, r6, r3
	movs r5, #0
	ldrsh r0, [r4, r5]
	subs r1, r1, r0
	ldr r0, _08226504 @ =0x00000F58
	adds r5, r6, r0
	ldr r0, [r5]
	muls r0, r1, r0
	movs r1, #0x20
	bl Div
	ldrh r1, [r4]
	adds r1, r1, r0
	ldr r2, _08226508 @ =0x00000DB8
	adds r0, r6, r2
	strh r1, [r0]
	ldr r3, _0822650C @ =0x00000E8E
	adds r0, r6, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r0, _08226510 @ =0x00000E96
	adds r4, r6, r0
	movs r2, #0
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	ldr r0, [r5]
	muls r0, r1, r0
	movs r1, #0x20
	bl Div
	ldrh r2, [r4]
	adds r2, r2, r0
	ldr r3, _08226514 @ =0x00000F25
	adds r0, r6, r3
	movs r4, #0
	ldrsb r4, [r0, r4]
	ldr r3, _08226518 @ =0x085B0A08
	ldr r0, [r5]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	muls r0, r4, r0
	adds r2, r2, r0
	ldr r4, _0822651C @ =0x00000DBA
	adds r0, r6, r4
	strh r2, [r0]
_082264DE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082264E8: .4byte 0x00000DE4
_082264EC: .4byte 0x00000E34
_082264F0: .4byte 0x00000F15
_082264F4: .4byte 0x00000F22
_082264F8: .4byte 0x00000F27
_082264FC: .4byte 0x00000E8C
_08226500: .4byte 0x00000E94
_08226504: .4byte 0x00000F58
_08226508: .4byte 0x00000DB8
_0822650C: .4byte 0x00000E8E
_08226510: .4byte 0x00000E96
_08226514: .4byte 0x00000F25
_08226518: .4byte 0x085B0A08
_0822651C: .4byte 0x00000DBA
