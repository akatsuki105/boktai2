	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _0818C3E8 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818C3EC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818C3EE
	.align 2, 0
_0818C3E8: .4byte 0x0000046C
_0818C3EC:
	movs r0, #0
_0818C3EE:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x34]
	cmp r0, #0
	bne _0818C3FC
	b _0818C6D2
_0818C3FC:
	ldr r1, _0818C468 @ =0xFFEFFFFF
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r5, _0818C46C @ =0x00000474
	adds r2, r7, r5
	movs r1, #0x21
	rsbs r1, r1, #0
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #1
	subs r5, #7
	adds r0, r7, r5
	strb r1, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r3, [r0]
	ldr r3, _0818C470 @ =0x00000553
	adds r0, r7, r3
	strb r1, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r7, r5
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r2, #0
	str r2, [sp, #0x30]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #6
	movs r3, #0
	bl FUN_0819328c
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r1, _0818C474 @ =0x00000F2C
	add r1, sl
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _0818C478
	movs r0, #1
	b _0818C47A
	.align 2, 0
_0818C468: .4byte 0xFFEFFFFF
_0818C46C: .4byte 0x00000474
_0818C470: .4byte 0x00000553
_0818C474: .4byte 0x00000F2C
_0818C478:
	movs r0, #0
_0818C47A:
	cmp r0, #0
	beq _0818C520
	movs r1, #0x80
	lsls r1, r1, #4
	mov r3, r8
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0818C490
	movs r0, #1
	b _0818C492
_0818C490:
	movs r0, #0
_0818C492:
	cmp r0, #0
	beq _0818C4C0
	ldr r1, _0818C4B8 @ =0x00000F8C
	add r1, sl
	movs r5, #0x81
	lsls r5, r5, #2
	adds r2, r7, r5
	adds r0, r7, #0
	bl FUN_08193328
	ldr r0, _0818C4BC @ =0xFFFFF7FF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r3, #1
	str r3, [sp, #0x30]
	b _0818C534
	.align 2, 0
_0818C4B8: .4byte 0x00000F8C
_0818C4BC: .4byte 0xFFFFF7FF
_0818C4C0:
	ldr r2, _0818C4EC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818C4F0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0818C4F4 @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0xcb
	bgt _0818C500
	ldr r1, _0818C4F8 @ =0x00000F8C
	add r1, sl
	ldr r0, _0818C4FC @ =0x03002BE0
	ldr r2, [r0]
	adds r2, #0x2c
	adds r0, r7, #0
	bl FUN_08193328
	b _0818C534
	.align 2, 0
_0818C4EC: .4byte 0x030046B8
_0818C4F0: .4byte 0x000003FF
_0818C4F4: .4byte 0x0203B400
_0818C4F8: .4byte 0x00000F8C
_0818C4FC: .4byte 0x03002BE0
_0818C500:
	ldr r1, _0818C51C @ =0x00000F8C
	add r1, sl
	adds r4, r7, #0
	adds r4, #8
	movs r3, #0x90
	lsls r3, r3, #0xc
	movs r0, #1
	str r0, [sp]
	adds r0, r7, #0
	adds r2, r4, #0
	bl FUN_08193b50
	adds r6, r4, #0
	b _0818C538
	.align 2, 0
_0818C51C: .4byte 0x00000F8C
_0818C520:
	ldr r1, _0818C5B4 @ =0x00000F8C
	add r1, sl
	movs r0, #0x81
	lsls r0, r0, #2
	adds r2, r7, r0
	adds r0, r7, #0
	bl FUN_08193328
	movs r1, #1
	str r1, [sp, #0x30]
_0818C534:
	adds r6, r7, #0
	adds r6, #8
_0818C538:
	add r4, sp, #8
	ldr r5, _0818C5B4 @ =0x00000F8C
	add r5, sl
	ldrh r0, [r5]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r5, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	bl ArcTan2_8
	strb r0, [r7, #5]
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _0818C5B8 @ =0x000FFFFF
	mov sb, r4
	cmp r1, r0
	bhi _0818C5BC
	adds r0, r2, #0
	movs r1, #0x30
	bl Div
	movs r5, #0xe0
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x30
	strh r0, [r1]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r2, [r0]
	movs r3, #4
	ldrsh r0, [r4, r3]
	movs r1, #0x30
	bl Div
	adds r5, #4
	b _0818C688
	.align 2, 0
_0818C5B4: .4byte 0x00000F8C
_0818C5B8: .4byte 0x000FFFFF
_0818C5BC:
	ldr r0, _0818C5F8 @ =0x001DE83F
	cmp r1, r0
	bhi _0818C5FC
	adds r0, r2, #0
	movs r1, #0x3e
	bl Div
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x3e
	strh r0, [r1]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0
	strh r1, [r0]
	mov r2, sb
	movs r3, #4
	ldrsh r0, [r2, r3]
	movs r1, #0x3e
	bl Div
	adds r5, #6
	b _0818C688
	.align 2, 0
_0818C5F8: .4byte 0x001DE83F
_0818C5FC:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0818C612
	movs r1, #0x81
	lsls r1, r1, #2
	adds r2, r7, r1
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08193a60
	b _0818C624
_0818C612:
	movs r3, #0x80
	lsls r3, r3, #0xb
	movs r0, #1
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08193b50
_0818C624:
	ldr r2, _0818C704 @ =0x00000F8C
	add r2, sl
	ldrh r1, [r2]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	add r4, sp, #8
	strh r1, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	mov r3, sb
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl ArcTan2_8
	strb r0, [r7, #5]
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r1, #0x38
	bl Div
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x38
	strh r0, [r1]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	mov r2, sb
	movs r3, #4
	ldrsh r0, [r2, r3]
	movs r1, #0x38
	bl Div
	movs r5, #0xe2
	lsls r5, r5, #1
_0818C688:
	adds r1, r7, r5
	strh r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	movs r0, #4
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	strh r0, [r2]
	movs r3, #0xaa
	lsls r3, r3, #2
	adds r0, r7, r3
	bl AuxShadow_Show
	ldr r5, _0818C708 @ =0x00000472
	adds r0, r7, r5
	ldrh r1, [r0]
	adds r0, r6, #0
	bl FUN_08191a14
	ldr r0, _0818C70C @ =0x000003E7
	bl PlaySound_082406e0
	ldr r0, _0818C710 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818C714 @ =0xFFFF7FFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0818C6D2:
	ldr r3, _0818C718 @ =0x00000484
	adds r0, r7, r3
	ldr r0, [r0]
	cmp r0, #9
	bgt _0818C720
	add r4, sp, #0x10
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #4
	adds r1, r4, #0
	ldr r2, _0818C71C @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r4, #2]
	movs r5, #0
_0818C6F2:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #2
	ble _0818C6F2
	b _0818C77A
	.align 2, 0
_0818C704: .4byte 0x00000F8C
_0818C708: .4byte 0x00000472
_0818C70C: .4byte 0x000003E7
_0818C710: .4byte 0x000003E5
_0818C714: .4byte 0xFFFF7FFF
_0818C718: .4byte 0x00000484
_0818C71C: .4byte 0x05000002
_0818C720:
	cmp r0, #0x13
	bgt _0818C750
	add r4, sp, #0x18
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #4
	adds r1, r4, #0
	ldr r2, _0818C74C @ =0x05000002
	bl CpuSet
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r5, #0
_0818C73A:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #5
	ble _0818C73A
	b _0818C77A
	.align 2, 0
_0818C74C: .4byte 0x05000002
_0818C750:
	cmp r0, #0x3b
	bgt _0818C77A
	add r4, sp, #0x20
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #4
	adds r1, r4, #0
	ldr r2, _0818C840 @ =0x05000002
	bl CpuSet
	movs r0, #0x40
	strh r0, [r4, #2]
	movs r5, #0
_0818C76A:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0818fa70
	adds r5, #1
	cmp r5, #5
	ble _0818C76A
_0818C77A:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r7, #0
	movs r1, #4
	movs r2, #8
	bl FUN_0818fdd8
	mov r0, sl
	bl FUN_0818f008
	movs r1, #0x10
	ldr r5, [sp, #0x34]
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0818C874
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _0818C844 @ =0x00000472
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_08191a14
	movs r0, #0xda
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_0818e6fc
	add r2, sp, #0x28
	ldr r3, _0818C848 @ =0x000004A4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	movs r6, #0
	strh r1, [r2]
	ldrh r0, [r3, #2]
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
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xd
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r5, [r0]
	ldr r5, _0818C84C @ =0x0000046A
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0818C850 @ =0x00000484
	adds r0, r7, r1
	str r6, [r0]
	adds r3, #3
	adds r0, r7, r3
	strb r2, [r0]
	movs r5, #0xaa
	lsls r5, r5, #2
	adds r0, r7, r5
	bl AuxShadow_Hide
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0818C854 @ =0x00000F2C
	add r0, sl
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818C858
	movs r0, #1
	b _0818C85A
	.align 2, 0
_0818C840: .4byte 0x05000002
_0818C844: .4byte 0x00000472
_0818C848: .4byte 0x000004A4
_0818C84C: .4byte 0x0000046A
_0818C850: .4byte 0x00000484
_0818C854: .4byte 0x00000F2C
_0818C858:
	movs r0, #0
_0818C85A:
	cmp r0, #0
	beq _0818C87E
	ldr r0, _0818C86C @ =0x00000E42
	add r0, sl
	ldrb r1, [r0]
	ldr r0, _0818C870 @ =0x00000E41
	add r0, sl
	strb r1, [r0]
	b _0818C87E
	.align 2, 0
_0818C86C: .4byte 0x00000E42
_0818C870: .4byte 0x00000E41
_0818C874:
	ldr r0, _0818C890 @ =0x00000484
	adds r1, r7, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818C87E:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818C890: .4byte 0x00000484
