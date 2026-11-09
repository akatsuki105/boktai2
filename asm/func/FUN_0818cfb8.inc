	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0818CFD8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818CFDC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818CFDE
	.align 2, 0
_0818CFD8: .4byte 0x0000046C
_0818CFDC:
	movs r0, #0
_0818CFDE:
	cmp r0, #0
	bne _0818CFE4
	b _0818D0FA
_0818CFE4:
	movs r2, #0x10
	ldr r3, _0818CFF8 @ =0x00000F2C
	adds r1, r7, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0818CFFC
	movs r0, #1
	b _0818CFFE
	.align 2, 0
_0818CFF8: .4byte 0x00000F2C
_0818CFFC:
	movs r0, #0
_0818CFFE:
	adds r2, r0, #0
	cmp r2, #0
	bne _0818D0FA
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r4, #1
	ldr r3, _0818D0C4 @ =0x0000046D
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_0818f918
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0818f17c
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r2, _0818D0C8 @ =0x00000472
	adds r4, r5, r2
	ldr r3, _0818D0CC @ =0xFFFFFF00
	adds r0, r3, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
	adds r1, r5, #0
	adds r1, #8
	adds r0, r7, #0
	bl FUN_0819014c
	movs r0, #0x20
	ldr r3, _0818D0D0 @ =0x00000474
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	ldr r2, _0818D0D4 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrb r2, [r5, #5]
	mov r0, sp
	movs r1, #2
	movs r3, #0
	bl FUN_08192ae0
	ldr r0, _0818D0D8 @ =0x00000D44
	adds r2, r7, r0
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0818D0DC @ =0x00000D54
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _0818D0E0 @ =0x00000D4C
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #0x10
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0818D0E4
	movs r0, #1
	b _0818D0E6
	.align 2, 0
_0818D0C4: .4byte 0x0000046D
_0818D0C8: .4byte 0x00000472
_0818D0CC: .4byte 0xFFFFFF00
_0818D0D0: .4byte 0x00000474
_0818D0D4: .4byte 0x0000FFFF
_0818D0D8: .4byte 0x00000D44
_0818D0DC: .4byte 0x00000D54
_0818D0E0: .4byte 0x00000D4C
_0818D0E4:
	movs r0, #0
_0818D0E6:
	cmp r0, #0
	bne _0818D0FA
	ldr r0, _0818D128 @ =0x000003E5
	bl PlaySound_082406e0
	movs r0, #0x80
	lsls r0, r0, #8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
_0818D0FA:
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _0818D12C @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818D134
	ldr r3, _0818D130 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0818D144
	.align 2, 0
_0818D128: .4byte 0x000003E5
_0818D12C: .4byte 0x0000A02F
_0818D130: .4byte 0x00000482
_0818D134:
	ldr r1, _0818D168 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0818D144
	movs r0, #1
	strh r0, [r2]
_0818D144:
	ldr r3, _0818D16C @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818D170
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
	b _0818D188
	.align 2, 0
_0818D168: .4byte 0x00000482
_0818D16C: .4byte 0x0000025D
_0818D170:
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
_0818D188:
	ldr r1, _0818D1C0 @ =0x000004A4
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
	bge _0818D1AA
	rsbs r2, r2, #0
_0818D1AA:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0818D1C4
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0818D1B8
	rsbs r2, r2, #0
_0818D1B8:
	cmp r2, #0x20
	bgt _0818D1C4
	movs r0, #1
	b _0818D22E
	.align 2, 0
_0818D1C0: .4byte 0x000004A4
_0818D1C4:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0818D1D0
	cmp r1, #0
	beq _0818D22C
_0818D1D0:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r2, _0818D1F4 @ =gSineTable
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
	blt _0818D1F8
	asrs r1, r0, #0xc
	b _0818D1FE
	.align 2, 0
_0818D1F4: .4byte gSineTable
_0818D1F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818D1FE:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _0818D21C @ =gSineTable
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _0818D220
	asrs r1, r0, #0xc
	b _0818D226
	.align 2, 0
_0818D21C: .4byte gSineTable
_0818D220:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818D226:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_0818D22C:
	movs r0, #0
_0818D22E:
	cmp r0, #0
	beq _0818D2F8
	adds r0, r5, #0
	bl FUN_0818e6fc
	add r2, sp, #8
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _0818D29C @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r1, #0xee
	lsls r1, r1, #1
	adds r3, r5, r1
	strb r0, [r3]
	ldr r2, _0818D2A0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0818D2A4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0818D2A8 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _0818D2F8
	ldrb r1, [r3]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818D2B0
	ldr r3, _0818D2AC @ =0xFFFFFF00
	adds r1, r1, r3
	b _0818D2BE
	.align 2, 0
_0818D29C: .4byte 0x000004A4
_0818D2A0: .4byte 0x030046B8
_0818D2A4: .4byte 0x000003FF
_0818D2A8: .4byte 0x0203B400
_0818D2AC: .4byte 0xFFFFFF00
_0818D2B0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818D2BE
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0818D2BE:
	cmp r1, #0
	bge _0818D2C4
	rsbs r1, r1, #0
_0818D2C4:
	cmp r1, #0x20
	ble _0818D2F8
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818D2F0 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _0818D2F4 @ =0x0000046A
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	b _0818D3CE
	.align 2, 0
_0818D2F0: .4byte 0x00000469
_0818D2F4: .4byte 0x0000046A
_0818D2F8:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08190804
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_0818fdd8
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_0818f938
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0818f17c
	ldr r0, _0818D3A8 @ =0x00000484
	adds r6, r5, r0
	ldr r0, [r6]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0818D336
	adds r0, r5, #0
	bl FUN_08191a9c
_0818D336:
	adds r0, r5, #0
	bl FUN_0819267c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818D3CE
	ldr r2, _0818D3AC @ =0x00000D4C
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	bne _0818D3C4
	movs r1, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r6, _0818D3B0 @ =0x00000469
	adds r0, r5, r6
	strb r4, [r0]
	ldr r2, _0818D3B4 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0818D3B8 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0818D3BC @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r3, _0818D3C0 @ =0x00000F2C
	adds r2, r7, r3
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0818D3CE
	.align 2, 0
_0818D3A8: .4byte 0x00000484
_0818D3AC: .4byte 0x00000D4C
_0818D3B0: .4byte 0x00000469
_0818D3B4: .4byte 0x0000046A
_0818D3B8: .4byte Enemy_ClearStateBegun
_0818D3BC: .4byte 0x0000046B
_0818D3C0: .4byte 0x00000F2C
_0818D3C4:
	subs r0, #1
	strh r0, [r1]
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
_0818D3CE:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
