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
	beq _080C92AC
	movs r2, #0
	strb r2, [r6]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #8
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C92AC:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _080C9326
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080C9300 @ =0x000002EA
	adds r3, r4, r0
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080C9304 @ =0x000002FA
	adds r2, r4, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r0, #0x14
	cmp r1, r0
	ble _080C9308
	ldrh r1, [r3]
	subs r1, #0x1e
	strh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r0, #0x14
	cmp r1, r0
	bge _080C9326
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r3]
	b _080C9326
	.align 2, 0
_080C9300: .4byte 0x000002EA
_080C9304: .4byte 0x000002FA
_080C9308:
	mov r0, r8
	cmp r0, #0x17
	ble _080C9326
	ldr r1, _080C9334 @ =FUN_080c9338
	movs r0, #0x23
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
_080C9326:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C9334: .4byte FUN_080c9338
