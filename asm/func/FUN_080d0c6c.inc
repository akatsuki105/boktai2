	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, _080D0CBC @ =0x0000037D
	adds r0, r7, r2
	ldrb r1, [r0]
	cmp r1, #1
	bne _080D0CA8
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	ldrh r0, [r0, #2]
	ands r1, r0
	cmp r1, #0
	beq _080D0CA8
	adds r0, r7, #0
	movs r1, #4
	movs r2, #2
	bl PlayerLink_SetAction
_080D0CA8:
	ldr r1, _080D0CBC @ =0x0000037D
	adds r0, r7, r1
	ldrb r4, [r0]
	cmp r4, #1
	beq _080D0D68
	cmp r4, #1
	bgt _080D0CC0
	cmp r4, #0
	beq _080D0CC8
	b _080D12F4
	.align 2, 0
_080D0CBC: .4byte 0x0000037D
_080D0CC0:
	cmp r4, #2
	bne _080D0CC6
	b _080D117E
_080D0CC6:
	b _080D12F4
_080D0CC8:
	movs r1, #4
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	movs r1, #2
	bl FUN_08066ee4
	mov sb, r0
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, sb
	beq _080D0D42
	ldr r0, [r7, #0x18]
	movs r1, #0xd0
	bl Sound_PlayForPlayer
	ldr r0, _080D0D2C @ =0x000003BD
	adds r2, r7, r0
	ldrb r0, [r2]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r7, r3
	strb r0, [r1]
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D0D34
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D0D30 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _080D0D42
	.align 2, 0
_080D0D2C: .4byte 0x000003BD
_080D0D30: .4byte 0x000002E6
_080D0D34:
	lsrs r0, r1, #0x19
	ldr r2, _080D0D60 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _080D0D64 @ =0x000002E7
	adds r0, r7, r3
	strb r4, [r0]
_080D0D42:
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	bne _080D0D52
	b _080D12F4
_080D0D52:
	adds r0, r7, #0
	movs r1, #4
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D12F4
	.align 2, 0
_080D0D60: .4byte 0x000002E6
_080D0D64: .4byte 0x000002E7
_080D0D68:
	movs r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r6, [r0, r3]
	ldr r0, _080D0DEC @ =0x000003BD
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	adds r4, r0, #7
	movs r2, #7
	ands r4, r2
	adds r5, r0, #1
	ands r5, r2
	subs r1, #0x64
	adds r0, r7, r1
	ldrb r0, [r0]
	movs r1, #3
	str r2, [sp, #0x1c]
	bl FUN_08066ee4
	mov sb, r0
	ldr r2, [sp, #0x1c]
	cmp r6, r4
	beq _080D0DB0
	cmp r6, r5
	beq _080D0DB0
	b _080D1144
_080D0DB0:
	mov r3, r8
	ldrb r1, [r3]
	subs r0, r6, r1
	lsls r0, r0, #1
	adds r0, #8
	adds r1, r1, r0
	ands r1, r2
	adds r6, r1, #1
	ands r6, r2
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, _080D0DF0 @ =gSineTable
	lsls r0, r6, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov r8, r2
	cmp r0, #0
	blt _080D0DF4
	asrs r2, r0, #0xc
	b _080D0DFA
	.align 2, 0
_080D0DEC: .4byte 0x000003BD
_080D0DF0: .4byte gSineTable
_080D0DF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D0DFA:
	add r0, sp, #0xc
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D0E2C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	lsls r2, r6, #5
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov sl, r2
	cmp r0, #0
	blt _080D0E30
	asrs r0, r0, #0xc
	b _080D0E36
	.align 2, 0
_080D0E2C: .4byte 0xFFFF0000
_080D0E30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D0E36:
	add r3, sp, #0xc
	ldrh r1, [r3, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D0E74 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r3, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D0E70
	cmp r1, #0
	blt _080D0E70
	ldr r0, _080D0E78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D0E70
	ldr r0, _080D0E7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D0E80
_080D0E70:
	movs r6, #0
	b _080D0E8E
	.align 2, 0
_080D0E74: .4byte 0xFFFF0000
_080D0E78: .4byte 0x030046A8
_080D0E7C: .4byte 0x030046AC
_080D0E80:
	ldr r0, _080D0EBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080D0E8E:
	add r5, sp, #0xc
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D0EB6
	cmp r1, #0
	blt _080D0EB6
	ldr r0, _080D0EC0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D0EB6
	ldr r0, _080D0EC4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D0EC8
_080D0EB6:
	movs r4, #0
	b _080D0ED6
	.align 2, 0
_080D0EBC: .4byte 0x030046A4
_080D0EC0: .4byte 0x030046A8
_080D0EC4: .4byte 0x030046AC
_080D0EC8:
	ldr r0, _080D0EE8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D0ED6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D0EEC
	adds r0, #4
	b _080D0EF8
	.align 2, 0
_080D0EE8: .4byte 0x030046A4
_080D0EEC:
	ldr r0, _080D0F0C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D0EF8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D0F10
	cmp r2, #2
	beq _080D0F14
	b _080D0F18
	.align 2, 0
_080D0F0C: .4byte 0x030046A4
_080D0F10:
	ldrb r0, [r5, #4]
	b _080D0F16
_080D0F14:
	ldrb r0, [r5]
_080D0F16:
	subs r1, r1, r0
_080D0F18:
	adds r5, r1, #0
	movs r0, #0x2e
	ldrsh r1, [r7, r0]
	adds r0, r1, #0
	subs r0, #0x80
	cmp r5, r0
	bgt _080D0F28
	b _080D1144
_080D0F28:
	adds r0, r1, #0
	adds r0, #0x80
	cmp r5, r0
	blt _080D0F32
	b _080D1144
_080D0F32:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D0F42
	adds r0, #4
	b _080D0F4E
_080D0F42:
	ldr r0, _080D0F88 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D0F4E:
	ldrh r0, [r0, #2]
	bl FUN_080cfc78
	cmp r0, #0
	beq _080D0F5A
	b _080D1144
_080D0F5A:
	ldr r2, _080D0F8C @ =gSineTable
	ldr r1, _080D0F90 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov r8, r2
	cmp r0, #0
	blt _080D0F94
	asrs r1, r0, #0xc
	b _080D0F9A
	.align 2, 0
_080D0F88: .4byte 0x030046A4
_080D0F8C: .4byte gSineTable
_080D0F90: .4byte 0x000003BD
_080D0F94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D0F9A:
	add r0, sp, #0xc
	ldrh r0, [r0]
	subs r0, r0, r1
	add r1, sp, #0xc
	strh r0, [r1]
	ldr r1, _080D0FC4 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #6
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D0FC8
	asrs r2, r0, #0xc
	b _080D0FCE
	.align 2, 0
_080D0FC4: .4byte 0x000003BD
_080D0FC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D0FCE:
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	subs r1, r1, r2
	strh r1, [r0, #4]
	adds r6, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _080D0FFA
	cmp r1, #0
	blt _080D0FFA
	ldr r0, _080D1000 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D0FFA
	ldr r0, _080D1004 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D1008
_080D0FFA:
	movs r4, #0
	b _080D1016
	.align 2, 0
_080D1000: .4byte 0x030046A8
_080D1004: .4byte 0x030046AC
_080D1008:
	ldr r0, _080D1028 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D1016:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D102C
	adds r0, #4
	b _080D1038
	.align 2, 0
_080D1028: .4byte 0x030046A4
_080D102C:
	ldr r0, _080D104C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D1038:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D1050
	cmp r2, #2
	beq _080D1054
	b _080D1058
	.align 2, 0
_080D104C: .4byte 0x030046A4
_080D1050:
	ldrb r0, [r6, #4]
	b _080D1056
_080D1054:
	ldrb r0, [r6]
_080D1056:
	subs r1, r1, r0
_080D1058:
	adds r0, r5, #0
	adds r0, #0xc8
	cmp r1, r0
	blt _080D1144
	add r1, sp, #0xc
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D1088
	cmp r1, #0
	blt _080D1088
	ldr r0, _080D108C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D1088
	ldr r0, _080D1090 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D1094
_080D1088:
	movs r4, #0
	b _080D10A2
	.align 2, 0
_080D108C: .4byte 0x030046A8
_080D1090: .4byte 0x030046AC
_080D1094:
	ldr r0, _080D10B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D10A2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D10B8
	adds r0, #4
	b _080D10C4
	.align 2, 0
_080D10B4: .4byte 0x030046A4
_080D10B8:
	ldr r0, _080D1110 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D10C4:
	ldrh r0, [r0, #2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080D1144
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	bl FUN_08066ee4
	mov sb, r0
	adds r0, r7, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _080D10F0
	movs r3, #3
	cmp r0, #2
	bne _080D10F0
	movs r3, #6
_080D10F0:
	ldr r2, _080D1114 @ =gSineTable
	mov r0, sl
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov r8, r2
	cmp r0, #0
	blt _080D1118
	asrs r0, r0, #0xc
	b _080D111E
	.align 2, 0
_080D1110: .4byte 0x030046A4
_080D1114: .4byte gSineTable
_080D1118:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D111E:
	rsbs r0, r0, #0
	strh r0, [r7, #0x34]
	movs r0, #0xff
	mov r2, sl
	ands r0, r2
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D113A
	asrs r0, r0, #0xc
	b _080D1140
_080D113A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D1140:
	rsbs r0, r0, #0
	strh r0, [r7, #0x38]
_080D1144:
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0x18
	beq _080D115C
	b _080D12F4
_080D115C:
	adds r0, r7, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D1168
	b _080D12F4
_080D1168:
	adds r0, r7, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #1
	beq _080D1174
	b _080D12F4
_080D1174:
	ldr r0, [r7, #0x18]
	movs r1, #0xdb
	bl Sound_PlayForPlayer
	b _080D12F4
_080D117E:
	movs r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	movs r1, #5
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r7, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	bne _080D11A4
	b _080D12F4
_080D11A4:
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r1, _080D11DC @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D11E8
	add r3, sp, #0x14
	ldrh r0, [r3]
	adds r0, #0x1c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080D11E0 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r4
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x2c
	lsls r1, r1, #0x10
	ldr r0, _080D11E4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r3, #4]
	subs r0, #0x4c
	b _080D1248
	.align 2, 0
_080D11DC: .4byte 0x000003BD
_080D11E0: .4byte 0xFFFF0000
_080D11E4: .4byte 0x0000FFFF
_080D11E8:
	cmp r0, #3
	bne _080D1220
	add r3, sp, #0x14
	ldrh r0, [r3]
	subs r0, #0x34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080D1218 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	lsrs r2, r1, #0x10
	lsls r2, r2, #0x10
	ldr r0, _080D121C @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x14]
	ldrh r1, [r3, #4]
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r3, #4]
	adds r4, r3, #0
	b _080D1294
	.align 2, 0
_080D1218: .4byte 0xFFFF0000
_080D121C: .4byte 0x0000FFFF
_080D1220:
	cmp r0, #5
	bne _080D1260
	add r3, sp, #0x14
	ldrh r0, [r3]
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080D1258 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r4
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x2c
	lsls r1, r1, #0x10
	ldr r0, _080D125C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r3, #4]
	subs r0, #0x20
_080D1248:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r3, #4]
	adds r4, r3, #0
	b _080D1294
	.align 2, 0
_080D1258: .4byte 0xFFFF0000
_080D125C: .4byte 0x0000FFFF
_080D1260:
	add r4, sp, #0x14
	cmp r0, #7
	bne _080D1294
	ldrh r0, [r4]
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _080D1304 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x44
	lsls r1, r1, #0x10
	ldr r0, _080D1308 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r4, #4]
	adds r0, #0x2c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r4, #4]
_080D1294:
	ldr r2, _080D130C @ =gSineTable
	ldr r3, _080D1310 @ =0x000003BD
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov r8, r2
	ldr r1, _080D1310 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #6
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	adds r1, r7, #0
	adds r1, #0x2c
	movs r2, #0x80
	lsls r2, r2, #1
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0xec
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #1
	bl FUN_080d03bc
	adds r0, r7, #0
	movs r1, #4
	movs r2, #1
	bl PlayerLink_SetAction
_080D12F4:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1304: .4byte 0xFFFF0000
_080D1308: .4byte 0x0000FFFF
_080D130C: .4byte gSineTable
_080D1310: .4byte 0x000003BD
