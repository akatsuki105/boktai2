	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	adds r5, r6, #0
	ldr r2, _0811F9B0 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811F9B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811F9B6
	.align 2, 0
_0811F9B0: .4byte 0x0000046C
_0811F9B4:
	movs r0, #0
_0811F9B6:
	cmp r0, #0
	beq _0811FA00
	ldr r4, _0811FA88 @ =Golem_StateDash
	movs r3, #0x28
	ldr r0, _0811FA8C @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0811FA90 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r1, #0
	strh r2, [r0]
	ldr r2, _0811FA90 @ =0x0000046B
	adds r0, r6, r2
	strb r1, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r5, #5]
	ldr r4, _0811FA94 @ =0x000006B6
	adds r1, r7, r4
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
_0811FA00:
	ldr r0, _0811FA98 @ =0x00000484
	adds r2, r6, r0
	ldr r1, [r2]
	cmp r1, #0x1e
	bgt _0811FA14
	ldr r3, _0811FA90 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0811FAAC
_0811FA14:
	movs r4, #0xcd
	lsls r4, r4, #3
	adds r2, r7, r4
	ldrh r0, [r2]
	cmp r0, #0
	beq _0811FA36
	movs r7, #0xea
	lsls r7, r7, #1
	adds r1, r6, r7
	str r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_0811FA36:
	ldr r2, _0811FA9C @ =Golem_StateUncurl
	movs r1, #0x26
	ldr r3, _0811FA8C @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _0811FA90 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _0811FAA0 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0811FAA4 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0811FAA8 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _0811FA98 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _0811FAB0
	.align 2, 0
_0811FA88: .4byte Golem_StateDash
_0811FA8C: .4byte 0x0000046D
_0811FA90: .4byte 0x0000046B
_0811FA94: .4byte 0x000006B6
_0811FA98: .4byte 0x00000484
_0811FA9C: .4byte Golem_StateUncurl
_0811FAA0: .4byte 0x00000553
_0811FAA4: .4byte 0x00000469
_0811FAA8: .4byte 0x0000046A
_0811FAAC:
	adds r0, r1, #1
	str r0, [r2]
_0811FAB0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
