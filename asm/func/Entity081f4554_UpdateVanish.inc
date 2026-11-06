	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081F33C2
	adds r0, r5, #0
	adds r0, #0x48
	ldr r1, [r7, #0x18]
	movs r2, #4
	str r2, [sp]
	movs r2, #0x17
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #0
	strb r0, [r4]
_081F33C2:
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F33F2
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F33FA
_081F33F2:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F33FA:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F341E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F3426
_081F341E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F3426:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F3460 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F34A6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F346A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F3464
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081F3480
	.align 2, 0
_081F3460: .4byte 0x0000FFFF
_081F3464:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F347E
_081F346A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F347E
	strh r1, [r4, #8]
	movs r2, #1
	b _081F3480
_081F347E:
	movs r2, #0
_081F3480:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _081F34A8
	movs r0, #1
	strb r0, [r4, #7]
	b _081F34A8
_081F34A6:
	movs r2, #0
_081F34A8:
	cmp r2, #0
	beq _081F34F6
	ldr r0, _081F3500 @ =0x00000153
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r7, #0x1c]
	bics r0, r1
	str r0, [r7, #0x1c]
	movs r1, #0xa9
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r6, #0
	strb r6, [r0]
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq _081F34D4
	adds r0, r5, #0
	bl AuxSprite_Remove
_081F34D4:
	ldr r2, _081F3504 @ =0x0000015B
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _081F34EA
	adds r0, r5, #0
	adds r0, #0x64
	bl AuxShadow_Remove
_081F34EA:
	movs r0, #0xff
	strb r0, [r4]
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r6, [r0]
_081F34F6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F3500: .4byte 0x00000153
_081F3504: .4byte 0x0000015B
