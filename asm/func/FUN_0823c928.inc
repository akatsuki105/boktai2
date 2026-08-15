	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r1, #0x84
	adds r1, r1, r7
	mov r8, r1
	ldrb r1, [r1]
	cmp r1, #0
	beq _0823C9A6
	adds r4, r7, #0
	adds r4, #0x8a
	ldrh r1, [r4]
	cmp r1, #0
	beq _0823C99A
	adds r5, r7, #0
	adds r5, #0x86
	ldrh r0, [r5]
	adds r6, r7, #0
	adds r6, #0x88
	muls r0, r1, r0
	ldrh r2, [r6]
	adds r0, r0, r2
	adds r1, #1
	bl Div
	adds r1, r0, #0
	movs r3, #0
	strh r1, [r5]
	adds r2, r7, #0
	adds r2, #0x7e
	strh r1, [r2]
	ldrh r1, [r4]
	subs r1, #1
	strh r1, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0
	bne _0823C9A6
	adds r2, #7
	ldrb r0, [r2]
	cmp r0, #0
	beq _0823C98E
	mov r4, r8
	strb r3, [r4]
	strb r3, [r2]
	strh r1, [r5]
	strh r1, [r6]
	b _0823C992
_0823C98E:
	ldrh r0, [r6]
	strh r0, [r5]
_0823C992:
	adds r0, r7, #0
	bl FUN_0823c228
	b _0823C9A6
_0823C99A:
	adds r1, r7, #0
	adds r1, #0x86
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0x7e
	strh r1, [r2]
_0823C9A6:
	movs r1, #0x7e
	adds r1, r1, r7
	mov sl, r1
	ldrh r2, [r1]
	cmp r2, #0
	beq _0823CA2C
	adds r0, r2, #0
	ldr r2, _0823CA1C @ =0x0203B400
	mov r8, r2
	ldr r4, _0823CA20 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r5, _0823CA24 @ =0x000003FF
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	bl ModArm
	mov r2, sl
	ldrh r1, [r2]
	lsrs r1, r1, #1
	subs r0, r0, r1
	adds r6, r7, #0
	adds r6, #0x80
	movs r1, #0
	mov sb, r1
	strh r0, [r6]
	ldrh r0, [r2]
	ldr r1, [r4]
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	bl ModArm
	adds r3, r0, #0
	mov r2, sl
	ldrh r1, [r2]
	lsrs r1, r1, #1
	subs r3, r3, r1
	adds r1, r7, #0
	adds r1, #0x82
	strh r3, [r1]
	ldr r2, _0823CA28 @ =0x03003540
	ldrh r1, [r6]
	ldrh r4, [r2]
	adds r1, r1, r4
	strh r1, [r2]
	ldrh r1, [r2, #4]
	adds r1, r1, r3
	strh r1, [r2, #4]
	mov r2, sb
	mov r1, sl
	b _0823CA34
	.align 2, 0
_0823CA1C: .4byte 0x0203B400
_0823CA20: .4byte 0x030046B8
_0823CA24: .4byte 0x000003FF
_0823CA28: .4byte 0x03003540
_0823CA2C:
	adds r1, r7, #0
	adds r1, #0x80
	strh r2, [r1]
	adds r1, #2
_0823CA34:
	strh r2, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
