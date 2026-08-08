	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _0806641E
	b _08066788
_0806641E:
	ldr r2, _08066484 @ =0x00000446
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08066436
	ldr r5, _08066488 @ =0x00000442
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #5
	bne _08066436
	movs r1, #1
_08066436:
	cmp r1, #0
	beq _0806643C
	b _08066788
_0806643C:
	movs r1, #0x10
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0806644E
	b _08066788
_0806644E:
	ldr r0, _0806648C @ =0x03002BAC
	ldr r1, _08066490 @ =0x03002B84
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0806645C
	b _08066788
_0806645C:
	ldr r0, _08066494 @ =0x03002B90
	ldrh r0, [r0]
	adds r0, #0x70
	movs r1, #0xff
	ands r0, r1
	asrs r4, r0, #5
	movs r6, #0
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _08066474
	b _0806657C
_08066474:
	cmp r4, #1
	bne _0806649C
	ldr r0, _08066498 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r6, [r0, r5]
	b _080664C2
	.align 2, 0
_08066484: .4byte 0x00000446
_08066488: .4byte 0x00000442
_0806648C: .4byte 0x03002BAC
_08066490: .4byte 0x03002B84
_08066494: .4byte 0x03002B90
_08066498: .4byte 0x030046A4
_0806649C:
	cmp r4, #3
	bne _080664A6
	movs r6, #1
	rsbs r6, r6, #0
	b _080664C2
_080664A6:
	cmp r4, #5
	bne _080664BC
	ldr r0, _080664B8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	rsbs r6, r0, #0
	b _080664C2
	.align 2, 0
_080664B8: .4byte 0x030046A4
_080664BC:
	cmp r4, #7
	bne _080664C2
	movs r6, #1
_080664C2:
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r5, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080664DA
	adds r0, #4
	b _080664E6
_080664DA:
	ldr r0, _0806650C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080664E6:
	ldrb r0, [r0]
	movs r5, #0xf
	mov r8, r5
	mov r1, r8
	ands r1, r0
	mov r8, r1
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r5, r0, r6
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08066510
	adds r0, #4
	b _0806651C
	.align 2, 0
_0806650C: .4byte 0x030046A4
_08066510:
	ldr r0, _08066558 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0806651C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r8, r0
	bhs _08066528
	b _08066788
_08066528:
	adds r0, r4, #1
	lsls r4, r0, #5
	ldr r2, _0806655C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r3, [r0, r5]
	ands r4, r1
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r1, _08066560 @ =0x03002BAC
	ldrh r0, [r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08066564
	asrs r2, r0, #0xc
	b _0806656A
	.align 2, 0
_08066558: .4byte 0x030046A4
_0806655C: .4byte 0x085B0A08
_08066560: .4byte 0x03002BAC
_08066564:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806656A:
	ldrh r0, [r7, #0x34]
	subs r0, r0, r2
	strh r0, [r7, #0x34]
	ldrh r0, [r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0806657A
	b _08066778
_0806657A:
	b _0806677C
_0806657C:
	cmp r4, #0
	bne _08066590
	ldr r0, _0806658C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	b _080665D0
	.align 2, 0
_0806658C: .4byte 0x030046A4
_08066590:
	cmp r4, #2
	bne _080665A8
	ldr r0, _080665A4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	subs r6, r0, #1
	b _080665D2
	.align 2, 0
_080665A4: .4byte 0x030046A4
_080665A8:
	cmp r4, #4
	bne _080665C0
	ldr r0, _080665BC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	mvns r6, r0
	b _080665D2
	.align 2, 0
_080665BC: .4byte 0x030046A4
_080665C0:
	cmp r4, #6
	bne _080665D2
	ldr r0, _080665EC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	rsbs r0, r0, #0
_080665D0:
	adds r6, r0, #1
_080665D2:
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrh r5, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080665F0
	adds r0, #4
	b _080665FC
	.align 2, 0
_080665EC: .4byte 0x030046A4
_080665F0:
	ldr r0, _08066624 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080665FC:
	ldrb r0, [r0]
	movs r1, #0xf
	mov r8, r1
	mov r2, r8
	ands r2, r0
	mov r8, r2
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrh r0, [r0]
	adds r5, r0, r6
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08066628
	adds r0, #4
	b _08066634
	.align 2, 0
_08066624: .4byte 0x030046A4
_08066628:
	ldr r0, _08066660 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08066634:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r8, r0
	bhs _08066640
	b _08066788
_08066640:
	ldrh r0, [r7, #0x2c]
	movs r1, #0xff
	adds r2, r1, #0
	ands r2, r0
	ldrh r0, [r7, #0x30]
	ands r1, r0
	cmp r4, #0
	bne _08066664
	cmp r2, r1
	bgt _080666B0
	ldr r0, _08066660 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r6, [r0, r1]
	b _080666C0
	.align 2, 0
_08066660: .4byte 0x030046A4
_08066664:
	cmp r4, #2
	bne _08066684
	adds r1, r2, r1
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _0806669C
	ldr r0, _08066680 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r6, [r0, r2]
	b _080666C0
	.align 2, 0
_08066680: .4byte 0x030046A4
_08066684:
	cmp r4, #4
	bne _080666A2
	cmp r2, r1
	ble _0806669C
	ldr r0, _08066698 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	b _080666BE
	.align 2, 0
_08066698: .4byte 0x030046A4
_0806669C:
	movs r6, #1
	rsbs r6, r6, #0
	b _080666C0
_080666A2:
	cmp r4, #6
	bne _080666C0
	adds r1, r2, r1
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _080666B4
_080666B0:
	movs r6, #1
	b _080666C0
_080666B4:
	ldr r0, _080666D8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
_080666BE:
	rsbs r6, r0, #0
_080666C0:
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r5, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080666DC
	adds r0, #4
	b _080666E8
	.align 2, 0
_080666D8: .4byte 0x030046A4
_080666DC:
	ldr r0, _08066710 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080666E8:
	ldrb r0, [r0]
	movs r5, #0xf
	mov r8, r5
	mov r1, r8
	ands r1, r0
	mov r8, r1
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r5, r0, r6
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08066714
	adds r0, #4
	b _08066720
	.align 2, 0
_08066710: .4byte 0x030046A4
_08066714:
	ldr r0, _08066758 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08066720:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r8, r0
	blo _08066788
	adds r0, r4, #1
	lsls r4, r0, #5
	ldr r2, _0806675C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r3, [r0, r5]
	ands r4, r1
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r1, _08066760 @ =0x03002BAC
	ldrh r0, [r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08066764
	asrs r2, r0, #0xc
	b _0806676A
	.align 2, 0
_08066758: .4byte 0x030046A4
_0806675C: .4byte 0x085B0A08
_08066760: .4byte 0x03002BAC
_08066764:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806676A:
	ldrh r0, [r7, #0x34]
	subs r0, r0, r2
	strh r0, [r7, #0x34]
	ldrh r0, [r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0806677C
_08066778:
	asrs r1, r0, #0xc
	b _08066782
_0806677C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08066782:
	ldrh r0, [r7, #0x38]
	subs r0, r0, r1
	strh r0, [r7, #0x38]
_08066788:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
