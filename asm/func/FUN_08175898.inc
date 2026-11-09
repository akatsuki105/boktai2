	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	str r0, [sp, #0x20]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r2, [sp, #0x20]
	ldr r3, _081758F8 @ =0x000004A4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrb r0, [r2, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	str r0, [sp, #0x2c]
	movs r1, #1
	rsbs r1, r1, #0
	add r0, sp, #0xc
_081758CC:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _081758CC
	movs r4, #0
	str r4, [sp, #0x34]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x24]
	movs r2, #0x81
	lsls r2, r2, #5
	adds r0, r1, r2
	ldrb r3, [r0]
	cmp r3, #2
	bne _081758FC
	ldr r6, [sp, #0x2c]
	adds r6, #1
	movs r0, #3
	ands r6, r0
	b _0817592A
	.align 2, 0
_081758F8: .4byte 0x000004A4
_081758FC:
	cmp r3, #3
	bne _08175928
	ldr r2, _0817591C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08175920 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08175924 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r1, [sp, #0x2c]
	adds r6, r1, r0
	ands r6, r3
	b _0817592A
	.align 2, 0
_0817591C: .4byte 0x030046B8
_08175920: .4byte 0x000003FF
_08175924: .4byte 0x0203B400
_08175928:
	ldr r6, [sp, #0x2c]
_0817592A:
	ldr r2, [sp, #0x24]
	movs r4, #0x81
	lsls r4, r4, #5
	adds r3, r2, r4
	ldrb r0, [r3]
	cmp r0, #0x10
	bls _08175956
	ldr r1, [sp, #0x20]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r4, [sp, #0x24]
	ldr r2, _08175990 @ =0x00001021
	adds r1, r4, r2
	movs r2, #0
	strb r0, [r1]
	strb r2, [r3]
_08175956:
	movs r3, #3
	str r3, [sp, #0x30]
_0817595A:
	ldr r4, [sp, #0x24]
	ldr r1, _08175990 @ =0x00001021
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, r6, r0
	cmp r0, #0
	bge _0817596A
	rsbs r0, r0, #0
_0817596A:
	cmp r0, #2
	bne _08175970
	b _08175D0E
_08175970:
	ldr r2, [sp, #0x2c]
	subs r0, r6, r2
	cmp r0, #0
	bge _0817597A
	rsbs r0, r0, #0
_0817597A:
	cmp r0, #2
	bne _08175980
	b _08175D0E
_08175980:
	cmp r6, #1
	beq _081759B0
	cmp r6, #1
	bgt _08175994
	cmp r6, #0
	beq _0817599E
	b _08175A04
	.align 2, 0
_08175990: .4byte 0x00001021
_08175994:
	cmp r6, #2
	beq _081759D0
	cmp r6, #3
	beq _081759E4
	b _08175A04
_0817599E:
	ldr r3, [sp, #0x20]
	ldr r4, _081759AC @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _08175A0E
	.align 2, 0
_081759AC: .4byte 0x00000256
_081759B0:
	ldr r0, [sp, #0x20]
	ldr r2, _081759C8 @ =0x00000256
	adds r1, r0, r2
	ldr r3, _081759CC @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	ldrh r2, [r1]
	adds r7, r0, r2
	str r1, [sp, #0x58]
	b _08175A0E
	.align 2, 0
_081759C8: .4byte 0x00000256
_081759CC: .4byte 0x030046A4
_081759D0:
	ldr r3, [sp, #0x20]
	ldr r4, _081759E0 @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _08175A0E
	.align 2, 0
_081759E0: .4byte 0x00000256
_081759E4:
	ldr r0, [sp, #0x20]
	ldr r2, _081759FC @ =0x00000256
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r3, _08175A00 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _08175A0E
	.align 2, 0
_081759FC: .4byte 0x00000256
_08175A00: .4byte 0x030046A4
_08175A04:
	ldr r1, [sp, #0x20]
	ldr r2, _08175A20 @ =0x00000256
	adds r0, r1, r2
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_08175A0E:
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175A24
	adds r0, #4
	b _08175A30
	.align 2, 0
_08175A20: .4byte 0x00000256
_08175A24:
	ldr r3, _08175A4C @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175A30:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x58]
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175A50
	adds r0, #4
	b _08175A5C
	.align 2, 0
_08175A4C: .4byte 0x030046A4
_08175A50:
	ldr r1, _08175A74 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175A5C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175A78
	adds r0, #4
	b _08175A84
	.align 2, 0
_08175A74: .4byte 0x030046A4
_08175A78:
	ldr r2, _08175AC8 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175A84:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x40]
	add r5, sp, #0x10
	ldr r3, _08175AC8 @ =0x030046A4
	mov r8, r3
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175ACC
	adds r0, #4
	b _08175AD8
	.align 2, 0
_08175AC8: .4byte 0x030046A4
_08175ACC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175AD8:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r5, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	add r4, sp, #0x10
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175AFC
	adds r0, #4
	b _08175B08
_08175AFC:
	ldr r1, _08175B1C @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175B08:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08175B20
	cmp r2, #2
	beq _08175B24
	b _08175B28
	.align 2, 0
_08175B1C: .4byte 0x030046A4
_08175B20:
	ldrb r0, [r4, #4]
	b _08175B26
_08175B24:
	ldrb r0, [r4]
_08175B26:
	subs r1, r1, r0
_08175B28:
	str r1, [sp, #0x44]
	ldr r2, [sp, #0x58]
	ldrh r5, [r2]
	add r3, sp, #0x10
	mov sb, r3
	ldr r4, _08175B70 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _08175B70 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x10
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175B74
	adds r0, #4
	b _08175B80
	.align 2, 0
_08175B70: .4byte 0x030046A4
_08175B74:
	ldr r3, _08175BAC @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175B80:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r4, sb
	strh r1, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	add r5, sp, #0x10
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175BB0
	adds r0, #4
	b _08175BBC
	.align 2, 0
_08175BAC: .4byte 0x030046A4
_08175BB0:
	ldr r3, _08175BD0 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175BBC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08175BD4
	cmp r2, #2
	beq _08175BD8
	b _08175BDC
	.align 2, 0
_08175BD0: .4byte 0x030046A4
_08175BD4:
	ldrb r0, [r5, #4]
	b _08175BDA
_08175BD8:
	ldrb r0, [r5]
_08175BDA:
	subs r1, r1, r0
_08175BDC:
	ldr r4, [sp, #0x44]
	subs r2, r4, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	adds r1, r4, #0
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r3, [sp, #0x40]
	ands r3, r0
	cmp r3, #0
	beq _08175BFC
	b _08175D0E
_08175BFC:
	cmp r2, #0
	beq _08175CF2
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _08175C22
	cmp r6, #1
	bne _08175C1A
	mov r0, sl
	cmp r0, #1
	bne _08175C3C
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _08175C4E
	b _08175D0E
_08175C1A:
	cmp r6, #3
	bne _08175D0E
	mov r4, sl
	b _08175C48
_08175C22:
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	bne _08175C4E
	cmp r6, #0
	bne _08175C42
	mov r3, sl
	cmp r3, #2
	bne _08175C3C
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _08175C4E
	b _08175D0E
_08175C3C:
	cmp r1, #0
	beq _08175C4E
	b _08175D0E
_08175C42:
	cmp r6, #2
	bne _08175D0E
	mov r0, sl
_08175C48:
	ldr r0, _08175C64 @ =0xFFFFFF00
	cmp r1, r0
	bne _08175D0E
_08175C4E:
	mov r3, sl
	cmp r3, #1
	bne _08175C7E
	cmp r6, #1
	bne _08175C72
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _08175C68
	movs r0, #0x80
	lsls r0, r0, #1
	b _08175CAA
	.align 2, 0
_08175C64: .4byte 0xFFFFFF00
_08175C68:
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _08175CB8
	b _08175D0E
_08175C72:
	cmp r6, #3
	bne _08175D0E
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	beq _08175CA8
	b _08175CB4
_08175C7E:
	mov r0, sl
	cmp r0, #2
	bne _08175CC4
	cmp r6, #0
	bne _08175C9E
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _08175C98
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _08175CB8
	b _08175D0E
_08175C98:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08175CAA
_08175C9E:
	cmp r6, #2
	bne _08175D0E
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _08175CB4
_08175CA8:
	ldr r0, _08175CB0 @ =0xFFFFFF00
_08175CAA:
	cmp r1, r0
	beq _08175CB8
	b _08175D0E
	.align 2, 0
_08175CB0: .4byte 0xFFFFFF00
_08175CB4:
	cmp r1, #0
	bne _08175D0E
_08175CB8:
	mov r4, sl
	cmp r4, #2
	bne _08175CC4
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	beq _08175CD0
_08175CC4:
	mov r1, sl
	cmp r1, #1
	bne _08175CE2
	ldr r3, [sp, #0x3c]
	cmp r3, #1
	bne _08175CE2
_08175CD0:
	adds r0, r2, #0
	cmp r2, #0
	bge _08175CD8
	rsbs r0, r2, #0
_08175CD8:
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r0, r4
	ble _08175CF2
	b _08175D0E
_08175CE2:
	adds r0, r2, #0
	cmp r0, #0
	bge _08175CEA
	rsbs r0, r0, #0
_08175CEA:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _08175CF4
_08175CF2:
	adds r5, r7, #0
_08175CF4:
	cmp r5, #0
	blt _08175D0E
	ldr r0, [sp, #0x2c]
	cmp r6, r0
	bne _08175D02
	str r5, [sp, #0x38]
	b _08175D0E
_08175D02:
	ldr r1, [sp, #0x34]
	lsls r0, r1, #2
	add r0, sp
	str r5, [r0]
	adds r1, #1
	str r1, [sp, #0x34]
_08175D0E:
	adds r6, #1
	movs r0, #3
	ands r6, r0
	ldr r2, [sp, #0x30]
	subs r2, #1
	str r2, [sp, #0x30]
	cmp r2, #0
	blt _08175D20
	b _0817595A
_08175D20:
	ldr r3, [sp, #0x34]
	cmp r3, #0
	bne _08175D28
	b _08175E7C
_08175D28:
	movs r4, #0
	str r4, [sp, #0x30]
	ldr r4, [sp, #0x28]
	adds r4, #0xc
	ldr r0, [sp, #0x30]
	cmp r0, r3
	bge _08175DD6
	mov r6, sp
_08175D38:
	ldr r1, [r6]
	ldr r0, [sp, #0x20]
	bl FUN_081794e0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08175DC8
	mov sb, r4
	ldr r5, [r6]
	ldr r7, _08175D84 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x28]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175D88
	adds r0, #4
	b _08175D92
	.align 2, 0
_08175D84: .4byte 0x030046A4
_08175D88:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175D92:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	mov r2, r8
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r1, [r6]
	ldr r0, [sp, #0x20]
	bl FUN_08179510
	ldr r3, [sp, #0x24]
	movs r4, #0x81
	lsls r4, r4, #5
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08175DC4 @ =0x0000101C
	adds r1, r3, r0
	b _08176306
	.align 2, 0
_08175DC4: .4byte 0x0000101C
_08175DC8:
	adds r6, #4
	ldr r1, [sp, #0x30]
	adds r1, #1
	str r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	cmp r1, r2
	blt _08175D38
_08175DD6:
	ldr r2, _08175E34 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08175E38 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08175E3C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	bl Mod
	str r0, [sp, #0x30]
	lsls r0, r0, #2
	add r0, sp
	mov r8, r4
	ldr r5, [r0]
	ldr r6, _08175E40 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r3, [sp, #0x28]
	strh r4, [r3, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175E44
	adds r0, #4
	b _08175E4E
	.align 2, 0
_08175E34: .4byte 0x030046B8
_08175E38: .4byte 0x000003FF
_08175E3C: .4byte 0x0203B400
_08175E40: .4byte 0x030046A4
_08175E44:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175E4E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, r8
	strh r0, [r4, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, [sp, #0x30]
	lsls r0, r1, #2
	add r0, sp
	ldr r1, [r0]
	ldr r0, [sp, #0x20]
	bl FUN_08179510
	ldr r2, [sp, #0x24]
	movs r3, #0x81
	lsls r3, r3, #5
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #1
	b _08176300
_08175E7C:
	movs r0, #1
	rsbs r0, r0, #0
	ldr r1, [sp, #0x38]
	cmp r1, r0
	beq _08175F10
	ldr r0, [sp, #0x20]
	bl FUN_081794e0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08175F10
	ldr r7, [sp, #0x28]
	adds r7, #0xc
	ldr r5, _08175ED0 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	ldr r0, [sp, #0x38]
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	ldr r0, [sp, #0x38]
	bl Div
	adds r6, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x28]
	strh r4, [r0, #0xc]
	ldr r0, [sp, #0x38]
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175ED4
	adds r0, #4
	b _08175EE0
	.align 2, 0
_08175ED0: .4byte 0x030046A4
_08175ED4:
	ldr r0, [r5]
	ldr r2, [sp, #0x38]
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08175EE0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r7, #2]
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x38]
	bl FUN_08179510
	ldr r3, [sp, #0x24]
	movs r4, #0x81
	lsls r4, r4, #5
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	ldr r0, _08175F0C @ =0x0000101C
	adds r1, r3, r0
	b _08176306
	.align 2, 0
_08175F0C: .4byte 0x0000101C
_08175F10:
	ldr r1, [sp, #0x24]
	ldr r2, _08175F2C @ =0x00001021
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r6, r0, #2
	movs r0, #3
	ands r6, r0
	cmp r6, #1
	beq _08175F4C
	cmp r6, #1
	bgt _08175F30
	cmp r6, #0
	beq _08175F3A
	b _08175FA0
	.align 2, 0
_08175F2C: .4byte 0x00001021
_08175F30:
	cmp r6, #2
	beq _08175F6C
	cmp r6, #3
	beq _08175F80
	b _08175FA0
_08175F3A:
	ldr r3, [sp, #0x20]
	ldr r4, _08175F48 @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _08175FAA
	.align 2, 0
_08175F48: .4byte 0x00000256
_08175F4C:
	ldr r0, [sp, #0x20]
	ldr r2, _08175F64 @ =0x00000256
	adds r1, r0, r2
	ldr r0, _08175F68 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r4, [r1]
	adds r7, r0, r4
	str r1, [sp, #0x58]
	b _08175FAA
	.align 2, 0
_08175F64: .4byte 0x00000256
_08175F68: .4byte 0x030046A4
_08175F6C:
	ldr r0, [sp, #0x20]
	ldr r2, _08175F7C @ =0x00000256
	adds r1, r0, r2
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _08175FAA
	.align 2, 0
_08175F7C: .4byte 0x00000256
_08175F80:
	ldr r3, [sp, #0x20]
	ldr r4, _08175F98 @ =0x00000256
	adds r1, r3, r4
	ldrh r2, [r1]
	ldr r0, _08175F9C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _08175FAA
	.align 2, 0
_08175F98: .4byte 0x00000256
_08175F9C: .4byte 0x030046A4
_08175FA0:
	ldr r4, [sp, #0x20]
	ldr r1, _08175FBC @ =0x00000256
	adds r0, r4, r1
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_08175FAA:
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175FC0
	adds r0, #4
	b _08175FCC
	.align 2, 0
_08175FBC: .4byte 0x00000256
_08175FC0:
	ldr r0, _08175FE8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08175FCC:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08175FEC
	adds r0, #4
	b _08175FF8
	.align 2, 0
_08175FE8: .4byte 0x030046A4
_08175FEC:
	ldr r0, _08176010 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08175FF8:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08176014
	adds r0, #4
	b _08176020
	.align 2, 0
_08176010: .4byte 0x030046A4
_08176014:
	ldr r0, _08176064 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08176020:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x48]
	add r5, sp, #0x18
	ldr r3, _08176064 @ =0x030046A4
	mov r8, r3
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	str r0, [sp, #0x4c]
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08176068
	adds r0, #4
	b _08176074
	.align 2, 0
_08176064: .4byte 0x030046A4
_08176068:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08176074:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r5, #2]
	ldr r4, [sp, #0x4c]
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	add r4, sp, #0x18
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08176098
	adds r0, #4
	b _081760A4
_08176098:
	ldr r2, _081760B8 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081760A4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081760BC
	cmp r2, #2
	beq _081760C0
	b _081760C4
	.align 2, 0
_081760B8: .4byte 0x030046A4
_081760BC:
	ldrb r0, [r4, #4]
	b _081760C2
_081760C0:
	ldrb r0, [r4]
_081760C2:
	subs r1, r1, r0
_081760C4:
	str r1, [sp, #0x50]
	ldr r0, [sp, #0x58]
	ldrh r5, [r0]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x54]
	ldr r2, _0817610C @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0817610C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x18
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08176110
	adds r0, #4
	b _0817611C
	.align 2, 0
_0817610C: .4byte 0x030046A4
_08176110:
	ldr r3, _08176148 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817611C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	ldr r4, [sp, #0x54]
	strh r1, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	add r5, sp, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817614C
	adds r0, #4
	b _08176158
	.align 2, 0
_08176148: .4byte 0x030046A4
_0817614C:
	ldr r0, _0817616C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08176158:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08176170
	cmp r2, #2
	beq _08176174
	b _08176178
	.align 2, 0
_0817616C: .4byte 0x030046A4
_08176170:
	ldrb r0, [r5, #4]
	b _08176176
_08176174:
	ldrb r0, [r5]
_08176176:
	subs r1, r1, r0
_08176178:
	ldr r3, [sp, #0x50]
	subs r2, r3, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	adds r1, r3, #0
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r4, [sp, #0x48]
	ands r4, r0
	cmp r4, #0
	beq _08176198
	b _08176310
_08176198:
	cmp r2, #0
	beq _08176286
	mov r0, sl
	cmp r0, #1
	bne _081761BA
	cmp r6, #1
	bne _081761B2
	mov r3, sb
	cmp r3, #1
	bne _081761D0
	movs r0, #0x80
	lsls r0, r0, #1
	b _081761E0
_081761B2:
	cmp r6, #3
	beq _081761B8
	b _08176310
_081761B8:
	b _081761DC
_081761BA:
	mov r0, sl
	cmp r0, #2
	bne _081761E6
	cmp r6, #0
	bne _081761D6
	mov r3, sb
	cmp r3, #2
	bne _081761D0
	movs r0, #0x80
	lsls r0, r0, #1
	b _081761E0
_081761D0:
	cmp r1, #0
	beq _081761E6
	b _08176310
_081761D6:
	cmp r6, #2
	beq _081761DC
	b _08176310
_081761DC:
	mov r4, sb
	ldr r0, _081761FC @ =0xFFFFFF00
_081761E0:
	cmp r1, r0
	beq _081761E6
	b _08176310
_081761E6:
	mov r0, sb
	cmp r0, #1
	bne _08176214
	cmp r6, #1
	bne _08176206
	mov r3, sl
	cmp r3, #1
	bne _08176200
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817623C
	.align 2, 0
_081761FC: .4byte 0xFFFFFF00
_08176200:
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817623C
_08176206:
	cmp r6, #3
	beq _0817620C
	b _08176310
_0817620C:
	mov r4, sl
	cmp r4, #1
	beq _0817623A
	b _08176248
_08176214:
	mov r0, sb
	cmp r0, #2
	bne _08176258
	cmp r6, #0
	bne _08176230
	mov r3, sl
	cmp r3, #2
	bne _0817622A
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817623C
_0817622A:
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817623C
_08176230:
	cmp r6, #2
	bne _08176310
	mov r4, sl
	cmp r4, #2
	bne _08176248
_0817623A:
	ldr r0, _08176244 @ =0xFFFFFF00
_0817623C:
	cmp r1, r0
	beq _0817624C
	b _08176310
	.align 2, 0
_08176244: .4byte 0xFFFFFF00
_08176248:
	cmp r1, #0
	bne _08176310
_0817624C:
	mov r0, sb
	cmp r0, #2
	bne _08176258
	mov r1, sl
	cmp r1, #2
	beq _08176264
_08176258:
	mov r3, sb
	cmp r3, #1
	bne _08176276
	mov r4, sl
	cmp r4, #1
	bne _08176276
_08176264:
	adds r1, r2, #0
	cmp r2, #0
	bge _0817626C
	rsbs r1, r2, #0
_0817626C:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _08176286
	b _08176310
_08176276:
	adds r0, r2, #0
	cmp r0, #0
	bge _0817627E
	rsbs r0, r0, #0
_0817627E:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _08176288
_08176286:
	adds r5, r7, #0
_08176288:
	cmp r5, #0
	blt _08176310
	ldr r0, [sp, #0x28]
	adds r0, #0xc
	mov r8, r0
	ldr r6, _081762CC @ =0x030046A4
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
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x28]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081762D0
	adds r0, #4
	b _081762DA
	.align 2, 0
_081762CC: .4byte 0x030046A4
_081762D0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081762DA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, [sp, #0x20]
	adds r1, r5, #0
	bl FUN_08179510
	ldr r2, [sp, #0x24]
	movs r3, #0x81
	lsls r3, r3, #5
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #2
_08176300:
	strb r0, [r1]
	ldr r4, _0817630C @ =0x0000101C
	adds r1, r2, r4
_08176306:
	movs r0, #0x28
	strh r0, [r1]
	b _08176320
	.align 2, 0
_0817630C: .4byte 0x0000101C
_08176310:
	ldr r1, [sp, #0x24]
	ldr r2, _08176330 @ =0x00001021
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #3
	ands r1, r2
	strb r1, [r0]
_08176320:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08176330: .4byte 0x00001021
