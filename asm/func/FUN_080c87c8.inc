	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r1, r4, #0
	adds r5, r1, #0
	adds r5, #0xa9
	ldrb r0, [r5]
	cmp r0, #0
	beq _080C87F8
	movs r2, #0
	strb r2, [r5]
	movs r3, #0xd2
	lsls r3, r3, #3
	adds r0, r1, r3
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x30
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C87F8:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _080C883C
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080c4990
	cmp r7, #0x64
	ble _080C883C
	ldr r1, _080C8844 @ =FUN_080c8848
	movs r0, #0x16
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	movs r0, #1
	strb r0, [r5]
_080C883C:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8844: .4byte FUN_080c8848
