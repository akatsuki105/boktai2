	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xbc
	adds r7, r0, #0
	ldr r0, _08119A3C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08119A40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08119A42
	.align 2, 0
_08119A3C: .4byte 0x0000046D
_08119A40:
	movs r0, #0
_08119A42:
	cmp r0, #0
	beq _08119A76
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08119A64
	ldr r0, _08119AA8 @ =0x0000018B
	bl PlaySound_082406e0
_08119A64:
	movs r0, #0x20
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _08119AAC @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
_08119A76:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x83
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _08119AB0
	asrs r0, r0, #2
	b _08119AB6
	.align 2, 0
_08119AA8: .4byte 0x0000018B
_08119AAC: .4byte 0xFFFFFEFF
_08119AB0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08119AB6:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _08119AD6
	asrs r0, r0, #2
	b _08119ADC
_08119AD6:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08119ADC:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _08119AE6
	movs r3, #0xc8
	b _08119AF0
_08119AE6:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08119AF0
	adds r3, r0, #0
_08119AF0:
	cmp r2, #0xc8
	ble _08119AF8
	movs r2, #0xc8
	b _08119B02
_08119AF8:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08119B02
	adds r2, r0, #0
_08119B02:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _08119B26
	cmp r2, #0
	bne _08119B26
	movs r0, #1
	b _08119B28
_08119B26:
	movs r0, #0
_08119B28:
	cmp r0, #0
	bne _08119B30
	bl _0811AA44
_08119B30:
	ldr r6, _08119BBC @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _08119B3E
	bl _0811AA44
_08119B3E:
	ldr r1, _08119BC0 @ =0x0000046B
	adds r0, r7, r1
	movs r6, #0
	movs r5, #1
	strb r5, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	movs r3, #0x21
	rsbs r3, r3, #0
	ldrh r0, [r2]
	ands r3, r0
	movs r4, #0
	strh r3, [r2]
	adds r1, #0x31
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0x98]
	cmp r0, #0
	beq _08119BD8
	ldr r2, _08119BC4 @ =0x00000594
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #7
	ldr r3, _08119BC8 @ =0x0000046D
	adds r0, r7, r3
	strb r5, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r1, #3
	subs r3, #0xeb
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _08119BCC @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _08119BD0 @ =0x0000046A
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r6, [r0]
	ldr r4, _08119BD4 @ =0x0000046C
	adds r0, r7, r4
	strb r5, [r0]
	bl _0811AA54
	.align 2, 0
_08119BBC: .4byte 0x0000046E
_08119BC0: .4byte 0x0000046B
_08119BC4: .4byte 0x00000594
_08119BC8: .4byte 0x0000046D
_08119BCC: .4byte 0x00000469
_08119BD0: .4byte 0x0000046A
_08119BD4: .4byte 0x0000046C
_08119BD8:
	movs r2, #0x80
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _08119BE8
	b _0811A308
_08119BE8:
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r6, _08119C50 @ =0x00000222
	adds r3, r7, r6
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _08119C54 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xac]
	str r4, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r5, #0
	blt _08119C4C
	cmp r1, #0
	blt _08119C4C
	ldr r0, _08119C58 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08119C4C
	ldr r0, _08119C5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08119C60
_08119C4C:
	movs r4, #0
	b _08119C6E
	.align 2, 0
_08119C50: .4byte 0x00000222
_08119C54: .4byte 0x03002BE0
_08119C58: .4byte 0x030046A8
_08119C5C: .4byte 0x030046AC
_08119C60:
	ldr r0, _08119C80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08119C6E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08119C84
	adds r0, #4
	b _08119C90
	.align 2, 0
_08119C80: .4byte 0x030046A4
_08119C84:
	ldr r0, _08119CA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08119C90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08119CA8
	cmp r2, #2
	beq _08119CAC
	b _08119CB0
	.align 2, 0
