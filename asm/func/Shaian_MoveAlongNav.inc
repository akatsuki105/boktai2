	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r4, r1, #0
	mov r8, r2
	mov sl, r3
	ldr r5, [sp, #0x28]
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r6, [r0]
	ldrh r0, [r4, #0x1c]
	mov r2, sb
	ldrh r1, [r2, #8]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r4, #0x20]
	mov r3, sb
	ldrh r1, [r3, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	movs r7, #0xc
	ldrsh r1, [r4, r7]
	movs r7, #8
	ldrsh r0, [r3, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _0817D24C
	rsbs r1, r1, #0
_0817D24C:
	cmp r1, r8
	bhi _0817D268
	movs r0, #0x10
	ldrsh r1, [r4, r0]
	mov r3, sb
	movs r4, #0xc
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _0817D262
	rsbs r1, r1, #0
_0817D262:
	cmp r1, sl
	bhi _0817D268
	b _0817D6B6
_0817D268:
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	mov r7, ip
	lsls r0, r7, #0x10
	cmp r2, #0
	bne _0817D27A
	cmp r0, #0
	bne _0817D27A
	b _0817D6C0
_0817D27A:
	asrs r1, r0, #0x10
	adds r0, r2, #0
	bl ArcTan2_8
	mov r1, sb
	strb r0, [r1, #5]
	ldr r2, _0817D2A4 @ =gSineTable
	ldrb r0, [r1, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0817D2A8
	asrs r0, r0, #0x10
	b _0817D2AE
	.align 2, 0
_0817D2A4: .4byte gSineTable
_0817D2A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0817D2AE:
	adds r3, r0, #0
	ldr r1, _0817D2CC @ =gSineTable
	mov r4, sb
	ldrb r2, [r4, #5]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r5, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _0817D2D0
	asrs r0, r0, #0x10
	b _0817D2D6
	.align 2, 0
_0817D2CC: .4byte gSineTable
_0817D2D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0817D2D6:
	mov r2, sb
	movs r4, #0x10
	ldrsh r1, [r2, r4]
	adds r2, r3, #0
	cmp r3, #0
	bge _0817D2E4
	rsbs r2, r3, #0
_0817D2E4:
	cmp r2, #0xa
	ble _0817D2EA
	adds r1, r1, r3
_0817D2EA:
	mov r7, sb
	strh r1, [r7, #0x10]
	movs r2, #0x14
	ldrsh r1, [r7, r2]
	adds r2, r0, #0
	cmp r0, #0
	bge _0817D2FA
	rsbs r2, r0, #0
_0817D2FA:
	cmp r2, #0xa
	ble _0817D300
	adds r1, r1, r0
_0817D300:
	mov r3, sb
	strh r1, [r3, #0x14]
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r4, _0817D318 @ =0x00000898
	adds r0, r6, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817D31C
	movs r0, #1
	b _0817D31E
	.align 2, 0
_0817D318: .4byte 0x00000898
_0817D31C:
	movs r0, #0
_0817D31E:
	cmp r0, #0
	bne _0817D324
	b _0817D6C0
_0817D324:
	mov r4, sp
	mov r3, sb
	adds r3, #8
	ldr r7, _0817D368 @ =0x00000854
	adds r2, r6, r7
	ldrh r0, [r2]
	mov r6, sb
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r5, #0
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r5, r3, #0
	cmp r0, #1
	bne _0817D35C
	b _0817D4FC
_0817D35C:
	cmp r0, #1
	bgt _0817D36C
	cmp r0, #0
	beq _0817D378
	b _0817D6C0
	.align 2, 0
_0817D368: .4byte 0x00000854
_0817D36C:
	cmp r0, #2
	beq _0817D378
	cmp r0, #3
	bne _0817D376
	b _0817D4FC
_0817D376:
	b _0817D6C0
_0817D378:
	mov r0, sp
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	bge _0817D384
	rsbs r0, r0, #0
_0817D384:
	cmp r0, r8
	blo _0817D38A
	b _0817D6C0
_0817D38A:
	mov r0, sb
	ldrb r0, [r0, #5]
	mov sl, r0
	mov r0, sp
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r0, #0
	bl ArcTan2_8
	mov r3, sb
	strb r0, [r3, #5]
	ldr r4, _0817D3B8 @ =0x00000256
	add r4, sb
	ldrh r6, [r4]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817D3BC
	adds r0, #4
	b _0817D3C8
	.align 2, 0
_0817D3B8: .4byte 0x00000256
_0817D3BC:
	ldr r0, _0817D3DC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817D3C8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817D3E0
	cmp r3, #2
	beq _0817D3E4
	b _0817D3E8
	.align 2, 0
_0817D3DC: .4byte 0x030046A4
_0817D3E0:
	ldrb r0, [r5, #4]
	b _0817D3E6
_0817D3E4:
	ldrb r0, [r5]
_0817D3E6:
	subs r2, r2, r0
_0817D3E8:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817D3FA
	adds r0, #4
	b _0817D406
_0817D3FA:
	ldr r0, _0817D418 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817D406:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0817D41C
	asrs r0, r0, #6
	b _0817D422
	.align 2, 0
_0817D418: .4byte 0x030046A4
_0817D41C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0817D422:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0817D460
	cmp r1, #1
	bgt _0817D434
	cmp r1, #0
	beq _0817D43E
	b _0817D6A4
_0817D434:
	cmp r1, #2
	beq _0817D49C
	cmp r1, #3
	beq _0817D4BE
	b _0817D6A4
_0817D43E:
	adds r4, r6, #1
	movs r5, #0
_0817D442:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817D456
	b _0817D5E0
_0817D456:
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0817D442
	b _0817D5E0
_0817D460:
	ldr r0, _0817D498 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	movs r5, #0
_0817D46E:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817D482
	b _0817D67C
_0817D482:
	ldr r0, _0817D498 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r4, r4, r1
	adds r5, #1
	cmp r5, #1
	blt _0817D46E
	subs r1, r4, r1
	b _0817D6A6
	.align 2, 0
_0817D498: .4byte 0x030046A4
_0817D49C:
	subs r4, r6, #1
	movs r5, #0
_0817D4A0:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817D4B4
	b _0817D63E
_0817D4B4:
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0817D4A0
	b _0817D63E
_0817D4BE:
	ldr r0, _0817D4F8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r4, r6, r0
	movs r5, #0
_0817D4CC:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817D4E0
	b _0817D690
_0817D4E0:
	ldr r0, _0817D4F8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	subs r4, r4, r1
	adds r5, #1
	cmp r5, #1
	blt _0817D4CC
	adds r1, r4, r1
	b _0817D6A6
	.align 2, 0
_0817D4F8: .4byte 0x030046A4
_0817D4FC:
	mov r0, sp
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _0817D508
	rsbs r0, r0, #0
_0817D508:
	cmp r0, sl
	blo _0817D50E
	b _0817D6C0
_0817D50E:
	mov r2, sb
	ldrb r2, [r2, #5]
	mov sl, r2
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0
	bl ArcTan2_8
	mov r4, sb
	strb r0, [r4, #5]
	ldr r4, _0817D53C @ =0x00000256
	add r4, sb
	ldrh r6, [r4]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817D540
	adds r0, #4
	b _0817D54C
	.align 2, 0
_0817D53C: .4byte 0x00000256
_0817D540:
	ldr r0, _0817D560 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817D54C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0817D564
	cmp r3, #2
	beq _0817D568
	b _0817D56C
	.align 2, 0
_0817D560: .4byte 0x030046A4
_0817D564:
	ldrb r0, [r5, #4]
	b _0817D56A
_0817D568:
	ldrb r0, [r5]
_0817D56A:
	subs r2, r2, r0
_0817D56C:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817D57E
	adds r0, #4
	b _0817D58A
_0817D57E:
	ldr r0, _0817D59C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0817D58A:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0817D5A0
	asrs r0, r0, #6
	b _0817D5A6
	.align 2, 0
_0817D59C: .4byte 0x030046A4
_0817D5A0:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0817D5A6:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0817D5E4
	cmp r1, #1
	bgt _0817D5B8
	cmp r1, #0
	beq _0817D5C2
	b _0817D6A4
_0817D5B8:
	cmp r1, #2
	beq _0817D620
	cmp r1, #3
	beq _0817D642
	b _0817D6A4
_0817D5C2:
	adds r4, r6, #1
	movs r5, #0
_0817D5C6:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D5E0
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0817D5C6
_0817D5E0:
	subs r1, r4, #1
	b _0817D6A6
_0817D5E4:
	ldr r0, _0817D61C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	movs r5, #0
_0817D5F2:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D67C
	ldr r0, _0817D61C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r4, r4, r1
	adds r5, #1
	cmp r5, #1
	blt _0817D5F2
	subs r1, r4, r1
	b _0817D6A6
	.align 2, 0
_0817D61C: .4byte 0x030046A4
_0817D620:
	subs r4, r6, #1
	movs r5, #0
_0817D624:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D63E
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0817D624
_0817D63E:
	adds r1, r4, #1
	b _0817D6A6
_0817D642:
	ldr r0, _0817D678 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r4, r6, r0
	movs r5, #0
_0817D650:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817D690
	ldr r0, _0817D678 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	subs r4, r4, r1
	adds r5, #1
	cmp r5, #1
	blt _0817D650
	adds r1, r4, r1
	b _0817D6A6
	.align 2, 0
_0817D678: .4byte 0x030046A4
_0817D67C:
	ldr r0, _0817D68C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r1, r4, r0
	b _0817D6A6
	.align 2, 0
_0817D68C: .4byte 0x030046A4
_0817D690:
	ldr r0, _0817D6A0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r1, r4, r0
	b _0817D6A6
	.align 2, 0
_0817D6A0: .4byte 0x030046A4
_0817D6A4:
	ldrh r1, [r4]
_0817D6A6:
	mov r0, sl
	mov r7, sb
	strb r0, [r7, #5]
	ldr r0, _0817D6BC @ =0x00000256
	add r0, sb
	ldrh r0, [r0]
	cmp r1, r0
	beq _0817D6C0
_0817D6B6:
	movs r0, #2
	b _0817D6C2
	.align 2, 0
_0817D6BC: .4byte 0x00000256
_0817D6C0:
	movs r0, #0
_0817D6C2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
