	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080F2178 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F217C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F217E
	.align 2, 0
_080F2178: .4byte 0x0000046C
_080F217C:
	movs r0, #0
_080F217E:
	adds r4, r0, #0
	cmp r4, #0
	beq _080F21C0
	movs r1, #0xba
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #0x11
	ldr r6, _080F21B8 @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080F21BC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	b _080F224A
	.align 2, 0
_080F21B8: .4byte 0x0000046D
_080F21BC: .4byte 0x0000046B
_080F21C0:
	ldr r6, _080F2230 @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080F2240
	adds r0, r5, #0
	adds r0, #0x48
	movs r1, #1
	bl FUN_08022488
	ldr r2, _080F2234 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _080F2238 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _080F223C @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r4, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080F224A
	.align 2, 0
_080F2230: .4byte 0x0000046B
_080F2234: .4byte FUN_080e48d0
_080F2238: .4byte 0x0000046D
_080F223C: .4byte 0x00000469
_080F2240:
	ldr r3, _080F2250 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F224A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F2250: .4byte 0x00000484
