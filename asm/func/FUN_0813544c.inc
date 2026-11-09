	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08135464 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08135468
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813546A
	.align 2, 0
_08135464: .4byte 0x0000046C
_08135468:
	movs r0, #0
_0813546A:
	cmp r0, #0
	beq _08135510
	ldr r1, _081354C0 @ =0x000005A4
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _081354C4 @ =0x0000046D
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081354C8 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _081354CC @ =0x00000553
	adds r0, r5, r1
	strb r2, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r4, [r5, #5]
	ldr r2, _081354D0 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _081354D4
	asrs r1, r0, #0xc
	b _081354DA
	.align 2, 0
_081354C0: .4byte 0x000005A4
_081354C4: .4byte 0x0000046D
_081354C8: .4byte 0x0000046B
_081354CC: .4byte 0x00000553
_081354D0: .4byte gSineTable
_081354D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081354DA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _081354F4
	asrs r2, r0, #0xc
	b _081354FA
_081354F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081354FA:
	movs r0, #0
	strh r2, [r3, #4]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r5, r4
	strh r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #2
	strh r0, [r1]
_08135510:
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r5, #0
	movs r1, #6
	bl FUN_081370f4
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08135598
	adds r0, r5, #0
	bl FUN_081355f0
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08135588 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0813558C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08135590 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _08135594 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _081355A2
	.align 2, 0
_08135588: .4byte 0x0000046D
_0813558C: .4byte 0x0000046B
_08135590: .4byte 0x0000046A
_08135594: .4byte 0x00000484
_08135598:
	ldr r0, _081355A8 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081355A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081355A8: .4byte 0x00000484
