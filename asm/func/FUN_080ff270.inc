	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _080FF290 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FF294
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FF296
	.align 2, 0
_080FF290: .4byte 0x0000046C
_080FF294:
	movs r0, #0
_080FF296:
	cmp r0, #0
	beq _080FF2CA
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _080FF2F0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080FF2F4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_080FF2CA:
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080FF31C
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080FF2FC
	ldr r1, _080FF2F8 @ =0x0000065C
	adds r0, r6, r1
	b _080FF30C
	.align 2, 0
_080FF2F0: .4byte 0x0000046D
_080FF2F4: .4byte 0x0000046B
_080FF2F8: .4byte 0x0000065C
_080FF2FC:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080FF31C
	ldr r2, _080FF318 @ =0x0000065C
	adds r0, r6, r2
_080FF30C:
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	b _080FF362
	.align 2, 0
_080FF318: .4byte 0x0000065C
_080FF31C:
	ldr r3, _080FF350 @ =0x0000046B
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080FF358
	movs r2, #0xf
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _080FF354 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _080FF362
	.align 2, 0
_080FF350: .4byte 0x0000046B
_080FF354: .4byte 0x00000484
_080FF358:
	ldr r0, _080FF368 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080FF362:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080FF368: .4byte 0x00000484
