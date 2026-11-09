	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	mov sb, r1
	adds r7, r2, #0
	adds r6, r7, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	adds r0, r7, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817F022
	bl _0817FA86
_0817F022:
	adds r0, r7, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0817F032
	b _0817F6D0
_0817F032:
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0817F05C
	ldr r3, _0817F058 @ =0x0000048C
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817F04A
	b _0817F6D0
_0817F04A:
	movs r0, #0
	mov r4, sb
	strh r1, [r4, #0x3e]
	mov r1, sb
	adds r1, #0x43
	strb r0, [r1]
	b _0817F6D0
	.align 2, 0
_0817F058: .4byte 0x0000048C
_0817F05C:
	adds r0, r7, #0
	adds r0, #0xd8
	movs r5, #4
	mov sl, r5
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0817F06E
	b _0817F6D0
_0817F06E:
	movs r5, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r5
	cmp r0, #0
	beq _0817F07E
	b _0817F398
_0817F07E:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov ip, r1
	cmp r0, #0
	bne _0817F090
	b _0817F6D0
_0817F090:
	ldr r1, _0817F120 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r7, r0
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817F0A2
	b _0817F6D0
_0817F0A2:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0817F0B0
	b _0817F6D0
_0817F0B0:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _0817F0C8
	b _0817F218
_0817F0C8:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, sb
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0817F130
	ands r3, r1
	cmp r3, #0
	beq _0817F130
	mov r0, sb
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0817F0F0
	rsbs r1, r1, #0
_0817F0F0:
	cmp r1, #0x20
	bgt _0817F130
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r2, _0817F124 @ =0x000004BE
	adds r1, r7, r2
	strh r0, [r1]
	ldr r3, _0817F128 @ =0x0000048C
	adds r0, r7, r3
	strb r5, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r5, _0817F12C @ =0x0000044E
	adds r1, r7, r5
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0817F6D0
	.align 2, 0
_0817F120: .4byte 0x0000A007
_0817F124: .4byte 0x000004BE
_0817F128: .4byte 0x0000048C
_0817F12C: .4byte 0x0000044E
_0817F130:
	movs r1, #0
	mov r0, sb
	strh r1, [r0, #0x3e]
	ldr r2, _0817F15C @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0817F164
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0817F160 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0817F1D2
	.align 2, 0
_0817F15C: .4byte 0x0000048A
_0817F160: .4byte 0x03002BE0
_0817F164:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0817F180
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0817F17C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0817F1D2
	.align 2, 0
_0817F17C: .4byte 0x03002BE0
_0817F180:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0817F19C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0817F198 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0817F1D2
	.align 2, 0
_0817F198: .4byte 0x03002BE0
_0817F19C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0817F1B8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0817F1B4 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0817F1D2
	.align 2, 0
_0817F1B4: .4byte 0x03002BE0
_0817F1B8:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0817F1CA
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0817F1D2
_0817F1CA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0817F1D4
_0817F1D2:
	movs r3, #1
_0817F1D4:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	mov r5, ip
	str r5, [r0]
	ldr r2, _0817F208 @ =0x0000049C
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	bne _0817F1F6
	b _0817F358
_0817F1F6:
	movs r1, #2
	ldr r3, _0817F20C @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F210
	movs r0, #1
	b _0817F212
	.align 2, 0
_0817F208: .4byte 0x0000049C
_0817F20C: .4byte 0x00000474
_0817F210:
	movs r0, #0
_0817F212:
	cmp r0, #0
	bne _0817F2FE
	b _0817F314
_0817F218:
	mov r0, sb
	strh r2, [r0, #0x3e]
	ldr r1, _0817F240 @ =0x0000048A
	adds r0, r7, r1
	strh r2, [r0]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0817F248
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, _0817F244 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0817F2BA
	.align 2, 0
_0817F240: .4byte 0x0000048A
_0817F244: .4byte 0x03002BE0
_0817F248:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0817F264
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _0817F260 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0817F2BA
	.align 2, 0
_0817F260: .4byte 0x03002BE0
_0817F264:
	adds r0, r2, #0
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _0817F284
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, _0817F280 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0817F2BA
	.align 2, 0
_0817F280: .4byte 0x03002BE0
_0817F284:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0817F2A0
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, _0817F29C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0817F2BA
	.align 2, 0
_0817F29C: .4byte 0x03002BE0
_0817F2A0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0817F2B2
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	str r3, [r0]
	b _0817F2BA
_0817F2B2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0817F2BC
_0817F2BA:
	movs r3, #1
_0817F2BC:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	mov r5, ip
	str r5, [r0]
	ldr r2, _0817F2F0 @ =0x0000049C
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	beq _0817F358
	movs r1, #2
	ldr r3, _0817F2F4 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F2F8
	movs r0, #1
	b _0817F2FA
	.align 2, 0
_0817F2F0: .4byte 0x0000049C
_0817F2F4: .4byte 0x00000474
_0817F2F8:
	movs r0, #0
_0817F2FA:
	cmp r0, #0
	beq _0817F314
_0817F2FE:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0817F310 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0817F320
	.align 2, 0
_0817F310: .4byte 0x03002BE0
_0817F314:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _0817F358
_0817F320:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0817F358:
	movs r1, #0x80
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F386
	ldr r5, _0817F390 @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	adds r4, #0xcc
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0817F386
	strh r1, [r2]
_0817F386:
	ldr r5, _0817F394 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _0817F6D0
	.align 2, 0
_0817F390: .4byte 0x0000024E
_0817F394: .4byte 0x0000048C
_0817F398:
	ldr r0, _0817F3AC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0817F3B0
	movs r0, #1
	b _0817F3B2
	.align 2, 0
_0817F3AC: .4byte 0x030047A4
_0817F3B0:
	movs r0, #0
_0817F3B2:
	cmp r0, #0
	beq _0817F3C0
	mov r0, r8
	mov r1, sb
	bl Hitbox_ApplyDamageAlt
	b _0817F3C8
_0817F3C0:
	mov r0, r8
	mov r1, sb
	bl Hitbox_ApplyDamage
_0817F3C8:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, sb
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0817F400 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0817F404 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #0x14]
	cmp r0, #2
	bls _0817F3F6
	cmp r2, #0x17
	bne _0817F408
_0817F3F6:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0817F42A
	.align 2, 0
_0817F400: .4byte 0x0000048C
_0817F404: .4byte 0x000001DF
_0817F408:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0817F3F6
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _0817F458 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0817F42A
	movs r1, #0
_0817F42A:
	mov r0, sb
	adds r0, #0x40
	strh r1, [r0]
	mov sl, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x18]
	cmp r0, #0
	beq _0817F466
	mov r1, sb
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sl
	ldrh r0, [r2]
	cmp r0, #0
	blt _0817F45C
	asrs r0, r0, #1
	b _0817F462
	.align 2, 0
_0817F458: .4byte 0x00000187
_0817F45C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0817F462:
	mov r3, sl
	strh r0, [r3]
_0817F466:
	mov r4, r8
	ldrh r1, [r4, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0817F484
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r5, _0817F480 @ =0x000001DD
	adds r1, r6, r5
	b _0817F4FC
	.align 2, 0
_0817F480: .4byte 0x000001DD
_0817F484:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	mov r2, sb
	adds r2, #0xc
	mov r1, sb
	ldrh r0, [r1, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0817F4E8
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0817F4E8
	ldr r2, _0817F4D8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817F4DC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0817F4E0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0817F4E4 @ =0x000001DD
	adds r1, r6, r4
	b _0817F4FC
	.align 2, 0
_0817F4D8: .4byte 0x030046B8
_0817F4DC: .4byte 0x000003FF
_0817F4E0: .4byte 0x0203B400
_0817F4E4: .4byte 0x000001DD
_0817F4E8:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _0817F51C @ =0x000001DD
	adds r1, r6, r3
_0817F4FC:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0817F524
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0817F520 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0817F592
	.align 2, 0
_0817F51C: .4byte 0x000001DD
_0817F520: .4byte 0x03002BE0
_0817F524:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0817F540
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0817F53C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0817F592
	.align 2, 0
_0817F53C: .4byte 0x03002BE0
_0817F540:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0817F55C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0817F558 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0817F592
	.align 2, 0
_0817F558: .4byte 0x03002BE0
_0817F55C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0817F578
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0817F574 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0817F592
	.align 2, 0
_0817F574: .4byte 0x03002BE0
_0817F578:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0817F58A
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0817F592
_0817F58A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0817F594
_0817F592:
	movs r3, #1
_0817F594:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _0817F5C8 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0817F630
	movs r1, #2
	ldr r2, _0817F5CC @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F5D0
	movs r0, #1
	b _0817F5D2
	.align 2, 0
_0817F5C8: .4byte 0x0000049C
_0817F5CC: .4byte 0x00000474
_0817F5D0:
	movs r0, #0
_0817F5D2:
	cmp r0, #0
	beq _0817F5EC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0817F5E8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0817F5F8
	.align 2, 0
_0817F5E8: .4byte 0x03002BE0
_0817F5EC:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0817F630
_0817F5F8:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0817F630:
	ldr r4, [sp, #0x14]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0817F664
	movs r1, #0x80
	ldr r5, [sp, #0x18]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817F664
	ldr r0, _0817F67C @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0817F664
	strh r1, [r2]
_0817F664:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0817F680 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0817F684 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F688
	movs r0, #1
	b _0817F68A
	.align 2, 0
_0817F67C: .4byte 0x0000024E
_0817F680: .4byte 0x030046A0
_0817F684: .4byte 0x00000934
_0817F688:
	movs r0, #0
_0817F68A:
	ldr r1, _0817F708 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0817F6A4
	movs r0, #0
	mov r2, sb
	strh r0, [r2, #0x3e]
	mov r3, sl
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r5, [sp, #0x14]
	strb r0, [r5]
_0817F6A4:
	adds r0, r6, #0
	bl FUN_080e64e4
	mov r1, sb
	ldrh r0, [r1, #0x3e]
	strh r0, [r4]
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r1, r6, r2
	mov r3, r8
	ldrh r0, [r3, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0817F6D0:
	ldr r5, _0817F708 @ =0x0000048A
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _0817F6DC
	b _0817FA86
_0817F6DC:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817F6F0
	b _0817FA86
_0817F6F0:
	movs r2, #1
	ldr r3, [sp, #8]
	ldr r4, _0817F70C @ =0x00000898
	adds r1, r3, r4
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0817F710
	movs r0, #1
	b _0817F712
	.align 2, 0
_0817F708: .4byte 0x0000048A
_0817F70C: .4byte 0x00000898
_0817F710:
	movs r0, #0
_0817F712:
	cmp r0, #0
	bne _0817F718
	b _0817FA86
_0817F718:
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817F728
	movs r0, #1
	b _0817F72A
_0817F728:
	movs r0, #0
_0817F72A:
	adds r1, r0, #0
	cmp r1, #0
	beq _0817F732
	b _0817FA86
_0817F732:
	movs r5, #0x93
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r2, [r0]
	movs r0, #0x1f
	ands r0, r2
	cmp r0, #0
	beq _0817F750
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	ble _0817F760
_0817F750:
	ldr r2, [sp, #8]
	ldr r3, _0817F75C @ =0x0000089C
	adds r0, r2, r3
	strb r1, [r0]
	b _0817F798
	.align 2, 0
_0817F75C: .4byte 0x0000089C
_0817F760:
	ldr r5, [sp, #8]
	ldr r3, _0817F778 @ =0x00000894
	adds r0, r5, r3
	ldr r0, [r0]
	cmp r2, r0
	bne _0817F780
	ldr r0, _0817F77C @ =0x0000089C
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0817F788
	.align 2, 0
_0817F778: .4byte 0x00000894
_0817F77C: .4byte 0x0000089C
_0817F780:
	ldr r2, [sp, #8]
	ldr r3, _0817F7CC @ =0x0000089C
	adds r0, r2, r3
	strb r1, [r0]
_0817F788:
	ldr r5, [sp, #8]
	ldr r1, _0817F7D0 @ =0x00000894
	adds r0, r5, r1
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r1, [r1]
	str r1, [r0]
_0817F798:
	ldr r3, [sp, #8]
	ldr r5, _0817F7CC @ =0x0000089C
	adds r0, r3, r5
	ldrb r1, [r0]
	cmp r1, #0x1b
	bhi _0817F7A6
	b _0817F9E6
_0817F7A6:
	movs r1, #0
	strb r1, [r0]
	movs r2, #0
	mov r0, sb
	strh r1, [r0, #0x3e]
	ldr r3, _0817F7D4 @ =0x0000048C
	adds r0, r7, r3
	strb r2, [r0]
	mov r0, sb
	adds r0, #0x44
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817F7D8
	movs r0, #1
	b _0817F7DA
	.align 2, 0
_0817F7CC: .4byte 0x0000089C
_0817F7D0: .4byte 0x00000894
_0817F7D4: .4byte 0x0000048C
_0817F7D8:
	movs r0, #0
_0817F7DA:
	cmp r0, #0
	bne _0817F7EC
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
_0817F7EC:
	movs r4, #0xf2
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldr r0, _0817F81C @ =0x00018FFF
	cmp r1, r0
	bhi _0817F828
	movs r1, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0817F820 @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _0817F824 @ =0x0000046A
	adds r0, r7, r4
	strb r1, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r2, [r0]
	b _0817F858
	.align 2, 0
_0817F81C: .4byte 0x00018FFF
_0817F820: .4byte 0x00000469
_0817F824: .4byte 0x0000046A
_0817F828:
	ldr r0, _0817F864 @ =0x0003FFFF
	cmp r1, r0
	bhi _0817F878
	adds r0, r7, #0
	bl FUN_0817ea84
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817F878
	movs r2, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0817F868 @ =0x00000469
	adds r0, r7, r3
	strb r2, [r0]
	ldr r4, _0817F86C @ =0x0000046A
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _0817F870 @ =0x00000484
	adds r0, r7, r5
	str r1, [r0]
_0817F858:
	ldr r0, _0817F874 @ =0x0000046C
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	b _0817FA86
	.align 2, 0
_0817F864: .4byte 0x0003FFFF
_0817F868: .4byte 0x00000469
_0817F86C: .4byte 0x0000046A
_0817F870: .4byte 0x00000484
_0817F874: .4byte 0x0000046C
_0817F878:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r0, _0817F8A0 @ =0x000FFFFF
	cmp r1, r0
	bls _0817F888
	b _0817FA86
_0817F888:
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	lsrs r5, r0, #6
	cmp r5, #1
	beq _0817F8BC
	cmp r5, #1
	bgt _0817F8A4
	cmp r5, #0
	beq _0817F8AE
	b _0817F904
	.align 2, 0
_0817F8A0: .4byte 0x000FFFFF
_0817F8A4:
	cmp r5, #2
	beq _0817F8D8
	cmp r5, #3
	beq _0817F8E8
	b _0817F904
_0817F8AE:
	ldr r2, _0817F8B8 @ =0x00000256
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r4, r0, #1
	b _0817F90A
	.align 2, 0
_0817F8B8: .4byte 0x00000256
_0817F8BC:
	ldr r3, _0817F8D0 @ =0x00000256
	adds r1, r7, r3
	ldr r0, _0817F8D4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	ldrh r1, [r1]
	adds r4, r0, r1
	b _0817F90A
	.align 2, 0
_0817F8D0: .4byte 0x00000256
_0817F8D4: .4byte 0x030046A4
_0817F8D8:
	ldr r1, _0817F8E4 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	subs r4, r0, #1
	b _0817F90A
	.align 2, 0
_0817F8E4: .4byte 0x00000256
_0817F8E8:
	ldr r2, _0817F8FC @ =0x00000256
	adds r0, r7, r2
	ldrh r1, [r0]
	ldr r0, _0817F900 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r1, r0
	b _0817F90A
	.align 2, 0
_0817F8FC: .4byte 0x00000256
_0817F900: .4byte 0x030046A4
_0817F904:
	ldr r4, _0817F91C @ =0x00000256
	adds r0, r7, r4
	ldrh r4, [r0]
_0817F90A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817F920
	adds r0, #4
	b _0817F92C
	.align 2, 0
_0817F91C: .4byte 0x00000256
_0817F920:
	ldr r0, _0817F988 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817F92C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0xa
	ldrsh r0, [r7, r2]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r3, r7
	mov sb, r3
	ldr r4, _0817F98C @ =0x00000469
	adds r4, r4, r7
	mov sl, r4
	ldr r2, _0817F990 @ =0x0000046A
	adds r2, r2, r7
	mov ip, r2
	ldr r3, _0817F994 @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x10]
	ldr r4, _0817F998 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0xc]
	cmp r0, r1
	bge _0817F9CA
	ldr r6, _0817F99C @ =0x7FFFFFFF
	adds r2, r5, #0
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
	movs r4, #3
	adds r1, r2, #1
	movs r0, #0x80
	rsbs r0, r0, #0
	mov r8, r0
	movs r3, #2
_0817F976:
	adds r0, r1, #0
	ands r0, r4
	lsls r0, r0, #6
	ldr r5, [sp, #0x1c]
	subs r0, r5, r0
	cmp r0, #0x80
	ble _0817F9A4
	ldr r5, _0817F9A0 @ =0xFFFFFF00
	b _0817F9AC
	.align 2, 0
_0817F988: .4byte 0x030046A4
_0817F98C: .4byte 0x00000469
_0817F990: .4byte 0x0000046A
_0817F994: .4byte 0x00000484
_0817F998: .4byte 0x0000046C
_0817F99C: .4byte 0x7FFFFFFF
_0817F9A0: .4byte 0xFFFFFF00
_0817F9A4:
	cmp r0, r8
	bge _0817F9AE
	movs r5, #0x80
	lsls r5, r5, #1
_0817F9AC:
	adds r0, r0, r5
_0817F9AE:
	cmp r0, #0
	bge _0817F9B4
	rsbs r0, r0, #0
_0817F9B4:
	cmp r0, r6
	bge _0817F9BE
	adds r6, r0, #0
	adds r2, r1, #0
	ands r2, r4
_0817F9BE:
	adds r1, #1
	subs r3, #1
	cmp r3, #0
	bge _0817F976
	lsls r0, r2, #6
	strb r0, [r7, #5]
_0817F9CA:
	movs r0, #2
	movs r2, #1
	movs r1, #0
	mov r3, sb
	strb r1, [r3]
	mov r4, sl
	strb r0, [r4]
	mov r5, ip
	strb r2, [r5]
	ldr r0, [sp, #0x10]
	str r1, [r0]
	ldr r1, [sp, #0xc]
	strb r2, [r1]
	b _0817FA86
_0817F9E6:
	cmp r1, #1
	bls _0817FA86
	cmp r1, #2
	bne _0817F9F4
	ldr r0, _0817FA18 @ =0x000002D3
	bl PlaySound_082406e0
_0817F9F4:
	movs r2, #0
	movs r1, #0
	mov r3, sb
	strh r1, [r3, #0x3e]
	ldr r5, _0817FA1C @ =0x0000048C
	adds r0, r7, r5
	strb r2, [r0]
	mov r0, sb
	adds r0, #0x44
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817FA20
	movs r0, #1
	b _0817FA22
	.align 2, 0
_0817FA18: .4byte 0x000002D3
_0817FA1C: .4byte 0x0000048C
_0817FA20:
	movs r0, #0
_0817FA22:
	cmp r0, #0
	bne _0817FA34
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
_0817FA34:
	adds r0, r7, #0
	bl FUN_0817dd08
	movs r1, #0x12
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0817FA98 @ =0x00000469
	adds r0, r7, r3
	strb r2, [r0]
	ldr r4, _0817FA9C @ =0x0000046A
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _0817FAA0 @ =0x00000484
	adds r0, r7, r5
	str r2, [r0]
	ldr r1, _0817FAA4 @ =0x0000046C
	adds r0, r7, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0817FAA8 @ =Enemy_ClearStateBegun
	movs r3, #0x10
	subs r5, #0x17
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0817FAAC @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
_0817FA86:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817FA98: .4byte 0x00000469
_0817FA9C: .4byte 0x0000046A
_0817FAA0: .4byte 0x00000484
_0817FAA4: .4byte 0x0000046C
_0817FAA8: .4byte Enemy_ClearStateBegun
_0817FAAC: .4byte 0x0000046B
