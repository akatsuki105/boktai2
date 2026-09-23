	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0802002C @ =0x000085E6
	bl FUN_08230e70
	adds r5, r0, #0
	cmp r5, #0
	bne _08020030
	movs r0, #1
	rsbs r0, r0, #0
	b _080200D6
	.align 2, 0
_0802002C: .4byte 0x000085E6
_08020030:
	movs r6, #0
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _08020040
	movs r0, #0
	b _080200D6
_08020040:
	bl Script_GetValue
	mov r8, r0
	movs r4, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _080200D4
	ldr r2, _080200E4 @ =0x0000042C
	adds r2, r2, r5
	mov ip, r2
	movs r7, #0
	ldr r0, _080200E8 @ =0x0000FFFC
	mov sl, r0
	ldr r2, _080200EC @ =FUN_08020cd8
	mov sb, r2
_0802005E:
	movs r0, #0x8c
	adds r1, r4, #0
	muls r1, r0, r1
	mov r2, ip
	ldr r0, [r2]
	adds r3, r0, r1
	ldrh r0, [r3, #0x34]
	cmp r0, r8
	bne _080200CC
	adds r1, r3, #0
	adds r1, #0x82
	movs r0, #0
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x37
	strb r7, [r0]
	mov r0, sb
	str r0, [r3, #0x30]
	adds r0, r3, #0
	adds r0, #0x39
	strb r7, [r0]
	adds r0, #1
	strb r7, [r0]
	ldr r2, [r3, #0x2c]
	ldrh r1, [r2, #6]
	mov r0, sl
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r3, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	orrs r1, r0
	strb r1, [r2, #4]
	adds r2, r3, #0
	adds r2, #0x88
	ldrh r1, [r2]
	adds r0, r3, #0
	adds r0, #0x80
	strh r1, [r0]
	adds r1, r3, #0
	adds r1, #0x72
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
	movs r6, #1
_080200CC:
	adds r4, #1
	ldrh r2, [r5, #0x1a]
	cmp r4, r2
	blt _0802005E
_080200D4:
	adds r0, r6, #0
_080200D6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080200E4: .4byte 0x0000042C
_080200E8: .4byte 0x0000FFFC
_080200EC: .4byte FUN_08020cd8
