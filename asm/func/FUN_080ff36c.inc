	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080FF384 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FF388
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FF38A
	.align 2, 0
_080FF384: .4byte 0x0000046C
_080FF388:
	movs r0, #0
_080FF38A:
	cmp r0, #0
	beq _080FF3BC
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _080FF438 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080FF43C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_080FF3BC:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080FF452
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080FF452
	ldr r2, _080FF43C @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080FF448
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r3, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _080FF440 @ =0x00000484
	adds r0, r5, r1
	str r3, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r4, _080FF444 @ =0x000005A4
	adds r0, r5, r4
	ldr r2, [r0]
	ldr r4, _080FF438 @ =0x0000046D
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _080FF43C @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	b _080FF452
	.align 2, 0
_080FF438: .4byte 0x0000046D
_080FF43C: .4byte 0x0000046B
_080FF440: .4byte 0x00000484
_080FF444: .4byte 0x000005A4
_080FF448:
	ldr r4, _080FF458 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080FF452:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080FF458: .4byte 0x00000484
