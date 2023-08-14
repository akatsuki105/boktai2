	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r5, r0, #0
	adds r7, r1, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08065794
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0806578C @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _08065790 @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080657BA
	.align 2, 0
_0806578C: .4byte 0xFFFF0000
_08065790: .4byte 0x0000FFFF
_08065794:
	ldr r0, _080657E8 @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _080657EC @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _080657F0 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #8]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0xc]
_080657BA:
	add r6, sp, #8
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080657E2
	cmp r1, #0
	blt _080657E2
	ldr r0, _080657F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080657E2
	ldr r0, _080657F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080657FC
_080657E2:
	movs r4, #0
	b _0806580A
	.align 2, 0
_080657E8: .4byte 0x030046A0
_080657EC: .4byte 0xFFFF0000
_080657F0: .4byte 0x0000FFFF
_080657F4: .4byte 0x030046A8
_080657F8: .4byte 0x030046AC
_080657FC:
	ldr r0, _0806581C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0806580A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08065820
	adds r0, #4
	b _0806582C
	.align 2, 0
_0806581C: .4byte 0x030046A4
_08065820:
	ldr r0, _08065840 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0806582C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08065844
	cmp r2, #2
	beq _08065848
	b _0806584C
	.align 2, 0
_08065840: .4byte 0x030046A4
_08065844:
	ldrb r0, [r6, #4]
	b _0806584A
_08065848:
	ldrb r0, [r6]
_0806584A:
	subs r1, r1, r0
_0806584C:
	add r0, sp, #8
	strh r1, [r0, #2]
	adds r4, r5, #0
	adds r4, #0x24
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	ldrb r0, [r5, #0x18]
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_0823b400
	adds r0, r5, #0
	bl FUN_0806540c
	adds r0, r5, #0
	bl FUN_08065514
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r6, r4, #0
	cmp r0, #0
	blt _080658A4
	cmp r0, #1
	ble _0806588A
	cmp r0, #5
	bne _080658A4
_0806588A:
	ldr r2, _080658A0 @ =0x00000359
	adds r0, r5, r2
	movs r1, #0
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x88
	adds r0, r6, #0
	bl FUN_0823b474
	b _080658B6
	.align 2, 0
_080658A0: .4byte 0x00000359
_080658A4:
	ldr r1, _08065918 @ =0x00000359
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0xe8
	adds r0, r6, #0
	bl FUN_0823b46c
_080658B6:
	movs r2, #0xde
	lsls r2, r2, #1
	adds r4, r5, r2
	adds r0, r4, #0
	add r1, sp, #8
	bl FUN_0823280c
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl FUN_0823b43c
	ldr r2, _0806591C @ =0xFFFF0000
	movs r0, #0x96
	lsls r0, r0, #0x11
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r0, r6, #0
	bl FUN_0823b47c
	ldrh r1, [r5, #0x24]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r6, #0
	movs r2, #2
	bl FUN_080f8c58
	ldr r2, _08065920 @ =0x03002B68
	adds r1, r5, #0
	adds r1, #0x28
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r2, [r5, #0x24]
	strh r2, [r1]
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08065918: .4byte 0x00000359
_0806591C: .4byte 0xFFFF0000
_08065920: .4byte 0x03002B68
