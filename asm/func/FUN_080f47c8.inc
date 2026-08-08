	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080F47E0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F47E4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F47E6
	.align 2, 0
_080F47E0: .4byte 0x0000046D
_080F47E4:
	movs r0, #0
_080F47E6:
	cmp r0, #0
	beq _080F4800
	ldrb r0, [r5, #5]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
_080F4800:
	movs r2, #0x10
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080F4896
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r4, _080F489C @ =FUN_080f3cdc
	movs r3, #1
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r6, _080F48A0 @ =0x00000554
	adds r0, r5, r6
	str r1, [r0]
	str r4, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	subs r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r3, [r0]
	ldr r4, _080F48A4 @ =FUN_080e6794
	movs r1, #0xe
	subs r6, #0xe4
	adds r0, r5, r6
	strb r3, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r4, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _080F48A8 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	subs r1, #2
	adds r0, r5, r1
	strh r3, [r0]
_080F4896:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F489C: .4byte FUN_080f3cdc
_080F48A0: .4byte 0x00000554
_080F48A4: .4byte FUN_080e6794
_080F48A8: .4byte 0x00000469
