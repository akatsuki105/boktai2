	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r0, #0x70
	adds r0, r0, r6
	mov sb, r0
	ldr r1, _08215A10 @ =0x00000DBC
	adds r7, r6, r1
	movs r2, #1
	mov r8, r2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	mov r0, r8
	ands r1, r0
	cmp r1, #0
	beq _08215978
	movs r1, #1
_08215978:
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _082159FC
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r5, #9
	ldr r1, [r6, #0x38]
	movs r0, #2
	movs r2, #9
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	str r5, [r6, #0x64]
	adds r0, r6, #0
	bl FUN_082158a0
	ldr r2, _08215A14 @ =0x00000E84
	adds r1, r6, r2
	ldr r0, _08215A18 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08215A1C @ =0x00000944
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_082158fc
_082159FC:
	ldr r4, [r6, #0x5c]
	cmp r4, #1
	bne _08215A04
	b _08215C08
_08215A04:
	cmp r4, #1
	bgt _08215A20
	cmp r4, #0
	beq _08215A2E
	b _08215D04
	.align 2, 0
_08215A10: .4byte 0x00000DBC
_08215A14: .4byte 0x00000E84
_08215A18: .4byte 0x030046A0
_08215A1C: .4byte 0x00000944
_08215A20:
	cmp r4, #2
	bne _08215A26
	b _08215C4C
_08215A26:
	cmp r4, #0x63
	bne _08215A2C
	b _08215C6E
_08215A2C:
	b _08215D04
_08215A2E:
	movs r3, #2
	ldr r2, [r6, #0x44]
	adds r0, r2, #0
	ands r0, r3
	movs r1, #3
	rsbs r1, r1, #0
	ands r1, r2
	str r1, [r6, #0x44]
	ldr r0, _08215A5C @ =0x030044E0
	ldrh r2, [r0, #2]
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _08215A60
	mov r0, r8
	str r0, [r6, #0x5c]
	str r4, [r6, #0x60]
	orrs r1, r3
	str r1, [r6, #0x44]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _08215D04
	.align 2, 0
_08215A5C: .4byte 0x030044E0
_08215A60:
	movs r5, #1
	mov r0, r8
	ands r0, r2
	cmp r0, #0
	beq _08215B30
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _08215A88 @ =0x00000E7C
	adds r1, r1, r6
	mov sb, r1
	ldr r0, [r1]
	cmp r0, #1
	beq _08215AA2
	cmp r0, #1
	bgt _08215A8C
	cmp r0, #0
	beq _08215A92
	b _08215D04
	.align 2, 0
_08215A88: .4byte 0x00000E7C
_08215A8C:
	cmp r0, #2
	beq _08215AB4
	b _08215D04
_08215A92:
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08219f34
	ldr r0, [r7, #8]
	orrs r0, r5
	str r0, [r7, #8]
	b _08215D04
_08215AA2:
	adds r0, r6, #0
	movs r1, #3
	bl FUN_08219f34
	ldr r0, [r7, #8]
	mov r2, r8
	orrs r0, r2
	str r0, [r7, #8]
	b _08215D04
_08215AB4:
	ldr r1, _08215B24 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	orrs r0, r5
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r0, #0xc8
	str r0, [sp, #8]
	adds r0, #4
	ldr r0, [r0]
	add r1, sp, #4
	bl Script_ExecById
	ldr r0, [r7, #8]
	orrs r0, r5
	str r0, [r7, #8]
	ldr r0, [r7, #0x68]
	orrs r0, r5
	str r0, [r7, #0x68]
	movs r0, #0
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _08215B28 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08215B2C @ =0x0000093E
	adds r0, r0, r1
	mov r2, sb
	ldr r1, [r2]
	b _08215CE8
	.align 2, 0
_08215B24: .4byte 0xFFFF0000
_08215B28: .4byte 0x030046A0
_08215B2C: .4byte 0x0000093E
_08215B30:
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _08215B5C
	ldr r0, _08215B58 @ =0x00000E7C
	adds r1, r6, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bge _08215B48
	str r3, [r1]
_08215B48:
	adds r0, r6, #0
	bl FUN_082158e4
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _08215B80
	.align 2, 0
_08215B58: .4byte 0x00000E7C
_08215B5C:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _08215B80
	ldr r2, _08215BCC @ =0x00000E7C
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	cmp r0, #2
	ble _08215B74
	str r4, [r1]
_08215B74:
	adds r0, r6, #0
	bl FUN_082158e4
	movs r0, #0xdc
	bl PlaySound_082406e0
_08215B80:
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, #2
	bne _08215BFE
	adds r0, r7, #0
	adds r0, #0x60
	adds r1, r6, #0
	adds r1, #0x18
	movs r2, #0x43
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, [r7, #0x68]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x68]
	ldr r0, _08215BD0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08215BD4
	adds r1, r7, #0
	adds r1, #0xc8
	ldr r0, [r1]
	cmp r0, #0
	bne _08215BC2
	movs r0, #9
	str r0, [r1]
_08215BC2:
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	b _08215BEE
	.align 2, 0
_08215BCC: .4byte 0x00000E7C
_08215BD0: .4byte 0x030044E0
_08215BD4:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08215BDE
	b _08215D04
_08215BDE:
	adds r1, r7, #0
	adds r1, #0xc8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	cmp r0, #8
	ble _08215BEE
	str r2, [r1]
_08215BEE:
	adds r0, r6, #0
	bl FUN_082158fc
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08215D04
_08215BFE:
	ldr r0, [r7, #0x68]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x68]
	b _08215D04
_08215C08:
	movs r4, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _08215C16
	movs r1, #1
_08215C16:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _08215C28
	movs r0, #0x1e
	mov r1, sb
	str r0, [r1, #4]
_08215C28:
	ldr r3, _08215C48 @ =0x0000FFFF
	mov r0, sb
	movs r1, #1
	movs r2, #0x1e
	bl FUN_0821b21c
	cmp r0, #0
	beq _08215D04
	str r4, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x44]
	orrs r0, r4
	str r0, [r6, #0x44]
	b _08215D04
	.align 2, 0
_08215C48: .4byte 0x0000FFFF
_08215C4C:
	ldr r2, [r6, #0x44]
	adds r0, r2, #0
	ands r0, r4
	movs r1, #3
	rsbs r1, r1, #0
	ands r1, r2
	str r1, [r6, #0x44]
	ldr r0, [r6, #0x60]
	cmp r0, #0x3b
	ble _08215D04
	movs r0, #0x63
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	orrs r1, r4
	str r1, [r6, #0x44]
	b _08215D04
_08215C6E:
	movs r0, #2
	ldr r1, [r6, #0x44]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x44]
	ldr r5, _08215CF4 @ =0x030046A0
	ldr r0, [r5]
	ldr r2, _08215CF8 @ =0x00000944
	adds r0, r0, r2
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r7, #8]
	mov r1, r8
	orrs r0, r1
	str r0, [r7, #8]
	ldr r0, [r7, #0x68]
	orrs r0, r1
	str r0, [r7, #0x68]
	ldr r0, [r6, #0x50]
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, [r5]
	ldr r2, _08215CFC @ =0x0000093E
	adds r0, r0, r2
	ldr r2, _08215D00 @ =0x00000E7C
	adds r1, r6, r2
	ldr r1, [r1]
_08215CE8:
	strh r1, [r0]
	adds r0, r6, #0
	bl KillEntity
	b _08215D14
	.align 2, 0
_08215CF4: .4byte 0x030046A0
_08215CF8: .4byte 0x00000944
_08215CFC: .4byte 0x0000093E
_08215D00: .4byte 0x00000E7C
_08215D04:
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	bgt _08215D14
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r7, #0
	bl FUN_082372cc
_08215D14:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
