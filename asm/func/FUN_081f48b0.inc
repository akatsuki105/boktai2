	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r5, r1, #0
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F48D8
	adds r0, r5, #0
	adds r0, #0x48
	ldr r1, [r7, #0x18]
	movs r4, #0
	str r4, [sp]
	movs r2, #0x18
	movs r3, #0
	bl AuxAnim_SetAnim
	strb r4, [r6]
_081F48D8:
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
	beq _081F4908
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F4910
_081F4908:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F4910:
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
	beq _081F4934
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F493C
_081F4934:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F493C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F4974 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F49BA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F497E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F4978
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081F4994
	.align 2, 0
_081F4974: .4byte 0x0000FFFF
_081F4978:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F4992
_081F497E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F4992
	strh r1, [r4, #8]
	movs r2, #1
	b _081F4994
_081F4992:
	movs r2, #0
_081F4994:
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
	bne _081F49BC
	movs r0, #1
	strb r0, [r4, #7]
	b _081F49BC
_081F49BA:
	movs r2, #0
_081F49BC:
	cmp r2, #0
	beq _081F49FC
	ldr r0, _081F4A04 @ =0x0000016F
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r7, #0x1c]
	bics r0, r1
	str r0, [r7, #0x1c]
	movs r1, #0xb7
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r6, #0
	strb r6, [r0]
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq _081F49E8
	adds r0, r5, #0
	bl AuxSprite_Remove
_081F49E8:
	adds r0, r5, #0
	adds r0, #0xa8
	bl Hitbox_Unregister
	movs r0, #0xff
	strb r0, [r4]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
_081F49FC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F4A04: .4byte 0x0000016F
