	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08134CE4 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08134CE8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08134CEA
	.align 2, 0
_08134CE4: .4byte 0x0000046C
_08134CE8:
	movs r0, #0
_08134CEA:
	cmp r0, #0
	beq _08134D2C
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _08134D70 @ =0x0000046D
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _08134D74 @ =0x0000046B
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r1, r4, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08134D2C:
	ldr r0, _08134D78 @ =0x00000484
	adds r5, r4, r0
	ldr r0, [r5]
	movs r1, #0x30
	bl Mod
	cmp r0, #0
	bne _08134D42
	ldr r0, _08134D7C @ =0x000003D7
	bl PlaySound_082406e0
_08134D42:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	ldr r2, _08134D80 @ =0x05000002
	bl CpuSet
	ldr r0, [r5]
	cmp r0, #0x73
	ble _08134DDC
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrb r1, [r0]
	ldrb r0, [r4, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08134D88
	ldr r5, _08134D84 @ =0xFFFFFF00
	adds r1, r1, r5
	b _08134D96
	.align 2, 0
_08134D70: .4byte 0x0000046D
_08134D74: .4byte 0x0000046B
_08134D78: .4byte 0x00000484
_08134D7C: .4byte 0x000003D7
_08134D80: .4byte 0x05000002
_08134D84: .4byte 0xFFFFFF00
_08134D88:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08134D96
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_08134D96:
	movs r0, #0
	cmp r1, #0x1f
	bgt _08134D9E
	movs r0, #1
_08134D9E:
	cmp r0, #0
	beq _08134DDC
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r4, #5]
	movs r2, #6
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	ldr r5, _08134DD4 @ =0x00000469
	adds r0, r4, r5
	strb r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r2, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r1, [r0]
	ldr r0, _08134DD8 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08134E7A
	.align 2, 0
_08134DD4: .4byte 0x00000469
_08134DD8: .4byte 0x0000046C
_08134DDC:
	ldr r1, _08134DF4 @ =0x00000484
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0x3f
	bgt _08134DF8
	movs r5, #0x14
	movs r2, #8
	mov ip, r2
	movs r6, #4
	movs r7, #0xc3
	lsls r7, r7, #5
	b _08134E12
	.align 2, 0
_08134DF4: .4byte 0x00000484
_08134DF8:
	cmp r0, #0x73
	bgt _08134E06
	movs r5, #0xe
	movs r3, #8
	mov ip, r3
	movs r6, #8
	b _08134E0E
_08134E06:
	movs r5, #3
	movs r0, #8
	mov ip, r0
	movs r6, #6
_08134E0E:
	movs r7, #0x9b
	lsls r7, r7, #3
_08134E12:
	ldr r3, _08134E30 @ =gSineTable
	ldrb r2, [r4, #5]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08134E34
	asrs r0, r0, #0xc
	b _08134E3A
	.align 2, 0
_08134E30: .4byte gSineTable
_08134E34:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08134E3A:
	adds r1, r0, #0
	lsls r0, r2, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08134E4E
	asrs r2, r0, #0xc
	b _08134E54
_08134E4E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08134E54:
	ldrb r0, [r4, #5]
	adds r0, r0, r6
	strb r0, [r4, #5]
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	mov r1, ip
	adds r2, r7, #0
	bl FUN_081370f4
	ldr r3, _08134E84 @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08134E7A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08134E84: .4byte 0x00000484
