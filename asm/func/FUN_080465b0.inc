	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov sl, r0
	adds r5, r1, #0
	str r2, [sp, #0x14]
	movs r0, #0x60
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r1, r5, r1
	str r1, [sp, #0x18]
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r2, r5, r2
	str r2, [sp, #0x1c]
	adds r3, r5, #0
	adds r3, #0x68
	str r3, [sp, #0x20]
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _080466D8
	movs r4, #0
	strb r4, [r5, #5]
	ldrb r0, [r5, #7]
	ldr r2, _08046630 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r5, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, sl
	adds r7, r0, r2
	ldr r3, _08046634 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov ip, r0
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r6
	cmp r0, #1
	bhi _08046638
	adds r0, r5, #0
	adds r0, #0x2c
	mov r1, ip
	strb r1, [r0]
	b _0804663E
	.align 2, 0
_08046630: .4byte 0x085AB414
_08046634: .4byte 0x0000192C
_08046638:
	adds r0, r5, #0
	adds r0, #0x2c
	strb r4, [r0]
_0804663E:
	adds r2, r0, #0
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _0804664E
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _08046654
_0804664E:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_08046654:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804667C
	ldr r0, [r6, #8]
	movs r1, #4
	orrs r0, r1
	b _08046684
_0804667C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08046684:
	str r0, [r6, #8]
	movs r0, #0
	strb r0, [r5, #8]
	mov r2, sb
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r5, r3
	bl ParticleShadow_Show
	mov r4, r8
	adds r4, #8
	ldr r0, [sp, #0x1c]
	adds r1, r4, #0
	bl Map_InitNavAgent
	adds r0, r5, #0
	adds r0, #0x28
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r5, #0x30]
	ldrh r3, [r5, #0x32]
	ldr r0, [sp, #0x18]
	bl Map_InitPathWalker
	movs r6, #0xa6
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	add r0, sp, #4
	movs r2, #0
	bl Map_ReadPathNodePos
	ldr r0, [sp, #0x1c]
	adds r1, r4, #0
	add r2, sp, #4
	bl FUN_08235f40
_080466D8:
	ldr r0, [r5, #0x10]
	cmp r0, #0x77
	bls _08046772
	mov r1, sl
	ldr r0, [r1, #0x28]
	movs r1, #0xf
	ands r0, r1
	ldr r2, [sp, #0x14]
	cmp r0, r2
	bne _08046772
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0804671A
	mov r0, sl
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804671A
	movs r0, #5
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	movs r0, #0
	str r0, [r5, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r5, #0x1c]
	movs r0, #0
	b _08046960
_0804671A:
	ldrb r0, [r5, #0x1f]
	cmp r0, #0
	beq _08046772
	mov r3, sl
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _08046772
	mov r2, sl
	adds r2, #0x20
	adds r3, r5, #0
	adds r3, #0x26
	ldrb r0, [r2]
	ldrb r4, [r3]
	cmp r0, r4
	bne _08046748
	mov r0, sl
	adds r0, #0x21
	adds r1, r5, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08046762
_08046748:
	ldrb r0, [r2]
	subs r0, #1
	ldrb r3, [r3]
	cmp r0, r3
	bne _08046772
	mov r0, sl
	adds r0, #0x21
	adds r1, r5, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _08046772
_08046762:
	movs r0, #0
	strb r0, [r5, #0x1e]
	movs r1, #6
	strb r1, [r5, #4]
	movs r1, #1
	strb r1, [r5, #5]
	str r0, [r5, #0x10]
	b _08046960
_08046772:
	mov r6, sl
	ldr r2, [r6, #0x18]
	ldr r3, [r5, #0x3c]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r4, [sp, #0x20]
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _0804678A
	rsbs r1, r1, #0
_0804678A:
	cmp r1, r3
	bge _080467BC
	movs r0, #2
	ldrsh r1, [r2, r0]
	ldr r4, [sp, #0x20]
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080467A0
	rsbs r1, r1, #0
_080467A0:
	cmp r1, #0xff
	bgt _080467BC
	movs r0, #4
	ldrsh r1, [r2, r0]
	ldr r2, [sp, #0x20]
	movs r4, #4
	ldrsh r0, [r2, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _080467B6
	rsbs r1, r1, #0
_080467B6:
	movs r0, #1
	cmp r1, r3
	blt _080467BE
_080467BC:
	movs r0, #0
_080467BE:
	cmp r0, #0
	beq _080467D6
	ldrb r0, [r5, #4]
	movs r1, #0
	strb r0, [r5, #0xc]
	movs r0, #3
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	str r1, [r5, #0x10]
	movs r0, #0
	b _08046960
_080467D6:
	mov r2, r8
	adds r2, #8
	ldr r6, [sp, #0x1c]
	movs r0, #0x1c
	ldrsh r1, [r6, r0]
	mov r3, r8
	movs r4, #8
	ldrsh r0, [r3, r4]
	subs r4, r1, r0
	movs r0, #0x20
	ldrsh r1, [r6, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _08046824 @ =0x000003FF
	adds r7, r2, #0
	cmp r1, r0
	bgt _08046828
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	mov r6, r8
	strh r0, [r6, #8]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
	adds r0, r5, #0
	bl FUN_080453b0
	movs r0, #0
	b _08046960
	.align 2, 0
_08046824: .4byte 0x000003FF
_08046828:
	adds r2, r5, #0
	adds r2, #0xa4
	ldrb r1, [r2, #0x1d]
	movs r0, #4
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _080468BA
	ldrh r1, [r2, #0x14]
	movs r0, #1
	ands r0, r1
	movs r6, #0x20
	cmp r0, #0
	beq _08046846
	movs r6, #0x10
_08046846:
	adds r0, r4, #0
	adds r1, r3, #0
	bl ArcTan2_8
	mov r2, r8
	strb r0, [r2, #5]
	add r3, sp, #0xc
	ldrb r4, [r2, #5]
	ldr r2, _08046874 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r2, r3, #0
	cmp r0, #0
	blt _08046878
	asrs r1, r0, #0xc
	b _0804687E
	.align 2, 0
_08046874: .4byte 0x085B0A08
_08046878:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0804687E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08046898 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	cmp r0, #0
	blt _0804689C
	asrs r0, r0, #0xc
	b _080468A2
	.align 2, 0
_08046898: .4byte 0x085B0A08
_0804689C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080468A2:
	strh r0, [r3, #4]
	ldrh r0, [r2]
	mov r6, r8
	ldrh r6, [r6, #8]
	adds r0, r0, r6
	mov r1, r8
	strh r0, [r1, #8]
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	ldrh r2, [r1, #0xc]
	adds r0, r0, r2
	strh r0, [r1, #0xc]
_080468BA:
	ldr r0, [sp, #0x1c]
	adds r1, r7, #0
	bl Map_StepNavPath
	ldrb r0, [r5, #7]
	ldr r2, _08046908 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	mov r6, sb
	lsls r0, r0, #5
	mov r3, sl
	adds r7, r0, r3
	ldr r4, _0804690C @ =0x0000192C
	adds r7, r7, r4
	ldrh r3, [r1]
	movs r0, #1
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08046910
	adds r0, r5, #0
	adds r0, #0x2c
	mov r1, r8
	strb r1, [r0]
	adds r2, r0, #0
	b _0804691A
	.align 2, 0
_08046908: .4byte 0x085AB414
_0804690C: .4byte 0x0000192C
_08046910:
	adds r1, r5, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_0804691A:
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _08046928
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _0804692E
_08046928:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_0804692E:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r4]
	cmp r1, #0
	beq _08046956
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _0804695E
_08046956:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804695E:
	str r1, [r6, #8]
_08046960:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
