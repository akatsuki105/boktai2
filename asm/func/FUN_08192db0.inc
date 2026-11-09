	push {r4, r5, r6, lr}
	adds r3, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r6, _08192DE0 @ =0x00000D58
	adds r5, r4, r6
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	subs r1, #0xcc
	ldr r6, _08192DE4 @ =0x0000077A
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08192DE8
	movs r0, #1
	b _08192DEA
	.align 2, 0
_08192DE0: .4byte 0x00000D58
_08192DE4: .4byte 0x0000077A
_08192DE8:
	movs r0, #0
_08192DEA:
	cmp r0, #0
	beq _08192E1C
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r2, _08192E10 @ =0x0000068A
	adds r1, r1, r2
	ldr r2, _08192E14 @ =0x000001AD
	strh r2, [r1]
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r1, r4, r6
	adds r1, r1, r0
	ldr r2, _08192E18 @ =0x00000EA8
	b _08192ED6
	.align 2, 0
_08192E10: .4byte 0x0000068A
_08192E14: .4byte 0x000001AD
_08192E18: .4byte 0x00000EA8
_08192E1C:
	ldr r6, _08192E4C @ =0x00000F36
	adds r0, r4, r6
	movs r6, #0
	ldrsh r1, [r0, r6]
	subs r0, r1, #1
	cmp r3, r0
	bne _08192E58
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r2, _08192E50 @ =0x0000068A
	adds r1, r1, r2
	movs r2, #0xd6
	lsls r2, r2, #1
	strh r2, [r1]
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r1, r4, r6
	adds r1, r1, r0
	ldr r2, _08192E54 @ =0x00000E88
	b _08192ED6
	.align 2, 0
_08192E4C: .4byte 0x00000F36
_08192E50: .4byte 0x0000068A
_08192E54: .4byte 0x00000E88
_08192E58:
	subs r0, r1, #2
	cmp r3, r0
	bne _08192E90
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r6, _08192E84 @ =0x0000068A
	adds r1, r1, r6
	ldr r2, _08192E88 @ =0x000001AB
	strh r2, [r1]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r4, r2
	adds r1, r1, r0
	ldr r6, _08192E8C @ =0x00000E68
	adds r0, r4, r6
	str r0, [r1]
	b _08192F56
	.align 2, 0
_08192E84: .4byte 0x0000068A
_08192E88: .4byte 0x000001AB
_08192E8C: .4byte 0x00000E68
_08192E90:
	subs r0, r1, #3
	cmp r3, r0
	bne _08192EE4
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r6, _08192EAC @ =0x00000F2C
	adds r0, r4, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08192EB0
	movs r0, #1
	b _08192EB2
	.align 2, 0
_08192EAC: .4byte 0x00000F2C
_08192EB0:
	movs r0, #0
_08192EB2:
	cmp r0, #0
	bne _08192EE4
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r2, _08192EDC @ =0x0000068A
	adds r1, r1, r2
	movs r2, #0xd5
	lsls r2, r2, #1
	strh r2, [r1]
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r1, r4, r6
	adds r1, r1, r0
	ldr r2, _08192EE0 @ =0x00000E48
_08192ED6:
	adds r0, r4, r2
	str r0, [r1]
	b _08192F56
	.align 2, 0
_08192EDC: .4byte 0x0000068A
_08192EE0: .4byte 0x00000E48
_08192EE4:
	cmp r2, #1
	beq _08192F20
	cmp r2, #1
	bgt _08192EF2
	cmp r2, #0
	beq _08192EF8
	b _08192F56
_08192EF2:
	cmp r2, #2
	beq _08192F40
	b _08192F56
_08192EF8:
	lsls r1, r3, #3
	adds r1, r1, r3
	lsls r1, r1, #3
	adds r1, r1, r3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r6, _08192F18 @ =0x0000068A
	adds r0, r0, r6
	ldr r2, _08192F1C @ =0x000001A9
	strh r2, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r0, r4, r2
	adds r0, r0, r1
	str r5, [r0]
	b _08192F56
	.align 2, 0
_08192F18: .4byte 0x0000068A
_08192F1C: .4byte 0x000001A9
_08192F20:
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r6, _08192F3C @ =0x00000684
	adds r0, r0, r6
	movs r1, #0xd4
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _08192F56
	.align 2, 0
_08192F3C: .4byte 0x00000684
_08192F40:
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, _08192F5C @ =0x00000684
	adds r0, r0, r1
	ldr r1, _08192F60 @ =0x000001A3
	bl Video_SetAuxSpritePltt
_08192F56:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08192F5C: .4byte 0x00000684
_08192F60: .4byte 0x000001A3
