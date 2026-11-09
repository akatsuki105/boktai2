	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08134468 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813446C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813446E
	.align 2, 0
_08134468: .4byte 0x0000046C
_0813446C:
	movs r0, #0
_0813446E:
	cmp r0, #0
	beq _081344B4
	ldr r3, _081344F0 @ =0x00000B34
	adds r0, r7, r3
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r6, _081344F4 @ =0x00000B38
	adds r0, r7, r6
	movs r2, #0
	strh r4, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	ldr r6, _081344F8 @ =0x0000046D
	adds r0, r5, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _081344FC @ =0x00000553
	adds r0, r5, r2
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_08136ac8
_081344B4:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08134508
	movs r2, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _08134500 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r0, _08134504 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0813472C
	.align 2, 0
_081344F0: .4byte 0x00000B34
_081344F4: .4byte 0x00000B38
_081344F8: .4byte 0x0000046D
_081344FC: .4byte 0x00000553
_08134500: .4byte 0x00000469
_08134504: .4byte 0x0000046C
_08134508:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08134534 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813453C
	ldr r3, _08134538 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0813454C
	.align 2, 0
_08134534: .4byte 0x0000A02F
_08134538: .4byte 0x00000482
_0813453C:
	ldr r1, _08134570 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0813454C
	movs r0, #1
	strh r0, [r2]
_0813454C:
	ldr r3, _08134574 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08134578
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _08134590
	.align 2, 0
_08134570: .4byte 0x00000482
_08134574: .4byte 0x0000025D
_08134578:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_08134590:
	ldr r1, _081345C8 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _081345B2
	rsbs r2, r2, #0
_081345B2:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _081345CC
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _081345C0
	rsbs r2, r2, #0
_081345C0:
	cmp r2, #0x20
	bgt _081345CC
	movs r0, #1
	b _08134636
	.align 2, 0
_081345C8: .4byte 0x000004A4
_081345CC:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _081345D8
	cmp r1, #0
	beq _08134634
_081345D8:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r2, _081345FC @ =gSineTable
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08134600
	asrs r1, r0, #0xc
	b _08134606
	.align 2, 0
_081345FC: .4byte gSineTable
_08134600:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08134606:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _08134624 @ =gSineTable
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _08134628
	asrs r1, r0, #0xc
	b _0813462E
	.align 2, 0
_08134624: .4byte gSineTable
_08134628:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813462E:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08134634:
	movs r0, #0
_08134636:
	cmp r0, #0
	beq _081346E0
	adds r0, r5, #0
	bl FUN_081355f0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _08134690 @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
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
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08134698
	ldr r3, _08134694 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081346A6
	.align 2, 0
_08134690: .4byte 0x000004A4
_08134694: .4byte 0xFFFFFF00
_08134698:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081346A6
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081346A6:
	cmp r1, #0
	bge _081346AC
	rsbs r1, r1, #0
_081346AC:
	cmp r1, #0x20
	ble _081346E0
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081346D8 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081346DC @ =0x0000046A
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	b _0813472C
	.align 2, 0
_081346D8: .4byte 0x00000469
_081346DC: .4byte 0x0000046A
_081346E0:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08137a30
	ldr r0, _08134708 @ =0x00000B44
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _0813470C
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r5, #0
	movs r1, #0x12
	bl FUN_081370f4
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08134718
	.align 2, 0
_08134708: .4byte 0x00000B44
_0813470C:
	movs r2, #0xc8
	lsls r2, r2, #7
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_081370f4
_08134718:
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08136ca0
	ldr r2, _08134734 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0813472C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08134734: .4byte 0x00000484
