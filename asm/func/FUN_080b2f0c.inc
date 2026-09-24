	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r0, #0xce
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B2F1C
	b _080B3076
_080B2F1C:
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #5
	bne _080B2F3A
	adds r0, #6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B2F3A
	adds r1, r5, #0
	adds r1, #0xee
	movs r0, #0xe2
	lsls r0, r0, #1
	b _080B2F50
_080B2F3A:
	ldrh r0, [r2]
	cmp r0, #6
	bne _080B2F52
	adds r0, r5, #0
	adds r0, #0xc6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B2F52
	adds r1, r5, #0
	adds r1, #0xee
	ldr r0, _080B2FA0 @ =0x000001C3
_080B2F50:
	strh r0, [r1]
_080B2F52:
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _080B2FA4
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2FAC
	.align 2, 0
_080B2FA0: .4byte 0x000001C3
_080B2FA4:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2FAC:
	str r0, [r5, #0x18]
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
	beq _080B2FD0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2FD8
_080B2FD0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2FD8:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3010 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B3056
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B301A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B3014
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080B3030
	.align 2, 0
_080B3010: .4byte 0x0000FFFF
_080B3014:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B302E
_080B301A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B302E
	strh r1, [r4, #8]
	movs r2, #1
	b _080B3030
_080B302E:
	movs r2, #0
_080B3030:
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
	bne _080B3058
	movs r0, #1
	strb r0, [r4, #7]
	b _080B3058
_080B3056:
	movs r2, #0
_080B3058:
	cmp r2, #0
	bne _080B305E
	b _080B31AC
_080B305E:
	adds r1, r5, #0
	adds r1, #0xd2
	movs r0, #0
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x5a
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #6
	bl Generator_SetState
	b _080B31AC
_080B3076:
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r0, [r0]
	cmp r0, #5
	bne _080B3092
	adds r0, r5, #0
	adds r0, #0xc6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B3092
	adds r1, r5, #0
	adds r1, #0xee
	ldr r0, _080B30E0 @ =0x000001C3
	strh r0, [r1]
_080B3092:
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _080B30E4
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B30EC
	.align 2, 0
_080B30E0: .4byte 0x000001C3
_080B30E4:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B30EC:
	str r0, [r5, #0x18]
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
	beq _080B3110
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B3118
_080B3110:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B3118:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3150 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B3196
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B315A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B3154
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080B3170
	.align 2, 0
_080B3150: .4byte 0x0000FFFF
_080B3154:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B316E
_080B315A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B316E
	strh r1, [r4, #8]
	movs r2, #1
	b _080B3170
_080B316E:
	movs r2, #0
_080B3170:
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
	bne _080B3198
	movs r0, #1
	strb r0, [r4, #7]
	b _080B3198
_080B3196:
	movs r2, #0
_080B3198:
	cmp r2, #0
	beq _080B31AC
	adds r1, r5, #0
	adds r1, #0xd2
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl Generator_SetState
_080B31AC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
