	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	mov sb, r7
	adds r4, r7, #0
	adds r4, #0x48
	bl Ringo_PollMessages
	bl FUN_08084710
	adds r1, r0, #0
	ldr r2, _0802AEFC @ =0x00000864
	adds r0, r7, r2
	str r1, [r0]
	cmp r1, #0
	bne _0802AE78
	ldr r3, _0802AF00 @ =0x0000087E
	adds r0, r7, r3
	strb r1, [r0]
_0802AE78:
	adds r0, r4, #0
	bl Mover_ApplyMove
	movs r5, #0xbd
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r7, r0
	adds r0, r7, #0
	bl Boss_AdvanceAnim
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	ldrh r1, [r4, #8]
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r0, [r0]
	ldrh r5, [r4, #0xa]
	adds r0, r0, r5
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r1, [r4, #0xc]
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r0, r7, r3
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	adds r0, r7, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0802AF50
	ldr r2, _0802AF04 @ =gSineTable
	movs r4, #0xb7
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0802AF08
	asrs r3, r0, #0xc
	b _0802AF0E
	.align 2, 0
_0802AEFC: .4byte 0x00000864
_0802AF00: .4byte 0x0000087E
_0802AF04: .4byte gSineTable
_0802AF08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0802AF0E:
	movs r4, #0xc5
	lsls r4, r4, #2
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r5, #0xb7
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0802AF3E
	asrs r2, r0, #0xc
	b _0802AF44
_0802AF3E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0802AF44:
	movs r4, #0xc6
	lsls r4, r4, #2
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_0802AF50:
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r3, r7, r5
	ldrb r0, [r3]
	cmp r0, #0
	beq _0802AFF0
	ldr r2, _0802AF90 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0802AF94 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0802AF98 @ =0x0203B400
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r2, _0802AF9C @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrb r0, [r3]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0802AFA0
	asrs r3, r0, #0xc
	b _0802AFA6
	.align 2, 0
_0802AF90: .4byte 0x030046B8
_0802AF94: .4byte 0x000003FF
_0802AF98: .4byte 0x0203B400
_0802AF9C: .4byte gSineTable
_0802AFA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0802AFA6:
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0802AFD2
	asrs r2, r0, #0xc
	b _0802AFD8
_0802AFD2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0802AFD8:
	movs r4, #0xc6
	lsls r4, r4, #2
	adds r0, r7, r4
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r1, r7, r5
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0802AFF0:
	mov r0, sb
	bl FUN_08022e20
	movs r3, #0
	ldr r1, _0802B070 @ =0x0000016B
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r3, r0
	bge _0802B060
	movs r2, #0x48
	add r2, sb
	mov r8, r2
_0802B008:
	lsls r6, r3, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _0802B054
	movs r4, #0
	ldrsh r5, [r1, r4]
	mov r2, r8
	movs r4, #8
	ldrsh r0, [r2, r4]
	subs r5, r5, r0
	movs r0, #4
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r2, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	str r3, [sp]
	bl ArcTan2_8
	mov r1, sb
	adds r1, #0xc8
	ldr r3, [sp]
	adds r1, r1, r3
	strb r0, [r1]
	mov r2, sb
	adds r2, #0xc0
	adds r2, r2, r6
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0802B054:
	adds r3, #1
	ldr r2, _0802B070 @ =0x0000016B
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r3, r0
	blt _0802B008
_0802B060:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802B070: .4byte 0x0000016B
