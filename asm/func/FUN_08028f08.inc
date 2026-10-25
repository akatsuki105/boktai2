	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	adds r4, r6, #0
	adds r0, #0x48
	str r0, [sp, #0x18]
	ldr r1, _08028F54 @ =0x0000104C
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _08028F28
	b _08029150
_08028F28:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08028F3A
	movs r0, #0
	strb r0, [r1]
_08028F3A:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _08028F44
	b _08029068
_08028F44:
	ldr r3, _08028F58 @ =0x00000864
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _08028F5C
	movs r3, #1
	b _08028F62
	.align 2, 0
_08028F54: .4byte 0x0000104C
_08028F58: .4byte 0x00000864
_08028F5C:
	ldr r1, _08028FB4 @ =0x00000899
	adds r0, r6, r1
	ldrb r3, [r0]
_08028F62:
	movs r2, #0
	mov sb, r2
	ldr r2, _08028FB8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08028FBC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08028FC0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r5, [r0]
	movs r0, #0xc0
	ands r5, r0
	lsls r0, r3, #2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r2, r4, r3
	add r4, sp, #8
	movs r1, #0xc8
	lsls r1, r1, #1
	mov sl, r1
	adds r7, r2, r0
	movs r2, #2
	mov r8, r2
_08028F94:
	ldr r2, _08028FC4 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08028FC8
	asrs r1, r0, #0xc
	b _08028FCE
	.align 2, 0
_08028FB4: .4byte 0x00000899
_08028FB8: .4byte 0x030046B8
_08028FBC: .4byte 0x000003FF
_08028FC0: .4byte 0x0203B400
_08028FC4: .4byte gSineTable
_08028FC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08028FCE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	ldr r2, _08028FF0 @ =gSineTable
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08028FF4
	asrs r3, r0, #0xc
	b _08028FFA
	.align 2, 0
_08028FF0: .4byte gSineTable
_08028FF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08028FFA:
	strh r3, [r4, #4]
	ldr r2, [r7]
	ldrh r0, [r2]
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	adds r0, r3, r0
	strh r0, [r4, #4]
	ldr r2, [sp, #0x18]
	ldrh r0, [r2, #0xa]
	adds r0, #0xa4
	strh r0, [r4, #2]
	ldr r2, [r7]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #0
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r3, [r7]
	ldr r1, _08029064 @ =0x0000104C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	str r1, [sp]
	mov r2, sb
	str r2, [sp, #4]
	add r1, sp, #8
	movs r2, #0
	bl FUN_0805a360
	adds r5, #0x55
	movs r3, #0x40
	add sb, r3
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _08028F94
	b _08029146
	.align 2, 0
_08029064: .4byte 0x0000104C
_08029068:
	ldr r2, _080290C0 @ =0x00000899
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r0, r6, #0
	adds r0, #0xa1
	ldrb r0, [r0]
	adds r0, #5
	lsls r0, r0, #0x1d
	lsrs r0, r0, #0x18
	adds r5, r0, #0
	subs r5, #0x30
	movs r0, #0
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov sl, r1
	movs r0, #0x86
	lsls r0, r0, #1
	adds r2, r6, r0
	add r4, sp, #0x10
	adds r7, r6, #0
	adds r7, #0x50
	movs r1, #6
	mov r8, r1
	lsls r0, r3, #2
	adds r2, r2, r0
	str r2, [sp, #0x1c]
_0802909E:
	ldr r2, _080290C4 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _080290C8
	asrs r1, r0, #0xc
	b _080290CE
	.align 2, 0
_080290C0: .4byte 0x00000899
_080290C4: .4byte gSineTable
_080290C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080290CE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	ldr r1, _080290F0 @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _080290F4
	asrs r0, r0, #0xc
	b _080290FA
	.align 2, 0
_080290F0: .4byte gSineTable
_080290F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080290FA:
	strh r0, [r4, #4]
	add r1, sp, #0x10
	ldr r2, [sp, #0x18]
	ldrh r0, [r2, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r1, [r4, #2]
	ldrh r0, [r7, #2]
	adds r1, r1, r0
	ldrh r0, [r7, #4]
	ldrh r2, [r4, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	adds r1, #0xa4
	strh r1, [r4, #2]
	ldr r0, [sp, #0x1c]
	ldr r3, [r0]
	ldr r1, _08029160 @ =0x0000104C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xc
	str r1, [sp]
	mov r2, sb
	str r2, [sp, #4]
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0805a360
	movs r3, #0x18
	add sb, r3
	adds r5, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _0802909E
_08029146:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0xff
	strb r0, [r1]
_08029150:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029160: .4byte 0x0000104C
