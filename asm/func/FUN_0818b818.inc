	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _0818B844 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818B848
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818B84A
	.align 2, 0
_0818B844: .4byte 0x0000046C
_0818B848:
	movs r0, #0
_0818B84A:
	ldr r7, _0818B8A0 @ =0x00000F2C
	add r7, sl
	cmp r0, #0
	beq _0818B902
	ldr r3, _0818B8A4 @ =0x00000256
	adds r0, r5, r3
	ldrh r1, [r0]
	ldr r0, _0818B8A8 @ =0x00000ED6
	add r0, sl
	strh r1, [r0]
	ldrh r6, [r0]
	ldr r7, _0818B8AC @ =0x00000F7C
	add r7, sl
	ldr r0, _0818B8B0 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818B8B4
	adds r0, #4
	b _0818B8C0
	.align 2, 0
_0818B8A0: .4byte 0x00000F2C
_0818B8A4: .4byte 0x00000256
_0818B8A8: .4byte 0x00000ED6
_0818B8AC: .4byte 0x00000F7C
_0818B8B0: .4byte 0x030046A4
_0818B8B4:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0818B8C0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r7, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	movs r2, #0x80
	lsls r2, r2, #8
	ldr r1, _0818B8E8 @ =0x00000F2C
	add r1, sl
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _0818B8EC
	movs r0, #1
	b _0818B8EE
	.align 2, 0
_0818B8E8: .4byte 0x00000F2C
_0818B8EC:
	movs r0, #0
_0818B8EE:
	cmp r0, #0
	bne _0818B902
	ldr r0, _0818B930 @ =0x000003E5
	bl PlaySound_082406e0
	movs r0, #0x80
	lsls r0, r0, #8
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
_0818B902:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r1, _0818B934 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818B93C
	ldr r0, _0818B938 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0818B94C
	.align 2, 0
_0818B930: .4byte 0x000003E5
_0818B934: .4byte 0x0000A02F
_0818B938: .4byte 0x00000482
_0818B93C:
	ldr r1, _0818B970 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0818B94C
	movs r0, #1
	strh r0, [r2]
_0818B94C:
	ldr r3, _0818B974 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818B978
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
	b _0818B990
	.align 2, 0
_0818B970: .4byte 0x00000482
_0818B974: .4byte 0x0000025D
_0818B978:
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
_0818B990:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	adds r3, r0, #0
	cmp r1, #0x80
	ble _0818B9AC
	ldr r2, _0818B9A8 @ =0xFFFFFF00
	adds r1, r1, r2
	b _0818B9BA
	.align 2, 0
_0818B9A8: .4byte 0xFFFFFF00
_0818B9AC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818B9BA
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0818B9BA:
	adds r6, r1, #0
	adds r0, r6, #0
	cmp r6, #0
	bge _0818B9C4
	rsbs r0, r6, #0
_0818B9C4:
	cmp r0, #8
	ble _0818BA1C
	ldr r2, _0818B9E8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0818B9EC
	asrs r0, r0, #0xc
	b _0818B9F2
	.align 2, 0
_0818B9E8: .4byte gSineTable
_0818B9EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818B9F2:
	adds r1, r0, #0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _0818BA0A
	asrs r2, r0, #0xc
	b _0818BA10
