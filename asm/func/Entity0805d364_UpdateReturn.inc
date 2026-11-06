	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0805CE3C
	b _0805CF40
_0805CE3C:
	movs r0, #0
	strb r0, [r7]
	adds r2, r7, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r4, _0805CE90 @ =0x0203B400
	ldr r3, _0805CE94 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0805CE98 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	mov r4, sp
	adds r2, r1, #0
	adds r2, #0x10
	ldr r1, _0805CE9C @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _0805CEA0
	asrs r3, r0, #0xc
	b _0805CEA6
	.align 2, 0
_0805CE90: .4byte 0x0203B400
_0805CE94: .4byte 0x030046B8
_0805CE98: .4byte 0x000003FF
_0805CE9C: .4byte gSineTable
_0805CEA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805CEA6:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r2, r0
	cmp r0, #0
	blt _0805CEBE
	asrs r0, r0, #0xc
	b _0805CEC4
_0805CEBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CEC4:
	strh r0, [r4, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	mov r3, r8
	adds r3, #0x38
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r4, r8
	ldrh r4, [r4, #0x38]
	adds r0, r0, r4
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	movs r3, #0x14
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r5, #0x18
	ldrsh r2, [r7, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805CF58 @ =0x0203B400
	ldr r2, _0805CF5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805CF60 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #8
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strb r0, [r7, #7]
	movs r0, #0x10
	strh r0, [r7, #0x10]
_0805CF40:
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	cmp r0, #0
	beq _0805CF64
	movs r0, #5
	movs r1, #0
	strb r0, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	strh r1, [r7, #4]
	b _0805D092
	.align 2, 0
_0805CF58: .4byte 0x0203B400
_0805CF5C: .4byte 0x030046B8
_0805CF60: .4byte 0x000003FF
_0805CF64:
	ldrb r0, [r7, #7]
	cmp r0, #0
	bne _0805CFCC
	adds r5, r7, #0
	adds r5, #0x14
	movs r3, #0x1c
	ldrsh r0, [r7, r3]
	movs r4, #0x14
	ldrsh r1, [r7, r4]
	subs r0, r0, r1
	movs r2, #0x20
	ldrsh r1, [r7, r2]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805CFC0 @ =0x0203B400
	ldr r2, _0805CFC4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805CFC8 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	subs r0, #1
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strb r0, [r7, #7]
	b _0805CFD4
	.align 2, 0
_0805CFC0: .4byte 0x0203B400
_0805CFC4: .4byte 0x030046B8
_0805CFC8: .4byte 0x000003FF
_0805CFCC:
	subs r0, #1
	strb r0, [r7, #7]
	adds r5, r7, #0
	adds r5, #0x14
_0805CFD4:
	mov r4, sp
	ldrb r6, [r7, #6]
	ldrh r2, [r7, #0x10]
	mov ip, r2
	ldr r2, _0805D000 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	cmp r0, #0
	blt _0805D004
	asrs r3, r0, #0xc
	b _0805D00A
	.align 2, 0
_0805D000: .4byte gSineTable
_0805D004:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805D00A:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _0805D026
	asrs r0, r0, #0xc
	b _0805D02C
_0805D026:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805D02C:
	strh r0, [r4, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r7, #0x14]
	adds r0, r0, r4
	strh r0, [r7, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0
	bl Entity0805d364_SetElemAnim
	mov r4, r8
	movs r0, #0x38
	ldrsh r2, [r4, r0]
	movs r1, #0x14
	ldrsh r0, [r7, r1]
	subs r2, r2, r0
	movs r3, #0x3c
	ldrsh r0, [r4, r3]
	movs r4, #4
	ldrsh r1, [r5, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r5, r0, #0
	muls r5, r0, r5
	adds r0, r5, #0
	adds r1, r1, r0
	ldr r0, _0805D088 @ =0x00003FFF
	cmp r1, r0
	bgt _0805D08C
	movs r0, #0xa
	strb r0, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	movs r0, #0
	b _0805D090
	.align 2, 0
_0805D088: .4byte 0x00003FFF
_0805D08C:
	ldrh r0, [r7, #4]
	adds r0, #1
_0805D090:
	strh r0, [r7, #4]
_0805D092:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
