	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r5, r0, #0
	mov r8, r5
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r0, r5
	mov sl, r0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FCC28
	movs r3, #0
	strb r3, [r1]
	movs r2, #0x14
	subs r1, #0x11
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add r0, sp, #0x3c
	movs r1, #0xf0
	lsls r1, r1, #3
	strh r1, [r0]
	strh r3, [r0, #2]
	strh r1, [r0, #4]
	adds r6, r0, #0
	movs r1, #7
	adds r7, r6, #0
	ldr r0, _081FCB74 @ =0x030046A8
	ldr r0, [r0]
	cmp r1, r0
	bhs _081FCB6E
	ldr r0, _081FCB78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FCB7C
_081FCB6E:
	movs r4, #0
	b _081FCB84
	.align 2, 0
_081FCB74: .4byte 0x030046A8
_081FCB78: .4byte 0x030046AC
_081FCB7C:
	ldr r0, _081FCB94 @ =0x030046A4
	ldr r0, [r0]
	ldrh r0, [r0, #0x32]
	adds r4, r0, #7
_081FCB84:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FCB98
	adds r0, #4
	b _081FCBA4
	.align 2, 0
_081FCB94: .4byte 0x030046A4
_081FCB98:
	ldr r0, _081FCC3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FCBA4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	adds r2, r5, #0
	adds r2, #0x50
	add r0, sp, #0x3c
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Boss_PlayAnimFacing
	mov r0, sl
	bl NestedState_Reset0
	mov r0, sl
	movs r1, #1
	bl NestedState_Set0
_081FCC28:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #1
	bne _081FCC32
	b _081FCE44
_081FCC32:
	cmp r0, #1
	bgt _081FCC40
	cmp r0, #0
	beq _081FCC4E
	b _081FCF3E
	.align 2, 0
_081FCC3C: .4byte 0x030046A4
_081FCC40:
	cmp r0, #2
	bne _081FCC46
	b _081FCEC2
_081FCC46:
	cmp r0, #3
	bne _081FCC4C
	b _081FCF1C
_081FCC4C:
	b _081FCF3E
_081FCC4E:
	movs r2, #0x14
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add r4, sp, #0x44
	adds r2, r5, #0
	adds r2, #0x50
	ldr r3, _081FCCB4 @ =0x00000808
	add r3, r8
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r6, #0x1e
	movs r2, #0
	ldrsh r0, [r4, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r7, r1, r0
	adds r0, r7, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _081FCCB8
	movs r1, #1
	rsbs r1, r1, #0
	b _081FCCE4
	.align 2, 0
_081FCCB4: .4byte 0x00000808
_081FCCB8:
	movs r3, #0
	ldrsh r0, [r4, r3]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4]
	movs r1, #2
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
	adds r1, r7, #0
_081FCCE4:
	ldr r0, _081FCCF4 @ =0x0000038B
	cmp r1, r0
	bgt _081FCCF8
	mov r0, sl
	movs r1, #1
	bl NestedState_Set0
	b _081FCE2E
	.align 2, 0
_081FCCF4: .4byte 0x0000038B
_081FCCF8:
	mov r3, sl
	ldr r0, [r3, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _081FCD06
	b _081FCE2E
_081FCD06:
	ldr r5, _081FCD4C @ =0x00000808
	add r5, r8
	add r0, sp, #0x44
	ldrh r0, [r0]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r4, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r4, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
	ldr r6, _081FCD50 @ =0x030046B8
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _081FCD54 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FCD58 @ =0x0203B400
	adds r0, r0, r2
	movs r3, #0xff
	mov sb, r3
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FCD5C
	adds r0, r5, #0
	bl FUN_081fae7c
	b _081FCE2E
	.align 2, 0
_081FCD4C: .4byte 0x00000808
_081FCD50: .4byte 0x030046B8
_081FCD54: .4byte 0x000003FF
_081FCD58: .4byte 0x0203B400
_081FCD5C:
	add r4, sp, #0x4c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081FCDAC @ =0x05000002
	bl CpuSet
	ldr r0, [r6]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	lsls r1, r0, #1
	ldr r2, _081FCDB0 @ =0x0203B400
	adds r1, r1, r2
	ldrh r7, [r1]
	mov r3, sb
	ands r7, r3
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r6, [r0]
	ands r6, r3
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0x54]
	str r1, [sp, #0x58]
	ldr r1, _081FCDB4 @ =gSineTable
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081FCDB8
	asrs r0, r0, #0xc
	b _081FCDBE
	.align 2, 0
_081FCDAC: .4byte 0x05000002
_081FCDB0: .4byte 0x0203B400
_081FCDB4: .4byte gSineTable
_081FCDB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FCDBE:
	add r3, sp, #0x54
	ldrh r1, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081FCDE8 @ =0xFFFF0000
	ldr r0, [sp, #0x54]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x54]
	ldr r1, _081FCDEC @ =gSineTable
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r5, r3, #0
	cmp r0, #0
	blt _081FCDF0
	asrs r1, r0, #0xc
	b _081FCDF6
	.align 2, 0
_081FCDE8: .4byte 0xFFFF0000
_081FCDEC: .4byte gSineTable
_081FCDF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FCDF6:
	ldrh r0, [r5, #4]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r5, #4]
	ldr r2, _081FCE38 @ =0x00002E78
	ldr r3, _081FCE3C @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FCE40 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
	str r1, [sp, #0x34]
	adds r0, r5, #0
	adds r1, r4, #0
	bl Entity081f26bc_Spawn
_081FCE2E:
	mov r2, sl
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	b _081FCF3E
	.align 2, 0
_081FCE38: .4byte 0x00002E78
_081FCE3C: .4byte 0x000038E2
_081FCE40: .4byte 0x00000232
_081FCE44:
	mov r3, sl
	ldr r0, [r3, #4]
	adds r0, #1
	str r0, [r3, #4]
	cmp r0, #0x78
	bls _081FCE58
	mov r0, sl
	movs r1, #2
	bl NestedState_Set0
_081FCE58:
	mov r0, sl
	ldr r1, [r0, #4]
	cmp r1, #0x5a
	bls _081FCEA0
	movs r0, #0xf
	ands r1, r0
	cmp r1, #0
	bne _081FCEA0
	ldr r2, _081FCE8C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FCE90 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FCE94 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FCE98
	adds r0, r5, #0
	movs r1, #0xb4
	bl FUN_081fad7c
	b _081FCEA0
	.align 2, 0
_081FCE8C: .4byte 0x030046B8
_081FCE90: .4byte 0x000003FF
_081FCE94: .4byte 0x0203B400
_081FCE98:
	adds r0, r5, #0
	movs r1, #0x50
	bl FUN_081fabc0
_081FCEA0:
	mov r2, sl
	ldr r0, [r2, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081FCEB4
	adds r0, r5, #0
	adds r0, #0x50
	bl FUN_081fae7c
_081FCEB4:
	movs r2, #0x14
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081FCF3E
_081FCEC2:
	mov r3, sl
	ldr r0, [r3, #4]
	adds r4, r5, #0
	adds r4, #0x98
	cmp r0, #0
	bne _081FCF04
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081fa628
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Boss_PlayAnimFacing
	ldr r0, _081FCF18 @ =0x000001B7
	bl PlaySound_082406e0
_081FCF04:
	movs r1, #4
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	mov r0, sl
	movs r1, #3
	bl NestedState_Set0
	b _081FCF3E
	.align 2, 0
_081FCF18: .4byte 0x000001B7
_081FCF1C:
	adds r0, r5, #0
	adds r0, #0xa7
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _081FCF50 @ =FUN_081fca00
	movs r0, #2
	adds r4, r5, #0
	adds r4, #0xa3
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
_081FCF3E:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FCF50: .4byte FUN_081fca00
