	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r0, r6, #0
	adds r0, #0x68
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08020D7A
	cmp r1, #0
	blt _08020D7A
	ldr r0, _08020D80 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08020D7A
	ldr r0, _08020D84 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08020D88
_08020D7A:
	movs r1, #0
	b _08020D96
	.align 2, 0
_08020D80: .4byte 0x030046A8
_08020D84: .4byte 0x030046AC
_08020D88:
	ldr r0, _08020DAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08020D96:
	adds r0, r6, #0
	adds r0, #0x38
	ldrb r2, [r0]
	mov sb, r0
	cmp r2, #1
	beq _08020DC6
	cmp r2, #1
	bgt _08020DB0
	cmp r2, #0
	beq _08020DBA
	b _08020E00
	.align 2, 0
_08020DAC: .4byte 0x030046A4
_08020DB0:
	cmp r2, #2
	beq _08020DDC
	cmp r2, #3
	beq _08020DE8
	b _08020E00
_08020DBA:
	subs r0, r1, #1
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _08020DFA
_08020DC6:
	ldr r0, _08020DD8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	b _08020DF6
	.align 2, 0
_08020DD8: .4byte 0x030046A4
_08020DDC:
	strh r1, [r6, #0x3c]
	subs r0, r1, #1
	strh r0, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _08020DFA
_08020DE8:
	strh r1, [r6, #0x3c]
	ldr r0, _08020E14 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3e]
_08020DF6:
	adds r1, r6, #0
	adds r1, #0x68
_08020DFA:
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
_08020E00:
	ldrh r4, [r6, #0x3c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08020E18
	adds r0, #4
	b _08020E24
	.align 2, 0
_08020E14: .4byte 0x030046A4
_08020E18:
	ldr r0, _08020E60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08020E24:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r4, r6, #0
	adds r4, #0x3b
	movs r5, #0
	strb r0, [r4]
	ldr r0, [r6, #0x2c]
	ldrh r1, [r6, #0x3c]
	ldrb r3, [r4]
	movs r2, #0xff
	str r2, [sp]
	str r5, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	adds r5, r6, #0
	ldr r0, [r7, #0x34]
	mov r8, r4
	cmp r0, #0
	bne _08020E9E
	adds r0, r6, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	beq _08020E64
	cmp r0, #0x10
	beq _08020E8A
	b _08020F8A
	.align 2, 0
_08020E60: .4byte 0x030046A4
_08020E64:
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r0, r0, r4
	adds r0, r7, r0
	movs r1, #0xa7
	bl Video_SetAuxSpritePltt
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	adds r0, r6, #0
	b _08020F4E
_08020E8A:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r1, r7, r1
	adds r0, r6, #0
	b _08020F4E
_08020E9E:
	adds r0, r6, #0
	adds r0, #0x45
	ldrb r1, [r0]
	adds r2, r0, #0
	cmp r1, #7
	bhi _08020F8A
	lsls r0, r1, #2
	ldr r1, _08020EB4 @ =_08020EB8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020EB4: .4byte _08020EB8
_08020EB8: @ jump table
	.4byte _08020ED8 @ case 0
	.4byte _08020EFE @ case 1
	.4byte _08020F06 @ case 2
	.4byte _08020F10 @ case 3
	.4byte _08020F18 @ case 4
	.4byte _08020F20 @ case 5
	.4byte _08020F28 @ case 6
	.4byte _08020F5C @ case 7
_08020ED8:
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r0, r0, r4
	adds r0, r7, r0
	ldrb r1, [r2]
	adds r1, #0xa7
	bl Video_SetAuxSpritePltt
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	b _08020F4C
_08020EFE:
	movs r3, #0x82
	lsls r3, r3, #3
	adds r4, r7, r3
	b _08020F2C
_08020F06:
	ldr r0, _08020F0C @ =0x00000414
	b _08020F2A
	.align 2, 0
_08020F0C: .4byte 0x00000414
_08020F10:
	movs r3, #0x83
	lsls r3, r3, #3
	adds r4, r7, r3
	b _08020F2C
_08020F18:
	ldr r0, _08020F1C @ =0x0000041C
	b _08020F2A
	.align 2, 0
_08020F1C: .4byte 0x0000041C
_08020F20:
	movs r3, #0x84
	lsls r3, r3, #3
	adds r4, r7, r3
	b _08020F2C
_08020F28:
	ldr r0, _08020F58 @ =0x00000424
_08020F2A:
	adds r4, r7, r0
_08020F2C:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r4]
	adds r0, r0, r1
	ldrb r1, [r2]
	adds r1, #0xa7
	bl Video_SetAuxSpritePltt
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r4]
	adds r1, r1, r0
_08020F4C:
	adds r0, r5, #0
_08020F4E:
	movs r2, #0
	bl AuxSprite_Add
	b _08020F8A
	.align 2, 0
_08020F58: .4byte 0x00000424
_08020F5C:
	movs r3, #0x85
	lsls r3, r3, #3
	adds r4, r7, r3
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r4]
	adds r0, r0, r1
	ldrb r1, [r2]
	adds r1, #0xa7
	bl Video_SetAuxSpritePltt
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r4]
	adds r1, r1, r0
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
_08020F8A:
	ldr r0, [r6, #0x78]
	ldr r1, [r6, #0x7c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r0, sb
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08020FAC
	ldrh r0, [r5, #0x1c]
	subs r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	adds r0, #0x20
	strh r0, [r5, #0x20]
	b _08020FC0
_08020FAC:
	ldrh r0, [r5, #0x1c]
	adds r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	subs r0, #0x20
	strh r0, [r5, #0x20]
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_08020FC0:
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r6, #0x70]
	str r1, [r6, #0x74]
	adds r0, r6, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _08020FE8
	ldr r0, _08020FE4 @ =FUN_0802108c
	str r0, [r6, #0x30]
	adds r0, r6, #0
	adds r0, #0x39
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	b _08021018
	.align 2, 0
_08020FE4: .4byte FUN_0802108c
_08020FE8:
	cmp r1, #1
	bne _08021008
	ldr r0, _08021004 @ =FUN_08021090
	str r0, [r6, #0x30]
	movs r0, #2
	adds r2, r6, #0
	adds r2, #0x39
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x3a
	strb r1, [r0]
	b _08021018
	.align 2, 0
_08021004: .4byte FUN_08021090
_08021008:
	ldr r0, _08021048 @ =FUN_0802108c
	str r0, [r6, #0x30]
	adds r1, r6, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
_08021018:
	ldrb r0, [r3]
	cmp r0, #0
	bne _08021050
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _0802104C @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	mov r3, r8
	ldrb r0, [r3]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	b _08021078
	.align 2, 0
_08021048: .4byte FUN_0802108c
_0802104C: .4byte 0x0000FFFD
_08021050:
	cmp r0, #1
	bne _08021078
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08021088 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	mov r3, r8
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r2, #4]
_08021078:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021088: .4byte 0x0000FFFC
