	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	adds r7, r1, #0
	ldr r0, _081F6D9C @ =0x000006EA
	adds r3, r7, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F6D32
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081F6D32:
	ldr r1, _081F6DA0 @ =0x000006D9
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #9
	bls _081F6D3E
	b _081F6EFC
_081F6D3E:
	adds r1, #0xf
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #4
	bl Mod
	cmp r0, #0
	beq _081F6D52
	b _081F7088
_081F6D52:
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r5, r0, #0
	adds r5, #0x1c
	ldr r1, [r0, #0x1c]
	ldr r2, [r0, #0x20]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	ldrh r0, [r0, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F6D96
	cmp r1, #0
	blt _081F6D96
	ldr r0, _081F6DA4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F6D96
	ldr r0, _081F6DA8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F6DAC
_081F6D96:
	movs r4, #0
	b _081F6DBA
	.align 2, 0
_081F6D9C: .4byte 0x000006EA
_081F6DA0: .4byte 0x000006D9
_081F6DA4: .4byte 0x030046A8
_081F6DA8: .4byte 0x030046AC
_081F6DAC:
	ldr r0, _081F6DCC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F6DBA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F6DD0
	adds r0, #4
	b _081F6DDC
	.align 2, 0
_081F6DCC: .4byte 0x030046A4
_081F6DD0:
	ldr r0, _081F6DF0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F6DDC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081F6DF4
	cmp r3, #2
	beq _081F6DF8
	b _081F6DFC
	.align 2, 0
_081F6DF0: .4byte 0x030046A4
_081F6DF4:
	ldrb r0, [r5, #4]
	b _081F6DFA
_081F6DF8:
	ldrb r0, [r5]
_081F6DFA:
	subs r2, r2, r0
_081F6DFC:
	lsls r2, r2, #0x10
	ldr r1, _081F6E58 @ =0x0000FFFF
	ldr r0, [sp, #0x2c]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x2c]
	add r0, sp, #0x2c
	movs r1, #2
	bl Entity081f73ec_SpawnDust
	ldr r4, _081F6E5C @ =0x0203B400
	ldr r3, _081F6E60 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081F6E64 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r6, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	add r2, sp, #0x34
	adds r3, r0, #0
	adds r3, #0xa
	ldr r1, _081F6E68 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _081F6E6C
	asrs r1, r0, #0xc
	b _081F6E72
	.align 2, 0
_081F6E58: .4byte 0x0000FFFF
_081F6E5C: .4byte 0x0203B400
_081F6E60: .4byte 0x030046B8
_081F6E64: .4byte 0x000003FF
_081F6E68: .4byte gSineTable
_081F6E6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F6E72:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _081F6E8C @ =gSineTable
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081F6E90
	asrs r0, r0, #0xc
	b _081F6E96
	.align 2, 0
_081F6E8C: .4byte gSineTable
_081F6E90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6E96:
	movs r4, #0
	strh r0, [r2, #4]
	ldr r2, _081F6EE4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081F6EE8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081F6EEC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x18
	strh r0, [r5, #2]
	ldr r2, _081F6EF0 @ =0x00009D41
	ldr r3, _081F6EF4 @ =0x0000E677
	movs r0, #2
	str r0, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _081F6EF8 @ =0x0000023D
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	add r0, sp, #0x2c
	adds r1, r5, #0
	bl Entity081efa9c_Spawn
	b _081F7088
	.align 2, 0
_081F6EE4: .4byte 0x030046B8
_081F6EE8: .4byte 0x000003FF
_081F6EEC: .4byte 0x0203B400
_081F6EF0: .4byte 0x00009D41
_081F6EF4: .4byte 0x0000E677
_081F6EF8: .4byte 0x0000023D
_081F6EFC:
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x14
	bl Mod
	cmp r0, #0
	beq _081F6F12
	b _081F7088
_081F6F12:
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r5, r0, #0
	adds r5, #0x1c
	ldr r1, [r0, #0x1c]
	ldr r2, [r0, #0x20]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	ldrh r0, [r0, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F6F56
	cmp r1, #0
	blt _081F6F56
	ldr r0, _081F6F5C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F6F56
	ldr r0, _081F6F60 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F6F64
_081F6F56:
	movs r4, #0
	b _081F6F72
	.align 2, 0
_081F6F5C: .4byte 0x030046A8
_081F6F60: .4byte 0x030046AC
_081F6F64:
	ldr r0, _081F6F84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F6F72:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F6F88
	adds r0, #4
	b _081F6F94
	.align 2, 0
_081F6F84: .4byte 0x030046A4
_081F6F88:
	ldr r0, _081F6FA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F6F94:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F6FAC
	cmp r2, #2
	beq _081F6FB0
	b _081F6FB4
	.align 2, 0
_081F6FA8: .4byte 0x030046A4
_081F6FAC:
	ldrb r0, [r5, #4]
	b _081F6FB2
_081F6FB0:
	ldrb r0, [r5]
_081F6FB2:
	subs r1, r1, r0
_081F6FB4:
	add r0, sp, #0x2c
	strh r1, [r0, #2]
	movs r1, #1
	bl Entity081f73ec_SpawnDust
	ldr r4, _081F7004 @ =0x0203B400
	ldr r3, _081F7008 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081F700C @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r6, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	add r2, sp, #0x34
	adds r3, r0, #6
	ldr r1, _081F7010 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _081F7014
	asrs r1, r0, #0xc
	b _081F701A
	.align 2, 0
_081F7004: .4byte 0x0203B400
_081F7008: .4byte 0x030046B8
_081F700C: .4byte 0x000003FF
_081F7010: .4byte gSineTable
_081F7014:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F701A:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _081F7034 @ =gSineTable
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081F7038
	asrs r0, r0, #0xc
	b _081F703E
	.align 2, 0
_081F7034: .4byte gSineTable
_081F7038:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F703E:
	movs r4, #0
	strh r0, [r2, #4]
	ldr r2, _081F70A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081F70A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081F70AC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0x10
	strh r0, [r5, #2]
	ldr r2, _081F70B0 @ =0x00009D41
	ldr r3, _081F70B4 @ =0x0000E677
	movs r0, #2
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _081F70B8 @ =0x0000023D
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	add r0, sp, #0x2c
	adds r1, r5, #0
	bl Entity081efa9c_Spawn
_081F7088:
	movs r0, #0xdd
	lsls r0, r0, #3
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _081F70BC @ =0x000006D9
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F70C0
	subs r0, #1
	b _081F70F4
	.align 2, 0
_081F70A4: .4byte 0x030046B8
_081F70A8: .4byte 0x000003FF
_081F70AC: .4byte 0x0203B400
_081F70B0: .4byte 0x00009D41
_081F70B4: .4byte 0x0000E677
_081F70B8: .4byte 0x0000023D
_081F70BC: .4byte 0x000006D9
_081F70C0:
	ldr r1, _081F70D8 @ =0x000006E4
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081F70E0
	ldr r0, _081F70DC @ =0x0000019D
	bl PlaySound_082406e0
	b _081F70E6
	.align 2, 0
_081F70D8: .4byte 0x000006E4
_081F70DC: .4byte 0x0000019D
_081F70E0:
	ldr r0, _081F7100 @ =0x000003DA
	bl PlaySound_082406e0
_081F70E6:
	ldr r0, _081F7104 @ =0x000006E6
	adds r1, r7, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _081F7108 @ =0x000006EA
	adds r1, r7, r0
	movs r0, #1
_081F70F4:
	strb r0, [r1]
	add sp, #0x3c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F7100: .4byte 0x000003DA
_081F7104: .4byte 0x000006E6
_081F7108: .4byte 0x000006EA
