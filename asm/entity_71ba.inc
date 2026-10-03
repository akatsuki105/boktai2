	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Entity71BA_IsPlayerOnTile
Entity71BA_IsPlayerOnTile: @ 0x080A0080
	push {lr}
	adds r3, r0, #0
	ldr r0, _080A00B0 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A00AC
	cmp r1, #0
	blt _080A00AC
	ldr r0, _080A00B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A00AC
	ldr r0, _080A00B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A00BC
_080A00AC:
	movs r0, #0
	b _080A00CA
	.align 2, 0
_080A00B0: .4byte 0x03002BE0
_080A00B4: .4byte 0x030046A8
_080A00B8: .4byte 0x030046AC
_080A00BC:
	ldr r0, _080A00D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A00CA:
	ldrh r3, [r3, #0x1e]
	cmp r0, r3
	beq _080A00D8
	movs r0, #0
	b _080A00DA
	.align 2, 0
_080A00D4: .4byte 0x030046A4
_080A00D8:
	movs r0, #1
_080A00DA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity71BA_IsPlayerAtHeight
Entity71BA_IsPlayerAtHeight: @ 0x080A00E0
	push {lr}
	ldr r1, _080A00F8 @ =0x03002BE0
	ldr r1, [r1]
	movs r2, #0x2e
	ldrsh r1, [r1, r2]
	ldrh r0, [r0, #0x20]
	lsls r0, r0, #8
	cmp r1, r0
	beq _080A00FC
	movs r0, #0
	b _080A00FE
	.align 2, 0
_080A00F8: .4byte 0x03002BE0
_080A00FC:
	movs r0, #1
_080A00FE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0104
FUN_080a0104: @ 0x080A0104
	push {lr}
	adds r2, r1, #0
	ldrb r1, [r0, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A0120
	ldr r0, _080A011C @ =0x03002BE0
	ldr r0, [r0]
	ldrh r1, [r0, #0x2c]
	b _080A0126
	.align 2, 0
_080A011C: .4byte 0x03002BE0
_080A0120:
	ldr r0, _080A0134 @ =0x03002BE0
	ldr r0, [r0]
	ldrh r1, [r0, #0x30]
_080A0126:
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	ble _080A0138
	movs r0, #0
	b _080A013A
	.align 2, 0
_080A0134: .4byte 0x03002BE0
_080A0138:
	movs r0, #1
_080A013A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0140
FUN_080a0140: @ 0x080A0140
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _080A017C @ =0x03002BE0
	ldr r2, [r0]
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #4
	bne _080A0184
	ldr r1, _080A0180 @ =0x000003BD
	adds r0, r2, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080A016A
	ldrb r1, [r3, #0x1c]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A01C2
_080A016A:
	cmp r2, #7
	bne _080A01D0
	ldrb r1, [r3, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A01C2
	b _080A01D0
	.align 2, 0
_080A017C: .4byte 0x03002BE0
_080A0180: .4byte 0x000003BD
_080A0184:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A01C2
	ldr r0, _080A01C8 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A01A4
	ldr r0, _080A01CC @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A01A4
	movs r1, #1
_080A01A4:
	cmp r1, #0
	bne _080A01B6
	ldr r0, [r4]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A01D0
_080A01B6:
	adds r0, r3, #0
	movs r1, #0x28
	bl FUN_080a0104
	cmp r0, #0
	beq _080A01D0
_080A01C2:
	movs r0, #1
	b _080A01D2
	.align 2, 0
_080A01C8: .4byte 0x03002B8C
_080A01CC: .4byte 0x03002B60
_080A01D0:
	movs r0, #0
_080A01D2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a01d8
FUN_080a01d8: @ 0x080A01D8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl Entity71BA_IsPlayerAtHeight
	adds r5, r0, #0
	cmp r5, #0
	beq _080A0250
	adds r0, r4, #0
	bl Entity71BA_IsPlayerOnTile
	cmp r0, #0
	beq _080A0228
	adds r0, r4, #0
	bl FUN_080a0140
	adds r5, r0, #0
	cmp r5, #0
	bne _080A0228
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	strb r5, [r4, #0x1d]
	ldr r0, _080A0224 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807a334
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _080A0260
	movs r1, #0
	bl VM_ExecByID
	b _080A0260
	.align 2, 0
_080A0224: .4byte 0x03002BE0
_080A0228:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r4, #0x1e]
	ldrh r3, [r4, #0x20]
	movs r2, #0xff
	str r2, [sp]
	ldr r2, _080A024C @ =0x0000082A
	str r2, [sp, #4]
	movs r2, #0
	bl Map_AddTileOverride
	movs r0, #1
	strb r0, [r4, #0x1d]
	b _080A0260
	.align 2, 0
_080A024C: .4byte 0x0000082A
_080A0250:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	strb r5, [r4, #0x1d]
_080A0260:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a0268
FUN_080a0268: @ 0x080A0268
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _080A02A4 @ =0x03002BE0
	ldr r2, [r0]
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #4
	bne _080A02AC
	ldr r1, _080A02A8 @ =0x000003BD
	adds r0, r2, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080A0292
	ldrb r1, [r3, #0x1c]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A02E2
_080A0292:
	cmp r2, #7
	bne _080A02F0
	ldrb r1, [r3, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A02E2
	b _080A02F0
	.align 2, 0
_080A02A4: .4byte 0x03002BE0
_080A02A8: .4byte 0x000003BD
_080A02AC:
	ldr r0, _080A02E8 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A02C0
	ldr r0, _080A02EC @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A02C0
	movs r1, #1
_080A02C0:
	cmp r1, #0
	bne _080A02D6
	ldr r0, [r4]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A02D6
	cmp r0, #3
	bne _080A02F0
_080A02D6:
	adds r0, r3, #0
	movs r1, #0x28
	bl FUN_080a0104
	cmp r0, #0
	beq _080A02F0
_080A02E2:
	movs r0, #1
	b _080A02F2
	.align 2, 0
_080A02E8: .4byte 0x03002B8C
_080A02EC: .4byte 0x03002B60
_080A02F0:
	movs r0, #0
_080A02F2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity71BA_ClampPlayer
Entity71BA_ClampPlayer: @ 0x080A02F8
	push {r4, lr}
	adds r2, r1, #0
	ldrb r1, [r0, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A032C
	ldr r4, _080A0328 @ =0x03002BE0
	ldr r3, [r4]
	ldrh r1, [r3, #0x2c]
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	blt _080A0350
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, r0, r2
	strh r0, [r3, #0x2c]
	ldr r0, [r4]
	ldrh r1, [r0, #0x2c]
	movs r2, #0x82
	lsls r2, r2, #1
	b _080A034C
	.align 2, 0
_080A0328: .4byte 0x03002BE0
_080A032C:
	ldr r4, _080A0358 @ =0x03002BE0
	ldr r3, [r4]
	ldrh r1, [r3, #0x30]
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	blt _080A0350
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, r0, r2
	strh r0, [r3, #0x30]
	ldr r0, [r4]
	ldrh r1, [r0, #0x30]
	movs r2, #0x84
	lsls r2, r2, #1
_080A034C:
	adds r0, r0, r2
	strh r1, [r0]
_080A0350:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A0358: .4byte 0x03002BE0

	thumb_func_start FUN_080a035c
FUN_080a035c: @ 0x080A035C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl Entity71BA_IsPlayerAtHeight
	adds r5, r0, #0
	cmp r5, #0
	bne _080A036E
	b _080A0490
_080A036E:
	adds r0, r4, #0
	bl Entity71BA_IsPlayerOnTile
	adds r5, r0, #0
	cmp r5, #0
	beq _080A0442
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A03BE
	ldr r2, _080A03A4 @ =0x03002BE0
	ldr r1, [r2]
	ldr r0, _080A03A8 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r1, [r4, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A03B0
	ldr r0, [r2]
	ldr r1, _080A03AC @ =0x000003BD
	adds r0, r0, r1
	movs r1, #7
	b _080A03B8
	.align 2, 0
_080A03A4: .4byte 0x03002BE0
_080A03A8: .4byte 0x000003F3
_080A03AC: .4byte 0x000003BD
_080A03B0:
	ldr r0, [r2]
	ldr r1, _080A0428 @ =0x000003BD
	adds r0, r0, r1
	movs r1, #1
_080A03B8:
	strb r1, [r0]
	movs r0, #1
	strh r0, [r4, #0x22]
_080A03BE:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A03D0
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	movs r0, #0
	strb r0, [r4, #0x1d]
_080A03D0:
	adds r0, r4, #0
	movs r1, #0x28
	bl Entity71BA_ClampPlayer
	ldr r0, _080A042C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _080A04B6
	ldr r0, _080A0430 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A03FC
	ldr r0, _080A0434 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A03FC
	movs r1, #1
_080A03FC:
	cmp r1, #0
	bne _080A04B6
	ldr r0, _080A042C @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A04B6
	cmp r0, #3
	beq _080A04B6
	ldrb r1, [r4, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A0438
	adds r0, r2, #0
	movs r1, #7
	bl FUN_0807a44c
	b _080A04B6
	.align 2, 0
_080A0428: .4byte 0x000003BD
_080A042C: .4byte 0x03002BE0
_080A0430: .4byte 0x03002B8C
_080A0434: .4byte 0x03002B60
_080A0438:
	adds r0, r2, #0
	movs r1, #1
	bl FUN_0807a44c
	b _080A04B6
_080A0442:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	beq _080A0458
	ldr r0, _080A0484 @ =0x03002BE0
	ldr r1, [r0]
	ldr r0, _080A0488 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	strh r5, [r4, #0x22]
_080A0458:
	adds r0, r4, #0
	bl FUN_080a0268
	cmp r0, #0
	bne _080A04A6
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A04B6
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r4, #0x1e]
	ldrh r3, [r4, #0x20]
	movs r2, #0xff
	str r2, [sp]
	ldr r2, _080A048C @ =0x0000080B
	str r2, [sp, #4]
	movs r2, #0
	bl Map_AddTileOverride
	movs r0, #1
	strb r0, [r4, #0x1d]
	b _080A04B6
	.align 2, 0
_080A0484: .4byte 0x03002BE0
_080A0488: .4byte 0x000003F3
_080A048C: .4byte 0x0000080B
_080A0490:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	beq _080A04A6
	ldr r0, _080A04C0 @ =0x03002BE0
	ldr r1, [r0]
	ldr r0, _080A04C4 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	strh r5, [r4, #0x22]
_080A04A6:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A04B6
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	strb r5, [r4, #0x1d]
_080A04B6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A04C0: .4byte 0x03002BE0
_080A04C4: .4byte 0x000003F3

	thumb_func_start FUN_080a04c8
FUN_080a04c8: @ 0x080A04C8
	push {lr}
	ldr r0, _080A04FC @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A04DE
	ldr r0, _080A0500 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A04DE
	movs r1, #1
_080A04DE:
	cmp r1, #0
	bne _080A04F6
	ldr r0, _080A0504 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A04F6
	cmp r0, #3
	bne _080A0508
_080A04F6:
	movs r0, #1
	b _080A050A
	.align 2, 0
_080A04FC: .4byte 0x03002B8C
_080A0500: .4byte 0x03002B60
_080A0504: .4byte 0x03002BE0
_080A0508:
	movs r0, #0
_080A050A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity71BA_UpdateTileOverride
Entity71BA_UpdateTileOverride: @ 0x080A0510
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl Entity71BA_IsPlayerAtHeight
	adds r5, r0, #0
	cmp r5, #0
	beq _080A05D0
	adds r0, r4, #0
	bl Entity71BA_IsPlayerOnTile
	cmp r0, #0
	beq _080A0580
	adds r0, r4, #0
	bl FUN_080a04c8
	cmp r0, #0
	beq _080A053E
	adds r0, r4, #0
	movs r1, #0x40
	bl Entity71BA_ClampPlayer
	b _080A05E0
_080A053E:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A05E0
	ldrb r1, [r4, #0x1c]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080A055C
	ldrh r1, [r4, #0x2a]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r4, #0x2a]
	b _080A056E
_080A055C:
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	strb r5, [r4, #0x1d]
	ldr r0, _080A057C @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807a334
_080A056E:
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _080A05E0
	movs r1, #0
	bl VM_ExecByID
	b _080A05E0
	.align 2, 0
_080A057C: .4byte 0x03002BE0
_080A0580:
	adds r0, r4, #0
	bl FUN_080a04c8
	cmp r0, #0
	beq _080A05BC
	adds r0, r4, #0
	movs r1, #0x40
	bl FUN_080a0104
	cmp r0, #0
	beq _080A05BC
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A05E0
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r4, #0x1e]
	ldrh r3, [r4, #0x20]
	movs r2, #0xff
	str r2, [sp]
	ldr r2, _080A05B8 @ =0x0000082A
	str r2, [sp, #4]
	movs r2, #0
	bl Map_AddTileOverride
	movs r0, #1
	strb r0, [r4, #0x1d]
	b _080A05E0
	.align 2, 0
_080A05B8: .4byte 0x0000082A
_080A05BC:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A05E0
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	movs r0, #0
	strb r0, [r4, #0x1d]
	b _080A05E0
_080A05D0:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A05E0
	adds r0, r4, #0
	adds r0, #0x24
	bl Map_RemoveTileOverride
	strb r5, [r4, #0x1d]
_080A05E0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start Entity71BA_Update
Entity71BA_Update: @ 0x080A05E8
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A0608 @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080A0602
	ldr r1, [r2, #0x38]
	adds r0, r2, #0
	bl _call_via_r1
_080A0602:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080A0608: .4byte 0x03002BE0

	thumb_func_start Entity71BA_Destroy
Entity71BA_Destroy: @ 0x080A060C
	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0x1d]
	cmp r1, #0
	beq _080A061C
	adds r0, #0x24
	bl Map_RemoveTileOverride
_080A061C:
	pop {r1}
	bx r1

	thumb_func_start Entity71BA_Init
Entity71BA_Init: @ 0x080A0620
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0
	strh r1, [r5, #0x18]
	strb r0, [r5, #0x1d]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A063C
	bl VM_GetValue
	b _080A063E
_080A063C:
	movs r0, #9
_080A063E:
	strb r0, [r5, #0x1c]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A0688
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A0680 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080A0684 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	b _080A0692
	.align 2, 0
_080A0680: .4byte 0xFFFF0000
_080A0684: .4byte 0x0000FFFF
_080A0688:
	ldr r1, _080A06C0 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_080A0692:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A06BA
	cmp r1, #0
	blt _080A06BA
	ldr r0, _080A06C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A06BA
	ldr r0, _080A06C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A06CC
_080A06BA:
	movs r0, #0
	b _080A06DA
	.align 2, 0
_080A06C0: .4byte 0xFFFF0000
_080A06C4: .4byte 0x030046A8
_080A06C8: .4byte 0x030046AC
_080A06CC:
	ldr r0, _080A0704 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A06DA:
	strh r0, [r5, #0x1e]
	mov r0, sp
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strh r0, [r5, #0x20]
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A06F4
	bl VM_GetValue
_080A06F4:
	str r0, [r5, #0x34]
	ldrb r1, [r5, #0x1c]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A070C
	ldr r0, _080A0708 @ =FUN_080a01d8
	b _080A071E
	.align 2, 0
_080A0704: .4byte 0x030046A4
_080A0708: .4byte FUN_080a01d8
_080A070C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080A071C
	ldr r0, _080A0718 @ =FUN_080a035c
	b _080A071E
	.align 2, 0
_080A0718: .4byte FUN_080a035c
_080A071C:
	ldr r0, _080A072C @ =Entity71BA_UpdateTileOverride
_080A071E:
	str r0, [r5, #0x38]
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A072C: .4byte Entity71BA_UpdateTileOverride

	thumb_func_start Entity71BA_Create
Entity71BA_Create: @ 0x080A0730
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0x3c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A076C
	ldr r1, _080A0764 @ =Entity71BA_Update
	ldr r2, _080A0768 @ =Entity71BA_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity71BA_Init
	cmp r0, #0
	bge _080A076C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A076E
	.align 2, 0
_080A0764: .4byte Entity71BA_Update
_080A0768: .4byte Entity71BA_Destroy
_080A076C:
	adds r0, r4, #0
_080A076E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
