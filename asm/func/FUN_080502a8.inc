	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _080502F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xb4
	lsls r0, r0, #2
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_0809c544
	adds r0, r4, #0
	movs r1, #4
	bl FUN_0804fbd0
	adds r0, r4, #0
	bl FUN_0804feb0
	ldrh r0, [r4, #0x1e]
	cmp r0, #0xb
	bne _080502E6
	movs r0, #0xaf
	bl sound_08240264
	b _080502F0
_080502E6:
	cmp r0, #1
	bne _080502F0
	movs r0, #0xad
	bl sound_08240264
_080502F0:
	adds r1, r4, #0
	adds r1, #0x37
	movs r0, #1
	strb r0, [r1]
_080502F8:
	adds r0, r4, #0
	bl FUN_080501c8
	ldr r0, [r4, #0x24]
	cmp r0, #0x1e
	bne _0805030A
	adds r0, r4, #0
	bl FUN_0804fbe0
_0805030A:
	ldr r0, [r4, #0x24]
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _080503B2
	ldr r0, _08050348 @ =0x03002BE0
	ldr r5, [r0]
	movs r0, #7
	bl FUN_08022a2c
	adds r7, r0, #0
	cmp r5, #0
	beq _08050350
	ldr r0, _0805034C @ =0x00000366
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _08050350
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldrh r1, [r2]
	bl Div
	adds r6, r0, #0
	b _08050352
	.align 2, 0
_08050348: .4byte 0x03002BE0
_0805034C: .4byte 0x00000366
_08050350:
	movs r6, #0
_08050352:
	cmp r6, #0
	bne _08050364
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08050364
	movs r6, #1
_08050364:
	cmp r7, #0
	beq _0805038C
	adds r2, r7, #0
	adds r2, #0x92
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	ble _0805038C
	adds r0, r7, #0
	adds r0, #0x90
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x64
	muls r0, r1, r0
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Div
	adds r1, r0, #0
	b _0805038E
_0805038C:
	movs r1, #0
_0805038E:
	cmp r1, #0
	bne _080503A0
	adds r0, r7, #0
	adds r0, #0x90
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _080503A0
	movs r1, #1
_080503A0:
	lsls r0, r1, #8
	orrs r0, r6
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
_080503B2:
	ldr r0, [r4, #0x2c]
	ldr r1, _080503E0 @ =0x00FFFF00
	ands r0, r1
	cmp r0, #0
	bne _080503C6
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _080503E4
_080503C6:
	bl FUN_0809c58c
	movs r1, #6
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x24]
	b _08050432
	.align 2, 0
_080503E0: .4byte 0x00FFFF00
_080503E4:
	ldrh r0, [r4, #0x1c]
	subs r0, #1
	movs r6, #0
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0805042C
	bl FUN_0803ca14
	bl FUN_0809c58c
	ldr r0, _08050424 @ =0x00000372
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0x28
	strb r6, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r5, [r4, #0x24]
	movs r2, #4
	ldr r1, _08050428 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x37
	strb r6, [r0]
	b _08050432
	.align 2, 0
_08050424: .4byte 0x00000372
_08050428: .4byte 0x030044BC
_0805042C:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
_08050432:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
