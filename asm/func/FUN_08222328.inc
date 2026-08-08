	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x78
	adds r7, r0, #0
	add r4, sp, #0x1c
	ldr r1, _082223F8 @ =0x0825289C
	adds r0, r4, #0
	movs r2, #0x12
	bl memcpy
	add r0, sp, #0x30
	mov sb, r0
	ldr r1, _082223FC @ =0x082528AE
	movs r2, #0x36
	bl memcpy
	add r6, sp, #0x68
	ldr r1, _08222400 @ =0x082528E4
	adds r0, r6, #0
	movs r2, #0xe
	bl memcpy
	movs r1, #1
	mov r8, r1
	ldr r2, [r7, #0x40]
	adds r1, r2, #0
	mov r0, r8
	ands r1, r0
	mov sl, r4
	cmp r1, #0
	beq _0822236E
	movs r1, #1
_0822236E:
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r7, #0x40]
	cmp r1, #0
	beq _082223DC
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r5, #0xb
	ldr r1, [r7, #0x38]
	movs r0, #2
	movs r2, #0xb
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	str r5, [r7, #0x58]
	bl FUN_0823d4e8
	bl FUN_0823d550
_082223DC:
	ldr r5, [r7, #0x50]
	cmp r5, #4
	bne _082223E4
	b _08222804
_082223E4:
	cmp r5, #4
	bgt _08222412
	cmp r5, #1
	beq _0822245C
	cmp r5, #1
	bgt _08222404
	cmp r5, #0
	beq _0822242C
	b _0822299C
	.align 2, 0
_082223F8: .4byte 0x0825289C
_082223FC: .4byte 0x082528AE
_08222400: .4byte 0x082528E4
_08222404:
	cmp r5, #2
	bne _0822240A
	b _08222628
_0822240A:
	cmp r5, #3
	bne _08222410
	b _08222778
_08222410:
	b _0822299C
_08222412:
	cmp r5, #6
	bne _08222418
	b _0822288E
_08222418:
	cmp r5, #6
	bge _0822241E
	b _08222868
_0822241E:
	cmp r5, #7
	bne _08222424
	b _08222904
_08222424:
	cmp r5, #0x63
	bne _0822242A
	b _0822293C
_0822242A:
	b _0822299C
_0822242C:
	movs r4, #2
	ldr r1, [r7, #0x40]
	adds r0, r1, #0
	ands r0, r4
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x40]
	adds r0, r7, #0
	adds r0, #0x5c
	ldr r3, _08222458 @ =0x0000FFFF
	movs r1, #0
	movs r2, #0x3c
	bl FUN_0821b21c
	cmp r0, #0
	bne _08222450
	b _0822299C
_08222450:
	mov r1, r8
	str r1, [r7, #0x50]
	str r5, [r7, #0x54]
	b _0822292E
	.align 2, 0
_08222458: .4byte 0x0000FFFF
_0822245C:
	movs r2, #2
	ldr r1, [r7, #0x40]
	ands r2, r1
	cmp r2, #0
	beq _08222468
	movs r2, #1
_08222468:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x40]
	cmp r2, #0
	beq _0822247E
	movs r0, #0xde
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	str r0, [r1]
_0822247E:
	add r2, sp, #4
	adds r1, r2, #0
	movs r0, #0x3a
	strb r0, [r1, #5]
	strb r0, [r2, #2]
	ldr r0, [r7, #0x54]
	cmp r0, #0x3b
	bgt _082224D4
	ldr r6, _082224C8 @ =0x0203B400
	ldr r4, _082224CC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _082224D0 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	add r1, sp, #4
	adds r0, #0x30
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	add r1, sp, #4
	adds r0, #0x30
	b _082224E4
	.align 2, 0
_082224C8: .4byte 0x0203B400
_082224CC: .4byte 0x030046B8
_082224D0: .4byte 0x000003FF
_082224D4:
	add r1, sp, #4
	adds r0, r7, #0
	adds r0, #0x64
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x65
	ldrb r0, [r0]
_082224E4:
	strb r0, [r1, #1]
	ldr r0, [r7, #0x54]
	cmp r0, #0x68
	bgt _08222534
	ldr r6, _08222528 @ =0x0203B400
	ldr r4, _0822252C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _08222530 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	add r1, sp, #4
	adds r0, #0x30
	strb r0, [r1, #3]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	add r1, sp, #4
	adds r0, #0x30
	b _08222544
	.align 2, 0
_08222528: .4byte 0x0203B400
_0822252C: .4byte 0x030046B8
_08222530: .4byte 0x000003FF
_08222534:
	add r1, sp, #4
	adds r0, r7, #0
	adds r0, #0x67
	ldrb r0, [r0]
	strb r0, [r1, #3]
	adds r0, r7, #0
	adds r0, #0x68
	ldrb r0, [r0]
_08222544:
	strb r0, [r1, #4]
	ldr r0, [r7, #0x54]
	cmp r0, #0x95
	bgt _082225A8
	ldr r6, _08222598 @ =0x0203B400
	ldr r4, _0822259C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _082225A0 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	add r1, sp, #4
	adds r0, #0x30
	strb r0, [r1, #6]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	add r1, sp, #4
	adds r0, #0x30
	strb r0, [r1, #7]
	ldr r0, [r7, #0x54]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _082225D0
	ldr r0, _082225A4 @ =0x00000273
	bl PlaySound_082406e0
	b _082225D0
	.align 2, 0
_08222598: .4byte 0x0203B400
_0822259C: .4byte 0x030046B8
_082225A0: .4byte 0x000003FF
_082225A4: .4byte 0x00000273
_082225A8:
	add r1, sp, #4
	adds r0, r7, #0
	adds r0, #0x6a
	ldrb r0, [r0]
	strb r0, [r1, #6]
	adds r0, r7, #0
	adds r0, #0x6b
	ldrb r0, [r0]
	strb r0, [r1, #7]
	movs r1, #0xde
	lsls r1, r1, #2
	adds r4, r7, r1
	ldr r0, [r4]
	cmp r0, #0
	bne _082225D0
	ldr r0, _08222620 @ =0x00000167
	bl PlaySound_082406e0
	movs r0, #1
	str r0, [r4]
_082225D0:
	add r0, sp, #4
	movs r5, #0
	strb r5, [r0, #8]
	movs r0, #0x14
	movs r1, #4
	movs r2, #8
	movs r3, #2
	bl FUN_0821b28c
	movs r0, #0x14
	movs r1, #4
	add r2, sp, #4
	bl FUN_0821b2b4
	ldr r0, [r7, #0x54]
	cmp r0, #0xd2
	bgt _08222600
	ldr r0, _08222624 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08222600
	b _0822299C
_08222600:
	movs r0, #0xde
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	cmp r0, #0
	bne _08222616
	ldr r0, _08222620 @ =0x00000167
	bl PlaySound_082406e0
	movs r0, #1
	str r0, [r4]
_08222616:
	movs r1, #2
	str r1, [r7, #0x50]
	str r5, [r7, #0x54]
	b _082228F8
	.align 2, 0
_08222620: .4byte 0x00000167
_08222624: .4byte 0x030044E0
_08222628:
	ldr r2, [r7, #0x40]
	adds r1, r2, #0
	ands r1, r5
	cmp r1, #0
	beq _08222634
	movs r1, #1
_08222634:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r7, #0x40]
	cmp r1, #0
	beq _08222694
	movs r0, #0x14
	movs r1, #4
	movs r2, #8
	movs r3, #2
	bl FUN_0821b28c
	adds r2, r7, #0
	adds r2, #0x64
	movs r0, #0x14
	movs r1, #4
	bl FUN_0821b2b4
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r2, #0
	str r2, [r0]
	add r4, sp, #0x10
	movs r0, #0x20
	strb r0, [r4]
	strb r0, [r4, #1]
	movs r1, #0x2c
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	strb r0, [r4, #4]
	strb r0, [r4, #5]
	strb r1, [r4, #6]
	strb r0, [r4, #7]
	strb r0, [r4, #8]
	strb r0, [r4, #9]
	strb r2, [r4, #0xa]
	movs r0, #0x12
	movs r1, #7
	movs r2, #0xa
	movs r3, #2
	bl FUN_0821b28c
	movs r0, #0x12
	movs r1, #7
	adds r2, r4, #0
	bl FUN_0821b2b4
_08222694:
	ldr r0, [r7, #0x54]
	cmp r0, #0x3b
	bgt _08222704
	movs r0, #0x18
	adds r0, r0, r7
	mov r8, r0
	ldr r6, _082226F4 @ =0x030046B8
	adds r4, r7, #0
	adds r4, #0x78
	movs r5, #7
_082226A8:
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _082226F8 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _082226FC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl FUN_0822f3cc
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _082226A8
	ldr r0, [r7, #0x54]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08222746
	ldr r0, _08222700 @ =0x00000273
	bl PlaySound_082406e0
	b _08222746
	.align 2, 0
_082226F4: .4byte 0x030046B8
_082226F8: .4byte 0x000003FF
_082226FC: .4byte 0x0203B400
_08222700: .4byte 0x00000273
_08222704:
	adds r0, r7, #0
	bl FUN_0822230c
	movs r0, #0x12
	movs r1, #7
	movs r2, #0xa
	movs r3, #2
	bl FUN_0821b28c
	adds r2, r7, #0
	adds r2, #0x6d
	movs r0, #0x12
	movs r1, #7
	bl FUN_0821b2b4
	movs r0, #0xde
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	cmp r0, #0
	bne _08222738
	ldr r0, _08222770 @ =0x00000167
	bl PlaySound_082406e0
	movs r0, #1
	str r0, [r4]
_08222738:
	movs r0, #3
	str r0, [r7, #0x50]
	movs r0, #0
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x40]
	orrs r0, r5
	str r0, [r7, #0x40]
_08222746:
	ldr r0, _08222774 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08222756
	b _0822299C
_08222756:
	movs r1, #0xde
	lsls r1, r1, #2
	adds r4, r7, r1
	ldr r0, [r4]
	cmp r0, #0
	bne _0822276A
	ldr r0, _08222770 @ =0x00000167
	bl PlaySound_082406e0
	str r5, [r4]
_0822276A:
	movs r0, #3
	b _082228F0
	.align 2, 0
_08222770: .4byte 0x00000167
_08222774: .4byte 0x030044E0
_08222778:
	movs r4, #2
	ldr r2, [r7, #0x40]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _08222786
	movs r1, #1
_08222786:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r7, #0x40]
	cmp r1, #0
	beq _082227B0
	adds r0, r7, #0
	bl FUN_0822230c
	movs r0, #0x12
	movs r1, #7
	movs r2, #0xa
	movs r3, #2
	bl FUN_0821b28c
	adds r2, r7, #0
	adds r2, #0x6d
	movs r0, #0x12
	movs r1, #7
	bl FUN_0821b2b4
_082227B0:
	ldr r0, [r7, #0x54]
	cmp r0, #0x3c
	bgt _082227C4
	ldr r0, _082227F8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _082227C4
	b _0822299C
_082227C4:
	movs r0, #0x17
	movs r1, #0xa
	movs r2, #5
	movs r3, #2
	bl FUN_0821b28c
	ldr r0, _082227FC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #1
	add r2, sl
	movs r0, #0x17
	movs r1, #0xa
	bl FUN_0821b2b4
	ldr r0, _08222800 @ =0x00000167
	bl PlaySound_082406e0
	movs r0, #4
	b _08222928
	.align 2, 0
_082227F8: .4byte 0x030044E0
_082227FC: .4byte 0x030046A0
_08222800: .4byte 0x00000167
_08222804:
	movs r4, #2
	ldr r1, [r7, #0x40]
	adds r0, r1, #0
	ands r0, r4
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x40]
	ldr r0, [r7, #0x54]
	cmp r0, #0x3c
	bgt _08222828
	ldr r0, _08222858 @ =0x030044E0
	ldrh r1, [r0, #2]
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	bne _08222828
	b _0822299C
_08222828:
	movs r0, #0x14
	movs r1, #0xd
	movs r2, #8
	movs r3, #2
	bl FUN_0821b28c
	ldr r0, _0822285C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08222860 @ =0x000002FA
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r2, r0, #3
	adds r2, r2, r0
	add r2, sb
	movs r0, #0x14
	movs r1, #0xd
	bl FUN_0821b2b4
	ldr r0, _08222864 @ =0x00000167
	bl PlaySound_082406e0
	movs r0, #5
	b _08222928
	.align 2, 0
_08222858: .4byte 0x030044E0
_0822285C: .4byte 0x030046A0
_08222860: .4byte 0x000002FA
_08222864: .4byte 0x00000167
_08222868:
	movs r4, #2
	ldr r1, [r7, #0x40]
	adds r0, r1, #0
	ands r0, r4
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x40]
	ldr r0, [r7, #0x54]
	cmp r0, #0x3c
	bgt _08222880
	b _0822299C
_08222880:
	movs r0, #9
	movs r1, #0x10
	adds r2, r6, #0
	bl FUN_0821b2b4
	movs r0, #6
	b _08222928
_0822288E:
	movs r0, #2
	ldr r1, [r7, #0x40]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x40]
	ldr r0, [r7, #0x54]
	movs r1, #0x1e
	bl Mod
	cmp r0, #0
	bne _082228DC
	ldr r0, [r7, #0x54]
	movs r1, #0x1e
	bl Div
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _082228C6
	movs r0, #9
	movs r1, #0x10
	movs r2, #0xf
	movs r3, #2
	bl FUN_0821b28c
	b _082228DC
_082228C6:
	movs r0, #9
	movs r1, #0x10
	movs r2, #0xf
	movs r3, #2
	bl FUN_0821b28c
	movs r0, #9
	movs r1, #0x10
	adds r2, r6, #0
	bl FUN_0821b2b4
_082228DC:
	ldr r0, _08222900 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0822299C
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #7
_082228F0:
	str r0, [r7, #0x50]
	movs r0, #0
	str r0, [r7, #0x54]
	movs r1, #2
_082228F8:
	ldr r0, [r7, #0x40]
	orrs r0, r1
	str r0, [r7, #0x40]
	b _0822299C
	.align 2, 0
_08222900: .4byte 0x030044E0
_08222904:
	movs r4, #2
	ldr r1, [r7, #0x40]
	adds r0, r1, #0
	ands r0, r4
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x40]
	adds r0, r7, #0
	adds r0, #0x5c
	ldr r3, _08222938 @ =0x0000FFFF
	movs r1, #1
	movs r2, #0x3c
	bl FUN_0821b21c
	cmp r0, #0
	beq _0822299C
	movs r0, #0x63
_08222928:
	str r0, [r7, #0x50]
	movs r0, #0
	str r0, [r7, #0x54]
_0822292E:
	ldr r0, [r7, #0x40]
	orrs r0, r4
	str r0, [r7, #0x40]
	b _0822299C
	.align 2, 0
_08222938: .4byte 0x0000FFFF
_0822293C:
	movs r0, #2
	ldr r1, [r7, #0x40]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x40]
	ldr r0, [r7, #0x54]
	cmp r0, #0x1e
	ble _0822299C
	ldr r0, [r7, #0x44]
	movs r1, #0
	bl FUN_082318ac
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	adds r0, r7, #0
	bl KillEntity
_0822299C:
	add sp, #0x78
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
