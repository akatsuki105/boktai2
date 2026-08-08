	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r7, r0, #0
	ldr r1, _080E1F6C @ =0x000001DF
	adds r0, r7, r1
	ldrb r0, [r0]
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080E1F70
	movs r0, #1
	b _080E1F72
	.align 2, 0
_080E1F6C: .4byte 0x000001DF
_080E1F70:
	movs r0, #0
_080E1F72:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sl, r2
	cmp r0, #0
	beq _080E1F80
	b _080E20EA
_080E1F80:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _080E1F9C
	ldr r5, _080E1FC0 @ =0x00000482
	adds r1, r7, r5
	movs r0, #3
	strh r0, [r1]
_080E1F9C:
	ldr r6, _080E1FC4 @ =0x00000202
	adds r1, r7, r6
	ldrh r0, [r1]
	cmp r0, #0
	beq _080E1FAA
	subs r0, #1
	strh r0, [r1]
_080E1FAA:
	ldr r1, _080E1FC8 @ =0x000001DF
	adds r0, r7, r1
	ldrb r0, [r0]
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080E1FCC
	movs r0, #1
	b _080E1FCE
	.align 2, 0
_080E1FC0: .4byte 0x00000482
_080E1FC4: .4byte 0x00000202
_080E1FC8: .4byte 0x000001DF
_080E1FCC:
	movs r0, #0
_080E1FCE:
	cmp r0, #0
	bne _080E201A
	adds r0, r7, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080E201A
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0
	bgt _080E2006
	strh r3, [r1]
	movs r0, #0xc0
	ldr r1, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080E200A
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r1, r0
	str r1, [r4]
	b _080E200A
_080E2006:
	subs r0, r2, #1
	strh r0, [r1]
_080E200A:
	movs r6, #0x91
	lsls r6, r6, #3
	adds r1, r7, r6
	ldrh r0, [r1]
	cmp r0, #0
	beq _080E201A
	subs r0, #1
	strh r0, [r1]
_080E201A:
	movs r2, #0x80
	lsls r2, r2, #2
	ldr r0, _080E2030 @ =0x00000474
	adds r1, r7, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _080E2034
	movs r0, #1
	b _080E2036
	.align 2, 0
_080E2030: .4byte 0x00000474
_080E2034:
	movs r0, #0
_080E2036:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sl, r1
	cmp r0, #0
	beq _080E20EA
	movs r3, #0
	movs r1, #0x80
	lsls r1, r1, #5
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080E2054
	movs r0, #1
	b _080E2056
_080E2054:
	movs r0, #0
_080E2056:
	cmp r0, #0
	beq _080E2064
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sl, r2
	b _080E20B0
_080E2064:
	ldr r2, _080E20D8 @ =0x0000A03F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r7, r4
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	bne _080E20B0
	movs r5, #0x8e
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _080E20B0
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _080E20AA
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _080E20AA
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	beq _080E20AC
_080E20AA:
	movs r3, #1
_080E20AC:
	cmp r3, #0
	beq _080E20BE
_080E20B0:
	movs r1, #0x80
	lsls r1, r1, #8
	mov r6, sl
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080E20CA
_080E20BE:
	adds r0, r7, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E20DC
