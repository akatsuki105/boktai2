	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x18
	adds r0, r0, r5
	mov sb, r0
	movs r4, #0
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08048034
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	subs r3, #2
	adds r1, r5, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080480A2
	strh r4, [r2]
	movs r4, #2
	b _080480A2
_08048034:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r3, r5, r0
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, [r3]
	ldr r0, [r2]
	cmp r1, r0
	blo _08048088
	str r4, [r2]
	str r4, [r3]
	ldr r2, _08048080 @ =0x030044E0
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08048062
	ldr r3, _08048084 @ =0x0000017F
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r4, #1
_08048062:
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804806E
	movs r4, #1
_0804806E:
	movs r1, #0x85
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _080480A2
	.align 2, 0
_08048080: .4byte 0x030044E0
_08048084: .4byte 0x0000017F
_08048088:
	ldr r2, _080480E4 @ =0x0000017F
	adds r0, r5, r2
	strb r4, [r0]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r3]
	adds r0, #1
	str r0, [r3]
_080480A2:
	ldr r1, _080480E4 @ =0x0000017F
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080480B0
	cmp r4, #0
	beq _08048188
_080480B0:
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _08048188
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	movs r3, #0
	strh r1, [r0]
	ldrb r0, [r2]
	cmp r0, #0
	beq _080480EC
	ldr r1, _080480E8 @ =TextBox_StateFastForward
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	mov r0, sb
	strb r3, [r0, #9]
	strb r3, [r0, #8]
	b _0804810A
	.align 2, 0
_080480E4: .4byte 0x0000017F
_080480E8: .4byte TextBox_StateFastForward
_080480EC:
	ldr r1, _08048170 @ =TextBox_StateType
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	ldr r3, _08048174 @ =0x00000183
	adds r1, r5, r3
	movs r0, #3
	strb r0, [r1]
	ldr r0, _08048178 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	mov r2, sb
	strb r0, [r2, #9]
_0804810A:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r0, r5, #0
	bl TextBox_GetLine
	mov r1, sb
	str r0, [r1, #0x1c]
	cmp r4, #2
	beq _08048126
	ldr r0, _0804817C @ =0x00000107
	bl PlaySound_082406e0
_08048126:
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r4, r5, r2
	ldrb r0, [r4]
	ldr r3, _08048180 @ =0x00000179
	adds r3, r3, r5
	mov r8, r3
	ldrb r1, [r3]
	adds r2, #2
	adds r7, r5, r2
	ldrb r2, [r7]
	ldr r3, _08048184 @ =0x0000017B
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
	bl TextRenderer_SetRect
	adds r0, r5, #0
	adds r0, #0x18
	bl FUN_08049640
	movs r1, #0x85
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _08048198
	.align 2, 0
_08048170: .4byte TextBox_StateType
_08048174: .4byte 0x00000183
_08048178: .4byte 0x030046A0
_0804817C: .4byte 0x00000107
_08048180: .4byte 0x00000179
_08048184: .4byte 0x0000017B
_08048188:
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r1, r5, r3
	bl MainSprite_AdvanceAnim
_08048198:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
