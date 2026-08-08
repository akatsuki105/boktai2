	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x19
	beq _0806A396
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0
	bl FUN_08060b84
	movs r5, #0xba
	lsls r5, r5, #2
	adds r2, r4, r5
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806A374
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806A370 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r5, #1
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _0806A384
	.align 2, 0
_0806A370: .4byte 0x000002E6
_0806A374:
	lsrs r1, r1, #0x19
	ldr r2, _0806A3AC @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _0806A3B0 @ =0x000002E7
	adds r0, r4, r5
	strb r2, [r0]
_0806A384:
	ldr r0, _0806A3B4 @ =0x000003D6
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _0806A396
	bl PlaySound_082406e0
	movs r0, #0
	strh r0, [r5]
_0806A396:
	ldr r1, _0806A3B8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _0806A3A2
	b _0806A61C
_0806A3A2:
	lsls r0, r0, #2
	ldr r1, _0806A3BC @ =_0806A3C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806A3AC: .4byte 0x000002E6
_0806A3B0: .4byte 0x000002E7
_0806A3B4: .4byte 0x000003D6
_0806A3B8: .4byte 0x0000037D
_0806A3BC: .4byte _0806A3C0
_0806A3C0: @ jump table
	.4byte _0806A3D4 @ case 0
	.4byte _0806A410 @ case 1
	.4byte _0806A52C @ case 2
	.4byte _0806A5C4 @ case 3
	.4byte _0806A5E8 @ case 4
_0806A3D4:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r5, _0806A40C @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _0806A400
	b _0806A61C
_0806A400:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	bl FUN_08060b84
	b _0806A61C
	.align 2, 0
_0806A40C: .4byte 0x0000037E
_0806A410:
	ldr r1, _0806A470 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806A424
	ldr r2, _0806A474 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
_0806A424:
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	movs r1, #0x2b
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806A478 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A47C
	asrs r0, r0, #0xc
	b _0806A482
	.align 2, 0
_0806A470: .4byte 0x0000037E
_0806A474: .4byte 0x000003F6
_0806A478: .4byte 0x085B0A08
_0806A47C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A482:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _0806A4A4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A4A8
	asrs r0, r0, #0xc
	b _0806A4AE
	.align 2, 0
_0806A4A4: .4byte 0x085B0A08
_0806A4A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A4AE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r1, _0806A4DC @ =0x0000037E
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #3
	bls _0806A4E8
	ldr r2, _0806A4E0 @ =0x000003F6
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	blt _0806A4E4
	subs r0, r2, r0
	b _0806A4E6
	.align 2, 0
_0806A4DC: .4byte 0x0000037E
_0806A4E0: .4byte 0x000003F6
_0806A4E4:
	movs r0, #0
_0806A4E6:
	strh r0, [r1]
_0806A4E8:
	ldr r5, _0806A524 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _0806A500
	b _0806A61C
_0806A500:
	ldr r2, _0806A528 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0806A50C
	b _0806A61C
_0806A50C:
	strh r0, [r1]
	movs r0, #0xaa
	lsls r0, r0, #2
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_08060b84
	b _0806A61C
	.align 2, 0
_0806A524: .4byte 0x0000037E
_0806A528: .4byte 0x000003F6
_0806A52C:
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806A560 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A564
	asrs r0, r0, #0xc
	b _0806A56A
	.align 2, 0
_0806A560: .4byte 0x085B0A08
_0806A564:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A56A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806A588
	asrs r0, r0, #0xc
	b _0806A58E
_0806A588:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806A58E:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806A61C
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #3
	bl FUN_08060b84
	b _0806A61C
_0806A5C4:
	ldr r5, _0806A5E4 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _0806A61C
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #4
	bl FUN_08060b84
	b _0806A61C
	.align 2, 0
_0806A5E4: .4byte 0x0000037E
_0806A5E8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806A61C
	ldr r2, _0806A624 @ =0x000003D2
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806A61C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806A624: .4byte 0x000003D2
