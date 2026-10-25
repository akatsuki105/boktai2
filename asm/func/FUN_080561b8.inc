	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov ip, r1
	mov sl, r2
	mov r7, ip
	adds r7, #0x30
	mov r3, ip
	adds r3, #0x4c
	adds r1, #0xc
	mov r2, ip
	ldrh r0, [r2, #0xc]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	ldrh r0, [r1, #2]
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	mov r2, ip
	ldrb r2, [r2, #5]
	mov sb, r2
	mov r0, ip
	ldrb r5, [r0, #8]
	ldr r1, _0805629C @ =0x00000DAC
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0x2c
	adds r2, r2, r4
	mov r8, r2
	ldr r1, _080562A0 @ =0x085AB990
	lsls r0, r5, #1
	adds r0, r0, r1
	ldrh r1, [r6, #0x24]
	ldrh r0, [r0]
	cmp r1, r0
	bhs _0805625C
	ldr r0, [r6, #0x20]
	movs r2, #3
	ands r0, r2
	mov r1, sl
	ands r1, r2
	cmp r0, r1
	bne _0805625C
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08056230
	rsbs r0, r0, #0
_08056230:
	cmp r0, #0x7f
	bgt _0805625C
	mov r0, r8
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08056246
	rsbs r1, r1, #0
_08056246:
	cmp r1, #0x7f
	bgt _0805625C
	adds r0, r6, #0
	adds r0, #0x2a
	strb r5, [r0]
	ldrh r0, [r6, #0x24]
	adds r0, #1
	strh r0, [r6, #0x24]
	ldrh r0, [r6, #0x28]
	add r0, sb
	strh r0, [r6, #0x28]
_0805625C:
	mov r1, ip
	ldrh r0, [r1]
	cmp r0, #0
	beq _08056268
	subs r0, #1
	strh r0, [r1]
_08056268:
	mov r4, ip
	adds r4, #0x5c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x5c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _080562A4
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080562AC
	.align 2, 0
_0805629C: .4byte 0x00000DAC
_080562A0: .4byte 0x085AB990
_080562A4:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080562AC:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080562D0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080562D8
_080562D0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080562D8:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08056310 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08056356
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805631A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08056314
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08056330
	.align 2, 0
_08056310: .4byte 0x0000FFFF
_08056314:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805632E
_0805631A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805632E
	strh r1, [r4, #8]
	movs r2, #1
	b _08056330
_0805632E:
	movs r2, #0
_08056330:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08056358
	movs r0, #1
	strb r0, [r4, #7]
	b _08056358
_08056356:
	movs r2, #0
_08056358:
	cmp r2, #0
	beq _0805639E
	mov r0, ip
	ldrh r3, [r0]
	cmp r3, #0
	bne _0805639E
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq _0805636E
	cmp r0, #3
	bne _0805638C
_0805636E:
	mov r1, ip
	ldrb r0, [r1, #2]
	adds r0, #1
	strb r0, [r1, #2]
	strh r3, [r1, #6]
	ldr r1, [r6, #0x18]
	mov r0, ip
	ldrb r2, [r0, #2]
	adds r2, #3
	str r3, [sp]
	mov r0, r8
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0805639E
_0805638C:
	movs r1, #1
	mov r2, sl
	lsls r1, r2
	ldr r0, [r6, #0x1c]
	bics r0, r1
	str r0, [r6, #0x1c]
	adds r0, r7, #0
	bl AuxSprite_Remove
_0805639E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
