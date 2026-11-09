	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldrb r0, [r6, #5]
	lsrs r2, r0, #5
	ldr r3, _08156F14 @ =0x000006BA
	adds r0, r5, r3
	movs r4, #0
	ldrsh r3, [r0, r4]
	subs r0, r3, r2
	lsls r4, r0, #5
	cmp r4, #0x80
	ble _08156EF2
	ldr r7, _08156F18 @ =0xFFFFFF00
	adds r4, r4, r7
_08156EF2:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r4, r0
	bge _08156F00
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r4, r0
_08156F00:
	ldr r1, _08156F1C @ =0x0000046D
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	beq _08156F20
	movs r0, #0
	strb r0, [r7]
	movs r0, #1
	b _08156F22
	.align 2, 0
_08156F14: .4byte 0x000006BA
_08156F18: .4byte 0xFFFFFF00
_08156F1C: .4byte 0x0000046D
_08156F20:
	movs r0, #0
_08156F22:
	cmp r0, #0
	bne _08156F28
	b _08157098
_08156F28:
	cmp r2, r3
	bne _08156FA8
	ldr r2, _08156F90 @ =0x0000054F
	adds r0, r6, r2
	ldrb r2, [r0]
	movs r3, #0xa9
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r3, [r0]
	movs r1, #0
	movs r5, #1
	strb r5, [r7]
	ldr r4, _08156F94 @ =0x0000046B
	adds r0, r6, r4
	strb r1, [r0]
	ldr r7, _08156F98 @ =0x00000553
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	adds r4, #0xe1
	adds r0, r6, r4
	ldrb r2, [r0]
	subs r7, #6
	adds r0, r6, r7
	ldrb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	ldrb r4, [r0]
	subs r7, #0xe5
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _08156F9C @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _08156FA0 @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	ldr r4, _08156FA4 @ =0x00000484
	adds r0, r6, r4
	str r1, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _08157258
	.align 2, 0
_08156F90: .4byte 0x0000054F
_08156F94: .4byte 0x0000046B
_08156F98: .4byte 0x00000553
_08156F9C: .4byte 0x00000469
_08156FA0: .4byte 0x0000046A
_08156FA4: .4byte 0x00000484
_08156FA8:
	cmp r4, #0
	blt _08157020
	cmp r2, #7
	bhi _08157098
	lsls r0, r2, #2
	ldr r1, _08156FBC @ =_08156FC0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08156FBC: .4byte _08156FC0
_08156FC0: @ jump table
	.4byte _08156FE0 @ case 0
	.4byte _08156FEA @ case 1
	.4byte _08156FF0 @ case 2
	.4byte _08156FF6 @ case 3
	.4byte _08156FFC @ case 4
	.4byte _08157002 @ case 5
	.4byte _0815700C @ case 6
	.4byte _08157016 @ case 7
_08156FE0:
	adds r0, r6, #0
	movs r1, #0x16
	bl Enemy_PlayAnimNoFacing
	b _08157098
_08156FEA:
	adds r0, r6, #0
	movs r1, #0x17
	b _0815707E
_08156FF0:
	adds r0, r6, #0
	movs r1, #0x18
	b _0815707E
_08156FF6:
	adds r0, r6, #0
	movs r1, #0x19
	b _0815707E
_08156FFC:
	adds r0, r6, #0
	movs r1, #0x1a
	b _0815707E
_08157002:
	adds r0, r6, #0
	movs r1, #0x13
	bl Enemy_PlayAnimNoFacing
	b _08157098
_0815700C:
	adds r0, r6, #0
	movs r1, #0x14
	bl Enemy_PlayAnimNoFacing
	b _08157098
_08157016:
	adds r0, r6, #0
	movs r1, #0x15
	bl Enemy_PlayAnimNoFacing
	b _08157098
_08157020:
	cmp r2, #7
	bhi _08157098
	lsls r0, r2, #2
	ldr r1, _08157030 @ =_08157034
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08157030: .4byte _08157034
_08157034: @ jump table
	.4byte _08157054 @ case 0
	.4byte _0815705E @ case 1
	.4byte _08157068 @ case 2
	.4byte _0815706E @ case 3
	.4byte _08157074 @ case 4
	.4byte _0815707A @ case 5
	.4byte _08157086 @ case 6
	.4byte _08157090 @ case 7
_08157054:
	adds r0, r6, #0
	movs r1, #0x18
	bl Enemy_PlayAnimNoFacing
	b _08157098
_0815705E:
	adds r0, r6, #0
	movs r1, #0x17
	bl Enemy_PlayAnimNoFacing
	b _08157098
_08157068:
	adds r0, r6, #0
	movs r1, #0x16
	b _0815707E
_0815706E:
	adds r0, r6, #0
	movs r1, #0x15
	b _0815707E
_08157074:
	adds r0, r6, #0
	movs r1, #0x14
	b _0815707E
_0815707A:
	adds r0, r6, #0
	movs r1, #0x13
_0815707E:
	movs r2, #1
	bl Enemy_PlayAnimNoFacingFlags
	b _08157098
_08157086:
	adds r0, r6, #0
	movs r1, #0x1a
	bl Enemy_PlayAnimNoFacing
	b _08157098
_08157090:
	adds r0, r6, #0
	movs r1, #0x19
	bl Enemy_PlayAnimNoFacing
_08157098:
	mov r1, r8
	ldrh r0, [r1, #8]
	cmp r0, #2
	bne _081570B6
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _081570B6
	cmp r4, #0
	bge _081570B0
	ldrb r0, [r6, #5]
	subs r0, #0x20
	b _081570B4
_081570B0:
	ldrb r0, [r6, #5]
	adds r0, #0x20
_081570B4:
	strb r0, [r6, #5]
_081570B6:
	ldr r2, _0815711C @ =0x0000046E
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081570C2
	b _08157258
_081570C2:
	ldrb r0, [r6, #5]
	lsrs r0, r0, #5
	ldr r3, _08157120 @ =0x000006BA
	adds r1, r5, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	cmp r1, r0
	beq _08157138
	ldr r4, _08157124 @ =Cockatrice_StateLookTurn
	movs r1, #0x2c
	movs r2, #0
	movs r3, #1
	strb r3, [r7]
	ldr r5, _08157128 @ =0x0000046B
	adds r0, r6, r5
	strb r2, [r0]
	ldr r7, _0815712C @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r4, #0
	strh r2, [r0]
	movs r1, #3
	subs r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r6, r7
	strb r3, [r0]
	ldr r1, _08157130 @ =0x0000046A
	adds r0, r6, r1
	strb r4, [r0]
	ldr r4, _08157134 @ =0x00000484
	adds r0, r6, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r3, [r0]
	b _08157258
	.align 2, 0
_0815711C: .4byte 0x0000046E
_08157120: .4byte 0x000006BA
_08157124: .4byte Cockatrice_StateLookTurn
_08157128: .4byte 0x0000046B
_0815712C: .4byte 0x00000553
_08157130: .4byte 0x0000046A
_08157134: .4byte 0x00000484
_08157138:
	movs r0, #0xd8
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #1
	movs r2, #0
	mov ip, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _081571CC
	ldr r3, _081571B4 @ =0x0000054F
	adds r0, r6, r3
	ldrb r2, [r0]
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r3, [r0]
	movs r4, #1
	strb r4, [r7]
	ldr r5, _081571B8 @ =0x0000046B
	adds r1, r6, r5
	movs r0, #0
	strb r0, [r1]
	ldr r7, _081571BC @ =0x00000553
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	mov r3, ip
	strh r3, [r0]
	adds r5, #0xe1
	adds r0, r6, r5
	ldrb r1, [r0]
	subs r7, #6
	adds r0, r6, r7
	ldrb r2, [r0]
	ldr r3, _081571C0 @ =0x0000054E
	adds r0, r6, r3
	ldrb r3, [r0]
	subs r5, #0xe4
	adds r0, r6, r5
	strb r1, [r0]
	subs r7, #0xe4
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _081571C4 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	ldr r2, _081571C8 @ =0x00000484
	adds r0, r6, r2
	mov r3, ip
	str r3, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r4, [r0]
	b _08157258
	.align 2, 0
_081571B4: .4byte 0x0000054F
_081571B8: .4byte 0x0000046B
_081571BC: .4byte 0x00000553
_081571C0: .4byte 0x0000054E
_081571C4: .4byte 0x0000046A
_081571C8: .4byte 0x00000484
_081571CC:
	ldr r1, _081571F8 @ =0x000006BE
	adds r0, r5, r1
	ldrb r0, [r0]
	ldrb r2, [r6, #5]
	subs r1, r0, r2
	cmp r1, #0x80
	ble _081571DE
	ldr r3, _081571FC @ =0xFFFFFF00
	adds r1, r1, r3
_081571DE:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081571EC
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_081571EC:
	cmp r1, #0
	bge _08157200
	adds r0, r2, #0
	adds r0, #0xe0
	b _08157204
	.align 2, 0
_081571F8: .4byte 0x000006BE
_081571FC: .4byte 0xFFFFFF00
_08157200:
	adds r0, r2, #0
	adds r0, #0x20
_08157204:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsrs r1, r0, #5
	ldr r2, _08157264 @ =0x000006BA
	adds r0, r5, r2
	movs r4, #0
	movs r5, #0
	strh r1, [r0]
	ldr r3, _08157268 @ =Cockatrice_StateLookTurn
	movs r1, #0x2c
	movs r2, #1
	strb r2, [r7]
	ldr r7, _0815726C @ =0x0000046B
	adds r0, r6, r7
	strb r4, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r5, [r0]
	movs r1, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08157270 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _08157274 @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	ldr r4, _08157278 @ =0x00000484
	adds r0, r6, r4
	str r5, [r0]
	ldr r5, _0815727C @ =0x0000046C
	adds r0, r6, r5
	strb r2, [r0]
_08157258:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08157264: .4byte 0x000006BA
_08157268: .4byte Cockatrice_StateLookTurn
_0815726C: .4byte 0x0000046B
_08157270: .4byte 0x00000469
_08157274: .4byte 0x0000046A
_08157278: .4byte 0x00000484
_0815727C: .4byte 0x0000046C
