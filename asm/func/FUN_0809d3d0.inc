	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xed
	lsls r0, r0, #3
	adds r5, r6, r0
	adds r1, r6, #0
	adds r1, #0x28
	adds r0, r5, #0
	bl MainSprite_AdvanceAnim
	ldr r2, _0809D3FC @ =0x00000F74
	adds r1, r6, r2
	ldr r0, [r1]
	cmp r0, #0
	beq _0809D400
	subs r0, #1
	str r0, [r1]
	b _0809D792
	.align 2, 0
_0809D3FC: .4byte 0x00000F74
_0809D400:
	ldr r0, _0809D458 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809D468
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D418
	b _0809D574
_0809D418:
	ldr r3, _0809D45C @ =0x00000E2B
	adds r4, r6, r3
	ldrb r0, [r4]
	bl FUN_0809cf98
	cmp r0, #0
	bne _0809D428
	b _0809D574
_0809D428:
	ldrb r2, [r4]
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bne _0809D43A
	b _0809D574
_0809D43A:
	strb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r2, _0809D460 @ =0x00000F4C
	adds r1, r6, r2
	bl FUN_08242b14
	adds r0, r6, #0
	bl FUN_0809d270
	ldr r1, _0809D464 @ =FUN_0809d7a4
	adds r0, r6, #0
	bl FUN_0809ce90
	b _0809D792
	.align 2, 0
