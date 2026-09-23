	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08020118 @ =0x000085E6
	bl FUN_08230e70
	adds r5, r0, #0
	cmp r5, #0
	beq _08020112
	movs r6, #0
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _0802011C
_08020112:
	movs r0, #1
	rsbs r0, r0, #0
	b _080201AE
	.align 2, 0
_08020118: .4byte 0x000085E6
_0802011C:
	bl Script_GetValue
	mov r8, r0
	movs r4, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _080201AC
	ldr r1, _080201BC @ =0x0000042C
	adds r1, r1, r5
	mov ip, r1
	movs r7, #0
	movs r2, #1
	mov sb, r2
	ldr r0, _080201C0 @ =0x0000FFFD
	mov sl, r0
_0802013A:
	movs r0, #0x8c
	adds r1, r4, #0
	muls r1, r0, r1
	mov r2, ip
	ldr r0, [r2]
	adds r3, r0, r1
	ldrh r0, [r3, #0x34]
	cmp r0, r8
	bne _080201A4
	adds r0, r3, #0
	adds r0, #0x82
	strh r7, [r0]
	subs r0, #0x4b
	mov r1, sb
	strb r1, [r0]
	ldr r2, _080201C4 @ =FUN_08020d10
	str r2, [r3, #0x30]
	adds r0, #0x4d
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x39
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x3a
	movs r1, #0
	strb r1, [r0]
	ldr r2, [r3, #0x2c]
	ldrh r1, [r2, #6]
	mov r0, sl
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r3, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	adds r0, r3, #0
	adds r0, #0x80
	strh r7, [r0]
	subs r0, #0xe
	ldrh r0, [r0]
	strh r0, [r3, #0x1e]
	movs r6, #1
_080201A4:
	adds r4, #1
	ldrh r2, [r5, #0x1a]
	cmp r4, r2
	blt _0802013A
_080201AC:
	adds r0, r6, #0
_080201AE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080201BC: .4byte 0x0000042C
_080201C0: .4byte 0x0000FFFD
_080201C4: .4byte FUN_08020d10
