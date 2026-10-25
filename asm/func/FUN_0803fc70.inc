	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov sb, r1
	adds r6, r5, #0
	movs r0, #0x48
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r1, r1, r5
	mov r8, r1
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803FD3E
	movs r2, #0
	mov ip, r2
	mov r3, ip
	strb r3, [r1]
	adds r0, r5, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r2, r5, #0
	adds r2, #0x4d
	strb r0, [r2]
	ldrb r0, [r2]
	adds r0, #0x20
	movs r7, #0xff
	ands r0, r7
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r3, r5, #0
	adds r3, #0xa0
	strb r1, [r3]
	ldrb r0, [r2]
	adds r0, #0x10
	ands r0, r7
	asrs r0, r0, #5
	adds r0, #3
	movs r4, #7
	ands r0, r4
	adds r1, r5, #0
	adds r1, #0xa1
	strb r0, [r1]
	ldrb r0, [r3]
	cmp r0, #1
	bls _0803FCE6
	movs r0, #0x40
	strb r0, [r2]
	movs r0, #2
	b _0803FCEC
_0803FCE6:
	mov r0, ip
	strb r0, [r2]
	movs r0, #1
_0803FCEC:
	strb r0, [r3]
	ldrb r0, [r2]
	adds r0, #0x10
	ands r0, r7
	asrs r0, r0, #5
	adds r0, #3
	ands r0, r4
	strb r0, [r1]
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	adds r2, r4, #0
	movs r3, #0x10
	bl Boss_PlayAnimFlip
	adds r0, r5, #0
	adds r0, #0xb0
	ldrh r2, [r0]
	mov r0, r8
	adds r1, r4, #0
	movs r3, #6
	bl MainSprite_SetAnimFrame
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	ldr r0, _0803FDB4 @ =0x0000035F
	bl PlaySound_0824078c
_0803FD3E:
	movs r1, #4
	adds r4, r5, #0
	adds r4, #0x98
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r1, #0xb7
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r6, r3
	str r1, [r0]
	adds r2, #0x12
	adds r0, r6, r2
	str r1, [r0]
	subs r3, #0x74
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803FD7E
	b _0803FEE0
_0803FD7E:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803FD94
	adds r0, r2, #2
	strh r0, [r3]
_0803FD94:
	ldr r2, _0803FDB8 @ =gSineTable
	mov r1, sb
	lsls r0, r1, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803FDBC
	asrs r1, r0, #0xc
	b _0803FDC2
	.align 2, 0
_0803FDB4: .4byte 0x0000035F
_0803FDB8: .4byte gSineTable
_0803FDBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803FDC2:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r2, #0
	mov sb, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803FDDC
	mov r3, sb
	strh r3, [r1]
_0803FDDC:
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrh r0, [r7]
	cmp r0, #1
	beq _0803FE2C
	cmp r0, #1
	bgt _0803FDF2
	cmp r0, #0
	beq _0803FDF8
	b _0803FEE0
_0803FDF2:
	cmp r0, #2
	beq _0803FEC0
	b _0803FEE0
_0803FDF8:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	mov r3, r8
	ldrh r0, [r3, #0x14]
	cmp r0, #2
	bls _0803FE14
	movs r1, #8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0803FE14:
	mov r0, r8
	ldrb r1, [r0, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803FEE0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	mov r1, sb
	strh r1, [r2]
	b _0803FEE0
_0803FE2C:
	movs r1, #0x18
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bne _0803FE58
	movs r3, #0xa7
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, sl
	str r0, [r2, #8]
	str r1, [r2, #0xc]
_0803FE58:
	ldrh r0, [r4]
	cmp r0, #0x1d
	bls _0803FEE0
	adds r0, r5, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #6
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	movs r3, #0x10
	bl Boss_PlayAnimFlip
	mov r0, r8
	movs r1, #0x40
	bl MainSprite_SetAnimSpeed
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	mov r0, sb
	strh r0, [r4]
	b _0803FEE0
_0803FEC0:
	mov r1, r8
	ldrh r0, [r1, #0x14]
	cmp r0, #2
	bhi _0803FED0
	movs r1, #8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0803FED0:
	mov r2, r8
	ldrh r0, [r2, #0x14]
	cmp r0, #6
	bne _0803FEE0
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803FEE0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
