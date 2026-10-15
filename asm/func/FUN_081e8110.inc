	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _081E819C @ =0x00001614
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E817C
	adds r0, r5, #0
	bl FUN_081e2960
	adds r0, r5, #0
	movs r1, #0
	movs r2, #6
	bl FUN_081e4cb4
	ldr r0, _081E81A0 @ =0x00001618
	adds r1, r5, r0
	movs r3, #0
	movs r0, #6
	strb r0, [r1]
	ldr r1, _081E81A4 @ =0x00001610
	adds r2, r5, r1
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb1
	lsls r0, r0, #5
	adds r1, r5, r0
	ldr r0, _081E81A8 @ =0x0000FFFF
	strh r0, [r1]
	ldr r1, _081E81AC @ =0x00001625
	adds r0, r5, r1
	strb r3, [r0]
	bl LinkShopManager_IsParent
	cmp r0, #0
	beq _081E816E
	movs r0, #0xa8
	bl sound_08240960
	cmp r0, #0
	bne _081E816E
	movs r0, #0xa8
	bl sound_08240264
_081E816E:
	adds r0, r5, #0
	bl FUN_081e49a8
	ldr r0, _081E819C @ =0x00001614
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_081E817C:
	adds r0, r5, #0
	bl FUN_081e2ee8
	adds r0, r5, #0
	bl FUN_081e4a60
	movs r2, #2
	ldr r0, _081E81A4 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081E81B0
	movs r0, #1
	b _081E81B2
	.align 2, 0
_081E819C: .4byte 0x00001614
_081E81A0: .4byte 0x00001618
_081E81A4: .4byte 0x00001610
_081E81A8: .4byte 0x0000FFFF
_081E81AC: .4byte 0x00001625
_081E81B0:
	movs r0, #0
_081E81B2:
	cmp r0, #0
	beq _081E81FC
	movs r1, #0x10
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E81C4
	movs r0, #1
	b _081E81C6
_081E81C4:
	movs r0, #0
_081E81C6:
	adds r6, r0, #0
	cmp r6, #0
	bne _081E8230
	adds r0, r5, #0
	bl FUN_081e3ce8
	movs r1, #0x10
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #7
	bl FUN_081e4cb4
	ldr r0, _081E81F4 @ =0x00001618
	adds r1, r5, r0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _081E81F8 @ =0x00001625
	adds r0, r5, r1
	strb r6, [r0]
	b _081E83DA
	.align 2, 0
_081E81F4: .4byte 0x00001618
_081E81F8: .4byte 0x00001625
_081E81FC:
	ldr r0, _081E822C @ =0x00001625
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x77
	bls _081E8230
	bl LinkShopManager_Abort
	adds r0, r5, #0
	bl FUN_081e44d0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	bl KillEntity
	b _081E83DA
	.align 2, 0
_081E822C: .4byte 0x00001625
_081E8230:
	movs r1, #4
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E823E
	movs r0, #1
	b _081E8240
_081E823E:
	movs r0, #0
_081E8240:
	cmp r0, #0
	beq _081E8280
	movs r1, #0x20
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8252
	movs r0, #1
	b _081E8254
_081E8252:
	movs r0, #0
_081E8254:
	cmp r0, #0
	bne _081E8280
	adds r0, r5, #0
	bl FUN_081e32d8
	movs r1, #0x20
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #8
	bl FUN_081e4cb4
	ldr r0, _081E827C @ =0x00001618
	adds r1, r5, r0
	movs r0, #8
	strb r0, [r1]
	b _081E83DA
	.align 2, 0
_081E827C: .4byte 0x00001618
_081E8280:
	movs r1, #8
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E828E
	movs r0, #1
	b _081E8290
_081E828E:
	movs r0, #0
_081E8290:
	cmp r0, #0
	beq _081E82CC
	movs r1, #0x40
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E82A2
	movs r0, #1
	b _081E82A4
_081E82A2:
	movs r0, #0
_081E82A4:
	cmp r0, #0
	bne _081E82CC
	adds r0, r5, #0
	bl FUN_081e3444
	movs r1, #0x40
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0xc
	bl FUN_081e4c64
	ldr r0, _081E82C8 @ =0x00001618
	adds r1, r5, r0
	movs r0, #0xc
	strb r0, [r1]
	b _081E83DA
	.align 2, 0
_081E82C8: .4byte 0x00001618
_081E82CC:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E82DC
	movs r0, #1
	b _081E82DE
_081E82DC:
	movs r0, #0
_081E82DE:
	cmp r0, #0
	beq _081E82F4
	ldr r1, _081E82F0 @ =0x00001618
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_081e4c64
	b _081E83DA
	.align 2, 0
_081E82F0: .4byte 0x00001618
_081E82F4:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8304
	movs r0, #1
	b _081E8306
_081E8304:
	movs r0, #0
_081E8306:
	cmp r0, #0
	beq _081E8320
	ldr r1, _081E831C @ =0x00001618
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_081e4cb4
	b _081E83DA
	.align 2, 0
_081E831C: .4byte 0x00001618
_081E8320:
	movs r1, #0x10
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E832E
	movs r0, #1
	b _081E8330
_081E832E:
	movs r0, #0
_081E8330:
	cmp r0, #0
	beq _081E83DA
	movs r1, #0x20
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8342
	movs r0, #1
	b _081E8344
_081E8342:
	movs r0, #0
_081E8344:
	cmp r0, #0
	beq _081E83DA
	movs r1, #0x40
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8356
	movs r0, #1
	b _081E8358
_081E8356:
	movs r0, #0
_081E8358:
	cmp r0, #0
	beq _081E83DA
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xc
	bne _081E83DA
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E837A
	movs r0, #1
	b _081E837C
_081E837A:
	movs r0, #0
_081E837C:
	cmp r0, #0
	beq _081E83DA
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081E83DA
	bl LinkShopManager_IsParent
	cmp r0, #0
	beq _081E83BC
	ldr r0, _081E83B0 @ =FUN_081e7db4
	str r0, [r5, #0x18]
	ldr r0, _081E83B4 @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E83B8 @ =0x00001616
	adds r0, r5, r1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e2d98
	b _081E83D4
	.align 2, 0
_081E83B0: .4byte FUN_081e7db4
_081E83B4: .4byte 0x00001614
_081E83B8: .4byte 0x00001616
_081E83BC:
	ldr r0, _081E83E0 @ =FUN_081e7fd0
	movs r4, #1
	str r0, [r5, #0x18]
	ldr r1, _081E83E4 @ =0x00001614
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e2dd8
_081E83D4:
	ldr r1, _081E83E8 @ =0x0000162C
	adds r0, r5, r1
	strh r4, [r0]
_081E83DA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E83E0: .4byte FUN_081e7fd0
_081E83E4: .4byte 0x00001614
_081E83E8: .4byte 0x0000162C
