	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _08164590 @ =0x00000553
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x25
	beq _08164588
	cmp r0, #0x21
	beq _08164588
	cmp r0, #0x22
	beq _08164588
	cmp r0, #0x23
	beq _08164588
	ldr r3, _08164594 @ =FUN_08162e74
	movs r1, #0x25
	ldr r2, _08164598 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0816459C @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xf
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081645A0 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
_08164588:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08164590: .4byte 0x00000553
_08164594: .4byte FUN_08162e74
_08164598: .4byte 0x0000046D
_0816459C: .4byte 0x0000046B
_081645A0: .4byte 0x0000046A
