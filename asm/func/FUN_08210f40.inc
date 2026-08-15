	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	movs r5, #0
	str r5, [r4, #0x20]
	adds r0, #0x24
	strb r5, [r0]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x26
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r1, _08210FDC @ =0x00000D88
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _08210FE0 @ =0x00000D89
	adds r0, r4, r2
	strb r5, [r0]
	adds r1, #2
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _08210FE4 @ =0x00000C88
	adds r0, r4, r2
	movs r1, #0
	mov r8, r1
	strh r5, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08210c70
	ldr r2, _08210FE8 @ =0x00000D98
	adds r0, r4, r2
	str r5, [r0]
	ldr r0, _08210FEC @ =0x00000C8A
	adds r7, r4, r0
	mov r1, r8
	strb r1, [r7]
	adds r0, r4, #0
	bl FUN_08210774
	adds r0, r4, #0
	bl FUN_08210718
	movs r0, #0x75
	bl prepare_08231510
	cmp r0, #0
	beq _08210FD4
	bl FUN_0823d340
	movs r2, #0xd9
	lsls r2, r2, #4
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _08210FD4
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _08210FD4
	bl FUN_0823d340
	ldr r1, _08210FF0 @ =0x00000D8C
	adds r6, r4, r1
	str r0, [r6]
	cmp r0, #0
	bne _08210FF4
_08210FD4:
	movs r0, #1
	rsbs r0, r0, #0
	b _0821104C
	.align 2, 0
_08210FDC: .4byte 0x00000D88
_08210FE0: .4byte 0x00000D89
_08210FE4: .4byte 0x00000C88
_08210FE8: .4byte 0x00000D98
_08210FEC: .4byte 0x00000C8A
_08210FF0: .4byte 0x00000D8C
_08210FF4:
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _08211058 @ =0x00000D94
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #4
	str r0, [sp]
	ldr r0, _0821105C @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	bl FUN_08049e5c
	bl FUN_08049f5c
	mov r0, r8
	strb r0, [r7]
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r6]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r4, #0
	bl FUN_0821053c
	movs r0, #0
_0821104C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08211058: .4byte 0x00000D94
_0821105C: .4byte 0x0000FFFF