_08119CA4: .4byte 0x030046A4
_08119CA8:
	ldrb r0, [r6, #4]
	b _08119CAE
_08119CAC:
	ldrb r0, [r6]
_08119CAE:
	subs r1, r1, r0
_08119CB0:
	strh r1, [r6, #2]
	ldr r0, _08119CC4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08119CC8
	movs r0, #1
	b _08119CCA
	.align 2, 0
_08119CC4: .4byte 0x030047A4
_08119CC8:
	movs r0, #0
_08119CCA:
	cmp r0, #0
	beq _08119D08
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08119CEA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08119CE6
	adds r2, r0, #0
_08119CE6:
	cmp r2, #0
	bge _08119CF4
_08119CEA:
	ldr r3, _08119CF0 @ =0x000005C4
	adds r0, r7, r3
	b _0811A218
	.align 2, 0
_08119CF0: .4byte 0x000005C4
_08119CF4:
	ldr r1, _08119D04 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08119D50
	.align 2, 0
_08119D04: .4byte 0x03002BE0
_08119D08:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08119D34
	cmp r1, #0
	blt _08119D34
	ldr r0, _08119D38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08119D34
	ldr r0, _08119D3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08119D40
_08119D34:
	movs r5, #0
	b _08119D4E
	.align 2, 0
_08119D38: .4byte 0x030046A8
_08119D3C: .4byte 0x030046AC
_08119D40:
	ldr r0, _08119D88 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08119D4E:
	movs r2, #0
_08119D50:
	ldr r6, _08119D8C @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _08119D70
	ldr r1, _08119D90 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08119D70
	b _0811A158
_08119D70:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _08119D94
	movs r0, #0
	b _0811A22E
	.align 2, 0
_08119D88: .4byte 0x030046A4
_08119D8C: .4byte 0x00000256
_08119D90: .4byte 0x03002BE0
_08119D94:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r3, [sp, #0xac]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r1, #0x80
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08119E48
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _08119E34 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x10]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _08119E38 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x18]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov r8, r6
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r1, sb
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _08119E3C @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08119E40 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _08119E44 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0xa8]
	mov r6, r8
	str r6, [sp, #0xb0]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _0811A016
	.align 2, 0
_08119E34: .4byte 0x0000046D
_08119E38: .4byte 0x0000046B
_08119E3C: .4byte 0x00000469
_08119E40: .4byte 0x00000484
_08119E44: .4byte 0x0000046C
_08119E48:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _08119F08 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	strb r0, [r3]
	ldr r4, _08119F0C @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x20]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08119F10 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x28]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x30]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _08119F14 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _08119F18 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _08119F1C @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x34]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x34]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x34]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0xa8]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xb0]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, ip
	cmp r0, #0
	blt _08119F04
	cmp r1, #0
	blt _08119F04
	ldr r0, _08119F20 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08119F04
	ldr r0, _08119F24 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08119F28
_08119F04:
	movs r4, #0
	b _08119F38
	.align 2, 0
_08119F08: .4byte 0x0000046D
_08119F0C: .4byte 0x0000046B
_08119F10: .4byte 0x00000553
_08119F14: .4byte 0x00000469
_08119F18: .4byte 0x0000046A
_08119F1C: .4byte 0x00000484
_08119F20: .4byte 0x030046A8
_08119F24: .4byte 0x030046AC
_08119F28:
	ldr r0, _08119F48 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08119F38:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08119F4C
	adds r0, #4
	b _08119F58
	.align 2, 0
_08119F48: .4byte 0x030046A4
_08119F4C:
	ldr r0, _08119F6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08119F58:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08119F70
	cmp r2, #2
	beq _08119F76
	b _08119F7C
	.align 2, 0
