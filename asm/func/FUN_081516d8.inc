	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081516F0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081516F4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081516F6
	.align 2, 0
_081516F0: .4byte 0x0000046C
_081516F4:
	movs r0, #0
_081516F6:
	cmp r0, #0
	beq _0815172A
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _08151788 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815178C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0815172A:
	adds r0, r5, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08151756
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815179E
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815179E
_08151756:
	ldr r3, _0815178C @ =0x0000046B
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08151794
	movs r2, #0x11
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08151790 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _0815179E
	.align 2, 0
_08151788: .4byte 0x0000046D
_0815178C: .4byte 0x0000046B
_08151790: .4byte 0x00000484
_08151794:
	ldr r0, _081517A4 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0815179E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081517A4: .4byte 0x00000484
