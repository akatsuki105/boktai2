	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081D016C @ =0x03000188
	ldr r4, [r0]
	adds r7, r6, #0
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _081D0112
	b _081D02A8
_081D0112:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r0, #0xba
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	movs r1, #0x70
	adds r1, r1, r6
	mov sb, r1
	cmp r0, #0
	beq _081D017E
	adds r0, r6, #0
	bl FUN_081cfdb8
	ldr r1, [r4, #0x18]
	adds r5, r6, #0
	adds r5, #0xb0
	ldrb r3, [r5]
	movs r4, #0
	str r4, [sp]
	mov r0, sb
	movs r2, #0
	bl FUN_08236fac
	mov r2, r8
	strb r4, [r2]
	ldrh r0, [r5]
	cmp r0, #1
	bgt _081D017E
	cmp r0, #0
	blt _081D017E
	ldr r0, _081D0170 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081D0178
	ldr r0, _081D0174 @ =0x0000026D
	bl PlaySound_082406e0
	b _081D017E
	.align 2, 0
_081D016C: .4byte 0x03000188
_081D0170: .4byte 0x030047A4
_081D0174: .4byte 0x0000026D
_081D0178:
	ldr r0, _081D01D4 @ =0x000001AB
	bl PlaySound_082406e0
_081D017E:
	adds r0, r6, #0
	adds r0, #0x78
	ldrh r1, [r0]
	cmp r1, #0
	bne _081D0190
	adds r0, #6
	ldrh r0, [r0]
	cmp r0, #2
	bhi _081D019E
_081D0190:
	cmp r1, #1
	bne _081D01A4
	adds r0, r6, #0
	adds r0, #0x7e
	ldrh r0, [r0]
	cmp r0, #0
	beq _081D01A4
_081D019E:
	adds r0, r6, #0
	bl FUN_081cfa24
_081D01A4:
	mov r4, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x70]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D01D8
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D01E0
	.align 2, 0
_081D01D4: .4byte 0x000001AB
_081D01D8:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D01E0:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0204
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D020C
_081D0204:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D020C:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D0244 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D028A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D024E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D0248
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D0264
	.align 2, 0
_081D0244: .4byte 0x0000FFFF
_081D0248:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D0262
_081D024E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D0262
	strh r1, [r4, #8]
	movs r2, #1
	b _081D0264
_081D0262:
	movs r2, #0
_081D0264:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D028C
	movs r0, #1
	strb r0, [r4, #7]
	b _081D028C
_081D028A:
	movs r2, #0
_081D028C:
	cmp r2, #0
	beq _081D02A8
	adds r1, r6, #0
	adds r1, #0xb6
	movs r0, #6
	strh r0, [r1]
	adds r2, r6, #0
	adds r2, #0xb8
	ldrh r1, [r2]
	ldr r0, _081D02B8 @ =0x0000FFDF
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
_081D02A8:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D02B8: .4byte 0x0000FFDF
