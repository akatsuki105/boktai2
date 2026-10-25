	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	mov r8, r6
	adds r2, r6, #0
	adds r2, #0xa9
	ldrb r0, [r2]
	cmp r0, #0
	beq _080321AE
	movs r1, #0
	strb r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
_080321AE:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _0803220C @ =0x00000167
	adds r0, r6, r3
	strb r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r4, r6, #0
	adds r4, #0x98
	ldr r0, [r4]
	orrs r0, r1
	movs r1, #0xc
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #9
	orrs r0, r1
	str r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080321F6
	b _080323B4
_080321F6:
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r7, [r2]
	cmp r7, #1
	beq _08032246
	cmp r7, #1
	bgt _08032210
	cmp r7, #0
	beq _08032218
	b _080323B4
	.align 2, 0
_0803220C: .4byte 0x00000167
_08032210:
	cmp r7, #2
	bne _08032216
	b _080323A0
_08032216:
	b _080323B4
_08032218:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r4]
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	str r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _0803223C
	b _080323B4
_0803223C:
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	strh r7, [r1]
	b _080323B4
_08032246:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ldr r1, [r4]
	orrs r1, r0
	movs r2, #0x10
	mov sl, r2
	orrs r1, r2
	str r1, [r4]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0x3c
	bhi _080322EE
	movs r4, #0xf
	ands r4, r0
	cmp r4, #0
	bne _080322EE
	adds r0, r6, #0
	movs r1, #4
	movs r2, #0x14
	bl FUN_08022c24
	ldr r1, _08032388 @ =0x00000173
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, _0803238C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r6, r2
	str r4, [sp]
	str r4, [sp, #4]
	str r7, [sp, #8]
	ldr r3, _08032390 @ =0x000008C8
	adds r2, r6, r3
	ldrh r2, [r2]
	str r2, [sp, #0xc]
	movs r2, #2
	str r2, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl FUN_0807ab64
	mov sb, r0
	adds r4, r6, #0
	adds r4, #0x90
	movs r0, #0
	ldrsh r5, [r4, r0]
	mov r2, sb
	adds r1, r5, r2
	adds r0, r6, #0
	bl Boss_SetHP
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r5, r0
	beq _080322E8
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, _08032394 @ =0xFFFF0000
	mov r3, sl
	str r3, [sp, #0x14]
	ldr r1, [sp, #0x18]
	ands r1, r2
	orrs r1, r3
	str r1, [sp, #0x18]
	adds r3, r6, #0
	adds r3, #0x50
	add r1, sp, #0x14
	str r1, [sp]
	str r7, [sp, #4]
	mov r1, sb
	movs r2, #1
	bl FUN_0805fe7c
_080322E8:
	movs r0, #0xe6
	bl PlaySound_0824078c
_080322EE:
	movs r2, #0xae
	lsls r2, r2, #1
	add r2, r8
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bhi _0803230E
	movs r1, #4
	ldr r0, _08032398 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080323B4
_0803230E:
	movs r1, #0xaf
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2]
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0xb5
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r3, #0x39
	bl Boss_PlayAnim
	movs r2, #0xa4
	lsls r2, r2, #4
	add r2, r8
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	mov r0, r8
	adds r0, #0xab
	ldrb r4, [r0]
	ldr r5, _08032388 @ =0x00000173
	add r5, r8
	cmp r4, #0
	bne _08032382
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _08032382
	adds r2, r0, #0
	ldr r1, _0803238C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r1, r8
	adds r1, #0xc8
	adds r1, r1, r2
	ldrb r3, [r1]
	ldr r1, _0803239C @ =0x00000A18
	add r1, r8
	movs r2, #0x32
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_0807ac74
_08032382:
	movs r0, #0xff
	strb r0, [r5]
	b _080323B4
	.align 2, 0
_08032388: .4byte 0x00000173
_0803238C: .4byte 0x03002BE0
_08032390: .4byte 0x000008C8
_08032394: .4byte 0xFFFF0000
_08032398: .4byte 0x03002BC0
_0803239C: .4byte 0x00000A18
_080323A0:
	ldr r2, _080323C4 @ =0x00000311
	adds r0, r6, r2
	ldrb r0, [r0]
	ands r7, r0
	cmp r7, #0
	beq _080323B4
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080323B4:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080323C4: .4byte 0x00000311
