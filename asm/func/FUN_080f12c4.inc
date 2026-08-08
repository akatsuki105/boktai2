	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x70
	adds r7, r0, #0
	ldr r0, _080F12E4 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F12E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F12EA
	.align 2, 0
_080F12E4: .4byte 0x0000046C
_080F12E8:
	movs r0, #0
_080F12EA:
	cmp r0, #0
	beq _080F1338
	ldr r1, _080F147C @ =0x000005A4
	adds r0, r7, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _080F1480 @ =0x0000046D
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
	ldr r5, _080F1484 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _080F1488 @ =0x00000553
	adds r0, r7, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, _080F148C @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_080F1338:
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F134E
	b _080F19BC
_080F134E:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0
	beq _080F1360
	b _080F19BC
_080F1360:
	ldr r0, _080F1490 @ =0x00000484
	adds r1, r7, r0
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _080F136C
	b _080F19B8
_080F136C:
	ldr r1, _080F1494 @ =0x00000222
	adds r1, r7, r1
	str r1, [sp, #8]
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r1, [r1]
	ands r0, r1
	movs r4, #0
	ldr r2, [sp, #8]
	strh r0, [r2]
	ldr r1, _080F1498 @ =FUN_080e6794
	movs r0, #0xe
	ldr r3, _080F1480 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0xc]
	movs r5, #1
	strb r5, [r3]
	ldr r6, _080F1484 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x10]
	strb r4, [r6]
	ldr r2, _080F1488 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x14]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x18]
	str r1, [r3]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x1c]
	mov r0, r8
	strh r0, [r6]
	ldr r1, _080F149C @ =0x00000543
	adds r0, r7, r1
	ldrb r3, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r6, #0xc
	mov sb, r6
	movs r0, #0xab
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r6, _080F14A0 @ =0x00000554
	adds r0, r7, r6
	str r3, [r0]
	str r2, [r1]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _080F14A4 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _080F14A8 @ =0x00000552
	adds r0, r7, r3
	mov r6, sb
	strb r6, [r0]
	movs r0, #3
	subs r1, #0xe8
	adds r1, r1, r7
	mov ip, r1
	strb r0, [r1]
	subs r2, #0xe8
	adds r2, r2, r7
	mov sl, r2
	strb r5, [r2]
	subs r3, #0xe8
	adds r3, r3, r7
	mov sb, r3
	strb r4, [r3]
	ldr r4, _080F1490 @ =0x00000484
	adds r6, r7, r4
	mov r0, r8
	str r0, [r6]
	ldr r1, _080F14AC @ =0x0000046C
	adds r3, r7, r1
	strb r5, [r3]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r5, [r4]
	str r5, [sp, #0x20]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x3c]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x40]
	ldr r3, [sp, #0x10]
	str r3, [sp, #0x38]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x68]
	ldr r3, [sp, #0x18]
	str r3, [sp, #0x6c]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x4c]
	ldr r3, [sp, #8]
	str r3, [sp, #0x50]
	mov r0, ip
	str r0, [sp, #0x2c]
	mov r3, sl
	str r3, [sp, #0x30]
	mov r0, sb
	str r0, [sp, #0x34]
	str r6, [sp, #0x48]
	adds r6, r4, #0
	mov r8, r2
	cmp r5, #0
	blt _080F1478
	cmp r1, #0
	blt _080F1478
	ldr r0, _080F14B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _080F1478
	ldr r0, _080F14B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F14B8
_080F1478:
	movs r5, #0
	b _080F14C6
	.align 2, 0
_080F147C: .4byte 0x000005A4
_080F1480: .4byte 0x0000046D
_080F1484: .4byte 0x0000046B
_080F1488: .4byte 0x00000553
_080F148C: .4byte 0xFFFFFDFF
_080F1490: .4byte 0x00000484
_080F1494: .4byte 0x00000222
_080F1498: .4byte FUN_080e6794
_080F149C: .4byte 0x00000543
_080F14A0: .4byte 0x00000554
_080F14A4: .4byte 0x00000551
_080F14A8: .4byte 0x00000552
_080F14AC: .4byte 0x0000046C
_080F14B0: .4byte 0x030046A8
_080F14B4: .4byte 0x030046AC
_080F14B8:
	ldr r0, _080F14D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_080F14C6:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F14DC
	adds r0, #4
	b _080F14E8
	.align 2, 0
_080F14D8: .4byte 0x030046A4
_080F14DC:
	ldr r0, _080F14FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F14E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080F1500
	cmp r2, #2
	beq _080F1506
	b _080F150C
	.align 2, 0
_080F14FC: .4byte 0x030046A4
_080F1500:
	ldr r2, [sp, #0x20]
	ldrb r0, [r2, #4]
	b _080F150A
_080F1506:
	ldr r3, [sp, #0x20]
	ldrb r0, [r3]
_080F150A:
	subs r1, r1, r0
_080F150C:
	ldr r4, [sp, #0x20]
	strh r1, [r4, #2]
	ldr r0, _080F1524 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F1528
	movs r0, #1
	b _080F152A
	.align 2, 0
_080F1524: .4byte 0x030047A4
_080F1528:
	movs r0, #0
_080F152A:
	cmp r0, #0
	beq _080F1568
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _080F154A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _080F1546
	adds r2, r0, #0
_080F1546:
	cmp r2, #0
	bge _080F1554
_080F154A:
	ldr r6, _080F1550 @ =0x000005C4
	adds r0, r7, r6
	b _080F19A4
	.align 2, 0
_080F1550: .4byte 0x000005C4
_080F1554:
	ldr r1, _080F1564 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _080F15B0
	.align 2, 0
_080F1564: .4byte 0x03002BE0
_080F1568:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080F1594
	cmp r1, #0
	blt _080F1594
	ldr r0, _080F1598 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F1594
	ldr r0, _080F159C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F15A0
_080F1594:
	movs r5, #0
	b _080F15AE
	.align 2, 0
_080F1598: .4byte 0x030046A8
_080F159C: .4byte 0x030046AC
_080F15A0:
	ldr r0, _080F1644 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080F15AE:
	movs r2, #0
_080F15B0:
	ldr r3, _080F1648 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _080F15D0
	ldr r1, _080F164C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080F15D0
	b _080F18E8
_080F15D0:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	mov sb, r2
	cmp r3, #0
	beq _080F15EA
	b _080F19BC
_080F15EA:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0x50]
	ldrh r1, [r5]
	ands r0, r1
	movs r5, #0
	ldr r1, [sp, #0x50]
	strh r0, [r1]
	movs r1, #0x80
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080F1650
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r6, [sp, #0x40]
	strb r2, [r6]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r6, [sp, #0x68]
	strb r0, [r6]
	ldr r0, [sp, #0x6c]
	str r1, [r0]
	ldr r1, [sp, #0x4c]
	strh r3, [r1]
	movs r0, #0xc
	ldr r4, [sp, #0x2c]
	strb r5, [r4]
	ldr r6, [sp, #0x30]
	strb r5, [r6]
	ldr r1, [sp, #0x34]
	strb r0, [r1]
	ldr r4, [sp, #0x48]
	str r3, [r4]
	ldr r5, [sp, #0x3c]
	strb r2, [r5]
	b _080F179E
	.align 2, 0
_080F1644: .4byte 0x030046A4
_080F1648: .4byte 0x00000256
_080F164C: .4byte 0x03002BE0
_080F1650:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, [sp, #0x40]
	strb r0, [r3]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r3, [sp, #0x68]
	strb r0, [r3]
	ldr r4, [sp, #0x6c]
	str r1, [r4]
	ldr r1, [sp, #0x4c]
	strh r2, [r1]
	movs r1, #5
	ldr r3, [sp, #0x2c]
	strb r5, [r3]
	ldr r4, [sp, #0x30]
	strb r5, [r4]
	ldr r5, [sp, #0x34]
	strb r1, [r5]
	ldr r1, [sp, #0x48]
	str r2, [r1]
	ldr r2, [sp, #0x3c]
	strb r0, [r2]
	ldr r4, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r4]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r4, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080F16B4
	cmp r1, #0
	blt _080F16B4
	ldr r0, _080F16B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F16B4
	ldr r0, _080F16BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F16C0
_080F16B4:
	movs r5, #0
	b _080F16CE
	.align 2, 0
_080F16B8: .4byte 0x030046A8
_080F16BC: .4byte 0x030046AC
_080F16C0:
	ldr r0, _080F16E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080F16CE:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F16E4
	adds r0, #4
	b _080F16F0
	.align 2, 0
_080F16E0: .4byte 0x030046A4
_080F16E4:
	ldr r0, _080F1704 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F16F0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080F1708
	cmp r2, #2
	beq _080F170C
	b _080F1710
	.align 2, 0
_080F1704: .4byte 0x030046A4
_080F1708:
	ldrb r0, [r4, #4]
	b _080F170E
_080F170C:
	ldrb r0, [r4]
_080F170E:
	subs r1, r1, r0
_080F1710:
	strh r1, [r4, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080F1738
	cmp r1, #0
	blt _080F1738
	ldr r0, _080F173C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080F1738
	ldr r0, _080F1740 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080F1744
_080F1738:
	movs r5, #0
	b _080F1752
	.align 2, 0
_080F173C: .4byte 0x030046A8
_080F1740: .4byte 0x030046AC
_080F1744:
	ldr r0, _080F1764 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080F1752:
	ldr r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080F1768
	adds r0, #4
	b _080F1774
	.align 2, 0
_080F1764: .4byte 0x030046A4
_080F1768:
	ldr r0, _080F1788 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080F1774:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080F178C
	cmp r3, #2
	beq _080F1790
	b _080F1794
	.align 2, 0
_080F1788: .4byte 0x030046A4
_080F178C:
	ldrb r0, [r4, #4]
	b _080F1792
_080F1790:
	ldrb r0, [r4]
_080F1792:
	subs r2, r2, r0
_080F1794:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_080F179E:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sb
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _080F17C8 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x44]
	cmp r0, #0
	bne _080F18AC
	movs r1, #4
	ldr r2, [sp, #0x50]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080F17CC
	movs r0, #1
	b _080F17CE
	.align 2, 0
_080F17C8: .4byte 0x00000482
_080F17CC:
	movs r0, #0
_080F17CE:
	ldr r3, _080F18BC @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x44]
	cmp r0, #0
	bne _080F18AC
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _080F18C0 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _080F18C4 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x5c]
	ldr r1, _080F18C8 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x60]
	ldr r2, _080F18CC @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x64]
	ldr r4, _080F18D0 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x54]
	ldr r5, _080F18D4 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x28]
	ldr r6, _080F18D8 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x58]
	ldr r6, _080F18DC @ =0x0203B400
	ldr r1, _080F18E0 @ =0x030046B8
	ldr r2, _080F18E4 @ =0x000003FF
	movs r5, #3
	mov r4, r8
_080F181E:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _080F183C
	adds r3, #1
	cmp r3, #3
	ble _080F181E
	mov r0, r8
_080F183C:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x6c]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x68]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [sp, #0x30]
	ldrb r0, [r4]
	ldr r5, [sp, #0x60]
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	ldrb r0, [r6]
	ldr r1, [sp, #0x64]
	strb r0, [r1]
	add r2, sp, #0x24
	ldrb r4, [r2]
	ldr r2, [sp, #0x54]
	strb r4, [r2]
	ldr r4, [sp, #0x28]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x40]
	strb r1, [r5]
	ldr r6, [sp, #0x38]
	strb r3, [r6]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r5, [sp, #0x6c]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x4c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
	ldr r5, [sp, #0x30]
	strb r1, [r5]
	ldr r6, [sp, #0x34]
	strb r2, [r6]
	ldr r0, [sp, #0x48]
	str r3, [r0]
	ldr r2, [sp, #0x3c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x58]
	strb r0, [r3]
_080F18AC:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x44]
	strh r0, [r4]
	b _080F19BC
	.align 2, 0
_080F18BC: .4byte 0x00000482
_080F18C0: .4byte 0x0000054F
_080F18C4: .4byte 0x0000054C
_080F18C8: .4byte 0x0000054D
_080F18CC: .4byte 0x0000054E
_080F18D0: .4byte 0x00000541
_080F18D4: .4byte 0x000005BC
_080F18D8: .4byte 0x00000542
_080F18DC: .4byte 0x0203B400
_080F18E0: .4byte 0x030046B8
_080F18E4: .4byte 0x000003FF
_080F18E8:
	mov sb, sp
	ldr r6, _080F1924 @ =0x030046A4
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
	bl FUN_08234224
	cmp r0, #0
	beq _080F1928
	adds r0, #4
	b _080F1932
	.align 2, 0
_080F1924: .4byte 0x030046A4
_080F1928:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080F1932:
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
	ldr r6, _080F1968 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _080F196C
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _080F1992
	.align 2, 0
_080F1968: .4byte 0x000004A4
_080F196C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _080F198C
	cmp r0, #2
	beq _080F1988
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080F1988:
	movs r0, #1
	b _080F199C
_080F198C:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_080F1992:
	ldr r1, _080F19B0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_080F199C:
	cmp r0, #0
	bne _080F19BC
	ldr r3, _080F19B4 @ =0x000005C4
	adds r0, r7, r3
_080F19A4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _080F19BC
	.align 2, 0
_080F19B0: .4byte 0xFFFFFDFF
_080F19B4: .4byte 0x000005C4
_080F19B8:
	adds r0, #1
	str r0, [r1]
_080F19BC:
	add sp, #0x70
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
