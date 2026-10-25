	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sb, r1
	mov sl, r7
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FEB10
	movs r2, #0
	strb r2, [r1]
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r6, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	mov r8, r0
	str r0, [sp, #4]
	str r2, [sp, #8]
	adds r0, r7, #0
	adds r2, r6, #0
	movs r3, #0xa
	bl Boss_PlayAnimFacing
	ldr r1, _081FEB6C @ =0x00000844
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl Boss_GiveWeaponExp
	movs r0, #0x97
	lsls r0, r0, #2
	adds r5, r7, r0
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08022fb8
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xf
	movs r3, #0
	bl MainSprite_SetAnim
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r4, #8]
	mov r1, r8
	orrs r0, r1
	str r0, [r4, #8]
	ldr r1, _081FEB70 @ =0x000007CC
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_08203d38
_081FEB10:
	ldr r0, _081FEB74 @ =0x00000804
	adds r1, r7, r0
	movs r3, #0
	movs r2, #0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r7, r1
	strh r2, [r0]
	subs r1, #0x38
	adds r0, r7, r1
	strb r3, [r0]
	movs r2, #9
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r4, r7, r0
	subs r0, #0x80
	adds r1, r7, r0
	adds r0, r4, #0
	bl MainSprite_AdvanceAnim
	mov r1, sb
	cmp r1, #0xd9
	bgt _081FEB8E
	ldr r1, _081FEB78 @ =0x00000155
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FEB84
	adds r0, r7, #0
	adds r0, #0xe0
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #1
	bhi _081FEB7C
	ldr r0, [r4, #8]
	subs r1, #5
	ands r0, r1
	b _081FEB82
	.align 2, 0
_081FEB6C: .4byte 0x00000844
_081FEB70: .4byte 0x000007CC
_081FEB74: .4byte 0x00000804
_081FEB78: .4byte 0x00000155
_081FEB7C:
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
_081FEB82:
	str r0, [r4, #8]
_081FEB84:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_081fa628
	b _081FEB96
_081FEB8E:
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
_081FEB96:
	mov r0, sb
	cmp r0, #0x80
	bne _081FEBA8
	movs r1, #0x97
	lsls r1, r1, #2
	add r1, sl
	adds r0, r7, #0
	bl FUN_08023024
_081FEBA8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
