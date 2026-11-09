	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08174B14 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08174B18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08174B1A
	.align 2, 0
_08174B14: .4byte 0x0000046C
_08174B18:
	movs r0, #0
_08174B1A:
	ldr r3, _08174BE0 @ =0x00001008
	add r3, sl
	str r3, [sp, #0x34]
	cmp r0, #0
	beq _08174BCC
	ldr r4, _08174BE4 @ =0x00000F78
	add r4, sl
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r4]
	str r1, [r4, #4]
	movs r2, #0xf8
	lsls r2, r2, #4
	add r2, sl
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r5, _08174BE8 @ =0x0203B400
	mov r8, r5
	ldr r3, _08174BEC @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r0, _08174BF0 @ =0x000003FF
	ands r1, r0
	str r1, [r3]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrh r0, [r4]
	subs r0, #0x40
	movs r5, #0x7f
	ands r2, r5
	adds r0, r0, r2
	movs r2, #0
	mov sb, r2
	movs r2, #0
	mov ip, r2
	strh r0, [r4]
	adds r1, #1
	ldr r4, _08174BF0 @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	ldr r2, _08174BF4 @ =0x00000F7C
	add r2, sl
	ldrh r0, [r2]
	subs r0, #0x40
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
	ldrb r1, [r7, #5]
	ldr r0, _08174BF8 @ =0x00000F8A
	add r0, sl
	strb r1, [r0]
	ldr r1, _08174BFC @ =0x00000F88
	add r1, sl
	movs r0, #0x3c
	strh r0, [r1]
	ldr r3, _08174C00 @ =FUN_081719b8
	movs r2, #0x27
	ldr r5, _08174C04 @ =0x0000046D
	adds r1, r7, r5
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08174C08 @ =0x0000046B
	adds r0, r7, r1
	mov r4, sb
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	mov r3, ip
	strh r3, [r0]
	movs r0, #0x41
	rsbs r0, r0, #0
	ldr r4, [sp, #0x34]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_08174BCC:
	bl Entity081f73ec_IsIdle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08174C0C
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrb r2, [r0]
	b _08174C52
	.align 2, 0
_08174BE0: .4byte 0x00001008
_08174BE4: .4byte 0x00000F78
_08174BE8: .4byte 0x0203B400
_08174BEC: .4byte 0x030046B8
_08174BF0: .4byte 0x000003FF
_08174BF4: .4byte 0x00000F7C
_08174BF8: .4byte 0x00000F8A
_08174BFC: .4byte 0x00000F88
_08174C00: .4byte FUN_081719b8
_08174C04: .4byte 0x0000046D
_08174C08: .4byte 0x0000046B
_08174C0C:
	ldr r0, _08174C60 @ =0x00000F78
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #8
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	ldr r4, _08174C64 @ =0x00000F88
	add r4, sl
	ldrh r1, [r4]
	bl Div
	ldrh r1, [r7, #0x10]
	adds r1, r1, r0
	strh r1, [r7, #0x10]
	ldr r0, _08174C68 @ =0x00000F7C
	add r0, sl
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #0xc
	ldrsh r1, [r7, r5]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	ldrh r1, [r7, #0x14]
	adds r1, r1, r0
	strh r1, [r7, #0x14]
	movs r1, #0x10
	ldrsh r0, [r7, r1]
	movs r2, #0x14
	ldrsh r1, [r7, r2]
	bl ArcTan2_8
	adds r2, r0, #0
_08174C52:
	ldrb r0, [r7, #5]
	subs r1, r2, r0
	cmp r1, #0x80
	ble _08174C70
	ldr r3, _08174C6C @ =0xFFFFFF00
	adds r1, r1, r3
	b _08174C7E
	.align 2, 0
_08174C60: .4byte 0x00000F78
_08174C64: .4byte 0x00000F88
_08174C68: .4byte 0x00000F7C
_08174C6C: .4byte 0xFFFFFF00
_08174C70:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08174C7E
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_08174C7E:
	adds r0, r1, #0
	cmp r1, #0
	bge _08174C86
	rsbs r0, r1, #0
_08174C86:
	cmp r0, #0x1f
	bgt _08174C8E
	strb r2, [r7, #5]
	b _08174C9E
_08174C8E:
	cmp r1, #0
	bge _08174C98
	ldrb r0, [r7, #5]
	subs r0, #4
	b _08174C9C
_08174C98:
	ldrb r0, [r7, #5]
	adds r0, #4
_08174C9C:
	strb r0, [r7, #5]
_08174C9E:
	ldr r6, _08174D28 @ =0x00000F88
	add r6, sl
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08174D18
	ldr r3, _08174D2C @ =0x00000F78
	add r3, sl
	movs r0, #0xf8
	lsls r0, r0, #4
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r5, _08174D30 @ =0x0203B400
	mov sb, r5
	ldr r4, _08174D34 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r0, _08174D38 @ =0x000003FF
	ands r1, r0
	str r1, [r4]
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	ldrh r0, [r3]
	subs r0, #0x40
	movs r5, #0x7f
	mov r8, r5
	mov r5, r8
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ldr r0, _08174D38 @ =0x000003FF
	ands r1, r0
	str r1, [r4]
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	ldr r3, _08174D3C @ =0x00000F7C
	add r3, sl
	ldrh r0, [r3]
	subs r0, #0x40
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ldr r2, _08174D38 @ =0x000003FF
	ands r1, r2
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x1e
	strh r0, [r6]
_08174D18:
	movs r1, #0x40
	ldr r3, [sp, #0x34]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08174D40
	movs r0, #1
	b _08174D42
	.align 2, 0
_08174D28: .4byte 0x00000F88
_08174D2C: .4byte 0x00000F78
_08174D30: .4byte 0x0203B400
_08174D34: .4byte 0x030046B8
_08174D38: .4byte 0x000003FF
_08174D3C: .4byte 0x00000F7C
_08174D40:
	movs r0, #0
_08174D42:
	cmp r0, #0
	beq _08174DCE
	ldr r0, _08174E88 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x2c
	movs r4, #0x8a
	lsls r4, r4, #2
	adds r1, r7, r4
	ldrh r1, [r1]
	movs r5, #0x8c
	lsls r5, r5, #2
	adds r2, r7, r5
	ldrh r2, [r2]
	adds r4, #0x1c
	adds r3, r7, r4
	ldr r3, [r3]
	adds r5, #8
	adds r4, r7, r5
	ldrh r4, [r4]
	str r4, [sp]
	ldr r4, _08174E8C @ =0x00000F9C
	add r4, sl
	ldrh r4, [r4]
	str r4, [sp, #4]
	movs r4, #0x20
	str r4, [sp, #8]
	movs r4, #0x18
	str r4, [sp, #0xc]
	movs r4, #0xfa
	lsls r4, r4, #4
	add r4, sl
	ldrh r4, [r4]
	str r4, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	ldr r4, _08174E90 @ =0x00000FB2
	add r4, sl
	ldrh r4, [r4]
	str r4, [sp, #0x18]
	subs r5, #0xae
	adds r4, r7, r5
	ldrh r4, [r4]
	str r4, [sp, #0x1c]
	adds r5, #2
	adds r4, r7, r5
	ldrh r4, [r4]
	str r4, [sp, #0x20]
	bl Entity081f73ec_Spawn
	movs r0, #0x41
	rsbs r0, r0, #0
	ldr r2, [sp, #0x34]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08174E94 @ =0x00000F96
	add r1, sl
	ldrb r0, [r1]
	subs r0, #2
	strb r0, [r1]
	ldr r1, _08174E98 @ =0x00000F97
	add r1, sl
	ldrb r0, [r1]
	subs r0, #2
	strb r0, [r1]
	ldr r3, _08174E9C @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	adds r0, #0x14
	str r0, [r1]
_08174DCE:
	ldr r5, _08174E9C @ =0x00000484
	adds r4, r7, r5
	ldr r1, _08174EA0 @ =0x00000F9A
	add r1, sl
	ldr r0, [r4]
	ldrh r1, [r1]
	cmp r0, r1
	bgt _08174DE0
	b _081750D0
_08174DE0:
	bl Entity081f73ec_IsIdle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08174DEC
	b _081750DC
_08174DEC:
	ldr r1, _08174EA4 @ =0x00000546
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _08174E02
	b _08174F6C
_08174E02:
	ldr r2, _08174EA8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08174EAC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08174EB0 @ =0x0203B400
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x2f
	ble _08174E1C
	b _08174F38
_08174E1C:
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _08174EB4 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_08175898
	add r2, sp, #0x24
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _08174EB8 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r6, #0
	adds r0, r2, #0
	strh r1, [r0]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #4
	ldrsh r1, [r2, r4]
	bl ArcTan2_8
	adds r5, #0x60
	adds r1, r7, r5
	strb r0, [r1]
	ldr r0, _08174E98 @ =0x00000F97
	add r0, sl
	strb r6, [r0]
	ldrb r1, [r1]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08174EC0
	ldr r0, _08174EBC @ =0xFFFFFF00
	adds r1, r1, r0
	b _08174ECE
	.align 2, 0
_08174E88: .4byte 0x03002BE0
_08174E8C: .4byte 0x00000F9C
_08174E90: .4byte 0x00000FB2
_08174E94: .4byte 0x00000F96
_08174E98: .4byte 0x00000F97
_08174E9C: .4byte 0x00000484
_08174EA0: .4byte 0x00000F9A
_08174EA4: .4byte 0x00000546
_08174EA8: .4byte 0x030046B8
_08174EAC: .4byte 0x000003FF
_08174EB0: .4byte 0x0203B400
_08174EB4: .4byte 0xFFEFFFFF
_08174EB8: .4byte 0x000004A4
_08174EBC: .4byte 0xFFFFFF00
_08174EC0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08174ECE
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08174ECE:
	cmp r1, #0
	bge _08174ED4
	rsbs r1, r1, #0
_08174ED4:
	cmp r1, #0x20
	ble _08174F08
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08174F00 @ =0x00000469
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _08174F04 @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r1, [r0]
	adds r4, #3
	adds r0, r7, r4
	strb r2, [r0]
	b _081750DC
	.align 2, 0
_08174F00: .4byte 0x00000469
_08174F04: .4byte 0x0000046A
_08174F08:
	movs r2, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08174F2C @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _08174F30 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r1, [r0]
	ldr r0, _08174F34 @ =0x0000046C
	adds r1, r7, r0
	b _081750C2
	.align 2, 0
_08174F2C: .4byte 0x00000469
_08174F30: .4byte 0x0000046A
_08174F34: .4byte 0x0000046C
_08174F38:
	movs r2, #0x11
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08174F5C @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _08174F60 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	ldr r5, _08174F64 @ =0x00000484
	adds r0, r7, r5
	str r1, [r0]
	ldr r0, _08174F68 @ =0x0000046C
	adds r1, r7, r0
	b _081750C2
	.align 2, 0
_08174F5C: .4byte 0x00000469
_08174F60: .4byte 0x0000046A
_08174F64: .4byte 0x00000484
_08174F68: .4byte 0x0000046C
_08174F6C:
	ldr r2, _08175008 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817500C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08175010 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xc1
	ble _08174F86
	b _081750A0
_08174F86:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _08175014 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_08175898
	add r2, sp, #0x2c
	adds r4, r7, #0
	adds r4, #8
	ldr r5, _08175018 @ =0x000004A4
	adds r0, r7, r5
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r0, #0
	mov r8, r0
	movs r5, #0
	mov sb, r5
	strh r1, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r5, #0xee
	lsls r5, r5, #1
	adds r4, r7, r5
	strb r0, [r4]
	ldr r0, _0817501C @ =0x00000F97
	add r0, sl
	mov r1, r8
	strb r1, [r0]
	movs r0, #0xfb
	lsls r0, r0, #4
	add r0, sl
	mov r2, sb
	strh r2, [r0]
	movs r0, #0xd3
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrb r1, [r4]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08175024
	ldr r3, _08175020 @ =0xFFFFFF00
	adds r1, r1, r3
	b _08175032
	.align 2, 0
_08175008: .4byte 0x030046B8
_0817500C: .4byte 0x000003FF
_08175010: .4byte 0x0203B400
_08175014: .4byte 0xFFEFFFFF
_08175018: .4byte 0x000004A4
_0817501C: .4byte 0x00000F97
_08175020: .4byte 0xFFFFFF00
_08175024:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08175032
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_08175032:
	cmp r1, #0
	bge _08175038
	rsbs r1, r1, #0
_08175038:
	cmp r1, #0x20
	ble _08175070
	movs r2, #1
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08175064 @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _08175068 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r1, [r0]
	ldr r1, _0817506C @ =0x0000046C
	adds r0, r7, r1
	strb r2, [r0]
	b _081750DC
	.align 2, 0
_08175064: .4byte 0x00000469
_08175068: .4byte 0x0000046A
_0817506C: .4byte 0x0000046C
_08175070:
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08175094 @ =0x00000469
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _08175098 @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	ldr r2, _0817509C @ =0x00000484
	adds r0, r7, r2
	str r1, [r0]
	adds r3, #4
	adds r1, r7, r3
	b _081750C2
	.align 2, 0
_08175094: .4byte 0x00000469
_08175098: .4byte 0x0000046A
_0817509C: .4byte 0x00000484
_081750A0:
	movs r2, #0x11
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	movs r1, #0
	strb r1, [r0]
	ldr r5, _081750C8 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	ldr r3, _081750CC @ =0x0000046A
	adds r0, r7, r3
	strb r2, [r0]
	adds r4, #0x1c
	adds r0, r7, r4
	str r1, [r0]
	adds r5, #3
	adds r1, r7, r5
_081750C2:
	movs r0, #1
	strb r0, [r1]
	b _081750DC
	.align 2, 0
_081750C8: .4byte 0x00000469
_081750CC: .4byte 0x0000046A
_081750D0:
	adds r0, r7, #0
	bl FUN_08179a94
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
_081750DC:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
