	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	movs r1, #0x1f
	ldrh r0, [r6, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _080D1BF8
	ldr r5, [r7, #0x4c]
	adds r0, r7, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamageAlt
	movs r4, #0
_080D1B84:
	lsls r1, r4, #2
	ldr r2, _080D1C00 @ =0x00000AB4
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _080D1BA2
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl _call_via_r3
	ldrh r1, [r6, #0x3e]
	adds r1, r1, r0
	strh r1, [r6, #0x3e]
_080D1BA2:
	adds r4, #1
	cmp r4, #2
	ble _080D1B84
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D1BF8
	ldr r2, _080D1C04 @ =0x00000A8D
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080D1BF8
	adds r0, r5, #0
	bl FUN_080cc618
	cmp r0, #0
	beq _080D1BF8
	adds r2, r6, #0
	adds r2, #0x43
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080D1BF8
	ldrh r1, [r6, #0x3e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsrs r0, r0, #1
	strh r0, [r6, #0x3e]
	ldrh r1, [r6, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D1BF8
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
_080D1BF8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1C00: .4byte 0x00000AB4
_080D1C04: .4byte 0x00000A8D
