	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _08146988 @ =0x0000046C
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814698C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814698E
	.align 2, 0
_08146988: .4byte 0x0000046C
_0814698C:
	movs r0, #0
_0814698E:
	cmp r0, #0
	beq _081469DC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	str r5, [r0]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	movs r3, #1
	movs r7, #0xd2
	lsls r7, r7, #3
	adds r1, r1, r7
	ldrh r2, [r1]
	movs r4, #0
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	ldr r2, _08146A10 @ =FUN_08147530
	movs r1, #0x24
	ldr r7, _08146A14 @ =0x0000046D
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _08146A18 @ =0x0000046B
	adds r0, r6, r3
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
_081469DC:
	ldr r3, _08146A18 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08146A20
	movs r2, #2
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	movs r1, #0
	strb r1, [r0]
	subs r3, #2
	adds r0, r6, r3
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _08146A1C @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _08146A2E
	.align 2, 0
_08146A10: .4byte FUN_08147530
_08146A14: .4byte 0x0000046D
_08146A18: .4byte 0x0000046B
_08146A1C: .4byte 0x00000484
_08146A20:
	movs r7, #0xc1
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_08146A2E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
