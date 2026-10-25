	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r1, #0
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C96F2
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xe
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C96F2:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C9764
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r6, _080C976C @ =0x000002EA
	adds r3, r4, r6
	movs r0, #0
	ldrsh r1, [r3, r0]
	adds r6, #0x10
	adds r2, r4, r6
	movs r6, #0
	ldrsh r0, [r2, r6]
	adds r0, #0x14
	cmp r1, r0
	ble _080C9742
	ldrh r1, [r3]
	subs r1, #0xa
	strh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r6, #0
	ldrsh r0, [r2, r6]
	adds r0, #0x14
	cmp r1, r0
	bge _080C9742
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r3]
_080C9742:
	cmp r5, #0xe
	ble _080C9764
	ldr r2, _080C9770 @ =FUN_080c9774
	movs r0, #0x26
	adds r3, r4, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C9764:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C976C: .4byte 0x000002EA
_080C9770: .4byte FUN_080c9774
