	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	mov r8, r5
	ldr r2, _0812F030 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812EF72
	movs r0, #0
	strb r0, [r1]
_0812EF72:
	adds r0, r5, #0
	movs r1, #0xe
	bl Enemy_PlayAnim
	ldr r3, _0812F034 @ =0x0000065E
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bgt _0812EF88
	b _0812F192
_0812EF88:
	adds r3, #2
	adds r2, r4, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r7, #0
	strh r0, [r2]
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrh r6, [r0]
	cmp r6, #0
	bne _0812F058
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	mov r1, r8
	bl FUN_080db290
	cmp r0, #0
	blt _0812F058
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r4, #7
	mov r8, r4
	movs r1, #0x3c
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r4, _0812F038 @ =0x00000554
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _0812F03C @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _0812F040 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	ldr r3, _0812F044 @ =FUN_080e68d8
	movs r1, #0xe
	subs r2, #0xe4
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _0812F048 @ =0x0000046B
	adds r0, r5, r4
	strb r7, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r6, [r0]
	movs r1, #3
	subs r4, #0xeb
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _0812F04C @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _0812F050 @ =0x0000046A
	adds r0, r5, r3
	strb r7, [r0]
	adds r4, #0x1c
	adds r0, r5, r4
	str r6, [r0]
	ldr r6, _0812F054 @ =0x0000046C
	adds r0, r5, r6
	b _0812F190
	.align 2, 0
_0812F030: .4byte 0x0000046D
_0812F034: .4byte 0x0000065E
_0812F038: .4byte 0x00000554
_0812F03C: .4byte 0x00000551
_0812F040: .4byte 0x00000552
_0812F044: .4byte FUN_080e68d8
_0812F048: .4byte 0x0000046B
_0812F04C: .4byte 0x00000469
_0812F050: .4byte 0x0000046A
_0812F054: .4byte 0x0000046C
_0812F058:
	ldr r2, _0812F0F4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0812F0F8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0812F0FC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r6, r0, #3
	movs r7, #3
	ands r6, r7
	cmp r6, #0
	bne _0812F11C
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r4, #7
	mov r8, r4
	movs r1, #0x3c
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r4, _0812F100 @ =0x00000554
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _0812F104 @ =0x00000551
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _0812F108 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	ldr r3, _0812F10C @ =FUN_080e68d8
	movs r2, #0xe
	subs r1, #0xe3
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0812F110 @ =0x0000046B
	adds r0, r5, r4
	strb r6, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0
	strh r6, [r0]
	subs r4, #0xeb
	adds r0, r5, r4
	strb r7, [r0]
	ldr r3, _0812F114 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _0812F118 @ =0x00000484
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	b _0812F192
	.align 2, 0
_0812F0F4: .4byte 0x030046B8
_0812F0F8: .4byte 0x000003FF
_0812F0FC: .4byte 0x0203B400
_0812F100: .4byte 0x00000554
_0812F104: .4byte 0x00000551
_0812F108: .4byte 0x00000552
_0812F10C: .4byte FUN_080e68d8
_0812F110: .4byte 0x0000046B
_0812F114: .4byte 0x00000469
_0812F118: .4byte 0x00000484
_0812F11C:
	ldr r4, _0812F19C @ =0x000005A4
	adds r0, r5, r4
	ldr r3, [r0]
	movs r4, #5
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0812F1A0 @ =0x00000551
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0812F1A4 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
	ldr r4, _0812F1A8 @ =FUN_080e68d8
	movs r3, #0xe
	subs r6, #0xe7
	adds r0, r5, r6
	movs r2, #1
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r3, #0
	strh r1, [r0]
	subs r6, #0xeb
	adds r0, r5, r6
	strb r7, [r0]
	ldr r4, _0812F1AC @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	ldr r3, _0812F1B0 @ =0x00000484
	adds r0, r5, r3
	str r1, [r0]
	adds r4, #3
	adds r0, r5, r4
_0812F190:
	strb r2, [r0]
_0812F192:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812F19C: .4byte 0x000005A4
_0812F1A0: .4byte 0x00000551
_0812F1A4: .4byte 0x00000552
_0812F1A8: .4byte FUN_080e68d8
_0812F1AC: .4byte 0x00000469
_0812F1B0: .4byte 0x00000484
