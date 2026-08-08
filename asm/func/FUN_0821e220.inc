	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #1
	mov r8, r0
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r6, r5, r1
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r1, #0xc
	adds r2, r5, #0
	adds r2, #0x98
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r7, #0xe8
	lsls r7, r7, #2
	adds r0, r5, r7
	ldr r7, [r0]
	cmp r7, #1
	beq _0821E2C6
	cmp r7, #1
	bgt _0821E262
	cmp r7, #0
	beq _0821E26E
	b _0821E3E0
_0821E262:
	cmp r7, #2
	beq _0821E318
	cmp r7, #0x63
	bne _0821E26C
	b _0821E3D2
_0821E26C:
	b _0821E3E0
_0821E26E:
	movs r4, #2
	ldr r0, [r6]
	adds r2, r0, #0
	ands r2, r4
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	cmp r2, #0
	beq _0821E292
	movs r1, #0xfd
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #0xf
	str r1, [r0]
	ldr r0, _0821E2AC @ =0x0000035F
	bl PlaySound_082406e0
_0821E292:
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r7, [r0]
	movs r1, #0xfd
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	ble _0821E2B0
	subs r2, #1
	b _0821E3A2
	.align 2, 0
_0821E2AC: .4byte 0x0000035F
_0821E2B0:
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r5, r2
	mov r1, r8
	str r1, [r0]
	adds r2, #4
	adds r0, r5, r2
	str r7, [r0]
	ldr r0, [r6]
	orrs r0, r4
	b _0821E3DE
_0821E2C6:
	movs r4, #2
	ldr r0, [r6]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r7, #0xb2
	lsls r7, r7, #2
	adds r0, r5, r7
	movs r3, #0
	strh r3, [r0]
	ldr r1, _0821E310 @ =0x00010010
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r1, _0821E314 @ =0x00000804
	adds r0, r5, r1
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, [r2]
	cmp r0, r1
	blt _0821E3E0
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	movs r2, #0xe9
	lsls r2, r2, #2
	adds r0, r5, r2
	str r3, [r0]
	ldr r0, [r6]
	orrs r0, r4
	b _0821E3DE
	.align 2, 0
_0821E310: .4byte 0x00010010
_0821E314: .4byte 0x00000804
_0821E318:
	ldr r0, [r6]
	adds r2, r0, #0
	ands r2, r7
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	cmp r2, #0
	beq _0821E394
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _0821E3B0 @ =0x00000BCE
	adds r0, r5, r2
	movs r4, #0
	strh r1, [r0]
	adds r3, r5, #0
	adds r3, #0x50
	ldr r1, _0821E3B4 @ =0x00000BCC
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x50]
	str r1, [r5, #0x54]
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #0
	ldrsh r0, [r3, r2]
	mov sb, r0
	movs r2, #4
	ldrsh r0, [r3, r2]
	mov ip, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r2, #4
	ldrsh r1, [r1, r2]
	mov r2, sb
	subs r0, r0, r2
	mov r2, ip
	subs r1, r1, r2
	bl FUN_0823785c
	movs r2, #0xed
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_0821c400
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r4, [r0]
_0821E394:
	movs r2, #0xfd
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	cmp r2, #0xe
	bgt _0821E3B8
	adds r2, #1
_0821E3A2:
	str r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0xf
	bl FUN_0821c2a0
	b _0821E3E0
	.align 2, 0
_0821E3B0: .4byte 0x00000BCE
_0821E3B4: .4byte 0x00000BCC
_0821E3B8:
	movs r1, #0x63
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, [r6]
	orrs r0, r7
	b _0821E3DE
_0821E3D2:
	ldr r0, [r6]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
_0821E3DE:
	str r0, [r6]
_0821E3E0:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
