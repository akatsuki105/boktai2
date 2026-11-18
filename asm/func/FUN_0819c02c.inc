	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _0819C054 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C058
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C05A
	.align 2, 0
_0819C054: .4byte 0x0000046D
_0819C058:
	movs r0, #0
_0819C05A:
	cmp r0, #0
	beq _0819C0F4
	ldr r2, [r6, #0x44]
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r1, _0819C094 @ =0x00000A54
	adds r3, r7, r1
	ldrb r4, [r0]
	movs r5, #0xc
	ldr r2, _0819C098 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0819C09C
	asrs r1, r0, #0xc
	b _0819C0A2
	.align 2, 0
_0819C094: .4byte 0x00000A54
_0819C098: .4byte gSineTable
_0819C09C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819C0A2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0819C0BC @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0819C0C0
	asrs r0, r0, #0xc
	b _0819C0C6
	.align 2, 0
_0819C0BC: .4byte gSineTable
_0819C0C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819C0C6:
	strh r0, [r3, #4]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrb r1, [r0]
	ldr r3, _0819C1B0 @ =0x00000A5D
	adds r0, r7, r3
	strb r1, [r0]
	ldr r0, _0819C1B4 @ =0x00000A4C
	adds r2, r7, r0
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r6, #0x44]
	ldrb r1, [r0, #6]
	ldr r2, _0819C1B8 @ =0x00000A5C
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #1
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
_0819C0F4:
	ldr r0, [r6, #0x44]
	ldrb r4, [r0, #6]
	ldr r1, _0819C1BC @ =0x00000A5E
	adds r2, r7, r1
	ldrb r1, [r2]
	subs r1, r4, r1
	strb r1, [r0, #6]
	movs r0, #1
	mov r3, r8
	ands r0, r3
	cmp r0, #0
	beq _0819C116
	ldrb r0, [r2]
	cmp r0, #0xb
	bhi _0819C116
	adds r0, #1
	strb r0, [r2]
_0819C116:
	adds r0, r6, #0
	bl FUN_0819fdf0
	ldr r0, [r6, #0x44]
	ldrb r0, [r0, #6]
	cmp r4, r0
	bge _0819C12A
	ldr r0, _0819C1C0 @ =0x00000169
	bl PlaySound_082406e0
_0819C12A:
	mov r0, r8
	cmp r0, #0x77
	ble _0819C132
	b _0819C258
_0819C132:
	ldr r1, _0819C1B4 @ =0x00000A4C
	adds r4, r7, r1
	ldr r2, _0819C1B8 @ =0x00000A5C
	adds r5, r7, r2
	ldrb r2, [r5]
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0819f150
	ldr r3, _0819C1C4 @ =0x00000A54
	adds r1, r7, r3
	ldrh r0, [r4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r4]
	ldrh r0, [r4, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	ldr r0, _0819C1C8 @ =0x00000E3C
	adds r1, r7, r0
	ldrb r0, [r5]
	ldrb r1, [r1]
	subs r0, r0, r1
	strb r0, [r5]
	ldr r0, _0819C1CC @ =0x03002BE0
	mov r2, sp
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r4]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	ldr r2, _0819C1B0 @ =0x00000A5D
	adds r1, r7, r2
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819C1D4
	ldr r3, _0819C1D0 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0819C1E2
	.align 2, 0
_0819C1B0: .4byte 0x00000A5D
_0819C1B4: .4byte 0x00000A4C
_0819C1B8: .4byte 0x00000A5C
_0819C1BC: .4byte 0x00000A5E
_0819C1C0: .4byte 0x00000169
_0819C1C4: .4byte 0x00000A54
_0819C1C8: .4byte 0x00000E3C
_0819C1CC: .4byte 0x03002BE0
_0819C1D0: .4byte 0xFFFFFF00
_0819C1D4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C1E2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0819C1E2:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819C1EA
	rsbs r0, r0, #0
_0819C1EA:
	cmp r0, #0x20
	ble _0819C1F8
	ldr r2, _0819C224 @ =0x00000A5D
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_0819C1F8:
	ldr r3, _0819C224 @ =0x00000A5D
	adds r0, r7, r3
	ldr r2, _0819C228 @ =0x00000E3D
	adds r1, r7, r2
	subs r3, #9
	adds r4, r7, r3
	ldrb r3, [r0]
	ldrb r5, [r1]
	ldr r2, _0819C22C @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0819C230
	asrs r1, r0, #0xc
	b _0819C236
	.align 2, 0
_0819C224: .4byte 0x00000A5D
_0819C228: .4byte 0x00000E3D
_0819C22C: .4byte gSineTable
_0819C230:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819C236:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0819C24E
	asrs r0, r0, #0xc
	b _0819C254
_0819C24E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819C254:
	strh r0, [r4, #4]
	b _0819C3B8
_0819C258:
	ldr r3, _0819C2C8 @ =0x00000A4C
	adds r4, r7, r3
	ldr r0, _0819C2CC @ =0x00000A5C
	adds r5, r7, r0
	ldrb r2, [r5]
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0819f150
	ldr r2, _0819C2D0 @ =0x00000A54
	adds r1, r7, r2
	ldrh r0, [r4]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r4, #2]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	ldrb r0, [r5]
	subs r0, #6
	strb r0, [r5]
	add r5, sp, #8
	adds r2, r6, #0
	adds r2, #8
	ldrh r0, [r6, #8]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r3, #0
	ldrsh r0, [r5, r3]
	movs r2, #4
	ldrsh r1, [r5, r2]
	bl ArcTan2_8
	ldr r3, _0819C2D4 @ =0x00000A5D
	adds r1, r7, r3
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819C2DC
	ldr r0, _0819C2D8 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0819C2EA
	.align 2, 0
_0819C2C8: .4byte 0x00000A4C
_0819C2CC: .4byte 0x00000A5C
_0819C2D0: .4byte 0x00000A54
_0819C2D4: .4byte 0x00000A5D
_0819C2D8: .4byte 0xFFFFFF00
_0819C2DC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C2EA
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0819C2EA:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819C2F2
	rsbs r0, r0, #0
_0819C2F2:
	cmp r0, #0xc
	ble _0819C300
	ldr r3, _0819C328 @ =0x00000A5D
	adds r1, r7, r3
	ldrb r0, [r1]
	adds r0, #6
	strb r0, [r1]
_0819C300:
	ldr r1, _0819C328 @ =0x00000A5D
	adds r0, r7, r1
	ldr r2, _0819C32C @ =0x00000A54
	adds r3, r7, r2
	ldrb r4, [r0]
	ldr r2, _0819C330 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	cmp r0, #0
	blt _0819C334
	asrs r1, r0, #0xc
	b _0819C33A
	.align 2, 0
_0819C328: .4byte 0x00000A5D
_0819C32C: .4byte 0x00000A54
_0819C330: .4byte gSineTable
_0819C334:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819C33A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _0819C354
	asrs r0, r0, #0xc
	b _0819C35A
_0819C354:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819C35A:
	strh r0, [r3, #4]
	add r0, sp, #8
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _0819C3C4 @ =0x000003FF
	cmp r1, r0
	ble _0819C380
	movs r0, #0x96
	lsls r0, r0, #2
	cmp r8, r0
	ble _0819C3B8
_0819C380:
	ldr r0, _0819C3C8 @ =0x00000A4C
	adds r2, r7, r0
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r3, _0819C3CC @ =FUN_0819c3dc
	movs r2, #0x28
	ldr r0, _0819C3D0 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0819C3D4 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0819C3D8 @ =0x00000553
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
_0819C3B8:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819C3C4: .4byte 0x000003FF
_0819C3C8: .4byte 0x00000A4C
_0819C3CC: .4byte FUN_0819c3dc
_0819C3D0: .4byte 0x0000046D
_0819C3D4: .4byte 0x0000046B
_0819C3D8: .4byte 0x00000553
