	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #4]
	adds r4, r2, #0
	str r3, [sp, #8]
	movs r0, #0
	strb r0, [r6, #0x1c]
	strb r0, [r6, #0x1d]
	strb r0, [r6, #0x1e]
	str r0, [r6, #0x24]
	ldr r0, _0805D45C @ =0x00001684
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0805D460 @ =0x00001685
	adds r1, r6, r2
	movs r0, #0x3f
	strb r0, [r1]
	ldr r0, _0805D464 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _0805D468 @ =0x00004C60
	adds r1, r2, r3
	ldr r0, _0805D46C @ =0x00004CA0
	adds r2, r2, r0
	ldr r3, _0805D470 @ =0x00001688
	adds r0, r6, r3
	movs r3, #6
	str r3, [sp]
	movs r3, #0x3f
	bl BlendPltt
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	adds r5, r6, #0
	adds r5, #0x44
	movs r0, #0
	str r0, [sp, #0xc]
	mov sl, r0
	ldr r1, _0805D474 @ =0x030046B8
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0xc0
_0805D40A:
	mov r2, sl
	strb r2, [r5, #1]
	movs r3, #1
	strb r3, [r5]
	mov r0, sl
	strh r0, [r5, #4]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D478 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D47C @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, [sp, #0xc]
	lsls r2, r0, #5
	movs r0, #0x1f
	ands r1, r0
	adds r2, r2, r1
	strb r2, [r5, #6]
	mov r1, sp
	ldrh r1, [r1, #8]
	strh r1, [r5, #0x10]
	mov r2, sp
	ldrh r2, [r2, #0x30]
	strh r2, [r5, #0x12]
	ldrb r0, [r6, #0x1f]
	movs r3, #0xdc
	adds r3, r3, r5
	mov sb, r3
	cmp r0, #2
	bne _0805D486
	ldr r0, [sp, #0xc]
	cmp r0, #7
	bgt _0805D480
	movs r1, #1
	strb r1, [r5, #8]
	b _0805D494
	.align 2, 0
_0805D45C: .4byte 0x00001684
_0805D460: .4byte 0x00001685
_0805D464: .4byte 0x03003584
_0805D468: .4byte 0x00004C60
_0805D46C: .4byte 0x00004CA0
_0805D470: .4byte 0x00001688
_0805D474: .4byte 0x030046B8
_0805D478: .4byte 0x000003FF
_0805D47C: .4byte 0x0203B400
_0805D480:
	mov r2, sl
	strb r2, [r5, #8]
	b _0805D494
_0805D486:
	cmp r0, #0
	bne _0805D490
	mov r3, sl
	strb r3, [r5, #8]
	b _0805D494
_0805D490:
	movs r0, #0xff
	strb r0, [r5, #8]
_0805D494:
	mov r0, sl
	strb r0, [r5, #9]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D4D8 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D4DC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r4, r0, #0
	adds r4, #0x10
	ldr r2, _0805D4E0 @ =gSineTable
	ldrb r3, [r5, #6]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _0805D4E4
	asrs r1, r0, #0xc
	b _0805D4EA
	.align 2, 0
_0805D4D8: .4byte 0x000003FF
_0805D4DC: .4byte 0x0203B400
_0805D4E0: .4byte gSineTable
_0805D4E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805D4EA:
	ldr r3, [sp, #4]
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	ldrh r0, [r3, #2]
	strh r0, [r5, #0x16]
	mov r1, ip
	lsls r0, r1, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805D50A
	asrs r2, r0, #0xc
	b _0805D510
_0805D50A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0805D510:
	ldr r3, [sp, #4]
	ldrh r0, [r3, #4]
	adds r0, r0, r2
	strh r0, [r5, #0x18]
	ldrh r0, [r5, #0x16]
	strh r0, [r5, #0xe]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D5C4 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D5C8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #7
	strb r0, [r5, #7]
	adds r4, r5, #0
	adds r4, #0x14
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r7, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x60]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0
	bl RingoBat_SetAnim
	movs r3, #0x84
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, _0805D5CC @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r1, _0805D5D0 @ =0x00001688
	adds r0, r6, r1
	mov r2, sb
	str r0, [r2, #0x38]
	movs r3, #0x92
	lsls r3, r3, #1
	adds r0, r5, r3
	bl ParticleShadow_Show
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r0, [r7, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r7, #6]
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r7, r7, r1
	adds r5, r5, r1
	cmp r0, #0xf
	bgt _0805D5AC
	b _0805D40A
_0805D5AC:
	movs r0, #1
	str r0, [r6, #0x18]
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805D5C4: .4byte 0x000003FF
_0805D5C8: .4byte 0x0203B400
_0805D5CC: .4byte 0x00000263
_0805D5D0: .4byte 0x00001688
