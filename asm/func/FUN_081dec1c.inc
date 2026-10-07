	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r1, _081DEC68 @ =0x030044D0
	movs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEC9C
	ldr r1, _081DEC6C @ =0x085AE3F4
	ldr r2, _081DEC70 @ =0x000002CD
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x32]
	ldr r0, _081DEC74 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x94
	lsls r3, r3, #4
	adds r0, r0, r3
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x54
	strb r1, [r0]
	subs r0, #0x22
	bl FUN_0809c544
	movs r6, #0
	ldr r5, _081DEC78 @ =0x03002BE0
	b _081DEC8A
	.align 2, 0
_081DEC68: .4byte 0x030044D0
_081DEC6C: .4byte 0x085AE3F4
_081DEC70: .4byte 0x000002CD
_081DEC74: .4byte 0x030046A0
_081DEC78: .4byte 0x03002BE0
_081DEC7C:
	ldr r0, [r5]
	cmp r0, #0
	beq _081DEC86
	bl FUN_0807d118
_081DEC86:
	adds r5, #4
	adds r6, #1
_081DEC8A:
	ldr r0, _081DECD4 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081DEC98
	ldrh r1, [r0, #0x1a]
_081DEC98:
	cmp r6, r1
	blt _081DEC7C
_081DEC9C:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DECA8
	b _081DEE98
_081DECA8:
	ldr r0, _081DECD8 @ =0x04000130
	ldrh r0, [r0]
	ldr r1, _081DECDC @ =0x0000FFF3
	mov r8, r1
	mov r2, r8
	ands r2, r0
	mov r8, r2
	movs r7, #0
	movs r5, #0
	ldrh r3, [r4, #0x1a]
	cmp r5, r3
	bge _081DED8E
	movs r0, #0xf0
	lsls r0, r0, #6
	mov ip, r0
	movs r6, #0
	ldr r1, _081DECE0 @ =0x000003FF
	mov sb, r1
_081DECCC:
	cmp r5, #0
	bge _081DECE8
	ldr r0, _081DECE4 @ =0x0000FFFF
	b _081DECEE
	.align 2, 0
_081DECD4: .4byte 0x03002C68
_081DECD8: .4byte 0x04000130
_081DECDC: .4byte 0x0000FFF3
_081DECE0: .4byte 0x000003FF
_081DECE4: .4byte 0x0000FFFF
_081DECE8:
	ldr r0, [r4, #0x44]
	adds r0, r6, r0
	ldrh r0, [r0]
_081DECEE:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r0, r3, #0
	mov r2, ip
	ands r0, r2
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	bne _081DED04
	movs r0, #1
	b _081DED06
_081DED04:
	movs r0, #0
_081DED06:
	cmp r0, #0
	beq _081DED54
	ldr r2, _081DED50 @ =0x03004510
	adds r2, r6, r2
	adds r0, r3, #0
	mov r1, sb
	ands r0, r1
	movs r1, #0xc
	orrs r0, r1
	strh r0, [r2]
	lsrs r2, r3, #2
	movs r0, #1
	ands r2, r0
	adds r0, r4, #0
	adds r0, #0x50
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r1, r4, #0
	adds r1, #0x58
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x52
	ldrb r0, [r0]
	lsls r2, r0
	ldrb r0, [r1]
	orrs r2, r0
	strb r2, [r1]
	cmp r5, #0
	bne _081DED84
	movs r7, #1
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _081DED84
	movs r7, #3
	b _081DED84
	.align 2, 0
_081DED50: .4byte 0x03004510
_081DED54:
	ldr r0, _081DED78 @ =0x0000FFFF
	cmp r3, r0
	bne _081DED5C
	b _081DEE98
_081DED5C:
	movs r2, #0x18
	ldrsh r0, [r4, r2]
	cmp r5, r0
	bne _081DED84
	adds r0, r3, #0
	mov r3, ip
	ands r0, r3
	movs r1, #0xa0
	lsls r1, r1, #6
	cmp r0, r1
	bne _081DED7C
	movs r0, #1
	b _081DED7E
	.align 2, 0
_081DED78: .4byte 0x0000FFFF
_081DED7C:
	movs r0, #0
_081DED7E:
	cmp r0, #0
	beq _081DED84
	b _081DEEA4
_081DED84:
	adds r6, #2
	adds r5, #1
	ldrh r0, [r4, #0x1a]
	cmp r5, r0
	blt _081DECCC
_081DED8E:
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	beq _081DEDA0
	adds r1, r4, #0
	adds r1, #0x52
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_081DEDA0:
	movs r0, #2
	ands r7, r0
	movs r1, #0x42
	adds r1, r1, r4
	mov sb, r1
	cmp r7, #0
	beq _081DEDF8
	adds r0, r4, #0
	bl FUN_081dda10
	adds r0, r4, #0
	bl FUN_081dda38
	adds r1, r4, #0
	adds r1, #0x52
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081DEE54 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x54
	strb r1, [r0]
	movs r5, #0
	ldrh r3, [r4, #0x1a]
	cmp r5, r3
	bge _081DEDF8
	adds r2, r4, #0
	adds r2, #0x50
	adds r1, r4, #0
	adds r1, #0x58
	movs r3, #0
_081DEDE6:
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r0, r1, r0
	strb r3, [r0]
	adds r5, #1
	ldrh r0, [r4, #0x1a]
	cmp r5, r0
	blt _081DEDE6
_081DEDF8:
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	movs r0, #0xe1
	lsls r0, r0, #3
	cmp r1, r0
	beq _081DEE0C
	movs r0, #0xe1
	lsls r0, r0, #2
	cmp r1, r0
	bne _081DEE34
_081DEE0C:
	movs r5, #0
	ldrh r3, [r4, #0x1a]
	cmp r5, r3
	bge _081DEE34
	ldr r6, _081DEE58 @ =0x03002BE0
_081DEE16:
	adds r0, r5, #0
	bl FUN_081df720
	cmp r0, #2
	ble _081DEE2A
	ldr r1, [r6]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_0801a108
_081DEE2A:
	adds r6, #4
	adds r5, #1
	ldrh r0, [r4, #0x1a]
	cmp r5, r0
	blt _081DEE16
_081DEE34:
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _081DEE60
	bl FUN_0809c58c
	movs r0, #0xa0
	lsls r0, r0, #6
	mov r2, sb
	strh r0, [r2]
	ldr r2, _081DEE5C @ =FUN_081deef8
	adds r0, r4, #0
	movs r1, #0xd
	bl Entity9A9F_SetState
	b _081DEEEA
	.align 2, 0
_081DEE54: .4byte 0x030046A0
_081DEE58: .4byte 0x03002BE0
_081DEE5C: .4byte FUN_081deef8
_081DEE60:
	ldr r0, _081DEE70 @ =0x03002C68
	ldr r2, [r0]
	adds r1, r0, #0
	cmp r2, #0
	bne _081DEE74
	adds r3, r4, #0
	adds r3, #0x53
	b _081DEE8E
	.align 2, 0
_081DEE70: .4byte 0x03002C68
_081DEE74:
	movs r3, #0x18
	ldrsh r0, [r2, r3]
	adds r3, r4, #0
	adds r3, #0x53
	cmp r0, #0
	bne _081DEE8E
	ldrb r0, [r3]
	cmp r0, #7
	bne _081DEE8E
	movs r0, #8
	mov r2, r8
	orrs r2, r0
	mov r8, r2
_081DEE8E:
	ldr r1, [r1]
	cmp r1, #0
	bne _081DEEB4
	movs r0, #0
	b _081DEEC4
_081DEE98:
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DEEEC
_081DEEA4:
	ldr r2, _081DEEB0 @ =FUN_081deef8
	adds r0, r4, #0
	movs r1, #0xd
	bl Entity9A9F_SetState
	b _081DEEEA
	.align 2, 0
_081DEEB0: .4byte FUN_081deef8
_081DEEB4:
	adds r0, r1, #0
	adds r0, #0x54
	ldrb r0, [r0]
	adds r1, #0x53
	ldrb r1, [r1]
	asrs r0, r1
	movs r1, #1
	ands r0, r1
_081DEEC4:
	lsls r0, r0, #2
	mov r1, r8
	orrs r1, r0
	lsls r2, r1, #0x10
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	strb r0, [r3]
	movs r0, #0xc0
	lsls r0, r0, #0x14
	orrs r0, r2
	lsls r0, r0, #2
	lsrs r0, r0, #0x12
	mov r2, sb
	strh r0, [r2]
	ldrh r0, [r4, #0x32]
	subs r0, #1
	strh r0, [r4, #0x32]
_081DEEEA:
	movs r0, #0
_081DEEEC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
