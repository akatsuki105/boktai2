	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _080F5500 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F5504
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F5506
	.align 2, 0
_080F5500: .4byte 0x0000046D
_080F5504:
	movs r0, #0
_080F5506:
	cmp r0, #0
	beq _080F55EA
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _080F5574 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _080F5578 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r5, _080F557C @ =0x00000202
	adds r0, r6, r5
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #3
	bl FUN_080ef86c
	ldr r7, _080F5580 @ =0x000001DF
	adds r1, r6, r7
	ldrb r0, [r1]
	cmp r0, #2
	beq _080F5550
	cmp r0, #0x16
	beq _080F5550
	adds r3, r0, #0
	adds r0, r6, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
_080F5550:
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080F5584 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F5588
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F5596
	.align 2, 0
_080F5574: .4byte 0xFFFEBE3F
_080F5578: .4byte 0x0000021E
_080F557C: .4byte 0x00000202
_080F5580: .4byte 0x000001DF
_080F5584: .4byte 0x0000025D
_080F5588:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080F5596:
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080F5614 @ =0x00000469
	adds r0, r6, r3
	strb r2, [r0]
	ldr r5, _080F5618 @ =0x0000046A
	adds r0, r6, r5
	strb r2, [r0]
	ldr r7, _080F561C @ =0x00000484
	adds r0, r6, r7
	str r2, [r0]
	ldr r0, _080F5620 @ =0x0000046C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r2, [r0]
	adds r3, #5
	adds r0, r6, r3
	strb r1, [r0]
	movs r5, #0x8e
	lsls r5, r5, #1
	adds r0, r6, r5
	strh r2, [r0]
	adds r7, #0x3a
	adds r0, r6, r7
	strh r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xa
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080F55EA:
	cmp r4, #6
	ble _080F56E2
	subs r0, r4, #6
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	ldrh r0, [r6, #0xa]
	subs r0, r0, r1
	strh r0, [r6, #0xa]
	ldr r1, _080F5624 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _080F5628
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _080F5632
	.align 2, 0
_080F5614: .4byte 0x00000469
_080F5618: .4byte 0x0000046A
_080F561C: .4byte 0x00000484
_080F5620: .4byte 0x0000046C
_080F5624: .4byte 0x0000025D
_080F5628:
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_080F5632:
	cmp r4, #8
	ble _080F56E2
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r5, #0
	movs r4, #0
	strh r4, [r0]
	movs r0, #8
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r1, r6, r7
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #4
	bl FUN_080e64b4
	ldr r2, _080F56C8 @ =FUN_080f5208
	movs r1, #0x17
	ldr r3, _080F56CC @ =0x0000046D
	adds r0, r6, r3
	movs r3, #1
	strb r3, [r0]
	ldr r7, _080F56D0 @ =0x0000046B
	adds r0, r6, r7
	strb r5, [r0]
	ldr r5, _080F56D4 @ =0x00000553
	adds r0, r6, r5
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080F56D8
	ldr r1, [r6, #0x44]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	b _080F56E2
	.align 2, 0
_080F56C8: .4byte FUN_080f5208
_080F56CC: .4byte 0x0000046D
_080F56D0: .4byte 0x0000046B
_080F56D4: .4byte 0x00000553
_080F56D8:
	ldr r1, [r6, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r3
	str r0, [r1, #8]
_080F56E2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
