	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0814DF60 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814DF64
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814DF66
	.align 2, 0
_0814DF60: .4byte 0x0000046D
_0814DF64:
	movs r0, #0
_0814DF66:
	cmp r0, #0
	bne _0814DF6C
	b _0814E0F6
_0814DF6C:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	mov r3, sp
	adds r4, r5, #0
	adds r4, #8
	movs r0, #0xe1
	lsls r0, r0, #3
	adds r2, r7, r0
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
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl ArcTan2_8
	adds r4, r0, #0
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r2, r0, #6
	subs r1, r4, r2
	cmp r1, #0x80
	ble _0814DFC4
	ldr r0, _0814DFC0 @ =0xFFFFFF00
	b _0814DFD0
	.align 2, 0
_0814DFC0: .4byte 0xFFFFFF00
_0814DFC4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0814DFD2
	movs r0, #0x80
	lsls r0, r0, #1
_0814DFD0:
	adds r1, r1, r0
_0814DFD2:
	adds r0, r1, #0
	cmp r1, #0
	bge _0814DFDA
	rsbs r0, r1, #0
_0814DFDA:
	cmp r0, #0xf
	bgt _0814E030
	mov r3, sp
	movs r6, #0x18
	ldr r2, _0814E000 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0814E004
	asrs r1, r0, #0xc
	b _0814E00A
	.align 2, 0
_0814E000: .4byte gSineTable
_0814E004:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814E00A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0814E026
	asrs r0, r0, #0xc
	b _0814E02C
_0814E026:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814E02C:
	strh r0, [r3, #4]
	b _0814E0CE
_0814E030:
	cmp r1, #0
	ble _0814E07C
	adds r3, r2, #0
	adds r3, #0x10
	movs r1, #0xff
	mov r4, sp
	ands r3, r1
	movs r6, #0x18
	ldr r2, _0814E05C @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0814E060
	asrs r1, r0, #0xc
	b _0814E066
	.align 2, 0
_0814E05C: .4byte gSineTable
_0814E060:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814E066:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	bge _0814E0C2
	b _0814E0C6
_0814E07C:
	adds r3, r2, #0
	adds r3, #0xef
	movs r1, #0xff
	mov r4, sp
	ands r3, r1
	movs r6, #0x18
	ldr r2, _0814E0A4 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0814E0A8
	asrs r1, r0, #0xc
	b _0814E0AE
	.align 2, 0
_0814E0A4: .4byte gSineTable
_0814E0A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814E0AE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0814E0C6
_0814E0C2:
	asrs r0, r0, #0xc
	b _0814E0CC
_0814E0C6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814E0CC:
	strh r0, [r4, #4]
_0814E0CE:
	mov r0, sp
	ldrh r1, [r0]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xe9
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0814E0F6:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	bl Hitbox_Register
	ldr r0, [r5, #0x18]
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0814E14C
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0814E11E
	asrs r1, r0, #1
	b _0814E124
_0814E11E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0814E124:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0814E13E
	asrs r1, r0, #1
	b _0814E144
_0814E13E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0814E144:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0814E14C:
	adds r0, r5, #0
	movs r1, #5
	bl Enemy_PlayAnim
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814E19C
	ldr r4, _0814E1A4 @ =FUN_0814e1b0
	movs r3, #0x23
	ldr r0, _0814E1A8 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814E1AC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0814E19C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814E1A4: .4byte FUN_0814e1b0
_0814E1A8: .4byte 0x0000046D
_0814E1AC: .4byte 0x0000046B
