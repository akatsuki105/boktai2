	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	ldr r0, _08047ABC @ =0x030000C4
	ldr r5, [r0]
	cmp r5, #0
	beq _08047AFE
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0x18
	adds r2, r2, r5
	mov sb, r2
	cmp r0, #0
	beq _08047AFE
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r4, r5, r3
	ldrb r0, [r4]
	ldr r1, _08047AC0 @ =0x00000179
	adds r1, r1, r5
	mov r8, r1
	ldrb r1, [r1]
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r7, r5, r2
	ldrb r2, [r7]
	adds r3, #3
	adds r6, r5, r3
	ldrb r3, [r6]
	bl FUN_0822ea60
	ldrb r1, [r4]
	mov r0, r8
	ldrb r2, [r0]
	ldrb r3, [r7]
	ldrb r0, [r6]
	str r0, [sp]
	mov r0, sb
	bl FUN_08049650
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r5, r1
	mov r2, sl
	strh r2, [r0]
	ldrh r1, [r0]
	adds r0, r5, #0
	bl TextBox_GetLine
	mov r3, sb
	str r0, [r3, #0x1c]
	movs r1, #0xbf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08047ACC
	ldr r0, _08047AC4 @ =TextBox_StateType
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	ldr r3, _08047AC8 @ =0x00000183
	adds r1, r5, r3
	movs r0, #3
	strb r0, [r1]
	b _08047AE0
	.align 2, 0
_08047ABC: .4byte 0x030000C4
_08047AC0: .4byte 0x00000179
_08047AC4: .4byte TextBox_StateType
_08047AC8: .4byte 0x00000183
_08047ACC:
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	ldr r1, _08047B10 @ =TextBox_StateRenderAll
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
_08047AE0:
	mov r0, sb
	bl FUN_08049640
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, _08047B14 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_08047AFE:
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047B10: .4byte TextBox_StateRenderAll
_08047B14: .4byte 0x0000FFFF
