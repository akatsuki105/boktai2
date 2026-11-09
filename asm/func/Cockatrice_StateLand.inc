	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x6c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _08155990 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08155994
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08155996
	.align 2, 0
_08155990: .4byte 0x0000046D
_08155994:
	movs r0, #0
_08155996:
	cmp r0, #0
	beq _081559CE
	adds r0, r7, #0
	movs r1, #0xf
	bl Enemy_PlayAnim
	movs r2, #0xe0
	lsls r2, r2, #3
	add r2, sb
	movs r1, #0xa
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, _08155AC8 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r1, _08155ACC @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081559CE:
	ldr r5, _08155AD0 @ =0x0000046E
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _081559DC
	bl _081562CA
_081559DC:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r2, #0x80
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r1, r7, r6
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x30]
	cmp r0, #0
	bne _081559F8
	b _08155FF8
_081559F8:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r0, #0x1a
	ldr r3, _08155AD4 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #8]
	movs r1, #0
	movs r3, #1
	ldr r4, [sp, #8]
	strb r3, [r4]
	subs r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xc]
	strb r1, [r5]
	ldr r6, _08155AD8 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x10]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x14]
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sl, r2
	movs r0, #0
	strh r1, [r2]
	movs r2, #0xc
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	strb r0, [r4]
	ldr r5, _08155ADC @ =0x00000469
	adds r5, r5, r7
	mov r8, r5
	strb r0, [r5]
	ldr r6, _08155AE0 @ =0x0000046A
	adds r6, r7, r6
	str r6, [sp, #0x68]
	strb r2, [r6]
	ldr r0, _08155AE4 @ =0x00000484
	adds r5, r7, r0
	str r1, [r5]
	ldr r1, _08155AE8 @ =0x0000046C
	adds r4, r7, r1
	strb r3, [r4]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r7, r2
	ldr r6, [r3]
	str r6, [sp, #0x18]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #8]
	str r0, [sp, #0x5c]
	ldr r6, [sp, #0xc]
	str r6, [sp, #0x54]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x38]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x3c]
	mov r0, sl
	str r0, [sp, #0x40]
	mov r6, sb
	str r6, [sp, #0x48]
	mov r0, r8
	str r0, [sp, #0x4c]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x50]
	str r5, [sp, #0x64]
	str r4, [sp, #0x58]
	adds r6, r3, #0
	mov r8, r2
	mov r0, ip
	cmp r0, #0
	blt _08155AC4
	cmp r1, #0
	blt _08155AC4
	ldr r0, _08155AEC @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08155AC4
	ldr r0, _08155AF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08155AF4
_08155AC4:
	movs r4, #0
	b _08155B04
	.align 2, 0
_08155AC8: .4byte 0xFFFFFEFF
_08155ACC: .4byte 0xFFEFFFFF
_08155AD0: .4byte 0x0000046E
_08155AD4: .4byte 0x0000046D
_08155AD8: .4byte 0x00000553
_08155ADC: .4byte 0x00000469
_08155AE0: .4byte 0x0000046A
_08155AE4: .4byte 0x00000484
_08155AE8: .4byte 0x0000046C
_08155AEC: .4byte 0x030046A8
_08155AF0: .4byte 0x030046AC
_08155AF4:
	ldr r0, _08155B14 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08155B04:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08155B18
	adds r0, #4
	b _08155B24
	.align 2, 0
_08155B14: .4byte 0x030046A4
_08155B18:
	ldr r0, _08155B38 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08155B24:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08155B3C
	cmp r2, #2
	beq _08155B42
	b _08155B48
	.align 2, 0
_08155B38: .4byte 0x030046A4
_08155B3C:
	ldr r2, [sp, #0x18]
	ldrb r0, [r2, #4]
	b _08155B46
_08155B42:
	ldr r3, [sp, #0x18]
	ldrb r0, [r3]
_08155B46:
	subs r1, r1, r0
_08155B48:
	ldr r4, [sp, #0x18]
	strh r1, [r4, #2]
	ldr r0, _08155B60 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08155B64
	movs r0, #1
	b _08155B66
	.align 2, 0
_08155B60: .4byte 0x030047A4
_08155B64:
	movs r0, #0
_08155B66:
	cmp r0, #0
	beq _08155BA4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _08155B86
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08155B82
	adds r2, r0, #0
_08155B82:
	cmp r2, #0
	bge _08155B90
_08155B86:
	ldr r6, _08155B8C @ =0x000005C4
	adds r0, r7, r6
	b _08155FE6
	.align 2, 0
_08155B8C: .4byte 0x000005C4
_08155B90:
	ldr r1, _08155BA0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08155BEC
	.align 2, 0
_08155BA0: .4byte 0x03002BE0
_08155BA4:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08155BD0
	cmp r1, #0
	blt _08155BD0
	ldr r0, _08155BD4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08155BD0
	ldr r0, _08155BD8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08155BDC
_08155BD0:
	movs r5, #0
	b _08155BEA
	.align 2, 0
_08155BD4: .4byte 0x030046A8
_08155BD8: .4byte 0x030046AC
_08155BDC:
	ldr r0, _08155C7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08155BEA:
	movs r2, #0
_08155BEC:
	ldr r3, _08155C80 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08155C0C
	ldr r1, _08155C84 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08155C0C
	b _08155F24
_08155C0C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x30]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08155C20
	b _081562CA
_08155C20:
	ldr r5, _08155C88 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x30]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sl, r2
	cmp r3, #0
	beq _08155C8C
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x5c]
	strb r2, [r3]
	ldr r6, [sp, #0x54]
	strb r5, [r6]
	ldr r3, [sp, #0x38]
	strb r0, [r3]
	ldr r6, [sp, #0x3c]
	str r1, [r6]
	ldr r0, [sp, #0x40]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x48]
	strb r5, [r1]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r5, [sp, #0x50]
	strb r0, [r5]
	ldr r6, [sp, #0x64]
	str r4, [r6]
	ldr r0, [sp, #0x58]
	strb r2, [r0]
	b _08155DDA
	.align 2, 0
_08155C7C: .4byte 0x030046A4
_08155C80: .4byte 0x00000256
_08155C84: .4byte 0x03002BE0
_08155C88: .4byte 0x00000222
_08155C8C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	strb r5, [r4]
	ldr r2, [sp, #0x38]
	strb r0, [r2]
	ldr r4, [sp, #0x3c]
	str r1, [r4]
	ldr r1, [sp, #0x40]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x48]
	strb r5, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r5, [sp, #0x50]
	strb r1, [r5]
	ldr r1, [sp, #0x64]
	str r3, [r1]
	ldr r2, [sp, #0x58]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08155CF0
	cmp r1, #0
	blt _08155CF0
	ldr r0, _08155CF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08155CF0
	ldr r0, _08155CF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08155CFC
_08155CF0:
	movs r4, #0
	b _08155D0A
	.align 2, 0
_08155CF4: .4byte 0x030046A8
_08155CF8: .4byte 0x030046AC
_08155CFC:
	ldr r0, _08155D1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08155D0A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08155D20
	adds r0, #4
	b _08155D2C
	.align 2, 0
_08155D1C: .4byte 0x030046A4
_08155D20:
	ldr r0, _08155D40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08155D2C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08155D44
	cmp r2, #2
	beq _08155D48
	b _08155D4C
	.align 2, 0
_08155D40: .4byte 0x030046A4
_08155D44:
	ldrb r0, [r5, #4]
	b _08155D4A
_08155D48:
	ldrb r0, [r5]
_08155D4A:
	subs r1, r1, r0
_08155D4C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08155D74
	cmp r1, #0
	blt _08155D74
	ldr r0, _08155D78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08155D74
	ldr r0, _08155D7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08155D80
_08155D74:
	movs r4, #0
	b _08155D8E
	.align 2, 0
_08155D78: .4byte 0x030046A8
_08155D7C: .4byte 0x030046AC
_08155D80:
	ldr r0, _08155DA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08155D8E:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08155DA4
	adds r0, #4
	b _08155DB0
	.align 2, 0
_08155DA0: .4byte 0x030046A4
_08155DA4:
	ldr r0, _08155DC4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08155DB0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08155DC8
	cmp r3, #2
	beq _08155DCC
	b _08155DD0
	.align 2, 0
_08155DC4: .4byte 0x030046A4
_08155DC8:
	ldrb r0, [r5, #4]
	b _08155DCE
_08155DCC:
	ldrb r0, [r5]
_08155DCE:
	subs r2, r2, r0
_08155DD0:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_08155DDA:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x30]
	ldrh r0, [r5]
	ands r0, r1
	mov sb, r4
	ldr r6, _08155E04 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x60]
	cmp r0, #0
	bne _08155EE8
	movs r1, #4
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08155E08
	movs r0, #1
	b _08155E0A
	.align 2, 0
_08155E04: .4byte 0x00000482
_08155E08:
	movs r0, #0
_08155E0A:
	ldr r3, _08155EF8 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x60]
	cmp r0, #0
	bne _08155EE8
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _08155EFC @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _08155F00 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x28]
	ldr r1, _08155F04 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x2c]
	ldr r2, _08155F08 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x34]
	ldr r4, _08155F0C @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x20]
	ldr r5, _08155F10 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x44]
	ldr r6, _08155F14 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x24]
	ldr r6, _08155F18 @ =0x0203B400
	ldr r1, _08155F1C @ =0x030046B8
	ldr r5, _08155F20 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_08155E5A:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _08155E78
	adds r3, #1
	cmp r3, #3
	ble _08155E5A
	mov r0, sb
_08155E78:
	movs r3, #0
	mov r1, r8
	strb r0, [r1]
	ldr r2, [sp, #0x3c]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x38]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	ldr r2, [sp, #0x28]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	ldrb r0, [r4]
	ldr r5, [sp, #0x2c]
	strb r0, [r5]
	ldr r6, [sp, #0x50]
	ldrb r0, [r6]
	ldr r1, [sp, #0x34]
	strb r0, [r1]
	mov r2, sp
	ldrb r4, [r2, #0x1c]
	ldr r2, [sp, #0x20]
	strb r4, [r2]
	ldr r5, [sp, #0x44]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x5c]
	strb r1, [r6]
	ldr r4, [sp, #0x54]
	strb r3, [r4]
	ldr r5, [sp, #0x38]
	strb r0, [r5]
	ldr r6, [sp, #0x3c]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x40]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	ldr r5, [sp, #0x4c]
	strb r1, [r5]
	ldr r6, [sp, #0x50]
	strb r2, [r6]
	ldr r0, [sp, #0x64]
	str r3, [r0]
	ldr r2, [sp, #0x58]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x24]
	strb r0, [r3]
_08155EE8:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x60]
	strh r0, [r4]
	b _081562CA
	.align 2, 0
_08155EF8: .4byte 0x00000482
_08155EFC: .4byte 0x0000054F
_08155F00: .4byte 0x0000054C
_08155F04: .4byte 0x0000054D
_08155F08: .4byte 0x0000054E
_08155F0C: .4byte 0x00000541
_08155F10: .4byte 0x000005BC
_08155F14: .4byte 0x00000542
_08155F18: .4byte 0x0203B400
_08155F1C: .4byte 0x030046B8
_08155F20: .4byte 0x000003FF
_08155F24:
	mov sb, sp
	ldr r6, _08155F60 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08155F64
	adds r0, #4
	b _08155F6E
	.align 2, 0
_08155F60: .4byte 0x030046A4
_08155F64:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08155F6E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _08155FA8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08155FB0
	ldr r0, _08155FAC @ =0xFFFFFDFF
	ldr r2, [sp, #0x30]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08155FDA
	.align 2, 0
_08155FA8: .4byte 0x000004A4
_08155FAC: .4byte 0xFFFFFDFF
_08155FB0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08155FD0
	cmp r0, #2
	beq _08155FCC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08155FCC:
	movs r0, #1
	b _08155FDC
_08155FD0:
	ldr r0, _08155FF0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x30]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08155FDA:
	movs r0, #0
_08155FDC:
	cmp r0, #0
	beq _08155FE2
	b _081562CA
_08155FE2:
	ldr r4, _08155FF4 @ =0x000005C4
	adds r0, r7, r4
_08155FE6:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081562CA
	.align 2, 0
_08155FF0: .4byte 0xFFFFFDFF
_08155FF4: .4byte 0x000005C4
_08155FF8:
	movs r2, #0x20
	movs r1, #0xe0
	lsls r1, r1, #3
	add r1, sb
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _0815600E
	movs r0, #1
	b _08156010
_0815600E:
	movs r0, #0
_08156010:
	adds r4, r0, #0
	cmp r4, #0
	beq _08156090
	ldr r3, _08156078 @ =Cockatrice_StateFlee
	movs r1, #0x34
	ldr r5, _0815607C @ =0x0000046D
	adds r0, r7, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08156080 @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r3, #0x13
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08156084 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08156088 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0815608C @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	adds r0, r7, #0
	bl Cockatrice_FleeToPathNode
	movs r1, #0x41
	rsbs r1, r1, #0
	mov r6, r8
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	b _081562CA
	.align 2, 0
_08156078: .4byte Cockatrice_StateFlee
_0815607C: .4byte 0x0000046D
_08156080: .4byte 0x0000046B
_08156084: .4byte 0x00000469
_08156088: .4byte 0x0000046A
_0815608C: .4byte 0x00000484
_08156090:
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r2, [sp, #0x30]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08156190
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r2, #1
	ldr r5, _08156120 @ =0x0000046D
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _08156124 @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	subs r3, #0x4d
	adds r0, r7, r3
	strb r2, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r7, r5
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r1, #0
	strh r4, [r0]
	movs r3, #7
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08156128 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0815612C @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08156130 @ =0x00000484
	adds r0, r7, r3
	str r4, [r0]
	ldr r4, _08156134 @ =0x0000046C
	adds r0, r7, r4
	strb r2, [r0]
	adds r5, #0x3c
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0815613C
	ldr r0, _08156138 @ =0xFFFFFDFF
	ldr r2, [sp, #0x30]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08156166
	.align 2, 0
_08156120: .4byte 0x0000046D
_08156124: .4byte 0x0000046B
_08156128: .4byte 0x00000469
_0815612C: .4byte 0x0000046A
_08156130: .4byte 0x00000484
_08156134: .4byte 0x0000046C
_08156138: .4byte 0xFFFFFDFF
_0815613C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815615C
	cmp r0, #2
	beq _08156158
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08156158:
	movs r0, #1
	b _08156168
_0815615C:
	ldr r0, _0815618C @ =0xFFFFFDFF
	ldr r3, [sp, #0x30]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08156166:
	movs r0, #0
_08156168:
	cmp r0, #0
	bne _0815616E
	b _08156274
_0815616E:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081562CA
	.align 2, 0
_0815618C: .4byte 0xFFFFFDFF
_08156190:
	movs r1, #0x80
	lsls r1, r1, #0xc
	mov r6, r8
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081561A2
	movs r0, #1
	b _081561A4
_081561A2:
	movs r0, #0
_081561A4:
	cmp r0, #0
	bne _081561AA
	b _081562C4
_081561AA:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r3, #1
	ldr r2, _08156224 @ =0x0000046D
	adds r0, r7, r2
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08156228 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	ldr r5, _0815622C @ =0x00000553
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08156230 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08156234 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _08156238 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x3b
	adds r0, r7, r6
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	ldr r4, _0815623C @ =0x000006F4
	add r4, sb
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08156244
	ldr r0, _08156240 @ =0xFFFFFDFF
	ldr r2, [sp, #0x30]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0815626E
	.align 2, 0
_08156224: .4byte 0x0000046D
_08156228: .4byte 0x0000046B
_0815622C: .4byte 0x00000553
_08156230: .4byte 0x00000469
_08156234: .4byte 0x0000046A
_08156238: .4byte 0x00000484
_0815623C: .4byte 0x000006F4
_08156240: .4byte 0xFFFFFDFF
_08156244:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08156264
	cmp r0, #2
	beq _08156260
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08156260:
	movs r0, #1
	b _08156270
_08156264:
	ldr r0, _0815627C @ =0xFFFFFDFF
	ldr r3, [sp, #0x30]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0815626E:
	movs r0, #0
_08156270:
	cmp r0, #0
	bne _08156280
_08156274:
	adds r0, r7, #0
	bl Cockatrice_RestAndResumeRoute
	b _081562CA
	.align 2, 0
_0815627C: .4byte 0xFFFFFDFF
_08156280:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r6, _081562B8 @ =0x00000482
	adds r1, r7, r6
	movs r0, #3
	strh r0, [r1]
	ldr r0, _081562BC @ =0x000006F4
	add r0, sb
	movs r1, #8
	bl ClearMemory
	ldr r1, _081562C0 @ =0xFFF7FFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081562CA
	.align 2, 0
_081562B8: .4byte 0x00000482
_081562BC: .4byte 0x000006F4
_081562C0: .4byte 0xFFF7FFFF
_081562C4:
	adds r0, r7, #0
	bl Cockatrice_RestAndResumeRoute
_081562CA:
	add sp, #0x6c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
