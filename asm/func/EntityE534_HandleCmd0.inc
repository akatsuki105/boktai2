	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov r8, r0
	ldr r3, _08011B28 @ =0xFFFF0000
	ldrh r1, [r2, #0xa]
	lsls r1, r1, #0x10
	ldrh r0, [r2, #8]
	orrs r0, r1
	str r0, [sp, #4]
	ldrh r1, [r2, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	movs r1, #0xe
	ldrsh r0, [r2, r1]
	str r0, [sp, #0x10]
	movs r5, #0x10
	ldrsh r3, [r2, r5]
	str r3, [sp, #0x14]
	movs r1, #0x12
	ldrsh r0, [r2, r1]
	str r0, [sp, #0x18]
	movs r5, #0x14
	ldrsh r3, [r2, r5]
	str r3, [sp, #0x1c]
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	str r0, [sp, #0x20]
	ldr r2, _08011B2C @ =0x00000CCC
	add r2, r8
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	mov r2, r8
	str r0, [r2, #0x1c]
	ldr r1, _08011B30 @ =0x00000CA4
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08011B34 @ =0x00000CA5
	add r1, r8
	movs r0, #0x3f
	strb r0, [r1]
	ldr r0, _08011B38 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _08011B3C @ =0x00004C60
	adds r1, r2, r3
	ldr r5, _08011B40 @ =0x00004CA0
	adds r2, r2, r5
	ldr r0, _08011B44 @ =0x00000CA8
	add r0, r8
	movs r3, #6
	str r3, [sp]
	movs r3, #0x3f
	bl BlendPltt
	mov r6, r8
	adds r6, #0x24
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _08011B48 @ =0x030046B8
	mov sl, r1
	add r7, sp, #4
	adds r4, r6, #0
	movs r2, #0xff
	mov sb, r2
_08011ABE:
	movs r0, #5
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r3, #0
	strh r3, [r4, #4]
	mov r5, sp
	ldrb r5, [r5, #0x1c]
	strb r5, [r4, #6]
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _08011AF6
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _08011B4C @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _08011B50 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x20]
	bl Mod
	ldrb r1, [r4, #6]
	adds r1, r1, r0
	strb r1, [r4, #6]
_08011AF6:
	mov r5, sp
	ldrh r5, [r5, #0x10]
	strh r5, [r4, #0xc]
	adds r3, r6, #0
	adds r3, #0x10
	movs r2, #6
	ldrsb r2, [r4, r2]
	ldr r0, _08011B54 @ =0x085B0A08
	adds r1, r2, #0
	adds r1, #0x40
	mov r5, sb
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r5, #0
	ldrsh r1, [r1, r5]
	ldr r5, [sp, #0x14]
	muls r1, r5, r1
	adds r5, r3, #0
	mov ip, r0
	cmp r1, #0
	blt _08011B58
	asrs r0, r1, #0xc
	b _08011B5E
	.align 2, 0
_08011B28: .4byte 0xFFFF0000
_08011B2C: .4byte 0x00000CCC
_08011B30: .4byte 0x00000CA4
_08011B34: .4byte 0x00000CA5
_08011B38: .4byte 0x03003584
_08011B3C: .4byte 0x00004C60
_08011B40: .4byte 0x00004CA0
_08011B44: .4byte 0x00000CA8
_08011B48: .4byte 0x030046B8
_08011B4C: .4byte 0x000003FF
_08011B50: .4byte 0x0203B400
_08011B54: .4byte 0x085B0A08
_08011B58:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011B5E:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	mov r1, sb
	ands r2, r1
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x14]
	muls r0, r1, r0
	cmp r0, #0
	blt _08011B7C
	asrs r0, r0, #0xc
	b _08011B82
_08011B7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011B82:
	strh r0, [r3, #4]
	ldrh r0, [r7]
	ldrh r2, [r4, #0x10]
	adds r0, r0, r2
	strh r0, [r4, #0x10]
	ldrh r0, [r7, #2]
	ldrh r3, [r5, #2]
	adds r0, r0, r3
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	adds r2, r6, #0
	adds r2, #0x18
	movs r1, #6
	ldrsb r1, [r4, r1]
	adds r0, r1, #0
	adds r0, #0x40
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #1
	add r0, ip
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r3, [sp, #0x18]
	muls r0, r3, r0
	adds r3, r2, #0
	cmp r0, #0
	blt _08011BC2
	asrs r0, r0, #0xc
	b _08011BC8
_08011BC2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011BC8:
	strh r0, [r2]
	movs r5, #0
	strh r5, [r2, #2]
	mov r0, sb
	ands r1, r0
	lsls r0, r1, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r5, [sp, #0x18]
	muls r0, r5, r0
	cmp r0, #0
	blt _08011BE6
	asrs r0, r0, #0xc
	b _08011BEC
_08011BE6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011BEC:
	strh r0, [r2, #4]
	ldrh r0, [r7]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r7, #2]
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r7, #4]
	ldrh r5, [r3, #4]
	adds r0, r0, r5
	strh r0, [r3, #4]
	mov r0, sl
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _08011C9C @ =0x000003FF
	ands r1, r2
	lsls r0, r1, #1
	ldr r3, _08011CA0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #3]
	ldr r5, [sp, #0xc]
	lsls r0, r5, #4
	ldrh r2, [r4, #0x12]
	adds r0, r0, r2
	strh r0, [r4, #0xa]
	adds r1, #1
	ldr r3, _08011C9C @ =0x000003FF
	ands r1, r3
	mov r5, sl
	str r1, [r5]
	lsls r1, r1, #1
	ldr r0, _08011CA0 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r1, #7
	ands r0, r1
	adds r0, #7
	strb r0, [r4, #8]
	ldr r0, [r4, #0x10]
	ldr r1, [r4, #0x14]
	str r0, [r4, #0x5c]
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x40]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl EntityE534Elem_SetAnim
	adds r0, r6, #0
	adds r0, #0x6c
	ldr r1, _08011CA4 @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r0, _08011CA8 @ =0x00000CA8
	add r0, r8
	str r0, [r4, #0x78]
	adds r0, r6, #0
	adds r0, #0x88
	bl ParticleShadow_Show
	ldr r1, [sp, #0xc]
	adds r1, #1
	str r1, [sp, #0xc]
	adds r4, #0xc8
	adds r6, #0xc8
	cmp r1, #0xf
	bgt _08011C82
	b _08011ABE
_08011C82:
	movs r0, #1
	mov r2, r8
	str r0, [r2, #0x18]
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08011C9C: .4byte 0x000003FF
_08011CA0: .4byte 0x0203B400
_08011CA4: .4byte 0x00000263
_08011CA8: .4byte 0x00000CA8
