	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	movs r0, #0x10
	adds r0, r0, r6
	mov ip, r0
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _0805FFA8
	movs r4, #0
	strb r4, [r6, #1]
	ldr r5, _0805FFD8 @ =0x0203B400
	ldr r1, _0805FFDC @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r3, _0805FFE0 @ =0x000003FF
	ands r0, r3
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	subs r0, #2
	strb r0, [r6, #9]
	strb r4, [r6, #0xb]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r3
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r2
	adds r0, #7
	strb r0, [r6, #0xc]
_0805FFA8:
	ldrb r0, [r6, #9]
	ldrb r1, [r6, #8]
	adds r0, r0, r1
	strb r0, [r6, #8]
	mov r4, sp
	movs r3, #8
	ldrsb r3, [r6, r3]
	movs r0, #4
	ldrsh r5, [r6, r0]
	ldr r2, _0805FFE4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805FFE8
	asrs r1, r0, #0xc
	b _0805FFEE
	.align 2, 0
_0805FFD8: .4byte 0x0203B400
_0805FFDC: .4byte 0x030046B8
_0805FFE0: .4byte 0x000003FF
_0805FFE4: .4byte 0x085B0A08
_0805FFE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805FFEE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0806000A
	asrs r0, r0, #0xc
	b _08060010
_0806000A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08060010:
	strh r0, [r4, #4]
	ldrh r2, [r6, #6]
	mov r3, sp
	strh r2, [r3, #2]
	mov r1, sp
	mov r4, ip
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	mov r1, ip
	adds r1, #0x1c
	ldrh r0, [r4, #0x1e]
	adds r2, r2, r0
	strh r2, [r1, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	ldrb r0, [r6, #0xb]
	adds r0, #1
	strb r0, [r6, #0xb]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6, #0xc]
	cmp r0, r1
	blo _080600BA
	ldrb r3, [r6, #0xa]
	ldr r2, _08060064 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08060068 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _0806006C @ =0x0203B400
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08060070
	adds r1, r3, #1
	b _08060072
	.align 2, 0
_08060064: .4byte 0x030046B8
_08060068: .4byte 0x000003FF
_0806006C: .4byte 0x0203B400
_08060070:
	adds r1, r3, #2
_08060072:
	movs r0, #3
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080600A4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080600A8 @ =0x0203B400
	adds r0, r0, r1
	movs r1, #0
	ldrb r0, [r0]
	cmp r0, #0x7f
	ble _08060092
	movs r1, #1
_08060092:
	ldrb r0, [r6, #0xa]
	adds r0, #0x36
	strh r0, [r6, #0x20]
	cmp r1, #0
	beq _080600AC
	ldr r0, [r6, #0x10]
	movs r1, #4
	orrs r0, r1
	b _080600B4
	.align 2, 0
_080600A4: .4byte 0x000003FF
_080600A8: .4byte 0x0203B400
_080600AC:
	ldr r0, [r6, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080600B4:
	str r0, [r6, #0x10]
	movs r0, #0
	strb r0, [r6, #0xb]
_080600BA:
	ldrh r0, [r6, #2]
	ldrh r4, [r6, #0xe]
	cmp r0, r4
	blo _080600D6
	adds r0, r7, #0
	adds r1, r6, #0
	mov r2, r8
	bl FUN_0805ff34
	movs r1, #0
	strb r1, [r6]
	movs r0, #1
	strb r0, [r6, #1]
	strh r1, [r6, #2]
_080600D6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
