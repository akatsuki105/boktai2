	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081517C0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081517C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081517C6
	.align 2, 0
_081517C0: .4byte 0x0000046C
_081517C4:
	movs r0, #0
_081517C6:
	cmp r0, #0
	beq _081517FA
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _08151880 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08151884 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08151888 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_081517FA:
	adds r0, r5, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08151826
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081518A2
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081518A2
_08151826:
	ldr r2, _08151884 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08151898
	movs r2, #3
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r3, #0
	strb r2, [r0]
	ldr r6, _0815188C @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _08151890 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _08151894 @ =FUN_0814e424
	movs r2, #0x2a
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08151884 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	b _081518A2
	.align 2, 0
_08151880: .4byte 0x0000046D
_08151884: .4byte 0x0000046B
_08151888: .4byte 0x00000553
_0815188C: .4byte 0x00000469
_08151890: .4byte 0x0000046A
_08151894: .4byte FUN_0814e424
_08151898:
	ldr r3, _081518A8 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081518A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081518A8: .4byte 0x00000484
