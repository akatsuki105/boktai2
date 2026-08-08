	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	movs r0, #0x70
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sl, r1
	movs r6, #0
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	str r0, [sp, #0xc]
	ldr r1, _08214B0C @ =0x000006BC
	adds r0, r7, r1
	ldrb r0, [r0]
	str r0, [sp, #0x10]
	adds r2, #5
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp, #0x14]
	adds r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	str r0, [sp, #0x18]
	adds r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
	movs r2, #1
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08214A78
	movs r2, #1
_08214A78:
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _08214AF2
	movs r0, #0
	bl FUN_0822b644
	str r6, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #2
	bl FUN_0822b644
	str r6, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #3
	bl FUN_0822b644
	str r6, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r4, #2
	ldr r1, [r7, #0x38]
	movs r0, #2
	movs r2, #2
	bl FUN_0822c398
	str r6, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	str r4, [r7, #0x64]
	adds r0, r7, #0
	bl FUN_08214274
	str r6, [r7, #0x68]
	mov r0, r8
	str r6, [r0, #4]
	ldr r3, _08214B10 @ =0x0000FFFF
	movs r1, #0
	movs r2, #1
	bl FUN_0821b21c
_08214AF2:
	ldr r1, [r7, #0x5c]
	cmp r1, #4
	bgt _08214BBC
	ldr r0, _08214B14 @ =0x030044E0
	ldrh r2, [r0, #2]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08214B2E
	cmp r1, #0
	bgt _08214B18
	movs r0, #4
	b _08214B1A
	.align 2, 0
_08214B0C: .4byte 0x000006BC
_08214B10: .4byte 0x0000FFFF
_08214B14: .4byte 0x030044E0
_08214B18:
	subs r0, r1, #1
_08214B1A:
	str r0, [r7, #0x5c]
	str r6, [r7, #0x60]
	movs r1, #2
	ldr r0, [r7, #0x44]
	orrs r0, r1
	str r0, [r7, #0x44]
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _08214B52
_08214B2E:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08214B52
	cmp r1, #3
	ble _08214B3E
	str r6, [r7, #0x5c]
	b _08214B42
_08214B3E:
	adds r0, r1, #1
	str r0, [r7, #0x5c]
_08214B42:
	str r6, [r7, #0x60]
	movs r1, #2
	ldr r0, [r7, #0x44]
	orrs r0, r1
	str r0, [r7, #0x44]
	movs r0, #0xdc
	bl PlaySound_082406e0
_08214B52:
	ldr r4, _08214B88 @ =0x030044E0
	ldrh r1, [r4, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08214B6E
	movs r0, #5
	str r0, [r7, #0x5c]
	movs r0, #0
	str r0, [r7, #0x60]
	movs r1, #2
	ldr r0, [r7, #0x44]
	orrs r0, r1
	str r0, [r7, #0x44]
_08214B6E:
	ldrh r1, [r4, #2]
	movs r5, #0x40
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08214BB6
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08214B8C
	movs r6, #2
	b _08214BBC
	.align 2, 0
_08214B88: .4byte 0x030044E0
_08214B8C:
	ldrh r0, [r4]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0
	beq _08214BBA
	ldr r0, [r7, #0x68]
	adds r0, #1
	str r0, [r7, #0x68]
	cmp r0, #0xe
	ble _08214BBC
	movs r1, #5
	bl Mod
	cmp r0, #0
	bne _08214BBC
	ldrh r1, [r4]
	adds r0, r5, #0
	ands r0, r1
	movs r6, #2
	cmp r0, #0
	beq _08214BBC
_08214BB6:
	movs r6, #1
	b _08214BBC
_08214BBA:
	str r1, [r7, #0x68]
_08214BBC:
	ldr r4, [r7, #0x5c]
	cmp r4, #3
	bne _08214BC4
	b _08214D10
_08214BC4:
	cmp r4, #3
	bgt _08214BD6
	cmp r4, #1
	beq _08214C4A
	cmp r4, #1
	bgt _08214CA4
	cmp r4, #0
	beq _08214BEA
	b _08214EE8
_08214BD6:
	cmp r4, #5
	bne _08214BDC
	b _08214DCE
_08214BDC:
	cmp r4, #5
	bge _08214BE2
	b _08214D68
_08214BE2:
	cmp r4, #0x63
	bne _08214BE8
	b _08214E70
_08214BE8:
	b _08214EE8
_08214BEA:
	movs r2, #2
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08214BF6
	movs r2, #1
_08214BF6:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _08214C0C
	adds r0, r7, #0
	bl FUN_08214334
	str r4, [r7, #0x68]
	movs r6, #0
_08214C0C:
	cmp r6, #1
	bne _08214C2C
	movs r2, #0x9c
	lsls r2, r2, #3
	add r2, sl
	ldr r1, [r2]
	ldr r0, _08214C28 @ =0x00000832
	cmp r1, r0
	ble _08214C20
	b _08214EE8
_08214C20:
	adds r0, r1, #1
	str r0, [r2]
	b _08214DC4
	.align 2, 0
_08214C28: .4byte 0x00000832
_08214C2C:
	cmp r6, #2
	beq _08214C32
	b _08214EE8
_08214C32:
	movs r2, #0x9c
	lsls r2, r2, #3
	add r2, sl
	ldr r1, [r2]
	movs r0, #0xfa
	lsls r0, r0, #3
	cmp r1, r0
	bgt _08214C44
	b _08214EE8
_08214C44:
	subs r0, r1, #1
	str r0, [r2]
	b _08214DC4
_08214C4A:
	movs r2, #2
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08214C56
	movs r2, #1
_08214C56:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _08214C6E
	adds r0, r7, #0
	bl FUN_08214334
	movs r0, #0
	str r0, [r7, #0x68]
	movs r6, #0
_08214C6E:
	cmp r6, #1
	bne _08214C88
	ldr r1, _08214C80 @ =0x000004E4
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0xb
	bls _08214C84
_08214C7C:
	strb r6, [r1]
	b _08214DC4
	.align 2, 0
_08214C80: .4byte 0x000004E4
_08214C84:
	adds r0, #1
	b _08214DC2
_08214C88:
	cmp r6, #2
	beq _08214C8E
	b _08214EE8
_08214C8E:
	ldr r1, _08214CA0 @ =0x000004E4
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #1
	bls _08214C9A
	b _08214DC0
_08214C9A:
	movs r0, #0xc
	b _08214DC2
	.align 2, 0
_08214CA0: .4byte 0x000004E4
_08214CA4:
	movs r2, #2
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08214CB0
	movs r2, #1
_08214CB0:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _08214CC8
	adds r0, r7, #0
	bl FUN_08214334
	movs r0, #0
	str r0, [r7, #0x68]
	movs r6, #0
_08214CC8:
	movs r0, #0x9c
	lsls r0, r0, #3
	add r0, sl
	ldr r0, [r0]
	ldr r1, _08214CF0 @ =0x000004E4
	add r1, sl
	ldrb r1, [r1]
	bl FUN_0823d970
	adds r5, r0, #0
	cmp r6, #1
	bne _08214CF8
	ldr r1, _08214CF4 @ =0x000004E5
	add r1, sl
	ldrb r0, [r1]
	cmp r0, r5
	bge _08214C7C
	adds r0, #1
	b _08214DC2
	.align 2, 0
_08214CF0: .4byte 0x000004E4
_08214CF4: .4byte 0x000004E5
_08214CF8:
	cmp r6, #2
	beq _08214CFE
	b _08214EE8
_08214CFE:
	ldr r1, _08214D0C @ =0x000004E5
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #1
	bhi _08214DC0
	strb r5, [r1]
	b _08214DC4
	.align 2, 0
_08214D0C: .4byte 0x000004E5
_08214D10:
	movs r2, #2
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08214D1C
	movs r2, #1
_08214D1C:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _08214D34
	adds r0, r7, #0
	bl FUN_08214334
	movs r0, #0
	str r0, [r7, #0x68]
	movs r6, #0
_08214D34:
	cmp r6, #1
	bne _08214D50
	ldr r1, _08214D48 @ =0x000004E6
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0x16
	bls _08214D4C
	movs r0, #0
	b _08214DC2
	.align 2, 0
_08214D48: .4byte 0x000004E6
_08214D4C:
	adds r0, #1
	b _08214DC2
_08214D50:
	cmp r6, #2
	beq _08214D56
	b _08214EE8
_08214D56:
	ldr r1, _08214D64 @ =0x000004E6
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08214DC0
	movs r0, #0x17
	b _08214DC2
	.align 2, 0
_08214D64: .4byte 0x000004E6
_08214D68:
	movs r2, #2
	ldr r1, [r7, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08214D74
	movs r2, #1
_08214D74:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	cmp r2, #0
	beq _08214D8C
	adds r0, r7, #0
	bl FUN_08214334
	movs r0, #0
	str r0, [r7, #0x68]
	movs r6, #0
_08214D8C:
	cmp r6, #1
	bne _08214DA8
	ldr r1, _08214DA0 @ =0x000004E7
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0x3a
	bls _08214DA4
	movs r0, #0
	b _08214DC2
	.align 2, 0
_08214DA0: .4byte 0x000004E7
_08214DA4:
	adds r0, #1
	b _08214DC2
_08214DA8:
	cmp r6, #2
	beq _08214DAE
	b _08214EE8
_08214DAE:
	ldr r1, _08214DBC @ =0x000004E7
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08214DC0
	movs r0, #0x3b
	b _08214DC2
	.align 2, 0
_08214DBC: .4byte 0x000004E7
_08214DC0:
	subs r0, #1
_08214DC2:
	strb r0, [r1]
_08214DC4:
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08214EE8
_08214DCE:
	movs r6, #2
	ldr r2, [r7, #0x44]
	adds r1, r2, #0
	ands r1, r6
	cmp r1, #0
	beq _08214DDC
	movs r1, #1
_08214DDC:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r7, #0x44]
	cmp r1, #0
	beq _08214E30
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0x9c
	lsls r0, r0, #3
	add r0, sl
	ldr r0, [r0]
	ldr r1, _08214E58 @ =0x000004E4
	add r1, sl
	ldrb r1, [r1]
	ldr r2, _08214E5C @ =0x000004E5
	add r2, sl
	ldrb r2, [r2]
	ldr r3, _08214E60 @ =0x000004E6
	add r3, sl
	ldrb r3, [r3]
	ldr r4, _08214E64 @ =0x000004E7
	add r4, sl
	ldrb r4, [r4]
	str r4, [sp]
	movs r5, #0
	str r5, [sp, #4]
	movs r4, #1
	str r4, [sp, #8]
	bl SetGameDateTime
	ldr r4, _08214E68 @ =0x030047E0
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x1c]
	ldr r2, [r4, #0x20]
	bl FUN_082401e8
	strb r5, [r4, #9]
	movs r0, #0x1e
	mov r1, r8
	str r0, [r1, #4]
_08214E30:
	ldr r0, [r7, #0x60]
	cmp r0, #0x3b
	ble _08214EE8
	adds r0, r7, #0
	adds r0, #0x70
	ldr r3, _08214E6C @ =0x0000FFFF
	movs r1, #1
	movs r2, #0x1e
	bl FUN_0821b21c
	cmp r0, #0
	beq _08214EE8
	movs r0, #0x63
	str r0, [r7, #0x5c]
	movs r0, #0
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x44]
	orrs r0, r6
	str r0, [r7, #0x44]
	b _08214EE8
	.align 2, 0
_08214E58: .4byte 0x000004E4
_08214E5C: .4byte 0x000004E5
_08214E60: .4byte 0x000004E6
_08214E64: .4byte 0x000004E7
_08214E68: .4byte 0x030047E0
_08214E6C: .4byte 0x0000FFFF
_08214E70:
	movs r0, #2
	ldr r1, [r7, #0x44]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	ldr r0, [r7, #0x50]
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
	ldr r0, _08214EDC @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08214EE0 @ =0x0000093E
	adds r0, r0, r2
	ldr r2, _08214EE4 @ =0x00000E7C
	adds r1, r7, r2
	ldr r1, [r1]
	strh r1, [r0]
	adds r0, r7, #0
	bl KillEntity
	b _082150C6
	.align 2, 0
_08214EDC: .4byte 0x030046A0
_08214EE0: .4byte 0x0000093E
_08214EE4: .4byte 0x00000E7C
_08214EE8:
	movs r0, #0x9c
	lsls r0, r0, #3
	add r0, sl
	ldr r0, [r0]
	ldr r1, [sp, #0xc]
	cmp r0, r1
	beq _08214F36
	mov sb, sl
	adds r5, r0, #0
	movs r6, #0
	movs r2, #0x18
	adds r2, r2, r7
	mov r8, r2
_08214F02:
	movs r0, #3
	subs r0, r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #5
	add r4, sb
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl FUN_0822f3cc
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	adds r6, #1
	cmp r6, #3
	ble _08214F02
_08214F36:
	ldr r0, _082150D8 @ =0x000004E4
	add r0, sl
	ldrb r0, [r0]
	ldr r1, [sp, #0x10]
	cmp r0, r1
	beq _08214F88
	movs r2, #0xc0
	lsls r2, r2, #1
	add r2, sl
	mov sb, r2
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x18
	adds r0, r0, r7
	mov r8, r0
_08214F54:
	movs r0, #1
	subs r0, r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #5
	add r4, sb
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl FUN_0822f3cc
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	adds r6, #1
	cmp r6, #1
	ble _08214F54
_08214F88:
	movs r0, #0x9c
	lsls r0, r0, #3
	add r0, sl
	ldr r2, [r0]
	ldr r1, [sp, #0xc]
	cmp r2, r1
	bne _08214FA2
	ldr r0, _082150D8 @ =0x000004E4
	add r0, sl
	ldrb r0, [r0]
	ldr r1, [sp, #0x10]
	cmp r0, r1
	beq _08214FBC
_08214FA2:
	ldr r0, _082150D8 @ =0x000004E4
	add r0, sl
	ldrb r1, [r0]
	adds r0, r2, #0
	bl FUN_0823d970
	adds r5, r0, #0
	ldr r1, _082150DC @ =0x000004E5
	add r1, sl
	ldrb r0, [r1]
	cmp r0, r5
	ble _08214FBC
	strb r5, [r1]
_08214FBC:
	ldr r0, _082150DC @ =0x000004E5
	add r0, sl
	ldrb r0, [r0]
	ldr r2, [sp, #0x14]
	cmp r0, r2
	beq _0821500E
	movs r1, #0x90
	lsls r1, r1, #2
	add r1, sl
	mov sb, r1
	adds r5, r0, #0
	movs r6, #0
	movs r2, #0x18
	adds r2, r2, r7
	mov r8, r2
_08214FDA:
	movs r0, #1
	subs r0, r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #5
	add r4, sb
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl FUN_0822f3cc
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	adds r6, #1
	cmp r6, #1
	ble _08214FDA
_0821500E:
	ldr r0, _082150E0 @ =0x000004E6
	add r0, sl
	ldrb r0, [r0]
	ldr r1, [sp, #0x18]
	cmp r0, r1
	beq _08215060
	movs r2, #0xc0
	lsls r2, r2, #2
	add r2, sl
	mov sb, r2
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x18
	adds r0, r0, r7
	mov r8, r0
_0821502C:
	movs r0, #1
	subs r0, r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #5
	add r4, sb
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl FUN_0822f3cc
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	adds r6, #1
	cmp r6, #1
	ble _0821502C
_08215060:
	ldr r0, _082150E4 @ =0x000004E7
	add r0, sl
	ldrb r0, [r0]
	ldr r1, [sp, #0x1c]
	cmp r0, r1
	beq _082150B2
	movs r2, #0xf0
	lsls r2, r2, #2
	add r2, sl
	mov sb, r2
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x18
	adds r0, r0, r7
	mov r8, r0
_0821507E:
	movs r0, #1
	subs r0, r0, r6
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #5
	add r4, sb
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl FUN_0822f3cc
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	adds r6, #1
	cmp r6, #1
	ble _0821507E
_082150B2:
	ldr r0, [r7, #0x5c]
	cmp r0, #4
	bgt _082150C6
	movs r0, #0x90
	lsls r0, r0, #3
	add r0, sl
	adds r1, r7, #0
	adds r1, #0x18
	bl FUN_082372cc
_082150C6:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082150D8: .4byte 0x000004E4
_082150DC: .4byte 0x000004E5
_082150E0: .4byte 0x000004E6
_082150E4: .4byte 0x000004E7
