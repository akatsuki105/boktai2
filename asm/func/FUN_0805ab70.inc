	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x20]
	adds r7, r1, #0
	str r2, [sp, #0x24]
	ldrb r0, [r7]
	cmp r0, #0
	bne _0805AB8A
	b _0805ACCA
_0805AB8A:
	movs r4, #0
	strb r4, [r7]
	adds r2, r7, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r7, #0
	bl FUN_0805a8d0
	adds r0, r7, #0
	adds r0, #0xe8
	ldr r2, [sp, #0x20]
	ldr r1, [r2, #0x20]
	str r4, [sp]
	movs r2, #4
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r3, _0805ACF0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0x40
	orrs r0, r2
	ldr r1, _0805ACF4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x14]
	ldr r5, _0805ACF8 @ =0x030046B8
	ldr r2, [r5]
	adds r2, #1
	ldr r4, _0805ACFC @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	ldr r3, _0805AD00 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r6, #1
	ands r1, r6
	adds r1, #1
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrb r3, [r7, #0xa]
	movs r6, #0xf
	ands r0, r6
	subs r3, r3, r0
	adds r3, #3
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r2, r2, #1
	ldr r0, _0805AD00 @ =0x0203B400
	adds r2, r2, r0
	ldrh r0, [r2]
	movs r2, #7
	mov sl, r2
	ands r0, r2
	ldrh r6, [r7, #0x10]
	adds r0, r0, r6
	adds r6, r7, #0
	adds r6, #0x14
	str r0, [sp]
	movs r0, #1
	mov r8, r0
	str r0, [sp, #4]
	movs r2, #2
	mov sb, r2
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	add r2, sp, #0x10
	bl FUN_080ddcc8
	ldr r0, [r5]
	adds r0, #1
	ands r0, r4
	lsls r1, r0, #1
	ldr r3, _0805AD00 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r2, #1
	ands r1, r2
	adds r1, #1
	adds r0, #1
	ands r0, r4
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r3, sl
	ands r0, r3
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	ldrb r3, [r7, #0xa]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	add r2, sp, #0x10
	bl FUN_080ddcc8
	ldr r0, [r5]
	adds r0, #1
	ands r0, r4
	lsls r1, r0, #1
	ldr r3, _0805AD00 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r2, #1
	ands r1, r2
	adds r1, #1
	adds r0, #1
	ands r0, r4
	str r0, [r5]
	lsls r2, r0, #1
	adds r2, r2, r3
	ldrh r3, [r2]
	movs r2, #0xf
	ands r3, r2
	ldrb r2, [r7, #0xa]
	adds r3, r3, r2
	adds r3, #3
	adds r0, #1
	ands r0, r4
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _0805AD00 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r2, sl
	ands r0, r2
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	add r2, sp, #0x10
	bl FUN_080ddcc8
	ldr r0, _0805AD04 @ =0x00000339
	bl PlaySound_082406e0
_0805ACCA:
	add r3, sp, #0x18
	ldrb r4, [r7, #0xa]
	ldrh r5, [r7, #0x10]
	ldr r2, _0805AD08 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r5, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _0805AD0C
	asrs r1, r0, #0xc
	b _0805AD12
	.align 2, 0
_0805ACF0: .4byte 0xFFFF0000
_0805ACF4: .4byte 0x0000FFFF
_0805ACF8: .4byte 0x030046B8
_0805ACFC: .4byte 0x000003FF
_0805AD00: .4byte 0x0203B400
_0805AD04: .4byte 0x00000339
_0805AD08: .4byte gSineTable
_0805AD0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805AD12:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AD2A
	asrs r0, r0, #0xc
	b _0805AD30
_0805AD2A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805AD30:
	strh r0, [r3, #4]
	adds r1, r7, #0
	adds r1, #0x14
	add r0, sp, #0x18
	ldrh r0, [r0]
	ldrh r2, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r6, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r6, #4]
	ldrh r6, [r1, #4]
	adds r0, r0, r6
	strh r0, [r1, #4]
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _0805AD62
	ldr r0, [sp, #0x20]
	adds r1, r7, #0
	ldr r2, [sp, #0x24]
	bl FUN_0805a6ec
	b _0805AD68
_0805AD62:
	ldrh r0, [r7, #6]
	adds r0, #1
	strh r0, [r7, #6]
_0805AD68:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
