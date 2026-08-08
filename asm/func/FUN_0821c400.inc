	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov ip, r0
	adds r7, r1, #0
	adds r5, r2, #0
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x28]
	lsls r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r4, ip
	cmp r3, #0
	bne _0821C430
	movs r3, #0xee
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, r7
	beq _0821C434
_0821C430:
	movs r6, #4
	b _0821C436
_0821C434:
	movs r6, #1
_0821C436:
	lsls r0, r1, #1
	orrs r6, r0
	movs r0, #2
	mov r8, r0
	cmp r2, #0
	beq _0821C446
	movs r3, #1
	mov r8, r3
_0821C446:
	movs r0, #0xee
	lsls r0, r0, #2
	add r0, ip
	movs r1, #0
	strh r7, [r0]
	ldr r0, _0821C494 @ =0x000003BA
	add r0, ip
	strh r1, [r0]
	movs r3, #0xed
	lsls r3, r3, #2
	add r3, ip
	ldrh r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrh r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	cmp r5, #1
	beq _0821C4BA
	cmp r5, #1
	bgt _0821C498
	cmp r5, #0
	beq _0821C49E
	b _0821C4F8
	.align 2, 0
_0821C494: .4byte 0x000003BA
_0821C498:
	cmp r5, #2
	beq _0821C4D8
	b _0821C4F8
_0821C49E:
	movs r1, #0xaf
	lsls r1, r1, #2
	add r1, ip
	movs r2, #0xa7
	lsls r2, r2, #2
	add r2, ip
	mov r0, r8
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	adds r3, r7, #0
	bl FUN_08022c34
	b _0821C512
_0821C4BA:
	movs r1, #0xaf
	lsls r1, r1, #2
	add r1, ip
	movs r2, #0xa7
	lsls r2, r2, #2
	add r2, ip
	mov r3, r8
	str r3, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	adds r3, r7, #0
	bl FUN_08022c9c
	b _0821C512
_0821C4D8:
	movs r1, #0xaf
	lsls r1, r1, #2
	add r1, ip
	movs r2, #0xa7
	lsls r2, r2, #2
	add r2, ip
	mov r0, r8
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	adds r3, r7, #0
	bl FUN_08022d24
	b _0821C512
_0821C4F8:
	movs r1, #0xaf
	lsls r1, r1, #2
	add r1, ip
	movs r2, #0xa7
	lsls r2, r2, #2
	add r2, ip
	mov r3, r8
	str r3, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	adds r3, r7, #0
	bl FUN_08022da8
_0821C512:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
