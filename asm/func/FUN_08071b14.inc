	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r1, _08071B30 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _08071B26
	b _08071FFC
_08071B26:
	lsls r0, r0, #2
	ldr r1, _08071B34 @ =_08071B38
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08071B30: .4byte 0x0000037D
_08071B34: .4byte _08071B38
_08071B38: @ jump table
	.4byte _08071B58 @ case 0
	.4byte _08071BB2 @ case 1
	.4byte _08071C96 @ case 2
	.4byte _08071D40 @ case 3
	.4byte _08071DD8 @ case 4
	.4byte _08071E1E @ case 5
	.4byte _08071F4C @ case 6
	.4byte _08071FC8 @ case 7
_08071B58:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08071B76
	b _08071FFC
_08071B76:
	movs r1, #0x80
	lsls r1, r1, #0x16
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08071B92
	movs r0, #0xa9
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x1e
	b _08071B9A
_08071B92:
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x3c
_08071B9A:
	strh r0, [r1]
	movs r0, #0x89
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08071FFC
_08071BB2:
	ldr r1, _08071C10 @ =0x0000037E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _08071BC2
	ldr r0, _08071C14 @ =0x000001F7
	bl PlaySound_082406e0
_08071BC2:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _08071BF0
	b _08071FFC
_08071BF0:
	ldr r0, _08071C18 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08071C1C @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bhi _08071C20
	movs r0, #0xd5
	b _08071E0E
	.align 2, 0
_08071C10: .4byte 0x0000037E
_08071C14: .4byte 0x000001F7
_08071C18: .4byte 0x00000A8F
_08071C1C: .4byte 0x000003E6
_08071C20:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08071C46
	movs r0, #0xfb
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071C6E
_08071C46:
	movs r1, #0x80
	lsls r1, r1, #0xd
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08071C64
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071C6E
_08071C64:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
_08071C6E:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2e
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r2, #0
	str r2, [sp, #0xc]
	movs r1, #0x14
	str r1, [sp, #0x10]
	movs r0, #0x11
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	str r2, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xc8
	movs r2, #0xaa
	movs r3, #8
	bl FUN_08080be8
	b _08071FFC
_08071C96:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08071D2C @ =0x0000037E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #6
	bne _08071CC6
	movs r0, #0xfa
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08071CC6:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08071CDA
	b _08071E0A
_08071CDA:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08071CF2
	b _08071FFC
_08071CF2:
	ldr r0, _08071D30 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08071D34 @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _08071D38 @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _08071D3C @ =0x00000121
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
	movs r0, #4
	bl GetWeaponSkillLevel
	cmp r0, #0x62
	ble _08071DAE
	adds r0, r5, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _08071FFC
	.align 2, 0
_08071D2C: .4byte 0x0000037E
_08071D30: .4byte 0x00000A8F
_08071D34: .4byte 0x000003E6
_08071D38: .4byte 0x0000095E
_08071D3C: .4byte 0x00000121
_08071D40:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071E0A
	ldr r1, _08071DC0 @ =0x0000037E
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r0, r5, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	bhs _08071D8C
	b _08071FFC
_08071D8C:
	ldr r0, _08071DC4 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _08071DC8 @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0x3c
	strh r0, [r1]
	ldr r0, _08071DCC @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _08071DD0 @ =0x00000121
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
_08071DAE:
	ldr r0, _08071DD4 @ =0x000001F5
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071FFC
	.align 2, 0
_08071DC0: .4byte 0x0000037E
_08071DC4: .4byte 0x00000A8F
_08071DC8: .4byte 0x000003E6
_08071DCC: .4byte 0x0000095E
_08071DD0: .4byte 0x00000121
_08071DD4: .4byte 0x000001F5
_08071DD8:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071E0A
	b _08071FFC
_08071E0A:
	movs r0, #0xfb
	lsls r0, r0, #1
_08071E0E:
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071FFC
_08071E1E:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x28
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071E50
	ldr r0, _08071ECC @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08071E50:
	ldr r1, _08071ED0 @ =0x000003E6
	adds r6, r5, r1
	ldrh r0, [r6]
	cmp r0, #0
	beq _08071F28
	cmp r0, #5
	bls _08071E9C
	ldr r3, _08071ED4 @ =0xFFFF0000
	ldr r1, _08071ED8 @ =0x0000FFFF
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r3
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbd08
_08071E9C:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r6]
	ldr r2, _08071EDC @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08071EE0
	asrs r0, r0, #0xc
	b _08071EE6
	.align 2, 0
_08071ECC: .4byte 0x00000A76
_08071ED0: .4byte 0x000003E6
_08071ED4: .4byte 0xFFFF0000
_08071ED8: .4byte 0x0000FFFF
_08071EDC: .4byte 0x085B0A08
_08071EE0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08071EE6:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _08071F04 @ =0x000003E6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08071F08
	asrs r0, r0, #0xc
	b _08071F0E
	.align 2, 0
_08071F04: .4byte 0x000003E6
_08071F08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08071F0E:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _08071F24 @ =0x000003E6
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _08071FFC
	.align 2, 0
_08071F24: .4byte 0x000003E6
_08071F28:
	ldr r2, _08071F48 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08071FFC
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _08071FFC
	.align 2, 0
_08071F48: .4byte 0x0000037E
_08071F4C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071F7E
	ldr r0, _08071F98 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08071F7E:
	ldr r1, _08071F98 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _08071FA0
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08071F9C @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _08071FFC
	.align 2, 0
_08071F98: .4byte 0x00000A76
_08071F9C: .4byte 0x0000037D
_08071FA0:
	ldr r0, _08071FC4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _08071FFC
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08060b84
	b _08071FFC
	.align 2, 0
_08071FC4: .4byte 0x0000037E
_08071FC8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0807200C @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08071FFC
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08071FFC:
	ldr r0, _08072010 @ =0x00000951
	adds r1, r5, r0
	movs r0, #4
	strb r0, [r1]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807200C: .4byte 0x0000037E
_08072010: .4byte 0x00000951
