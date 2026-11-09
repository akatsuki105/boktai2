	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r2, _0818227C @ =0x00000898
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08182280
	movs r0, #1
	b _08182282
	.align 2, 0
_0818227C: .4byte 0x00000898
_08182280:
	movs r0, #0
_08182282:
	cmp r0, #0
	beq _08182308
	adds r0, r5, #0
	bl FUN_0817e404
	ldr r3, _081822EC @ =0x00000898
	adds r2, r6, r3
	ldr r1, _081822F0 @ =0xFFFFCFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r6, _081822F4 @ =0x000005CC
	adds r0, r5, r6
	ldr r3, [r0]
	movs r1, #0x12
	ldr r7, _081822F8 @ =0x0000046D
	adds r0, r5, r7
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081822FC @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	subs r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r5, r7
	strb r3, [r0]
	ldr r1, _08182300 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _08182304 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #4
	adds r0, r5, r6
	strb r4, [r0]
	movs r0, #1
	b _08182408
	.align 2, 0
_081822EC: .4byte 0x00000898
_081822F0: .4byte 0xFFFFCFFF
_081822F4: .4byte 0x000005CC
_081822F8: .4byte 0x0000046D
_081822FC: .4byte 0x0000046B
_08182300: .4byte 0x0000046A
_08182304: .4byte 0x00000484
_08182308:
	movs r2, #0x80
	lsls r2, r2, #1
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r1, r5, r7
	ldrh r0, [r1]
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	bne _081823FC
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r2, _08182330 @ =0x00000898
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08182334
	movs r0, #1
	b _08182336
	.align 2, 0
_08182330: .4byte 0x00000898
_08182334:
	movs r0, #0
_08182336:
	cmp r0, #0
	bne _081823FC
	movs r7, #0xc9
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _081823FC
	ldr r2, _081823E0 @ =0x0000048C
	adds r0, r5, r2
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081823FC
	ldr r7, _081823E4 @ =0x0000089E
	adds r2, r6, r7
	ldrb r0, [r2]
	cmp r0, #0
	beq _08182370
	ldr r1, _081823E8 @ =0x0000089D
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08182374
_08182370:
	movs r0, #0xb4
	strb r0, [r2]
_08182374:
	ldr r2, _081823E8 @ =0x0000089D
	adds r2, r2, r6
	mov ip, r2
	ldrb r0, [r2]
	cmp r0, #1
	bls _081823FC
	ldr r3, _081823EC @ =0x000005CC
	adds r0, r5, r3
	ldr r2, [r0]
	movs r1, #0x12
	ldr r7, _081823F0 @ =0x0000046D
	adds r0, r5, r7
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	strh r3, [r0]
	movs r1, #3
	subs r7, #0xeb
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081823F4 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r3, _081823F8 @ =0x0000046C
	adds r0, r5, r3
	strb r4, [r0]
	ldr r7, _081823E4 @ =0x0000089E
	adds r0, r6, r7
	strb r2, [r0]
	mov r0, ip
	strb r2, [r0]
	movs r0, #1
	b _08182408
	.align 2, 0
_081823E0: .4byte 0x0000048C
_081823E4: .4byte 0x0000089E
_081823E8: .4byte 0x0000089D
_081823EC: .4byte 0x000005CC
_081823F0: .4byte 0x0000046D
_081823F4: .4byte 0x00000469
_081823F8: .4byte 0x0000046C
_081823FC:
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #0
_08182408:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
