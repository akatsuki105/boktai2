	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xd0
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _081B60E4 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B60E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B60EA
	.align 2, 0
_081B60E4: .4byte 0x0000046D
_081B60E8:
	movs r0, #0
_081B60EA:
	cmp r0, #0
	beq _081B6126
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r4, r7, r2
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081B6114
	movs r0, #0xd4
	bl PlaySound_082406e0
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081B6114:
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	movs r1, #0
	strh r0, [r4]
	ldr r3, _081B61F8 @ =0x0000046E
	adds r0, r7, r3
	strb r1, [r0]
_081B6126:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	mov sb, r2
	cmp r6, #0x11
	bgt _081B6166
	ldrh r3, [r5, #8]
	cmp r3, #0
	bne _081B6166
	ldrh r1, [r5, #0xe]
	ldrb r2, [r5, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081B6166
	cmp r2, #1
	beq _081B6166
	strh r3, [r5, #0xe]
_081B6166:
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _081B61D8
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B61D8
	ldr r2, _081B61FC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _081B6200 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r2, _081B6204 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081B6208 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081B620C @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r2, #0xa
	str r2, [sp]
	movs r2, #6
	str r2, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	add r2, sp, #0x10
	bl EmitSmoke
_081B61D8:
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _081B6210
	asrs r0, r0, #2
	b _081B6216
	.align 2, 0
_081B61F8: .4byte 0x0000046E
_081B61FC: .4byte 0xFFFF0000
_081B6200: .4byte 0x0000FFFF
_081B6204: .4byte 0x030046B8
_081B6208: .4byte 0x000003FF
_081B620C: .4byte 0x0203B400
_081B6210:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081B6216:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081B6236
	asrs r0, r0, #2
	b _081B623C
_081B6236:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081B623C:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081B6246
	movs r3, #0xc8
	b _081B6250
_081B6246:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081B6250
	adds r3, r0, #0
_081B6250:
	cmp r2, #0xc8
	ble _081B6258
	movs r2, #0xc8
	b _081B6262
_081B6258:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081B6262
	adds r2, r0, #0
_081B6262:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _081B6286
	cmp r2, #0
	bne _081B6286
	movs r0, #1
	b _081B6288
_081B6286:
	movs r0, #0
_081B6288:
	cmp r0, #0
	bne _081B6290
	bl _081B71C4
_081B6290:
	ldr r6, _081B62EC @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B629E
	bl _081B71C4
_081B629E:
	ldr r1, _081B62F0 @ =0x0000046B
	adds r0, r7, r1
	movs r2, #1
	mov r8, r2
	mov r3, r8
	strb r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, _081B62F4 @ =0xFFFFFEDF
	ldrh r1, [r2]
	ands r0, r1
	movs r6, #0
	strh r0, [r2]
	mov r5, sb
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r3, [r5]
	ands r3, r0
	str r3, [r5]
	ldr r1, _081B62F8 @ =0x0000049C
	adds r0, r7, r1
	ldr r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xc
	ands r4, r0
	str r2, [sp, #0xa8]
	cmp r4, #0
	beq _081B62FC
	movs r0, #2
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _081B71C4
	.align 2, 0
_081B62EC: .4byte 0x0000046E
_081B62F0: .4byte 0x0000046B
_081B62F4: .4byte 0xFFFFFEDF
_081B62F8: .4byte 0x0000049C
_081B62FC:
	movs r0, #8
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B6388
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r5, _081B636C @ =0x00000469
	adds r0, r7, r5
	strb r6, [r0]
	ldr r1, _081B6370 @ =0x0000046A
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _081B6374 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	adds r3, #4
	adds r0, r7, r3
	mov r5, r8
	strb r5, [r0]
	ldr r2, _081B6378 @ =FUN_081b570c
	movs r1, #0x14
	adds r3, #1
	adds r0, r7, r3
	strb r5, [r0]
	ldr r5, _081B637C @ =0x0000046B
	adds r0, r7, r5
	strb r6, [r0]
	ldr r6, _081B6380 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r0, #9
	rsbs r0, r0, #0
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r4, _081B6384 @ =0x00000482
	adds r0, r7, r4
	mov r5, r8
	strh r5, [r0]
	bl _081B71C4
	.align 2, 0
_081B636C: .4byte 0x00000469
_081B6370: .4byte 0x0000046A
_081B6374: .4byte 0x00000484
_081B6378: .4byte FUN_081b570c
_081B637C: .4byte 0x0000046B
_081B6380: .4byte 0x00000553
_081B6384: .4byte 0x00000482
_081B6388:
	movs r2, #0x80
	ands r1, r2
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _081B6396
	b _081B6AA8
_081B6396:
	orrs r3, r2
	str r3, [r5]
	movs r0, #4
	ldr r6, _081B63F8 @ =0x00000222
	adds r4, r7, r6
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	str r4, [sp, #0xc0]
	cmp r0, #0
	bne _081B63B8
	bl _081B71C4
_081B63B8:
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
	str r3, [sp, #0xa4]
	str r2, [sp, #0xc8]
	cmp r4, #0
	blt _081B63F4
	cmp r1, #0
	blt _081B63F4
	ldr r0, _081B63FC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B63F4
	ldr r0, _081B6400 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6404
_081B63F4:
	movs r4, #0
	b _081B6412
	.align 2, 0
_081B63F8: .4byte 0x00000222
_081B63FC: .4byte 0x030046A8
_081B6400: .4byte 0x030046AC
_081B6404:
	ldr r0, _081B6424 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B6412:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B6428
	adds r0, #4
	b _081B6434
	.align 2, 0
_081B6424: .4byte 0x030046A4
_081B6428:
	ldr r0, _081B6448 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B6434:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B644C
	cmp r2, #2
	beq _081B6450
	b _081B6454
	.align 2, 0
_081B6448: .4byte 0x030046A4
_081B644C:
	ldrb r0, [r5, #4]
	b _081B6452
_081B6450:
	ldrb r0, [r5]
_081B6452:
	subs r1, r1, r0
_081B6454:
	strh r1, [r5, #2]
	ldr r0, _081B6468 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B646C
	movs r0, #1
	b _081B646E
	.align 2, 0
_081B6468: .4byte 0x030047A4
_081B646C:
	movs r0, #0
_081B646E:
	cmp r0, #0
	beq _081B64AC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081B648E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B648A
	adds r2, r0, #0
_081B648A:
	cmp r2, #0
	bge _081B6498
_081B648E:
	ldr r2, _081B6494 @ =0x000005C4
	adds r0, r7, r2
	b _081B69B8
	.align 2, 0
_081B6494: .4byte 0x000005C4
_081B6498:
	ldr r1, _081B64A8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B64F4
	.align 2, 0
_081B64A8: .4byte 0x03002BE0
_081B64AC:
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
	blt _081B64D8
	cmp r1, #0
	blt _081B64D8
	ldr r0, _081B64DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B64D8
	ldr r0, _081B64E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B64E4
_081B64D8:
	movs r5, #0
	b _081B64F2
	.align 2, 0
_081B64DC: .4byte 0x030046A8
_081B64E0: .4byte 0x030046AC
_081B64E4:
	ldr r0, _081B652C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B64F2:
	movs r2, #0
_081B64F4:
	ldr r4, _081B6530 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B6514
	ldr r1, _081B6534 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B6514
	b _081B68F4
_081B6514:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xa8]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _081B6538
	movs r0, #0
	b _081B69CE
	.align 2, 0
_081B652C: .4byte 0x030046A4
_081B6530: .4byte 0x00000256
_081B6534: .4byte 0x03002BE0
_081B6538:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r6, [sp, #0xc0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0x80
	ldr r2, [sp, #0xa8]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081B65E8
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r4, _081B65D8 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x28]
	movs r5, #1
	strb r5, [r4]
	ldr r6, _081B65DC @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x2c]
	movs r2, #0
	strb r2, [r6]
	subs r3, #0x65
	adds r3, r7, r3
	str r3, [sp, #0x30]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x34]
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r6, r7
	mov r8, r6
	mov r0, sb
	strh r0, [r6]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _081B65E0 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081B65E4 @ =0x00000484
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x28]
	str r5, [sp, #0x98]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x34]
	str r1, [sp, #0xbc]
	mov r2, r8
	str r2, [sp, #0xac]
	b _081B67B2
	.align 2, 0
_081B65D8: .4byte 0x0000046D
_081B65DC: .4byte 0x0000046B
_081B65E0: .4byte 0x00000469
_081B65E4: .4byte 0x00000484
_081B65E8:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081B66A8 @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _081B66AC @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x38]
	movs r6, #0
	strb r6, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x40]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x44]
	strh r2, [r5]
	movs r1, #5
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x48]
	movs r3, #0
	strb r3, [r6]
	ldr r4, _081B66B0 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r6, _081B66B4 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081B66B8 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa4]
	ldr r0, [r0]
	str r0, [sp, #0x4c]
	ldr r1, [sp, #0xc8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x4c]
	strh r1, [r6]
	ldr r6, [sp, #0xc8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x4c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x90]
	ldr r2, [sp, #0x3c]
	str r2, [sp, #0xb8]
	ldr r3, [sp, #0x40]
	str r3, [sp, #0xbc]
	ldr r4, [sp, #0x44]
	str r4, [sp, #0xac]
	mov r5, ip
	cmp r5, #0
	blt _081B66A4
	cmp r1, #0
	blt _081B66A4
	ldr r0, _081B66BC @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081B66A4
	ldr r0, _081B66C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B66C4
_081B66A4:
	movs r4, #0
	b _081B66D4
	.align 2, 0
_081B66A8: .4byte 0x0000046D
_081B66AC: .4byte 0x0000046B
_081B66B0: .4byte 0x00000469
_081B66B4: .4byte 0x0000046A
_081B66B8: .4byte 0x00000484
_081B66BC: .4byte 0x030046A8
_081B66C0: .4byte 0x030046AC
_081B66C4:
	ldr r0, _081B66E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, ip
	adds r4, r0, r6
_081B66D4:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B66E8
	adds r0, #4
	b _081B66F4
	.align 2, 0
_081B66E4: .4byte 0x030046A4
_081B66E8:
	ldr r0, _081B6708 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B66F4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B670C
	cmp r2, #2
	beq _081B6712
	b _081B6718
	.align 2, 0
_081B6708: .4byte 0x030046A4
_081B670C:
	ldr r2, [sp, #0x4c]
	ldrb r0, [r2, #4]
	b _081B6716
_081B6712:
	ldr r3, [sp, #0x4c]
	ldrb r0, [r3]
_081B6716:
	subs r1, r1, r0
_081B6718:
	ldr r4, [sp, #0x4c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B6744
	cmp r1, #0
	blt _081B6744
	ldr r0, _081B6748 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B6744
	ldr r0, _081B674C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6750
_081B6744:
	movs r4, #0
	b _081B675E
	.align 2, 0
_081B6748: .4byte 0x030046A8
_081B674C: .4byte 0x030046AC
_081B6750:
	ldr r0, _081B6774 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B675E:
	ldr r6, [sp, #0xa4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B6778
	adds r0, #4
	b _081B6784
	.align 2, 0
_081B6774: .4byte 0x030046A4
_081B6778:
	ldr r0, _081B6798 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B6784:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B679C
	cmp r3, #2
	beq _081B67A0
	b _081B67A4
	.align 2, 0
_081B6798: .4byte 0x030046A4
_081B679C:
	ldrb r0, [r5, #4]
	b _081B67A2
_081B67A0:
	ldrb r0, [r5]
_081B67A2:
	subs r2, r2, r0
_081B67A4:
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B67B2:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x50]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081B67DC @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	cmp r0, #0
	bne _081B68BC
	movs r1, #4
	ldr r2, [sp, #0xc0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B67E0
	movs r0, #1
	b _081B67E2
	.align 2, 0
_081B67DC: .4byte 0x00000482
_081B67E0:
	movs r0, #0
_081B67E2:
	ldr r3, _081B68CC @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	cmp r0, #0
	bne _081B68BC
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xcc]
	ldr r1, _081B68D0 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B68D4 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081B68D8 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _081B68DC @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B68E0 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	ldr r6, _081B68E4 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	ldr r1, _081B68E8 @ =0x030046B8
	adds r2, r5, #0
_081B682A:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081B68EC @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081B68F0 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081B684E
	adds r3, #1
	cmp r3, #3
	ble _081B682A
	adds r0, r5, #0
_081B684E:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xb4]
	strb r0, [r6]
	add r0, sp, #0x50
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xc4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0xb8]
	strb r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb0]
	strb r0, [r4]
_081B68BC:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _081B69CE
	.align 2, 0
_081B68CC: .4byte 0x00000482
_081B68D0: .4byte 0x0000054F
_081B68D4: .4byte 0x0000054C
_081B68D8: .4byte 0x0000054E
_081B68DC: .4byte 0x00000541
_081B68E0: .4byte 0x000005BC
_081B68E4: .4byte 0x00000542
_081B68E8: .4byte 0x030046B8
_081B68EC: .4byte 0x000003FF
_081B68F0: .4byte 0x0203B400
_081B68F4:
	add r6, sp, #0x18
	ldr r0, _081B6934 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081B6938
	adds r0, #4
	b _081B6944
	.align 2, 0
_081B6934: .4byte 0x030046A4
_081B6938:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B6944:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B697C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B6984
	ldr r0, _081B6980 @ =0xFFFFFDFF
	ldr r6, [sp, #0xa8]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B69AE
	.align 2, 0
_081B697C: .4byte 0x000004A4
_081B6980: .4byte 0xFFFFFDFF
_081B6984:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B69A4
	cmp r0, #2
	beq _081B69A0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B69A0:
	movs r0, #1
	b _081B69B0
_081B69A4:
	ldr r0, _081B69C4 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B69AE:
	movs r0, #0
_081B69B0:
	cmp r0, #0
	bne _081B69CC
	ldr r3, _081B69C8 @ =0x000005C4
	adds r0, r7, r3
_081B69B8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B69CE
	.align 2, 0
_081B69C4: .4byte 0xFFFFFDFF
_081B69C8: .4byte 0x000005C4
_081B69CC:
	movs r0, #1
_081B69CE:
	cmp r0, #0
	bne _081B6A3E
	ldr r4, _081B6A04 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B6A0C
	ldr r0, _081B6A08 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B6A36
	.align 2, 0
_081B6A04: .4byte 0x000004A4
_081B6A08: .4byte 0xFFFFFDFF
_081B6A0C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B6A2C
	cmp r0, #2
	beq _081B6A28
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B6A28:
	movs r0, #1
	b _081B6A38
_081B6A2C:
	ldr r0, _081B6A94 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B6A36:
	movs r0, #0
_081B6A38:
	cmp r0, #0
	bne _081B6A3E
	b _081B7154
_081B6A3E:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081B6A98 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081B6A9C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081B6AA0 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081B6AA4 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _081B71C4
	.align 2, 0
_081B6A94: .4byte 0xFFFFFDFF
_081B6A98: .4byte 0x0000046D
_081B6A9C: .4byte 0x0000046B
_081B6AA0: .4byte 0x0000046A
_081B6AA4: .4byte 0x00000484
_081B6AA8:
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B6AB6
	b _081B71C4
_081B6AB6:
	movs r1, #0x10
	mov r6, sb
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	strh r4, [r0, #6]
	adds r3, r7, r1
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
	str r3, [sp, #0xa4]
	str r2, [sp, #0xc8]
	cmp r4, #0
	blt _081B6B02
	cmp r1, #0
	blt _081B6B02
	ldr r0, _081B6B08 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B6B02
	ldr r0, _081B6B0C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6B10
_081B6B02:
	movs r4, #0
	b _081B6B1E
	.align 2, 0
_081B6B08: .4byte 0x030046A8
_081B6B0C: .4byte 0x030046AC
_081B6B10:
	ldr r0, _081B6B30 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B6B1E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B6B34
	adds r0, #4
	b _081B6B40
	.align 2, 0
_081B6B30: .4byte 0x030046A4
_081B6B34:
	ldr r0, _081B6B54 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B6B40:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B6B58
	cmp r2, #2
	beq _081B6B5C
	b _081B6B60
	.align 2, 0
_081B6B54: .4byte 0x030046A4
_081B6B58:
	ldrb r0, [r5, #4]
	b _081B6B5E
_081B6B5C:
	ldrb r0, [r5]
_081B6B5E:
	subs r1, r1, r0
_081B6B60:
	strh r1, [r5, #2]
	ldr r0, _081B6B74 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B6B78
	movs r0, #1
	b _081B6B7A
	.align 2, 0
_081B6B74: .4byte 0x030047A4
_081B6B78:
	movs r0, #0
_081B6B7A:
	cmp r0, #0
	beq _081B6BB0
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _081B6B8C
	b _081B70CC
_081B6B8C:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B6B98
	adds r2, r0, #0
_081B6B98:
	cmp r2, #0
	bge _081B6B9E
	b _081B70CC
_081B6B9E:
	ldr r1, _081B6BAC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B6BF8
	.align 2, 0
_081B6BAC: .4byte 0x03002BE0
_081B6BB0:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B6BDC
	cmp r1, #0
	blt _081B6BDC
	ldr r0, _081B6BE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B6BDC
	ldr r0, _081B6BE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6BE8
_081B6BDC:
	movs r5, #0
	b _081B6BF6
	.align 2, 0
_081B6BE0: .4byte 0x030046A8
_081B6BE4: .4byte 0x030046AC
_081B6BE8:
	ldr r0, _081B6C30 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B6BF6:
	movs r2, #0
_081B6BF8:
	ldr r6, _081B6C34 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B6C18
	ldr r1, _081B6C38 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B6C18
	b _081B700C
_081B6C18:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xa8]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x54]
	cmp r0, #0
	beq _081B6C3C
	movs r0, #0
	b _081B70E6
	.align 2, 0
_081B6C30: .4byte 0x030046A4
_081B6C34: .4byte 0x00000256
_081B6C38: .4byte 0x03002BE0
_081B6C3C:
	ldr r3, _081B6CE0 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xc0]
	cmp r6, #0
	beq _081B6CFC
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081B6CE4 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x58]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _081B6CE8 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081B6CEC @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x60]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x64]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	add r1, sp, #0x54
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081B6CF0 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081B6CF4 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x54]
	str r6, [r1]
	ldr r6, _081B6CF8 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x58]
	str r5, [sp, #0x98]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x64]
	str r1, [sp, #0xbc]
	mov r2, r8
	str r2, [sp, #0xac]
	b _081B6ECA
	.align 2, 0
_081B6CE0: .4byte 0x00000222
_081B6CE4: .4byte 0x0000046D
_081B6CE8: .4byte 0x0000046B
_081B6CEC: .4byte 0x00000553
_081B6CF0: .4byte 0x00000469
_081B6CF4: .4byte 0x00000484
_081B6CF8: .4byte 0x0000046C
_081B6CFC:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081B6DBC @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _081B6DC0 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x68]
	movs r2, #0
	strb r2, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x70]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x74]
	strh r6, [r5]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x78]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081B6DC4 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _081B6DC8 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081B6DCC @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081B6DD0 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa4]
	ldr r0, [r0]
	str r0, [sp, #0x7c]
	ldr r1, [sp, #0xc8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x7c]
	strh r1, [r6]
	ldr r6, [sp, #0xc8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x7c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0x90]
	ldr r2, [sp, #0x6c]
	str r2, [sp, #0xb8]
	ldr r3, [sp, #0x70]
	str r3, [sp, #0xbc]
	ldr r4, [sp, #0x74]
	str r4, [sp, #0xac]
	mov r5, sl
	cmp r5, #0
	blt _081B6DB8
	cmp r1, #0
	blt _081B6DB8
	ldr r0, _081B6DD4 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081B6DB8
	ldr r0, _081B6DD8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6DDC
_081B6DB8:
	movs r4, #0
	b _081B6DEC
	.align 2, 0
_081B6DBC: .4byte 0x0000046D
_081B6DC0: .4byte 0x0000046B
_081B6DC4: .4byte 0x00000469
_081B6DC8: .4byte 0x0000046A
_081B6DCC: .4byte 0x00000484
_081B6DD0: .4byte 0x0000046C
_081B6DD4: .4byte 0x030046A8
_081B6DD8: .4byte 0x030046AC
_081B6DDC:
	ldr r0, _081B6DFC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, sl
	adds r4, r0, r6
_081B6DEC:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B6E00
	adds r0, #4
	b _081B6E0C
	.align 2, 0
_081B6DFC: .4byte 0x030046A4
_081B6E00:
	ldr r0, _081B6E20 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B6E0C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B6E24
	cmp r2, #2
	beq _081B6E2A
	b _081B6E30
	.align 2, 0
_081B6E20: .4byte 0x030046A4
_081B6E24:
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2, #4]
	b _081B6E2E
_081B6E2A:
	ldr r3, [sp, #0x7c]
	ldrb r0, [r3]
_081B6E2E:
	subs r1, r1, r0
_081B6E30:
	ldr r4, [sp, #0x7c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B6E5C
	cmp r1, #0
	blt _081B6E5C
	ldr r0, _081B6E60 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B6E5C
	ldr r0, _081B6E64 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B6E68
_081B6E5C:
	movs r4, #0
	b _081B6E76
	.align 2, 0
_081B6E60: .4byte 0x030046A8
_081B6E64: .4byte 0x030046AC
_081B6E68:
	ldr r0, _081B6E8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B6E76:
	ldr r6, [sp, #0xa4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B6E90
	adds r0, #4
	b _081B6E9C
	.align 2, 0
_081B6E8C: .4byte 0x030046A4
_081B6E90:
	ldr r0, _081B6EB0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B6E9C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B6EB4
	cmp r3, #2
	beq _081B6EB8
	b _081B6EBC
	.align 2, 0
_081B6EB0: .4byte 0x030046A4
_081B6EB4:
	ldrb r0, [r5, #4]
	b _081B6EBA
_081B6EB8:
	ldrb r0, [r5]
_081B6EBA:
	subs r2, r2, r0
_081B6EBC:
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081B6ECA:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x80]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa8]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081B6EF4 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	cmp r0, #0
	bne _081B6FD4
	movs r1, #4
	ldr r2, [sp, #0xc0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B6EF8
	movs r0, #1
	b _081B6EFA
	.align 2, 0
_081B6EF4: .4byte 0x00000482
_081B6EF8:
	movs r0, #0
_081B6EFA:
	ldr r3, _081B6FE4 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	cmp r0, #0
	bne _081B6FD4
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xcc]
	ldr r1, _081B6FE8 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081B6FEC @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081B6FF0 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _081B6FF4 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081B6FF8 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	ldr r6, _081B6FFC @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	ldr r1, _081B7000 @ =0x030046B8
	adds r2, r5, #0
_081B6F42:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081B7004 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081B7008 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081B6F66
	adds r3, #1
	cmp r3, #3
	ble _081B6F42
	adds r0, r5, #0
_081B6F66:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xbc]
	ldr r0, [r1]
	ldr r2, [sp, #0xcc]
	str r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xb4]
	strb r0, [r6]
	add r0, sp, #0x80
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xc4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0xb8]
	strb r0, [r6]
	ldr r0, [sp, #0xbc]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb0]
	strb r0, [r4]
_081B6FD4:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _081B70E6
	.align 2, 0
_081B6FE4: .4byte 0x00000482
_081B6FE8: .4byte 0x0000054F
_081B6FEC: .4byte 0x0000054C
_081B6FF0: .4byte 0x0000054E
_081B6FF4: .4byte 0x00000541
_081B6FF8: .4byte 0x000005BC
_081B6FFC: .4byte 0x00000542
_081B7000: .4byte 0x030046B8
_081B7004: .4byte 0x000003FF
_081B7008: .4byte 0x0203B400
_081B700C:
	add r6, sp, #0x20
	ldr r0, _081B704C @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081B7050
	adds r0, #4
	b _081B705C
	.align 2, 0
_081B704C: .4byte 0x030046A4
_081B7050:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B705C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081B7094 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B709C
	ldr r0, _081B7098 @ =0xFFFFFDFF
	ldr r6, [sp, #0xa8]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081B70C6
	.align 2, 0
_081B7094: .4byte 0x000004A4
_081B7098: .4byte 0xFFFFFDFF
_081B709C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B70BC
	cmp r0, #2
	beq _081B70B8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B70B8:
	movs r0, #1
	b _081B70C8
_081B70BC:
	ldr r0, _081B70DC @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081B70C6:
	movs r0, #0
_081B70C8:
	cmp r0, #0
	bne _081B70E4
_081B70CC:
	ldr r3, _081B70E0 @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081B70E6
	.align 2, 0
_081B70DC: .4byte 0xFFFFFDFF
_081B70E0: .4byte 0x000005C4
_081B70E4:
	movs r0, #1
_081B70E6:
	cmp r0, #0
	bne _081B716C
	ldr r4, _081B711C @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B7124
	ldr r0, _081B7120 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa8]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B714E
	.align 2, 0
_081B711C: .4byte 0x000004A4
_081B7120: .4byte 0xFFFFFDFF
_081B7124:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B7144
	cmp r0, #2
	beq _081B7140
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B7140:
	movs r0, #1
	b _081B7150
_081B7144:
	ldr r0, _081B7164 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa8]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B714E:
	movs r0, #0
_081B7150:
	cmp r0, #0
	bne _081B716C
_081B7154:
	ldr r4, _081B7168 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B71C4
	.align 2, 0
_081B7164: .4byte 0xFFFFFDFF
_081B7168: .4byte 0x000005C4
_081B716C:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081B71D4 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081B71D8 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081B71DC @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081B71E0 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081B71E4 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
_081B71C4:
	add sp, #0xd0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B71D4: .4byte 0x0000046D
_081B71D8: .4byte 0x0000046B
_081B71DC: .4byte 0x00000469
_081B71E0: .4byte 0x0000046A
_081B71E4: .4byte 0x00000484
