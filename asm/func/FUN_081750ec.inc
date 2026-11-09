	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r2, _0817510C @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08175110
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08175112
	.align 2, 0
_0817510C: .4byte 0x0000046C
_08175110:
	movs r0, #0
_08175112:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r5, r4, r3
	cmp r0, #0
	beq _08175172
	movs r7, #0xb4
	lsls r7, r7, #3
	adds r0, r4, r7
	ldr r2, [r0]
	movs r1, #1
	ldr r3, _081751B8 @ =0x0000046D
	adds r0, r4, r3
	movs r3, #0
	strb r1, [r0]
	ldr r7, _081751BC @ =0x0000046B
	adds r0, r4, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r3, [r0]
	ldr r7, _081751C0 @ =0x00001008
	adds r2, r6, r7
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, _081751C4 @ =0x0000FFC0
	strh r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r3, [r0]
	ldr r1, _081751C8 @ =0xFFEFFFFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
_08175172:
	ldr r3, _081751CC @ =0x0000FFFF
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	adds r0, r6, #0
	bl FUN_08176c60
	movs r1, #0x10
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08175218
	adds r0, r4, #0
	adds r0, #8
	movs r1, #3
	bl FUN_08176530
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r3, _081751C0 @ =0x00001008
	adds r1, r6, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081751D0
	movs r0, #1
	b _081751D2
	.align 2, 0
_081751B8: .4byte 0x0000046D
_081751BC: .4byte 0x0000046B
_081751C0: .4byte 0x00001008
_081751C4: .4byte 0x0000FFC0
_081751C8: .4byte 0xFFEFFFFF
_081751CC: .4byte 0x0000FFFF
_081751D0:
	movs r0, #0
_081751D2:
	cmp r0, #0
	beq _081751EC
	movs r0, #0xf7
	lsls r0, r0, #2
	bl PlaySound_082406e0
	ldr r0, _081751E8 @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	b _081751F2
	.align 2, 0
_081751E8: .4byte 0xFFFFFEFF
_081751EC:
	ldr r0, _08175228 @ =0x00000145
	bl PlaySound_082406e0
_081751F2:
	movs r2, #0xd
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r4, r7
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0817522C @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r2, [r0]
	ldr r2, _08175230 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_08175218:
	ldr r7, _08175230 @ =0x00000484
	adds r1, r4, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08175228: .4byte 0x00000145
_0817522C: .4byte 0x00000469
_08175230: .4byte 0x00000484
