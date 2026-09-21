	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	ldrb r0, [r4]
	cmp r0, #0x2f
	bne _080055EE
	b _080057E2
_080055EE:
	ldr r1, _08005638 @ =0x08251B3C
	adds r0, r4, #0
	movs r2, #5
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _080056D0
	movs r0, #0
	mov ip, r0
	movs r3, #0
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3f
	adds r1, r1, r6
	mov sb, r1
	adds r1, r6, #0
	adds r1, #0x36
	str r1, [sp]
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r1, r6, #0
	adds r1, #0x37
	str r1, [sp, #4]
	movs r1, #0x34
	adds r1, r1, r6
	mov sl, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _08005662
	cmp r0, #0
	bne _0800563C
	adds r5, r4, #1
	b _08005662
	.align 2, 0
_08005638: .4byte 0x08251B3C
_0800563C:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _08005648
	movs r4, #1
	mov ip, r4
	b _08005654
_08005648:
	mov r0, ip
	cmp r0, #0
	beq _08005654
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_08005654:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _08005662
	cmp r0, #0
	bne _0800563C
	adds r5, #1
_08005662:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _08005680
	cmp r3, #0
	beq _08005680
	adds r0, r2, #0
	adds r1, r3, #0
	bl TextBox_ParseDecimal
	mov r2, sb
	strb r0, [r2]
	b _08005686
_08005680:
	movs r0, #0
	mov r3, sb
	strb r0, [r3]
_08005686:
	adds r0, r5, #0
	movs r1, #0x3e
	bl TextBox_FindChar
	adds r5, r0, #0
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	mov r4, r8
	ldrb r1, [r4]
	ldr r2, [sp]
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, #0x64
	movs r3, #0
	strb r1, [r0]
	ldrb r1, [r6, #0x1b]
	lsls r1, r1, #2
	adds r1, r6, r1
	ldr r4, [sp, #4]
	ldrb r2, [r4]
	lsls r2, r2, #3
	mov r4, sl
	ldrb r0, [r4]
	lsls r0, r0, #4
	adds r2, r2, r0
	adds r1, #0x65
	strb r2, [r1]
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	ldrb r1, [r4]
	adds r0, #0x67
	strb r1, [r0]
	strb r3, [r7]
	b _08005854
_080056D0:
	ldr r1, _08005700 @ =0x08251B44
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _0800574C
	movs r0, #0
	mov ip, r0
	movs r3, #0
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _0800572A
	cmp r0, #0
	bne _08005704
	adds r5, r4, #1
	b _0800572A
	.align 2, 0
_08005700: .4byte 0x08251B44
_08005704:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _08005710
	movs r4, #1
	mov ip, r4
	b _0800571C
_08005710:
	mov r0, ip
	cmp r0, #0
	beq _0800571C
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_0800571C:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _0800572A
	cmp r0, #0
	bne _08005704
	adds r5, #1
_0800572A:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _08005744
	cmp r3, #0
	beq _08005744
	adds r0, r2, #0
	adds r1, r3, #0
	bl TextBox_ParseDecimal
	b _08005746
_08005744:
	movs r0, #0
_08005746:
	bl TextBox_GetExtendWidth
	b _080057C6
_0800574C:
	ldr r1, _0800577C @ =0x08251B4C
	adds r0, r4, #0
	movs r2, #3
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08005848
	movs r3, #0
	mov ip, r3
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _080057A6
	cmp r0, #0
	bne _08005780
	adds r5, r4, #1
	b _080057A6
	.align 2, 0
_0800577C: .4byte 0x08251B4C
_08005780:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _0800578C
	movs r4, #1
	mov ip, r4
	b _08005798
_0800578C:
	mov r0, ip
	cmp r0, #0
	beq _08005798
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_08005798:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _080057A6
	cmp r0, #0
	bne _08005780
	adds r5, #1
_080057A6:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _080057C0
	cmp r3, #0
	beq _080057C0
	adds r0, r2, #0
	adds r1, r3, #0
	bl TextBox_ParseDecimal
	b _080057C2
_080057C0:
	movs r0, #0
_080057C2:
	bl TextBox_GetVarWidth
_080057C6:
	adds r1, r0, #0
	ldrb r0, [r7]
	adds r0, r0, r1
	strb r0, [r7]
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #0x3e
	bl TextBox_FindChar
	adds r5, r0, #0
	b _08005854
_080057E2:
	ldr r1, _08005814 @ =0x08251B50
	adds r0, r4, #0
	movs r2, #6
	bl TextBox_StrNCmp
	cmp r0, #0
	bne _08005848
	adds r0, r4, #0
	movs r1, #0x3e
	bl TextBox_FindChar
	adds r5, r0, #0
	adds r0, r6, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	cmp r1, #0
	beq _08005818
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r0, #0x66
	strb r1, [r0]
	adds r7, r6, #0
	adds r7, #0x3a
	b _0800582A
	.align 2, 0
_08005814: .4byte 0x08251B50
_08005818:
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r2, r6, #0
	adds r2, #0x3a
	ldrb r1, [r2]
	adds r0, #0x66
	strb r1, [r0]
	adds r7, r2, #0
_0800582A:
	ldrb r0, [r6, #0x1b]
	adds r0, #1
	movs r1, #0
	strb r0, [r6, #0x1b]
	strb r1, [r7]
	adds r0, r6, #0
	adds r0, #0x34
	adds r1, r6, #0
	adds r1, #0x2c
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08005854
_08005848:
	adds r0, r4, #0
	movs r1, #0x3e
	bl TextBox_FindChar
	adds r4, r0, #0
	b _08005858
_08005854:
	adds r4, r5, #1
	adds r0, r4, #0
_08005858:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
