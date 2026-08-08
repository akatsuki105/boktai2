	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x8c
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r0, _080FC718 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FC71C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FC71E
	.align 2, 0
_080FC718: .4byte 0x0000046D
_080FC71C:
	movs r0, #0
_080FC71E:
	cmp r0, #0
	beq _080FC72A
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_080FC72A:
	movs r0, #0x10
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r5, r1, #0
	cmp r4, #0x11
	bgt _080FC75E
	ldr r0, [r7, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r4, [r3, #8]
	cmp r4, #0
	bne _080FC75E
	ldrh r1, [r3, #0xe]
	ldrb r2, [r3, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _080FC75E
	cmp r2, #1
	beq _080FC75E
	strh r4, [r3, #0xe]
_080FC75E:
	ldr r3, _080FC7EC @ =0x0000046E
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FC76C
	bl _080FD07C
_080FC76C:
	ldr r4, _080FC7F0 @ =0x0000046B
	adds r0, r7, r4
	movs r4, #0
	movs r1, #1
	mov sl, r1
	mov r2, sl
	strb r2, [r0]
	movs r0, #2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r2, [r1]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r1, [sp, #0x78]
	cmp r3, #0
	beq _080FC804
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _080FC7F4 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	ldr r1, _080FC7F8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r4, [r0]
	adds r3, #3
	adds r0, r7, r3
	mov r1, sl
	strb r1, [r0]
	ldr r2, _080FC7FC @ =0x00000594
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #7
	adds r3, #1
	adds r0, r7, r3
	mov r3, sl
	strb r3, [r0]
	ldr r3, _080FC7F0 @ =0x0000046B
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	ldr r0, _080FC800 @ =0xFFFFF67C
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	bl _080FD07C
	.align 2, 0
_080FC7EC: .4byte 0x0000046E
_080FC7F0: .4byte 0x0000046B
_080FC7F4: .4byte 0x00000469
_080FC7F8: .4byte 0x0000046A
_080FC7FC: .4byte 0x00000594
_080FC800: .4byte 0xFFFFF67C
_080FC804:
	movs r0, #0x80
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _080FC812
	b _080FCE34
_080FC812:
	adds r0, r7, #0
	movs r1, #0
	str r3, [sp, #0x88]
	bl FUN_080ef86c
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _080FC910 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	mov r0, sl
	strb r0, [r5]
	ldr r1, _080FC914 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	ldr r3, [sp, #0x88]
	strb r3, [r1]
	ldr r2, _080FC918 @ =0x00000484
	adds r2, r7, r2
	str r2, [sp, #0x14]
	str r3, [r2]
	ldr r4, _080FC91C @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x18]
	strb r0, [r4]
	ldr r1, _080FC920 @ =0x080E6795
	movs r0, #0xe
	ldr r5, _080FC924 @ =0x0000046D
	adds r6, r7, r5
	mov r2, sl
	strb r2, [r6]
	ldr r4, _080FC928 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	strb r3, [r4]
	adds r5, #0xe6
	adds r5, r5, r7
	mov ip, r5
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sb, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r3, [r1]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _080FC92C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _080FC930 @ =0x00000552
	adds r0, r7, r3
	movs r4, #0xc
	strb r4, [r0]
	subs r5, #0xac
	adds r3, r7, r5
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r6, [sp, #0x54]
	ldr r0, [sp, #8]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x5c]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x50]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x4c]
	mov r0, ip
	str r0, [sp, #0x74]
	mov r0, sb
	str r0, [sp, #0x7c]
	mov r0, r8
	str r0, [sp, #0x80]
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _080FC90C
	cmp r1, #0
	blt _080FC90C
	ldr r0, _080FC934 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080FC90C
	ldr r0, _080FC938 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FC93C
_080FC90C:
	movs r4, #0
	b _080FC94A
	.align 2, 0
_080FC910: .4byte 0x00000469
_080FC914: .4byte 0x0000046A
_080FC918: .4byte 0x00000484
_080FC91C: .4byte 0x0000046C
_080FC920: .4byte 0x080E6795
_080FC924: .4byte 0x0000046D
_080FC928: .4byte 0x0000046B
_080FC92C: .4byte 0x00000551
_080FC930: .4byte 0x00000552
_080FC934: .4byte 0x030046A8
_080FC938: .4byte 0x030046AC
_080FC93C:
	ldr r0, _080FC95C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080FC94A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FC960
	adds r0, #4
	b _080FC96C
	.align 2, 0
_080FC95C: .4byte 0x030046A4
_080FC960:
	ldr r0, _080FC980 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FC96C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FC984
	cmp r2, #2
	beq _080FC988
	b _080FC98C
	.align 2, 0
_080FC980: .4byte 0x030046A4
_080FC984:
	ldrb r0, [r5, #4]
	b _080FC98A
_080FC988:
	ldrb r0, [r5]
_080FC98A:
	subs r1, r1, r0
_080FC98C:
	strh r1, [r5, #2]
	ldr r0, _080FC9A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080FC9A4
	movs r0, #1
	b _080FC9A6
	.align 2, 0
_080FC9A0: .4byte 0x030047A4
_080FC9A4:
	movs r0, #0
_080FC9A6:
	cmp r0, #0
	beq _080FC9E4
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080FC9C6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _080FC9C2
	adds r2, r0, #0
_080FC9C2:
	cmp r2, #0
	bge _080FC9D0
_080FC9C6:
	ldr r2, _080FC9CC @ =0x000005C4
	adds r0, r7, r2
	b _080FCE22
	.align 2, 0
_080FC9CC: .4byte 0x000005C4
_080FC9D0:
	ldr r1, _080FC9E0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _080FCA2C
	.align 2, 0
_080FC9E0: .4byte 0x03002BE0
_080FC9E4:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080FCA10
	cmp r1, #0
	blt _080FCA10
	ldr r0, _080FCA14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FCA10
	ldr r0, _080FCA18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FCA1C
_080FCA10:
	movs r5, #0
	b _080FCA2A
	.align 2, 0
_080FCA14: .4byte 0x030046A8
_080FCA18: .4byte 0x030046AC
_080FCA1C:
	ldr r0, _080FCABC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080FCA2A:
	movs r2, #0
_080FCA2C:
	ldr r4, _080FCAC0 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _080FCA4C
	ldr r1, _080FCAC4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080FCA4C
	b _080FCD60
_080FCA4C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x78]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080FCA60
	b _080FD07C
_080FCA60:
	ldr r0, _080FCAC8 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x78]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _080FCACC
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r3, [sp, #0x74]
	strb r0, [r3]
	ldr r0, [sp, #0x7c]
	str r1, [r0]
	ldr r1, [sp, #0x80]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r1, [sp, #0x44]
	strb r5, [r1]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r5, [sp, #0x5c]
	str r4, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _080FCC1A
	.align 2, 0
_080FCABC: .4byte 0x030046A4
_080FCAC0: .4byte 0x00000256
_080FCAC4: .4byte 0x03002BE0
_080FCAC8: .4byte 0x00000222
_080FCACC:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r2, [sp, #0x74]
	strb r0, [r2]
	ldr r4, [sp, #0x7c]
	str r1, [r4]
	ldr r1, [sp, #0x80]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x44]
	strb r5, [r4]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080FCB30
	cmp r1, #0
	blt _080FCB30
	ldr r0, _080FCB34 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FCB30
	ldr r0, _080FCB38 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FCB3C
_080FCB30:
	movs r4, #0
	b _080FCB4A
	.align 2, 0
_080FCB34: .4byte 0x030046A8
_080FCB38: .4byte 0x030046AC
_080FCB3C:
	ldr r0, _080FCB5C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080FCB4A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FCB60
	adds r0, #4
	b _080FCB6C
	.align 2, 0
_080FCB5C: .4byte 0x030046A4
_080FCB60:
	ldr r0, _080FCB80 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FCB6C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FCB84
	cmp r2, #2
	beq _080FCB88
	b _080FCB8C
	.align 2, 0
_080FCB80: .4byte 0x030046A4
_080FCB84:
	ldrb r0, [r5, #4]
	b _080FCB8A
_080FCB88:
	ldrb r0, [r5]
_080FCB8A:
	subs r1, r1, r0
_080FCB8C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080FCBB4
	cmp r1, #0
	blt _080FCBB4
	ldr r0, _080FCBB8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FCBB4
	ldr r0, _080FCBBC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FCBC0
_080FCBB4:
	movs r4, #0
	b _080FCBCE
	.align 2, 0
_080FCBB8: .4byte 0x030046A8
_080FCBBC: .4byte 0x030046AC
_080FCBC0:
	ldr r0, _080FCBE0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080FCBCE:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FCBE4
	adds r0, #4
	b _080FCBF0
	.align 2, 0
_080FCBE0: .4byte 0x030046A4
_080FCBE4:
	ldr r0, _080FCC04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FCBF0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080FCC08
	cmp r3, #2
	beq _080FCC0C
	b _080FCC10
	.align 2, 0
_080FCC04: .4byte 0x030046A4
_080FCC08:
	ldrb r0, [r5, #4]
	b _080FCC0E
_080FCC0C:
	ldrb r0, [r5]
_080FCC0E:
	subs r2, r2, r0
_080FCC10:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_080FCC1A:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x78]
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	bne _080FCD24
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080FCC44
	movs r0, #1
	b _080FCC46
_080FCC44:
	movs r0, #0
_080FCC46:
	ldr r3, _080FCD34 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _080FCD24
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _080FCD38 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _080FCD3C @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x68]
	ldr r2, _080FCD40 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x6c]
	ldr r4, _080FCD44 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x70]
	ldr r5, _080FCD48 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x60]
	ldr r0, _080FCD4C @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x84]
	ldr r1, _080FCD50 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x64]
	ldr r6, _080FCD54 @ =0x0203B400
	ldr r1, _080FCD58 @ =0x030046B8
	ldr r2, _080FCD5C @ =0x000003FF
	movs r5, #3
	mov r4, r8
_080FCC96:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _080FCCB4
	adds r3, #1
	cmp r3, #3
	ble _080FCC96
	mov r0, r8
_080FCCB4:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x7c]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x74]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0x68]
	strb r0, [r5]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x6c]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0x70]
	strb r0, [r5]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x60]
	strb r1, [r0]
	ldr r1, [sp, #0x84]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x54]
	strb r1, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r4, [sp, #0x74]
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	str r2, [r5]
	movs r2, #0
	ldr r0, [sp, #0x80]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r0, [sp, #0x48]
	strb r2, [r0]
	ldr r2, [sp, #0x5c]
	str r3, [r2]
	ldr r3, [sp, #0x50]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x64]
	strb r0, [r4]
_080FCD24:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x58]
	strh r0, [r5]
	b _080FD07C
	.align 2, 0
_080FCD34: .4byte 0x00000482
_080FCD38: .4byte 0x0000054F
_080FCD3C: .4byte 0x0000054C
_080FCD40: .4byte 0x0000054D
_080FCD44: .4byte 0x0000054E
_080FCD48: .4byte 0x00000541
_080FCD4C: .4byte 0x000005BC
_080FCD50: .4byte 0x00000542
_080FCD54: .4byte 0x0203B400
_080FCD58: .4byte 0x030046B8
_080FCD5C: .4byte 0x000003FF
_080FCD60:
	mov sb, sp
	ldr r6, _080FCD9C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FCDA0
	adds r0, #4
	b _080FCDAA
	.align 2, 0
_080FCD9C: .4byte 0x030046A4
_080FCDA0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080FCDAA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _080FCDE4 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _080FCDEC
	ldr r0, _080FCDE8 @ =0xFFFFFDFF
	ldr r2, [sp, #0x78]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080FCE16
	.align 2, 0
_080FCDE4: .4byte 0x000004A4
_080FCDE8: .4byte 0xFFFFFDFF
_080FCDEC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _080FCE0C
	cmp r0, #2
	beq _080FCE08
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FCE08:
	movs r0, #1
	b _080FCE18
_080FCE0C:
	ldr r0, _080FCE2C @ =0xFFFFFDFF
	ldr r3, [sp, #0x78]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_080FCE16:
	movs r0, #0
_080FCE18:
	cmp r0, #0
	beq _080FCE1E
	b _080FD07C
_080FCE1E:
	ldr r4, _080FCE30 @ =0x000005C4
	adds r0, r7, r4
_080FCE22:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _080FD07C
	.align 2, 0
_080FCE2C: .4byte 0xFFFFFDFF
_080FCE30: .4byte 0x000005C4
_080FCE34:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r0, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x24]
	strb r0, [r1]
	ldr r2, _080FCF4C @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0x28]
	mov r3, sl
	strb r3, [r2]
	ldr r4, _080FCF50 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	strb r5, [r4]
	ldr r0, _080FCF54 @ =0x00000484
	adds r0, r7, r0
	str r0, [sp, #0x30]
	str r5, [r0]
	ldr r1, _080FCF58 @ =0x0000046C
	adds r1, r7, r1
	str r1, [sp, #0x34]
	strb r3, [r1]
	ldr r1, _080FCF5C @ =0x080E6795
	movs r0, #0xe
	ldr r2, _080FCF60 @ =0x0000046D
	adds r6, r7, r2
	strb r3, [r6]
	ldr r3, _080FCF64 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x38]
	strb r5, [r3]
	ldr r4, _080FCF68 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x3c]
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sb, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r5, [r1]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x3c
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _080FCF6C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _080FCF70 @ =0x00000552
	adds r0, r7, r3
	movs r4, #7
	strb r4, [r0]
	subs r5, #0xd2
	adds r0, r7, r5
	mov r1, sl
	strh r1, [r0]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldr r4, [sp, #0x78]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	adds r5, #0x26
	adds r0, r7, r5
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r6, [sp, #0x54]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x40]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0x44]
	ldr r4, [sp, #0x2c]
	str r4, [sp, #0x48]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x50]
	ldr r4, [sp, #0x38]
	str r4, [sp, #0x4c]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0x74]
	mov r3, sb
	str r3, [sp, #0x7c]
	mov r4, r8
	str r4, [sp, #0x80]
	cmp r2, #0
	blt _080FCF46
	cmp r1, #0
	blt _080FCF46
	ldr r0, _080FCF74 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FCF46
	ldr r0, _080FCF78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FCF7C
_080FCF46:
	movs r4, #0
	b _080FCF8A
	.align 2, 0
_080FCF4C: .4byte 0x00000469
_080FCF50: .4byte 0x0000046A
_080FCF54: .4byte 0x00000484
_080FCF58: .4byte 0x0000046C
_080FCF5C: .4byte 0x080E6795
_080FCF60: .4byte 0x0000046D
_080FCF64: .4byte 0x0000046B
_080FCF68: .4byte 0x00000553
_080FCF6C: .4byte 0x00000551
_080FCF70: .4byte 0x00000552
_080FCF74: .4byte 0x030046A8
_080FCF78: .4byte 0x030046AC
_080FCF7C:
	ldr r0, _080FCF9C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080FCF8A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FCFA0
	adds r0, #4
	b _080FCFAC
	.align 2, 0
_080FCF9C: .4byte 0x030046A4
_080FCFA0:
	ldr r0, _080FCFC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FCFAC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FCFC4
	cmp r2, #2
	beq _080FCFC8
	b _080FCFCC
	.align 2, 0
_080FCFC0: .4byte 0x030046A4
_080FCFC4:
	ldrb r0, [r5, #4]
	b _080FCFCA
_080FCFC8:
	ldrb r0, [r5]
_080FCFCA:
	subs r1, r1, r0
_080FCFCC:
	strh r1, [r5, #2]
	ldr r5, _080FCFFC @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080FD004
	ldr r0, _080FD000 @ =0xFFFFFDFF
	ldr r2, [sp, #0x78]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080FD02E
	.align 2, 0
_080FCFFC: .4byte 0x000004A4
_080FD000: .4byte 0xFFFFFDFF
_080FD004:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080FD024
	cmp r0, #2
	beq _080FD020
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FD020:
	movs r0, #1
	b _080FD030
_080FD024:
	ldr r0, _080FD068 @ =0xFFFFFDFF
	ldr r3, [sp, #0x78]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_080FD02E:
	movs r0, #0
_080FD030:
	adds r3, r0, #0
	cmp r3, #0
	bne _080FD070
	ldr r0, _080FD06C @ =FUN_080e48d0
	movs r2, #1
	ldr r4, [sp, #0x54]
	strb r2, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r1, [sp, #0x74]
	strb r3, [r1]
	ldr r4, [sp, #0x7c]
	str r0, [r4]
	movs r1, #0
	ldr r5, [sp, #0x80]
	strh r3, [r5]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r3, [sp, #0x50]
	strb r2, [r3]
	b _080FD07C
	.align 2, 0
_080FD068: .4byte 0xFFFFFDFF
_080FD06C: .4byte FUN_080e48d0
_080FD070:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_080FD07C:
	add sp, #0x8c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
