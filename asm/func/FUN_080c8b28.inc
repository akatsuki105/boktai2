	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	adds r5, r1, #0
	adds r4, r7, #0
	movs r0, #0xa9
	adds r0, r0, r4
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C8B68
	movs r2, #0
	mov r1, r8
	strb r2, [r1]
	ldr r0, _080C8BD0 @ =0x000025EE
	adds r1, r4, r0
	movs r0, #8
	strh r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x33
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C8B68:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _080C8C3C
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r5, #5
	bne _080C8B9C
	ldr r1, _080C8BD0 @ =0x000025EE
	adds r0, r4, r1
	ldrh r2, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080c35f0
_080C8B9C:
	cmp r5, #0x59
	ble _080C8C3C
	ldr r0, _080C8BD4 @ =0x000025EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _080C8BDC
	ldr r1, _080C8BD8 @ =FUN_080c8c4c
	movs r0, #0x1a
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
	b _080C8C3C
	.align 2, 0
_080C8BD0: .4byte 0x000025EE
_080C8BD4: .4byte 0x000025EC
_080C8BD8: .4byte FUN_080c8c4c
_080C8BDC:
	ldr r2, _080C8C14 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C8C18 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C8C1C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r3, r0, #3
	movs r5, #1
	ands r3, r5
	cmp r3, #0
	beq _080C8C24
	ldr r1, _080C8C20 @ =FUN_080c87c8
	movs r0, #0x15
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	mov r0, r8
	strb r5, [r0]
	b _080C8C3C
	.align 2, 0
_080C8C14: .4byte 0x030046B8
_080C8C18: .4byte 0x000003FF
_080C8C1C: .4byte 0x0203B400
_080C8C20: .4byte FUN_080c87c8
_080C8C24:
	ldr r1, _080C8C48 @ =FUN_080c8aa8
	movs r0, #0x18
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	mov r1, r8
	strb r5, [r1]
_080C8C3C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8C48: .4byte FUN_080c8aa8
