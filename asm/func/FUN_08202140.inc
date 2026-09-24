	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	cmp r1, #0
	bne _0820216E
	str r1, [r5, #0x1c]
	ldr r2, _0820218C @ =0x00000692
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08202190 @ =0x00000693
	adds r0, r5, r3
	strb r1, [r0]
	movs r4, #0xd2
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r1, [r0]
	ldr r6, _08202194 @ =0x00000691
	adds r0, r5, r6
	strb r1, [r0]
_0820216E:
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0820217C
	b _082022A0
_0820217C:
	cmp r0, #1
	bgt _08202198
	cmp r0, #0
	beq _082021A6
	movs r2, #0x98
	lsls r2, r2, #1
	adds r7, r5, r2
	b _08202402
	.align 2, 0
_0820218C: .4byte 0x00000692
_08202190: .4byte 0x00000693
_08202194: .4byte 0x00000691
_08202198:
	cmp r0, #2
	bne _0820219E
	b _082023F4
_0820219E:
	movs r3, #0x98
	lsls r3, r3, #1
	adds r7, r5, r3
	b _08202402
_082021A6:
	ldr r4, _08202204 @ =0x00000692
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _082021E0
	ldr r0, _08202208 @ =0x03002BE0
	ldr r0, [r0]
	ldr r6, _0820220C @ =0x000006E4
	adds r2, r5, r6
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _08202210 @ =0x00000694
	adds r3, r5, r0
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r3, r6]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r0, #0x20
	str r0, [r5, #0x1c]
_082021E0:
	mov r4, sp
	ldr r3, [r5, #0x1c]
	movs r6, #0x64
	ldr r2, _08202214 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	mov sl, r2
	cmp r0, #0
	blt _08202218
	asrs r1, r0, #0xc
	b _0820221E
	.align 2, 0
_08202204: .4byte 0x00000692
_08202208: .4byte 0x03002BE0
_0820220C: .4byte 0x000006E4
_08202210: .4byte 0x00000694
_08202214: .4byte 0x085B0A08
_08202218:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0820221E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0820223A
	asrs r0, r0, #0xc
	b _08202240
_0820223A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08202240:
	strh r0, [r4, #4]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r7, r5, r3
	mov r0, sp
	adds r1, r5, #0
	adds r1, #0x70
	ldrh r4, [r0]
	ldrh r3, [r0, #2]
	ldrh r2, [r0, #4]
	movs r6, #5
	mov sb, r6
_08202258:
	ldrh r6, [r1]
	adds r0, r4, r6
	strh r0, [r1]
	ldrh r6, [r1, #2]
	adds r0, r3, r6
	strh r0, [r1, #2]
	ldrh r6, [r1, #4]
	adds r0, r2, r6
	strh r0, [r1, #4]
	adds r1, #0x2c
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r6, sb
	cmp r6, #0
	bge _08202258
	ldr r0, _0820229C @ =0x00000692
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3c
	bhi _0820228C
	b _08202402
_0820228C:
	movs r0, #0
	strb r0, [r1]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _08202402
	.align 2, 0
_0820229C: .4byte 0x00000692
_082022A0:
	ldr r0, [r5, #0x1c]
	adds r0, #1
	movs r1, #0xff
	ands r0, r1
	str r0, [r5, #0x1c]
	movs r3, #0
	mov sb, r3
	movs r4, #0x98
	lsls r4, r4, #1
	adds r7, r5, r4
	mov r6, sp
	movs r0, #0x64
	mov r8, r0
	ldr r1, _082022EC @ =0x085B0A08
	mov sl, r1
_082022BE:
	movs r0, #7
	mov r2, sb
	subs r0, r0, r2
	ldr r1, [r5, #0x1c]
	muls r0, r1, r0
	lsrs r0, r0, #3
	adds r3, r0, r1
	ldr r2, _082022EC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _082022F0
	asrs r1, r0, #0xc
	b _082022F6
	.align 2, 0
_082022EC: .4byte 0x085B0A08
_082022F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_082022F6:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _08202316
	asrs r3, r0, #0xc
	b _0820231C
_08202316:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0820231C:
	strh r3, [r6, #4]
	movs r0, #0x2c
	mov r1, sb
	muls r1, r0, r1
	adds r1, r5, r1
	adds r2, r1, #0
	adds r2, #0x44
	ldrh r0, [r6]
	ldrh r4, [r2]
	adds r0, r0, r4
	strh r0, [r2]
	adds r1, #0x48
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0820235E
	cmp r1, #0
	blt _0820235E
	ldr r0, _08202364 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0820235E
	ldr r0, _08202368 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0820236C
_0820235E:
	movs r4, #0
	b _0820237A
	.align 2, 0
_08202364: .4byte 0x030046A8
_08202368: .4byte 0x030046AC
_0820236C:
	ldr r0, _0820238C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0820237A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08202390
	adds r0, #4
	b _0820239C
	.align 2, 0
_0820238C: .4byte 0x030046A4
_08202390:
	ldr r0, _082023EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0820239C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r0, #0x2c
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0x46
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, r2
	bgt _082023C0
	adds r0, r1, #0
	adds r0, #0x28
	strh r2, [r0, #0x1e]
_082023C0:
	movs r4, #1
	add sb, r4
	mov r0, sb
	cmp r0, #6
	bgt _082023CC
	b _082022BE
_082023CC:
	ldr r1, _082023F0 @ =0x00000692
	adds r3, r5, r1
	ldrb r0, [r3]
	cmp r0, #0xd1
	bls _082023E4
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	movs r1, #2
	strb r1, [r0]
	strb r2, [r3]
_082023E4:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	b _08202402
	.align 2, 0
_082023EC: .4byte 0x030046A4
_082023F0: .4byte 0x00000692
_082023F4:
	ldr r3, _082024DC @ =0x000006D9
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r4, #0x98
	lsls r4, r4, #1
	adds r7, r5, r4
_08202402:
	movs r6, #0
	mov sb, r6
	mov r4, sp
	adds r7, #0x1c
	mov r8, r7
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r7, r5, r0
_08202412:
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	subs r0, r0, r1
	strh r0, [r4]
	mov r2, r8
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r6, #2
	ldrsh r0, [r4, r6]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r6, r0, #0
	muls r6, r0, r6
	adds r0, r6, #0
	adds r3, r1, r0
	ldr r1, _082024E0 @ =0x085AE7C8
	movs r0, #7
	mov r2, sb
	subs r0, r0, r2
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _082024B8
	ldr r0, _082024E4 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0820249E
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
_0820249E:
	ldrh r0, [r4]
	ldrh r3, [r7]
	adds r0, r0, r3
	mov r6, r8
	strh r0, [r6]
	ldrh r0, [r4, #2]
	ldrh r1, [r7, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	strh r0, [r6, #4]
_082024B8:
	subs r7, #0x2c
	movs r3, #0x2c
	rsbs r3, r3, #0
	add r8, r3
	movs r6, #1
	add sb, r6
	mov r0, sb
	cmp r0, #6
	ble _08202412
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082024DC: .4byte 0x000006D9
_082024E0: .4byte 0x085AE7C8
_082024E4: .4byte 0x085AE7B8
