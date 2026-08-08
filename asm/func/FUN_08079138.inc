	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _08079150
	b _080794AC
_08079150:
	cmp r0, #2
	bhi _0807915A
	cmp r0, #1
	beq _08079162
	b _080794D6
_0807915A:
	cmp r0, #4
	bne _08079160
	b _08079458
_08079160:
	b _080794D6
_08079162:
	adds r0, r5, #0
	bl FUN_0807858c
	ldr r0, [r5, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08079186
	ldr r0, _080791D8 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080791DC @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	asrs r1, r1, #1
	adds r0, r5, #0
	bl FUN_080667b0
_08079186:
	adds r0, r5, #0
	bl FUN_0806680c
	cmp r0, #0
	beq _08079196
	adds r0, r5, #0
	bl FUN_0806687c
_08079196:
	adds r0, r5, #0
	bl FUN_080784fc
	adds r0, r5, #0
	bl FUN_080788d0
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08066d7c
	ldr r1, _080791E0 @ =0x085ABD30
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080791E4
	movs r4, #0xea
	lsls r4, r4, #2
	adds r0, r5, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
	b _080791EA
	.align 2, 0
_080791D8: .4byte 0x030046A0
_080791DC: .4byte 0x00000942
_080791E0: .4byte 0x085ABD30
_080791E4:
	adds r0, r5, #0
	bl FUN_08066408
_080791EA:
	adds r0, r5, #0
	bl FUN_08078bc0
	ldr r1, _080792BC @ =0x000003CE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08079202
	adds r0, r5, #0
	bl FUN_08066df8
_08079202:
	adds r0, r5, #0
	bl FUN_08065b7c
	adds r0, r5, #0
	bl FUN_0806623c
	ldr r3, _080792C0 @ =0x00000446
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08079226
	ldr r4, _080792C4 @ =0x00000442
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #5
	bne _08079226
	movs r1, #1
_08079226:
	cmp r1, #0
	beq _0807922C
	b _080794D6
_0807922C:
	movs r4, #0
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_08065b44
	cmp r0, #0
	bne _0807926A
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r2, [r0]
	cmp r2, #1
	bne _0807926A
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0807926A
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
_0807926A:
	cmp r4, #0
	bne _08079270
	b _0807944C
_08079270:
	ldr r0, _080792C8 @ =0x000003BE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	beq _08079284
	b _080794D6
_08079284:
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
	ldr r2, _080792CC @ =0x085B0A08
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
	blt _080792D0
	asrs r2, r0, #0xc
	b _080792D6
	.align 2, 0
_080792BC: .4byte 0x000003CE
_080792C0: .4byte 0x00000446
_080792C4: .4byte 0x00000442
_080792C8: .4byte 0x000003BE
_080792CC: .4byte 0x085B0A08
_080792D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080792D6:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08079300 @ =0xFFFF0000
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
	blt _08079304
	asrs r2, r0, #0xc
	b _0807930A
	.align 2, 0
_08079300: .4byte 0xFFFF0000
_08079304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0807930A:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0807934C @ =0xFFFF0000
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
	blt _08079346
	cmp r1, #0
	blt _08079346
	ldr r0, _08079350 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08079346
	ldr r0, _08079354 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08079358
_08079346:
	movs r4, #0
	b _08079366
	.align 2, 0
_0807934C: .4byte 0xFFFF0000
_08079350: .4byte 0x030046A8
_08079354: .4byte 0x030046AC
_08079358:
	ldr r0, _08079378 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08079366:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0807937C
	adds r0, #4
	b _08079388
	.align 2, 0
_08079378: .4byte 0x030046A4
_0807937C:
	ldr r0, _0807939C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08079388:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080793A0
	cmp r2, #2
	beq _080793A4
	b _080793A8
	.align 2, 0
_0807939C: .4byte 0x030046A4
_080793A0:
	ldrb r0, [r6, #4]
	b _080793A6
_080793A4:
	ldrb r0, [r6]
_080793A6:
	subs r1, r1, r0
_080793A8:
	movs r3, #0x2e
	ldrsh r0, [r5, r3]
	adds r0, #0xc8
	cmp r1, r0
	bhs _080793B4
	b _080794D6
_080793B4:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080793DC
	cmp r1, #0
	blt _080793DC
	ldr r0, _080793E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080793DC
	ldr r0, _080793E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080793E8
_080793DC:
	movs r4, #0
	b _080793F6
	.align 2, 0
_080793E0: .4byte 0x030046A8
_080793E4: .4byte 0x030046AC
_080793E8:
	ldr r0, _08079408 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080793F6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0807940C
	adds r0, #4
	b _08079418
	.align 2, 0
_08079408: .4byte 0x030046A4
_0807940C:
	ldr r0, _08079444 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08079418:
	ldrh r2, [r0, #2]
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	bne _080794D6
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ldr r3, _08079448 @ =0x000003BD
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0xd4
	adds r0, r5, r4
	strb r2, [r0]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0
	bl FUN_08060b84
	b _080794D6
	.align 2, 0
_08079444: .4byte 0x030046A4
_08079448: .4byte 0x000003BD
_0807944C:
	ldr r1, _08079454 @ =0x000003BE
	adds r0, r5, r1
	strh r4, [r0]
	b _080794D6
	.align 2, 0
_08079454: .4byte 0x000003BE
_08079458:
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	str r1, [r5, #0x20]
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
	cmp r0, #3
	bhi _0807947E
	ldrb r4, [r1]
	b _0807948C
_0807947E:
	ldr r3, _080794A4 @ =0x000003D2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r4, #0x1a
	cmp r0, #0
	beq _0807948C
	movs r4, #0x1b
_0807948C:
	ldr r0, _080794A8 @ =0x085ABD30
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_08078bc0
	b _080794D6
	.align 2, 0
_080794A4: .4byte 0x000003D2
_080794A8: .4byte 0x085ABD30
_080794AC:
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	str r1, [r5, #0x20]
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
	adds r0, r5, #0
	bl FUN_080726ec
_080794D6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
