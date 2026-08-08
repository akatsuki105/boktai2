	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r5, r0, #0
	ldr r0, _080F0EE8 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F0E94
	movs r0, #0
	strb r0, [r1]
_080F0E94:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F0EAA
	b _080F11BA
_080F0EAA:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F0EB8
	b _080F11BA
_080F0EB8:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r2, _080F0EEC @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _080F0EF4
	ldr r0, _080F0EF0 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _080F0F04
	.align 2, 0
_080F0EE8: .4byte 0x0000046C
_080F0EEC: .4byte 0x0000A02F
_080F0EF0: .4byte 0x00000482
_080F0EF4:
	ldr r1, _080F0F28 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _080F0F04
	movs r0, #1
	strh r0, [r2]
_080F0F04:
	ldr r4, _080F0F2C @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F0F30
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _080F0F48
	.align 2, 0
_080F0F28: .4byte 0x00000482
_080F0F2C: .4byte 0x0000025D
_080F0F30:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_080F0F48:
	ldr r0, _080F0F84 @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	bne _080F0F5A
	b _080F1178
_080F0F5A:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F0F70
	b _080F11B0
_080F0F70:
	movs r2, #4
	ldr r4, _080F0F88 @ =0x00000222
	adds r1, r5, r4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _080F0F8C
	movs r0, #1
	b _080F0F8E
	.align 2, 0
_080F0F84: .4byte 0x000004A4
_080F0F88: .4byte 0x00000222
_080F0F8C:
	movs r0, #0
_080F0F8E:
	cmp r0, #0
	beq _080F0F94
	b _080F1150
_080F0F94:
	adds r0, r5, #0
	bl FUN_080eb2a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F0FA2
	b _080F11BA
_080F0FA2:
	movs r1, #1
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080F0FB0
	movs r0, #1
	b _080F0FB2
_080F0FB0:
	movs r0, #0
_080F0FB2:
	cmp r0, #0
	bne _080F0FB8
	b _080F1150
_080F0FB8:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080F0FDA
	b _080F11BA
_080F0FDA:
	movs r1, #4
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080F0FE8
	movs r0, #1
	b _080F0FEA
_080F0FE8:
	movs r0, #0
_080F0FEA:
	cmp r0, #0
	beq _080F0FF0
	b _080F11BA
