	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x90
	adds r7, r0, #0
	ldr r0, _081811D0 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081811D4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081811D6
	.align 2, 0
_081811D0: .4byte 0x0000046C
_081811D4:
	movs r0, #0
_081811D6:
	cmp r0, #0
	beq _081811E4
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	strb r0, [r7, #5]
_081811E4:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081811FC
	bl _08181A66
_081811FC:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _0818120E
	bl _08181A66
_0818120E:
	ldr r3, _08181300 @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0818121C
	bl _08181A62
_0818121C:
	movs r0, #0x80
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	str r2, [sp, #0x48]
	cmp r3, #0
	bne _08181234
	b _08181828
_08181234:
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #8]
	strb r6, [r1]
	ldr r2, _08181304 @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r6, [r2]
	ldr r3, _08181308 @ =0x0000046A
	adds r3, r7, r3
	str r3, [sp, #0x10]
	strb r0, [r3]
	ldr r4, _08181300 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x14]
	str r6, [r4]
	ldr r0, _0818130C @ =0x0000046C
	adds r0, r0, r7
	mov sb, r0
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r0, #0x1a
	ldr r3, _08181310 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r1, [r3]
	ldr r4, _08181314 @ =0x0000046B
	adds r4, r4, r7
	mov r8, r4
	strb r6, [r4]
	ldr r1, _08181318 @ =0x00000553
	adds r1, r1, r7
	mov sl, r1
	strb r0, [r1]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r5, r7, r3
	str r2, [r5]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r7, r0
	strh r6, [r4]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
	ldr r2, [r3]
	str r2, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x1c]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, sb
	str r0, [sp, #0x80]
	ldr r6, [sp, #8]
	str r6, [sp, #0x70]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x78]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x84]
	mov r0, r8
	str r0, [sp, #0x7c]
	mov r6, sl
	str r6, [sp, #0x60]
	str r5, [sp, #0x68]
	str r4, [sp, #0x64]
	adds r6, r3, #0
	mov r8, r2
	mov r0, ip
	cmp r0, #0
	blt _081812FC
	cmp r1, #0
	blt _081812FC
	ldr r0, _0818131C @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081812FC
	ldr r0, _08181320 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08181324
_081812FC:
	movs r4, #0
	b _08181334
	.align 2, 0
_08181300: .4byte 0x00000484
_08181304: .4byte 0x00000469
_08181308: .4byte 0x0000046A
_0818130C: .4byte 0x0000046C
_08181310: .4byte 0x0000046D
_08181314: .4byte 0x0000046B
_08181318: .4byte 0x00000553
_0818131C: .4byte 0x030046A8
_08181320: .4byte 0x030046AC
_08181324:
	ldr r0, _08181344 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08181334:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08181348
	adds r0, #4
	b _08181354
	.align 2, 0
_08181344: .4byte 0x030046A4
_08181348:
	ldr r0, _08181368 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08181354:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0818136C
	cmp r2, #2
	beq _08181372
	b _08181378
	.align 2, 0
_08181368: .4byte 0x030046A4
_0818136C:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2, #4]
	b _08181376
_08181372:
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
_08181376:
	subs r1, r1, r0
_08181378:
	ldr r4, [sp, #0x1c]
	strh r1, [r4, #2]
	ldr r0, _08181390 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08181394
	movs r0, #1
	b _08181396
	.align 2, 0
_08181390: .4byte 0x030047A4
_08181394:
	movs r0, #0
_08181396:
	cmp r0, #0
	beq _081813D4
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081813B6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081813B2
	adds r2, r0, #0
_081813B2:
	cmp r2, #0
	bge _081813C0
_081813B6:
	ldr r2, _081813BC @ =0x000005C4
	adds r0, r7, r2
	b _08181816
	.align 2, 0
_081813BC: .4byte 0x000005C4
_081813C0:
	ldr r1, _081813D0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0818141C
	.align 2, 0
_081813D0: .4byte 0x03002BE0
_081813D4:
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
	blt _08181400
	cmp r1, #0
	blt _08181400
	ldr r0, _08181404 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08181400
	ldr r0, _08181408 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818140C
_08181400:
	movs r5, #0
	b _0818141A
	.align 2, 0
_08181404: .4byte 0x030046A8
_08181408: .4byte 0x030046AC
_0818140C:
	ldr r0, _081814AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0818141A:
	movs r2, #0
_0818141C:
	ldr r4, _081814B0 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0818143C
	ldr r1, _081814B4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0818143C
	b _08181754
_0818143C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x48]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08181450
	b _08181A66
_08181450:
	ldr r3, _081814B8 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x48]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sl, r2
	cmp r3, #0
	beq _081814BC
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x84]
	strb r2, [r3]
	ldr r6, [sp, #0x7c]
	strb r5, [r6]
	ldr r3, [sp, #0x60]
	strb r0, [r3]
	ldr r6, [sp, #0x68]
	str r1, [r6]
	ldr r0, [sp, #0x64]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x70]
	strb r5, [r1]
	ldr r3, [sp, #0x74]
	strb r5, [r3]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	ldr r0, [sp, #0x8c]
	str r4, [r0]
	ldr r1, [sp, #0x80]
	strb r2, [r1]
	b _0818160A
	.align 2, 0
_081814AC: .4byte 0x030046A4
_081814B0: .4byte 0x00000256
_081814B4: .4byte 0x03002BE0
_081814B8: .4byte 0x00000222
_081814BC:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x84]
	strb r0, [r4]
	ldr r2, [sp, #0x7c]
	strb r5, [r2]
	ldr r4, [sp, #0x60]
	strb r0, [r4]
	ldr r2, [sp, #0x68]
	str r1, [r2]
	ldr r4, [sp, #0x64]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x70]
	strb r5, [r2]
	ldr r4, [sp, #0x74]
	strb r5, [r4]
	ldr r2, [sp, #0x78]
	strb r1, [r2]
	ldr r4, [sp, #0x8c]
	str r3, [r4]
	ldr r1, [sp, #0x80]
	strb r0, [r1]
	ldr r5, [r6]
	mov r2, r8
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
	blt _08181520
	cmp r1, #0
	blt _08181520
	ldr r0, _08181524 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08181520
	ldr r0, _08181528 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818152C
_08181520:
	movs r4, #0
	b _0818153A
	.align 2, 0
_08181524: .4byte 0x030046A8
_08181528: .4byte 0x030046AC
_0818152C:
	ldr r0, _0818154C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0818153A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08181550
	adds r0, #4
	b _0818155C
	.align 2, 0
_0818154C: .4byte 0x030046A4
_08181550:
	ldr r0, _08181570 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818155C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08181574
	cmp r2, #2
	beq _08181578
	b _0818157C
	.align 2, 0
_08181570: .4byte 0x030046A4
_08181574:
	ldrb r0, [r5, #4]
	b _0818157A
_08181578:
	ldrb r0, [r5]
_0818157A:
	subs r1, r1, r0
_0818157C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081815A4
	cmp r1, #0
	blt _081815A4
	ldr r0, _081815A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081815A4
	ldr r0, _081815AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081815B0
_081815A4:
	movs r4, #0
	b _081815BE
	.align 2, 0
_081815A8: .4byte 0x030046A8
_081815AC: .4byte 0x030046AC
_081815B0:
	ldr r0, _081815D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081815BE:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081815D4
	adds r0, #4
	b _081815E0
	.align 2, 0
_081815D0: .4byte 0x030046A4
_081815D4:
	ldr r0, _081815F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081815E0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081815F8
	cmp r3, #2
	beq _081815FC
	b _08181600
	.align 2, 0
_081815F4: .4byte 0x030046A4
_081815F8:
	ldrb r0, [r5, #4]
	b _081815FE
_081815FC:
	ldrb r0, [r5]
_081815FE:
	subs r2, r2, r0
_08181600:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0818160A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r1
	mov sb, r3
	ldr r6, _08181634 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x88]
	cmp r0, #0
	bne _08181718
	movs r1, #4
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08181638
	movs r0, #1
	b _0818163A
	.align 2, 0
_08181634: .4byte 0x00000482
_08181638:
	movs r0, #0
_0818163A:
	ldr r3, _08181728 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x88]
	cmp r0, #0
	bne _08181718
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _0818172C @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08181730 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x54]
	ldr r2, _08181734 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x58]
	ldr r4, _08181738 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x5c]
	ldr r6, _0818173C @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	ldr r0, _08181740 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x6c]
	ldr r1, _08181744 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x50]
	ldr r6, _08181748 @ =0x0203B400
	ldr r1, _0818174C @ =0x030046B8
	ldr r5, _08181750 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_0818168A:
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
	bne _081816A8
	adds r3, #1
	cmp r3, #3
	ble _0818168A
	mov r0, sb
_081816A8:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x68]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x60]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x70]
	ldrb r0, [r4]
	ldr r6, [sp, #0x54]
	strb r0, [r6]
	ldr r1, [sp, #0x74]
	ldrb r0, [r1]
	ldr r2, [sp, #0x58]
	strb r0, [r2]
	ldr r4, [sp, #0x78]
	ldrb r0, [r4]
	ldr r6, [sp, #0x5c]
	strb r0, [r6]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x4c]
	strb r1, [r0]
	ldr r1, [sp, #0x6c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x84]
	strb r1, [r4]
	ldr r6, [sp, #0x7c]
	strb r3, [r6]
	ldr r4, [sp, #0x60]
	strb r0, [r4]
	ldr r6, [sp, #0x68]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x64]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r6, [sp, #0x74]
	strb r1, [r6]
	ldr r0, [sp, #0x78]
	strb r2, [r0]
	ldr r2, [sp, #0x8c]
	str r3, [r2]
	ldr r3, [sp, #0x80]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x50]
	strb r0, [r4]
_08181718:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x88]
	strh r0, [r6]
	b _08181A66
	.align 2, 0
_08181728: .4byte 0x00000482
_0818172C: .4byte 0x0000054F
_08181730: .4byte 0x0000054C
_08181734: .4byte 0x0000054D
_08181738: .4byte 0x0000054E
_0818173C: .4byte 0x00000541
_08181740: .4byte 0x000005BC
_08181744: .4byte 0x00000542
_08181748: .4byte 0x0203B400
_0818174C: .4byte 0x030046B8
_08181750: .4byte 0x000003FF
_08181754:
	mov sb, sp
	ldr r6, _08181790 @ =0x030046A4
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
	beq _08181794
	adds r0, #4
	b _0818179E
	.align 2, 0
_08181790: .4byte 0x030046A4
_08181794:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818179E:
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
	ldr r1, _081817D8 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081817E0
	ldr r0, _081817DC @ =0xFFFFFDFF
	ldr r2, [sp, #0x48]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0818180A
	.align 2, 0
_081817D8: .4byte 0x000004A4
_081817DC: .4byte 0xFFFFFDFF
_081817E0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08181800
	cmp r0, #2
	beq _081817FC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081817FC:
	movs r0, #1
	b _0818180C
_08181800:
	ldr r0, _08181820 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0818180A:
	movs r0, #0
_0818180C:
	cmp r0, #0
	beq _08181812
	b _08181A66
_08181812:
	ldr r4, _08181824 @ =0x000005C4
	adds r0, r7, r4
_08181816:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08181A66
	.align 2, 0
_08181820: .4byte 0xFFFFFDFF
_08181824: .4byte 0x000005C4
_08181828:
	movs r0, #3
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	ldr r0, _0818192C @ =0x00000469
	adds r0, r7, r0
	str r0, [sp, #0x28]
	strb r1, [r0]
	ldr r2, _08181930 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	strb r3, [r2]
	ldr r4, _08181934 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x30]
	str r3, [r4]
	ldr r6, _08181938 @ =0x0000046C
	adds r6, r7, r6
	str r6, [sp, #0x34]
	strb r1, [r6]
	ldr r2, _0818193C @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _08181940 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x38]
	strb r1, [r4]
	ldr r6, _08181944 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x3c]
	strb r3, [r6]
	ldr r1, _08181948 @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0x40]
	strb r0, [r1]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	str r2, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x44]
	movs r5, #0
	strh r3, [r6]
	ldr r1, _0818194C @ =0x000001DF
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x1e
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _08181950 @ =0x00000551
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _08181954 @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
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
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x70]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0x74]
	ldr r4, [sp, #0x2c]
	str r4, [sp, #0x78]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x8c]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x84]
	ldr r3, [sp, #0x3c]
	str r3, [sp, #0x7c]
	ldr r4, [sp, #0x40]
	str r4, [sp, #0x60]
	mov r6, r8
	str r6, [sp, #0x68]
	ldr r0, [sp, #0x44]
	str r0, [sp, #0x64]
	cmp r2, #0
	blt _08181926
	cmp r1, #0
	blt _08181926
	ldr r0, _08181958 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08181926
	ldr r0, _0818195C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08181960
_08181926:
	movs r4, #0
	b _0818196E
	.align 2, 0
_0818192C: .4byte 0x00000469
_08181930: .4byte 0x0000046A
_08181934: .4byte 0x00000484
_08181938: .4byte 0x0000046C
_0818193C: .4byte Enemy_WaitPendingState
_08181940: .4byte 0x0000046D
_08181944: .4byte 0x0000046B
_08181948: .4byte 0x00000553
_0818194C: .4byte 0x000001DF
_08181950: .4byte 0x00000551
_08181954: .4byte 0x00000552
_08181958: .4byte 0x030046A8
_0818195C: .4byte 0x030046AC
_08181960:
	ldr r0, _08181980 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0818196E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08181984
	adds r0, #4
	b _08181990
	.align 2, 0
_08181980: .4byte 0x030046A4
_08181984:
	ldr r0, _081819A4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08181990:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081819A8
	cmp r2, #2
	beq _081819AC
	b _081819B0
	.align 2, 0
_081819A4: .4byte 0x030046A4
_081819A8:
	ldrb r0, [r5, #4]
	b _081819AE
_081819AC:
	ldrb r0, [r5]
_081819AE:
	subs r1, r1, r0
_081819B0:
	strh r1, [r5, #2]
	ldr r1, _081819E0 @ =0x000004A4
	adds r0, r7, r1
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081819E8
	ldr r0, _081819E4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _08181A12
	.align 2, 0
_081819E0: .4byte 0x000004A4
_081819E4: .4byte 0xFFFFFDFF
_081819E8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08181A08
	cmp r0, #2
	beq _08181A04
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08181A04:
	movs r0, #1
	b _08181A14
_08181A08:
	ldr r0, _08181A4C @ =0xFFFFFDFF
	ldr r4, [sp, #0x48]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_08181A12:
	movs r0, #0
_08181A14:
	adds r3, r0, #0
	cmp r3, #0
	bne _08181A54
	ldr r0, _08181A50 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r6, [sp, #0x84]
	strb r2, [r6]
	ldr r1, [sp, #0x7c]
	strb r3, [r1]
	ldr r4, [sp, #0x60]
	strb r3, [r4]
	ldr r6, [sp, #0x68]
	str r0, [r6]
	movs r1, #0
	ldr r0, [sp, #0x64]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r6, [sp, #0x74]
	strb r1, [r6]
	ldr r0, [sp, #0x78]
	strb r1, [r0]
	ldr r1, [sp, #0x8c]
	str r3, [r1]
	ldr r3, [sp, #0x80]
	strb r2, [r3]
	b _08181A66
	.align 2, 0
_08181A4C: .4byte 0xFFFFFDFF
_08181A50: .4byte Enemy_ClearStateBegun
_08181A54:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _08181A66

_08181A62:
	adds r0, #1
	str r0, [r1]
_08181A66:
	add sp, #0x90
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
