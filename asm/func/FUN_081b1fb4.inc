	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x60
	adds r7, r0, #0
	ldr r0, _081B2118 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B1FD0
	movs r0, #0
	strb r0, [r1]
_081B1FD0:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B1FE8
	bl _081B280C
_081B1FE8:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _081B1FFA
	bl _081B280C
_081B1FFA:
	ldr r2, _081B211C @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _081B2008
	bl _081B2808
_081B2008:
	ldr r3, _081B2120 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _081B2124 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r0, #1
	strb r0, [r5]
	ldr r1, _081B2128 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	strb r6, [r1]
	ldr r2, _081B211C @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _081B2118 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r0, [r3]
	ldr r1, _081B212C @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _081B2130 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r2, _081B2134 @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	strb r6, [r2]
	ldr r3, _081B2138 @ =0x00000553
	adds r5, r7, r3
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r7, r0
	str r1, [r4]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r3, r7, r1
	strh r6, [r3]
	movs r0, #0x80
	subs r1, #0x48
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	mov r0, ip
	str r0, [sp, #0x50]
	ldr r0, [sp, #8]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	mov r0, sl
	str r0, [sp, #0x5c]
	mov r0, sb
	str r0, [sp, #0x54]
	mov r0, r8
	str r0, [sp, #0x4c]
	str r5, [sp, #0x2c]
	str r4, [sp, #0x34]
	str r3, [sp, #0x30]
	mov sl, r2
	cmp r1, #0
	bne _081B20A6
	b _081B2640
_081B20A6:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081B213C @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r5, [r3]
	adds r2, r7, #0
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
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _081B2112
	cmp r1, #0
	blt _081B2112
	ldr r0, _081B2140 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B2112
	ldr r0, _081B2144 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B2148
_081B2112:
	movs r4, #0
	b _081B2156
	.align 2, 0
_081B2118: .4byte 0x0000046C
_081B211C: .4byte 0x00000484
_081B2120: .4byte 0x000001DF
_081B2124: .4byte 0x00000469
_081B2128: .4byte 0x0000046A
_081B212C: .4byte Enemy_WaitPendingState
_081B2130: .4byte 0x0000046D
_081B2134: .4byte 0x0000046B
_081B2138: .4byte 0x00000553
_081B213C: .4byte 0x00000551
_081B2140: .4byte 0x030046A8
_081B2144: .4byte 0x030046AC
_081B2148:
	ldr r0, _081B2168 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B2156:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B216C
	adds r0, #4
	b _081B2178
	.align 2, 0
_081B2168: .4byte 0x030046A4
_081B216C:
	ldr r0, _081B218C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B2178:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B2190
	cmp r2, #2
	beq _081B2194
	b _081B2198
	.align 2, 0
_081B218C: .4byte 0x030046A4
_081B2190:
	ldrb r0, [r5, #4]
	b _081B2196
_081B2194:
	ldrb r0, [r5]
_081B2196:
	subs r1, r1, r0
_081B2198:
	strh r1, [r5, #2]
	ldr r0, _081B21AC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B21B0
	movs r0, #1
	b _081B21B2
	.align 2, 0
_081B21AC: .4byte 0x030047A4
_081B21B0:
	movs r0, #0
_081B21B2:
	cmp r0, #0
	beq _081B21F0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081B21D2
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B21CE
	adds r2, r0, #0
_081B21CE:
	cmp r2, #0
	bge _081B21DC
_081B21D2:
	ldr r2, _081B21D8 @ =0x000005C4
	adds r0, r7, r2
	b _081B262E
	.align 2, 0
_081B21D8: .4byte 0x000005C4
_081B21DC:
	ldr r1, _081B21EC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B2238
	.align 2, 0
_081B21EC: .4byte 0x03002BE0
_081B21F0:
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
	blt _081B221C
	cmp r1, #0
	blt _081B221C
	ldr r0, _081B2220 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B221C
	ldr r0, _081B2224 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B2228
_081B221C:
	movs r5, #0
	b _081B2236
	.align 2, 0
_081B2220: .4byte 0x030046A8
_081B2224: .4byte 0x030046AC
_081B2228:
	ldr r0, _081B22C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B2236:
	movs r2, #0
_081B2238:
	ldr r4, _081B22CC @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B2258
	ldr r1, _081B22D0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B2258
	b _081B256C
_081B2258:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081B226C
	b _081B280C
_081B226C:
	ldr r0, _081B22D4 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r2, [sp, #0x38]
	cmp r3, #0
	beq _081B22D8
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r3, [sp, #0x2c]
	strb r0, [r3]
	ldr r0, [sp, #0x34]
	str r1, [r0]
	ldr r1, [sp, #0x30]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r1, [sp, #0x44]
	strb r5, [r1]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r5, [sp, #0x5c]
	str r4, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _081B2426
	.align 2, 0
_081B22C8: .4byte 0x030046A4
_081B22CC: .4byte 0x00000256
_081B22D0: .4byte 0x03002BE0
_081B22D4: .4byte 0x00000222
_081B22D8:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	str r1, [r4]
	ldr r1, [sp, #0x30]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x44]
	strb r5, [r4]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r2, [sp, #0x50]
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
	blt _081B233C
	cmp r1, #0
	blt _081B233C
	ldr r0, _081B2340 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B233C
	ldr r0, _081B2344 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B2348
_081B233C:
	movs r4, #0
	b _081B2356
	.align 2, 0
_081B2340: .4byte 0x030046A8
_081B2344: .4byte 0x030046AC
_081B2348:
	ldr r0, _081B2368 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B2356:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B236C
	adds r0, #4
	b _081B2378
	.align 2, 0
_081B2368: .4byte 0x030046A4
_081B236C:
	ldr r0, _081B238C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B2378:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B2390
	cmp r2, #2
	beq _081B2394
	b _081B2398
	.align 2, 0
_081B238C: .4byte 0x030046A4
_081B2390:
	ldrb r0, [r5, #4]
	b _081B2396
_081B2394:
	ldrb r0, [r5]
_081B2396:
	subs r1, r1, r0
_081B2398:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B23C0
	cmp r1, #0
	blt _081B23C0
	ldr r0, _081B23C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B23C0
	ldr r0, _081B23C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B23CC
_081B23C0:
	movs r4, #0
	b _081B23DA
	.align 2, 0
_081B23C4: .4byte 0x030046A8
_081B23C8: .4byte 0x030046AC
_081B23CC:
	ldr r0, _081B23EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B23DA:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B23F0
	adds r0, #4
	b _081B23FC
	.align 2, 0
_081B23EC: .4byte 0x030046A4
_081B23F0:
	ldr r0, _081B2410 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B23FC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B2414
	cmp r3, #2
	beq _081B2418
	b _081B241C
	.align 2, 0
_081B2410: .4byte 0x030046A4
_081B2414:
	ldrb r0, [r5, #4]
	b _081B241A
_081B2418:
	ldrb r0, [r5]
_081B241A:
	subs r2, r2, r0
_081B241C:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081B2426:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov sb, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	bne _081B2530
	movs r1, #4
	ldr r2, [sp, #0x38]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B2450
	movs r0, #1
	b _081B2452
_081B2450:
	movs r0, #0
_081B2452:
	ldr r3, _081B2540 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _081B2530
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081B2544 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081B2548 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x20]
	ldr r2, _081B254C @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x24]
	ldr r4, _081B2550 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x28]
	ldr r5, _081B2554 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x18]
	ldr r0, _081B2558 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _081B255C @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x1c]
	ldr r6, _081B2560 @ =0x0203B400
	ldr r1, _081B2564 @ =0x030046B8
	ldr r5, _081B2568 @ =0x000003FF
	movs r2, #3
	mov r4, sb
_081B24A2:
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
	bne _081B24C0
	adds r3, #1
	cmp r3, #3
	ble _081B24A2
	mov r0, sb
_081B24C0:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0x20]
	strb r0, [r5]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0x28]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x18]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x54]
	strb r1, [r5]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r0, [r5]
	ldr r0, [sp, #0x34]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r4, [sp, #0x48]
	strb r2, [r4]
	ldr r5, [sp, #0x5c]
	str r3, [r5]
	ldr r0, [sp, #0x50]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x1c]
	strb r0, [r1]
_081B2530:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r2, [sp, #0x58]
	strh r0, [r2]
	b _081B280C
	.align 2, 0
_081B2540: .4byte 0x00000482
_081B2544: .4byte 0x0000054F
_081B2548: .4byte 0x0000054C
_081B254C: .4byte 0x0000054D
_081B2550: .4byte 0x0000054E
_081B2554: .4byte 0x00000541
_081B2558: .4byte 0x000005BC
_081B255C: .4byte 0x00000542
_081B2560: .4byte 0x0203B400
_081B2564: .4byte 0x030046B8
_081B2568: .4byte 0x000003FF
_081B256C:
	mov sb, sp
	ldr r6, _081B25A8 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	beq _081B25AC
	adds r0, #4
	b _081B25B6
	.align 2, 0
_081B25A8: .4byte 0x030046A4
_081B25AC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B25B6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _081B25F0 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B25F8
	ldr r0, _081B25F4 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B2622
	.align 2, 0
_081B25F0: .4byte 0x000004A4
_081B25F4: .4byte 0xFFFFFDFF
_081B25F8:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B2618
	cmp r0, #2
	beq _081B2614
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B2614:
	movs r0, #1
	b _081B2624
_081B2618:
	ldr r0, _081B2638 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B2622:
	movs r0, #0
_081B2624:
	cmp r0, #0
	beq _081B262A
	b _081B280C
_081B262A:
	ldr r4, _081B263C @ =0x000005C4
	adds r0, r7, r4
_081B262E:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B280C
	.align 2, 0
_081B2638: .4byte 0xFFFFFDFF
_081B263C: .4byte 0x000005C4
_081B2640:
	movs r1, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081B2652
	b _081B27CA
_081B2652:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081B26BC @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B26B8
	cmp r1, #0
	blt _081B26B8
	ldr r0, _081B26C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B26B8
	ldr r0, _081B26C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B26C8
_081B26B8:
	movs r4, #0
	b _081B26D6
	.align 2, 0
_081B26BC: .4byte 0x00000551
_081B26C0: .4byte 0x030046A8
_081B26C4: .4byte 0x030046AC
_081B26C8:
	ldr r0, _081B26E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B26D6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B26EC
	adds r0, #4
	b _081B26F8
	.align 2, 0
_081B26E8: .4byte 0x030046A4
_081B26EC:
	ldr r0, _081B270C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B26F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B2710
	cmp r2, #2
	beq _081B2714
	b _081B2718
	.align 2, 0
_081B270C: .4byte 0x030046A4
_081B2710:
	ldrb r0, [r5, #4]
	b _081B2716
_081B2714:
	ldrb r0, [r5]
_081B2716:
	subs r1, r1, r0
_081B2718:
	strh r1, [r5, #2]
	ldr r2, _081B2748 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B2750
	ldr r0, _081B274C @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _081B277A
	.align 2, 0
_081B2748: .4byte 0x000004A4
_081B274C: .4byte 0xFFFFFDFF
_081B2750:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B2770
	cmp r0, #2
	beq _081B276C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B276C:
	movs r0, #1
	b _081B277C
_081B2770:
	ldr r0, _081B27B4 @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081B277A:
	movs r0, #0
_081B277C:
	adds r3, r0, #0
	cmp r3, #0
	bne _081B27BC
	ldr r0, _081B27B8 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r1, [sp, #0x54]
	strb r2, [r1]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r3, [r5]
	ldr r1, [sp, #0x34]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r5, [sp, #0x5c]
	str r3, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _081B280C
	.align 2, 0
_081B27B4: .4byte 0xFFFFFDFF
_081B27B8: .4byte Enemy_ClearStateBegun
_081B27BC:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _081B280C
_081B27CA:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #2
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081B2804 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xce
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	b _081B280C
	.align 2, 0
_081B2804: .4byte 0x00000551
_081B2808:
	adds r0, #1
	str r0, [r1]
_081B280C:
	add sp, #0x60
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