_080E20CA:
	adds r2, r7, #0
	adds r2, #0x7c
	movs r1, #1
	ldr r0, [r2, #4]
	orrs r0, r1
	b _080E20E8
	.align 2, 0
_080E20D8: .4byte 0x0000A03F
_080E20DC:
	adds r2, r7, #0
	adds r2, #0x7c
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2, #4]
	ands r0, r1
_080E20E8:
	str r0, [r2, #4]
_080E20EA:
	movs r2, #0x80
	lsls r2, r2, #0xb
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _080E2174
	ldr r0, _080E2130 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	ldr r0, _080E2134 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080E2138 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	bgt _080E2140
	movs r1, #0x80
	lsls r1, r1, #0xc
	mov r3, sb
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _080E216C
	ldr r5, _080E213C @ =0x00000496
	adds r1, r7, r5
	movs r0, #0x33
	b _080E2172
	.align 2, 0
_080E2130: .4byte 0x030047A4
_080E2134: .4byte 0x030046A0
_080E2138: .4byte 0x00000942
_080E213C: .4byte 0x00000496
_080E2140:
	cmp r0, #6
	bgt _080E2150
	ldr r6, _080E214C @ =0x00000496
	adds r1, r7, r6
	movs r0, #0x32
	b _080E2172
	.align 2, 0
_080E214C: .4byte 0x00000496
_080E2150:
	movs r1, #0x80
	lsls r1, r1, #0xc
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080E216C
	ldr r3, _080E2168 @ =0x00000496
	adds r1, r7, r3
	movs r0, #0x33
	b _080E2172
	.align 2, 0
_080E2168: .4byte 0x00000496
_080E216C:
	ldr r4, _080E21A4 @ =0x00000496
	adds r1, r7, r4
	movs r0, #0x21
_080E2172:
	strh r0, [r1]
_080E2174:
	movs r0, #0x80
	lsls r0, r0, #8
	mov r5, sb
	ldr r1, [r5]
	ands r0, r1
	cmp r0, #0
	bne _080E2184
	b _080E2278
_080E2184:
	movs r0, #0x80
	lsls r0, r0, #0x12
	ands r1, r0
	cmp r1, #0
	beq _080E21BA
	ldr r6, _080E21A8 @ =0x00000494
	adds r1, r7, r6
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080E21AC
	subs r0, r2, #1
	strh r0, [r1]
	b _080E21BA
	.align 2, 0
_080E21A4: .4byte 0x00000496
_080E21A8: .4byte 0x00000494
_080E21AC:
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080E21D0 @ =0xFDFFFFFF
	mov r4, sb
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_080E21BA:
	ldr r5, _080E21D4 @ =0x00000492
	adds r0, r7, r5
	ldrh r2, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r5, r0, #0
	cmp r1, #0
	ble _080E21D8
	subs r0, r2, #1
	strh r0, [r5]
	b _080E2640
	.align 2, 0
_080E21D0: .4byte 0xFDFFFFFF
_080E21D4: .4byte 0x00000492
_080E21D8:
	movs r1, #0x80
	lsls r1, r1, #0x12
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r4, r7, r3
	cmp r0, #0
	bne _080E21F6
	movs r1, #0x40
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080E2230
_080E21F6:
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080E221C
	ldr r4, _080E2214 @ =0x00000476
	adds r0, r7, r4
	ldrh r1, [r0]
	ldr r6, _080E2218 @ =0x0000025D
	adds r0, r7, r6
_080E220C:
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E224A
	b _080E225C
	.align 2, 0
_080E2214: .4byte 0x00000476
_080E2218: .4byte 0x0000025D
_080E221C:
	ldr r1, _080E2228 @ =0x0000047E
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _080E222C @ =0x0000025D
	adds r0, r7, r2
	b _080E220C
	.align 2, 0
_080E2228: .4byte 0x0000047E
_080E222C: .4byte 0x0000025D
_080E2230:
	ldr r3, _080E2254 @ =0x0000047A
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r7, r4
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r6, _080E2258 @ =0x0000025D
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E225C
_080E224A:
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080E2268
	.align 2, 0
_080E2254: .4byte 0x0000047A
_080E2258: .4byte 0x0000025D
_080E225C:
	ldr r2, [r7, #0x44]
	ldr r0, _080E2270 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080E2268:
	movs r0, #0
	strh r0, [r5]
	ldr r1, _080E2274 @ =0xFFFF7FFF
	b _080E2638
	.align 2, 0
_080E2270: .4byte 0x03003584
_080E2274: .4byte 0xFFFF7FFF
_080E2278:
	movs r3, #0x80
	lsls r3, r3, #0x12
	ands r1, r3
	cmp r1, #0
	bne _080E2284
	b _080E23A4
_080E2284:
	ldr r3, _080E22A4 @ =0x00000494
	adds r0, r7, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	adds r5, r0, #0
	cmp r1, #0
	ble _080E2340
	cmp r1, #0x40
	bgt _080E2334
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r0, #0
	blt _080E22A8
	asrs r1, r0, #2
	b _080E22AE
	.align 2, 0
_080E22A4: .4byte 0x00000494
_080E22A8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080E22AE:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080E22DC
	ldr r1, _080E22D4 @ =0x0000047A
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r3, _080E22D8 @ =0x0000025D
	adds r0, r7, r3
_080E22CA:
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E2314
	b _080E2328
	.align 2, 0
_080E22D4: .4byte 0x0000047A
_080E22D8: .4byte 0x0000025D
_080E22DC:
	movs r1, #0x80
	lsls r1, r1, #7
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E2304
	ldr r6, _080E22FC @ =0x00000476
	adds r0, r7, r6
	ldrh r1, [r0]
	ldr r2, _080E2300 @ =0x0000025D
	adds r0, r7, r2
	b _080E22CA
	.align 2, 0
_080E22FC: .4byte 0x00000476
_080E2300: .4byte 0x0000025D
_080E2304:
	ldr r3, _080E2320 @ =0x0000047E
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, _080E2324 @ =0x0000025D
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E2328
_080E2314:
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080E2334
	.align 2, 0
_080E2320: .4byte 0x0000047E
_080E2324: .4byte 0x0000025D
_080E2328:
	ldr r2, [r7, #0x44]
	ldr r0, _080E233C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080E2334:
	ldrh r0, [r5]
	subs r0, #1
	b _080E24EC
	.align 2, 0
_080E233C: .4byte 0x03003584
_080E2340:
	ldr r6, _080E2364 @ =0x0000047A
	adds r0, r7, r6
	ldrh r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r3, _080E2368 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E236C
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080E2378
	.align 2, 0
_080E2364: .4byte 0x0000047A
_080E2368: .4byte 0x0000025D
_080E236C:
	ldr r2, [r7, #0x44]
	ldr r0, _080E2398 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080E2378:
	movs r0, #0
	strh r0, [r5]
	ldr r1, _080E239C @ =0xFDFFFFFF
	mov r4, sb
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _080E23A0 @ =0xFFFFBFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080E24EE
	.align 2, 0
_080E2398: .4byte 0x03003584
_080E239C: .4byte 0xFDFFFFFF
_080E23A0: .4byte 0xFFFFBFFF
_080E23A4:
	movs r0, #0xc0
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r2, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	bne _080E23B8
	b _080E24EE
_080E23B8:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080E2440
	ldr r0, _080E23EC @ =0xFFFFBEBF
	ands r0, r2
	str r0, [r4]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080E23F4
	mov r1, sb
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r2, _080E23F0 @ =0x00000494
	adds r1, r7, r2
	movs r0, #0x40
	strh r0, [r1]
	b _080E2640
	.align 2, 0
_080E23EC: .4byte 0xFFFFBEBF
_080E23F0: .4byte 0x00000494
_080E23F4:
	ldr r3, _080E2418 @ =0x0000047A
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r7, r4
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r5, _080E241C @ =0x0000025D
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E2420
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080E242C
	.align 2, 0
_080E2418: .4byte 0x0000047A
_080E241C: .4byte 0x0000025D
_080E2420:
	ldr r2, [r7, #0x44]
	ldr r0, _080E2438 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080E242C:
	ldr r6, _080E243C @ =0x00000494
	adds r1, r7, r6
	movs r0, #0
	strh r0, [r1]
	b _080E24EE
	.align 2, 0
_080E2438: .4byte 0x03003584
_080E243C: .4byte 0x00000494
_080E2440:
	ldr r1, _080E2460 @ =0x00000494
	adds r0, r7, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r5, r0, #0
	cmp r1, #0
	blt _080E24EE
	cmp r1, #0x40
	bgt _080E24EE
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r0, #0
	blt _080E2464
	asrs r1, r0, #2
	b _080E246A
	.align 2, 0
_080E2460: .4byte 0x00000494
_080E2464:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080E246A:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080E2498
	ldr r4, _080E2490 @ =0x0000047A
	adds r0, r7, r4
	ldrh r1, [r0]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r0, r7, r6
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r2, _080E2494 @ =0x0000025D
	adds r0, r7, r2
_080E2486:
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E24C8
	b _080E24DC
	.align 2, 0
_080E2490: .4byte 0x0000047A
_080E2494: .4byte 0x0000025D
_080E2498:
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080E24B8
	ldr r3, _080E24B0 @ =0x00000476
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, _080E24B4 @ =0x0000025D
	adds r0, r7, r4
	b _080E2486
	.align 2, 0
_080E24B0: .4byte 0x00000476
_080E24B4: .4byte 0x0000025D
_080E24B8:
	ldr r6, _080E24D4 @ =0x0000047E
	adds r0, r7, r6
	ldrh r1, [r0]
	ldr r2, _080E24D8 @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E24DC
_080E24C8:
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080E24E8
	.align 2, 0
_080E24D4: .4byte 0x0000047E
_080E24D8: .4byte 0x0000025D
_080E24DC:
	ldr r2, [r7, #0x44]
	ldr r0, _080E2504 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_080E24E8:
	ldrh r0, [r5]
	adds r0, #1
_080E24EC:
	strh r0, [r5]
_080E24EE:
	ldr r0, _080E2508 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #7
	ands r1, r2
	adds r3, r0, #0
	cmp r1, #0
	beq _080E250C
	movs r0, #1
	b _080E250E
	.align 2, 0
_080E2504: .4byte 0x03003584
_080E2508: .4byte 0x030047A4
_080E250C:
	movs r0, #0
_080E250E:
	cmp r0, #0
	beq _080E252C
	ldr r0, _080E2528 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080E251C
	b _080E2640
_080E251C:
	movs r4, #0x18
	ldrsh r2, [r0, r4]
	cmp r2, #0
	bge _080E252E
	b _080E2640
	.align 2, 0
_080E2528: .4byte 0x03002C68
_080E252C:
	movs r2, #0
_080E252E:
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080E2574
	ldr r1, _080E2564 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080E2570
	ldr r5, _080E2568 @ =0x00000446
	adds r0, r1, r5
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _080E255E
	ldr r6, _080E256C @ =0x00000442
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #4
	bne _080E255E
	movs r2, #1
_080E255E:
	adds r0, r2, #0
	b _080E25A4
	.align 2, 0
_080E2564: .4byte 0x03002BE0
_080E2568: .4byte 0x00000446
_080E256C: .4byte 0x00000442
_080E2570:
	movs r0, #0
	b _080E25A4
_080E2574:
	ldr r0, _080E25E8 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _080E25A8
	ldr r0, _080E25EC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _080E25A8
	ldr r0, _080E25F0 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080E25A2
	ldr r0, _080E25F4 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _080E25A2
	movs r1, #1
_080E25A2:
	adds r0, r1, #0
_080E25A4:
	cmp r0, #0
	beq _080E2600
_080E25A8:
	movs r5, #0x80
	lsls r5, r5, #0xa
	mov r3, sb
	ldr r4, [r3]
	ands r4, r5
	cmp r4, #0
	bne _080E2640
	movs r6, #0x8f
	lsls r6, r6, #3
	adds r0, r7, r6
	ldrh r0, [r0]
	ldr r2, _080E25F8 @ =0x0000047A
	adds r1, r7, r2
	ldrh r1, [r1]
	movs r3, #0x90
	lsls r3, r3, #3
	adds r2, r7, r3
	ldrh r2, [r2]
	adds r1, r1, r2
	ldr r6, _080E25FC @ =0x000001DF
	adds r2, r7, r6
	ldrb r3, [r2]
	str r4, [sp]
	movs r2, #0
	bl FUN_080eeb14
	mov r1, sb
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	b _080E2640
	.align 2, 0
_080E25E8: .4byte 0x03002B48
_080E25EC: .4byte 0x030046A0
_080E25F0: .4byte 0x03002B8C
_080E25F4: .4byte 0x03002B60
_080E25F8: .4byte 0x0000047A
_080E25FC: .4byte 0x000001DF
_080E2600:
	movs r1, #0x80
	lsls r1, r1, #0xa
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080E2640
	ldr r3, _080E2750 @ =0x0000047A
	adds r0, r7, r3
	ldrh r0, [r0]
	movs r4, #0x90
	lsls r4, r4, #3
	adds r1, r7, r4
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r1, r7, r5
	ldrh r1, [r1]
	ldr r6, _080E2754 @ =0x000001DF
	adds r2, r7, r6
	ldrb r3, [r2]
	movs r2, #1
	str r2, [sp]
	movs r2, #0
	bl FUN_080eeb14
	ldr r1, _080E2758 @ =0xFFFDFFFF
_080E2638:
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_080E2640:
	movs r1, #0x40
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _080E264E
	b _080E287C
_080E264E:
	movs r1, #0x80
	lsls r1, r1, #0xa
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r5, [r0]
	ands r5, r1
	adds r4, r0, #0
	cmp r5, #0
	beq _080E2664
	b _080E287C
_080E2664:
	movs r0, #0x80
	lsls r0, r0, #5
	mov r6, sb
	ldr r1, [r6]
	ands r0, r1
	cmp r0, #0
	bne _080E2674
	b _080E287C
_080E2674:
	ldr r0, _080E275C @ =0xFFFEBE3F
	ands r1, r0
	str r1, [r6]
	ldr r1, _080E2760 @ =0x0000021E
	adds r0, r7, r1
	movs r6, #0
	strh r5, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r5, [r0]
	ldr r3, _080E2764 @ =0x00000202
	adds r0, r7, r3
	strh r5, [r0]
	ldr r1, _080E2768 @ =0xFFFFEFFF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldrh r1, [r7, #8]
	adds r3, #0xa
	adds r0, r7, r3
	strh r1, [r0]
	ldrh r1, [r7, #0xc]
	movs r2, #0x84
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r1, [r7, #8]
	adds r3, #8
	adds r0, r7, r3
	strh r1, [r0]
	ldrh r1, [r7, #0xc]
	adds r2, #8
	adds r0, r7, r2
	strh r1, [r0]
	subs r3, #0x82
	adds r2, r7, r3
	movs r1, #0xc7
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	blt _080E26DC
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	strh r0, [r2]
_080E26DC:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bgt _080E27A0
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _080E276C @ =0x00000469
	adds r0, r7, r3
	strb r6, [r0]
	ldr r1, _080E2770 @ =0x0000046A
	adds r0, r7, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	mov r8, r0
	movs r2, #0x11
	adds r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _080E2774 @ =0x0000046B
	adds r0, r7, r1
	strb r6, [r0]
	adds r3, #0xe6
	adds r0, r7, r3
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	mov r1, r8
	str r1, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	ldr r0, _080E2778 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080E277C
	movs r0, #1
	b _080E277E
	.align 2, 0
_080E2750: .4byte 0x0000047A
_080E2754: .4byte 0x000001DF
_080E2758: .4byte 0xFFFDFFFF
_080E275C: .4byte 0xFFFEBE3F
_080E2760: .4byte 0x0000021E
_080E2764: .4byte 0x00000202
_080E2768: .4byte 0xFFFFEFFF
_080E276C: .4byte 0x00000469
_080E2770: .4byte 0x0000046A
_080E2774: .4byte 0x0000046B
_080E2778: .4byte 0x030047A4
_080E277C:
	movs r0, #0
_080E277E:
	cmp r0, #0
	bne _080E287C
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _080E287C
	ldr r0, _080E279C @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl FUN_080ec5b4
	b _080E287C
	.align 2, 0
_080E279C: .4byte 0x03002B28
_080E27A0:
	movs r0, #0x80
	lsls r0, r0, #2
	mov r3, sb
	ldr r4, [r3]
	ands r4, r0
	cmp r4, #0
	beq _080E2814
	ldr r4, _080E27FC @ =0x000005CC
	adds r0, r7, r4
	ldr r2, [r0]
	movs r1, #0x12
	ldr r3, _080E2800 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _080E2804 @ =0x0000046B
	adds r0, r7, r4
	strb r6, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #3
	subs r4, #0xeb
	adds r0, r7, r4
	strb r1, [r0]
	ldr r1, _080E2808 @ =0x00000469
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _080E280C @ =0x0000046A
	adds r0, r7, r2
	strb r6, [r0]
	adds r4, #0x1c
	adds r0, r7, r4
	str r5, [r0]
	ldr r5, _080E2810 @ =0x0000046C
	adds r0, r7, r5
	b _080E287A
	.align 2, 0
_080E27FC: .4byte 0x000005CC
_080E2800: .4byte 0x0000046D
_080E2804: .4byte 0x0000046B
_080E2808: .4byte 0x00000469
_080E280C: .4byte 0x0000046A
_080E2810: .4byte 0x0000046C
_080E2814:
	ldr r1, _080E28D4 @ =0x000001DF
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x7f
	bl FUN_080e5718
	ldr r2, _080E28D8 @ =0x000005FC
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	ldr r3, _080E28DC @ =0x00000594
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #7
	ldr r5, _080E28E0 @ =0x0000046D
	adds r0, r7, r5
	movs r3, #1
	strb r3, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r6, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _080E28E4 @ =0x00000469
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _080E28E8 @ =0x0000046A
	adds r0, r7, r2
	strb r6, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r4, [r0]
	ldr r6, _080E28EC @ =0x0000046C
	adds r0, r7, r6
_080E287A:
	strb r3, [r0]
_080E287C:
	movs r0, #0x40
	mov r1, sl
	ldrh r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _080E288A
	b _080E2A0A
_080E288A:
	movs r1, #0x80
	lsls r1, r1, #0xa
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _080E289E
	b _080E2A0A
_080E289E:
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	bgt _080E2920
	movs r6, #0x8e
	lsls r6, r6, #1
	adds r1, r7, r6
	ldrh r0, [r1]
	cmp r0, #0
	bne _080E28BA
	b _080E2A0A
_080E28BA:
	strh r2, [r1]
	ldr r1, _080E28F0 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E28F4
	ldr r2, [r7, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080E2902
	.align 2, 0
_080E28D4: .4byte 0x000001DF
_080E28D8: .4byte 0x000005FC
_080E28DC: .4byte 0x00000594
_080E28E0: .4byte 0x0000046D
_080E28E4: .4byte 0x00000469
_080E28E8: .4byte 0x0000046A
_080E28EC: .4byte 0x0000046C
_080E28F0: .4byte 0x0000025D
_080E28F4:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080E2902:
	ldr r2, _080E291C @ =0x0000044C
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E290E
	b _080E2A0A
_080E290E:
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r7, r3
	bl FUN_08013698
	b _080E2A0A
	.align 2, 0
_080E291C: .4byte 0x0000044C
_080E2920:
	movs r4, #0x8e
	lsls r4, r4, #1
	adds r1, r7, r4
	ldrh r0, [r1]
	lsls r2, r0, #0x10
	adds r6, r1, #0
	cmp r2, #0
	beq _080E2A0A
	movs r0, #0x20
	ands r3, r0
	cmp r3, #0
	bne _080E2A0A
	lsrs r0, r2, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080E298C
	ldr r5, _080E295C @ =0x0000025D
	adds r0, r7, r5
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080E2960
	ldr r2, [r7, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080E296E
	.align 2, 0
_080E295C: .4byte 0x0000025D
_080E2960:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080E296E:
	ldr r1, _080E2988 @ =0x0000044C
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _080E29C8
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r7, r2
	bl FUN_08013698
	b _080E29C8
	.align 2, 0
_080E2988: .4byte 0x0000044C
_080E298C:
	movs r2, #1
	ldr r3, _080E29A4 @ =0x0000025D
	adds r0, r7, r3
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080E29A8
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080E29B2
	.align 2, 0
_080E29A4: .4byte 0x0000025D
_080E29A8:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_080E29B2:
	ldr r4, _080E29E8 @ =0x0000044C
	adds r0, r7, r4
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _080E29C8
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_080136b4
_080E29C8:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080E2A0A
	ldrb r0, [r5]
	cmp r0, #0
	bne _080E29EC
	ldr r2, [r7, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080E29FA
	.align 2, 0
_080E29E8: .4byte 0x0000044C
_080E29EC:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080E29FA:
	ldrb r0, [r4]
	cmp r0, #0
	bne _080E2A0A
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r7, r2
	bl FUN_08013698
_080E2A0A:
	mov r3, sl
	ldrh r0, [r3]
	cmp r0, #0
	bne _080E2A24
	ldr r1, _080E2A20 @ =0xFFFFDFFF
	mov r4, sb
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	b _080E3116
	.align 2, 0
_080E2A20: .4byte 0xFFFFDFFF
_080E2A24:
	adds r0, r7, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080E2ACC
	movs r5, #0x80
	lsls r5, r5, #5
	mov r6, sl
	ldrh r0, [r6]
	ands r0, r5
	cmp r0, #0
	beq _080E2A56
	movs r0, #0x97
	lsls r0, r0, #3
	adds r4, r7, r0
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r6]
	bics r0, r5
	movs r1, #0
	strh r0, [r6]
	str r1, [r4]
_080E2A56:
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080E2A94
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _080E2AB4 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _080E2AB8 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r0, [r4]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r4]
	movs r5, #0x87
	lsls r5, r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _080E2ABC @ =0x0000021E
	adds r0, r7, r6
	strh r3, [r0]
	ldr r1, _080E2AC0 @ =0x00000202
	adds r0, r7, r1
	strh r3, [r0]
_080E2A94:
	movs r1, #0
	movs r0, #0x40
	mov r2, sl
	strh r0, [r2]
	ldr r3, _080E2AC4 @ =0x0000048C
	adds r0, r7, r3
	strb r1, [r0]
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, _080E2AC8 @ =0xFFFFF67F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080E3116
	.align 2, 0
_080E2AB4: .4byte 0xFEFFFFFF
_080E2AB8: .4byte 0xFFFFFDFF
_080E2ABC: .4byte 0x0000021E
_080E2AC0: .4byte 0x00000202
_080E2AC4: .4byte 0x0000048C
_080E2AC8: .4byte 0xFFFFF67F
_080E2ACC:
	movs r5, #0x80
	lsls r5, r5, #6
	mov r8, r5
	mov r6, sl
	ldrh r2, [r6]
	adds r1, r2, #0
	adds r0, r1, #0
	ands r0, r5
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _080E2BB4
	ldr r0, _080E2B84 @ =0x00000482
	adds r5, r7, r0
	movs r3, #0
	movs r6, #1
	strh r6, [r5]
	ldr r1, _080E2B88 @ =0x00000222
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _080E2B8C @ =0x0000024E
	adds r0, r7, r2
	strh r4, [r0]
	ldr r0, _080E2B90 @ =0xFFFFFC7F
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080E2B94 @ =0xF3FFFFFF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080E2B44
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _080E2B98 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080E2B9C @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _080E2BA0 @ =0x0000021E
	adds r0, r7, r2
	strh r4, [r0]
	subs r1, #0x1a
	adds r0, r7, r1
	strh r4, [r0]
_080E2B44:
	movs r2, #0x80
	lsls r2, r2, #3
	mov r3, sl
	ldrh r0, [r3]
	bics r0, r2
	strh r0, [r3]
	ldr r4, _080E2BA4 @ =0x00000542
	adds r1, r7, r4
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080E2BA8 @ =0xFBFFFFFF
	mov r3, sb
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r0, _080E2BAC @ =0xFFFFFAFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r3, r7, r0
	ldrh r0, [r3]
	orrs r2, r0
	strh r2, [r3]
	strh r6, [r5]
	ldr r0, _080E2BB0 @ =0xFFFFF67F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _080E2EDA
	.align 2, 0
_080E2B84: .4byte 0x00000482
_080E2B88: .4byte 0x00000222
_080E2B8C: .4byte 0x0000024E
_080E2B90: .4byte 0xFFFFFC7F
_080E2B94: .4byte 0xF3FFFFFF
_080E2B98: .4byte 0xFEFFFFFF
_080E2B9C: .4byte 0xFFFFFDFF
_080E2BA0: .4byte 0x0000021E
_080E2BA4: .4byte 0x00000542
_080E2BA8: .4byte 0xFBFFFFFF
_080E2BAC: .4byte 0xFFFFFAFF
_080E2BB0: .4byte 0xFFFFF67F
_080E2BB4:
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080E2C9C
	ldr r1, _080E2C6C @ =0x00000482
	adds r4, r7, r1
	movs r5, #0
	movs r6, #1
	strh r6, [r4]
	ldr r2, _080E2C70 @ =0x00000222
	adds r0, r7, r2
	strh r3, [r0]
	ldr r1, _080E2C74 @ =0x0000024E
	adds r0, r7, r1
	strh r3, [r0]
	ldr r0, _080E2C78 @ =0xFFFFFC7F
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080E2C7C @ =0xF3FFFFFF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080E2C20
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _080E2C80 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080E2C84 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _080E2C88 @ =0x0000021E
	adds r0, r7, r2
	strh r3, [r0]
	subs r1, #0x1a
	adds r0, r7, r1
	strh r3, [r0]
_080E2C20:
	movs r2, #0x80
	lsls r2, r2, #3
	mov r3, sl
	ldrh r0, [r3]
	bics r0, r2
	strh r0, [r3]
	ldr r5, _080E2C8C @ =0x00000542
	adds r1, r7, r5
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080E2C90 @ =0xFBFFFFFF
	mov r3, sb
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r0, _080E2C94 @ =0xFFFFDAFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r3, r7, r0
	ldrh r0, [r3]
	orrs r2, r0
	strh r2, [r3]
	strh r6, [r4]
	ldr r0, _080E2C98 @ =0xFFFFF67F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	mov r1, sb
	ldr r0, [r1]
	mov r2, r8
	orrs r0, r2
	str r0, [r1]
	b _080E2EDA
	.align 2, 0
_080E2C6C: .4byte 0x00000482
_080E2C70: .4byte 0x00000222
_080E2C74: .4byte 0x0000024E
_080E2C78: .4byte 0xFFFFFC7F
_080E2C7C: .4byte 0xF3FFFFFF
_080E2C80: .4byte 0xFEFFFFFF
_080E2C84: .4byte 0xFFFFFDFF
_080E2C88: .4byte 0x0000021E
_080E2C8C: .4byte 0x00000542
_080E2C90: .4byte 0xFBFFFFFF
_080E2C94: .4byte 0xFFFFDAFF
_080E2C98: .4byte 0xFFFFF67F
_080E2C9C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080E2D6C
	ldr r3, _080E2D3C @ =0x00000482
	adds r1, r7, r3
	movs r3, #0
	movs r0, #1
	strh r0, [r1]
	ldr r5, _080E2D40 @ =0x00000222
	adds r0, r7, r5
	strh r4, [r0]
	ldr r6, _080E2D44 @ =0x0000024E
	adds r0, r7, r6
	strh r4, [r0]
	ldr r0, _080E2D48 @ =0xFFFFFC7F
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080E2D4C @ =0xF3FFFFFF
	mov r5, sb
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080E2D02
	subs r6, #0xd2
	adds r2, r7, r6
	ldr r1, _080E2D50 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080E2D54 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r5, #0x87
	lsls r5, r5, #2
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0xa2
	adds r0, r7, r6
	strh r4, [r0]
	ldr r1, _080E2D58 @ =0x00000202
	adds r0, r7, r1
	strh r4, [r0]
_080E2D02:
	movs r2, #0x80
	lsls r2, r2, #3
	mov r4, sl
	ldrh r0, [r4]
	bics r0, r2
	strh r0, [r4]
	ldr r5, _080E2D5C @ =0x00000542
	adds r1, r7, r5
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080E2D60 @ =0xFBFFFFFF
	mov r6, sb
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r0, _080E2D64 @ =0xFFFFDAFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	orrs r2, r0
	orrs r2, r3
	ldr r0, _080E2D68 @ =0xFFFFF67F
	ands r2, r0
	strh r2, [r1]
	b _080E2EDA
	.align 2, 0
_080E2D3C: .4byte 0x00000482
_080E2D40: .4byte 0x00000222
_080E2D44: .4byte 0x0000024E
_080E2D48: .4byte 0xFFFFFC7F
_080E2D4C: .4byte 0xF3FFFFFF
_080E2D50: .4byte 0xFEFFFFFF
_080E2D54: .4byte 0xFFFFFDFF
_080E2D58: .4byte 0x00000202
_080E2D5C: .4byte 0x00000542
_080E2D60: .4byte 0xFBFFFFFF
_080E2D64: .4byte 0xFFFFDAFF
_080E2D68: .4byte 0xFFFFF67F
_080E2D6C:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080E2D98
	ldr r0, _080E2D94 @ =0xFFFFDAFF
	ands r0, r2
	mov r1, sl
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	b _080E2ED4
	.align 2, 0
_080E2D94: .4byte 0xFFFFDAFF
_080E2D98:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	bne _080E2DA2
	b _080E2EDA
_080E2DA2:
	ldr r1, _080E2FB8 @ =0xFFFEBE3F
	mov r4, sb
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r6, _080E2FBC @ =0x0000021E
	adds r6, r7, r6
	str r6, [sp, #0x28]
	strh r5, [r6]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r5, [r0]
	ldr r2, _080E2FC0 @ =0x00000202
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	strh r5, [r2]
	ldr r4, _080E2FC4 @ =0x00000482
	adds r3, r7, r4
	movs r0, #1
	strh r0, [r3]
	ldr r6, _080E2FC8 @ =0x00000222
	adds r0, r7, r6
	strh r5, [r0]
	adds r1, #0x2e
	adds r0, r7, r1
	strh r5, [r0]
	ldr r0, _080E2FCC @ =0xFFFFFC7F
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080E2FD0 @ =0xF3FFFFFF
	mov r4, sb
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r6, #0x80
	lsls r6, r6, #0xe
	ands r0, r6
	cmp r0, #0
	beq _080E2E20
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _080E2FD4 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080E2FD8 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r4, #0x87
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r6, #0
	strb r6, [r0]
	ldr r0, [sp, #0x28]
	strh r5, [r0]
	ldr r1, [sp, #0x2c]
	strh r5, [r1]
_080E2E20:
	mov r2, sl
	ldrh r1, [r2]
	ldr r0, _080E2FDC @ =0xFFFFFBFF
	ands r0, r1
	strh r0, [r2]
	ldr r4, _080E2FE0 @ =0x00000542
	adds r6, r7, r4
	movs r0, #1
	rsbs r0, r0, #0
	add r1, sp, #0x30
	strb r0, [r1]
	movs r0, #0xff
	strb r0, [r6]
	ldr r0, _080E2FE4 @ =0xFFFFDAFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r0, #6
	strh r0, [r3]
	movs r3, #0x80
	lsls r3, r3, #5
	mov r8, r3
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r3
	cmp r0, #0
	beq _080E2E76
	movs r0, #0x97
	lsls r0, r0, #3
	adds r4, r7, r0
	ldr r0, [r4]
	bl FUN_080f8e3c
	mov r1, sl
	ldrh r0, [r1]
	mov r2, r8
	bics r0, r2
	strh r0, [r1]
	str r5, [r4]
_080E2E76:
	mov r3, sb
	ldr r0, [r3]
	movs r4, #0x80
	lsls r4, r4, #0xe
	ands r0, r4
	cmp r0, #0
	beq _080E2EAE
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _080E2FD4 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080E2FD8 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r3, #0x87
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r4, #0
	strb r4, [r0]
	ldr r0, [sp, #0x28]
	strh r5, [r0]
	ldr r1, [sp, #0x2c]
	strh r5, [r1]
_080E2EAE:
	mov r2, sl
	ldrh r1, [r2]
	ldr r0, _080E2FDC @ =0xFFFFFBFF
	ands r0, r1
	strh r0, [r2]
	ldrb r0, [r6]
	add r3, sp, #0x30
	ldrb r3, [r3]
	orrs r0, r3
	strb r0, [r6]
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r0, r1
	movs r5, #0
	orrs r0, r5
_080E2ED4:
	ldr r1, _080E2FE8 @ =0xFFFFF67F
	ands r0, r1
	strh r0, [r2]
_080E2EDA:
	ldr r0, _080E2FEC @ =0x0000803E
	mov r6, sl
	ldrh r1, [r6]
	ands r0, r1
	cmp r0, #0
	bne _080E2EE8
	b _080E3012
_080E2EE8:
	ldr r0, _080E2FF0 @ =0xFFFFFDFE
	ands r0, r1
	movs r1, #0
	mov r8, r1
	strh r0, [r6]
	ldr r0, _080E2FF4 @ =0xF7FFBFFF
	mov r3, sb
	ldr r2, [r3]
	ands r2, r0
	str r2, [r3]
	movs r1, #0x20
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _080E2F0E
	movs r0, #0x81
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
_080E2F0E:
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r5, r7, r4
	ldr r0, _080E2FF8 @ =0xFFEFFFFB
	ldr r1, [r5]
	ands r1, r0
	str r1, [r5]
	movs r6, #0x80
	lsls r6, r6, #5
	mov r1, sl
	ldrh r0, [r1]
	ands r0, r6
	cmp r0, #0
	beq _080E2F42
	movs r2, #0x97
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r0, [r4]
	bl FUN_080f8e3c
	mov r3, sl
	ldrh r0, [r3]
	bics r0, r6
	strh r0, [r3]
	mov r6, r8
	str r6, [r4]
_080E2F42:
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080E2F7A
	ldr r1, _080E2FD4 @ =0xFEFFFFFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r0, _080E2FD8 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r4, #0x87
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	strb r5, [r0]
	ldr r6, _080E2FBC @ =0x0000021E
	adds r0, r7, r6
	mov r1, r8
	strh r1, [r0]
	ldr r2, _080E2FC0 @ =0x00000202
	adds r0, r7, r2
	strh r1, [r0]
_080E2F7A:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r3, sl
	ldrh r0, [r3]
	bics r0, r1
	strh r0, [r3]
	ldr r4, _080E2FE0 @ =0x00000542
	adds r2, r7, r4
	movs r0, #0xff
	strb r0, [r2]
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	ldr r6, _080E2FFC @ =0x0000048C
	adds r0, r7, r6
	movs r1, #0
	strb r1, [r0]
	movs r1, #0x10
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _080E3004
	ldr r1, _080E3000 @ =0xFFFFDFFF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080E301C
	.align 2, 0
_080E2FB8: .4byte 0xFFFEBE3F
_080E2FBC: .4byte 0x0000021E
_080E2FC0: .4byte 0x00000202
_080E2FC4: .4byte 0x00000482
_080E2FC8: .4byte 0x00000222
_080E2FCC: .4byte 0xFFFFFC7F
_080E2FD0: .4byte 0xF3FFFFFF
_080E2FD4: .4byte 0xFEFFFFFF
_080E2FD8: .4byte 0xFFFFFDFF
_080E2FDC: .4byte 0xFFFFFBFF
_080E2FE0: .4byte 0x00000542
_080E2FE4: .4byte 0xFFFFDAFF
_080E2FE8: .4byte 0xFFFFF67F
_080E2FEC: .4byte 0x0000803E
_080E2FF0: .4byte 0xFFFFFDFE
_080E2FF4: .4byte 0xF7FFBFFF
_080E2FF8: .4byte 0xFFEFFFFB
_080E2FFC: .4byte 0x0000048C
_080E3000: .4byte 0xFFFFDFFF
_080E3004:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r3, sb
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	b _080E301C
_080E3012:
	ldr r1, _080E3070 @ =0xFFFFDFFF
	mov r4, sb
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_080E301C:
	movs r3, #0x80
	lsls r3, r3, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r3
	cmp r0, #0
	beq _080E3052
	ldr r6, _080E3074 @ =0x00000542
	adds r1, r7, r6
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080E3046
	ldr r4, _080E3078 @ =0x00000553
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0x1b
	beq _080E3052
	cmp r0, #2
	beq _080E3052
_080E3046:
	movs r0, #0xff
	strb r0, [r1]
	mov r5, sl
	ldrh r0, [r5]
	bics r0, r3
	strh r0, [r5]
_080E3052:
	movs r0, #0x80
	mov r6, sl
	ldrh r3, [r6]
	adds r2, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _080E30A4
	ldr r1, _080E307C @ =0x000001DF
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _080E3084
	ldr r2, _080E3080 @ =0x00000482
	adds r1, r7, r2
	b _080E30D6
	.align 2, 0
_080E3070: .4byte 0xFFFFDFFF
_080E3074: .4byte 0x00000542
_080E3078: .4byte 0x00000553
_080E307C: .4byte 0x000001DF
_080E3080: .4byte 0x00000482
_080E3084:
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080E3098
	ldr r3, _080E3094 @ =0x00000482
	adds r1, r7, r3
	b _080E30D6
	.align 2, 0
_080E3094: .4byte 0x00000482
_080E3098:
	ldr r4, _080E30A0 @ =0x00000482
	adds r1, r7, r4
	b _080E30E4
	.align 2, 0
_080E30A0: .4byte 0x00000482
_080E30A4:
	movs r1, #0x90
	lsls r1, r1, #5
	ands r1, r2
	cmp r1, #0
	beq _080E30F0
	ldr r5, _080E30C0 @ =0x000001DF
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _080E30C8
	ldr r6, _080E30C4 @ =0x00000482
	adds r1, r7, r6
	b _080E30D6
	.align 2, 0
_080E30C0: .4byte 0x000001DF
_080E30C4: .4byte 0x00000482
_080E30C8:
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080E30E0
	ldr r0, _080E30DC @ =0x00000482
	adds r1, r7, r0
_080E30D6:
	movs r0, #2
	strh r0, [r1]
	b _080E3116
	.align 2, 0
_080E30DC: .4byte 0x00000482
_080E30E0:
	ldr r2, _080E30EC @ =0x00000482
	adds r1, r7, r2
_080E30E4:
	movs r0, #3
	strh r0, [r1]
	b _080E3116
	.align 2, 0
_080E30EC: .4byte 0x00000482
_080E30F0:
	ldr r0, _080E3224 @ =0xFFFFFBFF
	ands r0, r3
	movs r2, #0
	mov r3, sl
	strh r0, [r3]
	ldr r4, _080E3228 @ =0x00000222
	adds r0, r7, r4
	strh r1, [r0]
	ldr r5, _080E322C @ =0x00000542
	adds r1, r7, r5
	movs r0, #0xff
	strb r0, [r1]
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _080E3230 @ =0x00000541
	adds r0, r7, r1
	strb r2, [r0]
_080E3116:
	movs r2, #0x8a
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080E31E0
	subs r0, #1
	strh r0, [r1]
	movs r3, #0xa
	ldrsh r0, [r7, r3]
	cmp r0, #0
	blt _080E31E0
	ldrh r0, [r1]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _080E31E0
	ldr r4, _080E3234 @ =0x000001DD
	adds r0, r7, r4
	ldrb r3, [r0]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r6, _080E3238 @ =0x0203B400
	ldr r5, _080E323C @ =0x030046B8
	mov ip, r5
	ldr r2, [r5]
	adds r2, #1
	ldr r5, _080E3240 @ =0x000003FF
	ands r2, r5
	lsls r0, r2, #1
	adds r0, r0, r6
	ldr r4, [sp, #0x18]
	asrs r1, r4, #0x10
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080E3244 @ =0x0000FFFF
	mov r8, r0
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x18]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r4, _080E3248 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r1, #0x3c
	orrs r0, r1
	mov r1, r8
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	movs r1, #0x28
	orrs r0, r1
	str r0, [sp, #0x14]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r4, [r0]
	movs r0, #7
	ands r4, r0
	adds r4, #4
	adds r2, #1
	ands r2, r5
	mov r5, ip
	str r2, [r5]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r1, [r2]
	ands r1, r0
	adds r1, #8
	add r0, sp, #0x18
	str r4, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #2
	add r2, sp, #0x10
	bl FUN_080ddcc8
_080E31E0:
	adds r0, r7, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E31EE
	b _080E358C
_080E31EE:
	movs r0, #0x80
	mov r6, sl
	ldrh r1, [r6]
	ands r0, r1
	cmp r0, #0
	bne _080E31FC
	b _080E34E8
_080E31FC:
	ldr r0, _080E324C @ =0x0000A03F
	ands r0, r1
	cmp r0, #0
	beq _080E3206
	b _080E34E8
_080E3206:
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080E3214
	b _080E34E8
_080E3214:
	ldr r3, _080E3250 @ =0x0000024E
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _080E3254
	subs r0, #1
	strh r0, [r2]
	b _080E34E8
	.align 2, 0
_080E3224: .4byte 0xFFFFFBFF
_080E3228: .4byte 0x00000222
_080E322C: .4byte 0x00000542
_080E3230: .4byte 0x00000541
_080E3234: .4byte 0x000001DD
_080E3238: .4byte 0x0203B400
_080E323C: .4byte 0x030046B8
_080E3240: .4byte 0x000003FF
_080E3244: .4byte 0x0000FFFF
_080E3248: .4byte 0xFFFF0000
_080E324C: .4byte 0x0000A03F
_080E3250: .4byte 0x0000024E
_080E3254:
	ldr r4, _080E33D0 @ =0x000001DF
	adds r3, r7, r4
	ldrb r0, [r3]
	cmp r0, #2
	bne _080E3260
	b _080E34E8
_080E3260:
	cmp r0, #0x11
	bne _080E3266
	b _080E34E8
_080E3266:
	cmp r0, #0xb
	bne _080E326C
	b _080E34E8
_080E326C:
	cmp r0, #0x17
	bne _080E3272
	b _080E34E8
_080E3272:
	cmp r0, #8
	bne _080E3278
	b _080E34E8
_080E3278:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080E3288
	b _080E34E8
_080E3288:
	ldr r5, _080E33D4 @ =0x00000482
	adds r1, r7, r5
	movs r5, #0
	movs r6, #1
	movs r0, #1
	strh r0, [r1]
	ldr r1, _080E33D8 @ =0x00000222
	adds r0, r7, r1
	strh r4, [r0]
	strh r4, [r2]
	ldr r0, _080E33DC @ =0xFFFFFC7F
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	mov r2, sb
	ldr r1, _080E33E0 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080E32E6
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _080E33E4 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080E33E8 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _080E33EC @ =0x0000021E
	adds r0, r7, r2
	strh r4, [r0]
	subs r1, #0x1a
	adds r0, r7, r1
	strh r4, [r0]
_080E32E6:
	ldr r0, _080E33F0 @ =0xFFFFFBFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _080E33F4 @ =0x00000542
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldrb r3, [r3]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r2, _080E33F8 @ =0x080E6795
	movs r1, #0xe
	ldr r3, _080E33FC @ =0x0000046D
	adds r0, r7, r3
	strb r6, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r5, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r1, #3
	subs r3, #0xeb
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _080E3400 @ =0x00000469
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _080E3404 @ =0x0000046A
	adds r0, r7, r2
	strb r5, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r4, [r0]
	ldr r4, _080E3408 @ =0x0000046C
	adds r0, r7, r4
	strb r6, [r0]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	subs r6, #0x4c
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _080E340C @ =0x00000551
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _080E3410 @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	movs r1, #0x10
	mov r4, sb
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, _080E3414 @ =0xFFFFF636
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	add r5, sp, #0x20
	adds r0, r7, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r5]
	ldrh r1, [r1, #2]
	strh r1, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r5, #0
	cmp r2, #0
	blt _080E33CA
	cmp r1, #0
	blt _080E33CA
	ldr r0, _080E3418 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080E33CA
	ldr r0, _080E341C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E3420
_080E33CA:
	movs r4, #0
	b _080E342E
	.align 2, 0
_080E33D0: .4byte 0x000001DF
_080E33D4: .4byte 0x00000482
_080E33D8: .4byte 0x00000222
_080E33DC: .4byte 0xFFFFFC7F
_080E33E0: .4byte 0xF3FFFFFF
_080E33E4: .4byte 0xFEFFFFFF
_080E33E8: .4byte 0xFFFFFDFF
_080E33EC: .4byte 0x0000021E
_080E33F0: .4byte 0xFFFFFBFF
_080E33F4: .4byte 0x00000542
_080E33F8: .4byte 0x080E6795
_080E33FC: .4byte 0x0000046D
_080E3400: .4byte 0x00000469
_080E3404: .4byte 0x0000046A
_080E3408: .4byte 0x0000046C
_080E340C: .4byte 0x00000551
_080E3410: .4byte 0x00000552
_080E3414: .4byte 0xFFFFF636
_080E3418: .4byte 0x030046A8
_080E341C: .4byte 0x030046AC
_080E3420:
	ldr r0, _080E3440 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080E342E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E3444
	adds r0, #4
	b _080E3450
	.align 2, 0
_080E3440: .4byte 0x030046A4
_080E3444:
	ldr r0, _080E3464 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E3450:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E3468
	cmp r2, #2
	beq _080E346C
	b _080E3470
	.align 2, 0
_080E3464: .4byte 0x030046A4
_080E3468:
	ldrb r0, [r5, #4]
	b _080E346E
_080E346C:
	ldrb r0, [r5]
_080E346E:
	subs r1, r1, r0
_080E3470:
	strh r1, [r5, #2]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	ldr r2, _080E34A4 @ =0x000004A4
	adds r0, r7, r2
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080E34AC
	ldr r0, _080E34A8 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _080E34D6
	.align 2, 0
_080E34A4: .4byte 0x000004A4
_080E34A8: .4byte 0xFFFFFDFF
_080E34AC:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080E34CC
	cmp r0, #2
	beq _080E34C8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080E34C8:
	movs r0, #1
	b _080E34D8
_080E34CC:
	ldr r0, _080E3520 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_080E34D6:
	movs r0, #0
_080E34D8:
	cmp r0, #0
	bne _080E34E8
	ldr r5, _080E3524 @ =0x000005C4
	adds r0, r7, r5
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_080E34E8:
	movs r1, #0x80
	lsls r1, r1, #5
	mov r6, sl
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080E350C
	bl FUN_0808672c
	cmp r0, #0
	bne _080E350C
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_080E350C:
	movs r1, #2
	ldr r2, _080E3528 @ =0x00000474
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E352C
	movs r0, #1
	b _080E352E
	.align 2, 0
_080E3520: .4byte 0xFFFFFDFF
_080E3524: .4byte 0x000005C4
_080E3528: .4byte 0x00000474
_080E352C:
	movs r0, #0
_080E352E:
	cmp r0, #0
	beq _080E3548
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, _080E3544 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _080E3554
	.align 2, 0
_080E3544: .4byte 0x03002BE0
_080E3548:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _080E358C
_080E3554:
	ldr r1, [r0]
	movs r6, #8
	ldrsh r5, [r1, r6]
	movs r2, #8
	ldrsh r0, [r7, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r6, #0xc
	ldrsh r0, [r7, r6]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r7, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_080E358C:
	ldrb r0, [r7, #5]
	movs r4, #0xb5
	lsls r4, r4, #1
	adds r1, r7, r4
	strb r0, [r1]
	ldrb r0, [r7, #5]
	movs r5, #0x8d
	lsls r5, r5, #1
	adds r1, r7, r5
	strb r0, [r1]
	movs r0, #1
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
