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
	ldr r3, _08135650 @ =0x000004A4
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
_08135624:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _08135624
	movs r4, #0
	str r4, [sp, #0x34]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x20]
	ldr r2, _08135654 @ =0x00000256
	adds r0, r1, r2
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08135658
	adds r0, #4
	b _08135664
	.align 2, 0
_08135650: .4byte 0x000004A4
_08135654: .4byte 0x00000256
_08135658:
	ldr r0, _08135684 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135664:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	subs r0, #1
	cmp r0, #1
	bls _081356B8
	ldr r3, [sp, #0x24]
	ldr r4, _08135688 @ =0x00000B48
	adds r0, r3, r4
	ldrb r3, [r0]
	cmp r3, #2
	bne _0813568C
	ldr r6, [sp, #0x2c]
	adds r6, #1
	movs r0, #3
	ands r6, r0
	b _081356BA
	.align 2, 0
_08135684: .4byte 0x030046A4
_08135688: .4byte 0x00000B48
_0813568C:
	cmp r3, #3
	bne _081356B8
	ldr r2, _081356AC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081356B0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081356B4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x2c]
	adds r6, r2, r0
	ands r6, r3
	b _081356BA
	.align 2, 0
_081356AC: .4byte 0x030046B8
_081356B0: .4byte 0x000003FF
_081356B4: .4byte 0x0203B400
_081356B8:
	ldr r6, [sp, #0x2c]
_081356BA:
	ldr r4, [sp, #0x24]
	ldr r0, _0813571C @ =0x00000B48
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0x10
	bls _081356E2
	ldr r1, [sp, #0x20]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, _08135720 @ =0x00000B49
	adds r1, r4, r2
	movs r2, #0
	strb r0, [r1]
	strb r2, [r3]
_081356E2:
	movs r3, #3
	str r3, [sp, #0x30]
_081356E6:
	ldr r4, [sp, #0x24]
	ldr r1, _08135720 @ =0x00000B49
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, r6, r0
	cmp r0, #0
	bge _081356F6
	rsbs r0, r0, #0
_081356F6:
	cmp r0, #2
	bne _081356FC
	b _08135A9E
_081356FC:
	ldr r2, [sp, #0x2c]
	subs r0, r6, r2
	cmp r0, #0
	bge _08135706
	rsbs r0, r0, #0
_08135706:
	cmp r0, #2
	bne _0813570C
	b _08135A9E
_0813570C:
	cmp r6, #1
	beq _08135740
	cmp r6, #1
	bgt _08135724
	cmp r6, #0
	beq _0813572E
	b _08135794
	.align 2, 0
_0813571C: .4byte 0x00000B48
_08135720: .4byte 0x00000B49
_08135724:
	cmp r6, #2
	beq _08135760
	cmp r6, #3
	beq _08135774
	b _08135794
_0813572E:
	ldr r3, [sp, #0x20]
	ldr r4, _0813573C @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _0813579E
	.align 2, 0
_0813573C: .4byte 0x00000256
_08135740:
	ldr r0, [sp, #0x20]
	ldr r2, _08135758 @ =0x00000256
	adds r1, r0, r2
	ldr r3, _0813575C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	ldrh r2, [r1]
	adds r7, r0, r2
	str r1, [sp, #0x58]
	b _0813579E
	.align 2, 0
_08135758: .4byte 0x00000256
_0813575C: .4byte 0x030046A4
_08135760:
	ldr r3, [sp, #0x20]
	ldr r4, _08135770 @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _0813579E
	.align 2, 0
_08135770: .4byte 0x00000256
_08135774:
	ldr r0, [sp, #0x20]
	ldr r2, _0813578C @ =0x00000256
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r3, _08135790 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _0813579E
	.align 2, 0
_0813578C: .4byte 0x00000256
_08135790: .4byte 0x030046A4
_08135794:
	ldr r1, [sp, #0x20]
	ldr r2, _081357B0 @ =0x00000256
	adds r0, r1, r2
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_0813579E:
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081357B4
	adds r0, #4
	b _081357C0
	.align 2, 0
_081357B0: .4byte 0x00000256
_081357B4:
	ldr r3, _081357DC @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081357C0:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x58]
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081357E0
	adds r0, #4
	b _081357EC
	.align 2, 0
_081357DC: .4byte 0x030046A4
_081357E0:
	ldr r1, _08135804 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081357EC:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08135808
	adds r0, #4
	b _08135814
	.align 2, 0
_08135804: .4byte 0x030046A4
_08135808:
	ldr r2, _08135858 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135814:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x40]
	add r5, sp, #0x10
	ldr r3, _08135858 @ =0x030046A4
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
	beq _0813585C
	adds r0, #4
	b _08135868
	.align 2, 0
_08135858: .4byte 0x030046A4
_0813585C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135868:
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
	beq _0813588C
	adds r0, #4
	b _08135898
_0813588C:
	ldr r1, _081358AC @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135898:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081358B0
	cmp r2, #2
	beq _081358B4
	b _081358B8
	.align 2, 0
_081358AC: .4byte 0x030046A4
_081358B0:
	ldrb r0, [r4, #4]
	b _081358B6
_081358B4:
	ldrb r0, [r4]
_081358B6:
	subs r1, r1, r0
_081358B8:
	str r1, [sp, #0x44]
	ldr r2, [sp, #0x58]
	ldrh r5, [r2]
	add r3, sp, #0x10
	mov sb, r3
	ldr r4, _08135900 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _08135900 @ =0x030046A4
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
	beq _08135904
	adds r0, #4
	b _08135910
	.align 2, 0
_08135900: .4byte 0x030046A4
_08135904:
	ldr r3, _0813593C @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135910:
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
	beq _08135940
	adds r0, #4
	b _0813594C
	.align 2, 0
_0813593C: .4byte 0x030046A4
_08135940:
	ldr r3, _08135960 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0813594C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08135964
	cmp r2, #2
	beq _08135968
	b _0813596C
	.align 2, 0
_08135960: .4byte 0x030046A4
_08135964:
	ldrb r0, [r5, #4]
	b _0813596A
_08135968:
	ldrb r0, [r5]
_0813596A:
	subs r1, r1, r0
_0813596C:
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
	beq _0813598C
	b _08135A9E
_0813598C:
	cmp r2, #0
	beq _08135A82
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _081359B2
	cmp r6, #1
	bne _081359AA
	mov r0, sl
	cmp r0, #1
	bne _081359CC
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _081359DE
	b _08135A9E
_081359AA:
	cmp r6, #3
	bne _08135A9E
	mov r4, sl
	b _081359D8
_081359B2:
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	bne _081359DE
	cmp r6, #0
	bne _081359D2
	mov r3, sl
	cmp r3, #2
	bne _081359CC
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _081359DE
	b _08135A9E
_081359CC:
	cmp r1, #0
	beq _081359DE
	b _08135A9E
_081359D2:
	cmp r6, #2
	bne _08135A9E
	mov r0, sl
_081359D8:
	ldr r0, _081359F4 @ =0xFFFFFF00
	cmp r1, r0
	bne _08135A9E
_081359DE:
	mov r3, sl
	cmp r3, #1
	bne _08135A0E
	cmp r6, #1
	bne _08135A02
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _081359F8
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135A3A
	.align 2, 0
_081359F4: .4byte 0xFFFFFF00
_081359F8:
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _08135A48
	b _08135A9E
_08135A02:
	cmp r6, #3
	bne _08135A9E
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	beq _08135A38
	b _08135A44
_08135A0E:
	mov r0, sl
	cmp r0, #2
	bne _08135A54
	cmp r6, #0
	bne _08135A2E
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _08135A28
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _08135A48
	b _08135A9E
_08135A28:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135A3A
_08135A2E:
	cmp r6, #2
	bne _08135A9E
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _08135A44
_08135A38:
	ldr r0, _08135A40 @ =0xFFFFFF00
_08135A3A:
	cmp r1, r0
	beq _08135A48
	b _08135A9E
	.align 2, 0
_08135A40: .4byte 0xFFFFFF00
_08135A44:
	cmp r1, #0
	bne _08135A9E
_08135A48:
	mov r4, sl
	cmp r4, #2
	bne _08135A54
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	beq _08135A60
_08135A54:
	mov r1, sl
	cmp r1, #1
	bne _08135A72
	ldr r3, [sp, #0x3c]
	cmp r3, #1
	bne _08135A72
_08135A60:
	adds r0, r2, #0
	cmp r2, #0
	bge _08135A68
	rsbs r0, r2, #0
_08135A68:
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r0, r4
	ble _08135A82
	b _08135A9E
_08135A72:
	adds r0, r2, #0
	cmp r0, #0
	bge _08135A7A
	rsbs r0, r0, #0
_08135A7A:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _08135A84
_08135A82:
	adds r5, r7, #0
_08135A84:
	cmp r5, #0
	blt _08135A9E
	ldr r0, [sp, #0x2c]
	cmp r6, r0
	bne _08135A92
	str r5, [sp, #0x38]
	b _08135A9E
_08135A92:
	ldr r1, [sp, #0x34]
	lsls r0, r1, #2
	add r0, sp
	str r5, [r0]
	adds r1, #1
	str r1, [sp, #0x34]
_08135A9E:
	adds r6, #1
	movs r0, #3
	ands r6, r0
	ldr r2, [sp, #0x30]
	subs r2, #1
	str r2, [sp, #0x30]
	cmp r2, #0
	blt _08135AB0
	b _081356E6
_08135AB0:
	ldr r3, [sp, #0x34]
	cmp r3, #0
	bne _08135AB8
	b _08135C10
_08135AB8:
	movs r4, #0
	str r4, [sp, #0x30]
	ldr r4, [sp, #0x28]
	adds r4, #0xc
	ldr r0, [sp, #0x30]
	cmp r0, r3
	bge _08135B66
	mov r6, sp
_08135AC8:
	ldr r1, [r6]
	ldr r0, [sp, #0x20]
	bl FUN_08138744
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08135B58
	mov sb, r4
	ldr r5, [r6]
	ldr r7, _08135B14 @ =0x030046A4
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
	beq _08135B18
	adds r0, #4
	b _08135B22
	.align 2, 0
_08135B14: .4byte 0x030046A4
_08135B18:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135B22:
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
	bl FUN_08138770
	ldr r3, [sp, #0x24]
	ldr r4, _08135B50 @ =0x00000B48
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08135B54 @ =0x00000B44
	adds r1, r3, r0
	b _0813609C
	.align 2, 0
_08135B50: .4byte 0x00000B48
_08135B54: .4byte 0x00000B44
_08135B58:
	adds r6, #4
	ldr r1, [sp, #0x30]
	adds r1, #1
	str r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	cmp r1, r2
	blt _08135AC8
_08135B66:
	ldr r2, _08135BC4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08135BC8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08135BCC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	bl Mod
	str r0, [sp, #0x30]
	lsls r0, r0, #2
	add r0, sp
	mov r8, r4
	ldr r5, [r0]
	ldr r6, _08135BD0 @ =0x030046A4
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
	beq _08135BD4
	adds r0, #4
	b _08135BDE
	.align 2, 0
_08135BC4: .4byte 0x030046B8
_08135BC8: .4byte 0x000003FF
_08135BCC: .4byte 0x0203B400
_08135BD0: .4byte 0x030046A4
_08135BD4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135BDE:
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
	bl FUN_08138770
	ldr r2, [sp, #0x24]
	ldr r3, _08135C0C @ =0x00000B48
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #1
	b _08136096
	.align 2, 0
_08135C0C: .4byte 0x00000B48
_08135C10:
	movs r0, #1
	rsbs r0, r0, #0
	ldr r1, [sp, #0x38]
	cmp r1, r0
	beq _08135CA8
	ldr r0, [sp, #0x20]
	bl FUN_08138744
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08135CA8
	ldr r7, [sp, #0x28]
	adds r7, #0xc
	ldr r5, _08135C64 @ =0x030046A4
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
	beq _08135C68
	adds r0, #4
	b _08135C74
	.align 2, 0
_08135C64: .4byte 0x030046A4
_08135C68:
	ldr r0, [r5]
	ldr r2, [sp, #0x38]
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135C74:
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
	bl FUN_08138770
	ldr r3, [sp, #0x24]
	ldr r4, _08135CA0 @ =0x00000B48
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	ldr r0, _08135CA4 @ =0x00000B44
	adds r1, r3, r0
	b _0813609C
	.align 2, 0
_08135CA0: .4byte 0x00000B48
_08135CA4: .4byte 0x00000B44
_08135CA8:
	ldr r1, [sp, #0x24]
	ldr r2, _08135CC4 @ =0x00000B49
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r6, r0, #2
	movs r0, #3
	ands r6, r0
	cmp r6, #1
	beq _08135CE4
	cmp r6, #1
	bgt _08135CC8
	cmp r6, #0
	beq _08135CD2
	b _08135D38
	.align 2, 0
_08135CC4: .4byte 0x00000B49
_08135CC8:
	cmp r6, #2
	beq _08135D04
	cmp r6, #3
	beq _08135D18
	b _08135D38
_08135CD2:
	ldr r3, [sp, #0x20]
	ldr r4, _08135CE0 @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _08135D42
	.align 2, 0
_08135CE0: .4byte 0x00000256
_08135CE4:
	ldr r0, [sp, #0x20]
	ldr r2, _08135CFC @ =0x00000256
	adds r1, r0, r2
	ldr r0, _08135D00 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r4, [r1]
	adds r7, r0, r4
	str r1, [sp, #0x58]
	b _08135D42
	.align 2, 0
_08135CFC: .4byte 0x00000256
_08135D00: .4byte 0x030046A4
_08135D04:
	ldr r0, [sp, #0x20]
	ldr r2, _08135D14 @ =0x00000256
	adds r1, r0, r2
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _08135D42
	.align 2, 0
_08135D14: .4byte 0x00000256
_08135D18:
	ldr r3, [sp, #0x20]
	ldr r4, _08135D30 @ =0x00000256
	adds r1, r3, r4
	ldrh r2, [r1]
	ldr r0, _08135D34 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _08135D42
	.align 2, 0
_08135D30: .4byte 0x00000256
_08135D34: .4byte 0x030046A4
_08135D38:
	ldr r4, [sp, #0x20]
	ldr r1, _08135D54 @ =0x00000256
	adds r0, r4, r1
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_08135D42:
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08135D58
	adds r0, #4
	b _08135D64
	.align 2, 0
_08135D54: .4byte 0x00000256
_08135D58:
	ldr r0, _08135D80 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135D64:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08135D84
	adds r0, #4
	b _08135D90
	.align 2, 0
_08135D80: .4byte 0x030046A4
_08135D84:
	ldr r0, _08135DA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135D90:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08135DAC
	adds r0, #4
	b _08135DB8
	.align 2, 0
_08135DA8: .4byte 0x030046A4
_08135DAC:
	ldr r0, _08135DFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135DB8:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x48]
	add r5, sp, #0x18
	ldr r3, _08135DFC @ =0x030046A4
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
	beq _08135E00
	adds r0, #4
	b _08135E0C
	.align 2, 0
_08135DFC: .4byte 0x030046A4
_08135E00:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135E0C:
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
	beq _08135E30
	adds r0, #4
	b _08135E3C
_08135E30:
	ldr r2, _08135E50 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135E3C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08135E54
	cmp r2, #2
	beq _08135E58
	b _08135E5C
	.align 2, 0
_08135E50: .4byte 0x030046A4
_08135E54:
	ldrb r0, [r4, #4]
	b _08135E5A
_08135E58:
	ldrb r0, [r4]
_08135E5A:
	subs r1, r1, r0
_08135E5C:
	str r1, [sp, #0x50]
	ldr r0, [sp, #0x58]
	ldrh r5, [r0]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x54]
	ldr r2, _08135EA4 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _08135EA4 @ =0x030046A4
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
	beq _08135EA8
	adds r0, #4
	b _08135EB4
	.align 2, 0
_08135EA4: .4byte 0x030046A4
_08135EA8:
	ldr r3, _08135EE0 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08135EB4:
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
	beq _08135EE4
	adds r0, #4
	b _08135EF0
	.align 2, 0
_08135EE0: .4byte 0x030046A4
_08135EE4:
	ldr r0, _08135F04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08135EF0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08135F08
	cmp r2, #2
	beq _08135F0C
	b _08135F10
	.align 2, 0
_08135F04: .4byte 0x030046A4
_08135F08:
	ldrb r0, [r5, #4]
	b _08135F0E
_08135F0C:
	ldrb r0, [r5]
_08135F0E:
	subs r1, r1, r0
_08135F10:
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
	beq _08135F30
	b _081360AC
_08135F30:
	cmp r2, #0
	beq _0813601E
	mov r0, sl
	cmp r0, #1
	bne _08135F52
	cmp r6, #1
	bne _08135F4A
	mov r3, sb
	cmp r3, #1
	bne _08135F68
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135F78
_08135F4A:
	cmp r6, #3
	beq _08135F50
	b _081360AC
_08135F50:
	b _08135F74
_08135F52:
	mov r0, sl
	cmp r0, #2
	bne _08135F7E
	cmp r6, #0
	bne _08135F6E
	mov r3, sb
	cmp r3, #2
	bne _08135F68
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135F78
_08135F68:
	cmp r1, #0
	beq _08135F7E
	b _081360AC
_08135F6E:
	cmp r6, #2
	beq _08135F74
	b _081360AC
_08135F74:
	mov r4, sb
	ldr r0, _08135F94 @ =0xFFFFFF00
_08135F78:
	cmp r1, r0
	beq _08135F7E
	b _081360AC
_08135F7E:
	mov r0, sb
	cmp r0, #1
	bne _08135FAC
	cmp r6, #1
	bne _08135F9E
	mov r3, sl
	cmp r3, #1
	bne _08135F98
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135FD4
	.align 2, 0
_08135F94: .4byte 0xFFFFFF00
_08135F98:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135FD4
_08135F9E:
	cmp r6, #3
	beq _08135FA4
	b _081360AC
_08135FA4:
	mov r4, sl
	cmp r4, #1
	beq _08135FD2
	b _08135FE0
_08135FAC:
	mov r0, sb
	cmp r0, #2
	bne _08135FF0
	cmp r6, #0
	bne _08135FC8
	mov r3, sl
	cmp r3, #2
	bne _08135FC2
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135FD4
_08135FC2:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08135FD4
_08135FC8:
	cmp r6, #2
	bne _081360AC
	mov r4, sl
	cmp r4, #2
	bne _08135FE0
_08135FD2:
	ldr r0, _08135FDC @ =0xFFFFFF00
_08135FD4:
	cmp r1, r0
	beq _08135FE4
	b _081360AC
	.align 2, 0
_08135FDC: .4byte 0xFFFFFF00
_08135FE0:
	cmp r1, #0
	bne _081360AC
_08135FE4:
	mov r0, sb
	cmp r0, #2
	bne _08135FF0
	mov r1, sl
	cmp r1, #2
	beq _08135FFC
_08135FF0:
	mov r3, sb
	cmp r3, #1
	bne _0813600E
	mov r4, sl
	cmp r4, #1
	bne _0813600E
_08135FFC:
	adds r1, r2, #0
	cmp r2, #0
	bge _08136004
	rsbs r1, r2, #0
_08136004:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _0813601E
	b _081360AC
_0813600E:
	adds r0, r2, #0
	cmp r0, #0
	bge _08136016
	rsbs r0, r0, #0
_08136016:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _08136020
_0813601E:
	adds r5, r7, #0
_08136020:
	cmp r5, #0
	blt _081360AC
	ldr r0, [sp, #0x28]
	adds r0, #0xc
	mov r8, r0
	ldr r6, _08136064 @ =0x030046A4
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
	beq _08136068
	adds r0, #4
	b _08136072
	.align 2, 0
_08136064: .4byte 0x030046A4
_08136068:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08136072:
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
	bl FUN_08138770
	ldr r2, [sp, #0x24]
	ldr r3, _081360A4 @ =0x00000B48
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #2
_08136096:
	strb r0, [r1]
	ldr r4, _081360A8 @ =0x00000B44
	adds r1, r2, r4
_0813609C:
	movs r0, #0x28
	strh r0, [r1]
	b _081360BC
	.align 2, 0
_081360A4: .4byte 0x00000B48
_081360A8: .4byte 0x00000B44
_081360AC:
	ldr r1, [sp, #0x24]
	ldr r2, _081360CC @ =0x00000B49
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #3
	ands r1, r2
	strb r1, [r0]
_081360BC:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081360CC: .4byte 0x00000B49
