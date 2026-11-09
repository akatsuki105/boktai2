	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	movs r1, #0xa0
	ldr r0, _081912C0 @ =0x00000F2C
	add r0, sb
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081912C4
	movs r0, #1
	b _081912C6
	.align 2, 0
_081912C0: .4byte 0x00000F2C
_081912C4:
	movs r0, #0
_081912C6:
	cmp r0, #0
	beq _081912CC
	b _081913C2
_081912CC:
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r3
	cmp r2, #0
	blt _08191318
	cmp r1, #0
	blt _08191318
	ldr r0, _0819131C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191318
	ldr r0, _08191320 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191324
_08191318:
	movs r4, #0
	b _08191332
	.align 2, 0
_0819131C: .4byte 0x030046A8
_08191320: .4byte 0x030046AC
_08191324:
	ldr r0, _0819134C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08191332:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov r6, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08191350
	adds r0, #4
	b _0819135C
	.align 2, 0
_0819134C: .4byte 0x030046A4
_08191350:
	ldr r0, _08191370 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0819135C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08191374
	cmp r2, #2
	beq _08191378
	b _0819137C
	.align 2, 0
_08191370: .4byte 0x030046A4
_08191374:
	ldrb r0, [r6, #4]
	b _0819137A
_08191378:
	ldrb r0, [r6]
_0819137A:
	subs r1, r1, r0
_0819137C:
	movs r2, #0
	mov sl, r2
	ldr r3, _081913B0 @ =0x00000472
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, r1
	bge _0819139C
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r5, r4
	mov r1, sl
	strh r1, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0819139C:
	ldr r1, _081913B4 @ =0x00002004
	ldr r0, _081913B8 @ =0x00000F2C
	add r0, sb
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081913BC
	movs r0, #1
	b _081913BE
	.align 2, 0
_081913B0: .4byte 0x00000472
_081913B4: .4byte 0x00002004
_081913B8: .4byte 0x00000F2C
_081913BC:
	movs r0, #0
_081913BE:
	cmp r0, #0
	beq _081913D0
_081913C2:
	ldr r1, _081913CC @ =0x00000ED5
	add r1, sb
	movs r0, #0
	strb r0, [r1]
	b _08191760
	.align 2, 0
_081913CC: .4byte 0x00000ED5
_081913D0:
	mov r3, sp
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r4, r8
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	mov r1, sp
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08191422
	cmp r1, #0
	blt _08191422
	ldr r0, _08191428 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191422
	ldr r0, _0819142C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191430
_08191422:
	movs r4, #0
	b _0819143E
	.align 2, 0
_08191428: .4byte 0x030046A8
_0819142C: .4byte 0x030046AC
_08191430:
	ldr r0, _08191450 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0819143E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08191454
	adds r0, #4
	b _08191460
	.align 2, 0
_08191450: .4byte 0x030046A4
_08191454:
	ldr r0, _08191474 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191460:
	ldrh r6, [r0, #2]
	mov r7, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08191478
	adds r0, #4
	b _08191484
	.align 2, 0
_08191474: .4byte 0x030046A4
_08191478:
	ldr r0, _08191498 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191484:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0819149C
	cmp r2, #2
	beq _081914A0
	b _081914A4
	.align 2, 0
_08191498: .4byte 0x030046A4
_0819149C:
	ldrb r0, [r7, #4]
	b _081914A2
_081914A0:
	ldrb r0, [r7]
_081914A2:
	subs r1, r1, r0
_081914A4:
	movs r0, #0x40
	ands r6, r0
	cmp r6, #0
	beq _081914B0
	cmp r1, #0
	bne _081914B8
_081914B0:
	movs r0, #0
	strh r0, [r5, #0x10]
	movs r2, #1
	mov sl, r2
_081914B8:
	mov r3, sp
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r4, r8
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	ldrh r0, [r5, #0x14]
	adds r1, r1, r0
	strh r1, [r3, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08191504
	cmp r1, #0
	blt _08191504
	ldr r0, _08191508 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08191504
	ldr r0, _0819150C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191510
_08191504:
	movs r4, #0
	b _0819151E
	.align 2, 0
_08191508: .4byte 0x030046A8
_0819150C: .4byte 0x030046AC
_08191510:
	ldr r0, _08191530 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0819151E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08191534
	adds r0, #4
	b _08191540
	.align 2, 0
_08191530: .4byte 0x030046A4
_08191534:
	ldr r0, _08191554 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191540:
	ldrh r6, [r0, #2]
	mov r7, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08191558
	adds r0, #4
	b _08191564
	.align 2, 0
_08191554: .4byte 0x030046A4
_08191558:
	ldr r0, _08191578 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191564:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0819157C
	cmp r2, #2
	beq _08191580
	b _08191584
	.align 2, 0
_08191578: .4byte 0x030046A4
_0819157C:
	ldrb r0, [r7, #4]
	b _08191582
_08191580:
	ldrb r0, [r7]
_08191582:
	subs r1, r1, r0
_08191584:
	movs r0, #0x40
	ands r6, r0
	cmp r6, #0
	beq _08191590
	cmp r1, #0
	bne _08191598
_08191590:
	movs r0, #0
	strh r0, [r5, #0x14]
	movs r2, #1
	mov sl, r2
_08191598:
	mov r3, sp
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r4, r8
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	mov r1, sp
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r1, [r5, #0x14]
	ldrh r2, [r3, #4]
	adds r1, r1, r2
	strh r1, [r3, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081915F4
	cmp r1, #0
	blt _081915F4
	ldr r0, _081915F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081915F4
	ldr r0, _081915FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08191600
_081915F4:
	movs r4, #0
	b _0819160E
	.align 2, 0
_081915F8: .4byte 0x030046A8
_081915FC: .4byte 0x030046AC
_08191600:
	ldr r0, _08191620 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0819160E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08191624
	adds r0, #4
	b _08191630
	.align 2, 0
_08191620: .4byte 0x030046A4
_08191624:
	ldr r0, _08191644 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191630:
	ldrh r6, [r0, #2]
	mov r7, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08191648
	adds r0, #4
	b _08191654
	.align 2, 0
_08191644: .4byte 0x030046A4
_08191648:
	ldr r0, _08191668 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08191654:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0819166C
	cmp r2, #2
	beq _08191670
	b _08191674
	.align 2, 0
_08191668: .4byte 0x030046A4
_0819166C:
	ldrb r0, [r7, #4]
	b _08191672
_08191670:
	ldrb r0, [r7]
_08191672:
	subs r1, r1, r0
_08191674:
	movs r0, #0x40
	ands r6, r0
	cmp r6, #0
	beq _08191680
	cmp r1, #0
	bne _0819168A
_08191680:
	movs r0, #0
	strh r0, [r5, #0x10]
	strh r0, [r5, #0x14]
	movs r3, #1
	mov sl, r3
_0819168A:
	mov r4, sl
	cmp r4, #0
	beq _08191758
	ldr r1, _08191704 @ =0x00000ED5
	add r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bls _08191760
	ldr r2, _08191708 @ =0x00000F45
	add r2, sb
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	bl FUN_0818e6fc
	mov r2, sp
	ldr r1, _0819170C @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	mov r4, r8
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r5, r4
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08191714
	ldr r0, _08191710 @ =0xFFFFFF00
	adds r1, r1, r0
	b _08191722
	.align 2, 0
_08191704: .4byte 0x00000ED5
_08191708: .4byte 0x00000F45
_0819170C: .4byte 0x000004A4
_08191710: .4byte 0xFFFFFF00
_08191714:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08191722
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08191722:
	cmp r1, #0
	bge _08191728
	rsbs r1, r1, #0
_08191728:
	cmp r1, #0x20
	ble _08191760
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08191750 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _08191754 @ =0x0000046C
	adds r0, r5, r1
	b _0819175E
	.align 2, 0
_08191750: .4byte 0x00000469
_08191754: .4byte 0x0000046C
_08191758:
	ldr r0, _08191770 @ =0x00000ED5
	add r0, sb
	mov r2, sl
_0819175E:
	strb r2, [r0]
_08191760:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08191770: .4byte 0x00000ED5
