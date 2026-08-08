	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r5, #0x80
	lsls r5, r5, #4
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrh r2, [r3]
	adds r0, r5, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0
	beq _080E59F4
	b _080E5B14
_080E59F4:
	movs r6, #0
	adds r0, r5, #0
	orrs r0, r2
	strh r0, [r3]
	ldrh r7, [r1]
	cmp r7, #0
	beq _080E5A2A
	cmp r7, #1
	beq _080E5AA4
	movs r1, #1
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080E5A18
	b _080E5B14
_080E5A18:
	adds r0, r4, #0
	bl FUN_080ee738
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r4, r3
	mov r1, r8
	strh r1, [r0]
	b _080E5B14
_080E5A2A:
	movs r5, #1
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r4, r3
	ldr r1, [r2]
	adds r0, r1, #0
	ands r0, r5
	cmp r0, #0
	beq _080E5B14
	movs r0, #4
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	adds r0, r4, #0
	bl FUN_080ee2c8
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080E5A98 @ =0x00000469
	adds r0, r4, r3
	strb r6, [r0]
	ldr r1, _080E5A9C @ =0x0000046A
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	str r7, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r5, [r0]
	ldr r1, _080E5AA0 @ =0x00000584
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0xc
	adds r3, #1
	adds r0, r4, r3
	strb r5, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r7, [r0]
	b _080E5B14
	.align 2, 0
_080E5A98: .4byte 0x00000469
_080E5A9C: .4byte 0x0000046A
_080E5AA0: .4byte 0x00000584
_080E5AA4:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080E5B14
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r4, r3
	movs r1, #4
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_080ee538
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080E5B20 @ =0x00000469
	adds r0, r4, r3
	strb r6, [r0]
	ldr r1, _080E5B24 @ =0x0000046A
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	ldr r1, _080E5B28 @ =0x00000584
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0xc
	adds r3, #1
	adds r0, r4, r3
	strb r7, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
_080E5B14:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E5B20: .4byte 0x00000469
_080E5B24: .4byte 0x0000046A
_080E5B28: .4byte 0x00000584
