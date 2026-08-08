	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _080FE724 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FE728
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FE72A
	.align 2, 0
_080FE724: .4byte 0x0000046C
_080FE728:
	movs r0, #0
_080FE72A:
	cmp r0, #0
	beq _080FE7A8
	ldr r4, _080FE7C8 @ =0x080F3CDD
	movs r3, #0xa
	ldr r0, _080FE7CC @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080FE7D0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r5, #5]
	adds r1, #0x17
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e5718
	adds r0, r5, #0
	bl FUN_080e6750
	ldr r2, _080FE7D4 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _080FE78C
	movs r0, #4
	ldr r1, _080FE7D8 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080FE78C:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_080FE7A8:
	ldr r1, _080FE7D0 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080FE7E0
	adds r0, r5, #0
	bl FUN_080ff67c
	movs r0, #4
	ldr r1, _080FE7DC @ =0x0000065C
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080FE7EA
	.align 2, 0
_080FE7C8: .4byte 0x080F3CDD
_080FE7CC: .4byte 0x0000046D
_080FE7D0: .4byte 0x0000046B
_080FE7D4: .4byte 0x000001DF
_080FE7D8: .4byte 0x00000222
_080FE7DC: .4byte 0x0000065C
_080FE7E0:
	ldr r2, _080FE7F0 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080FE7EA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080FE7F0: .4byte 0x00000484
