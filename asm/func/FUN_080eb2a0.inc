	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x90
	str r0, [sp, #0x10]
	movs r1, #2
	ldr r2, _080EB2C0 @ =0x00000222
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080EB2C4
	movs r0, #1
	b _080EB2C6
	.align 2, 0
_080EB2C0: .4byte 0x00000222
_080EB2C4:
	movs r0, #0
_080EB2C6:
	cmp r0, #0
	beq _080EB2CE
	bl _080EC404
_080EB2CE:
	movs r2, #1
	ldr r3, [sp, #0x10]
	ldr r4, _080EB2E4 @ =0x00000222
	adds r1, r3, r4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x7c]
	cmp r0, #0
	beq _080EB2E8
	movs r0, #1
	b _080EB2EA
	.align 2, 0
_080EB2E4: .4byte 0x00000222
_080EB2E8:
	movs r0, #0
_080EB2EA:
	cmp r0, #0
	bne _080EB2F2
	bl _080EC404
_080EB2F2:
	ldr r5, [sp, #0x10]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r7, #0xa
	ldrsh r1, [r5, r7]
	movs r2, #0xa
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _080EB30A
	b _080EB958
_080EB30A:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r3, r5, r4
	ldr r5, [r3]
	ldr r2, [sp, #0x10]
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
	str r3, [sp, #0x5c]
	str r2, [sp, #0x38]
	cmp r4, #0
	blt _080EB346
	cmp r1, #0
	blt _080EB346
	ldr r0, _080EB34C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080EB346
	ldr r0, _080EB350 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080EB354
_080EB346:
	movs r4, #0
	b _080EB362
	.align 2, 0
_080EB34C: .4byte 0x030046A8
_080EB350: .4byte 0x030046AC
_080EB354:
	ldr r0, _080EB374 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080EB362:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EB378
	adds r0, #4
	b _080EB384
	.align 2, 0
_080EB374: .4byte 0x030046A4
_080EB378:
	ldr r0, _080EB398 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EB384:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080EB39C
	cmp r2, #2
	beq _080EB3A0
	b _080EB3A4
	.align 2, 0
_080EB398: .4byte 0x030046A4
_080EB39C:
	ldrb r0, [r5, #4]
	b _080EB3A2
_080EB3A0:
	ldrb r0, [r5]
_080EB3A2:
	subs r1, r1, r0
_080EB3A4:
	strh r1, [r5, #2]
	ldr r0, _080EB3B8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080EB3BC
	movs r0, #1
	b _080EB3BE
	.align 2, 0
_080EB3B8: .4byte 0x030047A4
_080EB3BC:
	movs r0, #0
_080EB3BE:
	cmp r0, #0
	beq _080EB408
	ldr r5, [sp, #0x10]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _080EB3E0
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _080EB3DC
	adds r2, r0, #0
_080EB3DC:
	cmp r2, #0
	bge _080EB3F4
_080EB3E0:
	ldr r7, [sp, #0x10]
	ldr r1, _080EB3F0 @ =0x000005C4
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _080EB940
	.align 2, 0
_080EB3F0: .4byte 0x000005C4
_080EB3F4:
	ldr r1, _080EB404 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _080EB454
	.align 2, 0
_080EB404: .4byte 0x03002BE0
_080EB408:
	ldr r2, [sp, #0x10]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080EB436
	cmp r1, #0
	blt _080EB436
	ldr r0, _080EB43C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080EB436
	ldr r0, _080EB440 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080EB444
_080EB436:
	movs r5, #0
	b _080EB452
	.align 2, 0
_080EB43C: .4byte 0x030046A8
_080EB440: .4byte 0x030046AC
_080EB444:
	ldr r0, _080EB538 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080EB452:
	movs r2, #0
_080EB454:
	ldr r4, [sp, #0x10]
	ldr r6, _080EB53C @ =0x00000256
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _080EB476
	ldr r1, _080EB540 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080EB476
	b _080EB878
_080EB476:
	movs r0, #0x80
	lsls r0, r0, #3
	ldr r7, [sp, #0x10]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	str r2, [sp, #0x60]
	cmp r7, #0
	beq _080EB492
	b _080EB940
_080EB492:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r2, [sp, #0x7c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x60]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080EB558
	ldr r4, [sp, #0x10]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r4, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _080EB544 @ =0x0000046D
	adds r4, r4, r6
	mov ip, r4
	movs r2, #1
	mov sb, r2
	mov r3, sb
	strb r3, [r4]
	ldr r4, [sp, #0x10]
	ldr r5, _080EB548 @ =0x0000046B
	adds r4, r4, r5
	mov sl, r4
	movs r6, #0
	strb r6, [r4]
	ldr r2, [sp, #0x10]
	ldr r3, _080EB54C @ =0x00000553
	adds r2, r2, r3
	mov r8, r2
	strb r0, [r2]
	movs r5, #0xaf
	lsls r5, r5, #3
	ldr r4, [sp, #0x10]
	adds r5, r4, r5
	str r5, [sp, #0x88]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r4, r6
	strh r7, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r4, r1
	movs r2, #0
	strb r2, [r4]
	ldr r6, [sp, #0x10]
	adds r1, #1
	adds r3, r6, r1
	strb r2, [r3]
	adds r1, #1
	adds r2, r6, r1
	strb r0, [r2]
	ldr r0, _080EB550 @ =0x00000484
	adds r1, r6, r0
	str r7, [r1]
	ldr r7, _080EB554 @ =0x0000046C
	adds r0, r6, r7
	mov r6, sb
	strb r6, [r0]
	mov r7, ip
	str r7, [sp, #0x50]
	mov r6, sl
	str r6, [sp, #0x48]
	mov r7, r8
	str r7, [sp, #0x70]
	ldr r6, [sp, #0x88]
	str r6, [sp, #0x78]
	str r5, [sp, #0x74]
	str r4, [sp, #0x3c]
	str r3, [sp, #0x40]
	str r2, [sp, #0x44]
	str r1, [sp, #0x58]
	str r0, [sp, #0x4c]
	b _080EB728
	.align 2, 0
_080EB538: .4byte 0x030046A4
_080EB53C: .4byte 0x00000256
_080EB540: .4byte 0x03002BE0
_080EB544: .4byte 0x0000046D
_080EB548: .4byte 0x0000046B
_080EB54C: .4byte 0x00000553
_080EB550: .4byte 0x00000484
_080EB554: .4byte 0x0000046C
_080EB558:
	ldr r7, [sp, #0x10]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _080EB61C @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r0, [r3]
	adds r4, r7, #0
	ldr r5, _080EB620 @ =0x0000046B
	adds r4, r4, r5
	mov ip, r4
	movs r6, #0
	strb r6, [r4]
	ldr r3, _080EB624 @ =0x00000553
	adds r7, r7, r3
	mov sl, r7
	strb r0, [r7]
	ldr r4, [sp, #0x10]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r4, r4, r5
	mov sb, r4
	str r1, [r4]
	ldr r6, [sp, #0x10]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r6, r6, r7
	mov r8, r6
	strh r2, [r6]
	movs r1, #5
	ldr r3, [sp, #0x10]
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r6, r3, r4
	movs r5, #0
	strb r5, [r6]
	ldr r7, _080EB628 @ =0x00000469
	adds r5, r3, r7
	movs r3, #0
	strb r3, [r5]
	ldr r7, [sp, #0x10]
	ldr r3, _080EB62C @ =0x0000046A
	adds r4, r7, r3
	strb r1, [r4]
	ldr r1, _080EB630 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	subs r1, #0x18
	adds r2, r7, r1
	strb r0, [r2]
	ldr r7, [sp, #0x5c]
	ldr r7, [r7]
	str r7, [sp, #0x1c]
	ldr r1, [sp, #0x38]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	strh r1, [r7]
	ldr r7, [sp, #0x38]
	ldr r0, [r7, #8]
	ldrh r0, [r0, #2]
	ldr r7, [sp, #0x1c]
	strh r0, [r7, #4]
	lsls r1, r1, #0x10
	asrs r7, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x50]
	mov r0, ip
	str r0, [sp, #0x48]
	mov r0, sl
	str r0, [sp, #0x70]
	mov r0, sb
	str r0, [sp, #0x78]
	mov r0, r8
	str r0, [sp, #0x74]
	str r6, [sp, #0x3c]
	str r5, [sp, #0x40]
	str r4, [sp, #0x44]
	str r3, [sp, #0x58]
	str r2, [sp, #0x4c]
	cmp r7, #0
	blt _080EB618
	cmp r1, #0
	blt _080EB618
	ldr r0, _080EB634 @ =0x030046A8
	ldr r0, [r0]
	cmp r7, r0
	bhs _080EB618
	ldr r0, _080EB638 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080EB63C
_080EB618:
	movs r7, #0
	b _080EB64A
	.align 2, 0
_080EB61C: .4byte 0x0000046D
_080EB620: .4byte 0x0000046B
_080EB624: .4byte 0x00000553
_080EB628: .4byte 0x00000469
_080EB62C: .4byte 0x0000046A
_080EB630: .4byte 0x00000484
_080EB634: .4byte 0x030046A8
_080EB638: .4byte 0x030046AC
_080EB63C:
	ldr r0, _080EB65C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r7
_080EB64A:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EB660
	adds r0, #4
	b _080EB66C
	.align 2, 0
_080EB65C: .4byte 0x030046A4
_080EB660:
	ldr r0, _080EB680 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EB66C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080EB684
	cmp r2, #2
	beq _080EB68A
	b _080EB690
	.align 2, 0
_080EB680: .4byte 0x030046A4
_080EB684:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2, #4]
	b _080EB68E
_080EB68A:
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
_080EB68E:
	subs r1, r1, r0
_080EB690:
	ldr r4, [sp, #0x1c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x5c]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080EB6BC
	cmp r1, #0
	blt _080EB6BC
	ldr r0, _080EB6C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080EB6BC
	ldr r0, _080EB6C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080EB6C8
_080EB6BC:
	movs r7, #0
	b _080EB6D6
	.align 2, 0
_080EB6C0: .4byte 0x030046A8
_080EB6C4: .4byte 0x030046AC
_080EB6C8:
	ldr r0, _080EB6EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_080EB6D6:
	ldr r6, [sp, #0x5c]
	ldr r4, [r6]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EB6F0
	adds r0, #4
	b _080EB6FC
	.align 2, 0
_080EB6EC: .4byte 0x030046A4
_080EB6F0:
	ldr r0, _080EB710 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EB6FC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080EB714
	cmp r3, #2
	beq _080EB718
	b _080EB71C
	.align 2, 0
_080EB710: .4byte 0x030046A4
_080EB714:
	ldrb r0, [r4, #4]
	b _080EB71A
_080EB718:
	ldrb r0, [r4]
_080EB71A:
	subs r2, r2, r0
_080EB71C:
	ldr r7, [sp, #0x5c]
	ldr r0, [r7]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r7]
	strh r1, [r0, #6]
_080EB728:
	ldr r0, [sp, #0x10]
	ldrb r0, [r0, #5]
	str r0, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x60]
	ldrh r0, [r2]
	ands r0, r1
	ldr r4, [sp, #0x20]
	ldr r5, _080EB758 @ =0x00000482
	ldr r3, [sp, #0x10]
	adds r5, r3, r5
	str r5, [sp, #0x54]
	cmp r0, #0
	beq _080EB748
	b _080EB848
_080EB748:
	movs r1, #4
	ldr r6, [sp, #0x7c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080EB75C
	movs r0, #1
	b _080EB75E
	.align 2, 0
_080EB758: .4byte 0x00000482
_080EB75C:
	movs r0, #0
_080EB75E:
	ldr r1, _080EB858 @ =0x00000482
	ldr r7, [sp, #0x10]
	adds r1, r7, r1
	str r1, [sp, #0x54]
	cmp r0, #0
	bne _080EB848
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x88]
	adds r5, r7, #0
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r5, r5, r6
	mov r8, r5
	ldr r0, _080EB85C @ =0x0000054F
	adds r7, r7, r0
	mov sb, r7
	ldr r1, [sp, #0x10]
	ldr r2, _080EB860 @ =0x0000054C
	adds r1, r1, r2
	mov sl, r1
	ldr r5, [sp, #0x10]
	adds r6, #5
	adds r5, r5, r6
	mov ip, r5
	subs r0, #1
	ldr r7, [sp, #0x10]
	adds r0, r7, r0
	str r0, [sp, #0x6c]
	ldr r1, _080EB864 @ =0x00000541
	adds r1, r7, r1
	str r1, [sp, #0x64]
	adds r2, #0x70
	adds r2, r7, r2
	str r2, [sp, #0x80]
	ldr r5, _080EB868 @ =0x00000542
	adds r5, r7, r5
	str r5, [sp, #0x68]
	ldr r1, _080EB86C @ =0x030046B8
	ldr r5, _080EB870 @ =0x000003FF
	movs r2, #3
	str r4, [sp, #0x8c]
_080EB7B6:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _080EB874 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	ldr r7, [sp, #0x8c]
	cmp r0, r7
	bne _080EB7D8
	adds r3, #1
	cmp r3, #3
	ble _080EB7B6
	adds r0, r4, #0
_080EB7D8:
	movs r3, #0
	ldr r1, [sp, #0x88]
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldr r0, [r2]
	mov r4, r8
	str r0, [r4]
	ldr r5, [sp, #0x70]
	ldrb r0, [r5]
	mov r6, sb
	strb r0, [r6]
	ldr r7, [sp, #0x3c]
	ldrb r0, [r7]
	mov r1, sl
	strb r0, [r1]
	ldr r2, [sp, #0x40]
	ldrb r0, [r2]
	mov r4, ip
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	ldr r6, [sp, #0x6c]
	strb r0, [r6]
	add r7, sp, #0x20
	ldrb r0, [r7]
	ldr r7, [sp, #0x64]
	strb r0, [r7]
	ldr r0, [sp, #0x80]
	ldr r2, [r0]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x50]
	strb r1, [r4]
	ldr r5, [sp, #0x48]
	strb r3, [r5]
	ldr r6, [sp, #0x70]
	strb r0, [r6]
	ldr r7, [sp, #0x78]
	str r2, [r7]
	movs r2, #0
	ldr r0, [sp, #0x74]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r5, [sp, #0x40]
	strb r1, [r5]
	ldr r6, [sp, #0x44]
	strb r2, [r6]
	ldr r7, [sp, #0x58]
	str r3, [r7]
	ldr r0, [sp, #0x4c]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x68]
	strb r0, [r1]
_080EB848:
	ldr r0, [sp, #0x10]
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x54]
	strh r0, [r2]
	b _080EB940
	.align 2, 0
_080EB858: .4byte 0x00000482
_080EB85C: .4byte 0x0000054F
_080EB860: .4byte 0x0000054C
_080EB864: .4byte 0x00000541
_080EB868: .4byte 0x00000542
_080EB86C: .4byte 0x030046B8
_080EB870: .4byte 0x000003FF
_080EB874: .4byte 0x0203B400
_080EB878:
	mov r8, sp
	ldr r6, _080EB8B4 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EB8B8
	adds r0, #4
	b _080EB8C2
	.align 2, 0
_080EB8B4: .4byte 0x030046A4
_080EB8B8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080EB8C2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r2, [sp, #0x10]
	ldr r3, _080EB8F8 @ =0x000004A4
	adds r0, r2, r3
	ldr r4, [r0]
	adds r5, r2, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _080EB8FC
	ldr r4, [sp, #0x10]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r4, r5
	b _080EB924
	.align 2, 0
_080EB8F8: .4byte 0x000004A4
_080EB8FC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _080EB91C
	cmp r0, #2
	beq _080EB918
	ldr r0, [sp, #0x10]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080EB918:
	movs r0, #1
	b _080EB92E
_080EB91C:
	ldr r6, [sp, #0x10]
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r0, r6, r7
_080EB924:
	ldr r1, _080EB950 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_080EB92E:
	cmp r0, #0
	bne _080EB940
	ldr r1, [sp, #0x10]
	ldr r2, _080EB954 @ =0x000005C4
	adds r0, r1, r2
	ldr r1, [r0]
	ldr r0, [sp, #0x10]
	bl _call_via_r1
_080EB940:
	movs r0, #2
	ldr r3, [sp, #0x7c]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #1
	bl _080EC406
	.align 2, 0
_080EB950: .4byte 0xFFFFFDFF
_080EB954: .4byte 0x000005C4
_080EB958:
	ldr r4, [sp, #0x10]
	ldrb r0, [r4, #5]
	adds r0, #0x20
	asrs r1, r0, #6
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bne _080EB96A
	b _080EBC14
_080EB96A:
	cmp r1, #1
	bgt _080EB974
	cmp r1, #0
	beq _080EB980
	b _080EBE88
_080EB974:
	cmp r1, #2
	beq _080EB980
	cmp r1, #3
	bne _080EB97E
	b _080EBC14
_080EB97E:
	b _080EBE88
_080EB980:
	ldr r5, [sp, #0x10]
	ldr r6, _080EB9B4 @ =0x00000256
	adds r4, r5, r6
	ldrh r1, [r4]
	ldr r5, _080EB9B8 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	subs r0, r1, r0
	mov r8, r0
	adds r7, r1, #0
	ldr r0, [sp, #0x10]
	movs r1, #0xa
	ldrsh r0, [r0, r1]
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	str r4, [sp, #0x84]
	cmp r0, #0
	beq _080EB9BC
	adds r0, #4
	b _080EB9C6
	.align 2, 0
_080EB9B4: .4byte 0x00000256
_080EB9B8: .4byte 0x030046A4
_080EB9BC:
	ldr r0, [r5]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080EB9C6:
	ldrb r0, [r0]
	lsrs r4, r0, #4
	ldr r2, _080EB9F0 @ =0x030046A4
	mov sl, r2
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r5, #6
	ldrsh r0, [r0, r5]
	adds r6, r1, #0
	muls r6, r0, r6
	str r6, [sp, #0x24]
	cmp r7, r8
	bge _080EBA5C
	adds r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _080EB9FC
	.align 2, 0
_080EB9F0: .4byte 0x030046A4
_080EB9F4:
	cmp r5, r8
	beq _080EBA58
	adds r5, #1
	adds r6, #1
_080EB9FC:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _080EBA1C
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EB9F4
_080EBA1C:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r7, r0
	b _080EBA3A
_080EBA2A:
	cmp r5, r8
	beq _080EBA58
	ldr r0, _080EBA54 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_080EBA3A:
	ldr r0, [sp, #0x24]
	cmp r0, r5
	ble _080EBABE
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBA2A
	b _080EBABE
	.align 2, 0
_080EBA54: .4byte 0x030046A4
_080EBA58:
	movs r0, #1
	b _080EBAC0
_080EBA5C:
	subs r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _080EBA70
_080EBA68:
	cmp r5, r8
	beq _080EBA58
	subs r5, #1
	subs r6, #1
_080EBA70:
	cmp r6, #0
	blt _080EBA86
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBA68
_080EBA86:
	ldr r0, _080EBA94 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r7, r0
	b _080EBAA8
	.align 2, 0
_080EBA94: .4byte 0x030046A4
_080EBA98:
	cmp r5, r8
	beq _080EBA58
	ldr r0, _080EBACC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_080EBAA8:
	cmp r5, #0
	blt _080EBABE
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBA98
_080EBABE:
	movs r0, #0
_080EBAC0:
	cmp r0, #0
	beq _080EBAD0
	movs r3, #3
	str r3, [sp, #0x14]
	b _080EBE96
	.align 2, 0
_080EBACC: .4byte 0x030046A4
_080EBAD0:
	ldr r4, [sp, #0x84]
	ldrh r1, [r4]
	ldr r5, _080EBAFC @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r0, r0, r1
	mov r8, r0
	adds r4, r1, #0
	ldr r7, [sp, #0x10]
	movs r0, #0xa
	ldrsh r7, [r7, r0]
	mov sb, r7
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EBB00
	adds r0, #4
	b _080EBB0A
	.align 2, 0
_080EBAFC: .4byte 0x030046A4
_080EBB00:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080EBB0A:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	ldr r1, _080EBB34 @ =0x030046A4
	mov sl, r1
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #6
	ldrsh r0, [r0, r3]
	adds r5, r1, #0
	muls r5, r0, r5
	str r5, [sp, #0x28]
	cmp r4, r8
	bge _080EBBA0
	adds r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _080EBB40
	.align 2, 0
_080EBB34: .4byte 0x030046A4
_080EBB38:
	cmp r5, r8
	beq _080EBB9C
	adds r5, #1
	adds r6, #1
_080EBB40:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _080EBB60
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBB38
_080EBB60:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r4, r0
	b _080EBB7E
_080EBB6E:
	cmp r5, r8
	beq _080EBB9C
	ldr r0, _080EBB98 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_080EBB7E:
	ldr r0, [sp, #0x28]
	cmp r0, r5
	ble _080EBC02
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBB6E
	b _080EBC02
	.align 2, 0
_080EBB98: .4byte 0x030046A4
_080EBB9C:
	movs r0, #1
	b _080EBC04
_080EBBA0:
	subs r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _080EBBB4
_080EBBAC:
	cmp r5, r8
	beq _080EBB9C
	subs r5, #1
	subs r6, #1
_080EBBB4:
	cmp r6, #0
	blt _080EBBCA
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBBAC
_080EBBCA:
	ldr r0, _080EBBD8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _080EBBEC
	.align 2, 0
_080EBBD8: .4byte 0x030046A4
_080EBBDC:
	cmp r5, r8
	beq _080EBB9C
	ldr r0, _080EBC10 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_080EBBEC:
	cmp r5, #0
	blt _080EBC02
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBBDC
_080EBC02:
	movs r0, #0
_080EBC04:
	cmp r0, #0
	bne _080EBC0A
	b _080EBE88
_080EBC0A:
	movs r3, #1
	str r3, [sp, #0x14]
	b _080EBE96
	.align 2, 0
_080EBC10: .4byte 0x030046A4
_080EBC14:
	ldr r5, [sp, #0x10]
	ldr r6, _080EBC3C @ =0x00000256
	adds r4, r5, r6
	ldrh r0, [r4]
	adds r7, r0, #1
	mov r8, r7
	adds r7, r0, #0
	movs r1, #0xa
	ldrsh r0, [r5, r1]
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	str r4, [sp, #0x84]
	cmp r0, #0
	beq _080EBC40
	adds r0, #4
	b _080EBC4C
	.align 2, 0
_080EBC3C: .4byte 0x00000256
_080EBC40:
	ldr r2, _080EBC78 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EBC4C:
	ldrb r0, [r0]
	lsrs r4, r0, #4
	ldr r2, _080EBC78 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r5, #6
	ldrsh r0, [r0, r5]
	adds r6, r1, #0
	muls r6, r0, r6
	str r6, [sp, #0x2c]
	cmp r7, r8
	bge _080EBCE4
	adds r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	ldr r0, _080EBC78 @ =0x030046A4
	mov sl, r0
	b _080EBC84
	.align 2, 0
_080EBC78: .4byte 0x030046A4
_080EBC7C:
	cmp r5, r8
	beq _080EBCE0
	adds r5, #1
	adds r6, #1
_080EBC84:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _080EBCA4
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBC7C
_080EBCA4:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r7, r0
	b _080EBCC2
_080EBCB2:
	cmp r5, r8
	beq _080EBCE0
	ldr r0, _080EBCDC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_080EBCC2:
	ldr r0, [sp, #0x2c]
	cmp r0, r5
	ble _080EBD46
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBCB2
	b _080EBD46
	.align 2, 0
_080EBCDC: .4byte 0x030046A4
_080EBCE0:
	movs r0, #1
	b _080EBD48
_080EBCE4:
	subs r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _080EBCF8
_080EBCF0:
	cmp r5, r8
	beq _080EBCE0
	subs r5, #1
	subs r6, #1
_080EBCF8:
	cmp r6, #0
	blt _080EBD0E
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBCF0
_080EBD0E:
	ldr r0, _080EBD1C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r7, r0
	b _080EBD30
	.align 2, 0
_080EBD1C: .4byte 0x030046A4
_080EBD20:
	cmp r5, r8
	beq _080EBCE0
	ldr r0, _080EBD54 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_080EBD30:
	cmp r5, #0
	blt _080EBD46
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBD20
_080EBD46:
	movs r0, #0
_080EBD48:
	cmp r0, #0
	beq _080EBD58
	movs r3, #0
	str r3, [sp, #0x14]
	b _080EBE96
	.align 2, 0
_080EBD54: .4byte 0x030046A4
_080EBD58:
	ldr r4, [sp, #0x84]
	ldrh r0, [r4]
	subs r5, r0, #1
	mov r8, r5
	adds r4, r0, #0
	ldr r6, [sp, #0x10]
	movs r7, #0xa
	ldrsh r6, [r6, r7]
	mov sb, r6
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EBD78
	adds r0, #4
	b _080EBD84
_080EBD78:
	ldr r2, _080EBDB0 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EBD84:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	ldr r1, _080EBDB0 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #6
	ldrsh r0, [r0, r3]
	adds r5, r1, #0
	muls r5, r0, r5
	str r5, [sp, #0x30]
	cmp r4, r8
	bge _080EBE1C
	adds r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	ldr r0, _080EBDB0 @ =0x030046A4
	mov sl, r0
	b _080EBDBC
	.align 2, 0
_080EBDB0: .4byte 0x030046A4
_080EBDB4:
	cmp r5, r8
	beq _080EBE18
	adds r5, #1
	adds r6, #1
_080EBDBC:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _080EBDDC
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBDB4
_080EBDDC:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r4, r0
	b _080EBDFA
_080EBDEA:
	cmp r5, r8
	beq _080EBE18
	ldr r0, _080EBE14 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_080EBDFA:
	ldr r0, [sp, #0x30]
	cmp r0, r5
	ble _080EBE7E
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBDEA
	b _080EBE7E
	.align 2, 0
_080EBE14: .4byte 0x030046A4
_080EBE18:
	movs r0, #1
	b _080EBE80
_080EBE1C:
	subs r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _080EBE30
_080EBE28:
	cmp r5, r8
	beq _080EBE18
	subs r5, #1
	subs r6, #1
_080EBE30:
	cmp r6, #0
	blt _080EBE46
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBE28
_080EBE46:
	ldr r0, _080EBE54 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _080EBE68
	.align 2, 0
_080EBE54: .4byte 0x030046A4
_080EBE58:
	cmp r5, r8
	beq _080EBE18
	ldr r0, _080EBEB0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_080EBE68:
	cmp r5, #0
	blt _080EBE7E
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EBE58
_080EBE7E:
	movs r0, #0
_080EBE80:
	movs r3, #2
	str r3, [sp, #0x14]
	cmp r0, #0
	bne _080EBE8E
_080EBE88:
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp, #0x14]
_080EBE8E:
	ldr r5, [sp, #0x14]
	cmp r5, #0
	bge _080EBE96
	b _080EC404
_080EBE96:
	ldr r6, [sp, #0x10]
	ldr r7, _080EBEB4 @ =0x00000256
	adds r0, r6, r7
	ldrh r0, [r0]
	mov r8, r0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EBEB8
	adds r0, #4
	b _080EBEC6
	.align 2, 0
_080EBEB0: .4byte 0x030046A4
_080EBEB4: .4byte 0x00000256
_080EBEB8:
	ldr r2, _080EBEF4 @ =0x030046A4
	ldr r1, [r2]
	mov r3, r8
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EBEC6:
	ldrb r0, [r0]
	movs r4, #0xf
	mov sb, r4
	mov r5, sb
	ands r5, r0
	mov sb, r5
	ldr r6, _080EBEF4 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	movs r2, #6
	ldrsh r0, [r0, r2]
	adds r5, r1, #0
	muls r5, r0, r5
	ldr r3, [sp, #0x14]
	cmp r3, #1
	beq _080EBF90
	cmp r3, #1
	bgt _080EBEF8
	cmp r3, #0
	beq _080EBF08
	b _080EC12E
	.align 2, 0
_080EBEF4: .4byte 0x030046A4
_080EBEF8:
	ldr r4, [sp, #0x14]
	cmp r4, #2
	bne _080EBF00
	b _080EC010
_080EBF00:
	cmp r4, #3
	bne _080EBF06
	b _080EC0B4
_080EBF06:
	b _080EC12E
_080EBF08:
	mov r4, r8
	adds r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	ldr r6, _080EBF3C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	cmp r5, r0
	blt _080EBF24
	b _080EC12E
_080EBF24:
	adds r7, r6, #0
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_080EBF2C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EBF40
	adds r0, #4
	b _080EBF46
	.align 2, 0
_080EBF3C: .4byte 0x030046A4
_080EBF40:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_080EBF46:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _080EBF70
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EBF60
	adds r0, #4
	b _080EBF66
_080EBF60:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_080EBF66:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080EBF74
_080EBF70:
	movs r0, #0
	b _080EBF76
_080EBF74:
	movs r0, #1
_080EBF76:
	cmp r0, #0
	bne _080EBF7C
	b _080EC086
_080EBF7C:
	adds r6, #4
	adds r4, #1
	adds r5, #1
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _080EBF2C
	b _080EC12E
_080EBF90:
	mov r2, r8
	adds r4, r2, r1
	cmp r5, r4
	bgt _080EBF9A
	b _080EC12E
_080EBF9A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EBFAA
	adds r0, #4
	b _080EBFB6
_080EBFAA:
	ldr r0, _080EBFD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EBFB6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _080EBFEA
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EBFD4
	adds r0, #4
	b _080EBFE0
	.align 2, 0
_080EBFD0: .4byte 0x030046A4
_080EBFD4:
	ldr r2, _080EBFF0 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EBFE0:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080EBFF4
_080EBFEA:
	movs r0, #0
	b _080EBFF6
	.align 2, 0
_080EBFF0: .4byte 0x030046A4
_080EBFF4:
	movs r0, #1
_080EBFF6:
	cmp r0, #0
	beq _080EC08A
	ldr r3, _080EC00C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r4, r4, r0
	cmp r5, r4
	bgt _080EBF9A
	b _080EC12E
	.align 2, 0
_080EC00C: .4byte 0x030046A4
_080EC010:
	mov r4, r8
	subs r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	cmp r5, #0
	bge _080EC022
	b _080EC12E
_080EC022:
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
	ldr r7, _080EC03C @ =0x030046A4
_080EC02A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EC040
	adds r0, #4
	b _080EC046
	.align 2, 0
_080EC03C: .4byte 0x030046A4
_080EC040:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_080EC046:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _080EC070
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EC060
	adds r0, #4
	b _080EC066
_080EC060:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_080EC066:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080EC074
_080EC070:
	movs r0, #0
	b _080EC076
_080EC074:
	movs r0, #1
_080EC076:
	cmp r0, #0
	beq _080EC09C
	subs r6, #4
	subs r4, #1
	subs r5, #1
	cmp r5, #0
	bge _080EC02A
	b _080EC12E
_080EC086:
	subs r5, r4, #1
	b _080EC130
_080EC08A:
	ldr r7, _080EC098 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _080EC130
	.align 2, 0
_080EC098: .4byte 0x030046A4
_080EC09C:
	adds r5, r4, #1
	b _080EC130
_080EC0A0:
	ldr r2, _080EC0B0 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	adds r5, r4, r0
	b _080EC130
	.align 2, 0
_080EC0B0: .4byte 0x030046A4
_080EC0B4:
	mov r5, r8
	subs r4, r5, r1
	cmp r4, #0
	blt _080EC12E
_080EC0BC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EC0CC
	adds r0, #4
	b _080EC0D8
_080EC0CC:
	ldr r0, _080EC0F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EC0D8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _080EC10E
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EC0F8
	adds r0, #4
	b _080EC104
	.align 2, 0
_080EC0F4: .4byte 0x030046A4
_080EC0F8:
	ldr r2, _080EC114 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EC104:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _080EC118
_080EC10E:
	movs r0, #0
	b _080EC11A
	.align 2, 0
_080EC114: .4byte 0x030046A4
_080EC118:
	movs r0, #1
_080EC11A:
	cmp r0, #0
	beq _080EC0A0
	ldr r6, _080EC174 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	subs r4, r4, r0
	cmp r4, #0
	bge _080EC0BC
_080EC12E:
	mov r5, r8
_080EC130:
	cmp r5, #0
	bne _080EC136
	b _080EC404
_080EC136:
	ldr r1, [sp, #0x10]
	ldr r2, _080EC178 @ =0x00000256
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r5, r0
	bne _080EC144
	b _080EC404
_080EC144:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r3, [sp, #0x10]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r3, r4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x60]
	adds r3, #8
	str r3, [sp, #0x34]
	add r7, sp, #8
	cmp r0, #0
	beq _080EC162
	b _080EC2AE
_080EC162:
	movs r1, #4
	ldr r6, [sp, #0x7c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080EC17C
	movs r0, #1
	b _080EC17E
	.align 2, 0
_080EC174: .4byte 0x030046A4
_080EC178: .4byte 0x00000256
_080EC17C:
	movs r0, #0
_080EC17E:
	ldr r7, [sp, #0x10]
	adds r7, #8
	str r7, [sp, #0x34]
	add r7, sp, #8
	cmp r0, #0
	beq _080EC18C
	b _080EC2AE
_080EC18C:
	movs r2, #0
	ldr r1, _080EC2EC @ =0x0000046D
	ldr r0, [sp, #0x10]
	adds r1, r0, r1
	str r1, [sp, #0x50]
	ldr r3, _080EC2F0 @ =0x0000046B
	adds r3, r0, r3
	str r3, [sp, #0x48]
	ldr r4, _080EC2F4 @ =0x00000553
	adds r4, r0, r4
	str r4, [sp, #0x70]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r0, r6
	str r6, [sp, #0x78]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r0, r1
	str r1, [sp, #0x74]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r0, r3
	str r3, [sp, #0x3c]
	ldr r4, _080EC2F8 @ =0x00000469
	adds r4, r0, r4
	str r4, [sp, #0x40]
	ldr r6, _080EC2FC @ =0x0000046A
	adds r6, r0, r6
	str r6, [sp, #0x44]
	ldr r1, _080EC300 @ =0x00000484
	adds r1, r0, r1
	str r1, [sp, #0x58]
	ldr r3, _080EC304 @ =0x0000046C
	adds r3, r0, r3
	str r3, [sp, #0x4c]
	ldrb r4, [r0, #5]
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r6, r0, r6
	str r6, [sp, #0x88]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r0, r1
	mov r8, r0
	ldr r3, [sp, #0x10]
	ldr r6, _080EC308 @ =0x0000054F
	adds r3, r3, r6
	mov sb, r3
	ldr r0, [sp, #0x10]
	adds r1, #4
	adds r0, r0, r1
	mov sl, r0
	ldr r3, [sp, #0x10]
	subs r6, #2
	adds r3, r3, r6
	mov ip, r3
	adds r1, #2
	ldr r0, [sp, #0x10]
	adds r1, r0, r1
	str r1, [sp, #0x6c]
	ldr r3, _080EC30C @ =0x00000541
	adds r3, r0, r3
	str r3, [sp, #0x64]
	adds r6, #0x6f
	adds r6, r0, r6
	str r6, [sp, #0x80]
	ldr r1, _080EC310 @ =0x00000542
	adds r1, r0, r1
	str r1, [sp, #0x68]
	ldr r1, _080EC314 @ =0x030046B8
	adds r3, r4, #0
_080EC21A:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _080EC318 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _080EC31C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r3
	bne _080EC23E
	adds r2, #1
	cmp r2, #3
	ble _080EC21A
	adds r0, r4, #0
_080EC23E:
	movs r3, #0
	ldr r1, [sp, #0x88]
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldr r0, [r2]
	mov r4, r8
	str r0, [r4]
	ldr r6, [sp, #0x70]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x3c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r6, [sp, #0x40]
	ldrb r0, [r6]
	mov r1, ip
	strb r0, [r1]
	ldr r2, [sp, #0x44]
	ldrb r0, [r2]
	ldr r4, [sp, #0x6c]
	strb r0, [r4]
	mov r6, sp
	ldrb r0, [r6, #0x14]
	ldr r6, [sp, #0x64]
	strb r0, [r6]
	ldr r1, [sp, #0x80]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x50]
	strb r1, [r4]
	ldr r6, [sp, #0x48]
	strb r3, [r6]
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r6, [sp, #0x78]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x74]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r6, [sp, #0x40]
	strb r1, [r6]
	ldr r0, [sp, #0x44]
	strb r2, [r0]
	ldr r2, [sp, #0x58]
	str r3, [r2]
	ldr r3, [sp, #0x4c]
	strb r1, [r3]
	movs r0, #2
	ldr r4, [sp, #0x68]
	strb r0, [r4]
_080EC2AE:
	mov r8, r7
	ldr r6, _080EC320 @ =0x030046A4
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
	adds r6, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #8
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EC324
	adds r0, #4
	b _080EC330
	.align 2, 0
_080EC2EC: .4byte 0x0000046D
_080EC2F0: .4byte 0x0000046B
_080EC2F4: .4byte 0x00000553
_080EC2F8: .4byte 0x00000469
_080EC2FC: .4byte 0x0000046A
_080EC300: .4byte 0x00000484
_080EC304: .4byte 0x0000046C
_080EC308: .4byte 0x0000054F
_080EC30C: .4byte 0x00000541
_080EC310: .4byte 0x00000542
_080EC314: .4byte 0x030046B8
_080EC318: .4byte 0x000003FF
_080EC31C: .4byte 0x0203B400
_080EC320: .4byte 0x030046A4
_080EC324:
	ldr r4, _080EC368 @ =0x030046A4
	ldr r0, [r4]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080EC330:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r5, r8
	strh r0, [r5, #2]
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	ldr r6, [sp, #0x10]
	ldrh r0, [r6, #0xa]
	strh r0, [r7, #2]
	ldr r1, _080EC36C @ =0x000004A4
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x34]
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080EC374
	ldr r0, _080EC370 @ =0xFFFFFDFF
	ldr r2, [sp, #0x60]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080EC39E
	.align 2, 0
_080EC368: .4byte 0x030046A4
_080EC36C: .4byte 0x000004A4
_080EC370: .4byte 0xFFFFFDFF
_080EC374:
	adds r0, r4, #0
	ldr r1, [sp, #0x34]
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080EC394
	cmp r0, #2
	beq _080EC390
	ldr r0, [sp, #0x10]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080EC390:
	movs r0, #1
	b _080EC3A0
_080EC394:
	ldr r0, _080EC3B4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x60]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_080EC39E:
	movs r0, #0
_080EC3A0:
	adds r4, r0, #0
	cmp r4, #0
	beq _080EC3B8
	movs r0, #2
	ldr r5, [sp, #0x7c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r0, #1
	b _080EC406
	.align 2, 0
_080EC3B4: .4byte 0xFFFFFDFF
_080EC3B8:
	ldr r1, _080EC418 @ =FUN_080e48d0
	ldr r5, [sp, #0x10]
	ldr r6, _080EC41C @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	ldr r7, _080EC420 @ =0x0000046B
	adds r0, r5, r7
	strb r4, [r0]
	ldr r2, _080EC424 @ =0x00000553
	adds r0, r5, r2
	strb r4, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _080EC428 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _080EC42C @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _080EC430 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	ldr r4, _080EC434 @ =0x0000046C
	adds r0, r5, r4
	strb r3, [r0]
_080EC404:
	movs r0, #0
_080EC406:
	add sp, #0x90
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080EC418: .4byte FUN_080e48d0
_080EC41C: .4byte 0x0000046D
_080EC420: .4byte 0x0000046B
_080EC424: .4byte 0x00000553
_080EC428: .4byte 0x00000469
_080EC42C: .4byte 0x0000046A
_080EC430: .4byte 0x00000484
_080EC434: .4byte 0x0000046C
