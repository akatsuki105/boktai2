	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	ldr r1, _080E1998 @ =0x0000046F
	adds r0, r5, r1
	movs r3, #1
	strb r3, [r0]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r3
	cmp r0, #0
	beq _080E194E
	movs r0, #0x40
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080E194E:
	ldr r0, _080E199C @ =0x0000046E
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #1
	bne _080E195A
	b _080E1A86
_080E195A:
	ldr r1, _080E19A0 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E1966
	b _080E1A64
_080E1966:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x48]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080E19A4
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080E19AC
	.align 2, 0
_080E1998: .4byte 0x0000046F
_080E199C: .4byte 0x0000046E
_080E19A0: .4byte 0x0000025D
_080E19A4:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080E19AC:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080E19D0
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080E19D8
_080E19D0:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080E19D8:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080E1A10 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080E1A56
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080E1A1A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080E1A14
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080E1A30
	.align 2, 0
_080E1A10: .4byte 0x0000FFFF
_080E1A14:
	subs r0, #1
	strh r0, [r4, #8]
	b _080E1A2E
_080E1A1A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080E1A2E
	strh r1, [r4, #8]
	movs r2, #1
	b _080E1A30
_080E1A2E:
	movs r2, #0
_080E1A30:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E1A58
	movs r0, #1
	strb r0, [r4, #7]
	b _080E1A58
_080E1A56:
	movs r2, #0
_080E1A58:
	ldr r3, _080E1A60 @ =0x0000046E
	adds r0, r5, r3
	strb r2, [r0]
	b _080E1A86
	.align 2, 0
_080E1A60: .4byte 0x0000046E
_080E1A64:
	ldr r1, [r5, #0x44]
	adds r4, r1, #0
	adds r4, #0x20
	adds r0, r4, #0
	str r3, [sp, #0x1c]
	bl FUN_082372cc
	adds r2, r0, #0
	ldrb r1, [r4, #0x1d]
	ldr r3, [sp, #0x1c]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _080E1A84
	cmp r2, #0
	beq _080E1A86
_080E1A84:
	strb r3, [r6]
_080E1A86:
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E1A94
	b _080E1F2C
_080E1A94:
	adds r0, r5, #0
	bl FUN_080e4b3c
	movs r2, #0x80
	lsls r2, r2, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r0, [r1]
	ands r0, r2
	str r1, [sp, #0x14]
	cmp r0, #0
	beq _080E1AD0
	movs r1, #0x20
	ldr r2, _080E1AC0 @ =0x00000474
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E1AC4
	movs r0, #1
	b _080E1AC6
	.align 2, 0
_080E1AC0: .4byte 0x00000474
_080E1AC4:
	movs r0, #0
_080E1AC6:
	cmp r0, #0
	bne _080E1AD0
	adds r0, r5, #0
	adds r0, #0x8c
	b _080E1AD2
_080E1AD0:
	movs r0, #0
_080E1AD2:
	str r0, [r5, #0x18]
	movs r3, #0x10
	ldrsh r0, [r5, r3]
	cmp r0, #0
	bne _080E1AE4
	movs r4, #0x14
	ldrsh r0, [r5, r4]
	cmp r0, #0
	beq _080E1AF8
_080E1AE4:
	movs r0, #0x80
	lsls r0, r0, #6
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r2, [r1]
	orrs r0, r2
	strh r0, [r1]
	mov sl, r1
	b _080E1B2E
_080E1AF8:
	ldr r3, _080E1B40 @ =0x000004AC
	adds r0, r5, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r2, #8
	ldrsh r0, [r5, r2]
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r3, r3, r5
	mov sl, r3
	cmp r1, r0
	bne _080E1B2E
	movs r4, #0x96
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xc
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _080E1B2E
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
_080E1B2E:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080E1B44
	movs r0, #1
	b _080E1B46
	.align 2, 0
_080E1B40: .4byte 0x000004AC
_080E1B44:
	movs r0, #0
_080E1B46:
	cmp r0, #0
	beq _080E1B50
	adds r0, r5, #0
	bl FUN_0823b4b8
_080E1B50:
	ldr r3, _080E1B8C @ =0x00000256
	adds r0, r5, r3
	ldrh r1, [r0]
	movs r4, #0x96
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #8
	ldrh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	str r1, [sp, #0x10]
	cmp r3, #0
	blt _080E1B88
	cmp r2, #0
	blt _080E1B88
	ldr r0, _080E1B90 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080E1B88
	ldr r0, _080E1B94 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _080E1B98
_080E1B88:
	movs r1, #0
	b _080E1BA6
	.align 2, 0
_080E1B8C: .4byte 0x00000256
_080E1B90: .4byte 0x030046A8
_080E1B94: .4byte 0x030046AC
_080E1B98:
	ldr r0, _080E1BC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r3
_080E1BA6:
	ldr r2, _080E1BC8 @ =0x00000256
	adds r0, r5, r2
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_080e4e20
	movs r1, #0x80
	lsls r1, r1, #6
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _080E1BCC
	movs r0, #1
	b _080E1BCE
	.align 2, 0
_080E1BC4: .4byte 0x030046A4
_080E1BC8: .4byte 0x00000256
_080E1BCC:
	movs r0, #0
_080E1BCE:
	ldr r4, _080E1C00 @ =0x000001DF
	adds r4, r5, r4
	str r4, [sp, #0x18]
	cmp r0, #0
	bne _080E1BDA
	b _080E1E78
_080E1BDA:
	ldr r1, _080E1C04 @ =0x00000256
	adds r0, r5, r1
	movs r3, #0x96
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r1, [r0]
	adds r6, r0, #0
	ldrh r2, [r2]
	cmp r1, r2
	bne _080E1BF0
	b _080E1E78
_080E1BF0:
	ldrb r0, [r4]
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080E1C08
	movs r0, #1
	b _080E1C0A
	.align 2, 0
_080E1C00: .4byte 0x000001DF
_080E1C04: .4byte 0x00000256
_080E1C08:
	movs r0, #0
_080E1C0A:
	cmp r0, #0
	beq _080E1C10
	b _080E1E78
_080E1C10:
	ldr r4, [sp, #0x18]
	ldrb r0, [r4]
	cmp r0, #0x1a
	bne _080E1C1A
	b _080E1E78
_080E1C1A:
	ldrh r4, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E1C2C
	adds r0, #4
	b _080E1C38
_080E1C2C:
	ldr r0, _080E1CD8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E1C38:
	ldrh r2, [r0, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _080E1CF8
	movs r1, #0xa
	ldrsh r0, [r5, r1]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r0, r0, r1
	ldr r3, _080E1CDC @ =0x00000472
	adds r1, r5, r3
	ldrh r1, [r1]
	cmp r0, r1
	bgt _080E1CF8
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080E1C6C
	b _080E1E78
_080E1C6C:
	movs r1, #0xbb
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	cmp r3, #0
	bne _080E1C7A
	ldr r3, _080E1CE0 @ =0x080F54E5
_080E1C7A:
	movs r2, #0x16
	ldr r0, _080E1CE4 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080E1CE8 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	movs r2, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r2, [r0]
	ldr r2, _080E1CEC @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _080E1CF0 @ =0x0000046A
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0x1c
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _080E1CF4 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0xa
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080E1E78
	.align 2, 0
_080E1CD8: .4byte 0x030046A4
_080E1CDC: .4byte 0x00000472
_080E1CE0: .4byte 0x080F54E5
_080E1CE4: .4byte 0x0000046D
_080E1CE8: .4byte 0x0000046B
_080E1CEC: .4byte 0x00000469
_080E1CF0: .4byte 0x0000046A
_080E1CF4: .4byte 0x0000046C
_080E1CF8:
	movs r0, #0x80
	ands r2, r0
	cmp r2, #0
	bne _080E1D02
	b _080E1E10
_080E1D02:
	movs r1, #0x10
	ldr r0, _080E1D18 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _080E1D1C @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E1D20
	movs r0, #1
	b _080E1D22
	.align 2, 0
_080E1D18: .4byte 0x030046A0
_080E1D1C: .4byte 0x00000934
_080E1D20:
	movs r0, #0
_080E1D22:
	cmp r0, #0
	beq _080E1E10
	ldrh r6, [r6]
	mov sb, sp
	ldr r7, _080E1D64 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r6, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E1D68
	adds r0, #4
	b _080E1D72
	.align 2, 0
_080E1D64: .4byte 0x030046A4
_080E1D68:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E1D72:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	add r2, sp, #8
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldr r4, [sp, #0x10]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	asrs r0, r0, #5
	ldr r4, _080E1E04 @ =0x000001DD
	adds r1, r5, r4
	strb r0, [r1]
	movs r0, #0x94
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0x20
	str r0, [r1]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	movs r3, #0x8b
	lsls r3, r3, #1
	adds r2, r5, r3
	strh r0, [r2]
	ldrh r1, [r1]
	ldr r4, _080E1E08 @ =0x0000048A
	adds r0, r5, r4
	strh r1, [r0]
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x28
	strh r0, [r1]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r0, #0x40
	str r0, [r1]
	ldr r3, _080E1E0C @ =0x0000048C
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r4, [sp, #0x14]
	ldr r0, [r4]
	orrs r0, r1
	b _080E1E76
	.align 2, 0
_080E1E04: .4byte 0x000001DD
_080E1E08: .4byte 0x0000048A
_080E1E0C: .4byte 0x0000048C
_080E1E10:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
	cmp r0, #3
	bne _080E1E3A
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E1E3A
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080E1E3A:
	ldr r4, _080E1E4C @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E1E50
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r0, [r0, #0xe]
	b _080E1E54
	.align 2, 0
_080E1E4C: .4byte 0x0000025D
_080E1E50:
	ldr r0, [r5, #0x44]
	ldrh r0, [r0, #0x2c]
_080E1E54:
	cmp r0, #0
	bne _080E1E78
	movs r1, #0x80
	lsls r1, r1, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080E1E78
	ldr r0, [sp, #0x10]
	bl FUN_0809f658
	ldr r1, _080E1E9C @ =0xFFFEFFFF
	ldr r0, [r4]
	ands r0, r1
_080E1E76:
	str r0, [r4]
_080E1E78:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r2, [sp, #0x14]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080E1ED0
	ldr r3, _080E1EA0 @ =0x00000256
	adds r0, r5, r3
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E1EA4
	adds r0, #4
	b _080E1EB0
	.align 2, 0
_080E1E9C: .4byte 0xFFFEFFFF
_080E1EA0: .4byte 0x00000256
_080E1EA4:
	ldr r0, _080E1EFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E1EB0:
	ldrh r1, [r0, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #3
	beq _080E1ED0
	movs r0, #0x88
	lsls r0, r0, #3
	ands r1, r0
	cmp r1, #0
	bne _080E1ED0
	ldr r4, _080E1F00 @ =0x000004A4
	adds r0, r5, r4
	ldr r0, [r0]
	ldr r1, [sp, #0x10]
	bl FUN_08236268
_080E1ED0:
	movs r0, #0xe5
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080E1F04 @ =0x00000544
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080E1EEA
	subs r0, #1
	strh r0, [r1]
_080E1EEA:
	ldr r3, [sp, #0x18]
	ldrb r0, [r3]
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080E1F08
	movs r0, #1
	b _080E1F0A
	.align 2, 0
_080E1EFC: .4byte 0x030046A4
_080E1F00: .4byte 0x000004A4
_080E1F04: .4byte 0x00000544
_080E1F08:
	movs r0, #0
_080E1F0A:
	cmp r0, #0
	bne _080E1F16
	adds r0, r5, #0
	adds r0, #0xa8
	bl FUN_08234660
_080E1F16:
	ldr r4, _080E1F40 @ =0x000004AC
	adds r2, r5, r4
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _080E1F44 @ =0xFFFFDFFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_080E1F2C:
	movs r0, #1
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080E1F40: .4byte 0x000004AC
_080E1F44: .4byte 0xFFFFDFFF
