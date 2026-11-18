	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r1, _0819FE14 @ =0x00000E44
	add r1, sl
	ldrh r0, [r1]
	cmp r0, #0
	bne _0819FE18
	movs r1, #3
	b _0819FE1C
	.align 2, 0
_0819FE14: .4byte 0x00000E44
_0819FE18:
	ldrh r0, [r1]
	subs r1, r0, #1
_0819FE1C:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r2, _0819FE68 @ =0x0000073C
	adds r0, r0, r2
	mov r3, sl
	adds r7, r3, r0
	movs r0, #0
	mov r8, r0
	add r4, sp, #4
	mov r1, sp
	adds r1, #0xc
	str r1, [sp, #0x14]
	ldr r6, _0819FE6C @ =0x0000095C
	add r6, sl
	mov sb, r1
_0819FE3C:
	movs r2, #0
	str r2, [sp]
	mov r0, sp
	add r1, sp, #4
	ldr r2, _0819FE70 @ =0x05000002
	bl CpuSet
	ldr r0, _0819FE74 @ =0x00000A4C
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	mov r3, r8
	cmp r3, #1
	beq _0819FE90
	cmp r3, #1
	bgt _0819FE78
	cmp r3, #0
	beq _0819FE80
	b _0819FEA4
	.align 2, 0
_0819FE68: .4byte 0x0000073C
_0819FE6C: .4byte 0x0000095C
_0819FE70: .4byte 0x05000002
_0819FE74: .4byte 0x00000A4C
_0819FE78:
	mov r0, r8
	cmp r0, #2
	beq _0819FE9C
	b _0819FEA4
_0819FE80:
	ldr r0, _0819FE8C @ =0x0000FF88
	strh r0, [r4]
	mov r1, sp
	strh r0, [r1, #8]
	b _0819FEA4
	.align 2, 0
_0819FE8C: .4byte 0x0000FF88
_0819FE90:
	ldr r0, _0819FE98 @ =0x0000FFE2
	strh r0, [r4]
	strh r0, [r4, #4]
	b _0819FEA4
	.align 2, 0
_0819FE98: .4byte 0x0000FFE2
_0819FE9C:
	movs r0, #0x3c
	strh r0, [r4]
	mov r2, sp
	strh r0, [r2, #8]
_0819FEA4:
	movs r0, #0
	ldrsh r3, [r4, r0]
	ldr r2, _0819FEC8 @ =gSineTable
	ldrb r0, [r7, #6]
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
	blt _0819FECC
	asrs r0, r0, #0xc
	b _0819FED2
	.align 2, 0
_0819FEC8: .4byte gSineTable
_0819FECC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819FED2:
	adds r3, r0, #0
	movs r2, #4
	ldrsh r0, [r4, r2]
	ldrb r1, [r7, #6]
	lsls r1, r1, #1
	adds r1, r1, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819FEEC
	asrs r0, r0, #0xc
	b _0819FEF2
_0819FEEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819FEF2:
	adds r1, r3, r0
	ldr r3, [sp, #0x14]
	ldrh r3, [r3]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819FF24 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldrb r0, [r7, #6]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _0819FF28
	asrs r0, r0, #0xc
	b _0819FF2C
	.align 2, 0
_0819FF24: .4byte 0xFFFF0000
_0819FF28:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_0819FF2C:
	adds r3, r0, #0
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldrb r0, [r7, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0819FF4C
	asrs r0, r0, #0xc
	b _0819FF52
_0819FF4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819FF52:
	adds r0, r3, r0
	mov r2, sb
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _0819FF98 @ =0xFFFF0000
	mov r3, sb
	ldr r1, [r3, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [r3, #4]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	bl Hitbox_Register
	adds r6, #0x50
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #2
	bgt _0819FF88
	b _0819FE3C
_0819FF88:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819FF98: .4byte 0xFFFF0000
