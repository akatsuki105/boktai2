	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, r1, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	ldr r5, [r0]
	movs r7, #0
	b _08049866
_0804979C:
	ldrb r0, [r5]
	cmp r0, #0x3c
	bne _08049834
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049878
	adds r4, r5, #0
	ldr r1, _080497D0 @ =0x08251CC4
	adds r0, r5, #0
	movs r2, #3
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08049824
	movs r6, #0
	movs r2, #0
	ldrb r0, [r5]
	mov r3, r8
	adds r3, #0x34
	cmp r0, #0x3e
	beq _080497F6
	cmp r0, #0
	bne _080497D4
	adds r4, r5, #1
	b _080497F6
	.align 2, 0
_080497D0: .4byte 0x08251CC4
_080497D4:
	ldrb r1, [r4]
	cmp r1, #0x3d
	bne _080497DE
	movs r6, #1
	b _080497E8
_080497DE:
	cmp r6, #0
	beq _080497E8
	adds r0, r3, r2
	strb r1, [r0]
	adds r2, #1
_080497E8:
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _080497F6
	cmp r0, #0
	bne _080497D4
	adds r4, #1
_080497F6:
	adds r1, r3, r2
	movs r0, #0
	strb r0, [r1]
	cmp r6, #0
	beq _08049810
	cmp r2, #0
	beq _08049810
	adds r0, r3, #0
	adds r1, r2, #0
	bl TextBox_ParseDecimal
	adds r1, r0, #0
	b _08049812
_08049810:
	movs r1, #0
_08049812:
	mov r0, r8
	bl TextRenderer_GetVarWidth
	adds r7, r7, r0
	adds r0, r4, #0
	movs r1, #0x3e
	bl TextBox_FindChar
	b _0804982C
_08049824:
	adds r0, r5, #0
	movs r1, #0x3e
	bl TextBox_FindChar
_0804982C:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049878
	b _08049866
_08049834:
	cmp r0, #0x1f
	bne _0804985C
	adds r0, r5, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08049858 @ =0x0000FFFF
	cmp r1, r0
	beq _08049862
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08049862
	adds r7, #1
	b _08049864
	.align 2, 0
_08049858: .4byte 0x0000FFFF
_0804985C:
	adds r7, #1
	adds r5, #1
	b _08049866
_08049862:
	adds r7, #2
_08049864:
	adds r5, #2
_08049866:
	ldrb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _08049862
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08049878
	cmp r0, #0xa
	bne _0804979C
_08049878:
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
