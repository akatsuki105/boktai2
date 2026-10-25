	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r6
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C9B32
	movs r4, #0
	strb r4, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x35
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	ldr r2, _080C9CA0 @ =0x000025F8
	adds r1, r6, r2
	movs r0, #3
	strb r0, [r1]
	ldr r5, _080C9CA4 @ =0x000025EA
	adds r0, r6, r5
	strh r4, [r0]
_080C9B32:
	cmp r7, #0x23
	bne _080C9B3C
	ldr r0, _080C9CA8 @ =0x0000022B
	bl PlaySound_082406e0
_080C9B3C:
	cmp r7, #0x36
	bne _080C9B5C
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x36
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C9B5C:
	ldr r2, _080C9CAC @ =0x00400002
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	subs r0, #0x23
	cmp r0, #0xf
	bhi _080C9B7A
	movs r0, #0x33
	subs r0, r0, r7
	lsls r0, r0, #1
	bl FUN_0823b9cc
_080C9B7A:
	adds r0, r7, #0
	subs r0, #0x47
	cmp r0, #0xf
	bhi _080C9B8C
	movs r0, #0x57
	subs r0, r0, r7
	lsls r0, r0, #1
	bl FUN_0823b9cc
_080C9B8C:
	adds r0, r7, #0
	subs r0, #0x50
	cmp r0, #0xf
	bhi _080C9C1C
	movs r5, #3
	ands r5, r7
	cmp r5, #0
	bne _080C9C1C
	ldr r4, _080C9CB0 @ =0xFFFF0000
	ldr r2, _080C9CB4 @ =0x0000FFFF
	mov ip, r2
	str r5, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	str r0, [sp, #0x14]
	ldr r2, _080C9CB8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C9CBC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C9CC0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	asrs r3, r3, #3
	movs r2, #0x7f
	mov sb, r2
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r0, [sp, #0x18]
	ands r0, r4
	orrs r0, r1
	ldr r2, _080C9CC4 @ =0x000002EA
	adds r1, r6, r2
	ldrh r1, [r1]
	mov r2, sb
	ands r3, r2
	adds r1, r3, r1
	lsls r1, r1, #0x10
	mov r2, ip
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r6, r0
	ldr r2, _080C9CC8 @ =0xFFFFFE00
	adds r0, r2, #0
	adds r3, r3, r0
	ldrh r2, [r1]
	subs r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x18
	ldr r1, [r0, #4]
	ands r1, r4
	orrs r1, r2
	str r1, [r0, #4]
	str r5, [sp]
	movs r1, #0x10
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	add r2, sp, #0x10
	movs r3, #0
	bl EmitSmoke
_080C9C1C:
	ldr r4, _080C9CA4 @ =0x000025EA
	add r4, r8
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	movs r2, #0xbb
	lsls r2, r2, #2
	add r2, r8
	ldrh r1, [r2]
	adds r1, #2
	strh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0xbf
	lsls r3, r3, #2
	add r3, r8
	movs r5, #0
	ldrsh r0, [r3, r5]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r0, r5
	cmp r1, r0
	blt _080C9C50
	ldrh r0, [r3]
	adds r0, r0, r5
	strh r0, [r2]
_080C9C50:
	ldr r2, _080C9CC4 @ =0x000002EA
	add r2, r8
	ldrh r0, [r4]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r1, _080C9CCC @ =0x000002FA
	add r1, r8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r1]
	movs r5, #0
	ldrsh r1, [r1, r5]
	cmp r0, r1
	bge _080C9C82
	strh r3, [r2]
	ldrh r0, [r4]
	rsbs r0, r0, #0
	strh r0, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #2
	bl Div
	strh r0, [r4]
_080C9C82:
	cmp r7, #0xf0
	bne _080C9C92
	movs r1, #0xba
	lsls r1, r1, #2
	add r1, r8
	adds r0, r6, #0
	bl FUN_08023024
_080C9C92:
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C9CA0: .4byte 0x000025F8
_080C9CA4: .4byte 0x000025EA
_080C9CA8: .4byte 0x0000022B
_080C9CAC: .4byte 0x00400002
_080C9CB0: .4byte 0xFFFF0000
_080C9CB4: .4byte 0x0000FFFF
_080C9CB8: .4byte 0x030046B8
_080C9CBC: .4byte 0x000003FF
_080C9CC0: .4byte 0x0203B400
_080C9CC4: .4byte 0x000002EA
_080C9CC8: .4byte 0xFFFFFE00
_080C9CCC: .4byte 0x000002FA
