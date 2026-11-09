	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	str r1, [sp, #8]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _081178EC @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081178F0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081178F2
	.align 2, 0
_081178EC: .4byte 0x0000046D
_081178F0:
	movs r0, #0
_081178F2:
	cmp r0, #0
	beq _081179D0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #1
	beq _0811791C
	cmp r0, #1
	bgt _08117914
	cmp r0, #0
	beq _08117978
	b _081179C8
_08117914:
	cmp r0, #3
	beq _0811791C
	cmp r0, #5
	bne _081179C8
_0811791C:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _08117934 @ =0x0000065C
	adds r1, r1, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _08117938
	movs r0, #1
	b _0811793A
	.align 2, 0
_08117934: .4byte 0x0000065C
_08117938:
	movs r0, #0
_0811793A:
	cmp r0, #0
	beq _0811794C
_0811793E:
	ldr r1, _08117948 @ =0xFFFFF7FF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081179C8
	.align 2, 0
_08117948: .4byte 0xFFFFF7FF
_0811794C:
	ldr r2, _0811796C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08117970 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08117974 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x1e
	b _081179CA
	.align 2, 0
_0811796C: .4byte 0x030046B8
_08117970: .4byte 0x000003FF
_08117974: .4byte 0x0203B400
_08117978:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _08117990 @ =0x0000065C
	adds r1, r1, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _08117994
	movs r0, #1
	b _08117996
	.align 2, 0
_08117990: .4byte 0x0000065C
_08117994:
	movs r0, #0
_08117996:
	cmp r0, #0
	bne _0811793E
	ldr r2, _081179BC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081179C0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081179C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #4
	adds r1, r0, #0
	adds r1, #0x32
	b _081179CA
	.align 2, 0
_081179BC: .4byte 0x030046B8
_081179C0: .4byte 0x000003FF
_081179C4: .4byte 0x0203B400
_081179C8:
	movs r1, #0
_081179CA:
	ldr r0, _08117A20 @ =0x000006BE
	add r0, sb
	strh r1, [r0]
_081179D0:
	mov r4, sp
	adds r4, #5
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _08117A24 @ =0x085AD608
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _08117A28 @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	bne _08117A34
	ldr r2, _08117A2C @ =0x000004B7
	adds r0, r5, r2
	mov r1, ip
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl AuxAnim_SetAnim
	ldr r2, _08117A30 @ =0x0000046E
	adds r7, r5, r2
	b _08117AB6
	.align 2, 0
_08117A20: .4byte 0x000006BE
_08117A24: .4byte 0x085AD608
_08117A28: .4byte 0x0000025D
_08117A2C: .4byte 0x000004B7
_08117A30: .4byte 0x0000046E
_08117A34:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r3, #8
	mov ip, r3
	ldr r1, _08117AA4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _08117AA8 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, ip
	bne _08117A70
	ldrb r0, [r7]
	cmp r0, #0
	bne _08117A70
	cmp r4, #1
	bne _08117A62
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08117ABA
_08117A62:
	cmp r4, #0
	bne _08117A70
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08117ABA
_08117A70:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov r8, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _08117A84
	movs r3, #6
_08117A84:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08117AAC
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08117AB4
	.align 2, 0
_08117AA4: .4byte 0x000004B7
_08117AA8: .4byte 0x0000046E
_08117AAC:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08117AB4:
	str r0, [r6, #8]
_08117AB6:
	movs r0, #0
	strb r0, [r7]
_08117ABA:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r5, r2
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r2, _08117B00 @ =0x000006B6
	add r2, sb
	ldrh r4, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _08117B04 @ =0x0000017F
	cmp r1, r0
	bgt _08117AE0
	adds r0, r4, #0
	adds r0, #0x10
	strh r0, [r2]
_08117AE0:
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	ldr r2, _08117B08 @ =0x00000482
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _08117B0C @ =0x0000A02F
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08117B10
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08117B20
	.align 2, 0
_08117B00: .4byte 0x000006B6
_08117B04: .4byte 0x0000017F
_08117B08: .4byte 0x00000482
_08117B0C: .4byte 0x0000A02F
_08117B10:
	ldr r1, _08117B44 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08117B20
	movs r0, #1
	strh r0, [r2]
_08117B20:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08117B48
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
	b _08117B60
	.align 2, 0
_08117B44: .4byte 0x00000482
_08117B48:
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
_08117B60:
	ldr r0, _08117B8C @ =0x000006BE
	add r0, sb
	ldr r2, [sp, #8]
	ldrh r0, [r0]
	cmp r2, r0
	ble _08117B7C
	ldr r0, _08117B90 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #4
	bl PlayGolemSound
_08117B7C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08117B8C: .4byte 0x000006BE
_08117B90: .4byte 0x0000046B
