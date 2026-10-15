	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r6, r5, #0
	adds r6, #0x48
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r0, r0, r5
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F4DC0
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r1, #0xbd
	lsls r1, r1, #1
	adds r3, r5, r1
	movs r2, #0
	movs r1, #0
	movs r0, #0x3c
	strh r0, [r3]
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	mov r0, ip
	strb r2, [r0]
_081F4DC0:
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F4E2C
	ldr r0, _081F4DF0 @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _081F4DF4 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r2, _081F4DF8 @ =0x0203B400
	adds r1, r1, r2
	ldrb r0, [r1]
	cmp r0, #0x3f
	bgt _081F4DFC
	ldr r1, [r4, #0x18]
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0x15
	b _081F4E0A
	.align 2, 0
_081F4DF0: .4byte 0x030046B8
_081F4DF4: .4byte 0x000003FF
_081F4DF8: .4byte 0x0203B400
_081F4DFC:
	cmp r0, #0x4d
	bgt _081F4E12
	ldr r1, [r4, #0x18]
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0x16
_081F4E0A:
	movs r3, #0
	bl AuxAnim_SetAnim
	b _081F4E22
_081F4E12:
	ldr r1, [r4, #0x18]
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0x14
	movs r3, #0
	bl AuxAnim_SetAnim
_081F4E22:
	movs r3, #0xba
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
_081F4E2C:
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _081F4F2E
	add r3, sp, #4
	adds r4, r7, #0
	adds r4, #0x1c
	adds r0, r5, #0
	adds r0, #0xf8
	ldr r2, [r0]
	ldrh r0, [r2]
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r3, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl ArcTan2_8
	ldr r3, _081F4E80 @ =0x00000175
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _081F4E88
	ldr r0, _081F4E84 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081F4E96
	.align 2, 0
_081F4E80: .4byte 0x00000175
_081F4E84: .4byte 0xFFFFFF00
_081F4E88:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081F4E96
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081F4E96:
	movs r3, #0xbf
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081F4F32
	adds r0, r1, #0
	cmp r1, #0
	bge _081F4EAA
	rsbs r0, r1, #0
_081F4EAA:
	cmp r0, #2
	ble _081F4F28
	cmp r1, #0
	bge _081F4EE8
	ldr r2, _081F4ED8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081F4EDC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081F4EE0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r3, _081F4EE4 @ =0x00000175
	adds r2, r5, r3
	movs r0, #1
	ands r1, r0
	adds r1, #1
	ldrb r0, [r2]
	subs r0, r0, r1
	b _081F4F0A
	.align 2, 0
_081F4ED8: .4byte 0x030046B8
_081F4EDC: .4byte 0x000003FF
_081F4EE0: .4byte 0x0203B400
_081F4EE4: .4byte 0x00000175
_081F4EE8:
	ldr r2, _081F4F18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081F4F1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081F4F20 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r3, _081F4F24 @ =0x00000175
	adds r2, r5, r3
	movs r0, #1
	ands r1, r0
	adds r1, #1
	ldrb r0, [r2]
	adds r0, r0, r1
_081F4F0A:
	strb r0, [r2]
	movs r0, #0xbf
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	b _081F4F2E
	.align 2, 0
_081F4F18: .4byte 0x030046B8
_081F4F1C: .4byte 0x000003FF
_081F4F20: .4byte 0x0203B400
_081F4F24: .4byte 0x00000175
_081F4F28:
	movs r0, #0
	strh r0, [r2]
	b _081F4F32
_081F4F2E:
	subs r0, #1
	strh r0, [r1]
_081F4F32:
	ldr r1, _081F4F64 @ =0x00000175
	adds r0, r5, r1
	ldr r2, _081F4F68 @ =0x00000173
	adds r1, r5, r2
	subs r2, #0xf
	adds r3, r5, r2
	ldrb r4, [r0]
	ldrb r1, [r1]
	mov ip, r1
	ldr r2, _081F4F6C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081F4F70
	asrs r1, r0, #0xc
	b _081F4F76
	.align 2, 0
_081F4F64: .4byte 0x00000175
_081F4F68: .4byte 0x00000173
_081F4F6C: .4byte 0x085B0A08
_081F4F70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F4F76:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081F4F92
	asrs r0, r0, #0xc
	b _081F4F98
_081F4F92:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F4F98:
	strh r0, [r3, #4]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _081F4FC0
	ldr r3, _081F5038 @ =0x00000173
	adds r2, r5, r3
	ldrb r1, [r2]
	adds r3, #0xd
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r1, r0
	bhs _081F4FC0
	adds r0, r1, #1
	strb r0, [r2]
_081F4FC0:
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	movs r3, #0xbd
	lsls r3, r3, #1
	adds r4, r5, r3
	ldrh r0, [r4]
	cmp r0, #0
	beq _081F4FFE
	adds r0, r5, #0
	adds r0, #0xf8
	ldr r0, [r0]
	movs r1, #2
	ldrsh r0, [r0, r1]
	movs r2, #0x1e
	ldrsh r1, [r7, r2]
	subs r1, #0xc8
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	ldrh r1, [r7, #0x1e]
	adds r1, r1, r0
	strh r1, [r7, #0x1e]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
_081F4FFE:
	movs r3, #0xb4
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r6, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F503C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081F5044
	.align 2, 0
_081F5038: .4byte 0x00000173
_081F503C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F5044:
	str r0, [r7]
	ldrb r0, [r6, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F5068
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081F5070
_081F5068:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F5070:
	str r0, [r7]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r3, _081F50A8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #7]
	cmp r0, r1
	blo _081F50EE
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F50B2
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081F50AC
	ldrb r0, [r6, #5]
	subs r0, #1
	strh r0, [r6, #8]
	movs r2, #1
	b _081F50C8
	.align 2, 0
_081F50A8: .4byte 0x0000FFFF
_081F50AC:
	subs r0, #1
	strh r0, [r6, #8]
	b _081F50C6
_081F50B2:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081F50C6
	strh r1, [r6, #8]
	movs r2, #1
	b _081F50C8
_081F50C6:
	movs r2, #0
_081F50C8:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F50F0
	movs r0, #1
	strb r0, [r6, #7]
	b _081F50F0
_081F50EE:
	movs r2, #0
_081F50F0:
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_081f4858
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081F511C
	subs r0, #1
	strh r0, [r1]
	b _081F5130
_081F511C:
	movs r3, #0xb7
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #3
	strb r0, [r1]
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_081F5130:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