_08119F6C: .4byte 0x030046A4
_08119F70:
	ldr r2, [sp, #0x34]
	ldrb r0, [r2, #4]
	b _08119F7A
_08119F76:
	ldr r3, [sp, #0x34]
	ldrb r0, [r3]
_08119F7A:
	subs r1, r1, r0
_08119F7C:
	ldr r4, [sp, #0x34]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08119FA8
	cmp r1, #0
	blt _08119FA8
	ldr r0, _08119FAC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08119FA8
	ldr r0, _08119FB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08119FB4
_08119FA8:
	movs r4, #0
	b _08119FC2
	.align 2, 0
_08119FAC: .4byte 0x030046A8
_08119FB0: .4byte 0x030046AC
_08119FB4:
	ldr r0, _08119FD8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08119FC2:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08119FDC
	adds r0, #4
	b _08119FE8
	.align 2, 0
_08119FD8: .4byte 0x030046A4
_08119FDC:
	ldr r0, _08119FFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08119FE8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811A000
	cmp r3, #2
	beq _0811A004
	b _0811A008
	.align 2, 0
_08119FFC: .4byte 0x030046A4
_0811A000:
	ldrb r0, [r5, #4]
	b _0811A006
_0811A004:
	ldrb r0, [r5]
_0811A006:
	subs r2, r2, r0
_0811A008:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0811A016:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x38]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0811A040 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _0811A120
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0811A044
	movs r0, #1
	b _0811A046
	.align 2, 0
_0811A040: .4byte 0x00000482
_0811A044:
	movs r0, #0
_0811A046:
	ldr r1, _0811A130 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _0811A120
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _0811A134 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0811A138 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0811A13C @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r0, _0811A140 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0811A144 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	ldr r2, _0811A148 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	ldr r1, _0811A14C @ =0x030046B8
	adds r2, r4, #0
_0811A08E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0811A150 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0811A154 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0811A0B2
	adds r3, #1
	cmp r3, #3
	ble _0811A08E
	adds r0, r4, #0
_0811A0B2:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb0]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xa8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	add r0, sp, #0x38
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	ldr r0, [sp, #0xb0]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa0]
	strb r0, [r4]
_0811A120:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _0811A22E
	.align 2, 0
_0811A130: .4byte 0x00000482
_0811A134: .4byte 0x0000054F
_0811A138: .4byte 0x0000054C
_0811A13C: .4byte 0x0000054E
_0811A140: .4byte 0x00000541
_0811A144: .4byte 0x000005BC
_0811A148: .4byte 0x00000542
_0811A14C: .4byte 0x030046B8
_0811A150: .4byte 0x000003FF
_0811A154: .4byte 0x0203B400
_0811A158:
	mov sb, sp
	ldr r6, _0811A194 @ =0x030046A4
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
	beq _0811A198
	adds r0, #4
	b _0811A1A2
	.align 2, 0
_0811A194: .4byte 0x030046A4
_0811A198:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811A1A2:
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
	ldr r6, _0811A1DC @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811A1E4
	ldr r0, _0811A1E0 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811A20E
	.align 2, 0
_0811A1DC: .4byte 0x000004A4
_0811A1E0: .4byte 0xFFFFFDFF
_0811A1E4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811A204
	cmp r0, #2
	beq _0811A200
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811A200:
	movs r0, #1
	b _0811A210
_0811A204:
	ldr r0, _0811A224 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811A20E:
	movs r0, #0
_0811A210:
	cmp r0, #0
	bne _0811A22C
	ldr r4, _0811A228 @ =0x000005C4
	adds r0, r7, r4
_0811A218:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811A22E
	.align 2, 0
_0811A224: .4byte 0xFFFFFDFF
_0811A228: .4byte 0x000005C4
_0811A22C:
	movs r0, #1
_0811A22E:
	cmp r0, #0
	bne _0811A29E
	ldr r5, _0811A264 @ =0x000004A4
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
	bne _0811A26C
	ldr r0, _0811A268 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811A296
	.align 2, 0
_0811A264: .4byte 0x000004A4
_0811A268: .4byte 0xFFFFFDFF
_0811A26C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811A28C
	cmp r0, #2
	beq _0811A288
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811A288:
	movs r0, #1
	b _0811A298
_0811A28C:
	ldr r0, _0811A2F4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811A296:
	movs r0, #0
_0811A298:
	cmp r0, #0
	bne _0811A29E
	b _0811A9BC
_0811A29E:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _0811A2F8 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0811A2FC @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811A300 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0811A304 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _0811AA54
	.align 2, 0
_0811A2F4: .4byte 0xFFFFFDFF
_0811A2F8: .4byte 0x0000046D
_0811A2FC: .4byte 0x0000046B
_0811A300: .4byte 0x0000046A
_0811A304: .4byte 0x00000484
_0811A308:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _0811A36C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x90
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	strh r3, [r0, #6]
	adds r3, r7, r1
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r5, #0
	blt _0811A366
	cmp r1, #0
	blt _0811A366
	ldr r0, _0811A370 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811A366
	ldr r0, _0811A374 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811A378
_0811A366:
	movs r4, #0
	b _0811A386
	.align 2, 0
_0811A36C: .4byte 0x03002BE0
_0811A370: .4byte 0x030046A8
_0811A374: .4byte 0x030046AC
_0811A378:
	ldr r0, _0811A398 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811A386:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811A39C
	adds r0, #4
	b _0811A3A8
	.align 2, 0
_0811A398: .4byte 0x030046A4
_0811A39C:
	ldr r0, _0811A3BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811A3A8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811A3C0
	cmp r2, #2
	beq _0811A3C4
	b _0811A3C8
	.align 2, 0
_0811A3BC: .4byte 0x030046A4
_0811A3C0:
	ldrb r0, [r6, #4]
	b _0811A3C6
_0811A3C4:
	ldrb r0, [r6]
_0811A3C6:
	subs r1, r1, r0
_0811A3C8:
	strh r1, [r6, #2]
	ldr r0, _0811A3DC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811A3E0
	movs r0, #1
	b _0811A3E2
	.align 2, 0
_0811A3DC: .4byte 0x030047A4
_0811A3E0:
	movs r0, #0
_0811A3E2:
	cmp r0, #0
	beq _0811A418
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _0811A3F4
	b _0811A934
_0811A3F4:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811A400
	adds r2, r0, #0
_0811A400:
	cmp r2, #0
	bge _0811A406
	b _0811A934
_0811A406:
	ldr r1, _0811A414 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811A460
	.align 2, 0
_0811A414: .4byte 0x03002BE0
_0811A418:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811A444
	cmp r1, #0
	blt _0811A444
	ldr r0, _0811A448 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811A444
	ldr r0, _0811A44C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811A450
_0811A444:
	movs r5, #0
	b _0811A45E
	.align 2, 0
_0811A448: .4byte 0x030046A8
_0811A44C: .4byte 0x030046AC
_0811A450:
	ldr r0, _0811A498 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811A45E:
	movs r2, #0
_0811A460:
	ldr r6, _0811A49C @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811A480
	ldr r1, _0811A4A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811A480
	b _0811A874
_0811A480:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x3c]
	cmp r0, #0
	beq _0811A4A4
	movs r0, #0
	b _0811A94E
	.align 2, 0
_0811A498: .4byte 0x030046A4
_0811A49C: .4byte 0x00000256
_0811A4A0: .4byte 0x03002BE0
_0811A4A4:
	ldr r3, _0811A548 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xac]
	cmp r6, #0
	beq _0811A560
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _0811A54C @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x40]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _0811A550 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x44]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x48]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r1, sp
	ldrh r1, [r1, #0x3c]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _0811A554 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0811A558 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x3c]
	str r6, [r1]
	ldr r6, _0811A55C @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0xa8]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb0]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _0811A732
	.align 2, 0
_0811A548: .4byte 0x00000222
_0811A54C: .4byte 0x0000046D
_0811A550: .4byte 0x0000046B
_0811A554: .4byte 0x00000469
_0811A558: .4byte 0x00000484
_0811A55C: .4byte 0x0000046C
_0811A560:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0811A624 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x50]
	strb r0, [r2]
	ldr r3, _0811A628 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x54]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0811A62C @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x58]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x60]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x64]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0811A630 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0811A634 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0811A638 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x68]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x68]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x68]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0xa8]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xb0]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, sl
	cmp r0, #0
	blt _0811A61E
	cmp r1, #0
	blt _0811A61E
	ldr r0, _0811A63C @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _0811A61E
	ldr r0, _0811A640 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811A644
