	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r4]
	adds r7, r4, #0
	adds r7, #0x96
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bhi _080ABA38
	adds r1, r4, #0
	adds r1, #0x95
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	ldrb r0, [r1]
	subs r2, r0, #1
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x9c
	ldr r3, [r0]
	ldrb r0, [r3, #0x1a]
	cmp r0, #0
	beq _080ABAB0
	lsls r0, r2, #0x18
	cmp r0, #0
	ble _080ABAB0
	subs r1, #0x79
	adds r0, r3, #0
	bl FUN_080ab3a0
	b _080ABAB0
_080ABA38:
	adds r6, r4, #0
	adds r6, #0x9c
	ldr r0, [r6]
	ldrb r5, [r0, #0x1a]
	cmp r5, #0
	beq _080ABA56
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r1, r4, #0
	adds r1, #0x90
	movs r0, #0
	strb r0, [r1]
	b _080ABAB0
_080ABA56:
	ldr r0, _080ABABC @ =0x00000165
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0x92
	ldrb r2, [r0]
	adds r0, #1
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	ldr r0, _080ABAC0 @ =0x00001FFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0
	movs r1, #4
	bl FUN_0823ce68
	ldr r0, [r6]
	bl FUN_080ab018
	adds r0, r4, #0
	adds r0, #0x91
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [r4, #0x48]
	mov r1, r8
	ands r0, r1
	str r0, [r4, #0x48]
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [r4, #0x64]
	str r1, [r4, #0x68]
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, _080ABAC4 @ =FUN_080ab99c
	str r0, [r1]
	strh r5, [r7]
	ldr r0, [r6]
	subs r1, #0x7c
	bl FUN_080ab540
_080ABAB0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABABC: .4byte 0x00000165
_080ABAC0: .4byte 0x00001FFF
_080ABAC4: .4byte FUN_080ab99c
