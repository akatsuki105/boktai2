	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _08079F34
	b _0807A24C
_08079F34:
	cmp r0, #2
	bhi _08079F3E
	cmp r0, #1
	beq _08079F46
	b _0807A268
_08079F3E:
	cmp r0, #4
	bne _08079F44
	b _0807A200
_08079F44:
	b _0807A268
_08079F46:
	adds r0, r5, #0
	bl FUN_080784fc
	adds r0, r5, #0
	bl FUN_080788d0
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08066d7c
	ldr r1, _08079F88 @ =0x085ABEDC
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08079F8C
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
	b _08079F92
	.align 2, 0
_08079F88: .4byte 0x085ABEDC
_08079F8C:
	adds r0, r5, #0
	bl FUN_08066408
_08079F92:
	adds r0, r5, #0
	bl FUN_08078bc0
	ldr r3, _0807A064 @ =0x000003CE
	adds r0, r5, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _08079FAA
	adds r0, r5, #0
	bl FUN_08066df8
_08079FAA:
	adds r0, r5, #0
	bl FUN_08065b7c
	adds r0, r5, #0
	bl FUN_0806623c
	ldr r1, _0807A068 @ =0x00000446
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08079FCE
	ldr r2, _0807A06C @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _08079FCE
	movs r1, #1
_08079FCE:
	cmp r1, #0
	beq _08079FD4
	b _0807A268
_08079FD4:
	movs r4, #0
	movs r3, #0xe5
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	bl FUN_08065b44
	cmp r0, #0
	bne _0807A012
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _0807A012
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0807A012
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
_0807A012:
	cmp r4, #0
	bne _0807A018
	b _0807A1F4
_0807A018:
	ldr r0, _0807A070 @ =0x000003BE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	beq _0807A02C
	b _0807A268
_0807A02C:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0807A074 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _0807A078
	asrs r2, r0, #0xc
	b _0807A07E
	.align 2, 0
_0807A064: .4byte 0x000003CE
_0807A068: .4byte 0x00000446
_0807A06C: .4byte 0x00000442
_0807A070: .4byte 0x000003BE
_0807A074: .4byte 0x085B0A08
_0807A078:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0807A07E:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807A0A8 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _0807A0AC
	asrs r2, r0, #0xc
	b _0807A0B2
	.align 2, 0
_0807A0A8: .4byte 0xFFFF0000
_0807A0AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0807A0B2:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807A0F4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0807A0EE
	cmp r1, #0
	blt _0807A0EE
	ldr r0, _0807A0F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0807A0EE
	ldr r0, _0807A0FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0807A100
_0807A0EE:
	movs r4, #0
	b _0807A10E
	.align 2, 0
_0807A0F4: .4byte 0xFFFF0000
_0807A0F8: .4byte 0x030046A8
_0807A0FC: .4byte 0x030046AC
_0807A100:
	ldr r0, _0807A120 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0807A10E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0807A124
	adds r0, #4
	b _0807A130
	.align 2, 0
_0807A120: .4byte 0x030046A4
_0807A124:
	ldr r0, _0807A144 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0807A130:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0807A148
	cmp r2, #2
	beq _0807A14C
	b _0807A150
	.align 2, 0
_0807A144: .4byte 0x030046A4
_0807A148:
	ldrb r0, [r6, #4]
	b _0807A14E
_0807A14C:
	ldrb r0, [r6]
_0807A14E:
	subs r1, r1, r0
_0807A150:
	movs r3, #0x2e
	ldrsh r0, [r5, r3]
	adds r0, #0xc8
	cmp r1, r0
	bhs _0807A15C
	b _0807A268
_0807A15C:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0807A184
	cmp r1, #0
	blt _0807A184
	ldr r0, _0807A188 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0807A184
	ldr r0, _0807A18C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0807A190
_0807A184:
	movs r4, #0
	b _0807A19E
	.align 2, 0
_0807A188: .4byte 0x030046A8
_0807A18C: .4byte 0x030046AC
_0807A190:
	ldr r0, _0807A1B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0807A19E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0807A1B4
	adds r0, #4
	b _0807A1C0
	.align 2, 0
_0807A1B0: .4byte 0x030046A4
_0807A1B4:
	ldr r0, _0807A1EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0807A1C0:
	ldrh r2, [r0, #2]
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	bne _0807A268
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ldr r3, _0807A1F0 @ =0x000003BD
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0xd4
	adds r0, r5, r4
	strb r2, [r0]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0
	bl FUN_08060b84
	b _0807A268
	.align 2, 0
_0807A1EC: .4byte 0x030046A4
_0807A1F0: .4byte 0x000003BD
_0807A1F4:
	ldr r1, _0807A1FC @ =0x000003BE
	adds r0, r5, r1
	strh r4, [r0]
	b _0807A268
	.align 2, 0
_0807A1FC: .4byte 0x000003BE
_0807A200:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r1]
	subs r0, #0x1c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0807A21E
	ldrb r4, [r1]
	b _0807A22C
_0807A21E:
	ldr r3, _0807A244 @ =0x000003D2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r4, #0x1a
	cmp r0, #0
	beq _0807A22C
	movs r4, #0x1b
_0807A22C:
	ldr r0, _0807A248 @ =0x085ABEDC
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08078bc0
	b _0807A268
	.align 2, 0
_0807A244: .4byte 0x000003D2
_0807A248: .4byte 0x085ABEDC
_0807A24C:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08078bc0
_0807A268:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