_0811A61E:
	movs r4, #0
	b _0811A654
	.align 2, 0
_0811A624: .4byte 0x0000046D
_0811A628: .4byte 0x0000046B
_0811A62C: .4byte 0x00000553
_0811A630: .4byte 0x00000469
_0811A634: .4byte 0x00000484
_0811A638: .4byte 0x0000046C
_0811A63C: .4byte 0x030046A8
_0811A640: .4byte 0x030046AC
_0811A644:
	ldr r0, _0811A664 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_0811A654:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811A668
	adds r0, #4
	b _0811A674
	.align 2, 0
_0811A664: .4byte 0x030046A4
_0811A668:
	ldr r0, _0811A688 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811A674:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811A68C
	cmp r2, #2
	beq _0811A692
	b _0811A698
	.align 2, 0
_0811A688: .4byte 0x030046A4
_0811A68C:
	ldr r2, [sp, #0x68]
	ldrb r0, [r2, #4]
	b _0811A696
_0811A692:
	ldr r3, [sp, #0x68]
	ldrb r0, [r3]
_0811A696:
	subs r1, r1, r0
_0811A698:
	ldr r4, [sp, #0x68]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811A6C4
	cmp r1, #0
	blt _0811A6C4
	ldr r0, _0811A6C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811A6C4
	ldr r0, _0811A6CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811A6D0
_0811A6C4:
	movs r4, #0
	b _0811A6DE
	.align 2, 0
_0811A6C8: .4byte 0x030046A8
_0811A6CC: .4byte 0x030046AC
_0811A6D0:
	ldr r0, _0811A6F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811A6DE:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811A6F8
	adds r0, #4
	b _0811A704
	.align 2, 0
_0811A6F4: .4byte 0x030046A4
_0811A6F8:
	ldr r0, _0811A718 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811A704:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811A71C
	cmp r3, #2
	beq _0811A720
	b _0811A724
	.align 2, 0
_0811A718: .4byte 0x030046A4
_0811A71C:
	ldrb r0, [r5, #4]
	b _0811A722
_0811A720:
	ldrb r0, [r5]
_0811A722:
	subs r2, r2, r0
_0811A724:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0811A732:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0811A75C @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _0811A83C
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0811A760
	movs r0, #1
	b _0811A762
	.align 2, 0
_0811A75C: .4byte 0x00000482
_0811A760:
	movs r0, #0
_0811A762:
	ldr r1, _0811A84C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _0811A83C
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _0811A850 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0811A854 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0811A858 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r0, _0811A85C @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0811A860 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	ldr r2, _0811A864 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	ldr r1, _0811A868 @ =0x030046B8
	adds r2, r4, #0
_0811A7AA:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0811A86C @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0811A870 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0811A7CE
	adds r3, #1
	cmp r3, #3
	ble _0811A7AA
	adds r0, r4, #0
_0811A7CE:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb0]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xa8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	add r0, sp, #0x6c
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	ldr r0, [sp, #0xb0]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa0]
	strb r0, [r4]
_0811A83C:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _0811A94E
	.align 2, 0
_0811A84C: .4byte 0x00000482
_0811A850: .4byte 0x0000054F
_0811A854: .4byte 0x0000054C
_0811A858: .4byte 0x0000054E
_0811A85C: .4byte 0x00000541
_0811A860: .4byte 0x000005BC
_0811A864: .4byte 0x00000542
_0811A868: .4byte 0x030046B8
_0811A86C: .4byte 0x000003FF
_0811A870: .4byte 0x0203B400
_0811A874:
	add r6, sp, #8
	ldr r0, _0811A8B4 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _0811A8B8
	adds r0, #4
	b _0811A8C4
	.align 2, 0
_0811A8B4: .4byte 0x030046A4
_0811A8B8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811A8C4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0811A8FC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811A904
	ldr r0, _0811A900 @ =0xFFFFFDFF
	ldr r6, [sp, #0x98]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0811A92E
	.align 2, 0
_0811A8FC: .4byte 0x000004A4
_0811A900: .4byte 0xFFFFFDFF
_0811A904:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811A924
	cmp r0, #2
	beq _0811A920
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811A920:
	movs r0, #1
	b _0811A930
_0811A924:
	ldr r0, _0811A944 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0811A92E:
	movs r0, #0
_0811A930:
	cmp r0, #0
	bne _0811A94C
_0811A934:
	ldr r3, _0811A948 @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811A94E
	.align 2, 0
_0811A944: .4byte 0xFFFFFDFF
_0811A948: .4byte 0x000005C4
_0811A94C:
	movs r0, #1
_0811A94E:
	cmp r0, #0
	bne _0811A9D4
	ldr r4, _0811A984 @ =0x000004A4
	adds r0, r7, r4
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
	bne _0811A98C
	ldr r0, _0811A988 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811A9B6
	.align 2, 0
_0811A984: .4byte 0x000004A4
_0811A988: .4byte 0xFFFFFDFF
_0811A98C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811A9AC
	cmp r0, #2
	beq _0811A9A8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811A9A8:
	movs r0, #1
	b _0811A9B8
_0811A9AC:
	ldr r0, _0811A9CC @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811A9B6:
	movs r0, #0
_0811A9B8:
	cmp r0, #0
	bne _0811A9D4
_0811A9BC:
	ldr r4, _0811A9D0 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0811AA54
	.align 2, 0
_0811A9CC: .4byte 0xFFFFFDFF
_0811A9D0: .4byte 0x000005C4
_0811A9D4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0811AA30 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0811AA34 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
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
	ldr r6, _0811AA38 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811AA3C @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0811AA40 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
	b _0811AA54
	.align 2, 0
_0811AA30: .4byte 0x0000046D
_0811AA34: .4byte 0x0000046B
_0811AA38: .4byte 0x00000469
_0811AA3C: .4byte 0x0000046A
_0811AA40: .4byte 0x00000484

_0811AA44:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0811AA54:
	add sp, #0xbc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
