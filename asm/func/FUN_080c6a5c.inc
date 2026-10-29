	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r7, r0, #0
	mov r8, r1
	adds r6, r7, #0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C6AD4
	movs r5, #0
	strb r5, [r1]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r1, _080C6B38 @ =0x000002FA
	adds r0, r6, r1
	subs r2, #0xf8
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r2, r1, r0
	adds r3, #2
	adds r0, r6, r3
	strh r2, [r0]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	movs r0, #0x8d
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	str r4, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xf
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C6AD4:
	movs r1, #0xd8
	lsls r1, r1, #0xd
	adds r4, r7, #0
	adds r4, #0x98
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r7, #0
	bl Jormungandr_EasePos
	adds r0, r7, #0
	movs r1, #0x10
	bl FUN_080c4a54
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r0, [r4]
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [r4]
	mov r2, r8
	cmp r2, #0x3c
	bne _080C6B2A
	ldr r3, _080C6B3C @ =0x00002608
	adds r0, r7, r3
	ldr r4, [r0]
	cmp r4, #0
	beq _080C6B2A
	ldr r1, _080C6B40 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x10]
	str r1, [sp, #0xc]
	add r1, sp, #0x10
	add r0, sp, #0xc
	str r0, [r1, #4]
	adds r0, r4, #0
	bl VM_ExecByID
_080C6B2A:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C6B38: .4byte 0x000002FA
_080C6B3C: .4byte 0x00002608
_080C6B40: .4byte 0xFFFF0000
