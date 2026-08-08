	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r1, _0806D770 @ =0x0000037D
	adds r0, r7, r1
	ldrb r0, [r0]
	mov r8, r0
	cmp r0, #0
	beq _0806D774
	cmp r0, #1
	bne _0806D76E
	b _0806D8EA
_0806D76E:
	b _0806DA0C
	.align 2, 0
_0806D770: .4byte 0x0000037D
_0806D774:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806D7AC
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806D7A4 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _0806D7A8 @ =0x000002E7
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	b _0806D7BC
	.align 2, 0
_0806D7A4: .4byte 0x000002E6
_0806D7A8: .4byte 0x000002E7
_0806D7AC:
	lsrs r0, r1, #0x19
	ldr r2, _0806D810 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _0806D814 @ =0x000002E7
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
_0806D7BC:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _0806D810 @ =0x000002E6
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _0806D818
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806D820
	.align 2, 0
_0806D810: .4byte 0x000002E6
_0806D814: .4byte 0x000002E7
_0806D818:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806D820:
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
	beq _0806D844
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806D84C
_0806D844:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806D84C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806D884 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806D8BC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806D888
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806D87C
	ldrb r0, [r4, #5]
_0806D87C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806D898
	.align 2, 0
_0806D884: .4byte 0x0000FFFF
_0806D888:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806D898
	strh r1, [r4, #8]
_0806D898:
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
	bne _0806D8BC
	movs r0, #1
	strb r0, [r4, #7]
_0806D8BC:
	movs r0, #0xfe
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bhi _0806D8E4
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _0806D8E0 @ =0x0000037D
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	b _0806DA0C
	.align 2, 0
_0806D8E0: .4byte 0x0000037D
_0806D8E4:
	subs r0, #0x1e
	strh r0, [r1]
	b _0806DA0C
_0806D8EA:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _0806D940 @ =0x000002E6
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, r8
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, r8
	ands r0, r2
	cmp r1, r0
	beq _0806D944
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806D94C
	.align 2, 0
_0806D940: .4byte 0x000002E6
_0806D944:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806D94C:
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
	beq _0806D970
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806D978
_0806D970:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806D978:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806D9B0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806D9F6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806D9BA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806D9B4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0806D9D0
	.align 2, 0
_0806D9B0: .4byte 0x0000FFFF
_0806D9B4:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806D9CE
_0806D9BA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806D9CE
	strh r1, [r4, #8]
	movs r2, #1
	b _0806D9D0
_0806D9CE:
	movs r2, #0
_0806D9D0:
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
	bne _0806D9F8
	movs r0, #1
	strb r0, [r4, #7]
	b _0806D9F8
_0806D9F6:
	movs r2, #0
_0806D9F8:
	cmp r2, #0
	beq _0806DA0C
	adds r0, r7, #0
	bl FUN_080609dc
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806DA0C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
