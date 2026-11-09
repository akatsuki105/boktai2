	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _081331DC @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081331E0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081331E2
	.align 2, 0
_081331DC: .4byte 0x0000046D
_081331E0:
	movs r0, #0
_081331E2:
	cmp r0, #0
	beq _0813321A
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r4, #5]
	add r1, sp, #4
	add r2, sp, #8
	bl Centipede_GetAnimVariant
	ldr r2, [sp, #4]
	ldr r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0x12
	bl FUN_081367a0
	movs r0, #2
	movs r7, #0xb3
	lsls r7, r7, #4
	adds r2, r5, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813321A:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r6, #0
	str r6, [sp]
	mov r0, sp
	ldr r2, _08133274 @ =0x05000002
	bl CpuSet
	ldr r1, _08133278 @ =0x00000B4A
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0xc8
	cmp r0, #3
	bls _0813323A
	adds r2, #0x64
_0813323A:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r2
	blt _0813328C
	ldr r3, _0813327C @ =FUN_0813344c
	movs r2, #0x26
	ldr r0, _08133280 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08133284 @ =0x0000046B
	adds r0, r4, r1
	strb r6, [r0]
	ldr r7, _08133288 @ =0x00000553
	adds r0, r4, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r6, [r0]
	b _08133438
	.align 2, 0
_08133274: .4byte 0x05000002
_08133278: .4byte 0x00000B4A
_0813327C: .4byte FUN_0813344c
_08133280: .4byte 0x0000046D
_08133284: .4byte 0x0000046B
_08133288: .4byte 0x00000553
_0813328C:
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _081332A0
	movs r6, #1
	ldrh r0, [r1]
	adds r0, #0xa
	b _081332A6
_081332A0:
	movs r6, #2
	ldrh r0, [r1]
	adds r0, #0x28
_081332A6:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _081332CC @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r6, r0
	cmp r0, #0
	blt _081332D0
	asrs r1, r0, #0xc
	b _081332D6
	.align 2, 0
_081332CC: .4byte gSineTable
_081332D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081332D6:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081332EE
	asrs r2, r0, #0xc
	b _081332F4
_081332EE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081332F4:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	ldr r2, _0813333C @ =0x00002EE0
	adds r0, r4, #0
	movs r1, #0xe
	bl FUN_081370f4
	movs r2, #0
	mov sb, r2
	mov ip, r2
	ldr r3, _08133340 @ =0x00000B3A
	adds r0, r5, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp ip, r0
	blt _08133318
	b _08133438
_08133318:
	ldr r3, _08133344 @ =gSineTable
	movs r6, #0
	ldr r0, _08133348 @ =0x00000674
	adds r2, r5, r0
	movs r1, #0x90
	lsls r1, r1, #1
	mov r8, r1
_08133326:
	adds r0, r6, r5
	movs r7, #2
	mov sl, r7
	ldr r1, _0813334C @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _08133350
	movs r0, #1
	b _08133352
	.align 2, 0
_0813333C: .4byte 0x00002EE0
_08133340: .4byte 0x00000B3A
_08133344: .4byte gSineTable
_08133348: .4byte 0x00000674
_0813334C: .4byte 0x00000755
_08133350:
	movs r0, #0
_08133352:
	cmp r0, #0
	beq _08133422
	adds r0, r6, r5
	movs r1, #5
	ldr r7, _0813336C @ =0x00000755
	adds r0, r0, r7
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08133370
	movs r0, #1
	b _08133372
	.align 2, 0
_0813336C: .4byte 0x00000755
_08133370:
	movs r0, #0
_08133372:
	cmp r0, #0
	bne _08133422
	mov r0, sb
	cmp r0, #0
	beq _08133388
	cmp r0, #1
	beq _081333D0
	ldrh r0, [r4, #8]
	strh r0, [r2]
	ldrh r0, [r4, #0xc]
	b _0813341C
_08133388:
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	mov sl, r1
	movs r0, #0x36
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081333AA
	asrs r1, r0, #0xc
	b _081333B0
_081333AA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081333B0:
	ldrh r0, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r4, #5]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r7, [r0, r1]
	mov sl, r7
	movs r0, #0x36
	mov r7, sl
	muls r7, r0, r7
	adds r0, r7, #0
	cmp r0, #0
	bge _0813340E
	b _08133412
_081333D0:
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081333EE
	asrs r1, r0, #0xc
	b _081333F4
_081333EE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081333F4:
	ldrh r0, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r4, #5]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _08133412
_0813340E:
	asrs r1, r0, #0xc
	b _08133418
_08133412:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08133418:
	ldrh r0, [r4, #0xc]
	subs r0, r0, r1
_0813341C:
	strh r0, [r2, #4]
	movs r0, #1
	add sb, r0
_08133422:
	add r6, r8
	add r2, r8
	movs r1, #1
	add ip, r1
	ldr r7, _08133448 @ =0x00000B3A
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	bge _08133438
	b _08133326
_08133438:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08133448: .4byte 0x00000B3A
