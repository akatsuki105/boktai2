	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	mov r8, r1
	adds r5, r6, #0
	adds r7, r5, #0
	adds r7, #0xa9
	ldrb r0, [r7]
	cmp r0, #0
	beq _080C7572
	movs r4, #0
	strb r4, [r7]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r2, #0xf4
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _080C75C0 @ =0x000008F2
	adds r1, r5, r0
	movs r0, #0xc0
	strb r0, [r1]
	ldr r0, _080C75C4 @ =0x00000225
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C7572:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C75E8
	mov r2, r8
	cmp r2, #9
	ble _080C7592
	adds r0, r5, #0
	bl Jormungandr_EasePos
_080C7592:
	mov r0, r8
	cmp r0, #0xf
	ble _080C75E8
	ldr r2, _080C75C8 @ =0x00001908
	adds r1, r5, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _080C75D0
	ldr r1, _080C75CC @ =FUN_080c73c0
	movs r0, #3
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	b _080C75E4
	.align 2, 0
_080C75C0: .4byte 0x000008F2
_080C75C4: .4byte 0x00000225
_080C75C8: .4byte 0x00001908
_080C75CC: .4byte FUN_080c73c0
_080C75D0:
	ldr r1, _080C75F4 @ =FUN_080c75f8
	movs r0, #6
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
_080C75E4:
	movs r0, #1
	strb r0, [r7]
_080C75E8:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C75F4: .4byte FUN_080c75f8
