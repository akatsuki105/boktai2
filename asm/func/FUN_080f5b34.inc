	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _080F5B4C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F5B50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F5B52
	.align 2, 0
_080F5B4C: .4byte 0x0000046D
_080F5B50:
	movs r0, #0
_080F5B52:
	cmp r0, #0
	beq _080F5B74
	adds r0, r7, #0
	movs r1, #7
	bl FUN_080ef86c
	adds r0, r7, #0
	bl FUN_080e499c
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #3
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080F5B74:
	ldr r2, _080F5BF8 @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080F5BF2
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r6, #0
	movs r5, #0
	strh r5, [r0]
	ldr r1, _080F5BFC @ =0x0000046B
	adds r0, r7, r1
	movs r4, #1
	strb r4, [r0]
	movs r2, #0x10
	subs r3, #0x1a
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _080F5C00 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	ldr r1, _080F5C04 @ =0x0000046A
	adds r0, r7, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r1, _080F5C08 @ =0x0000059C
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #0xf
	adds r3, #1
	adds r0, r7, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
_080F5BF2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F5BF8: .4byte 0x0000046E
_080F5BFC: .4byte 0x0000046B
_080F5C00: .4byte 0x00000469
_080F5C04: .4byte 0x0000046A
_080F5C08: .4byte 0x0000059C
