	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	ldr r0, _0811D1F4 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811D0AC
	movs r0, #0
	strb r0, [r1]
_0811D0AC:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811D0C4
	bl _0811D8AA
_0811D0C4:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _0811D0D6
	bl _0811D8AA
_0811D0D6:
	ldr r2, _0811D1F8 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0811D0E4
	bl _0811D8A6
_0811D0E4:
	ldr r3, _0811D1FC @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r0, #3
	movs r1, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _0811D200 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	strb r1, [r5]
	ldr r0, _0811D204 @ =0x0000046A
	adds r0, r7, r0
	str r0, [sp, #0x10]
	strb r6, [r0]
	ldr r2, _0811D1F8 @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _0811D1F4 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r1, [r3]
	ldr r2, _0811D208 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _0811D20C @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	strb r1, [r4]
	ldr r5, _0811D210 @ =0x0000046B
	adds r5, r5, r7
	mov r8, r5
	strb r6, [r5]
	ldr r1, _0811D214 @ =0x00000553
	adds r5, r7, r1
	strb r0, [r5]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r4, r7, r3
	str r2, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	strh r6, [r3]
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	mov r0, ip
	str r0, [sp, #0x28]
	ldr r0, [sp, #8]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x20]
	mov r0, sl
	str r0, [sp, #0x34]
	mov r0, sb
	str r0, [sp, #0x2c]
	mov r0, r8
	str r0, [sp, #0x24]
	str r5, [sp, #0x50]
	str r4, [sp, #0x54]
	str r3, [sp, #0x40]
	mov sl, r2
	cmp r1, #0
	bne _0811D182
	b _0811D71C
_0811D182:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0811D218 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
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
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _0811D1EE
	cmp r1, #0
	blt _0811D1EE
	ldr r0, _0811D21C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0811D1EE
	ldr r0, _0811D220 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811D224
_0811D1EE:
	movs r4, #0
	b _0811D232
	.align 2, 0
_0811D1F4: .4byte 0x0000046C
_0811D1F8: .4byte 0x00000484
_0811D1FC: .4byte 0x000001DF
_0811D200: .4byte 0x00000469
_0811D204: .4byte 0x0000046A
_0811D208: .4byte Enemy_WaitPendingState
_0811D20C: .4byte 0x0000046D
_0811D210: .4byte 0x0000046B
_0811D214: .4byte 0x00000553
_0811D218: .4byte 0x00000551
_0811D21C: .4byte 0x030046A8
_0811D220: .4byte 0x030046AC
_0811D224:
	ldr r0, _0811D244 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0811D232:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811D248
	adds r0, #4
	b _0811D254
	.align 2, 0
_0811D244: .4byte 0x030046A4
_0811D248:
	ldr r0, _0811D268 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811D254:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811D26C
	cmp r2, #2
	beq _0811D270
	b _0811D274
	.align 2, 0
_0811D268: .4byte 0x030046A4
_0811D26C:
	ldrb r0, [r5, #4]
	b _0811D272
_0811D270:
	ldrb r0, [r5]
_0811D272:
	subs r1, r1, r0
_0811D274:
	strh r1, [r5, #2]
	ldr r0, _0811D288 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811D28C
	movs r0, #1
	b _0811D28E
	.align 2, 0
_0811D288: .4byte 0x030047A4
_0811D28C:
	movs r0, #0
_0811D28E:
	cmp r0, #0
	beq _0811D2CC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811D2AE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811D2AA
	adds r2, r0, #0
_0811D2AA:
	cmp r2, #0
	bge _0811D2B8
_0811D2AE:
	ldr r2, _0811D2B4 @ =0x000005C4
	adds r0, r7, r2
	b _0811D70A
	.align 2, 0
_0811D2B4: .4byte 0x000005C4
_0811D2B8:
	ldr r1, _0811D2C8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811D314
	.align 2, 0
_0811D2C8: .4byte 0x03002BE0
_0811D2CC:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811D2F8
	cmp r1, #0
	blt _0811D2F8
	ldr r0, _0811D2FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811D2F8
	ldr r0, _0811D300 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811D304
_0811D2F8:
	movs r5, #0
	b _0811D312
	.align 2, 0
_0811D2FC: .4byte 0x030046A8
_0811D300: .4byte 0x030046AC
_0811D304:
	ldr r0, _0811D3A4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811D312:
	movs r2, #0
_0811D314:
	ldr r4, _0811D3A8 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811D334
	ldr r1, _0811D3AC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811D334
	b _0811D648
_0811D334:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0811D348
	b _0811D8AA
_0811D348:
	ldr r0, _0811D3B0 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0811D3B4
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x2c]
	strb r2, [r3]
	ldr r3, [sp, #0x24]
	strb r5, [r3]
	ldr r3, [sp, #0x50]
	strb r0, [r3]
	ldr r0, [sp, #0x54]
	str r1, [r0]
	ldr r1, [sp, #0x40]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x18]
	strb r5, [r3]
	ldr r1, [sp, #0x1c]
	strb r5, [r1]
	ldr r3, [sp, #0x20]
	strb r0, [r3]
	ldr r5, [sp, #0x34]
	str r4, [r5]
	ldr r0, [sp, #0x28]
	strb r2, [r0]
	b _0811D502
	.align 2, 0
_0811D3A4: .4byte 0x030046A4
_0811D3A8: .4byte 0x00000256
_0811D3AC: .4byte 0x03002BE0
_0811D3B0: .4byte 0x00000222
_0811D3B4:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x24]
	strb r5, [r4]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	str r1, [r4]
	ldr r1, [sp, #0x40]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x18]
	strb r5, [r2]
	ldr r4, [sp, #0x1c]
	strb r5, [r4]
	ldr r5, [sp, #0x20]
	strb r1, [r5]
	ldr r1, [sp, #0x34]
	str r3, [r1]
	ldr r2, [sp, #0x28]
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
	blt _0811D418
	cmp r1, #0
	blt _0811D418
	ldr r0, _0811D41C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811D418
	ldr r0, _0811D420 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811D424
_0811D418:
	movs r4, #0
	b _0811D432
	.align 2, 0
_0811D41C: .4byte 0x030046A8
_0811D420: .4byte 0x030046AC
_0811D424:
	ldr r0, _0811D444 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811D432:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811D448
	adds r0, #4
	b _0811D454
	.align 2, 0
_0811D444: .4byte 0x030046A4
_0811D448:
	ldr r0, _0811D468 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811D454:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811D46C
	cmp r2, #2
	beq _0811D470
	b _0811D474
	.align 2, 0
_0811D468: .4byte 0x030046A4
_0811D46C:
	ldrb r0, [r5, #4]
	b _0811D472
_0811D470:
	ldrb r0, [r5]
_0811D472:
	subs r1, r1, r0
_0811D474:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811D49C
	cmp r1, #0
	blt _0811D49C
	ldr r0, _0811D4A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811D49C
	ldr r0, _0811D4A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811D4A8
_0811D49C:
	movs r4, #0
	b _0811D4B6
	.align 2, 0
_0811D4A0: .4byte 0x030046A8
_0811D4A4: .4byte 0x030046AC
_0811D4A8:
	ldr r0, _0811D4C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811D4B6:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811D4CC
	adds r0, #4
	b _0811D4D8
	.align 2, 0
_0811D4C8: .4byte 0x030046A4
_0811D4CC:
	ldr r0, _0811D4EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811D4D8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811D4F0
	cmp r3, #2
	beq _0811D4F4
	b _0811D4F8
	.align 2, 0
_0811D4EC: .4byte 0x030046A4
_0811D4F0:
	ldrb r0, [r5, #4]
	b _0811D4F6
_0811D4F4:
	ldrb r0, [r5]
_0811D4F6:
	subs r2, r2, r0
_0811D4F8:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0811D502:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x30]
	cmp r0, #0
	bne _0811D60C
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811D52C
	movs r0, #1
	b _0811D52E
_0811D52C:
	movs r0, #0
_0811D52E:
	ldr r3, _0811D61C @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x30]
	cmp r0, #0
	bne _0811D60C
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _0811D620 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0811D624 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _0811D628 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r4, _0811D62C @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _0811D630 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x38]
	ldr r0, _0811D634 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x58]
	ldr r1, _0811D638 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r6, _0811D63C @ =0x0203B400
	ldr r1, _0811D640 @ =0x030046B8
	ldr r5, _0811D644 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_0811D57E:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _0811D59C
	adds r3, #1
	cmp r3, #3
	ble _0811D57E
	mov r0, r8
_0811D59C:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x50]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x18]
	ldrb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r0, [r5]
	ldr r1, [sp, #0x1c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x20]
	ldrb r0, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x58]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x2c]
	strb r1, [r5]
	ldr r4, [sp, #0x24]
	strb r3, [r4]
	ldr r5, [sp, #0x50]
	strb r0, [r5]
	ldr r0, [sp, #0x54]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x40]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r4, [sp, #0x20]
	strb r2, [r4]
	ldr r5, [sp, #0x34]
	str r3, [r5]
	ldr r0, [sp, #0x28]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x3c]
	strb r0, [r1]
_0811D60C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x30]
	strh r0, [r2]
	b _0811D8AA
	.align 2, 0
_0811D61C: .4byte 0x00000482
_0811D620: .4byte 0x0000054F
_0811D624: .4byte 0x0000054C
_0811D628: .4byte 0x0000054D
_0811D62C: .4byte 0x0000054E
_0811D630: .4byte 0x00000541
_0811D634: .4byte 0x000005BC
_0811D638: .4byte 0x00000542
_0811D63C: .4byte 0x0203B400
_0811D640: .4byte 0x030046B8
_0811D644: .4byte 0x000003FF
_0811D648:
	mov sb, sp
	ldr r6, _0811D684 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	beq _0811D688
	adds r0, #4
	b _0811D692
	.align 2, 0
_0811D684: .4byte 0x030046A4
_0811D688:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811D692:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _0811D6CC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811D6D4
	ldr r0, _0811D6D0 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811D6FE
	.align 2, 0
_0811D6CC: .4byte 0x000004A4
_0811D6D0: .4byte 0xFFFFFDFF
_0811D6D4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811D6F4
	cmp r0, #2
	beq _0811D6F0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811D6F0:
	movs r0, #1
	b _0811D700
_0811D6F4:
	ldr r0, _0811D714 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811D6FE:
	movs r0, #0
_0811D700:
	cmp r0, #0
	beq _0811D706
	b _0811D8AA
_0811D706:
	ldr r4, _0811D718 @ =0x000005C4
	adds r0, r7, r4
_0811D70A:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0811D8AA
	.align 2, 0
_0811D714: .4byte 0xFFFFFDFF
_0811D718: .4byte 0x000005C4
_0811D71C:
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r3, _0811D790 @ =Golem_StateMove
	movs r4, #7
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _0811D794 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0811D798 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811D78A
	cmp r1, #0
	blt _0811D78A
	ldr r0, _0811D79C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811D78A
	ldr r0, _0811D7A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811D7A4
_0811D78A:
	movs r4, #0
	b _0811D7B2
	.align 2, 0
_0811D790: .4byte Golem_StateMove
_0811D794: .4byte 0x00000554
_0811D798: .4byte 0x00000551
_0811D79C: .4byte 0x030046A8
_0811D7A0: .4byte 0x030046AC
_0811D7A4:
	ldr r0, _0811D7C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811D7B2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811D7C8
	adds r0, #4
	b _0811D7D4
	.align 2, 0
_0811D7C4: .4byte 0x030046A4
_0811D7C8:
	ldr r0, _0811D7E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811D7D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811D7EC
	cmp r2, #2
	beq _0811D7F0
	b _0811D7F4
	.align 2, 0
_0811D7E8: .4byte 0x030046A4
_0811D7EC:
	ldrb r0, [r5, #4]
	b _0811D7F2
_0811D7F0:
	ldrb r0, [r5]
_0811D7F2:
	subs r1, r1, r0
_0811D7F4:
	strh r1, [r5, #2]
	ldr r2, _0811D824 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811D82C
	ldr r0, _0811D828 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _0811D856
	.align 2, 0
_0811D824: .4byte 0x000004A4
_0811D828: .4byte 0xFFFFFDFF
_0811D82C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811D84C
	cmp r0, #2
	beq _0811D848
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811D848:
	movs r0, #1
	b _0811D858
_0811D84C:
	ldr r0, _0811D890 @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_0811D856:
	movs r0, #0
_0811D858:
	adds r3, r0, #0
	cmp r3, #0
	bne _0811D898
	ldr r0, _0811D894 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r1, [sp, #0x2c]
	strb r2, [r1]
	ldr r4, [sp, #0x24]
	strb r3, [r4]
	ldr r5, [sp, #0x50]
	strb r3, [r5]
	ldr r1, [sp, #0x54]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x40]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r4, [sp, #0x20]
	strb r1, [r4]
	ldr r5, [sp, #0x34]
	str r3, [r5]
	ldr r0, [sp, #0x28]
	strb r2, [r0]
	b _0811D8AA
	.align 2, 0
_0811D890: .4byte 0xFFFFFDFF
_0811D894: .4byte Enemy_ClearStateBegun
_0811D898:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _0811D8AA

_0811D8A6:
	adds r0, #1
	str r0, [r1]
_0811D8AA:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
