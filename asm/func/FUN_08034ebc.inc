	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov r8, r6
	adds r2, r6, #0
	adds r2, #0xa9
	ldrb r0, [r2]
	cmp r0, #0
	beq _08034F28
	movs r1, #0
	strb r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	subs r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _08034F74 @ =0x00000874
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x2f
	bl Boss_PlayAnim
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x30
	movs r3, #2
	bl MainSprite_SetAnim
_08034F28:
	ldr r2, _08034F78 @ =0x0001000C
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08034F7C
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	b _08035254
	.align 2, 0
_08034F74: .4byte 0x00000874
_08034F78: .4byte 0x0001000C
_08034F7C:
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #5
	bls _08034F8A
	b _08035232
_08034F8A:
	lsls r0, r0, #2
	ldr r1, _08034F94 @ =_08034F98
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08034F94: .4byte _08034F98
_08034F98: @ jump table
	.4byte _08034FB0 @ case 0
	.4byte _08034FF2 @ case 1
	.4byte _08035094 @ case 2
	.4byte _080350EC @ case 3
	.4byte _0803514A @ case 4
	.4byte _0803521C @ case 5
_08034FB0:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08034FC6
	b _08035232
_08034FC6:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, r8
	adds r2, r5, #0
	movs r3, #0x31
	bl Boss_PlayAnim
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x32
	b _080350D4
_08034FF2:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrh r0, [r7]
	adds r0, #1
	movs r1, #0
	mov sb, r1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _0803500C
	b _08035232
_0803500C:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, r8
	adds r2, r5, #0
	movs r3, #0x33
	bl Boss_PlayAnim
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x34
	movs r3, #2
	bl MainSprite_SetAnim
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r7]
	ldr r0, _0803508C @ =0x00000173
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0803507A
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r2, _08035090 @ =0x00000876
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
_0803507A:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	b _08035232
	.align 2, 0
_0803508C: .4byte 0x00000173
_08035090: .4byte 0x00000876
_08035094:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r7, r6, r2
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080350AA
	b _08035232
_080350AA:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r5, r6, r2
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, r8
	adds r2, r5, #0
	movs r3, #0x35
	bl Boss_PlayAnim
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x36
_080350D4:
	movs r3, #2
	bl MainSprite_SetAnim
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r7]
	b _08035232
_080350EC:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r5, r6, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08035102
	b _08035232
_08035102:
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r4, r6, r1
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, r8
	movs r3, #0x37
	bl Boss_PlayAnim
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r4, #8]
	orrs r0, r2
	str r0, [r4, #8]
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r5]
	b _08035232
_0803514A:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08035232
	ldr r1, _080351D8 @ =0x00000874
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _080351E8
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, r8
	movs r3, #0x38
	bl Boss_PlayAnim
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r2, r6, r1
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r4, [r0]
	ldr r2, _080351DC @ =0x00000173
	adds r5, r6, r2
	cmp r4, #0
	bne _080351CC
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _080351CC
	adds r2, r0, #0
	ldr r1, _080351E0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #0xc8
	adds r1, r1, r2
	ldrb r3, [r1]
	ldr r2, _080351E4 @ =0x00000A18
	adds r1, r6, r2
	movs r2, #0x32
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_0807ac74
_080351CC:
	movs r0, #0xff
	strb r0, [r5]
	adds r0, #0x5f
	adds r1, r6, r0
	b _0803520A
	.align 2, 0
_080351D8: .4byte 0x00000874
_080351DC: .4byte 0x00000173
_080351E0: .4byte 0x03002BE0
_080351E4: .4byte 0x00000A18
_080351E8:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, r8
	movs r3, #0x38
	bl Boss_PlayAnim
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r6, r2
_0803520A:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	b _08035232
_0803521C:
	ldr r1, _08035264 @ =0x00000311
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08035232
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08035232:
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r0, r6, r2
	subs r2, #0x80
	adds r1, r6, r2
	bl MainSprite_AdvanceAnim
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_08035254:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035264: .4byte 0x00000311
