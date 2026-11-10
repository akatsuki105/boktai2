	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	adds r7, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r2, _08153DCC @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08153DD0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08153DD2
	.align 2, 0
_08153DCC: .4byte 0x0000046D
_08153DD0:
	movs r0, #0
_08153DD2:
	cmp r0, #0
	beq _08153DF4
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, _08153E54 @ =0xFFFFFEFE
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r5, _08153E58 @ =0x0000046E
	adds r0, r7, r5
	strb r1, [r0]
_08153DF4:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #9
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r5, r2, #0
	cmp r6, #0x11
	bgt _08153E34
	ldrh r3, [r4, #8]
	cmp r3, #0
	bne _08153E34
	ldrh r1, [r4, #0xe]
	ldrb r2, [r4, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _08153E34
	cmp r2, #1
	beq _08153E34
	strh r3, [r4, #0xe]
_08153E34:
	movs r6, #0x83
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x85
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _08153E5C
	asrs r0, r0, #2
	b _08153E62
	.align 2, 0
_08153E54: .4byte 0xFFFFFEFE
_08153E58: .4byte 0x0000046E
_08153E5C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08153E62:
	adds r3, r0, #0
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r6, #8
	adds r1, r7, r6
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _08153E80
	asrs r0, r0, #2
	b _08153E86
_08153E80:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08153E86:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _08153E90
	movs r3, #0xc8
	b _08153E9A
_08153E90:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08153E9A
	adds r3, r0, #0
_08153E9A:
	cmp r2, #0xc8
	ble _08153EA2
	movs r2, #0xc8
	b _08153EAC
_08153EA2:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08153EAC
	adds r2, r0, #0
_08153EAC:
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
	bne _08153ED0
	cmp r2, #0
	bne _08153ED0
	movs r0, #1
	b _08153ED2
_08153ED0:
	movs r0, #0
_08153ED2:
	cmp r0, #0
	bne _08153EDA
	bl _0815475C
_08153EDA:
	ldr r1, _08153F2C @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153EE8
	bl _0815475C
_08153EE8:
	ldr r2, _08153F30 @ =0x0000046B
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	subs r0, #0x22
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r4, _08153F34 @ =0x0000049C
	adds r0, r7, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0x40]
	cmp r0, #0
	beq _08153F38
	movs r0, #2
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _0815475C
	.align 2, 0
_08153F2C: .4byte 0x0000046E
_08153F30: .4byte 0x0000046B
_08153F34: .4byte 0x0000049C
_08153F38:
	movs r0, #0xe0
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08153F4C
	movs r0, #1
	b _08153F4E
_08153F4C:
	movs r0, #0
_08153F4E:
	cmp r0, #0
	beq _08153FB8
	ldr r3, _08153FA4 @ =Cockatrice_StateFlee
	movs r1, #0x34
	ldr r6, _08153FA8 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _08153FAC @ =0x0000046B
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
	movs r3, #0x13
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08153FB0 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08153FB4 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	bl _0815475C
	.align 2, 0
_08153FA4: .4byte Cockatrice_StateFlee
_08153FA8: .4byte 0x0000046D
_08153FAC: .4byte 0x0000046B
_08153FB0: .4byte 0x0000046A
_08153FB4: .4byte 0x00000484
_08153FB8:
	movs r1, #0x80
	ldr r6, [sp, #0x40]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _08153FCA
	b _0815470C
_08153FCA:
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _08154020 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
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
	str r3, [sp, #0x80]
	str r2, [sp, #0x68]
	cmp r4, #0
	blt _0815401A
	cmp r1, #0
	blt _0815401A
	ldr r0, _08154024 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0815401A
	ldr r0, _08154028 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815402C
_0815401A:
	movs r4, #0
	b _0815403A
	.align 2, 0
_08154020: .4byte 0x03002BE0
_08154024: .4byte 0x030046A8
_08154028: .4byte 0x030046AC
_0815402C:
	ldr r0, _0815404C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0815403A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08154050
	adds r0, #4
	b _0815405C
	.align 2, 0
_0815404C: .4byte 0x030046A4
_08154050:
	ldr r0, _08154070 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815405C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08154074
	cmp r2, #2
	beq _08154078
	b _0815407C
	.align 2, 0
_08154070: .4byte 0x030046A4
_08154074:
	ldrb r0, [r5, #4]
	b _0815407A
_08154078:
	ldrb r0, [r5]
_0815407A:
	subs r1, r1, r0
_0815407C:
	strh r1, [r5, #2]
	ldr r0, _08154090 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08154094
	movs r0, #1
	b _08154096
	.align 2, 0
_08154090: .4byte 0x030047A4
_08154094:
	movs r0, #0
_08154096:
	cmp r0, #0
	beq _081540D4
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081540B6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081540B2
	adds r2, r0, #0
_081540B2:
	cmp r2, #0
	bge _081540C0
_081540B6:
	ldr r3, _081540BC @ =0x000005C4
	adds r0, r7, r3
	b _081545F8
	.align 2, 0
_081540BC: .4byte 0x000005C4
_081540C0:
	ldr r1, _081540D0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0815411C
	.align 2, 0
_081540D0: .4byte 0x03002BE0
_081540D4:
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
	blt _08154100
	cmp r1, #0
	blt _08154100
	ldr r0, _08154104 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08154100
	ldr r0, _08154108 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815410C
_08154100:
	movs r5, #0
	b _0815411A
	.align 2, 0
_08154104: .4byte 0x030046A8
_08154108: .4byte 0x030046AC
_0815410C:
	ldr r0, _08154154 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815411A:
	movs r2, #0
_0815411C:
	ldr r6, _08154158 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0815413C
	ldr r1, _0815415C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0815413C
	b _08154538
_0815413C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x40]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _08154160
	movs r0, #0
	b _0815460E
	.align 2, 0
_08154154: .4byte 0x030046A4
_08154158: .4byte 0x00000256
_0815415C: .4byte 0x03002BE0
_08154160:
	ldr r3, _08154204 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x40]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x58]
	cmp r6, #0
	beq _0815421C
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _08154208 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #8]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _0815420C @ =0x0000046B
	adds r3, r3, r7
	mov r8, r3
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0xc]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
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
	ldr r6, _08154210 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08154214 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _08154218 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #8]
	str r6, [sp, #0x74]
	mov r6, r8
	str r6, [sp, #0x6c]
	ldr r6, [sp, #0xc]
	str r6, [sp, #0x48]
	mov r6, sl
	str r6, [sp, #0x4c]
	str r5, [sp, #0x50]
	str r4, [sp, #0x5c]
	str r3, [sp, #0x60]
	str r2, [sp, #0x64]
	str r1, [sp, #0x7c]
	str r0, [sp, #0x70]
	b _081543EE
	.align 2, 0
_08154204: .4byte 0x00000222
_08154208: .4byte 0x0000046D
_0815420C: .4byte 0x0000046B
_08154210: .4byte 0x00000469
_08154214: .4byte 0x00000484
_08154218: .4byte 0x0000046C
_0815421C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081542E0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	ldr r3, _081542E4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081542E8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x18]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x20]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x24]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081542EC @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081542F0 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081542F4 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x80]
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x68]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x28]
	strh r1, [r6]
	ldr r6, [sp, #0x68]
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
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x6c]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x48]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x4c]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x50]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x5c]
	str r5, [sp, #0x60]
	str r4, [sp, #0x64]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x70]
	mov r0, ip
	cmp r0, #0
	blt _081542DA
	cmp r1, #0
	blt _081542DA
	ldr r0, _081542F8 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081542DA
	ldr r0, _081542FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08154300
_081542DA:
	movs r4, #0
	b _08154310
	.align 2, 0
_081542E0: .4byte 0x0000046D
_081542E4: .4byte 0x0000046B
_081542E8: .4byte 0x00000553
_081542EC: .4byte 0x00000469
_081542F0: .4byte 0x00000484
_081542F4: .4byte 0x0000046C
_081542F8: .4byte 0x030046A8
_081542FC: .4byte 0x030046AC
_08154300:
	ldr r0, _08154320 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08154310:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08154324
	adds r0, #4
	b _08154330
	.align 2, 0
_08154320: .4byte 0x030046A4
_08154324:
	ldr r0, _08154344 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08154330:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08154348
	cmp r2, #2
	beq _0815434E
	b _08154354
	.align 2, 0
_08154344: .4byte 0x030046A4
_08154348:
	ldr r2, [sp, #0x28]
	ldrb r0, [r2, #4]
	b _08154352
_0815434E:
	ldr r3, [sp, #0x28]
	ldrb r0, [r3]
_08154352:
	subs r1, r1, r0
_08154354:
	ldr r4, [sp, #0x28]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x80]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08154380
	cmp r1, #0
	blt _08154380
	ldr r0, _08154384 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08154380
	ldr r0, _08154388 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815438C
_08154380:
	movs r4, #0
	b _0815439A
	.align 2, 0
_08154384: .4byte 0x030046A8
_08154388: .4byte 0x030046AC
_0815438C:
	ldr r0, _081543B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815439A:
	ldr r6, [sp, #0x80]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081543B4
	adds r0, #4
	b _081543C0
	.align 2, 0
_081543B0: .4byte 0x030046A4
_081543B4:
	ldr r0, _081543D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081543C0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081543D8
	cmp r3, #2
	beq _081543DC
	b _081543E0
	.align 2, 0
_081543D4: .4byte 0x030046A4
_081543D8:
	ldrb r0, [r5, #4]
	b _081543DE
_081543DC:
	ldrb r0, [r5]
_081543DE:
	subs r2, r2, r0
_081543E0:
	ldr r1, [sp, #0x80]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x80]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081543EE:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x2c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x40]
	ldrh r0, [r4]
	ands r0, r1
	mov sb, r3
	ldr r5, _08154418 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x78]
	cmp r0, #0
	bne _081544FC
	movs r1, #4
	ldr r6, [sp, #0x58]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0815441C
	movs r0, #1
	b _0815441E
	.align 2, 0
_08154418: .4byte 0x00000482
_0815441C:
	movs r0, #0
_0815441E:
	ldr r1, _0815450C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x78]
	cmp r0, #0
	bne _081544FC
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r2, r7
	mov r8, r2
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sl, r4
	ldr r5, _08154510 @ =0x0000054F
	adds r5, r5, r7
	mov ip, r5
	ldr r6, _08154514 @ =0x0000054C
	adds r6, r7, r6
	str r6, [sp, #0x38]
	ldr r0, _08154518 @ =0x0000054D
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _0815451C @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _08154520 @ =0x00000541
	adds r2, r7, r2
	str r2, [sp, #0x30]
	ldr r4, _08154524 @ =0x000005BC
	adds r4, r7, r4
	str r4, [sp, #0x54]
	ldr r5, _08154528 @ =0x00000542
	adds r5, r7, r5
	str r5, [sp, #0x34]
	ldr r6, _0815452C @ =0x0203B400
	ldr r1, _08154530 @ =0x030046B8
	ldr r5, _08154534 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_0815446E:
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
	bne _0815448C
	adds r3, #1
	cmp r3, #3
	ble _0815446E
	mov r0, sb
_0815448C:
	movs r3, #0
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x4c]
	ldr r0, [r1]
	mov r2, sl
	str r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	mov r5, ip
	strb r0, [r5]
	ldr r6, [sp, #0x5c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x38]
	strb r0, [r1]
	ldr r2, [sp, #0x60]
	ldrb r0, [r2]
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r5, [sp, #0x64]
	ldrb r0, [r5]
	ldr r6, [sp, #0x44]
	strb r0, [r6]
	add r0, sp, #0x2c
	ldrb r1, [r0]
	ldr r0, [sp, #0x30]
	strb r1, [r0]
	ldr r1, [sp, #0x54]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x74]
	strb r1, [r4]
	ldr r5, [sp, #0x6c]
	strb r3, [r5]
	ldr r6, [sp, #0x48]
	strb r0, [r6]
	ldr r0, [sp, #0x4c]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x50]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x5c]
	strb r0, [r5]
	ldr r6, [sp, #0x60]
	strb r1, [r6]
	ldr r0, [sp, #0x64]
	strb r2, [r0]
	ldr r2, [sp, #0x7c]
	str r3, [r2]
	ldr r3, [sp, #0x70]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x34]
	strb r0, [r4]
_081544FC:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x78]
	strh r0, [r5]
	movs r0, #0
	b _0815460E
	.align 2, 0
_0815450C: .4byte 0x00000482
_08154510: .4byte 0x0000054F
_08154514: .4byte 0x0000054C
_08154518: .4byte 0x0000054D
_0815451C: .4byte 0x0000054E
_08154520: .4byte 0x00000541
_08154524: .4byte 0x000005BC
_08154528: .4byte 0x00000542
_0815452C: .4byte 0x0203B400
_08154530: .4byte 0x030046B8
_08154534: .4byte 0x000003FF
_08154538:
	mov sb, sp
	ldr r6, _08154574 @ =0x030046A4
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
	beq _08154578
	adds r0, #4
	b _08154582
	.align 2, 0
_08154574: .4byte 0x030046A4
_08154578:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08154582:
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
	ldr r6, _081545BC @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081545C4
	ldr r0, _081545C0 @ =0xFFFFFDFF
	ldr r2, [sp, #0x40]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081545EE
	.align 2, 0
_081545BC: .4byte 0x000004A4
_081545C0: .4byte 0xFFFFFDFF
_081545C4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081545E4
	cmp r0, #2
	beq _081545E0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081545E0:
	movs r0, #1
	b _081545F0
_081545E4:
	ldr r0, _08154604 @ =0xFFFFFDFF
	ldr r3, [sp, #0x40]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081545EE:
	movs r0, #0
_081545F0:
	cmp r0, #0
	bne _0815460C
	ldr r4, _08154608 @ =0x000005C4
	adds r0, r7, r4
_081545F8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0815460E
	.align 2, 0
_08154604: .4byte 0xFFFFFDFF
_08154608: .4byte 0x000005C4
_0815460C:
	movs r0, #1
_0815460E:
	cmp r0, #0
	bne _08154694
	ldr r5, _08154644 @ =0x000004A4
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
	bne _0815464C
	ldr r0, _08154648 @ =0xFFFFFDFF
	ldr r2, [sp, #0x40]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08154676
	.align 2, 0
_08154644: .4byte 0x000004A4
_08154648: .4byte 0xFFFFFDFF
_0815464C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815466C
	cmp r0, #2
	beq _08154668
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08154668:
	movs r0, #1
	b _08154678
_0815466C:
	ldr r0, _0815468C @ =0xFFFFFDFF
	ldr r3, [sp, #0x40]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08154676:
	movs r0, #0
_08154678:
	cmp r0, #0
	bne _08154694
	ldr r4, _08154690 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0815475C
	.align 2, 0
_0815468C: .4byte 0xFFFFFDFF
_08154690: .4byte 0x000005C4
_08154694:
	movs r0, #4
	ldr r5, _081546F4 @ =0x00000222
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r4, _081546F8 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081546FC @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #0xc
	subs r6, #0xeb
	adds r0, r7, r6
	strb r3, [r0]
	ldr r2, _08154700 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _08154704 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _08154708 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _0815475C
	.align 2, 0
_081546F4: .4byte 0x00000222
_081546F8: .4byte 0x0000046D
_081546FC: .4byte 0x0000046B
_08154700: .4byte 0x00000469
_08154704: .4byte 0x0000046A
_08154708: .4byte 0x0000046C
_0815470C:
	adds r0, r7, #0
	bl Cockatrice_StartFlee
	ldr r2, _0815476C @ =Cockatrice_StateFlee
	movs r1, #0x34
	ldr r3, _08154770 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _08154774 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	ldr r6, _08154778 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #0x13
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0815477C @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _08154780 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _08154784 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
_0815475C:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815476C: .4byte Cockatrice_StateFlee
_08154770: .4byte 0x0000046D
_08154774: .4byte 0x0000046B
_08154778: .4byte 0x00000553
_0815477C: .4byte 0x0000046A
_08154780: .4byte 0x00000484
_08154784: .4byte 0x0000046C
