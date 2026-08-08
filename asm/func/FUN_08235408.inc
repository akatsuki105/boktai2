	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	mov sb, r1
	adds r0, r2, #0
	str r3, [sp, #8]
	movs r1, #1
	rsbs r1, r1, #0
	mov sl, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl FUN_08234f44
	mov r8, r0
	cmp r0, #0
	beq _08235436
	ldrb r0, [r0]
	cmp r0, #0
	bne _08235440
_08235436:
	movs r0, #0
	strh r0, [r6]
	strh r0, [r6, #2]
	strh r0, [r6, #4]
	b _0823555A
_08235440:
	mov r0, r8
	bl FUN_08234f6c
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _08235460
	mov r7, sp
	ldrh r7, [r7, #0x10]
	strh r7, [r6]
	mov r0, sp
	ldrh r0, [r0, #0x10]
	strh r0, [r6, #2]
	mov r1, sp
	ldrh r1, [r1, #0x10]
	strh r1, [r6, #4]
	b _0823555A
_08235460:
	mov r4, sp
	mov r0, sp
	ldr r1, [sp, #0x10]
	movs r2, #0
	bl FUN_08234f80
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r6]
	ldrh r0, [r4, #4]
	strh r0, [r6, #4]
	mov r3, sl
	movs r5, #0
	mov r7, r8
	ldrb r7, [r7]
	cmp r5, r7
	bge _082354D8
	mov r4, sp
_08235484:
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	ldr r1, [sp, #0x10]
	str r3, [sp, #0xc]
	bl FUN_08234f80
	mov r0, sb
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r7, #0
	ldrsh r0, [r4, r7]
	subs r2, r2, r0
	mov r0, sb
	movs r7, #4
	ldrsh r1, [r0, r7]
	movs r7, #4
	ldrsh r0, [r4, r7]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r0, #0
	adds r0, r1, #0
	muls r0, r1, r0
	adds r2, r2, r0
	ldr r3, [sp, #0xc]
	cmp r2, r3
	bhs _082354CE
	ldr r1, [sp, #8]
	cmp r2, r1
	blo _082354CE
	mov sl, r5
	adds r3, r2, #0
	ldrh r0, [r4]
	strh r0, [r6]
	ldrh r0, [r4, #4]
	strh r0, [r6, #4]
_082354CE:
	adds r5, #1
	mov r7, r8
	ldrb r7, [r7]
	cmp r5, r7
	blt _08235484
_082354D8:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _082354FC
	cmp r1, #0
	blt _082354FC
	ldr r0, _08235500 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _082354FC
	ldr r0, _08235504 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08235508
_082354FC:
	movs r4, #0
	b _08235516
	.align 2, 0
_08235500: .4byte 0x030046A8
_08235504: .4byte 0x030046AC
_08235508:
	ldr r0, _08235528 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08235516:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823552C
	adds r0, #4
	b _08235538
	.align 2, 0
_08235528: .4byte 0x030046A4
_0823552C:
	ldr r0, _0823554C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08235538:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08235550
	cmp r2, #2
	beq _08235554
	b _08235558
	.align 2, 0
_0823554C: .4byte 0x030046A4
_08235550:
	ldrb r0, [r6, #4]
	b _08235556
_08235554:
	ldrb r0, [r6]
_08235556:
	subs r1, r1, r0
_08235558:
	strh r1, [r6, #2]
_0823555A:
	mov r0, sl
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
