	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x100
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08100272
	ldr r3, _08100264 @ =0x0000048A
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0810026C
	ldr r0, _08100268 @ =0x00000211
	bl PlaySound_082406e0
	b _08100272
	.align 2, 0
_08100264: .4byte 0x0000048A
_08100268: .4byte 0x00000211
_0810026C:
	movs r0, #0xd4
	bl PlaySound_082406e0
_08100272:
	adds r0, r7, #0
	bl FUN_081001dc
	movs r0, #0x80
	lsls r0, r0, #6
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r7, r4
	ldrh r3, [r1]
	adds r2, r3, #0
	ands r0, r2
	str r1, [sp, #0xf0]
	cmp r0, #0
	bne _08100290
	b _081009F0
_08100290:
	ldr r5, _0810031C @ =0x000001DD
	adds r0, r7, r5
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, _08100320 @ =0xFFFFDFDF
	ldr r6, [sp, #0xf0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r0, _08100324 @ =0x00000544
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _08100328 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r3, r7, r5
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xd0]
	str r2, [sp, #0xdc]
	cmp r5, #0
	blt _08100316
	cmp r1, #0
	blt _08100316
	ldr r0, _0810032C @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08100316
	ldr r0, _08100330 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100334
_08100316:
	movs r4, #0
	b _08100342
	.align 2, 0
_0810031C: .4byte 0x000001DD
_08100320: .4byte 0xFFFFDFDF
_08100324: .4byte 0x00000544
_08100328: .4byte 0x03002BE0
_0810032C: .4byte 0x030046A8
_08100330: .4byte 0x030046AC
_08100334:
	ldr r0, _08100354 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08100342:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08100358
	adds r0, #4
	b _08100364
	.align 2, 0
_08100354: .4byte 0x030046A4
_08100358:
	ldr r0, _08100378 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08100364:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810037C
	cmp r2, #2
	beq _08100380
	b _08100384
	.align 2, 0
_08100378: .4byte 0x030046A4
_0810037C:
	ldrb r0, [r6, #4]
	b _08100382
_08100380:
	ldrb r0, [r6]
_08100382:
	subs r1, r1, r0
_08100384:
	strh r1, [r6, #2]
	ldr r0, _08100398 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810039C
	movs r0, #1
	b _0810039E
	.align 2, 0
_08100398: .4byte 0x030047A4
_0810039C:
	movs r0, #0
_0810039E:
	cmp r0, #0
	beq _081003DC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081003BE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081003BA
	adds r2, r0, #0
_081003BA:
	cmp r2, #0
	bge _081003C8
_081003BE:
	ldr r2, _081003C4 @ =0x000005C4
	adds r0, r7, r2
	b _081008F4
	.align 2, 0
_081003C4: .4byte 0x000005C4
_081003C8:
	ldr r1, _081003D8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08100424
	.align 2, 0
_081003D8: .4byte 0x03002BE0
_081003DC:
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
	blt _08100408
	cmp r1, #0
	blt _08100408
	ldr r0, _0810040C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08100408
	ldr r0, _08100410 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100414
_08100408:
	movs r5, #0
	b _08100422
	.align 2, 0
_0810040C: .4byte 0x030046A8
_08100410: .4byte 0x030046AC
_08100414:
	ldr r0, _0810045C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08100422:
	movs r2, #0
_08100424:
	ldr r4, _08100460 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08100444
	ldr r1, _08100464 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08100444
	b _08100834
_08100444:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xf0]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	cmp r0, #0
	beq _08100468
	movs r0, #0
	b _0810090A
	.align 2, 0
_0810045C: .4byte 0x030046A4
_08100460: .4byte 0x00000256
_08100464: .4byte 0x03002BE0
_08100468:
	ldr r6, _0810050C @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0xf0]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xf8]
	cmp r6, #0
	beq _08100520
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _08100510 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x1c]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _08100514 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x20]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x24]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x28]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x18]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _08100518 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0810051C @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x18]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0xc8]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0xc0]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xe8]
	str r5, [sp, #0xf4]
	str r4, [sp, #0xb4]
	str r3, [sp, #0xb8]
	str r2, [sp, #0xbc]
	str r1, [sp, #0xcc]
	str r0, [sp, #0xc4]
	b _081006F2
	.align 2, 0
_0810050C: .4byte 0x00000222
_08100510: .4byte 0x0000046D
_08100514: .4byte 0x0000046B
_08100518: .4byte 0x00000469
_0810051C: .4byte 0x00000484
_08100520:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081005E4 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r3, _081005E8 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x30]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081005EC @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x34]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x38]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x40]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081005F0 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081005F4 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081005F8 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd0]
	ldr r0, [r0]
	str r0, [sp, #0x44]
	ldr r1, [sp, #0xdc]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x44]
	strh r1, [r6]
	ldr r6, [sp, #0xdc]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x44]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xc8]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0xc0]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0x38]
	str r6, [sp, #0xe8]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0xf4]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xb8]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xcc]
	str r2, [sp, #0xc4]
	mov r0, sl
	cmp r0, #0
	blt _081005DE
	cmp r1, #0
	blt _081005DE
	ldr r0, _081005FC @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081005DE
	ldr r0, _08100600 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100604
_081005DE:
	movs r4, #0
	b _08100614
	.align 2, 0
_081005E4: .4byte 0x0000046D
_081005E8: .4byte 0x0000046B
_081005EC: .4byte 0x00000553
_081005F0: .4byte 0x00000469
_081005F4: .4byte 0x00000484
_081005F8: .4byte 0x0000046C
_081005FC: .4byte 0x030046A8
_08100600: .4byte 0x030046AC
_08100604:
	ldr r0, _08100624 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_08100614:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08100628
	adds r0, #4
	b _08100634
	.align 2, 0
_08100624: .4byte 0x030046A4
_08100628:
	ldr r0, _08100648 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08100634:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810064C
	cmp r2, #2
	beq _08100652
	b _08100658
	.align 2, 0
_08100648: .4byte 0x030046A4
_0810064C:
	ldr r2, [sp, #0x44]
	ldrb r0, [r2, #4]
	b _08100656
_08100652:
	ldr r3, [sp, #0x44]
	ldrb r0, [r3]
_08100656:
	subs r1, r1, r0
_08100658:
	ldr r4, [sp, #0x44]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd0]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08100684
	cmp r1, #0
	blt _08100684
	ldr r0, _08100688 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08100684
	ldr r0, _0810068C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100690
_08100684:
	movs r4, #0
	b _0810069E
	.align 2, 0
_08100688: .4byte 0x030046A8
_0810068C: .4byte 0x030046AC
_08100690:
	ldr r0, _081006B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810069E:
	ldr r6, [sp, #0xd0]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081006B8
	adds r0, #4
	b _081006C4
	.align 2, 0
_081006B4: .4byte 0x030046A4
_081006B8:
	ldr r0, _081006D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081006C4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081006DC
	cmp r3, #2
	beq _081006E0
	b _081006E4
	.align 2, 0
_081006D8: .4byte 0x030046A4
_081006DC:
	ldrb r0, [r5, #4]
	b _081006E2
_081006E0:
	ldrb r0, [r5]
_081006E2:
	subs r2, r2, r0
_081006E4:
	ldr r1, [sp, #0xd0]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd0]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081006F2:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x48]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf0]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _0810071C @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _081007FC
	movs r1, #4
	ldr r2, [sp, #0xf8]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08100720
	movs r0, #1
	b _08100722
	.align 2, 0
_0810071C: .4byte 0x00000482
_08100720:
	movs r0, #0
_08100722:
	ldr r3, _0810080C @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _081007FC
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08100810 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _08100814 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08100818 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _0810081C @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd4]
	ldr r1, _08100820 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xec]
	ldr r2, _08100824 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xd8]
	ldr r1, _08100828 @ =0x030046B8
	str r4, [sp, #0xfc]
_08100768:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0810082C @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _08100830 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0xfc]
	cmp r0, r2
	bne _0810078E
	adds r3, #1
	cmp r3, #3
	ble _08100768
	adds r0, r4, #0
_0810078E:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xe8]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb4]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xb8]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xbc]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0x48
	ldrb r1, [r0]
	ldr r0, [sp, #0xd4]
	strb r1, [r0]
	ldr r1, [sp, #0xec]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xc8]
	strb r1, [r4]
	ldr r6, [sp, #0xc0]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xe8]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf4]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb4]
	strb r0, [r4]
	ldr r6, [sp, #0xb8]
	strb r1, [r6]
	ldr r0, [sp, #0xbc]
	strb r2, [r0]
	ldr r2, [sp, #0xcc]
	str r3, [r2]
	ldr r3, [sp, #0xc4]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xd8]
	strb r0, [r4]
_081007FC:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _0810090A
	.align 2, 0
_0810080C: .4byte 0x00000482
_08100810: .4byte 0x0000054F
_08100814: .4byte 0x0000054D
_08100818: .4byte 0x0000054E
_0810081C: .4byte 0x00000541
_08100820: .4byte 0x000005BC
_08100824: .4byte 0x00000542
_08100828: .4byte 0x030046B8
_0810082C: .4byte 0x000003FF
_08100830: .4byte 0x0203B400
_08100834:
	mov sb, sp
	ldr r6, _08100870 @ =0x030046A4
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
	beq _08100874
	adds r0, #4
	b _0810087E
	.align 2, 0
_08100870: .4byte 0x030046A4
_08100874:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810087E:
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
	ldr r6, _081008B8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081008C0
	ldr r0, _081008BC @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081008EA
	.align 2, 0
_081008B8: .4byte 0x000004A4
_081008BC: .4byte 0xFFFFFDFF
_081008C0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081008E0
	cmp r0, #2
	beq _081008DC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081008DC:
	movs r0, #1
	b _081008EC
_081008E0:
	ldr r0, _08100900 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf0]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081008EA:
	movs r0, #0
_081008EC:
	cmp r0, #0
	bne _08100908
	ldr r4, _08100904 @ =0x000005C4
	adds r0, r7, r4
_081008F4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0810090A
	.align 2, 0
_08100900: .4byte 0xFFFFFDFF
_08100904: .4byte 0x000005C4
_08100908:
	movs r0, #1
_0810090A:
	cmp r0, #0
	bne _0810097C
	ldr r5, _08100940 @ =0x000004A4
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
	bl FUN_0823599c
	cmp r0, #0
	bne _08100948
	ldr r0, _08100944 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08100972
	.align 2, 0
_08100940: .4byte 0x000004A4
_08100944: .4byte 0xFFFFFDFF
_08100948:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08100968
	cmp r0, #2
	beq _08100964
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08100964:
	movs r0, #1
	b _08100974
_08100968:
	ldr r0, _081009D8 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf0]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08100972:
	movs r0, #0
_08100974:
	cmp r0, #0
	bne _0810097C
	bl _08101948
_0810097C:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081009DC @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081009E0 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081009E4 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081009E8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081009EC @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	bl FUN_081019b6
	.align 2, 0
_081009D8: .4byte 0xFFFFFDFF
_081009DC: .4byte 0x0000046D
_081009E0: .4byte 0x0000046B
_081009E4: .4byte 0x00000469
_081009E8: .4byte 0x0000046A
_081009EC: .4byte 0x00000484
_081009F0:
	ldr r4, _08100A08 @ =0x00008002
	ands r4, r2
	cmp r4, #0
	beq _08100A0C
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r3
	ldr r1, [sp, #0xf0]
	strh r0, [r1]
_08100A02:
	movs r0, #0
	bl FUN_081019ba
	.align 2, 0
_08100A08: .4byte 0x00008002
_08100A0C:
	ldr r2, _08100A7C @ =0x0000049C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _08100AA0
	ldr r3, _08100A80 @ =0x000005CC
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #0x12
	ldr r5, _08100A84 @ =0x0000046D
	adds r0, r7, r5
	movs r3, #1
	strb r3, [r0]
	ldr r6, _08100A88 @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08100A8C @ =0x00000469
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _08100A90 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _08100A94 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _08100A98 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _08100A9C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bl _081019B8
	.align 2, 0
_08100A7C: .4byte 0x0000049C
_08100A80: .4byte 0x000005CC
_08100A84: .4byte 0x0000046D
_08100A88: .4byte 0x0000046B
_08100A8C: .4byte 0x00000469
_08100A90: .4byte 0x0000046A
_08100A94: .4byte 0x00000484
_08100A98: .4byte 0x0000046C
_08100A9C: .4byte 0xFEFFFFFF
_08100AA0:
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r3
	ldr r6, [sp, #0xf0]
	strh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08100A02
	ldr r1, _08100B78 @ =0x000004BE
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08100A02
	ldr r3, _08100B7C @ =0x0000065C
	adds r2, r5, r3
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xf0]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _08100ADA
	b _0810124C
_08100ADA:
	ldr r5, _08100B80 @ =0x0000048D
	adds r2, r7, r5
	ldrb r0, [r2]
	cmp r0, #0
	bne _08100B06
	ldr r6, _08100B84 @ =0x0000048C
	adds r0, r7, r6
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08100B06
	ldr r1, _08100B78 @ =0x000004BE
	adds r0, r7, r1
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_08100B06:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0
	bne _08100B14
	b _08100A02
_08100B14:
	ldr r0, _08100B88 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x80
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r4, _08100B8C @ =0x00000222
	adds r3, r7, r4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r4, r7, r5
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xd0]
	str r2, [sp, #0xdc]
	str r3, [sp, #0xf8]
	cmp r5, #0
	blt _08100B74
	cmp r1, #0
	blt _08100B74
	ldr r0, _08100B90 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08100B74
	ldr r0, _08100B94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100B98
_08100B74:
	movs r4, #0
	b _08100BA6
	.align 2, 0
_08100B78: .4byte 0x000004BE
_08100B7C: .4byte 0x0000065C
_08100B80: .4byte 0x0000048D
_08100B84: .4byte 0x0000048C
_08100B88: .4byte 0x03002BE0
_08100B8C: .4byte 0x00000222
_08100B90: .4byte 0x030046A8
_08100B94: .4byte 0x030046AC
_08100B98:
	ldr r0, _08100BB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08100BA6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08100BBC
	adds r0, #4
	b _08100BC8
	.align 2, 0
_08100BB8: .4byte 0x030046A4
_08100BBC:
	ldr r0, _08100BDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08100BC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08100BE0
	cmp r2, #2
	beq _08100BE4
	b _08100BE8
	.align 2, 0
_08100BDC: .4byte 0x030046A4
_08100BE0:
	ldrb r0, [r6, #4]
	b _08100BE6
_08100BE4:
	ldrb r0, [r6]
_08100BE6:
	subs r1, r1, r0
_08100BE8:
	strh r1, [r6, #2]
	ldr r0, _08100BFC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08100C00
	movs r0, #1
	b _08100C02
	.align 2, 0
_08100BFC: .4byte 0x030047A4
_08100C00:
	movs r0, #0
_08100C02:
	cmp r0, #0
	beq _08100C40
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _08100C22
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08100C1E
	adds r2, r0, #0
_08100C1E:
	cmp r2, #0
	bge _08100C2C
_08100C22:
	ldr r1, _08100C28 @ =0x000005C4
	adds r0, r7, r1
	b _0810115C
	.align 2, 0
_08100C28: .4byte 0x000005C4
_08100C2C:
	ldr r1, _08100C3C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08100C88
	.align 2, 0
_08100C3C: .4byte 0x03002BE0
_08100C40:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08100C6C
	cmp r1, #0
	blt _08100C6C
	ldr r0, _08100C70 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08100C6C
	ldr r0, _08100C74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100C78
_08100C6C:
	movs r5, #0
	b _08100C86
	.align 2, 0
_08100C70: .4byte 0x030046A8
_08100C74: .4byte 0x030046AC
_08100C78:
	ldr r0, _08100CC0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08100C86:
	movs r2, #0
_08100C88:
	ldr r3, _08100CC4 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08100CA8
	ldr r1, _08100CC8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08100CA8
	b _08101098
_08100CA8:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf0]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x4c]
	cmp r0, #0
	beq _08100CCC
	movs r0, #0
	b _08101172
	.align 2, 0
_08100CC0: .4byte 0x030046A4
_08100CC4: .4byte 0x00000256
_08100CC8: .4byte 0x03002BE0
_08100CCC:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0xf8]
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x80
	ldr r6, [sp, #0xf0]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08100D88
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _08100D6C @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x50]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _08100D70 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x54]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08100D74 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x58]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x5c]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x4c
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _08100D78 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _08100D7C @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08100D80 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x4c]
	str r6, [r1]
	ldr r6, _08100D84 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xc8]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0xc0]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xe8]
	str r5, [sp, #0xf4]
	str r4, [sp, #0xb4]
	str r3, [sp, #0xb8]
	str r2, [sp, #0xbc]
	str r1, [sp, #0xcc]
	str r0, [sp, #0xc4]
	b _08100F56
	.align 2, 0
_08100D6C: .4byte 0x0000046D
_08100D70: .4byte 0x0000046B
_08100D74: .4byte 0x00000553
_08100D78: .4byte 0x00000469
_08100D7C: .4byte 0x0000046A
_08100D80: .4byte 0x00000484
_08100D84: .4byte 0x0000046C
_08100D88:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _08100E48 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x60]
	strb r0, [r3]
	ldr r4, _08100E4C @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x64]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08100E50 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x68]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x70]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x74]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _08100E54 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _08100E58 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _08100E5C @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd0]
	ldr r0, [r0]
	str r0, [sp, #0x78]
	ldr r1, [sp, #0xdc]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x78]
	strh r1, [r6]
	ldr r6, [sp, #0xdc]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x78]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x60]
	str r0, [sp, #0xc8]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0xc0]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0x6c]
	str r6, [sp, #0xe8]
	ldr r0, [sp, #0x70]
	str r0, [sp, #0xf4]
	ldr r6, [sp, #0x74]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xb8]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xcc]
	str r2, [sp, #0xc4]
	mov r0, sb
	cmp r0, #0
	blt _08100E44
	cmp r1, #0
	blt _08100E44
	ldr r0, _08100E60 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _08100E44
	ldr r0, _08100E64 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100E68
_08100E44:
	movs r4, #0
	b _08100E78
	.align 2, 0
_08100E48: .4byte 0x0000046D
_08100E4C: .4byte 0x0000046B
_08100E50: .4byte 0x00000553
_08100E54: .4byte 0x00000469
_08100E58: .4byte 0x0000046A
_08100E5C: .4byte 0x00000484
_08100E60: .4byte 0x030046A8
_08100E64: .4byte 0x030046AC
_08100E68:
	ldr r0, _08100E88 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_08100E78:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08100E8C
	adds r0, #4
	b _08100E98
	.align 2, 0
_08100E88: .4byte 0x030046A4
_08100E8C:
	ldr r0, _08100EAC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08100E98:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08100EB0
	cmp r2, #2
	beq _08100EB6
	b _08100EBC
	.align 2, 0
_08100EAC: .4byte 0x030046A4
_08100EB0:
	ldr r2, [sp, #0x78]
	ldrb r0, [r2, #4]
	b _08100EBA
_08100EB6:
	ldr r3, [sp, #0x78]
	ldrb r0, [r3]
_08100EBA:
	subs r1, r1, r0
_08100EBC:
	ldr r4, [sp, #0x78]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd0]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08100EE8
	cmp r1, #0
	blt _08100EE8
	ldr r0, _08100EEC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08100EE8
	ldr r0, _08100EF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08100EF4
_08100EE8:
	movs r4, #0
	b _08100F02
	.align 2, 0
_08100EEC: .4byte 0x030046A8
_08100EF0: .4byte 0x030046AC
_08100EF4:
	ldr r0, _08100F18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08100F02:
	ldr r6, [sp, #0xd0]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08100F1C
	adds r0, #4
	b _08100F28
	.align 2, 0
_08100F18: .4byte 0x030046A4
_08100F1C:
	ldr r0, _08100F3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08100F28:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08100F40
	cmp r3, #2
	beq _08100F44
	b _08100F48
	.align 2, 0
_08100F3C: .4byte 0x030046A4
_08100F40:
	ldrb r0, [r5, #4]
	b _08100F46
_08100F44:
	ldrb r0, [r5]
_08100F46:
	subs r2, r2, r0
_08100F48:
	ldr r1, [sp, #0xd0]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd0]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08100F56:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x7c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf0]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _08100F80 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _08101060
	movs r1, #4
	ldr r2, [sp, #0xf8]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08100F84
	movs r0, #1
	b _08100F86
	.align 2, 0
_08100F80: .4byte 0x00000482
_08100F84:
	movs r0, #0
_08100F86:
	ldr r3, _08101070 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _08101060
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08101074 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _08101078 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0810107C @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _08101080 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd4]
	ldr r1, _08101084 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xec]
	ldr r2, _08101088 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xd8]
	ldr r1, _0810108C @ =0x030046B8
	str r4, [sp, #0xfc]
_08100FCC:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _08101090 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _08101094 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0xfc]
	cmp r0, r2
	bne _08100FF2
	adds r3, #1
	cmp r3, #3
	ble _08100FCC
	adds r0, r4, #0
_08100FF2:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xe8]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb4]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xb8]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xbc]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0x7c
	ldrb r1, [r0]
	ldr r0, [sp, #0xd4]
	strb r1, [r0]
	ldr r1, [sp, #0xec]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xc8]
	strb r1, [r4]
	ldr r6, [sp, #0xc0]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xe8]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf4]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb4]
	strb r0, [r4]
	ldr r6, [sp, #0xb8]
	strb r1, [r6]
	ldr r0, [sp, #0xbc]
	strb r2, [r0]
	ldr r2, [sp, #0xcc]
	str r3, [r2]
	ldr r3, [sp, #0xc4]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xd8]
	strb r0, [r4]
_08101060:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _08101172
	.align 2, 0
_08101070: .4byte 0x00000482
_08101074: .4byte 0x0000054F
_08101078: .4byte 0x0000054D
_0810107C: .4byte 0x0000054E
_08101080: .4byte 0x00000541
_08101084: .4byte 0x000005BC
_08101088: .4byte 0x00000542
_0810108C: .4byte 0x030046B8
_08101090: .4byte 0x000003FF
_08101094: .4byte 0x0203B400
_08101098:
	add r6, sp, #8
	ldr r0, _081010D8 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _081010DC
	adds r0, #4
	b _081010E8
	.align 2, 0
_081010D8: .4byte 0x030046A4
_081010DC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081010E8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _08101120 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _08101128
	ldr r0, _08101124 @ =0xFFFFFDFF
	ldr r6, [sp, #0xf0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _08101152
	.align 2, 0
_08101120: .4byte 0x000004A4
_08101124: .4byte 0xFFFFFDFF
_08101128:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _08101148
	cmp r0, #2
	beq _08101144
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08101144:
	movs r0, #1
	b _08101154
_08101148:
	ldr r0, _08101168 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08101152:
	movs r0, #0
_08101154:
	cmp r0, #0
	bne _08101170
	ldr r3, _0810116C @ =0x000005C4
	adds r0, r7, r3
_0810115C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08101172
	.align 2, 0
_08101168: .4byte 0xFFFFFDFF
_0810116C: .4byte 0x000005C4
_08101170:
	movs r0, #1
_08101172:
	cmp r0, #0
	bne _081011E2
	ldr r4, _081011A8 @ =0x000004A4
	adds r0, r7, r4
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
	bl FUN_0823599c
	cmp r0, #0
	bne _081011B0
	ldr r0, _081011AC @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081011DA
	.align 2, 0
_081011A8: .4byte 0x000004A4
_081011AC: .4byte 0xFFFFFDFF
_081011B0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081011D0
	cmp r0, #2
	beq _081011CC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081011CC:
	movs r0, #1
	b _081011DC
_081011D0:
	ldr r0, _08101238 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf0]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081011DA:
	movs r0, #0
_081011DC:
	cmp r0, #0
	bne _081011E2
	b _08101948
_081011E2:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _0810123C @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _08101240 @ =0x0000046B
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
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08101244 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08101248 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _081019B8
	.align 2, 0
_08101238: .4byte 0xFFFFFDFF
_0810123C: .4byte 0x0000046D
_08101240: .4byte 0x0000046B
_08101244: .4byte 0x0000046A
_08101248: .4byte 0x00000484
_0810124C:
	ldr r6, _081012E8 @ =0x0000048D
	adds r2, r7, r6
	ldrb r0, [r2]
	cmp r0, #0
	bne _08101278
	ldr r1, _081012EC @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08101278
	ldr r3, _081012F0 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_08101278:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	cmp r0, #0
	bne _08101288
	bl _08100A02
_08101288:
	ldr r0, _081012F4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	adds r3, r7, r6
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xd0]
	str r2, [sp, #0xdc]
	cmp r5, #0
	blt _081012E2
	cmp r1, #0
	blt _081012E2
	ldr r0, _081012F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081012E2
	ldr r0, _081012FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08101300
_081012E2:
	movs r4, #0
	b _0810130E
	.align 2, 0
_081012E8: .4byte 0x0000048D
_081012EC: .4byte 0x0000048C
_081012F0: .4byte 0x000004BE
_081012F4: .4byte 0x03002BE0
_081012F8: .4byte 0x030046A8
_081012FC: .4byte 0x030046AC
_08101300:
	ldr r0, _08101320 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0810130E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08101324
	adds r0, #4
	b _08101330
	.align 2, 0
_08101320: .4byte 0x030046A4
_08101324:
	ldr r0, _08101344 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08101330:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08101348
	cmp r2, #2
	beq _0810134C
	b _08101350
	.align 2, 0
_08101344: .4byte 0x030046A4
_08101348:
	ldrb r0, [r6, #4]
	b _0810134E
_0810134C:
	ldrb r0, [r6]
_0810134E:
	subs r1, r1, r0
_08101350:
	strh r1, [r6, #2]
	ldr r0, _08101364 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08101368
	movs r0, #1
	b _0810136A
	.align 2, 0
_08101364: .4byte 0x030047A4
_08101368:
	movs r0, #0
_0810136A:
	cmp r0, #0
	beq _081013A8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0810138A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08101386
	adds r2, r0, #0
_08101386:
	cmp r2, #0
	bge _08101394
_0810138A:
	ldr r2, _08101390 @ =0x000005C4
	adds r0, r7, r2
	b _081018C4
	.align 2, 0
_08101390: .4byte 0x000005C4
_08101394:
	ldr r1, _081013A4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081013F0
	.align 2, 0
_081013A4: .4byte 0x03002BE0
_081013A8:
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
	blt _081013D4
	cmp r1, #0
	blt _081013D4
	ldr r0, _081013D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081013D4
	ldr r0, _081013DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081013E0
_081013D4:
	movs r5, #0
	b _081013EE
	.align 2, 0
_081013D8: .4byte 0x030046A8
_081013DC: .4byte 0x030046AC
_081013E0:
	ldr r0, _08101428 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081013EE:
	movs r2, #0
_081013F0:
	ldr r4, _0810142C @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08101410
	ldr r1, _08101430 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08101410
	b _08101800
_08101410:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xf0]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x80]
	cmp r0, #0
	beq _08101434
	movs r0, #0
	b _081018DA
	.align 2, 0
_08101428: .4byte 0x030046A4
_0810142C: .4byte 0x00000256
_08101430: .4byte 0x03002BE0
_08101434:
	ldr r6, _081014D8 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0xf0]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xf8]
	cmp r0, #0
	beq _081014EC
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _081014DC @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x84]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _081014E0 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x88]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x8c]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x90]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	add r0, sp, #0x80
	ldrh r0, [r0]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _081014E4 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081014E8 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x80]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x84]
	str r6, [sp, #0xc8]
	ldr r6, [sp, #0x88]
	str r6, [sp, #0xc0]
	ldr r6, [sp, #0x8c]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x90]
	str r6, [sp, #0xe8]
	str r5, [sp, #0xf4]
	str r4, [sp, #0xb4]
	str r3, [sp, #0xb8]
	str r2, [sp, #0xbc]
	str r1, [sp, #0xcc]
	str r0, [sp, #0xc4]
	b _081016BE
	.align 2, 0
_081014D8: .4byte 0x00000222
_081014DC: .4byte 0x0000046D
_081014E0: .4byte 0x0000046B
_081014E4: .4byte 0x00000469
_081014E8: .4byte 0x00000484
_081014EC:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081015B0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x94]
	strb r0, [r2]
	ldr r3, _081015B4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x98]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081015B8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xa0]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa4]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	strb r4, [r3]
	ldr r4, _081015BC @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081015C0 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081015C4 @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd0]
	ldr r0, [r0]
	str r0, [sp, #0xac]
	ldr r1, [sp, #0xdc]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xac]
	strh r1, [r6]
	ldr r6, [sp, #0xdc]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xac]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x94]
	str r0, [sp, #0xc8]
	ldr r6, [sp, #0x98]
	str r6, [sp, #0xc0]
	ldr r0, [sp, #0x9c]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0xa0]
	str r6, [sp, #0xe8]
	ldr r0, [sp, #0xa4]
	str r0, [sp, #0xf4]
	ldr r6, [sp, #0xa8]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xb8]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xcc]
	str r2, [sp, #0xc4]
	mov r0, r8
	cmp r0, #0
	blt _081015AC
	cmp r1, #0
	blt _081015AC
	ldr r0, _081015C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _081015AC
	ldr r0, _081015CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081015D0
_081015AC:
	movs r4, #0
	b _081015E0
	.align 2, 0
_081015B0: .4byte 0x0000046D
_081015B4: .4byte 0x0000046B
_081015B8: .4byte 0x00000553
_081015BC: .4byte 0x00000469
_081015C0: .4byte 0x0000046A
_081015C4: .4byte 0x00000484
_081015C8: .4byte 0x030046A8
_081015CC: .4byte 0x030046AC
_081015D0:
	ldr r0, _081015F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_081015E0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081015F4
	adds r0, #4
	b _08101600
	.align 2, 0
_081015F0: .4byte 0x030046A4
_081015F4:
	ldr r0, _08101614 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08101600:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08101618
	cmp r2, #2
	beq _0810161E
	b _08101624
	.align 2, 0
_08101614: .4byte 0x030046A4
_08101618:
	ldr r2, [sp, #0xac]
	ldrb r0, [r2, #4]
	b _08101622
_0810161E:
	ldr r3, [sp, #0xac]
	ldrb r0, [r3]
_08101622:
	subs r1, r1, r0
_08101624:
	ldr r4, [sp, #0xac]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd0]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08101650
	cmp r1, #0
	blt _08101650
	ldr r0, _08101654 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08101650
	ldr r0, _08101658 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810165C
_08101650:
	movs r4, #0
	b _0810166A
	.align 2, 0
_08101654: .4byte 0x030046A8
_08101658: .4byte 0x030046AC
_0810165C:
	ldr r0, _08101680 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810166A:
	ldr r6, [sp, #0xd0]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08101684
	adds r0, #4
	b _08101690
	.align 2, 0
_08101680: .4byte 0x030046A4
_08101684:
	ldr r0, _081016A4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08101690:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081016A8
	cmp r3, #2
	beq _081016AC
	b _081016B0
	.align 2, 0
_081016A4: .4byte 0x030046A4
_081016A8:
	ldrb r0, [r5, #4]
	b _081016AE
_081016AC:
	ldrb r0, [r5]
_081016AE:
	subs r2, r2, r0
_081016B0:
	ldr r1, [sp, #0xd0]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd0]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081016BE:
	ldrb r3, [r7, #5]
	str r3, [sp, #0xb0]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf0]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _081016E8 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _081017C8
	movs r1, #4
	ldr r2, [sp, #0xf8]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081016EC
	movs r0, #1
	b _081016EE
	.align 2, 0
_081016E8: .4byte 0x00000482
_081016EC:
	movs r0, #0
_081016EE:
	ldr r3, _081017D8 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _081017C8
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081017DC @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081017E0 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081017E4 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _081017E8 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd4]
	ldr r1, _081017EC @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xec]
	ldr r2, _081017F0 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xd8]
	ldr r1, _081017F4 @ =0x030046B8
	str r4, [sp, #0xfc]
_08101734:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081017F8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081017FC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0xfc]
	cmp r0, r2
	bne _0810175A
	adds r3, #1
	cmp r3, #3
	ble _08101734
	adds r0, r4, #0
_0810175A:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xe8]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb4]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xb8]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xbc]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0xb0
	ldrb r1, [r0]
	ldr r0, [sp, #0xd4]
	strb r1, [r0]
	ldr r1, [sp, #0xec]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xc8]
	strb r1, [r4]
	ldr r6, [sp, #0xc0]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xe8]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf4]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb4]
	strb r0, [r4]
	ldr r6, [sp, #0xb8]
	strb r1, [r6]
	ldr r0, [sp, #0xbc]
	strb r2, [r0]
	ldr r2, [sp, #0xcc]
	str r3, [r2]
	ldr r3, [sp, #0xc4]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xd8]
	strb r0, [r4]
_081017C8:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _081018DA
	.align 2, 0
_081017D8: .4byte 0x00000482
_081017DC: .4byte 0x0000054F
_081017E0: .4byte 0x0000054D
_081017E4: .4byte 0x0000054E
_081017E8: .4byte 0x00000541
_081017EC: .4byte 0x000005BC
_081017F0: .4byte 0x00000542
_081017F4: .4byte 0x030046B8
_081017F8: .4byte 0x000003FF
_081017FC: .4byte 0x0203B400
_08101800:
	add r6, sp, #0x10
	ldr r0, _08101840 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _08101844
	adds r0, #4
	b _08101850
	.align 2, 0
_08101840: .4byte 0x030046A4
_08101844:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08101850:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _08101888 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _08101890
	ldr r0, _0810188C @ =0xFFFFFDFF
	ldr r6, [sp, #0xf0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081018BA
	.align 2, 0
_08101888: .4byte 0x000004A4
_0810188C: .4byte 0xFFFFFDFF
_08101890:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081018B0
	cmp r0, #2
	beq _081018AC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081018AC:
	movs r0, #1
	b _081018BC
_081018B0:
	ldr r0, _081018D0 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081018BA:
	movs r0, #0
_081018BC:
	cmp r0, #0
	bne _081018D8
	ldr r3, _081018D4 @ =0x000005C4
	adds r0, r7, r3
_081018C4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081018DA
	.align 2, 0
_081018D0: .4byte 0xFFFFFDFF
_081018D4: .4byte 0x000005C4
_081018D8:
	movs r0, #1
_081018DA:
	cmp r0, #0
	bne _08101960
	ldr r4, _08101910 @ =0x000004A4
	adds r0, r7, r4
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
	bl FUN_0823599c
	cmp r0, #0
	bne _08101918
	ldr r0, _08101914 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08101942
	.align 2, 0
_08101910: .4byte 0x000004A4
_08101914: .4byte 0xFFFFFDFF
_08101918:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08101938
	cmp r0, #2
	beq _08101934
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08101934:
	movs r0, #1
	b _08101944
_08101938:
	ldr r0, _08101958 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf0]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08101942:
	movs r0, #0
_08101944:
	cmp r0, #0
	bne _08101960
_08101948:
	ldr r4, _0810195C @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _08100A02
	.align 2, 0
_08101958: .4byte 0xFFFFFDFF
_0810195C: .4byte 0x000005C4
_08101960:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081019CC @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081019D0 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081019D4 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081019D8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081019DC @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #3
FUN_081019b6:
	strh r0, [r1]
_081019B8:
	movs r0, #1
FUN_081019ba:
	add sp, #0x100
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081019CC: .4byte 0x0000046D
_081019D0: .4byte 0x0000046B
_081019D4: .4byte 0x00000469
_081019D8: .4byte 0x0000046A
_081019DC: .4byte 0x00000484
