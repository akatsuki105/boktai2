	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0xb8
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	cmp r1, r0
	beq _080B2E3C
	ldr r0, [r6, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2E44
_080B2E3C:
	ldr r0, [r6, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2E44:
	str r0, [r6, #0x18]
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
	beq _080B2E68
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2E70
_080B2E68:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2E70:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B2EA8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B2EE0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B2EAC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B2EA0
	ldrb r0, [r4, #5]
_080B2EA0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B2EBC
	.align 2, 0
_080B2EA8: .4byte 0x0000FFFF
_080B2EAC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B2EBC
	strh r1, [r4, #8]
_080B2EBC:
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
	bne _080B2EE0
	movs r0, #1
	strb r0, [r4, #7]
_080B2EE0:
	adds r0, r6, #0
	adds r0, #0xea
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2EF8
	adds r1, r6, #0
	adds r1, #0xee
	ldr r0, _080B2EF4 @ =0x000001C5
	b _080B2F00
	.align 2, 0
_080B2EF4: .4byte 0x000001C5
_080B2EF8:
	adds r1, r6, #0
	adds r1, #0xee
	movs r0, #0xe2
	lsls r0, r0, #1
_080B2F00:
	strh r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
