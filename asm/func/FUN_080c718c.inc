	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r7, #0
	movs r0, #0xa9
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C71F8
	movs r2, #0
	mov r1, r8
	strb r2, [r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r3, #8
	adds r0, r5, r3
	movs r4, #0
	strh r1, [r0]
	ldr r1, _080C7234 @ =0x000002FA
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, #0x80
	adds r3, #2
	adds r1, r5, r3
	strh r0, [r1]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, #0x60
	adds r3, #2
	adds r1, r5, r3
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	ldr r2, _080C7238 @ =0x000025FA
	adds r0, r5, r2
	strb r4, [r0]
_080C71F8:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C72DC
	adds r0, r5, #0
	bl FUN_080c4990
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080c4a40
	cmp r6, #0x23
	bne _080C723C
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x13
	b _080C72A8
	.align 2, 0
_080C7234: .4byte 0x000002FA
_080C7238: .4byte 0x000025FA
_080C723C:
	cmp r6, #0x3c
	bne _080C7268
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x14
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	adds r0, r5, #0
	bl FUN_080c6b44
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r5, r2
	b _080C728A
_080C7268:
	cmp r6, #0x6e
	bne _080C727A
	adds r0, r5, #0
	bl FUN_080c6b44
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r1, r5, r3
	b _080C728A
_080C727A:
	cmp r6, #0xa0
	bne _080C7292
	adds r0, r5, #0
	bl FUN_080c6b44
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r5, r0
_080C728A:
	ldrh r0, [r1]
	subs r0, #0x60
	strh r0, [r1]
	b _080C72DC
_080C7292:
	cmp r6, #0xad
	bne _080C72B2
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x15
_080C72A8:
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	b _080C72DC
_080C72B2:
	cmp r6, #0xd2
	bne _080C72DC
	ldr r2, _080C72E8 @ =0x00001909
	adds r0, r7, r2
	ldrb r1, [r0]
	ldr r3, _080C72EC @ =0x00001908
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _080C72F0 @ =FUN_080c73c0
	movs r0, #3
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
_080C72DC:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C72E8: .4byte 0x00001909
_080C72EC: .4byte 0x00001908
_080C72F0: .4byte FUN_080c73c0
