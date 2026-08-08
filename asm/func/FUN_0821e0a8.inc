	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #1
	mov sb, r0
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	ldr r0, [r1]
	adds r2, r0, #0
	mov r3, sb
	ands r2, r3
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r4, r8
	str r0, [r4]
	cmp r2, #0
	beq _0821E160
	movs r0, #0xed
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r7, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	str r3, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #9
	movs r2, #1
	movs r3, #0
	bl FUN_0821c400
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r4, #4
	ldrsh r3, [r0, r4]
	adds r0, r7, #0
	adds r0, #0xcc
	movs r4, #0
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0xce
	strh r2, [r1]
	adds r2, r7, #0
	adds r2, #0xd0
	strh r3, [r2]
	adds r6, r7, #0
	adds r6, #0xdc
	strb r4, [r6]
	subs r1, #0x86
	movs r3, #0
	ldrsh r5, [r0, r3]
	movs r4, #8
	ldrsh r0, [r1, r4]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r1, r7, #0
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	mov r3, sb
	strb r3, [r6]
_0821E160:
	movs r4, #0xe8
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, #0
	bne _0821E1F2
	mov r1, r8
	ldr r0, [r1]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	adds r4, r7, #0
	adds r4, #0x58
	movs r3, #0xed
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r3, [r0]
	movs r6, #0x28
	ldr r2, _0821E1A8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	mov r5, r8
	cmp r0, #0
	blt _0821E1AC
	asrs r1, r0, #0xc
	b _0821E1B2
	.align 2, 0
_0821E1A8: .4byte 0x085B0A08
_0821E1AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821E1B2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0821E1CE
	asrs r0, r0, #0xc
	b _0821E1D4
_0821E1CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821E1D4:
	strh r0, [r4, #4]
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r2, r7, r3
	ldr r4, _0821E21C @ =0x00000804
	adds r0, r7, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r2]
	cmp r0, r1
	blt _0821E1F2
	movs r1, #0x10
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0821E1F2:
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r0, [r0]
	movs r1, #3
	bl Mod
	cmp r0, #0
	bne _0821E20E
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x14
	bl FUN_0821ddc4
_0821E20E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821E21C: .4byte 0x00000804
