	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _081C0AD0 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C0AD4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C0AD6
	.align 2, 0
_081C0AD0: .4byte 0x0000046C
_081C0AD4:
	movs r0, #0
_081C0AD6:
	cmp r0, #0
	beq _081C0AE2
	ldr r3, _081C0B14 @ =0x0000046B
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
_081C0AE2:
	adds r0, r6, #0
	bl GolemLink_TryChaseHitTarget
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C0AF0
	b _081C105E
_081C0AF0:
	ldr r4, _081C0B14 @ =0x0000046B
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C0AFC
	b _081C1054
_081C0AFC:
	adds r3, r7, #0
	ldr r0, _081C0B18 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #7
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	beq _081C0B1C
	movs r0, #1
	b _081C0B1E
	.align 2, 0
_081C0B14: .4byte 0x0000046B
_081C0B18: .4byte 0x030047A4
_081C0B1C:
	movs r0, #0
_081C0B1E:
	cmp r0, #0
	beq _081C0B4C
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C0B5C
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C0B3A
	adds r2, r0, #0
_081C0B3A:
	cmp r2, #0
	blt _081C0B5C
	ldr r1, _081C0B48 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _081C0B4E
	.align 2, 0
_081C0B48: .4byte 0x03002BE0
_081C0B4C:
	ldr r0, _081C0BB4 @ =0x03002BE0
_081C0B4E:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C0B9A
_081C0B5C:
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C0B9A
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xf
	subs r0, r0, r1
	cmp r0, #0
	bge _081C0B80
	movs r0, #0
_081C0B80:
	ldr r2, _081C0BB8 @ =0x000006BC
	adds r1, r7, r2
	asrs r0, r0, #0x10
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _081C0B9A
	strh r2, [r1]
_081C0B9A:
	ldr r0, _081C0BBC @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C0BC0
	movs r0, #1
	b _081C0BC2
	.align 2, 0
_081C0BB4: .4byte 0x03002BE0
_081C0BB8: .4byte 0x000006BC
_081C0BBC: .4byte 0x000006B4
_081C0BC0:
	movs r0, #0
_081C0BC2:
	adds r5, r0, #0
	cmp r5, #0
	beq _081C0C40
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C0CBC
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C0BE0
	adds r2, r0, #0
_081C0BE0:
	cmp r2, #0
	blt _081C0CBC
	ldr r1, _081C0C2C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081C0CBC
	ldr r2, _081C0C30 @ =GolemLink_StateUncurl
	movs r1, #0x26
	ldr r3, _081C0C34 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081C0C38 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _081C0C3C @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #3
	b _081C0E68
	.align 2, 0
_081C0C2C: .4byte 0x03002BE0
_081C0C30: .4byte GolemLink_StateUncurl
_081C0C34: .4byte 0x0000046D
_081C0C38: .4byte 0x0000046B
_081C0C3C: .4byte 0x00000553
_081C0C40:
	ldr r0, _081C0CA0 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081C0CBC
	ldr r2, _081C0CA4 @ =GolemLink_StateUncurl
	movs r1, #0x26
	ldr r3, _081C0CA8 @ =0x0000046D
	adds r0, r6, r3
	movs r4, #1
	strb r4, [r0]
	ldr r7, _081C0CAC @ =0x0000046B
	adds r0, r6, r7
	strb r5, [r0]
	adds r3, #0xe6
	adds r0, r6, r3
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r5, [r0]
	movs r2, #2
	movs r3, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081C0CB0 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081C0CB4 @ =0x0000046A
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _081C0CB8 @ =0x00000484
	adds r0, r6, r3
	str r5, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r4, [r0]
	b _081C105E
	.align 2, 0
_081C0CA0: .4byte 0x03002BE0
_081C0CA4: .4byte GolemLink_StateUncurl
_081C0CA8: .4byte 0x0000046D
_081C0CAC: .4byte 0x0000046B
_081C0CB0: .4byte 0x00000469
_081C0CB4: .4byte 0x0000046A
_081C0CB8: .4byte 0x00000484
_081C0CBC:
	ldr r1, _081C0CF4 @ =0x000006B4
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _081C0DBC
	adds r3, r7, #0
	adds r4, r7, #0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081C0D78
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081C0D00
	ldr r1, _081C0CF8 @ =0x000006BC
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r0, _081C0CFC @ =0x0000018F
	cmp r1, r0
	bls _081C0D0C
	b _081C0D10
	.align 2, 0
_081C0CF4: .4byte 0x000006B4
_081C0CF8: .4byte 0x000006BC
_081C0CFC: .4byte 0x0000018F
_081C0D00:
	ldr r1, _081C0D64 @ =0x000006BC
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _081C0D0C
	movs r2, #1
_081C0D0C:
	cmp r2, #0
	beq _081C0D44
_081C0D10:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r7, #0xf6
	lsls r7, r7, #1
	adds r1, r3, r7
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081C0D44
	adds r0, r4, #0
	adds r0, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r1, [r1]
	adds r1, #8
	movs r2, #0xa
	movs r3, #0x80
	lsls r3, r3, #1
	bl Map_HasLineOfSight
	lsls r0, r0, #0x18
	movs r1, #1
	cmp r0, #0
	bne _081C0D46
_081C0D44:
	movs r1, #0
_081C0D46:
	cmp r1, #0
	beq _081C0D78
	ldr r2, _081C0D68 @ =GolemLink_StateCharge
	movs r1, #0x27
	ldr r3, _081C0D6C @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081C0D70 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _081C0D74 @ =0x00000553
	b _081C0E4E
	.align 2, 0
