	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r1, r4, #0
	adds r5, r1, #0
	adds r5, #0xa9
	ldrb r0, [r5]
	cmp r0, #0
	beq _080C8674
	movs r2, #0
	strb r2, [r5]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r1, r3
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #3
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C8674:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080C86A0
	cmp r6, #0xf
	ble _080C86A0
	ldr r1, _080C86A8 @ =FUN_080c6c8c
	adds r0, r4, #0
	adds r0, #0xa3
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	movs r0, #1
	strb r0, [r5]
_080C86A0:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C86A8: .4byte FUN_080c6c8c