_0809D458: .4byte 0x030044E0
_0809D45C: .4byte 0x00000E2B
_0809D460: .4byte 0x00000F4C
_0809D464: .4byte FUN_0809d7a4
_0809D468:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809D55C
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	movs r3, #0xb0
	adds r3, r3, r6
	mov r8, r3
	cmp r0, #2
	beq _0809D51C
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0809D51C
	ldr r2, _0809D54C @ =0x00000F4C
	adds r4, r6, r2
	adds r1, r0, #0
	mov ip, r1
	ldr r0, _0809D550 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _0809D51C
	movs r3, #0xae
	lsls r3, r3, #1
	adds r5, r2, r3
	cmp r5, #0
	beq _0809D51C
	ldrb r0, [r4]
	strb r0, [r5, #0x1c]
	ldrb r0, [r4, #1]
	strb r0, [r5, #0x1d]
	ldrb r0, [r4, #2]
	strb r0, [r5, #0x1e]
	ldrb r0, [r4, #3]
	strb r0, [r5, #0x1f]
	ldrb r1, [r4, #4]
	adds r3, #0x20
	adds r0, r2, r3
	strb r1, [r0]
	ldrb r0, [r4, #5]
	adds r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	ldrh r0, [r4, #6]
	strh r0, [r5, #0x22]
	ldrh r0, [r4, #8]
	strh r0, [r5, #0x24]
	ldrh r0, [r4, #0xa]
	strh r0, [r5, #0x26]
	movs r3, #0
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r2, r0
	ldr r1, _0809D554 @ =0x00000F58
	adds r2, r6, r1
_0809D4E6:
	adds r0, r7, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #0xb
	ble _0809D4E6
	adds r2, r5, #0
	adds r2, #0x34
	adds r1, r4, #0
	adds r1, #0x18
	movs r3, #2
_0809D4FE:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r0, [r1, #1]
	strb r0, [r2, #1]
	ldrb r0, [r1, #2]
	strb r0, [r2, #2]
	ldrb r0, [r1, #3]
	strb r0, [r2, #3]
	adds r2, #4
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _0809D4FE
	mov r2, ip
	strb r2, [r5, #0x17]
_0809D51C:
	adds r0, r6, #0
	bl FUN_0809d230
	movs r3, #1
	mov r1, r8
	movs r2, #0x23
_0809D528:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809D528
	ldr r3, _0809D558 @ =0x00000F84
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r0, #0
	bne _0809D542
	b _0809D762
_0809D542:
	movs r1, #0
	bl Script_ExecById
	b _0809D762
	.align 2, 0
_0809D54C: .4byte 0x00000F4C
_0809D550: .4byte 0x03002C68
_0809D554: .4byte 0x00000F58
_0809D558: .4byte 0x00000F84
_0809D55C:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0809D566
	b _0809D770
_0809D566:
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r5, r6, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _0809D57E
_0809D574:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0809D792
_0809D57E:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, [r6, #0x18]
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D634
	ldr r2, _0809D628 @ =0x00000F4C
	adds r4, r6, r2
	ldrb r1, [r1, #0x17]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov ip, r1
	ldr r0, _0809D62C @ =0x03002C68
	ldr r2, [r0]
	mov sb, r0
	movs r3, #0xb0
	adds r3, r3, r6
	mov r8, r3
	cmp r2, #0
	bne _0809D5AE
	b _0809D6CA
_0809D5AE:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r5, r2, r0
	cmp r5, #0
	bne _0809D5BA
	b _0809D6CA
_0809D5BA:
	ldrb r0, [r4]
	strb r0, [r5, #0x1c]
	ldrb r0, [r4, #1]
	strb r0, [r5, #0x1d]
	ldrb r0, [r4, #2]
	strb r0, [r5, #0x1e]
	ldrb r0, [r4, #3]
	strb r0, [r5, #0x1f]
	ldrb r1, [r4, #4]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	ldrb r0, [r4, #5]
	adds r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	ldrh r0, [r4, #6]
	strh r0, [r5, #0x22]
	ldrh r0, [r4, #8]
	strh r0, [r5, #0x24]
	ldrh r0, [r4, #0xa]
	strh r0, [r5, #0x26]
	movs r3, #0
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r2, r0
	ldr r1, _0809D630 @ =0x00000F58
	adds r2, r6, r1
_0809D5F4:
	adds r0, r7, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #0xb
	ble _0809D5F4
	adds r2, r5, #0
	adds r2, #0x34
	adds r1, r4, #0
	adds r1, #0x18
	movs r3, #2
_0809D60C:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r0, [r1, #1]
	strb r0, [r2, #1]
	ldrb r0, [r1, #2]
	strb r0, [r2, #2]
	ldrb r0, [r1, #3]
	strb r0, [r2, #3]
	adds r2, #4
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _0809D60C
	b _0809D6C6
	.align 2, 0
_0809D628: .4byte 0x00000F4C
_0809D62C: .4byte 0x03002C68
_0809D630: .4byte 0x00000F58
_0809D634:
	ldr r3, _0809D6E0 @ =0x00000F4C
	adds r4, r6, r3
	ldrb r5, [r5]
	lsls r5, r5, #0x18
	asrs r5, r5, #0x18
	mov ip, r5
	ldr r0, _0809D6E4 @ =0x03002C68
	ldr r2, [r0]
	mov sb, r0
	movs r0, #0xb0
	adds r0, r0, r6
	mov r8, r0
	cmp r2, #0
	beq _0809D6CA
	movs r1, #0xae
	lsls r1, r1, #1
	adds r5, r2, r1
	cmp r5, #0
	beq _0809D6CA
	ldrb r0, [r4]
	strb r0, [r5, #0x1c]
	ldrb r0, [r4, #1]
	strb r0, [r5, #0x1d]
	ldrb r0, [r4, #2]
	strb r0, [r5, #0x1e]
	ldrb r0, [r4, #3]
	strb r0, [r5, #0x1f]
	ldrb r1, [r4, #4]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	ldrb r0, [r4, #5]
	adds r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	ldrh r0, [r4, #6]
	strh r0, [r5, #0x22]
	ldrh r0, [r4, #8]
	strh r0, [r5, #0x24]
	ldrh r0, [r4, #0xa]
	strh r0, [r5, #0x26]
	movs r3, #0
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r2, r0
	ldr r1, _0809D6E8 @ =0x00000F58
	adds r2, r6, r1
_0809D694:
	adds r0, r7, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #0xb
	ble _0809D694
	adds r2, r5, #0
	adds r2, #0x34
	adds r1, r4, #0
	adds r1, #0x18
	movs r3, #2
_0809D6AC:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r0, [r1, #1]
	strb r0, [r2, #1]
	ldrb r0, [r1, #2]
	strb r0, [r2, #2]
	ldrb r0, [r1, #3]
	strb r0, [r2, #3]
	adds r2, #4
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _0809D6AC
_0809D6C6:
	mov r2, ip
	strb r2, [r5, #0x17]
_0809D6CA:
	mov r3, sb
	ldr r0, [r3]
	cmp r0, #0
	beq _0809D6EC
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809D6EC
	movs r0, #1
	b _0809D6EE
	.align 2, 0
_0809D6E0: .4byte 0x00000F4C
_0809D6E4: .4byte 0x03002C68
_0809D6E8: .4byte 0x00000F58
_0809D6EC:
	movs r0, #0
_0809D6EE:
	cmp r0, #0
	beq _0809D71A
	bl FUN_081df8d4
	adds r0, r6, #0
	bl FUN_0809d230
	bl FUN_08049fa8
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	b _0809D74E
_0809D71A:
	movs r0, #3
	bl FUN_081df95c
	adds r0, r6, #0
	bl FUN_0809d230
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, _0809D76C @ =0x00000F88
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0809D74E
	movs r1, #0
	bl Script_ExecById
_0809D74E:
	movs r3, #1
	mov r1, r8
	movs r2, #0x23
_0809D754:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809D754
_0809D762:
	adds r0, r6, #0
	bl KillEntity
	b _0809D792
	.align 2, 0
_0809D76C: .4byte 0x00000F88
_0809D770:
	ldr r2, _0809D7A0 @ =0x00000E28
	adds r4, r6, r2
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _0809D792
	adds r0, r6, #0
	bl FUN_0809cea8
	adds r0, r6, #0
	bl FUN_0809d00c
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080b9fc4
_0809D792:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809D7A0: .4byte 0x00000E28
