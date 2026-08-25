	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r1, _080715BC @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _080715B2
	b _08071AD8
_080715B2:
	lsls r0, r0, #2
	ldr r1, _080715C0 @ =_080715C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080715BC: .4byte 0x0000037D
_080715C0: .4byte _080715C4
_080715C4: @ jump table
	.4byte _080715E4 @ case 0
	.4byte _0807163E @ case 1
	.4byte _08071740 @ case 2
	.4byte _08071800 @ case 3
	.4byte _080718A8 @ case 4
	.4byte _080718FC @ case 5
	.4byte _08071A28 @ case 6
	.4byte _08071AA4 @ case 7
_080715E4:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08071602
	b _08071AD8
_08071602:
	movs r1, #0x80
	lsls r1, r1, #0x16
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807161E
	movs r0, #0xa9
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x1e
	b _08071626
_0807161E:
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x3c
_08071626:
	strh r0, [r1]
	movs r0, #0x89
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08071AD8
_0807163E:
	ldr r1, _080716B4 @ =0x0000037E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _0807164E
	ldr r0, _080716B8 @ =0x000001F7
	bl PlaySound_082406e0
_0807164E:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _0807167C
	b _08071AD8
_0807167C:
	ldr r0, _080716BC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0x32
	cmp r0, #0
	bne _08071692
	movs r4, #1
_08071692:
	ldr r0, _080716C0 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080716C4 @ =0x000003E6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, r4
	bge _080716C8
	movs r0, #0xd5
	b _080718E6
	.align 2, 0
_080716B4: .4byte 0x0000037E
_080716B8: .4byte 0x000001F7
_080716BC: .4byte 0x030046A0
_080716C0: .4byte 0x00000A8F
_080716C4: .4byte 0x000003E6
_080716C8:
	ldr r0, _080716F4 @ =0x00000A92
	adds r1, r5, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080716F8
	movs r0, #0xcd
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071716
	.align 2, 0
_080716F4: .4byte 0x00000A92
_080716F8:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne _0807170C
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071716
_0807170C:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
_08071716:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2c
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	movs r0, #0x14
	str r0, [sp, #0x10]
	movs r0, #3
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0xb4
	movs r3, #0
	bl FUN_08080be8
	b _08071AD8
_08071740:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _080717E8 @ =0x00000A92
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _080717EC @ =0x0000037E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #6
	bne _0807177A
	movs r0, #0xfc
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0807177A:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0807178E
	b _080718E4
_0807178E:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r1, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080717A6
	b _08071AD8
_080717A6:
	ldr r0, _080717F0 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080717F4 @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _080717F8 @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _080717FC @ =0x00000121
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
	movs r0, #4
	bl GetWeaponSkillLevel
	cmp r0, #0x62
	ble _08071878
	movs r0, #0xfc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _08071AD8
	.align 2, 0
_080717E8: .4byte 0x00000A92
_080717EC: .4byte 0x0000037E
_080717F0: .4byte 0x00000A8F
_080717F4: .4byte 0x000003E6
_080717F8: .4byte 0x0000095E
_080717FC: .4byte 0x00000121
_08071800:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0807188C @ =0x00000A92
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080718E4
	ldr r2, _08071890 @ =0x0000037E
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r2, #0xa9
	lsls r2, r2, #4
	adds r0, r5, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	bhs _08071856
	b _08071AD8
_08071856:
	ldr r0, _08071894 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _08071898 @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0x3c
	strh r0, [r1]
	ldr r0, _0807189C @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _080718A0 @ =0x00000121
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
_08071878:
	ldr r0, _080718A4 @ =0x000001F9
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08071AD8
	.align 2, 0
_0807188C: .4byte 0x00000A92
_08071890: .4byte 0x0000037E
_08071894: .4byte 0x00000A8F
_08071898: .4byte 0x000003E6
_0807189C: .4byte 0x0000095E
_080718A0: .4byte 0x00000121
_080718A4: .4byte 0x000001F9
_080718A8:
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _080718F8 @ =0x00000A92
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080718E4
	b _08071AD8
_080718E4:
	movs r0, #0xcd
_080718E6:
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08071AD8
	.align 2, 0
_080718F8: .4byte 0x00000A92
_080718FC:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0807192E
	ldr r2, _080719A8 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_0807192E:
	ldr r0, _080719AC @ =0x000003E6
	adds r6, r5, r0
	ldrh r0, [r6]
	cmp r0, #0
	beq _08071A04
	cmp r0, #5
	bls _0807197A
	ldr r3, _080719B0 @ =0xFFFF0000
	ldr r1, _080719B4 @ =0x0000FFFF
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r3
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbd08
_0807197A:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r6]
	ldr r2, _080719B8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080719BC
	asrs r0, r0, #0xc
	b _080719C2
	.align 2, 0
_080719A8: .4byte 0x00000A76
_080719AC: .4byte 0x000003E6
_080719B0: .4byte 0xFFFF0000
_080719B4: .4byte 0x0000FFFF
_080719B8: .4byte 0x085B0A08
_080719BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080719C2:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _080719E0 @ =0x000003E6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080719E4
	asrs r0, r0, #0xc
	b _080719EA
	.align 2, 0
_080719E0: .4byte 0x000003E6
_080719E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080719EA:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _08071A00 @ =0x000003E6
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _08071AD8
	.align 2, 0
_08071A00: .4byte 0x000003E6
_08071A04:
	ldr r2, _08071A24 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08071AD8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _08071AD8
	.align 2, 0
_08071A24: .4byte 0x0000037E
_08071A28:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08071A5A
	ldr r0, _08071A74 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08071A5A:
	ldr r1, _08071A74 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _08071A7C
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08071A78 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _08071AD8
	.align 2, 0
_08071A74: .4byte 0x00000A76
_08071A78: .4byte 0x0000037D
_08071A7C:
	ldr r0, _08071AA0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _08071AD8
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08060b84
	b _08071AD8
	.align 2, 0
_08071AA0: .4byte 0x0000037E
_08071AA4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08071B08 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08071AD8
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08071AD8:
	ldr r0, _08071B0C @ =0x00000A92
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0xe
	bls _08071AF8
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08071AF4
	adds r0, r5, #0
	bl FUN_08066794
_08071AF4:
	movs r0, #0
	strh r0, [r4]
_08071AF8:
	ldr r2, _08071B10 @ =0x00000951
	adds r1, r5, r2
	movs r0, #8
	strb r0, [r1]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08071B08: .4byte 0x0000037E
_08071B0C: .4byte 0x00000A92
_08071B10: .4byte 0x00000951
