	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	mov r8, r0
	adds r5, r1, #0
	mov r6, r8
	movs r0, #0xa9
	adds r0, r0, r6
	mov sb, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C99CC
	movs r2, #0
	mov r1, sb
	strb r2, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xf
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	subs r2, #8
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _080C9A6C @ =0x000002FA
	adds r1, r6, r0
	subs r2, #0x70
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r2, #0x72
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, _080C9A70 @ =0x000025F8
	adds r1, r6, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _080C9A74 @ =0x0000022F
	bl PlaySound_082406e0
_080C99CC:
	adds r0, r6, #0
	bl Jormungandr_EasePos
	ldr r2, _080C9A78 @ =0x00600002
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r7, #3
	ands r7, r5
	cmp r7, #0
	bne _080C9A5E
	ldr r4, _080C9A7C @ =0xFFFF0000
	ldr r1, _080C9A80 @ =0x0000FFFF
	mov ip, r1
	str r7, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	str r0, [sp, #0x14]
	ldr r2, _080C9A84 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C9A88 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080C9A8C @ =0x0203B400
	adds r0, r0, r2
	ldrh r3, [r0]
	asrs r3, r3, #3
	movs r0, #0xff
	ands r3, r0
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r0, [sp, #0x18]
	ands r0, r4
	orrs r0, r1
	ldr r2, _080C9A90 @ =0x0000026E
	adds r1, r6, r2
	ldrh r1, [r1]
	subs r3, #0x80
	adds r1, r3, r1
	lsls r1, r1, #0x10
	mov r2, ip
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r2, [r0]
	subs r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x18
	ldr r1, [r0, #4]
	ands r1, r4
	orrs r1, r2
	str r1, [r0, #4]
	str r7, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	add r2, sp, #0x10
	movs r3, #0
	bl EmitSmoke
_080C9A5E:
	cmp r5, #0x4f
	bgt _080C9A94
	adds r0, r6, #0
	movs r1, #8
	bl FUN_080c4a54
	b _080C9AD8
	.align 2, 0
_080C9A6C: .4byte 0x000002FA
_080C9A70: .4byte 0x000025F8
_080C9A74: .4byte 0x0000022F
_080C9A78: .4byte 0x00600002
_080C9A7C: .4byte 0xFFFF0000
_080C9A80: .4byte 0x0000FFFF
_080C9A84: .4byte 0x030046B8
_080C9A88: .4byte 0x000003FF
_080C9A8C: .4byte 0x0203B400
_080C9A90: .4byte 0x0000026E
_080C9A94:
	cmp r5, #0x64
	bne _080C9AA4
	ldr r2, _080C9AA0 @ =0x000008F4
	adds r1, r6, r2
	movs r0, #0
	b _080C9AD6
	.align 2, 0
_080C9AA0: .4byte 0x000008F4
_080C9AA4:
	cmp r5, #0x96
	bne _080C9AD8
	movs r2, #0xba
	lsls r2, r2, #2
	add r2, r8
	movs r0, #0xbc
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C9AE8 @ =FUN_080c9aec
	movs r0, #0x29
	mov r3, r8
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	mov r0, r8
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	movs r0, #1
	mov r1, sb
_080C9AD6:
	strb r0, [r1]
_080C9AD8:
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C9AE8: .4byte FUN_080c9aec