_081C0D64: .4byte 0x000006BC
_081C0D68: .4byte GolemLink_StateCharge
_081C0D6C: .4byte 0x0000046D
_081C0D70: .4byte 0x0000046B
_081C0D74: .4byte 0x00000553
_081C0D78:
	ldr r2, _081C0DAC @ =GolemLink_StateUncurl
	movs r1, #0x26
	ldr r3, _081C0DB0 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081C0DB4 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _081C0DB8 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #3
	b _081C0E68
	.align 2, 0
_081C0DAC: .4byte GolemLink_StateUncurl
_081C0DB0: .4byte 0x0000046D
_081C0DB4: .4byte 0x0000046B
_081C0DB8: .4byte 0x00000553
_081C0DBC:
	adds r3, r7, #0
	adds r4, r7, #0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081C0EA4
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081C0DF0
	ldr r1, _081C0DE8 @ =0x000006BC
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r0, _081C0DEC @ =0x0000018F
	cmp r1, r0
	bls _081C0DFC
	b _081C0E00
	.align 2, 0
_081C0DE8: .4byte 0x000006BC
_081C0DEC: .4byte 0x0000018F
_081C0DF0:
	ldr r1, _081C0E88 @ =0x000006BC
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _081C0DFC
	movs r2, #1
_081C0DFC:
	cmp r2, #0
	beq _081C0E32
_081C0E00:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r3, r2
	adds r2, #8
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081C0E32
	adds r0, r4, #0
	adds r0, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r1, [r1]
	adds r1, #8
	movs r2, #0xa
	movs r3, #0x80
	lsls r3, r3, #1
	bl Map_HasLineOfSight
	lsls r0, r0, #0x18
	movs r1, #1
	cmp r0, #0
	bne _081C0E34
_081C0E32:
	movs r1, #0
_081C0E34:
	cmp r1, #0
	beq _081C0EA4
	ldr r2, _081C0E8C @ =GolemLink_StateCharge
	movs r1, #0x27
	ldr r7, _081C0E90 @ =0x0000046D
	adds r0, r6, r7
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081C0E94 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	adds r7, #0xe6
_081C0E4E:
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #4
_081C0E68:
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081C0E98 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081C0E9C @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081C0EA0 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081C105E
	.align 2, 0
_081C0E88: .4byte 0x000006BC
_081C0E8C: .4byte GolemLink_StateCharge
_081C0E90: .4byte 0x0000046D
_081C0E94: .4byte 0x0000046B
_081C0E98: .4byte 0x00000469
_081C0E9C: .4byte 0x0000046A
_081C0EA0: .4byte 0x00000484
_081C0EA4:
	ldr r1, _081C0EEC @ =0x00000256
	adds r0, r6, r1
	ldrh r5, [r0]
	mov sl, sp
	ldr r2, _081C0EF0 @ =0x030046A4
	mov r8, r2
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C0EF4
	adds r0, #4
	b _081C0F00
	.align 2, 0
_081C0EEC: .4byte 0x00000256
_081C0EF0: .4byte 0x030046A4
_081C0EF4:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C0F00:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r4, #0
	mov r8, r4
	mov r1, sl
	strh r0, [r1, #2]
	mov r2, sb
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	mov r5, sp
	mov r0, sp
	bl GolemLink_SnapToTileCenter
	add r3, sp, #8
	adds r4, r6, #0
	adds r4, #8
	ldrh r0, [r6, #8]
	mov r1, sp
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _081C0F8C @ =0x00000FFF
	cmp r1, r0
	bgt _081C0FA0
	adds r0, r7, #0
	bl GolemLink_RouteTo
	movs r1, #2
	movs r2, #6
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	mov r4, r8
	strb r4, [r0]
	ldr r7, _081C0F90 @ =0x00000469
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081C0F94 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081C0F98 @ =0x00000484
	adds r0, r6, r2
	movs r3, #0
	str r3, [r0]
	ldr r4, _081C0F9C @ =0x0000046C
	adds r1, r6, r4
	movs r0, #1
	strb r0, [r1]
	b _081C105E
	.align 2, 0
_081C0F8C: .4byte 0x00000FFF
_081C0F90: .4byte 0x00000469
_081C0F94: .4byte 0x0000046A
_081C0F98: .4byte 0x00000484
_081C0F9C: .4byte 0x0000046C
_081C0FA0:
	ldr r1, _081C1038 @ =0x000004A4
	adds r0, r6, r1
	ldr r2, [r0]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r5, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	movs r4, #4
	ldrsh r1, [r3, r4]
	bl ArcTan2_8
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r6, #5]
	ldr r2, _081C103C @ =0x000006C2
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _081C1040 @ =GolemLink_StateRoll
	movs r1, #0x22
	ldr r4, _081C1044 @ =0x0000046D
	adds r0, r6, r4
	movs r2, #1
	strb r2, [r0]
	ldr r7, _081C1048 @ =0x0000046B
	adds r0, r6, r7
	mov r4, r8
	strb r4, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r4, #0
	strh r4, [r0]
	movs r1, #2
	subs r7, #0xeb
	adds r0, r6, r7
	mov r3, r8
	strb r3, [r0]
	ldr r4, _081C104C @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _081C1050 @ =0x00000484
	adds r0, r6, r1
	movs r3, #0
	str r3, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r2, [r0]
	b _081C105E
	.align 2, 0
_081C1038: .4byte 0x000004A4
_081C103C: .4byte 0x000006C2
_081C1040: .4byte GolemLink_StateRoll
_081C1044: .4byte 0x0000046D
_081C1048: .4byte 0x0000046B
_081C104C: .4byte 0x00000469
_081C1050: .4byte 0x00000484
_081C1054:
	ldr r7, _081C1070 @ =0x00000484
	adds r1, r6, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081C105E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C1070: .4byte 0x00000484
