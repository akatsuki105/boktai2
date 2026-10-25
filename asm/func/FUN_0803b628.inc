	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	mov sb, r1
	mov r8, r7
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803B664
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r4, #0x98
	lsls r4, r4, #2
	adds r2, r7, r4
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x19
	bl Boss_PlayAnimFacing
_0803B664:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r1, [r0]
	movs r0, #0xc
	adds r2, r7, #0
	adds r2, #0x98
	ldr r1, [r2]
	orrs r1, r0
	str r1, [r2]
	mov r4, sb
	cmp r4, #5
	ble _0803B686
	movs r0, #0x10
	orrs r1, r0
	str r1, [r2]
_0803B686:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B69C
	b _0803B7AA
_0803B69C:
	movs r0, #1
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0803B79C
	ldr r4, _0803B6F0 @ =0x0203B400
	ldr r3, _0803B6F4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0803B6F8 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	add r4, sp, #0xc
	adds r1, #0x20
	mov ip, r1
	ldr r1, _0803B6FC @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	adds r6, r3, #0
	cmp r0, #0
	blt _0803B700
	asrs r2, r0, #0xc
	b _0803B706
	.align 2, 0
_0803B6F0: .4byte 0x0203B400
_0803B6F4: .4byte 0x030046B8
_0803B6F8: .4byte 0x000003FF
_0803B6FC: .4byte gSineTable
_0803B700:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0803B706:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _0803B722
	asrs r0, r0, #0xc
	b _0803B728
_0803B722:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803B728:
	strh r0, [r4, #4]
	add r3, sp, #0xc
	movs r2, #0xa8
	lsls r2, r2, #2
	add r2, r8
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	ldrh r4, [r3, #4]
	adds r0, r0, r4
	strh r0, [r3, #4]
	adds r1, #0x80
	strh r1, [r3, #2]
	ldr r4, _0803B7B8 @ =0x0203B400
	ldr r0, [r6]
	adds r0, #1
	ldr r3, _0803B7BC @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrb r1, [r1]
	adds r0, #1
	ands r0, r3
	lsls r2, r0, #1
	adds r2, r2, r4
	ldrh r2, [r2]
	movs r5, #0xf
	ands r2, r5
	adds r2, #0x10
	adds r0, #1
	ands r0, r3
	str r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	ands r3, r5
	adds r3, #4
	ldr r0, _0803B7C0 @ =0x00000DE8
	add r0, r8
	ldr r0, [r0]
	movs r4, #0x3c
	str r4, [sp]
	movs r4, #0xb1
	lsls r4, r4, #1
	add r4, r8
	ldrb r4, [r4]
	str r4, [sp, #4]
	add r4, sp, #0xc
	str r4, [sp, #8]
	bl FUN_08060220
_0803B79C:
	mov r0, sb
	cmp r0, #9
	ble _0803B7AA
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803B7AA:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B7B8: .4byte 0x0203B400
_0803B7BC: .4byte 0x000003FF
_0803B7C0: .4byte 0x00000DE8