_080F0FF0:
	movs r4, #0
	ldr r0, _080F110C @ =0x0000046C
	adds r0, r5, r0
	str r0, [sp, #0x28]
	ldrb r7, [r5, #5]
	movs r1, #0xa8
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0x3c]
	movs r2, #0xa9
	lsls r2, r2, #3
	adds r2, r5, r2
	str r2, [sp, #0xc]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r5
	mov sb, r0
	ldr r1, _080F1110 @ =0x00000553
	adds r1, r1, r5
	mov ip, r1
	ldr r2, _080F1114 @ =0x0000054F
	adds r2, r5, r2
	str r2, [sp, #0x1c]
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r5, r0
	str r0, [sp, #0x20]
	ldr r1, _080F1118 @ =0x0000054C
	adds r1, r5, r1
	str r1, [sp, #0x10]
	ldr r2, _080F111C @ =0x00000469
	adds r2, r2, r5
	mov sl, r2
	ldr r0, _080F1120 @ =0x0000054D
	adds r0, r5, r0
	str r0, [sp, #0x14]
	ldr r1, _080F1124 @ =0x0000046A
	adds r1, r1, r5
	mov r8, r1
	ldr r2, _080F1128 @ =0x0000054E
	adds r2, r5, r2
	str r2, [sp, #0x18]
	ldr r0, _080F112C @ =0x00000541
	adds r0, r5, r0
	str r0, [sp, #0x40]
	ldr r1, _080F1130 @ =0x000005BC
	adds r1, r5, r1
	str r1, [sp, #0x34]
	ldr r2, _080F1134 @ =0x0000046D
	adds r2, r5, r2
	str r2, [sp, #0x2c]
	ldr r0, _080F1138 @ =0x0000046B
	adds r0, r5, r0
	str r0, [sp, #0x24]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r5, r1
	str r1, [sp, #0x38]
	ldr r2, _080F113C @ =0x00000484
	adds r2, r5, r2
	str r2, [sp, #0x30]
	ldr r0, _080F1140 @ =0x00000542
	adds r0, r5, r0
	str r0, [sp, #8]
	ldr r2, _080F1144 @ =0x0203B400
	ldr r1, _080F1148 @ =0x030046B8
	ldr r6, _080F114C @ =0x000003FF
	movs r5, #3
	adds r3, r7, #0
_080F107A:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r3
	bne _080F1098
	adds r4, #1
	cmp r4, #3
	ble _080F107A
	adds r0, r7, #0
_080F1098:
	movs r3, #0
	ldr r1, [sp, #0x3c]
	strb r0, [r1]
	mov r2, sb
	ldr r0, [r2]
	ldr r4, [sp, #0xc]
	str r0, [r4]
	mov r1, ip
	ldrb r0, [r1]
	ldr r2, [sp, #0x1c]
	strb r0, [r2]
	ldr r4, [sp, #0x20]
	ldrb r0, [r4]
	ldr r1, [sp, #0x10]
	strb r0, [r1]
	mov r2, sl
	ldrb r0, [r2]
	ldr r4, [sp, #0x14]
	strb r0, [r4]
	mov r1, r8
	ldrb r0, [r1]
	ldr r2, [sp, #0x18]
	strb r0, [r2]
	mov r4, sp
	ldrb r0, [r4, #4]
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r1, [sp, #0x34]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x2c]
	strb r1, [r4]
	ldr r4, [sp, #0x24]
	strb r3, [r4]
	mov r4, ip
	strb r0, [r4]
	mov r0, sb
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x38]
	strh r3, [r4]
	movs r0, #3
	ldr r4, [sp, #0x20]
	strb r0, [r4]
	mov r0, sl
	strb r1, [r0]
	mov r4, r8
	strb r2, [r4]
	ldr r0, [sp, #0x30]
	str r3, [r0]
	ldr r2, [sp, #0x28]
	strb r1, [r2]
	movs r0, #2
	ldr r4, [sp, #8]
	strb r0, [r4]
	b _080F11BA
	.align 2, 0
_080F110C: .4byte 0x0000046C
_080F1110: .4byte 0x00000553
_080F1114: .4byte 0x0000054F
_080F1118: .4byte 0x0000054C
_080F111C: .4byte 0x00000469
_080F1120: .4byte 0x0000054D
_080F1124: .4byte 0x0000046A
_080F1128: .4byte 0x0000054E
_080F112C: .4byte 0x00000541
_080F1130: .4byte 0x000005BC
_080F1134: .4byte 0x0000046D
_080F1138: .4byte 0x0000046B
_080F113C: .4byte 0x00000484
_080F1140: .4byte 0x00000542
_080F1144: .4byte 0x0203B400
_080F1148: .4byte 0x030046B8
_080F114C: .4byte 0x000003FF
_080F1150:
	movs r1, #0xd
	ldr r2, _080F116C @ =0x0000046A
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _080F1170 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	ldr r0, _080F1174 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _080F11B0
	.align 2, 0
_080F116C: .4byte 0x0000046A
_080F1170: .4byte 0x00000484
_080F1174: .4byte 0x0000046C
_080F1178:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F11B0
	movs r1, #0xe
	ldr r2, _080F11A4 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _080F11A8 @ =0x00000484
	adds r0, r5, r4
	str r6, [r0]
	ldr r0, _080F11AC @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _080F11BA
	.align 2, 0
_080F11A4: .4byte 0x0000046A
_080F11A8: .4byte 0x00000484
_080F11AC: .4byte 0x0000046C
_080F11B0:
	ldr r2, _080F11CC @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F11BA:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F11CC: .4byte 0x00000484
