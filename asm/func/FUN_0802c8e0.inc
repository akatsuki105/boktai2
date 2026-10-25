	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x38
	adds r7, r0, #0
	mov r8, r7
	adds r6, r7, #0
	adds r6, #0x48
	adds r1, r7, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802C90E
	strb r2, [r1]
	adds r0, r7, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r0, #1
	b _0802C910
_0802C90E:
	movs r0, #0
_0802C910:
	cmp r0, #0
	beq _0802C91C
	movs r0, #8
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802C91C:
	movs r0, #0xb9
	lsls r0, r0, #1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C92A
	b _0802CA24
_0802C92A:
	mov r3, sp
	ldrb r4, [r6, #5]
	movs r5, #0xc8
	ldr r2, _0802C94C @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0802C950
	asrs r1, r0, #0xc
	b _0802C956
	.align 2, 0
_0802C94C: .4byte gSineTable
_0802C950:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802C956:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0802C96E
	asrs r0, r0, #0xc
	b _0802C974
_0802C96E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802C974:
	strh r0, [r3, #4]
	mov r4, sp
	mov r1, sp
	ldrh r0, [r6, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r3, [r6, #0xa]
	adds r0, r0, r3
	strh r0, [r4, #2]
	ldrh r0, [r6, #0xc]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	ldr r5, _0802CA18 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r5
	ldr r1, _0802CA1C @ =0x0000FF38
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r2, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, [sp, #0x10]
	ands r0, r5
	movs r1, #0xc8
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r3, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r4, [r3, #4]
	adds r0, r0, r4
	strh r0, [r3, #4]
	ldr r0, _0802CA20 @ =0x0000016B
	add r0, r8
	ldrb r1, [r0]
	mov r0, r8
	bl FUN_08028720
	adds r2, r0, #0
	cmp r2, #0
	bge _0802CA06
	b _0802CB44
_0802CA06:
	movs r0, #7
	adds r1, r7, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r1, #0x16
	movs r0, #0
	str r0, [r1]
	subs r1, #0x14
	b _0802CC78
	.align 2, 0
_0802CA18: .4byte 0xFFFF0000
_0802CA1C: .4byte 0x0000FF38
_0802CA20: .4byte 0x0000016B
_0802CA24:
	add r3, sp, #0x18
	ldrb r4, [r6, #5]
	ldr r2, _0802CA48 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	mov ip, r3
	cmp r0, #0
	blt _0802CA4C
	asrs r1, r0, #0xc
	b _0802CA52
	.align 2, 0
_0802CA48: .4byte gSineTable
_0802CA4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802CA52:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	muls r0, r1, r0
	cmp r0, #0
	blt _0802CA6C
	asrs r0, r0, #0xc
	b _0802CA72
_0802CA6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802CA72:
	strh r0, [r3, #4]
	add r5, sp, #0x18
	ldrh r0, [r6, #8]
	ldrh r3, [r5]
	adds r0, r0, r3
	strh r0, [r5]
	mov r4, ip
	ldrh r0, [r4, #2]
	ldrh r1, [r6, #0xa]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r6, #0xc]
	ldrh r2, [r4, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	ldr r4, _0802CB30 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r4
	ldr r1, _0802CB34 @ =0x0000FF80
	orrs r0, r1
	str r0, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r2, #4]
	ldrh r0, [r5]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r2, #2]
	mov r3, ip
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, [sp, #0x28]
	ands r0, r4
	movs r1, #0x80
	orrs r0, r1
	str r0, [sp, #0x28]
	add r3, sp, #0x28
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r3, #4]
	ldrh r0, [r5]
	ldrh r4, [r3]
	adds r0, r0, r4
	strh r0, [r3]
	ldrh r0, [r3, #2]
	mov r4, ip
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	ldr r0, _0802CB38 @ =0x0000016B
	add r0, r8
	ldrb r1, [r0]
	mov r0, r8
	bl FUN_08028720
	adds r2, r0, #0
	cmp r2, #0
	blt _0802CB44
	ldr r1, _0802CB3C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r0, #0x20]
	ands r0, r1
	rsbs r0, r0, #0
	lsrs r3, r0, #0x1f
	cmp r3, #0
	bne _0802CB44
	ldr r0, _0802CB40 @ =0x00000173
	add r0, r8
	strb r2, [r0]
	movs r0, #8
	adds r1, r7, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbc
	str r3, [r0]
	adds r1, #2
	b _0802CC78
	.align 2, 0
_0802CB30: .4byte 0xFFFF0000
_0802CB34: .4byte 0x0000FF80
_0802CB38: .4byte 0x0000016B
_0802CB3C: .4byte 0x03002BE0
_0802CB40: .4byte 0x00000173
_0802CB44:
	movs r2, #0xc8
	lsls r2, r2, #1
	mov ip, r2
	mov r4, r8
	adds r4, #0x48
	add r3, sp, #0x30
	ldrb r6, [r4, #5]
	ldr r2, _0802CB74 @ =gSineTable
	adds r0, r6, #0
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
	adds r5, r3, #0
	cmp r0, #0
	blt _0802CB78
	asrs r1, r0, #0xc
	b _0802CB7E
	.align 2, 0
_0802CB74: .4byte gSineTable
_0802CB78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802CB7E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0802CB9A
	asrs r0, r0, #0xc
	b _0802CBA0
_0802CB9A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802CBA0:
	strh r0, [r3, #4]
	add r1, sp, #0x30
	ldrh r0, [r4, #8]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r5, #2]
	ldrh r3, [r4, #0xa]
	adds r0, r0, r3
	strh r0, [r5, #2]
	ldrh r1, [r4, #0xc]
	ldrh r4, [r5, #4]
	adds r1, r1, r4
	strh r1, [r5, #4]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0802CBDE
	cmp r1, #0
	blt _0802CBDE
	ldr r0, _0802CBE4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0802CBDE
	ldr r0, _0802CBE8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0802CBEC
_0802CBDE:
	movs r4, #0
	b _0802CBFA
	.align 2, 0
_0802CBE4: .4byte 0x030046A8
_0802CBE8: .4byte 0x030046AC
_0802CBEC:
	ldr r0, _0802CC0C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0802CBFA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0802CC10
	adds r0, #4
	b _0802CC1C
	.align 2, 0
_0802CC0C: .4byte 0x030046A4
_0802CC10:
	ldr r0, _0802CC30 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0802CC1C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0802CC34
	cmp r2, #2
	beq _0802CC38
	b _0802CC3C
	.align 2, 0
_0802CC30: .4byte 0x030046A4
_0802CC34:
	ldrb r0, [r5, #4]
	b _0802CC3A
_0802CC38:
	ldrb r0, [r5]
_0802CC3A:
	subs r1, r1, r0
_0802CC3C:
	movs r0, #0xb2
	lsls r0, r0, #1
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, r1, r0
	ldr r3, _0802CC80 @ =0x000001FF
	adds r0, r0, r3
	ldr r1, _0802CC84 @ =0x000002FE
	movs r2, #0
	cmp r0, r1
	bls _0802CC56
	movs r2, #1
_0802CC56:
	cmp r2, #0
	bne _0802CC64
	adds r0, r7, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802CC88
_0802CC64:
	movs r0, #9
	adds r2, r7, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa8
_0802CC78:
	movs r0, #1
	strb r0, [r1]
	b _0802CC92
	.align 2, 0
_0802CC80: .4byte 0x000001FF
_0802CC84: .4byte 0x000002FE
_0802CC88:
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802CC92:
	add sp, #0x38
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
