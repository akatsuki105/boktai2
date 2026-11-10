	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	movs r1, #0x10
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r5, r7, r2
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08128870
	bl _0812913E
_08128870:
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812888A
	movs r0, #1
	bl _08129140
_0812888A:
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0812889A
	bl _0812913E
_0812889A:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	bne _081288A8
	bl _0812913E
_081288A8:
	movs r1, #0x80
	lsls r1, r1, #0x11
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081288BE
	bl _0812913E
_081288BE:
	ldr r6, _08128920 @ =0x0000021E
	adds r0, r7, r6
	ldr r1, _08128924 @ =0x03002B68
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081288D0
	bl _0812913E
_081288D0:
	movs r1, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r7, #0
	bl Enemy_FindVisiblePlayer
	adds r1, r0, #0
	mov r8, r4
	cmp r1, #0
	bne _081288F0
	bl _081290FA
_081288F0:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
	ldr r0, [r1, #0x18]
	ldrh r0, [r0, #6]
	mov sl, r0
	movs r3, #0xfc
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	cmp r0, #0
	bne _0812890C
	b _0812909C
_0812890C:
	movs r1, #2
	ldr r4, _08128928 @ =0x00000474
	adds r0, r7, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812892C
	movs r0, #1
	b _0812892E
	.align 2, 0
_08128920: .4byte 0x0000021E
_08128924: .4byte 0x03002B68
_08128928: .4byte 0x00000474
_0812892C:
	movs r0, #0
_0812892E:
	cmp r0, #0
	beq _08128948
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _08128944 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r6, r1, #0
	b _08128956
	.align 2, 0
_08128944: .4byte 0x03002BE0
_08128948:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _0812898E
_08128956:
	ldr r1, [r6]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r7, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r7, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0812898E:
	adds r0, r7, #0
	bl Mummy_CanAttack
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812899C
	b _08128FDC
_0812899C:
	movs r1, #0xa0
	lsls r1, r1, #5
	ldr r0, _081289B0 @ =0x0000071E
	add r0, sb
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081289B4
	movs r0, #1
	b _081289B6
	.align 2, 0
_081289B0: .4byte 0x0000071E
_081289B4:
	movs r0, #0
_081289B6:
	cmp r0, #0
	beq _081289BC
	b _0812913E
_081289BC:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r3, r7, r4
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x60]
	str r2, [sp, #0x3c]
	cmp r4, #0
	blt _081289F8
	cmp r1, #0
	blt _081289F8
	ldr r0, _081289FC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081289F8
	ldr r0, _08128A00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08128A04
_081289F8:
	movs r4, #0
	b _08128A12
	.align 2, 0
_081289FC: .4byte 0x030046A8
_08128A00: .4byte 0x030046AC
_08128A04:
	ldr r0, _08128A24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08128A12:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08128A28
	adds r0, #4
	b _08128A34
	.align 2, 0
_08128A24: .4byte 0x030046A4
_08128A28:
	ldr r0, _08128A48 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08128A34:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08128A4C
	cmp r2, #2
	beq _08128A50
	b _08128A54
	.align 2, 0
_08128A48: .4byte 0x030046A4
_08128A4C:
	ldrb r0, [r5, #4]
	b _08128A52
_08128A50:
	ldrb r0, [r5]
_08128A52:
	subs r1, r1, r0
_08128A54:
	strh r1, [r5, #2]
	ldr r0, _08128A68 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08128A6C
	movs r0, #1
	b _08128A6E
	.align 2, 0
_08128A68: .4byte 0x030047A4
_08128A6C:
	movs r0, #0
_08128A6E:
	cmp r0, #0
	beq _08128AB0
	ldr r1, [r6]
	cmp r1, #0
	beq _08128A88
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08128A84
	adds r2, r0, #0
_08128A84:
	cmp r2, #0
	bge _08128A9C
_08128A88:
	ldr r6, _08128A98 @ =0x000005C4
	adds r0, r7, r6
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0812913E
	.align 2, 0
_08128A98: .4byte 0x000005C4
_08128A9C:
	ldr r1, _08128AAC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08128AF4
	.align 2, 0
_08128AAC: .4byte 0x03002BE0
_08128AB0:
	ldr r0, [r6]
	ldrh r1, [r0, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08128AD6
	cmp r1, #0
	blt _08128AD6
	ldr r0, _08128ADC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08128AD6
	ldr r0, _08128AE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08128AE4
_08128AD6:
	movs r5, #0
	b _08128AF2
	.align 2, 0
_08128ADC: .4byte 0x030046A8
_08128AE0: .4byte 0x030046AC
_08128AE4:
	ldr r0, _08128BD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08128AF2:
	movs r2, #0
_08128AF4:
	ldr r1, _08128BD4 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _08128B14
	ldr r1, _08128BD8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08128B14
	b _08128F0C
_08128B14:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	str r2, [sp, #0x64]
	cmp r1, #0
	beq _08128B30
	b _0812913E
_08128B30:
	ldr r4, _08128BDC @ =0x00000222
	adds r2, r7, r4
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x64]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x38]
	cmp r6, #0
	beq _08128BF0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _08128BE0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #8]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _08128BE4 @ =0x0000046B
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0
	strb r6, [r4]
	ldr r2, _08128BE8 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r3, r7
	mov sl, r3
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r5, r7, r4
	mov r6, sb
	strh r6, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	movs r2, #0
	strb r2, [r4]
	ldr r6, _08128BEC @ =0x00000469
	adds r3, r7, r6
	strb r2, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	adds r6, #0x1b
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #8]
	str r6, [sp, #0x54]
	mov r6, r8
	str r6, [sp, #0x4c]
	ldr r6, [sp, #0xc]
	str r6, [sp, #0x7c]
	mov r6, sl
	str r6, [sp, #0x80]
	str r5, [sp, #0x30]
	str r4, [sp, #0x40]
	str r3, [sp, #0x44]
	str r2, [sp, #0x48]
	str r1, [sp, #0x5c]
	str r0, [sp, #0x50]
	b _08128DC2
	.align 2, 0
_08128BD0: .4byte 0x030046A4
_08128BD4: .4byte 0x00000256
_08128BD8: .4byte 0x03002BE0
_08128BDC: .4byte 0x00000222
_08128BE0: .4byte 0x0000046D
_08128BE4: .4byte 0x0000046B
_08128BE8: .4byte 0x00000553
_08128BEC: .4byte 0x00000469
_08128BF0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _08128CB0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	ldr r3, _08128CB4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	ldr r2, _08128CB8 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x18]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x20]
	strh r6, [r4]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x24]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _08128CBC @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _08128CC0 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _08128CC4 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _08128CC8 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x60]
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x3c]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x28]
	strh r1, [r6]
	ldr r6, [sp, #0x3c]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x28]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x54]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x4c]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x7c]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x30]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x40]
	str r5, [sp, #0x44]
	str r4, [sp, #0x48]
	str r3, [sp, #0x5c]
	str r2, [sp, #0x50]
	mov r0, ip
	cmp r0, #0
	blt _08128CAC
	cmp r1, #0
	blt _08128CAC
	ldr r0, _08128CCC @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08128CAC
	ldr r0, _08128CD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08128CD4
_08128CAC:
	movs r4, #0
	b _08128CE4
	.align 2, 0
_08128CB0: .4byte 0x0000046D
_08128CB4: .4byte 0x0000046B
_08128CB8: .4byte 0x00000553
_08128CBC: .4byte 0x00000469
_08128CC0: .4byte 0x0000046A
_08128CC4: .4byte 0x00000484
_08128CC8: .4byte 0x0000046C
_08128CCC: .4byte 0x030046A8
_08128CD0: .4byte 0x030046AC
_08128CD4:
	ldr r0, _08128CF4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08128CE4:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08128CF8
	adds r0, #4
	b _08128D04
	.align 2, 0
_08128CF4: .4byte 0x030046A4
_08128CF8:
	ldr r0, _08128D18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08128D04:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08128D1C
	cmp r2, #2
	beq _08128D22
	b _08128D28
	.align 2, 0
_08128D18: .4byte 0x030046A4
_08128D1C:
	ldr r2, [sp, #0x28]
	ldrb r0, [r2, #4]
	b _08128D26
_08128D22:
	ldr r3, [sp, #0x28]
	ldrb r0, [r3]
_08128D26:
	subs r1, r1, r0
_08128D28:
	ldr r4, [sp, #0x28]
	strh r1, [r4, #2]
	ldr r6, [sp, #0x60]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08128D54
	cmp r1, #0
	blt _08128D54
	ldr r0, _08128D58 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08128D54
	ldr r0, _08128D5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08128D60
_08128D54:
	movs r4, #0
	b _08128D6E
	.align 2, 0
_08128D58: .4byte 0x030046A8
_08128D5C: .4byte 0x030046AC
_08128D60:
	ldr r0, _08128D84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08128D6E:
	ldr r0, [sp, #0x60]
	ldr r5, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08128D88
	adds r0, #4
	b _08128D94
	.align 2, 0
_08128D84: .4byte 0x030046A4
_08128D88:
	ldr r0, _08128DA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08128D94:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08128DAC
	cmp r3, #2
	beq _08128DB0
	b _08128DB4
	.align 2, 0
_08128DA8: .4byte 0x030046A4
_08128DAC:
	ldrb r0, [r5, #4]
	b _08128DB2
_08128DB0:
	ldrb r0, [r5]
_08128DB2:
	subs r2, r2, r0
_08128DB4:
	ldr r1, [sp, #0x60]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x60]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08128DC2:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x2c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x64]
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r6, _08128DEC @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x58]
	cmp r0, #0
	bne _08128ED0
	movs r1, #4
	ldr r2, [sp, #0x38]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08128DF0
	movs r0, #1
	b _08128DF2
	.align 2, 0
_08128DEC: .4byte 0x00000482
_08128DF0:
	movs r0, #0
_08128DF2:
	ldr r3, _08128EE0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _08128ED0
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _08128EE4 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08128EE8 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x70]
	ldr r2, _08128EEC @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x74]
	ldr r4, _08128EF0 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x78]
	ldr r6, _08128EF4 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x68]
	ldr r0, _08128EF8 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x34]
	ldr r1, _08128EFC @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	ldr r6, _08128F00 @ =0x0203B400
	ldr r1, _08128F04 @ =0x030046B8
	ldr r5, _08128F08 @ =0x000003FF
	movs r4, #3
	mov r2, r8
_08128E42:
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
	bne _08128E60
	adds r3, #1
	cmp r3, #3
	ble _08128E42
	mov r0, r8
_08128E60:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x80]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x7c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r6, [sp, #0x70]
	strb r0, [r6]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x74]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	add r0, sp, #0x2c
	ldrb r1, [r0]
	ldr r0, [sp, #0x68]
	strb r1, [r0]
	ldr r1, [sp, #0x34]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x54]
	strb r1, [r4]
	ldr r6, [sp, #0x4c]
	strb r3, [r6]
	ldr r4, [sp, #0x7c]
	strb r0, [r4]
	ldr r6, [sp, #0x80]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x30]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r6, [sp, #0x44]
	strb r1, [r6]
	ldr r0, [sp, #0x48]
	strb r2, [r0]
	ldr r2, [sp, #0x5c]
	str r3, [r2]
	ldr r3, [sp, #0x50]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x6c]
	strb r0, [r4]
_08128ED0:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r6, [sp, #0x58]
	strh r0, [r6]
	b _0812913E
	.align 2, 0
_08128EE0: .4byte 0x00000482
_08128EE4: .4byte 0x0000054F
_08128EE8: .4byte 0x0000054C
_08128EEC: .4byte 0x0000054D
_08128EF0: .4byte 0x0000054E
_08128EF4: .4byte 0x00000541
_08128EF8: .4byte 0x000005BC
_08128EFC: .4byte 0x00000542
_08128F00: .4byte 0x0203B400
_08128F04: .4byte 0x030046B8
_08128F08: .4byte 0x000003FF
_08128F0C:
	mov sb, sp
	ldr r6, _08128F48 @ =0x030046A4
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
	beq _08128F4C
	adds r0, #4
	b _08128F56
	.align 2, 0
_08128F48: .4byte 0x030046A4
_08128F4C:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08128F56:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r6, r8
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _08128F8C @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08128F90
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _08128FB6
	.align 2, 0
_08128F8C: .4byte 0x000004A4
_08128F90:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08128FB0
	cmp r0, #2
	beq _08128FAC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08128FAC:
	movs r0, #1
	b _08128FC0
_08128FB0:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_08128FB6:
	ldr r1, _08128FD4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08128FC0:
	cmp r0, #0
	beq _08128FC6
	b _0812913E
_08128FC6:
	ldr r4, _08128FD8 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0812913E
	.align 2, 0
_08128FD4: .4byte 0xFFFFFDFF
_08128FD8: .4byte 0x000005C4
_08128FDC:
	adds r0, r7, #0
	bl Mummy_TryReachHeardPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08128FEA
	b _0812913E
_08128FEA:
	movs r1, #0x80
	lsls r1, r1, #0x13
	mov r6, r8
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08129078
	ldr r1, _08129030 @ =0x0000025E
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, sl
	beq _0812907E
	ldr r2, _08129034 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08129038
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r7, r4
	b _0812905C
	.align 2, 0
_08129030: .4byte 0x0000025E
_08129034: .4byte 0x000004A4
_08129038:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08129056
	cmp r0, #2
	beq _08129064
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08129064
_08129056:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0812905C:
	ldr r1, _08129070 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08129064:
	ldr r1, _08129074 @ =0x0000025E
	adds r0, r7, r1
	mov r2, sl
	strh r2, [r0]
	b _0812907E
	.align 2, 0
_08129070: .4byte 0xFFFFFDFF
_08129074: .4byte 0x0000025E
_08129078:
	adds r0, r7, #0
	bl Enemy_Alert
_0812907E:
	movs r0, #0x80
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	mov r4, r8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
	b _08129140
_0812909C:
	movs r1, #0x80
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081290B2
	movs r1, #0x80
	lsls r1, r1, #3
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081290FA
_081290B2:
	movs r1, #0xa0
	lsls r1, r1, #5
	ldr r0, _081290C8 @ =0x0000071E
	add r0, sb
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081290CC
	movs r0, #1
	b _081290CE
	.align 2, 0
_081290C8: .4byte 0x0000071E
_081290CC:
	movs r0, #0
_081290CE:
	cmp r0, #0
	bne _081290FA
	ldr r6, _08129110 @ =0x00000482
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r0, #1
	bne _0812913E
	ldr r1, _08129114 @ =0x0000021E
	adds r0, r7, r1
	ldr r1, _08129118 @ =0x03002B68
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0812913E
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081290FA:
	movs r2, #0x80
	lsls r2, r2, #7
	ldr r1, _0812911C @ =0x0000071E
	add r1, sb
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _08129120
	movs r0, #1
	b _08129122
	.align 2, 0
_08129110: .4byte 0x00000482
_08129114: .4byte 0x0000021E
_08129118: .4byte 0x03002B68
_0812911C: .4byte 0x0000071E
_08129120:
	movs r0, #0
_08129122:
	cmp r0, #0
	beq _0812913E
	ldr r6, _08129150 @ =0x000001DF
	adds r0, r7, r6
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #1
	bl Enemy_SetEmote
	ldr r0, _08129154 @ =0xFFFFBFFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_0812913E:
	movs r0, #0
_08129140:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08129150: .4byte 0x000001DF
_08129154: .4byte 0xFFFFBFFF
