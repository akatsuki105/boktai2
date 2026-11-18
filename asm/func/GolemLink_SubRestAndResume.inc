	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	adds r7, r0, #0
	ldr r0, _081C1094 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C1098
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C109A
	.align 2, 0
_081C1094: .4byte 0x0000046C
_081C1098:
	movs r0, #0
_081C109A:
	cmp r0, #0
	beq _081C10CE
	ldr r4, _081C115C @ =GolemLink_StateCurledIdle
	movs r3, #0x2b
	ldr r2, _081C1160 @ =0x0000046D
	adds r1, r7, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r5, _081C1164 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _081C1168 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	adds r0, r7, r5
	strb r1, [r0]
_081C10CE:
	ldr r4, _081C1164 @ =0x0000046B
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C10DA
	b _081C1764
_081C10DA:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r3, _081C116C @ =Enemy_WaitPendingState
	movs r2, #0xe
	ldr r5, _081C1160 @ =0x0000046D
	adds r5, r5, r7
	mov r8, r5
	movs r1, #0
	movs r0, #1
	strb r0, [r5]
	adds r6, r7, r4
	strb r1, [r6]
	ldr r0, _081C1168 @ =0x00000553
	adds r5, r7, r0
	strb r2, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r4, r7, r2
	str r3, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	movs r2, #0
	mov sb, r2
	strh r1, [r3]
	movs r1, #0x80
	subs r0, #0x48
	adds r2, r7, r0
	ldrh r0, [r2]
	ands r0, r1
	mov r1, r8
	str r1, [sp, #0x24]
	str r6, [sp, #0x1c]
	str r5, [sp, #0x48]
	str r4, [sp, #0x4c]
	str r3, [sp, #0x30]
	str r2, [sp, #0x14]
	cmp r0, #0
	beq _081C1178
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x78
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r6, _081C1170 @ =0x00000554
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	ldr r3, _081C1174 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #6
	adds r0, r7, r5
	b _081C11A4
	.align 2, 0
_081C115C: .4byte GolemLink_StateCurledIdle
_081C1160: .4byte 0x0000046D
_081C1164: .4byte 0x0000046B
_081C1168: .4byte 0x00000553
_081C116C: .4byte Enemy_WaitPendingState
_081C1170: .4byte 0x00000554
_081C1174: .4byte 0x00000551
_081C1178:
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x78
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _081C1244 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	subs r6, #0x50
	adds r0, r7, r6
	mov r1, sb
	strb r1, [r0]
	ldr r2, _081C1248 @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _081C124C @ =0x00000552
	adds r0, r7, r3
_081C11A4:
	strb r4, [r0]
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r5, _081C1250 @ =0x00000482
	adds r1, r7, r5
	movs r2, #0
	movs r3, #0
	movs r0, #2
	strh r0, [r1]
	movs r0, #3
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sb, r6
	strb r0, [r6]
	ldr r0, _081C1254 @ =0x00000469
	adds r0, r0, r7
	mov r8, r0
	strb r1, [r0]
	ldr r4, _081C1258 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x54]
	strb r2, [r4]
	ldr r6, _081C125C @ =0x00000484
	adds r5, r7, r6
	str r3, [r5]
	ldr r0, _081C1260 @ =0x0000046C
	adds r3, r7, r0
	strb r1, [r3]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r2, [r4]
	mov sl, r2
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	mov r6, sl
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x20]
	mov r0, sb
	str r0, [sp, #0xc]
	mov r3, r8
	str r3, [sp, #0x10]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0x18]
	str r5, [sp, #0x2c]
	adds r6, r4, #0
	mov r8, r2
	mov r0, ip
	cmp r0, #0
	blt _081C123E
	cmp r1, #0
	blt _081C123E
	ldr r0, _081C1264 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081C123E
	ldr r0, _081C1268 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C126C
_081C123E:
	movs r4, #0
	b _081C127C
	.align 2, 0
_081C1244: .4byte 0x00000554
_081C1248: .4byte 0x00000551
_081C124C: .4byte 0x00000552
_081C1250: .4byte 0x00000482
_081C1254: .4byte 0x00000469
_081C1258: .4byte 0x0000046A
_081C125C: .4byte 0x00000484
_081C1260: .4byte 0x0000046C
_081C1264: .4byte 0x030046A8
_081C1268: .4byte 0x030046AC
_081C126C:
	ldr r0, _081C128C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_081C127C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C1290
	adds r0, #4
	b _081C129C
	.align 2, 0
_081C128C: .4byte 0x030046A4
_081C1290:
	ldr r0, _081C12B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C129C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C12B4
	cmp r2, #2
	beq _081C12BA
	b _081C12C0
	.align 2, 0
_081C12B0: .4byte 0x030046A4
_081C12B4:
	mov r2, sl
	ldrb r0, [r2, #4]
	b _081C12BE
_081C12BA:
	mov r3, sl
	ldrb r0, [r3]
_081C12BE:
	subs r1, r1, r0
_081C12C0:
	mov r4, sl
	strh r1, [r4, #2]
	ldr r0, _081C12D8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C12DC
	movs r0, #1
	b _081C12DE
	.align 2, 0
_081C12D8: .4byte 0x030047A4
_081C12DC:
	movs r0, #0
_081C12DE:
	cmp r0, #0
	beq _081C131C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _081C12FE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C12FA
	adds r2, r0, #0
_081C12FA:
	cmp r2, #0
	bge _081C1308
_081C12FE:
	ldr r6, _081C1304 @ =0x000005C4
	adds r0, r7, r6
	b _081C175C
	.align 2, 0
_081C1304: .4byte 0x000005C4
_081C1308:
	ldr r1, _081C1318 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C1364
	.align 2, 0
_081C1318: .4byte 0x03002BE0
_081C131C:
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
	blt _081C1348
	cmp r1, #0
	blt _081C1348
	ldr r0, _081C134C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C1348
	ldr r0, _081C1350 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C1354
_081C1348:
	movs r5, #0
	b _081C1362
	.align 2, 0
_081C134C: .4byte 0x030046A8
_081C1350: .4byte 0x030046AC
_081C1354:
	ldr r0, _081C13F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C1362:
	movs r2, #0
_081C1364:
	ldr r3, _081C13F8 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C1384
	ldr r1, _081C13FC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C1384
	b _081C169C
_081C1384:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x14]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081C1398
	b _081C1764
_081C1398:
	ldr r5, _081C1400 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x14]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081C1404
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x24]
	strb r2, [r3]
	ldr r6, [sp, #0x1c]
	strb r5, [r6]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r6, [sp, #0x4c]
	str r1, [r6]
	ldr r0, [sp, #0x30]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0xc]
	strb r5, [r1]
	ldr r3, [sp, #0x10]
	strb r5, [r3]
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r6, [sp, #0x2c]
	str r4, [r6]
	ldr r0, [sp, #0x20]
	strb r2, [r0]
	b _081C1552
	.align 2, 0
_081C13F4: .4byte 0x030046A4
_081C13F8: .4byte 0x00000256
_081C13FC: .4byte 0x03002BE0
_081C1400: .4byte 0x00000222
_081C1404:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x1c]
	strb r5, [r4]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	str r1, [r4]
	ldr r1, [sp, #0x30]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0xc]
	strb r5, [r2]
	ldr r4, [sp, #0x10]
	strb r5, [r4]
	ldr r5, [sp, #0x18]
	strb r1, [r5]
	ldr r1, [sp, #0x2c]
	str r3, [r1]
	ldr r2, [sp, #0x20]
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
	blt _081C1468
	cmp r1, #0
	blt _081C1468
	ldr r0, _081C146C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C1468
	ldr r0, _081C1470 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C1474
_081C1468:
	movs r4, #0
	b _081C1482
	.align 2, 0
_081C146C: .4byte 0x030046A8
_081C1470: .4byte 0x030046AC
_081C1474:
	ldr r0, _081C1494 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C1482:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C1498
	adds r0, #4
	b _081C14A4
	.align 2, 0
_081C1494: .4byte 0x030046A4
_081C1498:
	ldr r0, _081C14B8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C14A4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C14BC
	cmp r2, #2
	beq _081C14C0
	b _081C14C4
	.align 2, 0
_081C14B8: .4byte 0x030046A4
_081C14BC:
	ldrb r0, [r5, #4]
	b _081C14C2
_081C14C0:
	ldrb r0, [r5]
_081C14C2:
	subs r1, r1, r0
_081C14C4:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C14EC
	cmp r1, #0
	blt _081C14EC
	ldr r0, _081C14F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C14EC
	ldr r0, _081C14F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C14F8
_081C14EC:
	movs r4, #0
	b _081C1506
	.align 2, 0
_081C14F0: .4byte 0x030046A8
_081C14F4: .4byte 0x030046AC
_081C14F8:
	ldr r0, _081C1518 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C1506:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C151C
	adds r0, #4
	b _081C1528
	.align 2, 0
_081C1518: .4byte 0x030046A4
_081C151C:
	ldr r0, _081C153C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C1528:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C1540
	cmp r3, #2
	beq _081C1544
	b _081C1548
	.align 2, 0
_081C153C: .4byte 0x030046A4
_081C1540:
	ldrb r0, [r5, #4]
	b _081C1546
_081C1544:
	ldrb r0, [r5]
_081C1546:
	subs r2, r2, r0
_081C1548:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081C1552:
	ldrb r4, [r7, #5]
	str r4, [sp, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x14]
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _081C157C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x28]
	cmp r0, #0
	bne _081C1660
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C1580
	movs r0, #1
	b _081C1582
	.align 2, 0
_081C157C: .4byte 0x00000482
_081C1580:
	movs r0, #0
_081C1582:
	ldr r3, _081C1670 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x28]
	cmp r0, #0
	bne _081C1660
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _081C1674 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _081C1678 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _081C167C @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _081C1680 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r4, _081C1684 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x34]
	ldr r5, _081C1688 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x50]
	ldr r6, _081C168C @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x38]
	ldr r6, _081C1690 @ =0x0203B400
	ldr r1, _081C1694 @ =0x030046B8
	ldr r5, _081C1698 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081C15D2:
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
	bne _081C15F0
	adds r3, #1
	cmp r3, #3
	ble _081C15D2
	mov r0, r8
_081C15F0:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x4c]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x48]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	ldr r2, [sp, #0x3c]
	strb r0, [r2]
	ldr r4, [sp, #0x10]
	ldrb r0, [r4]
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r6, [sp, #0x18]
	ldrb r0, [r6]
	ldr r1, [sp, #0x44]
	strb r0, [r1]
	mov r2, sp
	ldrb r4, [r2, #8]
	ldr r2, [sp, #0x34]
	strb r4, [r2]
	ldr r5, [sp, #0x50]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x24]
	strb r1, [r6]
	ldr r4, [sp, #0x1c]
	strb r3, [r4]
	ldr r5, [sp, #0x48]
	strb r0, [r5]
	ldr r6, [sp, #0x4c]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x30]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xc]
	strb r0, [r4]
	ldr r5, [sp, #0x10]
	strb r1, [r5]
	ldr r6, [sp, #0x18]
	strb r2, [r6]
	ldr r0, [sp, #0x2c]
	str r3, [r0]
	ldr r2, [sp, #0x20]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x38]
	strb r0, [r3]
_081C1660:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x28]
	strh r0, [r4]
	b _081C1764
	.align 2, 0
_081C1670: .4byte 0x00000482
_081C1674: .4byte 0x0000054F
_081C1678: .4byte 0x0000054C
_081C167C: .4byte 0x0000054D
_081C1680: .4byte 0x0000054E
_081C1684: .4byte 0x00000541
_081C1688: .4byte 0x000005BC
_081C168C: .4byte 0x00000542
_081C1690: .4byte 0x0203B400
_081C1694: .4byte 0x030046B8
_081C1698: .4byte 0x000003FF
_081C169C:
	mov sb, sp
	ldr r6, _081C16D8 @ =0x030046A4
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
	beq _081C16DC
	adds r0, #4
	b _081C16E6
	.align 2, 0
_081C16D8: .4byte 0x030046A4
_081C16DC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C16E6:
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
	ldr r6, _081C1720 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C1728
	ldr r0, _081C1724 @ =0xFFFFFDFF
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C1752
	.align 2, 0
_081C1720: .4byte 0x000004A4
_081C1724: .4byte 0xFFFFFDFF
_081C1728:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C1748
	cmp r0, #2
	beq _081C1744
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C1744:
	movs r0, #1
	b _081C1754
_081C1748:
	ldr r0, _081C1774 @ =0xFFFFFDFF
	ldr r3, [sp, #0x14]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C1752:
	movs r0, #0
_081C1754:
	cmp r0, #0
	bne _081C1764
	ldr r4, _081C1778 @ =0x000005C4
	adds r0, r7, r4
_081C175C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_081C1764:
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C1774: .4byte 0xFFFFFDFF
_081C1778: .4byte 0x000005C4
