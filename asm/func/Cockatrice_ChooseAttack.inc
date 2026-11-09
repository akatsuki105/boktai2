	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	movs r1, #2
	movs r0, #0xe0
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815A6C8
	movs r0, #1
	b _0815A6CA
_0815A6C8:
	movs r0, #0
_0815A6CA:
	cmp r0, #0
	bne _0815A6D0
	b _0815ABAC
_0815A6D0:
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	mov sl, r0
	ldr r3, _0815A6F8 @ =0x00000256
	adds r4, r6, r3
	ldrh r7, [r4]
	adds r5, r6, #0
	adds r5, #8
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	str r4, [sp, #0x24]
	str r5, [sp, #0x1c]
	cmp r0, #0
	beq _0815A6FC
	adds r0, #4
	b _0815A708
	.align 2, 0
_0815A6F8: .4byte 0x00000256
_0815A6FC:
	ldr r0, _0815A71C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815A708:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815A720
	cmp r3, #2
	beq _0815A724
	b _0815A728
	.align 2, 0
_0815A71C: .4byte 0x030046A4
_0815A720:
	ldrb r0, [r5, #4]
	b _0815A726
_0815A724:
	ldrb r0, [r5]
_0815A726:
	subs r2, r2, r0
_0815A728:
	mov sb, r2
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815A73A
	adds r0, #4
	b _0815A746
_0815A73A:
	ldr r0, _0815A758 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815A746:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov r8, r0
	ldrb r0, [r6, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0815A75C
	asrs r0, r0, #6
	b _0815A762
	.align 2, 0
_0815A758: .4byte 0x030046A4
_0815A75C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0815A762:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0815A810
	cmp r1, #1
	bgt _0815A774
	cmp r1, #0
	beq _0815A782
	b _0815AA18
_0815A774:
	cmp r1, #2
	bne _0815A77A
	b _0815A8B8
_0815A77A:
	cmp r1, #3
	bne _0815A780
	b _0815A948
_0815A780:
	b _0815AA18
_0815A782:
	adds r5, r7, #1
	movs r4, #0
	movs r0, #0xd6
	lsls r0, r0, #3
	add sl, r0
	ldr r1, _0815A7F4 @ =0x0000046D
	adds r1, r6, r1
	str r1, [sp, #0x3c]
	ldr r2, _0815A7F8 @ =0x0000046B
	adds r2, r6, r2
	str r2, [sp, #0x34]
	ldr r3, _0815A7FC @ =0x00000553
	adds r3, r6, r3
	str r3, [sp, #0x18]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x20]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r6, r1
	str r1, [sp, #0x14]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x28]
	ldr r3, _0815A800 @ =0x00000469
	adds r3, r6, r3
	str r3, [sp, #0x2c]
	ldr r0, _0815A804 @ =0x0000046A
	adds r0, r6, r0
	str r0, [sp, #0x30]
	ldr r1, _0815A808 @ =0x00000484
	adds r1, r6, r1
	str r1, [sp, #0xc]
	ldr r2, _0815A80C @ =0x0000046C
	adds r2, r6, r2
	str r2, [sp, #0x38]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x10]
_0815A7D6:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815A7F0
	adds r5, #1
	adds r4, #1
	cmp r4, #2
	blt _0815A7D6
_0815A7F0:
	subs r5, #1
	b _0815AA6C
	.align 2, 0
_0815A7F4: .4byte 0x0000046D
_0815A7F8: .4byte 0x0000046B
_0815A7FC: .4byte 0x00000553
_0815A800: .4byte 0x00000469
_0815A804: .4byte 0x0000046A
_0815A808: .4byte 0x00000484
_0815A80C: .4byte 0x0000046C
_0815A810:
	ldr r1, _0815A898 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	adds r5, r7, r0
	movs r4, #0
	movs r0, #0xd6
	lsls r0, r0, #3
	add sl, r0
	ldr r2, _0815A89C @ =0x0000046D
	adds r2, r6, r2
	str r2, [sp, #0x3c]
	ldr r3, _0815A8A0 @ =0x0000046B
	adds r3, r6, r3
	str r3, [sp, #0x34]
	ldr r0, _0815A8A4 @ =0x00000553
	adds r0, r6, r0
	str r0, [sp, #0x18]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x20]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x14]
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x28]
	ldr r2, _0815A8A8 @ =0x00000469
	adds r2, r6, r2
	str r2, [sp, #0x2c]
	ldr r3, _0815A8AC @ =0x0000046A
	adds r3, r6, r3
	str r3, [sp, #0x30]
	ldr r0, _0815A8B0 @ =0x00000484
	adds r0, r6, r0
	str r0, [sp, #0xc]
	ldr r2, _0815A8B4 @ =0x0000046C
	adds r2, r6, r2
	str r2, [sp, #0x38]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x10]
_0815A86E:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815A882
	b _0815A9F0
_0815A882:
	ldr r0, _0815A898 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #2
	blt _0815A86E
	subs r5, r5, r0
	b _0815AA6C
	.align 2, 0
_0815A898: .4byte 0x030046A4
_0815A89C: .4byte 0x0000046D
_0815A8A0: .4byte 0x0000046B
_0815A8A4: .4byte 0x00000553
_0815A8A8: .4byte 0x00000469
_0815A8AC: .4byte 0x0000046A
_0815A8B0: .4byte 0x00000484
_0815A8B4: .4byte 0x0000046C
_0815A8B8:
	subs r5, r7, #1
	movs r4, #0
	movs r2, #0xd6
	lsls r2, r2, #3
	add sl, r2
	ldr r3, _0815A92C @ =0x0000046D
	adds r3, r6, r3
	str r3, [sp, #0x3c]
	ldr r0, _0815A930 @ =0x0000046B
	adds r0, r6, r0
	str r0, [sp, #0x34]
	ldr r1, _0815A934 @ =0x00000553
	adds r1, r6, r1
	str r1, [sp, #0x18]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x20]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x14]
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x28]
	ldr r1, _0815A938 @ =0x00000469
	adds r1, r6, r1
	str r1, [sp, #0x2c]
	ldr r2, _0815A93C @ =0x0000046A
	adds r2, r6, r2
	str r2, [sp, #0x30]
	ldr r3, _0815A940 @ =0x00000484
	adds r3, r6, r3
	str r3, [sp, #0xc]
	ldr r0, _0815A944 @ =0x0000046C
	adds r0, r6, r0
	str r0, [sp, #0x38]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r6, r1
	str r1, [sp, #0x10]
_0815A90C:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815A926
	subs r5, #1
	adds r4, #1
	cmp r4, #2
	blt _0815A90C
_0815A926:
	adds r5, #1
	b _0815AA6C
	.align 2, 0
_0815A92C: .4byte 0x0000046D
_0815A930: .4byte 0x0000046B
_0815A934: .4byte 0x00000553
_0815A938: .4byte 0x00000469
_0815A93C: .4byte 0x0000046A
_0815A940: .4byte 0x00000484
_0815A944: .4byte 0x0000046C
_0815A948:
	ldr r1, _0815A9D0 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r7, r0
	movs r4, #0
	movs r3, #0xd6
	lsls r3, r3, #3
	add sl, r3
	ldr r0, _0815A9D4 @ =0x0000046D
	adds r0, r6, r0
	str r0, [sp, #0x3c]
	ldr r2, _0815A9D8 @ =0x0000046B
	adds r2, r6, r2
	str r2, [sp, #0x34]
	ldr r3, _0815A9DC @ =0x00000553
	adds r3, r6, r3
	str r3, [sp, #0x18]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x20]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r2, r6, r2
	str r2, [sp, #0x14]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r6, r3
	str r3, [sp, #0x28]
	ldr r0, _0815A9E0 @ =0x00000469
	adds r0, r6, r0
	str r0, [sp, #0x2c]
	ldr r2, _0815A9E4 @ =0x0000046A
	adds r2, r6, r2
	str r2, [sp, #0x30]
	ldr r3, _0815A9E8 @ =0x00000484
	adds r3, r6, r3
	str r3, [sp, #0xc]
	ldr r0, _0815A9EC @ =0x0000046C
	adds r0, r6, r0
	str r0, [sp, #0x38]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r2, r6, r2
	str r2, [sp, #0x10]
_0815A9A6:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	mov r3, r8
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815AA04
	ldr r0, _0815A9D0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r5, r5, r0
	adds r4, #1
	cmp r4, #2
	blt _0815A9A6
	adds r5, r5, r0
	b _0815AA6C
	.align 2, 0
_0815A9D0: .4byte 0x030046A4
_0815A9D4: .4byte 0x0000046D
_0815A9D8: .4byte 0x0000046B
_0815A9DC: .4byte 0x00000553
_0815A9E0: .4byte 0x00000469
_0815A9E4: .4byte 0x0000046A
_0815A9E8: .4byte 0x00000484
_0815A9EC: .4byte 0x0000046C
_0815A9F0:
	ldr r1, _0815AA00 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r5, r5, r0
	b _0815AA6C
	.align 2, 0
_0815AA00: .4byte 0x030046A4
_0815AA04:
	ldr r1, _0815AA14 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	adds r5, r5, r0
	b _0815AA6C
	.align 2, 0
_0815AA14: .4byte 0x030046A4
_0815AA18:
	ldr r0, [sp, #0x24]
	ldrh r5, [r0]
	movs r1, #0xd6
	lsls r1, r1, #3
	add sl, r1
	ldr r2, _0815AAB0 @ =0x0000046D
	adds r2, r6, r2
	str r2, [sp, #0x3c]
	ldr r3, _0815AAB4 @ =0x0000046B
	adds r3, r6, r3
	str r3, [sp, #0x34]
	ldr r4, _0815AAB8 @ =0x00000553
	adds r4, r6, r4
	str r4, [sp, #0x18]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r7, r6, r7
	str r7, [sp, #0x20]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp, #0x14]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r6, r1
	str r1, [sp, #0x28]
	ldr r2, _0815AABC @ =0x00000469
	adds r2, r6, r2
	str r2, [sp, #0x2c]
	ldr r3, _0815AAC0 @ =0x0000046A
	adds r3, r6, r3
	str r3, [sp, #0x30]
	ldr r4, _0815AAC4 @ =0x00000484
	adds r4, r6, r4
	str r4, [sp, #0xc]
	ldr r7, _0815AAC8 @ =0x0000046C
	adds r7, r6, r7
	str r7, [sp, #0x38]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp, #0x10]
_0815AA6C:
	ldr r1, [sp, #0x24]
	ldrh r1, [r1]
	cmp r5, r1
	bne _0815AAD0
	mov r7, sl
	ldr r2, _0815AACC @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0815AACC @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	bne _0815AB08
	b _0815AB10
	.align 2, 0
_0815AAB0: .4byte 0x0000046D
_0815AAB4: .4byte 0x0000046B
_0815AAB8: .4byte 0x00000553
_0815AABC: .4byte 0x00000469
_0815AAC0: .4byte 0x0000046A
_0815AAC4: .4byte 0x00000484
_0815AAC8: .4byte 0x0000046C
_0815AACC: .4byte 0x030046A4
_0815AAD0:
	mov r7, sl
	ldr r1, _0815AB0C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _0815AB0C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815AB10
_0815AB08:
	adds r0, #4
	b _0815AB1C
	.align 2, 0
_0815AB0C: .4byte 0x030046A4
_0815AB10:
	ldr r3, _0815ABA0 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815AB1C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r7, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	ldr r2, _0815ABA4 @ =Cockatrice_StateJumpDown
	movs r0, #0x2a
	movs r1, #0
	movs r3, #1
	ldr r5, [sp, #0x3c]
	strb r3, [r5]
	ldr r7, [sp, #0x34]
	strb r1, [r7]
	ldr r4, [sp, #0x18]
	strb r0, [r4]
	ldr r5, [sp, #0x20]
	str r2, [r5]
	movs r4, #0
	ldr r7, [sp, #0x14]
	strh r1, [r7]
	movs r0, #3
	ldr r2, [sp, #0x28]
	strb r0, [r2]
	ldr r5, [sp, #0x2c]
	strb r4, [r5]
	ldr r7, [sp, #0x30]
	strb r4, [r7]
	ldr r0, [sp, #0xc]
	str r1, [r0]
	ldr r1, [sp, #0x38]
	strb r3, [r1]
	ldr r0, _0815ABA8 @ =0x03002BE0
	mov r2, sp
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldr r4, [sp, #0x1c]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r7, #4
	ldrsh r1, [r2, r7]
	bl ArcTan2_8
	strb r0, [r6, #5]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, [sp, #0x10]
	b _0815B174
	.align 2, 0
_0815ABA0: .4byte 0x030046A4
_0815ABA4: .4byte Cockatrice_StateJumpDown
_0815ABA8: .4byte 0x03002BE0
_0815ABAC:
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r1, [r0]
	adds r1, #0x20
	movs r2, #0xff
	ands r1, r2
	asrs r1, r1, #6
	ldrb r0, [r6, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #6
	cmp r1, #0x80
	ble _0815ABD8
	ldr r4, _0815ABD4 @ =0xFFFFFF00
	adds r1, r1, r4
	b _0815ABE6
	.align 2, 0
_0815ABD4: .4byte 0xFFFFFF00
_0815ABD8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0815ABE6
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_0815ABE6:
	cmp r1, #0
	bge _0815ABEC
	rsbs r1, r1, #0
_0815ABEC:
	cmp r1, #0x17
	ble _0815ABF2
	b _0815B198
_0815ABF2:
	movs r7, #0xf2
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r1, #0xda
	lsls r1, r1, #3
	add r1, r8
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _0815AC08
	b _0815B0F8
_0815AC08:
	ldr r1, _0815AC48 @ =0x000006E4
	add r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _0815AC16
	b _0815B288
_0815AC16:
	movs r0, #0xde
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r1]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r5, _0815AC4C @ =0x00000256
	adds r4, r6, r5
	ldrh r7, [r4]
	adds r5, r6, #0
	adds r5, #8
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	str r4, [sp, #0x24]
	cmp r0, #0
	beq _0815AC50
	adds r0, #4
	b _0815AC5C
	.align 2, 0
_0815AC48: .4byte 0x000006E4
_0815AC4C: .4byte 0x00000256
_0815AC50:
	ldr r0, _0815AC70 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815AC5C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815AC74
	cmp r3, #2
	beq _0815AC78
	b _0815AC7C
	.align 2, 0
_0815AC70: .4byte 0x030046A4
_0815AC74:
	ldrb r0, [r5, #4]
	b _0815AC7A
_0815AC78:
	ldrb r0, [r5]
_0815AC7A:
	subs r2, r2, r0
_0815AC7C:
	mov sl, r2
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815AC8E
	adds r0, #4
	b _0815AC9A
_0815AC8E:
	ldr r0, _0815ACAC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815AC9A:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sb, r0
	ldrb r0, [r6, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0815ACB0
	asrs r0, r0, #6
	b _0815ACB6
	.align 2, 0
_0815ACAC: .4byte 0x030046A4
_0815ACB0:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0815ACB6:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0815AD6C
	cmp r1, #1
	bgt _0815ACC8
	cmp r1, #0
	beq _0815ACD6
	b _0815AF8C
_0815ACC8:
	cmp r1, #2
	bne _0815ACCE
	b _0815AE1C
_0815ACCE:
	cmp r1, #3
	bne _0815ACD4
	b _0815AEB4
_0815ACD4:
	b _0815AF8C
_0815ACD6:
	adds r5, r7, #1
	movs r4, #0
	movs r0, #0xe0
	lsls r0, r0, #3
	add r8, r0
	ldr r1, _0815AD50 @ =0x0000046D
	adds r1, r6, r1
	str r1, [sp, #0x3c]
	ldr r2, _0815AD54 @ =0x0000046B
	adds r2, r6, r2
	str r2, [sp, #0x34]
	ldr r3, _0815AD58 @ =0x00000553
	adds r3, r6, r3
	str r3, [sp, #0x18]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x20]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r6, r1
	str r1, [sp, #0x14]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x28]
	ldr r3, _0815AD5C @ =0x00000469
	adds r3, r6, r3
	str r3, [sp, #0x2c]
	ldr r0, _0815AD60 @ =0x0000046A
	adds r0, r6, r0
	str r0, [sp, #0x30]
	ldr r1, _0815AD64 @ =0x00000484
	adds r1, r6, r1
	str r1, [sp, #0xc]
	ldr r2, _0815AD68 @ =0x0000046C
	adds r2, r6, r2
	str r2, [sp, #0x38]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x10]
	ldr r0, [sp, #8]
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r6, r0, r1
_0815AD32:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sl
	mov r3, sb
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815AD4C
	adds r5, #1
	adds r4, #1
	cmp r4, #2
	blt _0815AD32
_0815AD4C:
	subs r5, #1
	b _0815AFE8
	.align 2, 0
_0815AD50: .4byte 0x0000046D
_0815AD54: .4byte 0x0000046B
_0815AD58: .4byte 0x00000553
_0815AD5C: .4byte 0x00000469
_0815AD60: .4byte 0x0000046A
_0815AD64: .4byte 0x00000484
_0815AD68: .4byte 0x0000046C
_0815AD6C:
	ldr r1, _0815ADFC @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r7, r0
	movs r4, #0
	movs r3, #0xe0
	lsls r3, r3, #3
	add r8, r3
	ldr r0, _0815AE00 @ =0x0000046D
	adds r0, r6, r0
	str r0, [sp, #0x3c]
	ldr r2, _0815AE04 @ =0x0000046B
	adds r2, r6, r2
	str r2, [sp, #0x34]
	ldr r3, _0815AE08 @ =0x00000553
	adds r3, r6, r3
	str r3, [sp, #0x18]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x20]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r2, r6, r2
	str r2, [sp, #0x14]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r6, r3
	str r3, [sp, #0x28]
	ldr r0, _0815AE0C @ =0x00000469
	adds r0, r6, r0
	str r0, [sp, #0x2c]
	ldr r2, _0815AE10 @ =0x0000046A
	adds r2, r6, r2
	str r2, [sp, #0x30]
	ldr r3, _0815AE14 @ =0x00000484
	adds r3, r6, r3
	str r3, [sp, #0xc]
	ldr r0, _0815AE18 @ =0x0000046C
	adds r0, r6, r0
	str r0, [sp, #0x38]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r2, r6, r2
	str r2, [sp, #0x10]
	ldr r3, [sp, #8]
	movs r0, #0xd6
	lsls r0, r0, #3
	adds r6, r3, r0
_0815ADD2:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sl
	mov r3, sb
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815ADE6
	b _0815AF64
_0815ADE6:
	ldr r0, _0815ADFC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #2
	blt _0815ADD2
	subs r5, r5, r0
	b _0815AFE8
	.align 2, 0
_0815ADFC: .4byte 0x030046A4
_0815AE00: .4byte 0x0000046D
_0815AE04: .4byte 0x0000046B
_0815AE08: .4byte 0x00000553
_0815AE0C: .4byte 0x00000469
_0815AE10: .4byte 0x0000046A
_0815AE14: .4byte 0x00000484
_0815AE18: .4byte 0x0000046C
_0815AE1C:
	subs r5, r7, #1
	movs r4, #0
	movs r2, #0xe0
	lsls r2, r2, #3
	add r8, r2
	ldr r3, _0815AE98 @ =0x0000046D
	adds r3, r6, r3
	str r3, [sp, #0x3c]
	ldr r0, _0815AE9C @ =0x0000046B
	adds r0, r6, r0
	str r0, [sp, #0x34]
	ldr r1, _0815AEA0 @ =0x00000553
	adds r1, r6, r1
	str r1, [sp, #0x18]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x20]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x14]
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x28]
	ldr r1, _0815AEA4 @ =0x00000469
	adds r1, r6, r1
	str r1, [sp, #0x2c]
	ldr r2, _0815AEA8 @ =0x0000046A
	adds r2, r6, r2
	str r2, [sp, #0x30]
	ldr r3, _0815AEAC @ =0x00000484
	adds r3, r6, r3
	str r3, [sp, #0xc]
	ldr r0, _0815AEB0 @ =0x0000046C
	adds r0, r6, r0
	str r0, [sp, #0x38]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r6, r1
	str r1, [sp, #0x10]
	ldr r2, [sp, #8]
	movs r3, #0xd6
	lsls r3, r3, #3
	adds r6, r2, r3
_0815AE78:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sl
	mov r3, sb
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815AE92
	subs r5, #1
	adds r4, #1
	cmp r4, #2
	blt _0815AE78
_0815AE92:
	adds r5, #1
	b _0815AFE8
	.align 2, 0
_0815AE98: .4byte 0x0000046D
_0815AE9C: .4byte 0x0000046B
_0815AEA0: .4byte 0x00000553
_0815AEA4: .4byte 0x00000469
_0815AEA8: .4byte 0x0000046A
_0815AEAC: .4byte 0x00000484
_0815AEB0: .4byte 0x0000046C
_0815AEB4:
	ldr r1, _0815AF44 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r5, r7, r0
	movs r4, #0
	movs r0, #0xe0
	lsls r0, r0, #3
	add r8, r0
	ldr r2, _0815AF48 @ =0x0000046D
	adds r2, r6, r2
	str r2, [sp, #0x3c]
	ldr r3, _0815AF4C @ =0x0000046B
	adds r3, r6, r3
	str r3, [sp, #0x34]
	ldr r0, _0815AF50 @ =0x00000553
	adds r0, r6, r0
	str r0, [sp, #0x18]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x20]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x14]
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x28]
	ldr r2, _0815AF54 @ =0x00000469
	adds r2, r6, r2
	str r2, [sp, #0x2c]
	ldr r3, _0815AF58 @ =0x0000046A
	adds r3, r6, r3
	str r3, [sp, #0x30]
	ldr r0, _0815AF5C @ =0x00000484
	adds r0, r6, r0
	str r0, [sp, #0xc]
	ldr r2, _0815AF60 @ =0x0000046C
	adds r2, r6, r2
	str r2, [sp, #0x38]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x10]
	ldr r0, [sp, #8]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r6, r0, r2
_0815AF1A:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sl
	mov r3, sb
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815AF78
	ldr r0, _0815AF44 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r5, r5, r0
	adds r4, #1
	cmp r4, #2
	blt _0815AF1A
	adds r5, r5, r0
	b _0815AFE8
	.align 2, 0
_0815AF44: .4byte 0x030046A4
_0815AF48: .4byte 0x0000046D
_0815AF4C: .4byte 0x0000046B
_0815AF50: .4byte 0x00000553
_0815AF54: .4byte 0x00000469
_0815AF58: .4byte 0x0000046A
_0815AF5C: .4byte 0x00000484
_0815AF60: .4byte 0x0000046C
_0815AF64:
	ldr r1, _0815AF74 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r5, r5, r0
	b _0815AFE8
	.align 2, 0
_0815AF74: .4byte 0x030046A4
_0815AF78:
	ldr r1, _0815AF88 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	adds r5, r5, r0
	b _0815AFE8
	.align 2, 0
_0815AF88: .4byte 0x030046A4
_0815AF8C:
	ldr r0, [sp, #0x24]
	ldrh r5, [r0]
	movs r1, #0xe0
	lsls r1, r1, #3
	add r8, r1
	ldr r2, _0815B028 @ =0x0000046D
	adds r2, r6, r2
	str r2, [sp, #0x3c]
	ldr r3, _0815B02C @ =0x0000046B
	adds r3, r6, r3
	str r3, [sp, #0x34]
	ldr r4, _0815B030 @ =0x00000553
	adds r4, r6, r4
	str r4, [sp, #0x18]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r7, r6, r7
	str r7, [sp, #0x20]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp, #0x14]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r6, r1
	str r1, [sp, #0x28]
	ldr r2, _0815B034 @ =0x00000469
	adds r2, r6, r2
	str r2, [sp, #0x2c]
	ldr r3, _0815B038 @ =0x0000046A
	adds r3, r6, r3
	str r3, [sp, #0x30]
	ldr r4, _0815B03C @ =0x00000484
	adds r4, r6, r4
	str r4, [sp, #0xc]
	ldr r7, _0815B040 @ =0x0000046C
	adds r7, r6, r7
	str r7, [sp, #0x38]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp, #0x10]
	ldr r1, [sp, #8]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r6, r1, r2
_0815AFE8:
	ldr r3, [sp, #0x24]
	ldrh r3, [r3]
	cmp r5, r3
	bne _0815B048
	ldr r4, _0815B044 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0815B044 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	bne _0815B07E
	b _0815B088
	.align 2, 0
_0815B028: .4byte 0x0000046D
_0815B02C: .4byte 0x0000046B
_0815B030: .4byte 0x00000553
_0815B034: .4byte 0x00000469
_0815B038: .4byte 0x0000046A
_0815B03C: .4byte 0x00000484
_0815B040: .4byte 0x0000046C
_0815B044: .4byte 0x030046A4
_0815B048:
	ldr r4, _0815B084 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0815B084 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815B088
_0815B07E:
	adds r0, #4
	b _0815B094
	.align 2, 0
_0815B084: .4byte 0x030046A4
_0815B088:
	ldr r3, _0815B0F0 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815B094:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r2, _0815B0F4 @ =Cockatrice_StatePrepareJump
	movs r0, #0x21
	movs r1, #0
	movs r3, #1
	ldr r4, [sp, #0x3c]
	strb r3, [r4]
	ldr r5, [sp, #0x34]
	strb r1, [r5]
	ldr r7, [sp, #0x18]
	strb r0, [r7]
	ldr r0, [sp, #0x20]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x14]
	strh r1, [r4]
	movs r0, #3
	ldr r5, [sp, #0x28]
	strb r0, [r5]
	ldr r7, [sp, #0x2c]
	strb r2, [r7]
	ldr r0, [sp, #0x30]
	strb r2, [r0]
	ldr r2, [sp, #0xc]
	str r1, [r2]
	ldr r4, [sp, #0x38]
	strb r3, [r4]
	mov r5, r8
	ldr r0, [r5]
	orrs r0, r3
	str r0, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r7, [sp, #0x10]
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	b _0815B288
	.align 2, 0
_0815B0F0: .4byte 0x030046A4
_0815B0F4: .4byte Cockatrice_StatePrepareJump
_0815B0F8:
	ldr r1, _0815B17C @ =0x000006E2
	add r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _0815B106
	b _0815B288
_0815B106:
	ldr r0, _0815B180 @ =0x000006F2
	add r0, r8
	ldrh r0, [r0]
	movs r4, #0
	movs r5, #0
	strh r0, [r1]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	adds r0, #0x20
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r6, #5]
	ldr r3, _0815B184 @ =Cockatrice_StateFire
	movs r1, #0x30
	ldr r7, _0815B188 @ =0x0000046D
	adds r0, r6, r7
	movs r2, #1
	strb r2, [r0]
	subs r7, #2
	adds r0, r6, r7
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
	strh r5, [r0]
	movs r1, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r4, [r0]
	ldr r3, _0815B18C @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, _0815B190 @ =0x0000046A
	adds r0, r6, r4
	strb r2, [r0]
	adds r7, #0x1c
	adds r0, r6, r7
	str r5, [r0]
	ldr r1, _0815B194 @ =0x0000046C
	adds r0, r6, r1
	strb r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
_0815B174:
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _0815B288
	.align 2, 0
_0815B17C: .4byte 0x000006E2
_0815B180: .4byte 0x000006F2
_0815B184: .4byte Cockatrice_StateFire
_0815B188: .4byte 0x0000046D
_0815B18C: .4byte 0x00000469
_0815B190: .4byte 0x0000046A
_0815B194: .4byte 0x0000046C
_0815B198:
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r5, _0815B22C @ =0x0000046D
	adds r0, r6, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _0815B230 @ =0x0000046B
	adds r0, r6, r7
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r6, r5
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #0xeb
	adds r0, r6, r5
	strb r1, [r0]
	ldr r7, _0815B234 @ =0x00000469
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0815B238 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _0815B23C @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r4, [r0]
	adds r7, #0x19
	adds r1, r6, r7
	movs r0, #2
	strh r0, [r1]
	movs r0, #4
	ldr r1, _0815B240 @ =0x00000222
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0815B244 @ =0x000004A4
	adds r0, r6, r2
	ldr r5, [r0]
	adds r7, r6, #0
	adds r7, #8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0815B248
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r6, r4
	b _0815B26E
	.align 2, 0
_0815B22C: .4byte 0x0000046D
_0815B230: .4byte 0x0000046B
_0815B234: .4byte 0x00000469
_0815B238: .4byte 0x0000046A
_0815B23C: .4byte 0x00000484
_0815B240: .4byte 0x00000222
_0815B244: .4byte 0x000004A4
_0815B248:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0815B268
	cmp r0, #2
	beq _0815B264
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815B264:
	movs r0, #1
	b _0815B278
_0815B268:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r6, r5
_0815B26E:
	ldr r1, _0815B298 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0815B278:
	cmp r0, #0
	bne _0815B288
	ldr r7, _0815B29C @ =0x000005C4
	adds r0, r6, r7
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_0815B288:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815B298: .4byte 0xFFFFFDFF
_0815B29C: .4byte 0x000005C4
