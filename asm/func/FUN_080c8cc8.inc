	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov r8, r1
	mov r6, sb
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C8D2C
	movs r3, #0
	strb r3, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C8DA8 @ =0x000002F2
	adds r1, r6, r2
	adds r2, #0x2e
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	str r1, [sp]
	str r3, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x11
	movs r2, #0
	bl SpriteHolder_SetAnim
_080C8D2C:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _080C8D98
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r2, r8
	cmp r2, #5
	ble _080C8D84
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r5, #1
	str r5, [sp]
	str r7, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0x12
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r6, r2
	str r5, [sp]
	str r7, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x19
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C8D84:
	mov r0, r8
	cmp r0, #0x13
	ble _080C8D92
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080C8D92:
	mov r0, sb
	bl FUN_080c4990
_080C8D98:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8DA8: .4byte 0x000002F2
