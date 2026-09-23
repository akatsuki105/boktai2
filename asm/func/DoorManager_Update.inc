	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	mov r8, r0
	ldrh r0, [r0, #0x1a]
	cmp r0, #0
	bne _080210AC
	bl _08021B16
_080210AC:
	movs r0, #0
	mov sl, r0
	mov r2, r8
	adds r2, #0x38
	mov r1, r8
	ldrb r1, [r1, #0x1c]
	cmp sl, r1
	bge _080210D2
	mov r1, r8
	adds r1, #0x1e
_080210C0:
	ldrh r0, [r1]
	strh r0, [r1, #8]
	adds r1, #2
	movs r3, #1
	add sl, r3
	mov r0, r8
	ldrb r0, [r0, #0x1c]
	cmp sl, r0
	blt _080210C0
_080210D2:
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	movs r1, #0
	mov r3, r8
	strb r0, [r3, #0x1d]
	strb r1, [r3, #0x1c]
	ldrh r0, [r3, #0x18]
	adds r1, r2, #0
	bl FUN_08230f94
	adds r4, r0, #0
	mov r0, r8
	ldr r5, [r0, #0x38]
	b _0802115C
_080210EE:
	ldr r0, [r5, #4]
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #5
	bhi _0802115A
	lsls r0, r1, #2
	ldr r1, _08021104 @ =_08021108
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021104: .4byte _08021108
_08021108: @ jump table
	.4byte _08021120 @ case 0
	.4byte _0802112A @ case 1
	.4byte _08021134 @ case 2
	.4byte _0802113E @ case 3
	.4byte _08021148 @ case 4
	.4byte _08021152 @ case 5
_08021120:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fc88
	b _0802115A
_0802112A:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fd10
	b _0802115A
_08021134:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fd88
	b _0802115A
_0802113E:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fdf0
	b _0802115A
_08021148:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fe58
	b _0802115A
_08021152:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fe98
_0802115A:
	adds r5, #8
_0802115C:
	adds r0, r4, #0
	subs r4, #1
	cmp r0, #0
	bgt _080210EE
	ldr r0, _080211D0 @ =0x030046A0
	ldr r1, [r0]
	ldr r2, _080211D4 @ =0xFFFF0000
	ldrh r0, [r1, #0x30]
	str r0, [sp]
	ldrh r1, [r1, #0x34]
	mov r3, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	movs r1, #0
	mov sl, r1
	mov r2, r8
	ldrh r2, [r2, #0x1a]
	cmp sl, r2
	blt _08021196
	bl _08021A74
_08021196:
	ldr r2, _080211D8 @ =0x0000042C
	add r2, r8
	movs r0, #0x8c
	mov r1, sl
	muls r1, r0, r1
	ldr r0, [r2]
	adds r7, r0, r1
	adds r0, r7, #0
	adds r0, #0x39
	ldrb r0, [r0]
	strh r0, [r7, #0x10]
	adds r0, r7, #0
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #0
	beq _080211F4
	adds r1, r7, #0
	adds r1, #0x42
	ldr r0, _080211D0 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080211DC
	movs r0, #1
	b _080211DE
	.align 2, 0
_080211D0: .4byte 0x030046A0
_080211D4: .4byte 0xFFFF0000
_080211D8: .4byte 0x0000042C
_080211DC:
	movs r0, #0
_080211DE:
	cmp r0, #0
	beq _080211EC
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _080211F2
_080211EC:
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
_080211F2:
	str r0, [r7]
_080211F4:
	adds r0, r7, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0x10
	bls _08021202
	bl _08021A64
_08021202:
	lsls r0, r0, #2
	ldr r1, _0802120C @ =_08021210
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802120C: .4byte _08021210
_08021210: @ jump table
	.4byte _08021254 @ case 0
	.4byte _08021388 @ case 1
	.4byte _08021390 @ case 2
	.4byte _08021816 @ case 3
	.4byte _08021482 @ case 4
	.4byte _080215B4 @ case 5
	.4byte _080216E8 @ case 6
	.4byte _08021816 @ case 7
	.4byte _08021390 @ case 8
	.4byte _08021390 @ case 9
	.4byte _08021390 @ case 10
	.4byte _08021390 @ case 11
	.4byte _08021390 @ case 12
	.4byte _08021390 @ case 13
	.4byte _08021390 @ case 14
	.4byte _08021840 @ case 15
	.4byte _080218E0 @ case 16
_08021254:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021266
	bl _08021A64
_08021266:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _08021378 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0802137C @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021380 @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08021384 @ =0x00012CC7
	cmp r1, r0
	bgt _080212F0
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _080212CA
	rsbs r1, r1, #0
_080212CA:
	cmp r1, #0xfe
	bgt _080212F0
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _080212F0
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_080212F0:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #8
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	bne _08021306
	b _08021A64
_08021306:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0802137C @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021380 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _08021384 @ =0x00012CC7
	cmp r3, r0
	ble _08021358
	b _08021A64
_08021358:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _08021362
	rsbs r1, r1, #0
_08021362:
	cmp r1, #0xfe
	ble _08021368
	b _08021A64
_08021368:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _08021376
	b _08021A64
_08021376:
	b _08021A4E
	.align 2, 0
_08021378: .4byte 0x030046A0
_0802137C: .4byte 0xFFFF0000
_08021380: .4byte 0x0000FFFF
_08021384: .4byte 0x00012CC7
_08021388:
	adds r0, r7, #0
	bl FUN_0801f7f4
	b _08021A64
_08021390:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080213A0
	b _08021A64
_080213A0:
	adds r0, r7, #0
	bl FUN_0801f858
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _08021454 @ =0x030046A0
	ldr r5, [r0]
	ldrh r0, [r5, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08021458 @ =0xFFFF0000
	mov sb, r1
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r5, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r6, _0802145C @ =0x0000FFFF
	ands r6, r1
	orrs r6, r4
	adds r2, r6, #0
	ldrh r1, [r5, #0x34]
	subs r1, r3, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
	ands r0, r3
	adds r3, r0, #0
	orrs r3, r1
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08021460 @ =0x00012CC7
	cmp r1, r0
	bgt _0802147E
	asrs r1, r6, #0x10
	cmp r1, #0
	bge _08021400
	rsbs r1, r1, #0
_08021400:
	cmp r1, #0xfe
	bgt _0802147E
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _0802147E
	adds r0, r7, #0
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	bne _08021468
	ldr r0, _08021464 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802147E
	mov r0, r8
	adds r1, r7, #0
	bl FUN_0801fb08
	cmp r0, #0
	bne _0802147E
	ldr r0, [r7, #0x48]
	cmp r0, #0
	beq _0802147E
	ldr r0, [sp, #0x10]
	mov r3, sb
	ands r0, r3
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #0x50
	add r1, sp, #0x10
	str r0, [r1, #4]
	ldr r0, [r7, #0x48]
	bl Script_ExecById
	b _0802147E
	.align 2, 0
_08021454: .4byte 0x030046A0
_08021458: .4byte 0xFFFF0000
_0802145C: .4byte 0x0000FFFF
_08021460: .4byte 0x00012CC7
_08021464: .4byte 0x030044E0
_08021468:
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_0802147E:
	add r6, sp, #0x18
	b _080219D0
_08021482:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021492
	b _08021A64
_08021492:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _080215A4 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080215A8 @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080215AC @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080215B0 @ =0x00012CC7
	cmp r1, r0
	bgt _0802151C
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _080214F6
	rsbs r1, r1, #0
_080214F6:
	cmp r1, #0xfe
	bgt _0802151C
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _0802151C
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_0802151C:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #0x20
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	bne _08021532
	b _08021A64
_08021532:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080215A8 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080215AC @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _080215B0 @ =0x00012CC7
	cmp r3, r0
	ble _08021584
	b _08021A64
_08021584:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _0802158E
	rsbs r1, r1, #0
_0802158E:
	cmp r1, #0xfe
	ble _08021594
	b _08021A64
_08021594:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _080215A2
	b _08021A64
_080215A2:
	b _08021A4E
	.align 2, 0
_080215A4: .4byte 0x030046A0
_080215A8: .4byte 0xFFFF0000
_080215AC: .4byte 0x0000FFFF
_080215B0: .4byte 0x00012CC7
_080215B4:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080215C4
	b _08021A64
_080215C4:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _080216D8 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080216DC @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080216E0 @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080216E4 @ =0x00012CC7
	cmp r1, r0
	bgt _0802164E
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _08021628
	rsbs r1, r1, #0
_08021628:
	cmp r1, #0xfe
	bgt _0802164E
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _0802164E
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_0802164E:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #0x28
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	bne _08021664
	b _08021A64
_08021664:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080216DC @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080216E0 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _080216E4 @ =0x00012CC7
	cmp r3, r0
	ble _080216B6
	b _08021A64
_080216B6:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _080216C0
	rsbs r1, r1, #0
_080216C0:
	cmp r1, #0xfe
	ble _080216C6
	b _08021A64
_080216C6:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _080216D4
	b _08021A64
_080216D4:
	b _08021A4E
	.align 2, 0
_080216D8: .4byte 0x030046A0
_080216DC: .4byte 0xFFFF0000
_080216E0: .4byte 0x0000FFFF
_080216E4: .4byte 0x00012CC7
_080216E8:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080216F8
	b _08021A64
_080216F8:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _08021830 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08021834 @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021838 @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0802183C @ =0x00012CC7
	cmp r1, r0
	bgt _08021782
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _0802175C
	rsbs r1, r1, #0
_0802175C:
	cmp r1, #0xfe
	bgt _08021782
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021782
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_08021782:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #0x30
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	beq _08021816
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08021834 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021838 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _0802183C @ =0x00012CC7
	cmp r3, r0
	bgt _08021816
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _080217F0
	rsbs r1, r1, #0
_080217F0:
	cmp r1, #0xfe
	bgt _08021816
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021816
	mov r3, r8
	ldrb r0, [r3, #0x1c]
	lsls r0, r0, #1
	mov r1, r8
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	ldrb r0, [r3, #0x1c]
	adds r0, #1
	strb r0, [r3, #0x1c]
_08021816:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021826
	b _08021A64
_08021826:
	adds r0, r7, #0
	bl FUN_0801f764
	b _08021A64
	.align 2, 0
_08021830: .4byte 0x030046A0
_08021834: .4byte 0xFFFF0000
_08021838: .4byte 0x0000FFFF
_0802183C: .4byte 0x00012CC7
_08021840:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r0, _080218CC @ =0x030046A0
	ldr r6, [r0]
	ldr r1, _080218D0 @ =0x00000942
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	bgt _08021858
	b _08021A64
_08021858:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6, #0x30]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080218D4 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080218D8 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #0x34]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _080218DC @ =0x00012CC7
	cmp r3, r0
	ble _080218AA
	b _08021A64
_080218AA:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _080218B4
	rsbs r1, r1, #0
_080218B4:
	cmp r1, #0xfe
	ble _080218BA
	b _08021A64
_080218BA:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _080218C8
	b _08021A64
_080218C8:
	b _08021A4E
	.align 2, 0
_080218CC: .4byte 0x030046A0
_080218D0: .4byte 0x00000942
_080218D4: .4byte 0xFFFF0000
_080218D8: .4byte 0x0000FFFF
_080218DC: .4byte 0x00012CC7
_080218E0:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080218F0
	b _08021A64
_080218F0:
	adds r0, r7, #0
	bl FUN_0801f858
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _080219A4 @ =0x030046A0
	ldr r5, [r0]
	ldrh r0, [r5, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080219A8 @ =0xFFFF0000
	mov sb, r1
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r5, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r6, _080219AC @ =0x0000FFFF
	ands r6, r1
	orrs r6, r4
	adds r2, r6, #0
	ldrh r1, [r5, #0x34]
	subs r1, r3, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
	ands r0, r3
	adds r3, r0, #0
	orrs r3, r1
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080219B0 @ =0x00012CC7
	cmp r1, r0
	bgt _080219CE
	asrs r1, r6, #0x10
	cmp r1, #0
	bge _08021950
	rsbs r1, r1, #0
_08021950:
	cmp r1, #0xfe
	bgt _080219CE
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _080219CE
	adds r0, r7, #0
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	bne _080219B8
	ldr r0, _080219B4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080219CE
	mov r0, r8
	adds r1, r7, #0
	bl FUN_0801fb08
	cmp r0, #0
	bne _080219CE
	ldr r0, [r7, #0x48]
	cmp r0, #0
	beq _080219CE
	ldr r0, [sp, #0x38]
	mov r3, sb
	ands r0, r3
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x38]
	adds r0, r7, #0
	adds r0, #0x50
	add r1, sp, #0x38
	str r0, [r1, #4]
	ldr r0, [r7, #0x48]
	bl Script_ExecById
	b _080219CE
	.align 2, 0
_080219A4: .4byte 0x030046A0
_080219A8: .4byte 0xFFFF0000
_080219AC: .4byte 0x0000FFFF
_080219B0: .4byte 0x00012CC7
_080219B4: .4byte 0x030044E0
_080219B8:
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_080219CE:
	add r6, sp, #0x40
_080219D0:
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	beq _08021A64
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08021AB0 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021AB4 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _08021AB8 @ =0x00012CC7
	cmp r3, r0
	bgt _08021A64
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _08021A34
	rsbs r1, r1, #0
_08021A34:
	cmp r1, #0xfe
	bgt _08021A64
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021A64
	adds r0, r7, #0
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	beq _08021A64
_08021A4E:
	mov r3, r8
	ldrb r0, [r3, #0x1c]
	lsls r0, r0, #1
	mov r1, r8
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	ldrb r0, [r3, #0x1c]
	adds r0, #1
	strb r0, [r3, #0x1c]
_08021A64:
	movs r0, #1
	add sl, r0
	mov r1, r8
	ldrh r1, [r1, #0x1a]
	cmp sl, r1
	bge _08021A74
	bl _08021196
_08021A74:
	movs r2, #0
	mov sl, r2
	mov r3, r8
	ldrb r3, [r3, #0x1d]
	cmp sl, r3
	bge _08021AAA
_08021A80:
	mov r0, sl
	lsls r1, r0, #1
	mov r0, r8
	adds r0, #0x26
	adds r4, r0, r1
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021A9E
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801fd10
_08021A9E:
	movs r1, #1
	add sl, r1
	mov r2, r8
	ldrb r2, [r2, #0x1d]
	cmp sl, r2
	blt _08021A80
_08021AAA:
	movs r3, #0
	mov sl, r3
	b _08021ADE
	.align 2, 0
_08021AB0: .4byte 0xFFFF0000
_08021AB4: .4byte 0x0000FFFF
_08021AB8: .4byte 0x00012CC7
_08021ABC:
	mov r2, sl
	lsls r1, r2, #1
	mov r0, r8
	adds r0, #0x1e
	adds r4, r0, r1
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801fad8
	cmp r0, #0
	bne _08021ADA
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801fc88
_08021ADA:
	movs r3, #1
	add sl, r3
_08021ADE:
	mov r0, r8
	ldrb r0, [r0, #0x1c]
	cmp sl, r0
	blt _08021ABC
	movs r1, #0
	mov sl, r1
	mov r2, r8
	ldrh r2, [r2, #0x1a]
	cmp sl, r2
	bge _08021B16
	ldr r4, _08021B28 @ =0x0000042C
	add r4, r8
_08021AF6:
	movs r0, #0x8c
	mov r1, sl
	muls r1, r0, r1
	ldr r0, [r4]
	adds r0, r0, r1
	ldr r1, [r0, #0x30]
	cmp r1, #0
	beq _08021B0A
	bl _call_via_r1
_08021B0A:
	movs r3, #1
	add sl, r3
	mov r0, r8
	ldrh r0, [r0, #0x1a]
	cmp sl, r0
	blt _08021AF6
_08021B16:
	movs r0, #0
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08021B28: .4byte 0x0000042C
