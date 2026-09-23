	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0x68
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080207E8
	cmp r1, #0
	blt _080207E8
	ldr r0, _080207EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080207E8
	ldr r0, _080207F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080207F4
_080207E8:
	movs r3, #0
	b _08020802
	.align 2, 0
_080207EC: .4byte 0x030046A8
_080207F0: .4byte 0x030046AC
_080207F4:
	ldr r0, _08020820 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_08020802:
	adds r0, r7, #0
	adds r0, #0x38
	ldrb r1, [r0]
	mov sl, r0
	adds r5, r7, #0
	adds r5, #0x84
	cmp r1, #9
	bls _08020814
	b _08020940
_08020814:
	lsls r0, r1, #2
	ldr r1, _08020824 @ =_08020828
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020820: .4byte 0x030046A4
_08020824: .4byte _08020828
_08020828: @ jump table
	.4byte _08020850 @ case 0
	.4byte _08020864 @ case 1
	.4byte _08020878 @ case 2
	.4byte _0802088E @ case 3
	.4byte _080208B0 @ case 4
	.4byte _080208BE @ case 5
	.4byte _080208D4 @ case 6
	.4byte _080208E8 @ case 7
	.4byte _08020910 @ case 8
	.4byte _0802091E @ case 9
_08020850:
	subs r0, r3, #1
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x18
	b _08020902
_08020864:
	ldr r0, _08020874 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	b _080208F6
	.align 2, 0
_08020874: .4byte 0x030046A4
_08020878:
	strh r3, [r7, #0x3c]
	subs r0, r3, #1
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #2
	b _08020904
_0802088E:
	strh r3, [r7, #0x3c]
	ldr r0, _080208AC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x68
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x1c
	movs r0, #2
	b _08020904
	.align 2, 0
_080208AC: .4byte 0x030046A4
_080208B0:
	subs r0, r3, #1
	movs r2, #0
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	b _08020932
_080208BE:
	ldr r0, _080208D0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	movs r2, #0
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	b _0802092E
	.align 2, 0
_080208D0: .4byte 0x030046A4
_080208D4:
	strh r3, [r7, #0x3c]
	subs r0, r3, #1
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x18
	b _08020902
_080208E8:
	strh r3, [r7, #0x3c]
	ldr r0, _0802090C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3e]
_080208F6:
	adds r1, r7, #0
	adds r1, #0x68
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x1c
_08020902:
	movs r0, #1
_08020904:
	str r0, [r1]
	adds r5, r1, #0
	b _08020940
	.align 2, 0
_0802090C: .4byte 0x030046A4
_08020910:
	movs r2, #0
	strh r3, [r7, #0x3c]
	subs r0, r3, #1
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	b _08020932
_0802091E:
	movs r2, #0
	strh r3, [r7, #0x3c]
	ldr r0, _08020954 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3e]
_0802092E:
	adds r1, r7, #0
	adds r1, #0x68
_08020932:
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x84
	str r2, [r0]
	adds r5, r0, #0
_08020940:
	ldrh r4, [r7, #0x3c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08020958
	adds r0, #4
	b _08020964
	.align 2, 0
_08020954: .4byte 0x030046A4
_08020958:
	ldr r0, _080209D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08020964:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r4, r7, #0
	adds r4, #0x3b
	movs r1, #0
	mov sb, r1
	strb r0, [r4]
	ldr r0, [r7, #0x2c]
	ldrh r1, [r7, #0x3c]
	ldrb r3, [r4]
	movs r2, #0xff
	str r2, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	ldrb r0, [r5]
	movs r3, #0x39
	adds r3, r3, r7
	mov r8, r3
	strb r0, [r3]
	adds r6, r7, #0
	adds r6, #0x3a
	mov r0, sb
	strb r0, [r6]
	mov sb, r7
	ldr r0, [r7, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, #0xc8
	ldr r2, [sp, #8]
	adds r1, r2, r1
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r7, #0x78]
	ldr r1, [r7, #0x7c]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	mov r3, sl
	ldrb r1, [r3]
	movs r0, #1
	ands r0, r1
	mov ip, r4
	cmp r0, #0
	bne _080209D4
	ldrh r0, [r7, #0x20]
	adds r0, #0x80
	strh r0, [r7, #0x20]
	b _080209E2
	.align 2, 0
_080209D0: .4byte 0x030046A4
_080209D4:
	ldrh r0, [r7, #0x1c]
	adds r0, #0x80
	strh r0, [r7, #0x1c]
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	str r0, [r7]
_080209E2:
	mov r4, sb
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [r7, #0x70]
	str r1, [r7, #0x74]
	adds r0, r7, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	beq _08020A04
	cmp r1, #1
	bne _08020A04
	ldr r0, _08020A00 @ =FUN_08020cd8
	b _08020A06
	.align 2, 0
_08020A00: .4byte FUN_08020cd8
_08020A04:
	ldr r0, _08020A64 @ =FUN_08020d10
_08020A06:
	str r0, [r7, #0x30]
	adds r2, r4, #0
	ldrb r3, [r2]
	cmp r3, #0
	bne _08020A70
	adds r0, r7, #0
	adds r0, #0x82
	movs r1, #0
	strh r3, [r0]
	movs r0, #1
	strb r0, [r2]
	ldr r0, _08020A64 @ =FUN_08020d10
	str r0, [r7, #0x30]
	ldrb r0, [r5]
	mov r2, r8
	strb r0, [r2]
	strb r1, [r6]
	ldr r2, [r7, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020A68 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r1, [r2]
	ldr r0, _08020A6C @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r7, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	mov r4, ip
	ldrb r0, [r4]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	adds r0, r7, #0
	adds r0, #0x80
	strh r3, [r0]
	subs r0, #6
	ldrh r0, [r0]
	b _08020ACE
	.align 2, 0
_08020A64: .4byte FUN_08020d10
_08020A68: .4byte 0x0000FFFD
_08020A6C: .4byte 0x0000FFFE
_08020A70:
	cmp r3, #1
	bne _08020AD4
	adds r2, r7, #0
	adds r2, #0x82
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r4]
	ldr r0, _08020AF0 @ =FUN_08020cd8
	str r0, [r7, #0x30]
	mov r0, r8
	strb r1, [r0]
	strb r1, [r6]
	ldr r2, [r7, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020AF4 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	ldr r2, [r7, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	mov r3, ip
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r2, #4]
	adds r2, r7, #0
	adds r2, #0x88
	ldrh r1, [r2]
	adds r0, r7, #0
	adds r0, #0x80
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0x7a
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
_08020ACE:
	adds r1, r7, #0
	adds r1, #0x72
	strh r0, [r1]
_08020AD4:
	movs r0, #0
	str r0, [r7, #0x60]
	str r0, [r7, #0x64]
	movs r1, #0
	bl FUN_080dbe54
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020AF0: .4byte FUN_08020cd8
_08020AF4: .4byte 0x0000FFFC
