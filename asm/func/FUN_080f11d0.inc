	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080F11E8 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F11EC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F11EE
	.align 2, 0
_080F11E8: .4byte 0x0000046C
_080F11EC:
	movs r0, #0
_080F11EE:
	cmp r0, #0
	beq _080F1222
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _080F129C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _080F12A0 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _080F12A4 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_080F1222:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F12BA
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080F12BA
	ldr r6, _080F12A0 @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080F12B0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xc
	ldr r2, _080F12A8 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0x19
	adds r0, r5, r6
	str r4, [r0]
	ldr r1, _080F12AC @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r2, #0x1a
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _080F12A0 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _080F12BA
	.align 2, 0
_080F129C: .4byte 0x0000046D
_080F12A0: .4byte 0x0000046B
_080F12A4: .4byte 0x00000553
_080F12A8: .4byte 0x0000046A
_080F12AC: .4byte 0x0000046C
_080F12B0:
	ldr r6, _080F12C0 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F12BA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F12C0: .4byte 0x00000484
