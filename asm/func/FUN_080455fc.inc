	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r4, r1, #0
	str r2, [sp, #4]
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r0, r4, r0
	str r0, [sp, #8]
	movs r1, #0xc4
	adds r1, r1, r4
	mov sl, r1
	ldrb r3, [r4, #5]
	cmp r3, #0
	beq _080456C6
	movs r5, #0
	strb r5, [r4, #5]
	ldrb r0, [r4, #7]
	ldr r2, _0804567C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r3, _08045680 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov ip, r0
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	adds r1, r2, #0
	strb r2, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08045684
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, ip
	strb r2, [r0]
	b _08045690
	.align 2, 0
_0804567C: .4byte 0x085AB404
_08045680: .4byte 0x0000192C
_08045684:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
_08045690:
	adds r5, r0, #0
	ldrb r0, [r1]
	adds r0, r0, r3
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r5]
	cmp r1, #0
	beq _080456B6
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _080456BE
_080456B6:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_080456BE:
	str r1, [r6, #8]
	movs r1, #0
	strb r1, [r4, #8]
	b _08045760
_080456C6:
	ldrb r0, [r4, #7]
	ldr r2, _0804571C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r0, _08045720 @ =0x0000192C
	adds r7, r7, r0
	ldrh r1, [r1]
	mov ip, r1
	movs r1, #1
	mov sb, r1
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	adds r1, r2, #0
	strb r2, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08045724
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, sb
	strb r2, [r0]
	b _08045730
	.align 2, 0
_0804571C: .4byte 0x085AB404
_08045720: .4byte 0x0000192C
_08045724:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r3, [r0]
_08045730:
	adds r5, r0, #0
	ldrb r0, [r1]
	add r0, ip
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	movs r3, #1
	mov r0, sb
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r5]
	cmp r1, #0
	beq _08045756
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _0804575E
_08045756:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804575E:
	str r1, [r6, #8]
_08045760:
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #0xf
	ands r1, r2
	ldr r3, [sp, #4]
	cmp r1, r3
	bne _080457F4
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _0804579C
	mov r1, r8
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	beq _0804579C
	movs r0, #5
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	movs r0, #0
	str r0, [r4, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #0
	b _0804587E
_0804579C:
	ldrb r1, [r4, #0x1f]
	cmp r1, #0
	beq _080457F4
	mov r6, r8
	ldrb r1, [r6, #0x1e]
	cmp r1, #0
	beq _080457F4
	mov r3, r8
	adds r3, #0x20
	adds r5, r4, #0
	adds r5, #0x26
	ldrb r1, [r3]
	ldrb r7, [r5]
	cmp r1, r7
	bne _080457CA
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _080457E4
_080457CA:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r5, [r5]
	cmp r1, r5
	bne _080457F4
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhi _080457F4
_080457E4:
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #6
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _0804587E
_080457F4:
	mov r1, r8
	ldr r3, [r1, #0x18]
	ldr r5, [r4, #0x3c]
	movs r6, #0
	ldrsh r2, [r3, r6]
	mov r7, sl
	movs r6, #0
	ldrsh r1, [r7, r6]
	subs r2, r2, r1
	cmp r2, #0
	bge _0804580C
	rsbs r2, r2, #0
_0804580C:
	cmp r2, r5
	bge _0804583E
	movs r7, #2
	ldrsh r2, [r3, r7]
	mov r6, sl
	movs r7, #2
	ldrsh r1, [r6, r7]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045822
	rsbs r2, r2, #0
_08045822:
	cmp r2, #0xff
	bgt _0804583E
	movs r1, #4
	ldrsh r2, [r3, r1]
	mov r3, sl
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045838
	rsbs r2, r2, #0
_08045838:
	movs r1, #1
	cmp r2, r5
	blt _08045840
_0804583E:
	movs r1, #0
_08045840:
	cmp r1, #0
	beq _08045858
	ldrb r0, [r4, #4]
	movs r1, #0
	strb r0, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0x10]
	movs r0, #0
	b _0804587E
_08045858:
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _0804587E
	ldrh r1, [r4, #0x20]
	cmp r1, #0
	bne _0804587A
	ldr r0, [sp, #8]
	bl FUN_08234e3c
	adds r0, r4, #0
	bl FUN_080453b0
	b _0804587E
_0804587A:
	subs r1, #1
	strh r1, [r4, #0x20]
_0804587E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
