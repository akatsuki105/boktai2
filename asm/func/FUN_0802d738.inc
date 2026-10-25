	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	mov r8, r7
	adds r4, r7, #0
	adds r4, #0x48
	adds r1, r7, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D75E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802D764
_0802D75E:
	movs r0, #0
	adds r1, r7, #0
	adds r1, #0xa7
_0802D764:
	cmp r0, #0
	beq _0802D770
	movs r0, #0x18
	adds r2, r7, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802D770:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D846
	ldr r5, _0802D818 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r5
	ldr r1, _0802D81C @ =0x0000FF5C
	orrs r0, r1
	str r0, [sp]
	mov r2, sp
	ldr r0, [sp, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #4]
	adds r3, r4, #0
	adds r3, #8
	mov r0, sp
	ldrh r4, [r4, #8]
	ldrh r0, [r0]
	adds r1, r4, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r6, [r3, #2]
	adds r0, r0, r6
	strh r0, [r2, #2]
	ldrh r1, [r3, #4]
	ldrh r3, [r2, #4]
	adds r0, r1, r3
	strh r0, [r2, #4]
	ldr r0, [sp, #8]
	ands r0, r5
	movs r2, #0xa4
	orrs r0, r2
	str r0, [sp, #8]
	add r3, sp, #8
	ldr r0, [r3, #4]
	ands r0, r5
	orrs r0, r2
	str r0, [r3, #4]
	ldrh r0, [r3]
	adds r4, r4, r0
	strh r4, [r3]
	ldrh r0, [r3, #2]
	adds r0, r0, r6
	strh r0, [r3, #2]
	ldrh r0, [r3, #4]
	adds r1, r1, r0
	strh r1, [r3, #4]
	ldr r0, _0802D820 @ =0x0000016B
	add r0, r8
	ldrb r1, [r0]
	mov r0, r8
	mov r2, sp
	bl FUN_08028720
	adds r2, r0, #0
	cmp r2, #0
	blt _0802D82C
	ldr r1, _0802D824 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r0, #0x20]
	ands r0, r1
	rsbs r0, r0, #0
	lsrs r3, r0, #0x1f
	cmp r3, #0
	bne _0802D82C
	ldr r0, _0802D828 @ =0x00000173
	add r0, r8
	strb r2, [r0]
	movs r0, #0x18
	adds r1, r7, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbc
	str r3, [r0]
	adds r1, #2
	b _0802D840
	.align 2, 0
_0802D818: .4byte 0xFFFF0000
_0802D81C: .4byte 0x0000FF5C
_0802D820: .4byte 0x0000016B
_0802D824: .4byte 0x03002BE0
_0802D828: .4byte 0x00000173
_0802D82C:
	movs r0, #0x19
	adds r2, r7, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa8
_0802D840:
	movs r0, #1
	strb r0, [r1]
	b _0802D850
_0802D846:
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D850:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
