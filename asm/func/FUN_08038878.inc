	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r1, #4
	ldr r0, _08038928 @ =0x03002BC0
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _08038892
	b _080389A0
_08038892:
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xc9
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r0, #0
	mov sb, r0
	mov sl, r0
	ldr r1, _0803892C @ =0x0000068C
	adds r1, r1, r7
	mov r8, r1
	adds r2, #0xda
	adds r6, r7, r2
_080388B0:
	ldrb r0, [r5, #2]
	adds r4, r5, #0
	adds r4, #0xd4
	cmp r0, #0
	beq _0803898C
	mov r0, sl
	strb r0, [r5, #5]
	ldr r1, _08038930 @ =0x085AAE30
	ldrb r0, [r5, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	bl _call_via_r3
	adds r0, r5, #0
	adds r0, #0x24
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r7, r2
	bl MainSprite_AdvanceAnim
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	beq _080388F2
	subs r0, #1
	strh r0, [r5, #0x18]
	adds r0, r5, #0
	movs r1, #1
	bl DurathrorElem_SetFlags
_080388F2:
	ldrh r1, [r5, #0x1a]
	movs r2, #0x1a
	ldrsh r0, [r5, r2]
	cmp r0, #0
	ble _0803890E
	subs r0, r1, #1
	strh r0, [r5, #0x1a]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0803890E
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_080373a4
_0803890E:
	adds r0, r5, #0
	movs r1, #1
	bl DurathrorElem_TestFlags
	cmp r0, #0
	beq _08038934
	ldrh r0, [r6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r6]
	mov r2, sl
	strh r2, [r5, #6]
	b _08038948
	.align 2, 0
_08038928: .4byte 0x03002BC0
_0803892C: .4byte 0x0000068C
_08038930: .4byte 0x085AAE30
_08038934:
	ldrh r1, [r6]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r6]
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
_08038948:
	adds r0, r5, #0
	movs r1, #2
	bl DurathrorElem_TestFlags
	cmp r0, #0
	beq _08038968
	adds r4, r5, #0
	adds r4, #0x84
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_08038968:
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _0803897A
	adds r0, r5, #0
	bl FUN_080375d4
	ldrb r0, [r5, #8]
	subs r0, #1
	strb r0, [r5, #8]
_0803897A:
	ldr r0, [r5, #0x10]
	adds r0, #1
	str r0, [r5, #0x10]
	movs r0, #0xba
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803898C:
	movs r1, #1
	add sb, r1
	movs r2, #0x92
	lsls r2, r2, #1
	add r8, r2
	adds r6, r6, r2
	adds r5, r5, r2
	mov r0, sb
	cmp r0, #5
	ble _080388B0
_080389A0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
