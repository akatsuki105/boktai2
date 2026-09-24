	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov sb, r0
	movs r0, #0
	str r0, [sp, #0x20]
	cmp r1, #0
	bne _0820180A
	ldr r0, _08201830 @ =0x00000692
	add r0, sb
	add r1, sp, #0x20
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r0, _08201834 @ =0x00000693
	add r0, sb
	add r2, sp, #0x20
	ldrb r2, [r2]
	strb r2, [r0]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08201838 @ =0x00000691
	add r0, sb
	add r3, sp, #0x20
	ldrb r3, [r3]
	strb r3, [r0]
_0820180A:
	movs r0, #0xd2
	lsls r0, r0, #3
	add r0, sb
	ldrb r0, [r0]
	movs r4, #0x98
	lsls r4, r4, #1
	add r4, sb
	str r4, [sp, #0x30]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x34]
	cmp r0, #4
	bls _08201826
	b _08201D96
_08201826:
	lsls r0, r0, #2
	ldr r1, _0820183C @ =_08201840
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08201830: .4byte 0x00000692
_08201834: .4byte 0x00000693
_08201838: .4byte 0x00000691
_0820183C: .4byte _08201840
_08201840: @ jump table
	.4byte _08201854 @ case 0
	.4byte _08201918 @ case 1
	.4byte _08201A38 @ case 2
	.4byte _08201BC8 @ case 3
	.4byte _08201D80 @ case 4
_08201854:
	mov r2, sb
	ldr r0, [r2, #0x1c]
	adds r0, #1
	str r0, [r2, #0x1c]
	movs r3, #0
	mov sl, r3
	movs r4, #0x98
	lsls r4, r4, #1
	add r4, sb
	str r4, [sp, #0x30]
	mov r0, sp
	adds r0, #0x18
	str r0, [sp, #0x34]
	ldr r6, _082018A8 @ =0x085B0A08
	movs r5, #0xff
	adds r2, #0x44
	movs r4, #0
_08201876:
	ldrh r0, [r2, #2]
	adds r0, #9
	strh r0, [r2, #2]
	movs r1, #8
	mov r3, sl
	subs r1, r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r3, r0, #0
	adds r3, #0xa
	mov r1, sb
	ldr r0, [r1, #0x1c]
	adds r0, r4, r0
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _082018AC
	asrs r1, r0, #0xf
	b _082018B2
	.align 2, 0
_082018A8: .4byte 0x085B0A08
_082018AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xf
	rsbs r1, r0, #0
_082018B2:
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	mov r1, sb
	ldr r0, [r1, #0x1c]
	adds r0, r4, r0
	ands r0, r5
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _082018D6
	asrs r1, r0, #0xf
	b _082018DC
_082018D6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xf
	rsbs r1, r0, #0
_082018DC:
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r2, #0x2c
	adds r4, #0x10
	movs r3, #1
	add sl, r3
	mov r0, sl
	cmp r0, #6
	ble _08201876
	ldr r1, _08201914 @ =0x00000692
	add r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bhi _08201904
	b _08201D96
_08201904:
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #1
	strb r0, [r1]
	b _08201D96
	.align 2, 0
_08201914: .4byte 0x00000692
_08201918:
	ldr r0, _08201A28 @ =0x00000692
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	bne _08201932
	ldr r0, _08201A2C @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _08201A30 @ =0x000006E4
	add r2, sb
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_08201932:
	movs r1, #0
	mov sl, r1
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, sb
	str r2, [sp, #0x30]
	mov r3, sp
	adds r3, #0x18
	str r3, [sp, #0x34]
	mov r4, sp
	mov r6, sb
	adds r6, #0x44
	ldr r0, _08201A30 @ =0x000006E4
	add r0, sb
	mov r8, r0
_08201950:
	ldrh r0, [r6]
	mov r2, r8
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #7
	mov r3, sl
	subs r1, r1, r3
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r7, r0, #1
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	movs r3, #2
	ldrsh r1, [r4, r3]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _082019CE
	movs r3, #0
	ldrsh r0, [r4, r3]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4]
	movs r1, #2
	ldrsh r0, [r4, r1]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_082019CE:
	ldrh r0, [r4]
	ldrh r3, [r6]
	adds r0, r0, r3
	strh r0, [r6]
	ldrh r2, [r4, #2]
	ldrh r0, [r6, #2]
	adds r2, r2, r0
	strh r2, [r6, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	ldr r1, _08201A34 @ =0x085AE7D8
	mov r3, sl
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r2, r2, r0
	strh r2, [r6, #2]
	adds r6, #0x2c
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #6
	ble _08201950
	movs r2, #1
	str r2, [sp, #0x20]
	ldr r1, _08201A28 @ =0x00000692
	add r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bhi _08201A18
	b _08201D96
_08201A18:
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #2
	strb r0, [r1]
	b _08201D96
	.align 2, 0
_08201A28: .4byte 0x00000692
_08201A2C: .4byte 0x03002BE0
_08201A30: .4byte 0x000006E4
_08201A34: .4byte 0x085AE7D8
_08201A38:
	movs r7, #0
	ldr r0, _08201B14 @ =0x000006E4
	add r0, sb
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r0, _08201B18 @ =0x00000694
	add r0, sb
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r2, r2, r0
	movs r0, #0xdd
	lsls r0, r0, #3
	add r0, sb
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xd3
	lsls r0, r0, #3
	add r0, sb
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	add r4, sp, #8
	strh r2, [r4]
	strh r7, [r4, #2]
	strh r1, [r4, #4]
	movs r6, #0x96
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	movs r3, #4
	ldrsh r1, [r4, r3]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _08201AB8
	movs r3, #0
	ldrsh r0, [r4, r3]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4]
	movs r1, #2
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_08201AB8:
	movs r3, #0
	mov sl, r3
	movs r0, #0x98
	lsls r0, r0, #1
	add r0, sb
	str r0, [sp, #0x30]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x34]
_08201ACA:
	movs r0, #0x2c
	mov r1, sl
	muls r1, r0, r1
	add r1, sb
	adds r2, r1, #0
	adds r2, #0x44
	ldrh r0, [r4]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	adds r1, #0x48
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08201B0E
	cmp r1, #0
	blt _08201B0E
	ldr r0, _08201B1C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08201B0E
	ldr r0, _08201B20 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08201B24
_08201B0E:
	movs r5, #0
	b _08201B32
	.align 2, 0
_08201B14: .4byte 0x000006E4
_08201B18: .4byte 0x00000694
_08201B1C: .4byte 0x030046A8
_08201B20: .4byte 0x030046AC
_08201B24:
	ldr r0, _08201B44 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r3
_08201B32:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08201B48
	adds r0, #4
	b _08201B54
	.align 2, 0
_08201B44: .4byte 0x030046A4
_08201B48:
	ldr r0, _08201BBC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08201B54:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r0, #0x2c
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	mov r3, sb
	adds r1, r3, r0
	adds r0, r1, #0
	adds r0, #0x46
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, r2
	bgt _08201B7C
	adds r0, r1, #0
	adds r0, #0x28
	strh r2, [r0, #0x1e]
	adds r7, #1
_08201B7C:
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #6
	ble _08201ACA
	cmp r7, #6
	ble _08201B9E
	mov r0, sb
	movs r1, #0x14
	movs r2, #0x14
	bl FUN_082010f0
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #3
	strb r0, [r1]
_08201B9E:
	cmp r7, #0
	bgt _08201BA4
	b _08201D96
_08201BA4:
	ldr r4, _08201BC0 @ =0x00000693
	add r4, sb
	ldrb r0, [r4]
	cmp r0, #0
	beq _08201BB0
	b _08201D96
_08201BB0:
	ldr r0, _08201BC4 @ =0x000001BB
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4]
	b _08201D96
	.align 2, 0
_08201BBC: .4byte 0x030046A4
_08201BC0: .4byte 0x00000693
_08201BC4: .4byte 0x000001BB
_08201BC8:
	mov r2, sb
	ldr r0, [r2, #0x1c]
	adds r0, #0x10
	str r0, [r2, #0x1c]
	movs r3, #0
	mov sl, r3
	movs r4, #0x98
	lsls r4, r4, #1
	add r4, sb
	str r4, [sp, #0x30]
	add r0, sp, #0x10
	mov r8, r0
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x34]
	mov r7, r8
	mov r5, sb
	adds r5, #0x44
	ldr r2, _08201CBC @ =0x00000694
	add r2, sb
	str r2, [sp, #0x24]
_08201BF2:
	ldrh r1, [r5]
	ldr r3, [sp, #0x24]
	ldrh r0, [r3]
	subs r1, r1, r0
	add r6, sp, #0x10
	strh r1, [r6]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r4, #0
	ldrsh r0, [r6, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	movs r4, #4
	ldrsh r1, [r7, r4]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08201C6C
	mov r3, r8
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #3
	adds r1, r4, #0
	bl Div
	strh r0, [r6]
	movs r2, #2
	ldrsh r0, [r7, r2]
	lsls r0, r0, #3
	adds r1, r4, #0
	bl Div
	mov r3, r8
	strh r0, [r3, #2]
	movs r1, #4
	ldrsh r0, [r7, r1]
	lsls r0, r0, #3
	adds r1, r4, #0
	bl Div
	mov r2, r8
	strh r0, [r2, #4]
_08201C6C:
	mov r3, r8
	ldrh r0, [r3]
	ldrh r4, [r5]
	adds r0, r0, r4
	strh r0, [r5]
	ldrh r0, [r7, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r2, [r5, #4]
	adds r0, r0, r2
	strh r0, [r5, #4]
	movs r1, #9
	mov r3, sl
	subs r1, r1, r3
	ldr r0, _08201CC0 @ =0x00000692
	add r0, sb
	ldrb r2, [r0]
	movs r0, #0x3c
	subs r0, r0, r2
	adds r3, r1, #0
	muls r3, r0, r3
	ldr r2, _08201CC4 @ =0x085B0A08
	mov r4, sl
	lsls r0, r4, #4
	mov r4, sb
	ldr r1, [r4, #0x1c]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08201CC8
	asrs r3, r0, #0xf
	b _08201CCE
	.align 2, 0
_08201CBC: .4byte 0x00000694
_08201CC0: .4byte 0x00000692
_08201CC4: .4byte 0x085B0A08
_08201CC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xf
	rsbs r3, r0, #0
_08201CCE:
	ldrh r0, [r5, #2]
	adds r0, r0, r3
	strh r0, [r5, #2]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08201CF8
	cmp r1, #0
	blt _08201CF8
	ldr r0, _08201CFC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08201CF8
	ldr r0, _08201D00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08201D04
_08201CF8:
	movs r4, #0
	b _08201D12
	.align 2, 0
_08201CFC: .4byte 0x030046A8
_08201D00: .4byte 0x030046AC
_08201D04:
	ldr r0, _08201D24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08201D12:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08201D28
	adds r0, #4
	b _08201D34
	.align 2, 0
_08201D24: .4byte 0x030046A4
_08201D28:
	ldr r0, _08201D78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08201D34:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmp r0, r1
	bgt _08201D46
	strh r1, [r5, #2]
_08201D46:
	adds r5, #0x2c
	movs r3, #1
	add sl, r3
	mov r4, sl
	cmp r4, #6
	bgt _08201D54
	b _08201BF2
_08201D54:
	ldr r1, _08201D7C @ =0x00000692
	add r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x28
	bls _08201D96
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #4
	strb r0, [r1]
	b _08201D96
	.align 2, 0
_08201D78: .4byte 0x030046A4
_08201D7C: .4byte 0x00000692
_08201D80:
	ldr r1, _08201E78 @ =0x000006D9
	add r1, sb
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x98
	lsls r0, r0, #1
	add r0, sb
	str r0, [sp, #0x30]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x34]
_08201D96:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	beq _08201E84
	movs r3, #0
	mov sl, r3
	ldr r5, [sp, #0x34]
	mov r4, sp
	adds r4, #0x18
	str r4, [sp, #0x28]
	ldr r0, [sp, #0x30]
	adds r0, #0x1c
	mov r8, r0
	movs r7, #0xbc
	lsls r7, r7, #1
	add r7, sb
_08201DB4:
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	subs r0, r0, r1
	ldr r2, [sp, #0x28]
	strh r0, [r2]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r4, #4
	ldrsh r0, [r5, r4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r3, r1, r0
	ldr r1, _08201E7C @ =0x085AE7C8
	movs r0, #7
	mov r4, sl
	subs r0, r0, r4
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _08201E62
	ldr r0, _08201E80 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08201E46
	ldr r1, [sp, #0x34]
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	ldr r3, [sp, #0x28]
	strh r0, [r3]
	movs r1, #2
	ldrsh r0, [r5, r1]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #2]
	movs r2, #4
	ldrsh r0, [r5, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #4]
_08201E46:
	ldr r3, [sp, #0x34]
	ldrh r0, [r3]
	ldrh r4, [r7]
	adds r0, r0, r4
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r5, #2]
	ldrh r2, [r7, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r5, #4]
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
_08201E62:
	subs r7, #0x2c
	movs r4, #0x2c
	rsbs r4, r4, #0
	add r8, r4
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #6
	ble _08201DB4
	b _08201F5C
	.align 2, 0
_08201E78: .4byte 0x000006D9
_08201E7C: .4byte 0x085AE7C8
_08201E80: .4byte 0x085AE7B8
_08201E84:
	movs r2, #0
	mov sl, r2
	ldr r5, [sp, #0x34]
	mov r3, sp
	adds r3, #0x18
	str r3, [sp, #0x2c]
	ldr r4, [sp, #0x30]
	adds r4, #0x1c
	mov r8, r4
	movs r7, #0xbc
	lsls r7, r7, #1
	add r7, sb
_08201E9C:
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	subs r0, r0, r1
	ldr r2, [sp, #0x2c]
	strh r0, [r2]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r4, #4
	ldrsh r0, [r5, r4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r3, r1, r0
	ldr r1, _08201F6C @ =0x085AE7C8
	movs r0, #7
	mov r4, sl
	subs r0, r0, r4
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _08201F4A
	ldr r0, _08201F70 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08201F2E
	ldr r1, [sp, #0x34]
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	ldr r3, [sp, #0x2c]
	strh r0, [r3]
	movs r1, #2
	ldrsh r0, [r5, r1]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #2]
	movs r2, #4
	ldrsh r0, [r5, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #4]
_08201F2E:
	ldr r3, [sp, #0x34]
	ldrh r0, [r3]
	ldrh r4, [r7]
	adds r0, r0, r4
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r5, #2]
	ldrh r2, [r7, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r5, #4]
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
_08201F4A:
	subs r7, #0x2c
	movs r4, #0x2c
	rsbs r4, r4, #0
	add r8, r4
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #6
	ble _08201E9C
_08201F5C:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08201F6C: .4byte 0x085AE7C8
_08201F70: .4byte 0x085AE7B8
