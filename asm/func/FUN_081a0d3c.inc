	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081A0D64 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A0D68
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A0D6A
	.align 2, 0
_081A0D64: .4byte 0x0000046C
_081A0D68:
	movs r0, #0
_081A0D6A:
	adds r7, r5, #0
	adds r7, #8
	cmp r0, #0
	bne _081A0D74
	b _081A0F00
_081A0D74:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _081A0DF0 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r0, #0xea
	lsls r0, r0, #4
	add r0, r8
	strb r1, [r0]
	ldr r0, _081A0DF4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _081A0DF8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A0DFC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081A0E00 @ =0x0203B400
	adds r0, r0, r4
	movs r1, #0xff
	ldrb r6, [r0]
	mov r4, sp
	ldr r3, _081A0E04 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	adds r7, r2, #0
	mov ip, r3
	cmp r0, #0
	blt _081A0E08
	asrs r1, r0, #0xc
	b _081A0E0E
	.align 2, 0
_081A0DF0: .4byte 0x0000046D
_081A0DF4: .4byte 0x03002BE0
_081A0DF8: .4byte 0x030046B8
_081A0DFC: .4byte 0x000003FF
_081A0E00: .4byte 0x0203B400
_081A0E04: .4byte gSineTable
_081A0E08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A0E0E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _081A0E2A
	asrs r0, r0, #0xc
	b _081A0E30
_081A0E2A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A0E30:
	strh r0, [r4, #4]
	mov r0, sp
	add r2, sp, #8
	ldrh r1, [r2]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _081A0EC0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	mov r3, sp
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r4, r5, #0
	adds r4, #8
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _081A0EC4 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _081A0EC8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	movs r1, #0xff
	ldr r3, _081A0ECC @ =0x00000F0C
	add r3, r8
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	adds r7, r4, #0
	cmp r0, #0
	blt _081A0ED0
	asrs r1, r0, #0xc
	b _081A0ED6
	.align 2, 0
_081A0EC0: .4byte 0xFFFF0000
_081A0EC4: .4byte 0x000003FF
_081A0EC8: .4byte 0x0203B400
_081A0ECC: .4byte 0x00000F0C
_081A0ED0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A0ED6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _081A0EF0
	asrs r0, r0, #0xc
	b _081A0EF6
_081A0EF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A0EF6:
	strh r0, [r3, #4]
	ldr r1, _081A0FA0 @ =0x00000E56
	add r1, r8
	movs r0, #1
	strh r0, [r1]
_081A0F00:
	movs r6, #0xea
	lsls r6, r6, #4
	add r6, r8
	ldrb r1, [r6]
	mov r4, sp
	lsls r1, r1, #3
	add r1, r8
	ldr r3, _081A0FA4 @ =0x00000E58
	adds r1, r1, r3
	ldrh r0, [r1]
	ldrh r2, [r5, #8]
	subs r0, r0, r2
	mov r2, sp
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_0819ef24
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _081A1000
	ldrb r1, [r6]
	lsls r1, r1, #3
	add r1, r8
	ldr r4, _081A0FA4 @ =0x00000E58
	adds r0, r1, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #8
	ldrsh r2, [r5, r3]
	subs r0, r0, r2
	adds r4, #4
	adds r1, r1, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r0, _081A0FA0 @ =0x00000E56
	add r0, r8
	mov r6, sp
	ldrb r3, [r5, #5]
	ldrh r4, [r0]
	ldr r2, _081A0FA8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A0FAC
	asrs r1, r0, #0xc
	b _081A0FB2
	.align 2, 0
_081A0FA0: .4byte 0x00000E56
_081A0FA4: .4byte 0x00000E58
_081A0FA8: .4byte gSineTable
_081A0FAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A0FB2:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _081A0FCC @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A0FD0
	asrs r0, r0, #0xc
	b _081A0FD6
	.align 2, 0
_081A0FCC: .4byte gSineTable
_081A0FD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A0FD6:
	strh r0, [r6, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r4, [r5, #0x14]
	adds r0, r0, r4
	strh r0, [r5, #0x14]
	ldr r2, _081A0FFC @ =0x00000F0C
	add r2, r8
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	b _081A1124
	.align 2, 0
_081A0FFC: .4byte 0x00000F0C
_081A1000:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _081A1010
	b _081A1124
_081A1010:
	ldr r3, _081A1098 @ =0x00000F0C
	add r3, r8
	ldr r2, _081A109C @ =0x00000E98
	add r2, r8
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _081A10A0 @ =0x00000F0E
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r5, #8]
	ldr r0, _081A10A4 @ =0x00000E9C
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	movs r0, #0
	strb r0, [r6]
	ldr r0, _081A10A8 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _081A10AC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A10B0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081A10B4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r4, r0, r2
	movs r1, #0xff
	mov r3, sp
	ands r4, r1
	ldr r2, _081A10B8 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	mov ip, r2
	cmp r0, #0
	blt _081A10BC
	asrs r1, r0, #0xc
	b _081A10C2
	.align 2, 0
_081A1098: .4byte 0x00000F0C
_081A109C: .4byte 0x00000E98
_081A10A0: .4byte 0x00000F0E
_081A10A4: .4byte 0x00000E9C
_081A10A8: .4byte 0x03002BE0
_081A10AC: .4byte 0x030046B8
_081A10B0: .4byte 0x000003FF
_081A10B4: .4byte 0x0203B400
_081A10B8: .4byte gSineTable
_081A10BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A10C2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _081A10DE
	asrs r0, r0, #0xc
	b _081A10E4
_081A10DE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A10E4:
	strh r0, [r3, #4]
	add r2, sp, #8
	mov r0, sp
	ldrh r1, [r0]
	ldrh r3, [r2]
	adds r1, r1, r3
	strh r1, [r2]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r2, #4]
	adds r0, r0, r4
	strh r0, [r2, #4]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _081A1120 @ =0x00000E56
	add r1, r8
	ldrh r0, [r1]
	lsrs r0, r0, #1
	strh r0, [r1]
	b _081A114C
	.align 2, 0
_081A1120: .4byte 0x00000E56
_081A1124:
	ldr r1, _081A1158 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081A1142
	ldr r1, _081A115C @ =0x00000E56
	add r1, r8
	ldrh r0, [r1]
	cmp r0, #0xb
	bhi _081A1142
	adds r0, #1
	strh r0, [r1]
_081A1142:
	ldr r2, _081A1158 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A114C:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A1158: .4byte 0x00000484
_081A115C: .4byte 0x00000E56
