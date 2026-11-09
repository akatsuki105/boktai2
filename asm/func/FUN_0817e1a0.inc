	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	adds r1, #0x34
	ldr r2, _0817E1C0 @ =0x00000898
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817E1C4
	movs r0, #1
	b _0817E1C6
	.align 2, 0
_0817E1C0: .4byte 0x00000898
_0817E1C4:
	movs r0, #0
_0817E1C6:
	cmp r0, #0
	bne _0817E1CC
	b _0817E320
_0817E1CC:
	movs r3, #0x95
	lsls r3, r3, #2
	adds r4, r5, r3
	ldrh r0, [r4]
	movs r1, #0xa
	bl Div
	movs r2, #0xf5
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r3, r0, #0
	muls r3, r1, r3
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldrh r1, [r4]
	cmp r0, r1
	ble _0817E202
	subs r0, r0, r1
	subs r3, r3, r0
	strh r1, [r2]
_0817E202:
	ldr r2, _0817E21C @ =0x0000048A
	adds r0, r5, r2
	strh r3, [r0]
	ldr r0, _0817E220 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0817E224
	movs r0, #1
	b _0817E226
	.align 2, 0
_0817E21C: .4byte 0x0000048A
_0817E220: .4byte 0x030047A4
_0817E224:
	movs r0, #0
_0817E226:
	cmp r0, #0
	beq _0817E294
	movs r3, #0x94
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _0817E294
	cmp r2, #0
	beq _0817E294
	ldr r0, _0817E24C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0817E250
	movs r0, #1
	rsbs r0, r0, #0
	b _0817E254
	.align 2, 0
_0817E24C: .4byte 0x03002C68
_0817E250:
	movs r4, #0x18
	ldrsh r0, [r0, r4]
_0817E254:
	cmp r0, #1
	beq _0817E276
	cmp r0, #1
	bgt _0817E262
	cmp r0, #0
	beq _0817E26C
	b _0817E294
_0817E262:
	cmp r0, #2
	beq _0817E280
	cmp r0, #3
	beq _0817E28A
	b _0817E294
_0817E26C:
	ldr r0, [r1]
	cmp r0, #1
	beq _0817E294
	movs r0, #0
	b _0817E296
_0817E276:
	ldr r0, [r1]
	cmp r0, #2
	beq _0817E294
	movs r0, #0
	b _0817E296
_0817E280:
	ldr r0, [r1]
	cmp r0, #4
	beq _0817E294
	movs r0, #0
	b _0817E296
_0817E28A:
	ldr r0, [r1]
	cmp r0, #8
	beq _0817E294
	movs r0, #0
	b _0817E296
_0817E294:
	movs r0, #1
_0817E296:
	cmp r0, #0
	beq _0817E2FA
	ldrh r0, [r5]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #0x95
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	adds r4, #6
	adds r3, r5, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl HUD_ShowEnemyGauge
	add r7, sp, #0xc
	str r4, [sp, #8]
	add r0, sp, #8
	adds r1, r7, #0
	ldr r2, _0817E310 @ =0x05000002
	bl CpuSet
	ldr r0, _0817E314 @ =0x0000048A
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _0817E2E6
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0817E2FA
_0817E2E6:
	adds r0, r5, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r5, #0
	adds r3, #8
	str r7, [sp]
	movs r2, #1
	str r2, [sp, #4]
	bl CreateDamageNumber
_0817E2FA:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0817e004
	ldr r3, _0817E318 @ =0x00000898
	adds r2, r6, r3
	ldr r1, _0817E31C @ =0xFFFFFDFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0817E3E2
	.align 2, 0
_0817E310: .4byte 0x05000002
_0817E314: .4byte 0x0000048A
_0817E318: .4byte 0x00000898
_0817E31C: .4byte 0xFFFFFDFF
_0817E320:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r4, _0817E338 @ =0x00000898
	adds r1, r6, r4
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0817E33C
	movs r0, #1
	b _0817E33E
	.align 2, 0
_0817E338: .4byte 0x00000898
_0817E33C:
	movs r0, #0
_0817E33E:
	cmp r0, #0
	beq _0817E388
	ldr r1, _0817E37C @ =0xFFFEFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1, #8]
	ldr r1, _0817E380 @ =0x000007AA
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0xf6
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0817e004
	ldr r1, _0817E384 @ =0xFFFFFBFF
	b _0817E3DC
	.align 2, 0
_0817E37C: .4byte 0xFFFEFFFF
_0817E380: .4byte 0x000007AA
_0817E384: .4byte 0xFFFFFBFF
_0817E388:
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0817E398
	movs r0, #1
	b _0817E39A
_0817E398:
	movs r0, #0
_0817E39A:
	cmp r0, #0
	beq _0817E3E2
	ldr r1, _0817E3EC @ =0xFFFF7FFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r3, _0817E3F0 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0817E3F4 @ =0x000007AC
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0xf6
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r1, [r0]
	ldr r3, _0817E3F8 @ =0x000007B2
	adds r1, r6, r3
	movs r0, #0x1e
	strh r0, [r1]
	ldr r1, _0817E3FC @ =0xFFFDFFFF
	ldr r0, [r4]
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xb
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_0817e004
	ldr r1, _0817E400 @ =0xFFFFF7FF
_0817E3DC:
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_0817E3E2:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817E3EC: .4byte 0xFFFF7FFF
_0817E3F0: .4byte 0x00000482
_0817E3F4: .4byte 0x000007AC
_0817E3F8: .4byte 0x000007B2
_0817E3FC: .4byte 0xFFFDFFFF
_0817E400: .4byte 0xFFFFF7FF
