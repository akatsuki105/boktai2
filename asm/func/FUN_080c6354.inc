	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r7, r0, #0
	adds r6, r1, #0
	adds r4, r7, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C638A
	movs r2, #0
	strb r2, [r1]
	ldr r1, _080C63F4 @ =0x0000192F
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #5
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C638A:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080C63F4 @ =0x0000192F
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _080C63A8
	ldr r0, _080C63F8 @ =0x00000226
	bl PlaySound_082406e0
_080C63A8:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bls _080C63BA
	movs r0, #0
	strb r0, [r5]
_080C63BA:
	cmp r6, #0x20
	bne _080C6400
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, _080C63FC @ =0x000002FA
	adds r0, r4, r3
	subs r2, #0xf0
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r2, r1, r0
	subs r3, #8
	adds r0, r4, r3
	strh r2, [r0]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	b _080C640A
	.align 2, 0
_080C63F4: .4byte 0x0000192F
_080C63F8: .4byte 0x00000226
_080C63FC: .4byte 0x000002FA
_080C6400:
	cmp r6, #0x20
	ble _080C640A
	adds r0, r7, #0
	bl FUN_080c4990
_080C640A:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
