	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x14]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, [sp, #0x14]
	ldr r2, [r2, #0x44]
	str r2, [sp, #0x18]
	movs r3, #0
	mov r8, r3
	ldr r0, [sp, #0x14]
	subs r1, #0xa4
	adds r0, r0, r1
	mov sl, r0
_0819FFEE:
	movs r1, #0x40
	ldr r0, _081A0000 @ =0x00000E48
	add r0, sb
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A0004
	movs r0, #1
	b _081A0006
	.align 2, 0
_081A0000: .4byte 0x00000E48
_081A0004:
	movs r0, #0
_081A0006:
	cmp r0, #0
	bne _081A002A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x14]
	ldr r3, _081A0020 @ =0x00000474
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A0024
	movs r0, #1
	b _081A0026
	.align 2, 0
_081A0020: .4byte 0x00000474
_081A0024:
	movs r0, #0
_081A0026:
	cmp r0, #0
	beq _081A0068
_081A002A:
	mov r1, sl
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	ldr r1, [sp, #0x14]
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	ldr r1, _081A0060 @ =0x00000DA2
	add r1, sb
	movs r5, #1
	ldr r4, _081A0064 @ =0x00000D02
	add r4, sb
_081A0048:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldrh r0, [r4]
	orrs r0, r2
	strh r0, [r4]
	adds r1, #0x50
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _081A0048
	b _081A022E
	.align 2, 0
_081A0060: .4byte 0x00000DA2
_081A0064: .4byte 0x00000D02
_081A0068:
	mov r3, sl
	ldrh r1, [r3, #6]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r3, #6]
	ldr r1, [sp, #0x14]
	adds r1, #0xd8
	ldrh r2, [r1, #6]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	strh r0, [r1, #6]
	str r1, [sp, #0x1c]
	add r4, sp, #4
	add r7, sp, #0xc
	mov r0, r8
	adds r0, #1
	str r0, [sp, #0x20]
	movs r6, #5
	rsbs r6, r6, #0
	ldr r3, _081A00E0 @ =0x00000DA2
	add r3, sb
	movs r5, #1
	ldr r2, _081A00E4 @ =0x00000D02
	add r2, sb
_081A009C:
	ldrh r1, [r3]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r3]
	ldrh r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2]
	adds r3, #0x50
	adds r2, #0x50
	subs r5, #1
	cmp r5, #0
	bge _081A009C
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081A00E8 @ =0x05000002
	bl CpuSet
	ldr r2, [sp, #0x14]
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	mov r3, r8
	cmp r3, #1
	beq _081A00FC
	cmp r3, #1
	bgt _081A00EC
	cmp r3, #0
	beq _081A00F4
	b _081A010A
	.align 2, 0
_081A00E0: .4byte 0x00000DA2
_081A00E4: .4byte 0x00000D02
_081A00E8: .4byte 0x05000002
_081A00EC:
	mov r0, r8
	cmp r0, #2
	beq _081A0104
	b _081A010A
_081A00F4:
	ldr r0, _081A00F8 @ =0x0000FF88
	b _081A0106
	.align 2, 0
_081A00F8: .4byte 0x0000FF88
_081A00FC:
	ldr r0, _081A0100 @ =0x0000FFE2
	b _081A0106
	.align 2, 0
_081A0100: .4byte 0x0000FFE2
_081A0104:
	movs r0, #0x3c
_081A0106:
	strh r0, [r4]
	strh r0, [r4, #4]
_081A010A:
	movs r1, #0
	ldrsh r3, [r4, r1]
	ldr r2, _081A0130 @ =gSineTable
	ldr r1, [sp, #0x18]
	ldrb r0, [r1, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _081A0134
	asrs r0, r0, #0xc
	b _081A013A
	.align 2, 0
_081A0130: .4byte gSineTable
_081A0134:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A013A:
	adds r3, r0, #0
	movs r2, #4
	ldrsh r0, [r4, r2]
	ldr r2, [sp, #0x18]
	ldrb r1, [r2, #6]
	lsls r1, r1, #1
	adds r1, r1, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _081A0156
	asrs r0, r0, #0xc
	b _081A015C
_081A0156:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A015C:
	adds r1, r3, r0
	ldrh r3, [r7]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081A018C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldr r2, [sp, #0x18]
	ldrb r0, [r2, #6]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _081A0190
	asrs r0, r0, #0xc
	b _081A0194
	.align 2, 0
_081A018C: .4byte 0xFFFF0000
_081A0190:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_081A0194:
	adds r3, r0, #0
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldr r1, [sp, #0x18]
	ldrb r0, [r1, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081A01B6
	asrs r0, r0, #0xc
	b _081A01BC
_081A01B6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A01BC:
	adds r0, r3, r0
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _081A01F4 @ =0xFFFF0000
	ldr r1, [r7, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [r7, #4]
	mov r3, r8
	cmp r3, #0
	bne _081A01F8
	ldr r0, [sp, #0x1c]
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, sl
	bl Hitbox_Register
	b _081A0224
	.align 2, 0
_081A01F4: .4byte 0xFFFF0000
_081A01F8:
	mov r0, r8
	lsls r4, r0, #2
	add r4, r8
	lsls r4, r4, #4
	ldr r1, _081A0240 @ =0x00000D4C
	adds r0, r4, r1
	add r0, sb
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r2, _081A0244 @ =0x00000CAC
	adds r4, r4, r2
	add r4, sb
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_081A0224:
	ldr r3, [sp, #0x20]
	mov r8, r3
	cmp r3, #2
	bgt _081A022E
	b _0819FFEE
_081A022E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A0240: .4byte 0x00000D4C
_081A0244: .4byte 0x00000CAC
