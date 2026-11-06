	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	str r0, [sp, #0x54]
	adds r6, r1, #0
	adds r0, #0x93
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081F1004
	asrs r0, r1, #6
	b _081F100A
_081F1004:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081F100A:
	lsls r7, r0, #6
	add r3, sp, #0x3c
	ldr r2, _081F102C @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	cmp r0, #0
	blt _081F1030
	asrs r1, r0, #0xc
	b _081F1036
	.align 2, 0
_081F102C: .4byte gSineTable
_081F1030:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F1036:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _081F1056
	asrs r0, r0, #0xc
	b _081F105C
_081F1056:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F105C:
	strh r0, [r3, #4]
	ldr r3, [sp, #0x54]
	adds r3, #0x1c
	ldr r0, [sp, #0x54]
	ldrh r2, [r0, #0x1c]
	add r1, sp, #0x3c
	ldrh r0, [r1]
	adds r0, r2, r0
	strh r0, [r1]
	mov r1, sp
	ldrh r0, [r1, #0x3e]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1, #0x3e]
	ldrh r1, [r3, #4]
	add r3, sp, #0x40
	ldrh r0, [r3]
	adds r0, r1, r0
	strh r0, [r3]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081F10A4
	cmp r1, #0
	blt _081F10A4
	ldr r0, _081F10A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F10A4
	ldr r0, _081F10AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F10B0
_081F10A4:
	movs r0, #0
	b _081F10BE
	.align 2, 0
_081F10A8: .4byte 0x030046A8
_081F10AC: .4byte 0x030046AC
_081F10B0:
	ldr r0, _081F1168 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081F10BE:
	str r0, [sp, #0x58]
	add r4, sp, #0x44
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081F116C @ =0x05000002
	bl CpuSet
	cmp r6, #0
	bgt _081F10D6
	b _081F12A4
_081F10D6:
	ldr r1, _081F1170 @ =0x030046B8
	mov sl, r1
	add r5, sp, #0x4c
	mov r8, r6
	movs r2, #0
	mov sb, r2
_081F10E2:
	mov r3, sl
	ldr r1, [r3]
	adds r1, #1
	ldr r0, _081F1174 @ =0x000003FF
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _081F1178 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r3, #0xff
	ands r0, r3
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x4c]
	adds r1, #1
	ldr r0, _081F1174 @ =0x000003FF
	ands r1, r0
	mov r2, sl
	str r1, [r2]
	lsls r1, r1, #1
	ldr r3, _081F1178 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r0, #0xff
	ands r1, r0
	subs r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ldr r2, _081F117C @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	add r0, sp, #0x3c
	ldrh r2, [r5]
	ldrh r0, [r0]
	adds r2, r2, r0
	strh r2, [r5]
	mov r3, sp
	ldrh r0, [r3, #0x3e]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	add r1, sp, #0x40
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #4]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F1164
	cmp r1, #0
	blt _081F1164
	ldr r0, _081F1180 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F1164
	ldr r0, _081F1184 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F1188
_081F1164:
	movs r6, #0
	b _081F1196
	.align 2, 0
_081F1168: .4byte 0x030046A4
_081F116C: .4byte 0x05000002
_081F1170: .4byte 0x030046B8
_081F1174: .4byte 0x000003FF
_081F1178: .4byte 0x0203B400
_081F117C: .4byte 0xFFFF0000
_081F1180: .4byte 0x030046A8
_081F1184: .4byte 0x030046AC
_081F1188:
	ldr r0, _081F11A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_081F1196:
	cmp r7, #0
	blt _081F11A4
	asrs r0, r7, #6
	b _081F11AA
	.align 2, 0
_081F11A0: .4byte 0x030046A4
_081F11A4:
	rsbs r0, r7, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081F11AA:
	str r0, [sp]
	ldr r0, [sp, #0x54]
	adds r1, r5, #0
	ldr r2, [sp, #0x58]
	adds r3, r6, #0
	bl Entity081f1770_IsPathBlocked
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F1296
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F11CE
	adds r0, #4
	b _081F11DA
_081F11CE:
	ldr r0, _081F11F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F11DA:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #0
	bne _081F1296
	ldr r0, [sp, #0x58]
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F11F8
	adds r0, #4
	b _081F1206
	.align 2, 0
_081F11F4: .4byte 0x030046A4
_081F11F8:
	ldr r0, _081F121C @ =0x030046A4
	ldr r1, [r0]
	ldr r2, [sp, #0x58]
	lsls r0, r2, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F1206:
	ldrb r0, [r0]
	movs r4, #0xf
	ands r4, r0
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F1220
	adds r0, #4
	b _081F122C
	.align 2, 0
_081F121C: .4byte 0x030046A4
_081F1220:
	ldr r0, _081F12B4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F122C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r1, r0, #0
	subs r0, r4, r1
	cmp r0, #0
	bge _081F123C
	rsbs r0, r0, #0
_081F123C:
	cmp r0, #1
	bgt _081F1296
	lsls r0, r1, #8
	strh r0, [r5, #2]
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081F12B8 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _081F12BC @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x14
	movs r0, #3
	str r0, [sp]
	mov r3, sb
	str r3, [sp, #4]
	movs r0, #0x31
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #1
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	str r3, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #4
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	ldr r0, _081F12C0 @ =0x00200004
	str r0, [sp, #0x28]
	movs r0, #0x1e
	str r0, [sp, #0x2c]
	movs r0, #8
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	adds r0, r5, #0
	add r1, sp, #0x44
	ldr r2, _081F12C4 @ =0x00001C1A
	ldr r3, _081F12C8 @ =0x0000D1B8
	bl Entity081f26bc_Spawn
_081F1296:
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	beq _081F12A4
	b _081F10E2
_081F12A4:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F12B4: .4byte 0x030046A4
_081F12B8: .4byte 0x000003FF
_081F12BC: .4byte 0x0203B400
_081F12C0: .4byte 0x00200004
_081F12C4: .4byte 0x00001C1A
_081F12C8: .4byte 0x0000D1B8
