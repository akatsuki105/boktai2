	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x21
	ldrb r2, [r3]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r7, [r0]
	cmp r2, r7
	beq _080CBC10
	ldrh r0, [r0]
	subs r0, r0, r2
	subs r1, #0x2c
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7f
	bgt _080CBC0A
	adds r0, r2, #4
	b _080CBC0E
_080CBC0A:
	adds r0, r2, #0
	adds r0, #0xfc
_080CBC0E:
	strb r0, [r3]
_080CBC10:
	movs r7, #0x97
	lsls r7, r7, #1
	adds r7, r7, r6
	mov ip, r7
	ldrh r0, [r7]
	cmp r0, #0
	bne _080CBC64
	ldr r5, _080CBC58 @ =0x0203B400
	ldr r4, _080CBC5C @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _080CBC60 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	movs r7, #0x96
	lsls r7, r7, #1
	adds r2, r6, r7
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x78
	mov r1, ip
	strh r0, [r1]
	b _080CBC6A
	.align 2, 0
_080CBC58: .4byte 0x0203B400
_080CBC5C: .4byte 0x030046B8
_080CBC60: .4byte 0x000003FF
_080CBC64:
	subs r0, #1
	mov r7, ip
	strh r0, [r7]
_080CBC6A:
	adds r4, r6, #0
	adds r4, #0xb8
	adds r1, r6, #0
	adds r1, #0x24
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #7
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