_0818BA0A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818BA10:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
_0818BA1C:
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	adds r2, r5, #0
	adds r2, #0x10
	ldrh r0, [r5, #0x10]
	ldrh r1, [r5, #8]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r3, [r3, #4]
	adds r1, r1, r3
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0818BA64
	cmp r1, #0
	blt _0818BA64
	ldr r0, _0818BA6C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0818BA64
	ldr r0, _0818BA70 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818BA74
_0818BA64:
	movs r2, #0
	mov r8, r2
	b _0818BA84
	.align 2, 0
_0818BA6C: .4byte 0x030046A8
_0818BA70: .4byte 0x030046AC
_0818BA74:
	ldr r0, _0818BB00 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
	mov r8, r0
_0818BA84:
	ldr r0, _0818BB04 @ =0x00000ED6
	add r0, sl
	ldrh r0, [r0]
	cmp r0, r8
	beq _0818BAD2
	mov r4, sp
	ldr r2, _0818BB08 @ =0x00000F7C
	add r2, sl
	ldrh r1, [r2]
	mov r0, sp
	ldrh r0, [r0]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #8
	bl Div
	ldrh r1, [r5, #0x10]
	adds r1, r1, r0
	strh r1, [r5, #0x10]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #8
	bl Div
	ldrh r1, [r5, #0x14]
	adds r1, r1, r0
	strh r1, [r5, #0x14]
_0818BAD2:
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #8
	bl FUN_0818fdd8
	ldr r2, _0818BB0C @ =gSineTable
	ldr r3, _0818BB10 @ =0x00000484
	adds r0, r5, r3
	movs r1, #0xff
	ldrb r0, [r0]
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0818BB14
	asrs r1, r0, #8
	b _0818BB1A
	.align 2, 0
_0818BB00: .4byte 0x030046A4
_0818BB04: .4byte 0x00000ED6
_0818BB08: .4byte 0x00000F7C
_0818BB0C: .4byte gSineTable
_0818BB10: .4byte 0x00000484
_0818BB14:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0818BB1A:
	ldr r0, _0818BB30 @ =0x00000ADA
	add r0, sl
	strh r1, [r0]
	movs r1, #0x10
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0818BB34
	movs r0, #1
	b _0818BB36
	.align 2, 0
_0818BB30: .4byte 0x00000ADA
_0818BB34:
	movs r0, #0
_0818BB36:
	cmp r0, #0
	beq _0818BB4E
	adds r0, r5, #0
	bl FUN_08191a9c
	adds r0, r5, #0
	bl FUN_0819267c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818BC10
	b _0818BB58
_0818BB4E:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x14
	bl FUN_08191774
_0818BB58:
	adds r0, r6, #0
	cmp r6, #0
	bge _0818BB60
	rsbs r0, r6, #0
_0818BB60:
	cmp r0, #7
	bgt _0818BBE0
	ldr r0, _0818BB7C @ =0x00000ED6
	add r0, sl
	ldrh r0, [r0]
	cmp r0, r8
	bne _0818BC06
	movs r1, #0x10
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0818BB80
	movs r0, #1
	b _0818BB82
	.align 2, 0
_0818BB7C: .4byte 0x00000ED6
_0818BB80:
	movs r0, #0
_0818BB82:
	adds r2, r0, #0
	cmp r2, #0
	beq _0818BBB0
	movs r2, #0xe
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _0818BBAC @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	b _0818BBD0
	.align 2, 0
_0818BBAC: .4byte 0x00000484
_0818BBB0:
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0818BBD8 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _0818BBDC @ =0x0000046C
	adds r1, r5, r2
_0818BBD0:
	movs r0, #1
	strb r0, [r1]
	b _0818BC06
	.align 2, 0
_0818BBD8: .4byte 0x00000484
_0818BBDC: .4byte 0x0000046C
_0818BBE0:
	cmp r6, #0
	ble _0818BBF8
	ldr r3, _0818BBF4 @ =0x00000482
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #2
	ldrb r1, [r5, #5]
	adds r0, r0, r1
	b _0818BC04
	.align 2, 0
_0818BBF4: .4byte 0x00000482
_0818BBF8:
	ldr r2, _0818BC20 @ =0x00000482
	adds r0, r5, r2
	ldrh r1, [r0]
	lsls r1, r1, #2
	ldrb r0, [r5, #5]
	subs r0, r0, r1
_0818BC04:
	strb r0, [r5, #5]
_0818BC06:
	ldr r3, _0818BC24 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818BC10:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818BC20: .4byte 0x00000482
_0818BC24: .4byte 0x00000484
