	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r2, _0810A0D8 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A0DC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A0DE
	.align 2, 0
_0810A0D8: .4byte 0x0000046D
_0810A0DC:
	movs r0, #0
_0810A0DE:
	cmp r0, #0
	beq _0810A0EA
	adds r0, r7, #0
	movs r1, #5
	bl Enemy_PlayAnim
_0810A0EA:
	ldrh r0, [r4, #0x14]
	cmp r0, #2
	bne _0810A0FC
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _0810A0FC
	ldr r0, _0810A124 @ =0x000003A9
	bl PlaySound_082406e0
_0810A0FC:
	ldrh r0, [r4, #0x14]
	cmp r0, #3
	bne _0810A10C
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r5, r1
	bl Hitbox_Register
_0810A10C:
	movs r2, #0x20
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0810A128
	movs r0, #1
	b _0810A12A
	.align 2, 0
_0810A124: .4byte 0x000003A9
_0810A128:
	movs r0, #0
_0810A12A:
	adds r4, r0, #0
	cmp r4, #0
	bne _0810A132
	b _0810A3A0
_0810A132:
	ldrb r0, [r7, #5]
	adds r1, r0, #0
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0810A144
	asrs r0, r1, #6
	b _0810A14A
_0810A144:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0810A14A:
	lsls r3, r0, #6
	add r4, sp, #0x2c
	movs r5, #0x14
	ldr r2, _0810A170 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _0810A174
	asrs r1, r0, #0xc
	b _0810A17A
	.align 2, 0
_0810A170: .4byte gSineTable
_0810A174:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810A17A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0810A196
	asrs r0, r0, #0xc
	b _0810A19C
_0810A196:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810A19C:
	strh r0, [r4, #4]
	ldr r2, _0810A1D4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810A1D8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0810A1DC @ =0x0203B400
	adds r0, r0, r1
	movs r1, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x34
	movs r4, #0xa
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	mov r8, r5
	cmp r0, #0
	blt _0810A1E0
	asrs r2, r0, #0xc
	b _0810A1E6
	.align 2, 0
_0810A1D4: .4byte 0x030046B8
_0810A1D8: .4byte 0x000003FF
_0810A1DC: .4byte 0x0203B400
_0810A1E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0810A1E6:
	movs r0, #0
	strh r2, [r5]
	strh r0, [r5, #2]
	ldr r1, _0810A204 @ =gSineTable
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0810A208
	asrs r0, r0, #0xc
	b _0810A20E
	.align 2, 0
_0810A204: .4byte gSineTable
_0810A208:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810A20E:
	movs r4, #0
	strh r0, [r5, #4]
	movs r2, #0x1e
	mov ip, r2
	mov r1, ip
	mov r0, r8
	strh r1, [r0, #2]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	ldr r2, [sp, #0x3c]
	asrs r1, r2, #0x10
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0810A2B8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x3c]
	add r5, sp, #0x3c
	add r1, sp, #0x34
	ldrh r0, [r5]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	mov r2, r8
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r5, #4]
	ldr r2, _0810A2BC @ =0x0000D45E
	ldr r3, _0810A2C0 @ =0x00001DC3
	movs r0, #2
	str r0, [sp]
	mov r1, ip
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xf7
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r5, #0
	mov r1, r8
	bl Entity081efa9c_Spawn
	ldr r2, _0810A2C4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810A2C8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0810A2CC @ =0x0203B400
	adds r0, r0, r2
	movs r2, #0xff
	ldrb r3, [r0]
	mov ip, r8
	movs r4, #0xa
	ldr r1, _0810A2D0 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r6, r5, #0
	cmp r0, #0
	blt _0810A2D4
	asrs r1, r0, #0xc
	b _0810A2DA
	.align 2, 0
_0810A2B8: .4byte 0x0000FFFF
_0810A2BC: .4byte 0x0000D45E
_0810A2C0: .4byte 0x00001DC3
_0810A2C4: .4byte 0x030046B8
_0810A2C8: .4byte 0x000003FF
_0810A2CC: .4byte 0x0203B400
_0810A2D0: .4byte gSineTable
_0810A2D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810A2DA:
	movs r0, #0
	mov r2, ip
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _0810A2FC @ =gSineTable
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0810A300
	asrs r0, r0, #0xc
	b _0810A306
	.align 2, 0
_0810A2FC: .4byte gSineTable
_0810A300:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810A306:
	movs r2, #0
	mov sb, r2
	movs r4, #0
	mov r1, ip
	strh r0, [r1, #4]
	movs r5, #0x1e
	mov r2, r8
	strh r5, [r2, #2]
	ldrh r0, [r6, #2]
	adds r0, #0xdc
	strh r0, [r6, #2]
	add r2, sp, #0x34
	add r1, sp, #0x3c
	ldrh r0, [r1]
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r1]
	mov r1, r8
	ldrh r0, [r1, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r6, #4]
	mov r2, r8
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r6, #4]
	ldr r2, _0810A388 @ =0x0000D45E
	ldr r3, _0810A38C @ =0x00001DC3
	movs r0, #3
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xf7
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r6, #0
	mov r1, r8
	bl Entity081efa9c_Spawn
	movs r0, #0x21
	rsbs r0, r0, #0
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r3, _0810A390 @ =Skeleton_StateBecomeSkeleton
	movs r2, #0x24
	ldr r0, _0810A394 @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A398 @ =0x0000046B
	adds r0, r7, r1
	mov r1, sb
	strb r1, [r0]
	ldr r1, _0810A39C @ =0x00000553
	b _0810A3BE
	.align 2, 0
_0810A388: .4byte 0x0000D45E
_0810A38C: .4byte 0x00001DC3
_0810A390: .4byte Skeleton_StateBecomeSkeleton
_0810A394: .4byte 0x0000046D
_0810A398: .4byte 0x0000046B
_0810A39C: .4byte 0x00000553
_0810A3A0:
	ldr r2, _0810A3E4 @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A3D2
	ldr r3, _0810A3E8 @ =Skeleton_StateArcherMeleeMiss
	movs r2, #0x23
	ldr r0, _0810A3EC @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A3F0 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r1, #0xe8
_0810A3BE:
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
_0810A3D2:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810A3E4: .4byte 0x0000046E
_0810A3E8: .4byte Skeleton_StateArcherMeleeMiss
_0810A3EC: .4byte 0x0000046D
_0810A3F0: .4byte 0x0000046B
