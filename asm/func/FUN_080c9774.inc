	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov r8, r1
	adds r4, r5, #0
	adds r6, r4, #0
	adds r6, #0xa9
	ldrb r0, [r6]
	cmp r0, #0
	beq _080C97AE
	movs r2, #0
	strb r2, [r6]
	ldr r1, _080C9818 @ =0x000025F9
	adds r0, r4, r1
	strb r2, [r0]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xf
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C97AE:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _080C980C
	movs r2, #0xc0
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x3f
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080C97E4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xc
	bl FUN_080c4a40
_080C97E4:
	ldr r0, _080C981C @ =0x00000167
	cmp r8, r0
	bgt _080C97F4
	ldr r1, _080C9818 @ =0x000025F9
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080C980C
_080C97F4:
	ldr r1, _080C9820 @ =FUN_080c9824
	movs r0, #0x27
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r7, [r0]
	movs r0, #1
	strb r0, [r6]
_080C980C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C9818: .4byte 0x000025F9
_080C981C: .4byte 0x00000167
_080C9820: .4byte FUN_080c9824
