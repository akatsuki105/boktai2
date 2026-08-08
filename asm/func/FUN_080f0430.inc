	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r6, r4, r0
	ldrh r0, [r6]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080F0450
	b _080F0698
_080F0450:
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F0468
	movs r0, #1
	b _080F069A
_080F0468:
	movs r1, #0x80
	lsls r1, r1, #0xd
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r4
	mov sb, r3
	ldr r0, [r3]
	ands r0, r1
	mov r1, sb
	str r1, [sp, #4]
	cmp r0, #0
	bne _080F0482
	b _080F0698
_080F0482:
	ldrh r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #1
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	cmp r0, #0
	beq _080F0496
	b _080F0698
_080F0496:
	movs r3, #0x97
	lsls r3, r3, #3
	adds r3, r3, r4
	mov sl, r3
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080F04AC
	b _080F0698
_080F04AC:
	adds r0, r4, #0
	movs r1, #6
	bl FUN_080f9a38
	adds r7, r0, #0
	cmp r7, #0
	bne _080F04BC
	b _080F0698
_080F04BC:
	movs r2, #0x80
	lsls r2, r2, #5
	mov r8, r2
	adds r5, r6, #0
	ldrh r0, [r5]
	ands r0, r2
	cmp r0, #0
	beq _080F04E2
	mov r3, sl
	ldr r0, [r3]
	bl FUN_080f8e3c
	ldrh r0, [r5]
	mov r1, r8
	bics r0, r1
	strh r0, [r5]
	ldr r2, [sp]
	mov r3, sl
	str r2, [r3]
_080F04E2:
	movs r0, #0xec
	lsls r0, r0, #1
	adds r3, r4, r0
	ldr r0, [r7]
	str r0, [r3]
	ldr r0, [r0, #0x18]
	ldrh r0, [r0, #6]
	mov sl, r0
	ldr r1, _080F0564 @ =0x00000222
	adds r2, r4, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r7, #0
	strh r0, [r2]
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080F05AE
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r2, [sp, #4]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080F058C
	ldr r1, _080F0568 @ =0x0000025E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, sl
	beq _080F0592
	ldr r2, _080F056C @ =0x000004A4
	adds r0, r4, r2
	ldr r7, [r0]
	movs r0, #8
	adds r0, r0, r4
	mov r8, r0
	ldr r0, [r3]
	adds r6, r0, #0
	adds r6, #8
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	bl FUN_0823599c
	cmp r0, #0
	beq _080F0570
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080F0570
	cmp r0, #2
	beq _080F0578
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _080F0578
	.align 2, 0
_080F0564: .4byte 0x00000222
_080F0568: .4byte 0x0000025E
_080F056C: .4byte 0x000004A4
_080F0570:
	ldr r0, _080F0584 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_080F0578:
	ldr r1, _080F0588 @ =0x0000025E
	adds r0, r4, r1
	mov r2, sl
	strh r2, [r0]
	b _080F0592
	.align 2, 0
_080F0584: .4byte 0xFFFFFDFF
_080F0588: .4byte 0x0000025E
_080F058C:
	adds r0, r4, #0
	bl FUN_080f00ec
_080F0592:
	movs r0, #0x80
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r2, [sp, #4]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _080F0698
_080F05AE:
	ldr r3, _080F0670 @ =0x00000544
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _080F0698
	movs r1, #0x80
	ldr r2, [sp, #4]
	ldr r0, [r2]
	adds r5, r0, #0
	ands r5, r1
	cmp r5, #0
	bne _080F0698
	orrs r0, r1
	mov r3, sb
	str r0, [r3]
	ldrh r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #1
	bics r0, r1
	strh r0, [r6]
	ldr r1, _080F0674 @ =0x08251F80
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r0, r4, #0
	bl FUN_080e6768
	ldr r1, _080F0678 @ =FUN_080e48d0
	ldr r2, _080F067C @ =0x0000046D
	adds r0, r4, r2
	movs r2, #1
	strb r2, [r0]
	ldr r3, _080F0680 @ =0x0000046B
	adds r0, r4, r3
	strb r7, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	movs r3, #0x10
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _080F0684 @ =0x00000469
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r7, [r0]
	adds r1, #0x1b
	adds r0, r4, r1
	str r5, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r2, [r0]
	ldr r0, _080F0688 @ =0xFFFFFBFF
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r0, _080F068C @ =0x00000542
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r2, _080F0690 @ =0x00000202
	adds r1, r4, r2
	movs r0, #0xb4
	strh r0, [r1]
	ldr r3, _080F0694 @ =0x000001DF
	adds r0, r4, r3
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	subs r0, #0x82
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	b _080F069A
	.align 2, 0
_080F0670: .4byte 0x00000544
_080F0674: .4byte 0x08251F80
_080F0678: .4byte FUN_080e48d0
_080F067C: .4byte 0x0000046D
_080F0680: .4byte 0x0000046B
_080F0684: .4byte 0x00000469
_080F0688: .4byte 0xFFFFFBFF
_080F068C: .4byte 0x00000542
_080F0690: .4byte 0x00000202
_080F0694: .4byte 0x000001DF
_080F0698:
	movs r0, #0
_080F069A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
