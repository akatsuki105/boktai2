	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x50
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r7, r5, r0
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r2, #4
	mov sb, r2
	adds r2, r5, #0
	adds r2, #0x98
	ldr r0, [r2]
	mov r3, sb
	orrs r0, r3
	str r0, [r2]
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, [r0]
	cmp r3, #1
	beq _0821E4E8
	cmp r3, #1
	bgt _0821E43C
	cmp r3, #0
	beq _0821E448
	b _0821E5E2
_0821E43C:
	cmp r3, #2
	beq _0821E530
	cmp r3, #0x63
	bne _0821E446
	b _0821E5D8
_0821E446:
	b _0821E5E2
_0821E448:
	movs r0, #2
	ldr r1, [r4]
	ands r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r4]
	cmp r0, #0
	beq _0821E46A
	str r3, [sp]
	str r3, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x10
	movs r2, #0
	movs r3, #1
	bl FUN_0821c400
_0821E46A:
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #4
	bne _0821E490
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #1
	bne _0821E490
	ldr r0, _0821E48C @ =0x0000035E
	bl PlaySound_082406e0
	b _0821E4AE
	.align 2, 0
_0821E48C: .4byte 0x0000035E
_0821E490:
	movs r6, #0xb4
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r0, [r0]
	cmp r0, #6
	bne _0821E4AE
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _0821E4AE
	ldr r0, _0821E4E0 @ =0x0000035F
	bl PlaySound_082406e0
_0821E4AE:
	ldr r2, _0821E4E4 @ =0x000002D9
	adds r0, r5, r2
	ldrb r1, [r0]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _0821E4C0
	b _0821E5E2
_0821E4C0:
	movs r1, #1
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r6, #0xe9
	lsls r6, r6, #2
	adds r1, r5, r6
	movs r0, #0
	str r0, [r1]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	b _0821E5BA
	.align 2, 0
_0821E4E0: .4byte 0x0000035F
_0821E4E4: .4byte 0x000002D9
_0821E4E8:
	movs r3, #2
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r1, _0821E528 @ =0x00010018
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r6, _0821E52C @ =0x00000804
	adds r0, r5, r6
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, [r2]
	cmp r0, r1
	blt _0821E5E2
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe9
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0
	str r0, [r1]
	ldr r0, [r4]
	orrs r0, r3
	b _0821E5E0
	.align 2, 0
_0821E528: .4byte 0x00010018
_0821E52C: .4byte 0x00000804
_0821E530:
	ldr r1, [r4]
	adds r0, r1, #0
	ands r0, r3
	movs r2, #3
	rsbs r2, r2, #0
	ands r2, r1
	str r2, [r4]
	cmp r0, #0
	beq _0821E5C0
	adds r0, r5, #0
	movs r1, #4
	bl FUN_0821c010
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	ldr r0, _0821E5A4 @ =0x00000BCC
	adds r4, r5, r0
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0821c0c4
	ldr r2, _0821E5A8 @ =0x00000BF6
	adds r1, r5, r2
	movs r3, #0
	mov r8, r3
	strb r0, [r1]
	ldrh r0, [r4]
	strh r0, [r6]
	movs r0, #0xbd
	lsls r0, r0, #4
	adds r1, r5, r0
	ldrh r0, [r1]
	strh r0, [r6, #4]
	ldrh r0, [r4]
	strh r0, [r7]
	ldrh r0, [r1]
	strh r0, [r7, #4]
	str r3, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x10
	movs r2, #0
	bl FUN_0821c400
	movs r2, #0
	ldrsh r1, [r6, r2]
	ldr r0, _0821E5AC @ =0x00000AEF
	cmp r1, r0
	bgt _0821E5B0
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r0, r5, r3
	mov r6, r8
	str r6, [r0]
	b _0821E5E2
	.align 2, 0
_0821E5A4: .4byte 0x00000BCC
_0821E5A8: .4byte 0x00000BF6
_0821E5AC: .4byte 0x00000AEF
_0821E5B0:
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	mov r2, sb
_0821E5BA:
	orrs r0, r2
	str r0, [r1]
	b _0821E5E2
_0821E5C0:
	ldr r6, _0821E5D4 @ =0x000002D9
	adds r0, r5, r6
	ldrb r0, [r0]
	ands r3, r0
	cmp r3, #0
	beq _0821E5E2
	movs r0, #0x10
	orrs r2, r0
	str r2, [r4]
	b _0821E5E2
	.align 2, 0
_0821E5D4: .4byte 0x000002D9
_0821E5D8:
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
_0821E5E0:
	str r0, [r4]
_0821E5E2:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
