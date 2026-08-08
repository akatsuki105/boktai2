	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _080771C8 @ =0x0000037E
	adds r4, r6, r0
	ldrh r1, [r4]
	cmp r1, #0
	bne _0807712E
	movs r2, #0x96
	lsls r2, r2, #4
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _080771CC @ =0x0000037F
	bl PlaySound_082406e0
	movs r0, #0x38
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_0807712E:
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	blt _08077152
	adds r0, r6, #0
	movs r1, #0x41
	bl FUN_08060c40
	adds r2, r6, #0
	adds r2, #0xa8
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
_08077152:
	adds r0, r6, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r6, #0
	adds r0, #0xc2
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xd0
	ldr r0, _080771D0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080771D4 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080771D8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080771E0
	.align 2, 0
_080771C8: .4byte 0x0000037E
_080771CC: .4byte 0x0000037F
_080771D0: .4byte 0x03003584
_080771D4: .4byte 0x000002E6
_080771D8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080771E0:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077204
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0807720C
_08077204:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0807720C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08077244 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0807727C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08077248
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0807723C
	ldrb r0, [r4, #5]
_0807723C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08077258
	.align 2, 0
_08077244: .4byte 0x0000FFFF
_08077248:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08077258
	strh r1, [r4, #8]
_08077258:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807727C
	movs r0, #1
	strb r0, [r4, #7]
_0807727C:
	ldr r3, _080772D8 @ =0x0000095E
	adds r1, r6, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _080772DC @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080772A2
	movs r0, #0x20
	strh r0, [r1]
_080772A2:
	ldr r0, _080772E0 @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _080772CE
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	ldr r2, _080772E4 @ =0x00000381
	adds r0, r6, r2
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_08072620
	ldr r3, _080772E8 @ =0x000004AF
	adds r0, r6, r3
	strb r4, [r0]
_080772CE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080772D8: .4byte 0x0000095E
_080772DC: .4byte 0x0000FFFF
_080772E0: .4byte 0x0000037E
_080772E4: .4byte 0x00000381
_080772E8: .4byte 0x000004AF
