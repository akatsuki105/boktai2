	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _080A55D0 @ =0x03002C48
	ldr r4, [r0]
	cmp r4, #0
	bne _080A557C
	b _080A583C
_080A557C:
	ldrb r0, [r4, #0x19]
	ldrb r1, [r4, #0x18]
	cmp r0, r1
	blo _080A5586
	b _080A583C
_080A5586:
	adds r1, r0, #0
	movs r0, #0xb8
	muls r0, r1, r0
	adds r0, #0x1c
	adds r7, r4, r0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A559E
	bl VM_GetValue
_080A559E:
	strh r0, [r7]
	adds r4, r7, #0
	adds r4, #0x28
	adds r5, r7, #0
	adds r5, #0x54
	movs r0, #0x74
	bl VM_SeekToNamedArg
	mov sb, r4
	cmp r0, #0
	bne _080A55B6
	b _080A583C
_080A55B6:
	bl VM_GetValue
	mov r8, r0
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A55D4
	bl VM_GetValue
	adds r6, r0, #0
	b _080A55D6
	.align 2, 0
_080A55D0: .4byte 0x03002C48
_080A55D4:
	movs r6, #0
_080A55D6:
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r2, #0
	strh r6, [r4, #0x10]
	ldrh r1, [r5, #6]
	adds r0, r7, #0
	adds r0, #0x84
	strh r1, [r0]
	strb r2, [r7, #3]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5606
	bl VM_GetValue
	strb r0, [r7, #3]
_080A5606:
	ldrb r0, [r7, #3]
	cmp r0, #0
	beq _080A5614
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	str r0, [r4]
_080A5614:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5630
	bl VM_GetValue
	strh r0, [r4, #0x1c]
	bl VM_GetValue
	strh r0, [r4, #0x1e]
	bl VM_GetValue
	b _080A5634
_080A5630:
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
_080A5634:
	strh r0, [r4, #0x20]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5644
	bl VM_GetValue
_080A5644:
	strb r0, [r7, #4]
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5656
	bl VM_GetValue
	strb r0, [r4, #7]
_080A5656:
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	bne _080A5664
	b _080A57E6
_080A5664:
	ldr r4, _080A56B0 @ =0x0000922E
	bl VM_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl GetFile
	adds r6, r7, #0
	adds r6, #0xac
	str r0, [r6]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0x98
	strb r0, [r5]
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0x99
	strb r0, [r4]
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	mov r8, r6
	adds r6, r4, #0
	cmp r1, #0
	beq _080A56B4
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x9a
	strb r0, [r1]
	adds r0, r1, #0
	b _080A56BA
	.align 2, 0
_080A56B0: .4byte 0x0000922E
_080A56B4:
	adds r0, r7, #0
	adds r0, #0x9a
	strb r1, [r0]
_080A56BA:
	ldrb r1, [r0]
	cmp r1, #0
	beq _080A56D8
	movs r0, #0x65
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A56D8
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	str r0, [r1]
	b _080A56DE
_080A56D8:
	adds r0, r7, #0
	adds r0, #0xb0
	str r1, [r0]
_080A56DE:
	adds r4, r7, #0
	adds r4, #0x9c
	mov r2, r8
	ldr r1, [r2]
	ldrb r2, [r5]
	ldrb r3, [r6]
	ldrb r0, [r7, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl AuxAnim_SetAnim
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A570E
	bl VM_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
_080A570E:
	mov r6, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _080A573C
	ldr r0, [r7, #0x28]
	movs r1, #4
	orrs r0, r1
	b _080A5744
_080A573C:
	ldr r0, [r7, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5744:
	str r0, [r7, #0x28]
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
	beq _080A5768
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080A5770
_080A5768:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080A5770:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080A57A8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080A57E0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080A57AC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080A57A0
	ldrb r0, [r4, #5]
_080A57A0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080A57BC
	.align 2, 0
_080A57A8: .4byte 0x0000FFFF
_080A57AC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080A57BC
	strh r1, [r4, #8]
_080A57BC:
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
	bne _080A57E0
	movs r0, #1
	strb r0, [r4, #7]
_080A57E0:
	movs r0, #8
	strb r0, [r7, #2]
	b _080A57F6
_080A57E6:
	adds r0, r7, #0
	adds r0, #0xac
	str r1, [r0]
	subs r0, #0x12
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	strb r1, [r7, #2]
_080A57F6:
	movs r5, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5808
	bl VM_GetValue
	adds r5, r0, #0
_080A5808:
	adds r4, r7, #0
	adds r4, #0xb4
	movs r0, #0
	str r0, [r4]
	cmp r5, #0
	beq _080A5832
	movs r0, #0x40
	bl Malloc
	str r0, [r4]
	cmp r0, #0
	beq _080A5832
	movs r1, #0x40
	bl ClearMemory
	ldr r0, [r4]
	adds r1, r7, #0
	adds r1, #0x44
	movs r2, #0
	bl ParticleShadow_Init
_080A5832:
	ldr r0, _080A584C @ =0x03002C48
	ldr r1, [r0]
	ldrb r0, [r1, #0x19]
	adds r0, #1
	strb r0, [r1, #0x19]
_080A583C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A584C: .4byte 0x03002C48
