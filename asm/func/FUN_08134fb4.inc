	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08134FE0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08134FE4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08134FE6
	.align 2, 0
_08134FE0: .4byte 0x0000046C
_08134FE4:
	movs r0, #0
_08134FE6:
	cmp r0, #0
	beq _08135066
	ldr r3, _08135038 @ =0x00000256
	adds r0, r5, r3
	ldrh r1, [r0]
	ldr r0, _0813503C @ =0x00000ADE
	add r0, sl
	strh r1, [r0]
	ldrh r6, [r0]
	ldr r7, _08135040 @ =0x00000B84
	add r7, sl
	ldr r0, _08135044 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08135048
	adds r0, #4
	b _08135054
	.align 2, 0
_08135038: .4byte 0x00000256
_0813503C: .4byte 0x00000ADE
_08135040: .4byte 0x00000B84
_08135044: .4byte 0x030046A4
_08135048:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135054:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r7, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
_08135066:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _081350A0 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081350A8
	ldr r3, _081350A4 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081350B8
	.align 2, 0
_081350A0: .4byte 0x0000A02F
_081350A4: .4byte 0x00000482
_081350A8:
	ldr r1, _081350DC @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081350B8
	movs r0, #1
	strh r0, [r2]
_081350B8:
	ldr r3, _081350E0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081350E4
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
	b _081350FC
	.align 2, 0
_081350DC: .4byte 0x00000482
_081350E0: .4byte 0x0000025D
_081350E4:
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
_081350FC:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	adds r3, r0, #0
	cmp r1, #0x80
	ble _08135118
	ldr r2, _08135114 @ =0xFFFFFF00
	adds r1, r1, r2
	b _08135126
	.align 2, 0
_08135114: .4byte 0xFFFFFF00
_08135118:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08135126
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_08135126:
	adds r6, r1, #0
	adds r0, r6, #0
	cmp r6, #0
	bge _08135130
	rsbs r0, r6, #0
_08135130:
	cmp r0, #8
	ble _08135180
	ldr r2, _08135150 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08135154
	asrs r0, r0, #0xc
	b _0813515A
	.align 2, 0
_08135150: .4byte gSineTable
_08135154:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0813515A:
	adds r1, r0, #0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0813516E
	asrs r2, r0, #0xc
	b _08135174
_0813516E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08135174:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
_08135180:
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	adds r2, r5, #0
	adds r2, #0x10
	ldrh r0, [r5, #0x10]
	ldrh r1, [r5, #8]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r3, [r3, #4]
	adds r1, r1, r3
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081351C8
	cmp r1, #0
	blt _081351C8
	ldr r0, _081351CC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081351C8
	ldr r0, _081351D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081351D4
_081351C8:
	movs r7, #0
	b _081351E2
	.align 2, 0
_081351CC: .4byte 0x030046A8
_081351D0: .4byte 0x030046AC
_081351D4:
	ldr r0, _08135278 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_081351E2:
	ldr r2, _0813527C @ =0x00000ADE
	add r2, sl
	mov r8, r2
	ldrh r0, [r2]
	cmp r0, r7
	beq _08135232
	mov r4, sp
	ldr r2, _08135280 @ =0x00000B84
	add r2, sl
	ldrh r1, [r2]
	mov r0, sp
	ldrh r0, [r0]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl Div
	ldrh r1, [r5, #0x10]
	adds r1, r1, r0
	strh r1, [r5, #0x10]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl Div
	ldrh r1, [r5, #0x14]
	adds r1, r1, r0
	strh r1, [r5, #0x14]
_08135232:
	ldr r2, _08135284 @ =0x0000A410
	adds r0, r5, #0
	movs r1, #0xc
	bl FUN_081370f4
	adds r0, r6, #0
	cmp r6, #0
	bge _08135244
	rsbs r0, r6, #0
_08135244:
	cmp r0, #7
	bgt _0813528C
	mov r2, r8
	ldrh r0, [r2]
	cmp r0, r7
	bne _081352B2
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08135288 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _081352B2
	.align 2, 0
_08135278: .4byte 0x030046A4
_0813527C: .4byte 0x00000ADE
_08135280: .4byte 0x00000B84
_08135284: .4byte 0x0000A410
_08135288: .4byte 0x00000484
_0813528C:
	cmp r6, #0
	ble _081352A4
	ldr r1, _081352A0 @ =0x00000482
	adds r0, r5, r1
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldrb r2, [r5, #5]
	adds r0, r0, r2
	b _081352B0
	.align 2, 0
_081352A0: .4byte 0x00000482
_081352A4:
	ldr r3, _081352CC @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	lsls r1, r1, #1
	ldrb r0, [r5, #5]
	subs r0, r0, r1
_081352B0:
	strb r0, [r5, #5]
_081352B2:
	ldr r0, _081352D0 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081352CC: .4byte 0x00000482
_081352D0: .4byte 0x00000484
