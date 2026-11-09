	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0817421C @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08174220
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08174222
	.align 2, 0
_0817421C: .4byte 0x0000046C
_08174220:
	movs r0, #0
_08174222:
	cmp r0, #0
	beq _08174266
	movs r3, #0x20
	ldr r5, _0817424C @ =0x00000474
	adds r2, r4, r5
	ldrh r1, [r2]
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08174250 @ =0x00001008
	add r2, r8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ands r0, r3
	cmp r0, #0
	beq _08174254
	movs r0, #1
	b _08174256
	.align 2, 0
_0817424C: .4byte 0x00000474
_08174250: .4byte 0x00001008
_08174254:
	movs r0, #0
_08174256:
	cmp r0, #0
	beq _08174266
	bl Entity081f73ec_RequestDive
	movs r0, #0xf7
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08174266:
	movs r7, #0xa
	ldrsh r1, [r4, r7]
	ldr r0, _08174294 @ =0xFFFFF800
	ldrh r6, [r4, #0xa]
	cmp r1, r0
	ble _08174324
	mov r3, sp
	ldrb r5, [r4, #5]
	ldr r2, _08174298 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	cmp r0, #0
	blt _0817429C
	asrs r1, r0, #0xc
	b _081742A2
	.align 2, 0
_08174294: .4byte 0xFFFFF800
_08174298: .4byte gSineTable
_0817429C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081742A2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _081742BC
	asrs r0, r0, #0xc
	b _081742C2
_081742BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081742C2:
	strh r0, [r3, #4]
	adds r0, r6, #0
	subs r0, #0x64
	strh r0, [r4, #0xa]
	ldr r0, [r4, #0x44]
	ldr r0, [r0]
	cmp r0, #0
	bne _0817432A
	movs r3, #0xa
	ldrsh r1, [r4, r3]
	ldr r5, _08174308 @ =0x00000472
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r1, r0
	bge _0817432A
	adds r0, r4, #0
	adds r0, #8
	movs r1, #3
	bl FUN_08176530
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x20
	ldr r0, _0817430C @ =0x00001008
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08174310
	movs r0, #1
	b _08174312
	.align 2, 0
_08174308: .4byte 0x00000472
_0817430C: .4byte 0x00001008
_08174310:
	movs r0, #0
_08174312:
	cmp r0, #0
	bne _0817432A
	ldr r0, _08174320 @ =0x000001A5
	bl PlaySound_082406e0
	b _0817432A
	.align 2, 0
_08174320: .4byte 0x000001A5
_08174324:
	movs r0, #0xf8
	lsls r0, r0, #8
	strh r0, [r4, #0xa]
_0817432A:
	ldr r7, _08174344 @ =0x00000484
	adds r0, r4, r7
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _08174348
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #4
	movs r3, #0
	bl FUN_08177d34
	b _08174354
	.align 2, 0
_08174344: .4byte 0x00000484
_08174348:
	ldr r3, _081743FC @ =0x0000A410
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #6
	bl FUN_08177d34
_08174354:
	movs r6, #0
	ldr r1, _08174400 @ =0x00001012
	add r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	bge _081743DC
	add r3, sp, #8
	adds r5, r4, #0
	adds r5, #8
	str r5, [sp, #0x14]
	ldr r7, _08174404 @ =0x00000472
	adds r7, r4, r7
	str r7, [sp, #0x10]
	mov sl, r1
	mov r5, r8
	mov ip, r6
	movs r0, #0x92
	lsls r0, r0, #1
	mov sb, r0
_0817437C:
	mov r2, ip
	add r2, r8
	ldr r1, _08174408 @ =0x00000674
	adds r2, r2, r1
	ldrh r0, [r2]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldr r7, [sp, #0x14]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	movs r0, #0xfa
	lsls r0, r0, #7
	cmp r1, r0
	ble _081743CC
	ldr r0, _0817440C @ =0x00000676
	adds r2, r5, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r7, [sp, #0x10]
	ldrh r1, [r7]
	cmp r0, r1
	bge _081743CC
	strh r1, [r2]
_081743CC:
	add r5, sb
	add ip, sb
	adds r6, #1
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	blt _0817437C
_081743DC:
	mov r0, r8
	bl FUN_08176c60
	cmp r0, #0
	blt _081743E8
	b _0817454C
_081743E8:
	movs r1, #0x20
	ldr r0, _08174410 @ =0x00001008
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08174414
	movs r0, #1
	b _08174416
	.align 2, 0
_081743FC: .4byte 0x0000A410
_08174400: .4byte 0x00001012
_08174404: .4byte 0x00000472
_08174408: .4byte 0x00000674
_0817440C: .4byte 0x00000676
_08174410: .4byte 0x00001008
_08174414:
	movs r0, #0
_08174416:
	adds r2, r0, #0
	cmp r2, #0
	beq _08174458
	ldr r3, _08174450 @ =0x00000484
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0xa0
	bgt _08174428
	b _0817454C
_08174428:
	movs r2, #0x13
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	strb r1, [r0]
	ldr r7, _08174454 @ =0x00000469
	adds r0, r4, r7
	strb r1, [r0]
	subs r3, #0x1a
	adds r0, r4, r3
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r4, r5
	str r1, [r0]
	adds r7, #3
	adds r1, r4, r7
	movs r0, #1
	strb r0, [r1]
	b _0817454C
	.align 2, 0
_08174450: .4byte 0x00000484
_08174454: .4byte 0x00000469
_08174458:
	ldr r1, _081744A0 @ =0x00000484
	adds r0, r4, r1
	ldr r1, _081744A4 @ =0x00000F98
	add r1, r8
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	ble _0817454C
	ldr r3, _081744A8 @ =0x00000F96
	add r3, r8
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	ble _081744B4
	movs r1, #0xe
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r4, r5
	strb r2, [r0]
	ldr r7, _081744AC @ =0x00000469
	adds r0, r4, r7
	strb r2, [r0]
	adds r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	adds r7, #0x1b
	adds r0, r4, r7
	str r2, [r0]
	ldr r0, _081744B0 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	b _08174556
	.align 2, 0
_081744A0: .4byte 0x00000484
_081744A4: .4byte 0x00000F98
_081744A8: .4byte 0x00000F96
_081744AC: .4byte 0x00000469
_081744B0: .4byte 0x0000046C
_081744B4:
	ldr r5, _081744E8 @ =0x00000F97
	add r5, r8
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #4
	ble _081744FC
	movs r1, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	ldr r5, _081744EC @ =0x00000469
	adds r0, r4, r5
	strb r2, [r0]
	ldr r7, _081744F0 @ =0x0000046A
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _081744F4 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	ldr r2, _081744F8 @ =0x0000046C
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _08174556
	.align 2, 0
_081744E8: .4byte 0x00000F97
_081744EC: .4byte 0x00000469
_081744F0: .4byte 0x0000046A
_081744F4: .4byte 0x00000484
_081744F8: .4byte 0x0000046C
_081744FC:
	movs r1, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	ldr r7, _08174540 @ =0x00000469
	adds r0, r4, r7
	strb r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r7, #0x1b
	adds r0, r4, r7
	str r2, [r0]
	ldr r0, _08174544 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08174548 @ =0x00000474
	adds r2, r4, r1
	subs r0, #0x22
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #8
	movs r1, #3
	bl FUN_08176530
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08174556
	.align 2, 0
_08174540: .4byte 0x00000469
_08174544: .4byte 0x0000046C
_08174548: .4byte 0x00000474
_0817454C:
	ldr r2, _08174568 @ =0x00000484
	adds r1, r4, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08174556:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08174568: .4byte 0x00000484
