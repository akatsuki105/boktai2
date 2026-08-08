	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080F2D1C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F2D20
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F2D22
	.align 2, 0
_080F2D1C: .4byte 0x0000046C
_080F2D20:
	movs r0, #0
_080F2D22:
	cmp r0, #0
	beq _080F2D56
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _080F2DF0 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _080F2DF4 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _080F2DF8 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_080F2D56:
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F2D6C
	b _080F2EB6
_080F2D6C:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080F2D7C
	b _080F2EB6
_080F2D7C:
	ldr r1, _080F2DF4 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F2D88
	b _080F2EAC
_080F2D88:
	movs r1, #0x10
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _080F2E04
	movs r1, #8
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r6, _080F2DFC @ =0x00000469
	adds r0, r5, r6
	strb r4, [r0]
	ldr r2, _080F2E00 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r2, #0x13
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _080F2DF4 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _080F2EB6
	.align 2, 0
_080F2DF0: .4byte 0x0000046D
_080F2DF4: .4byte 0x0000046B
_080F2DF8: .4byte 0x00000553
_080F2DFC: .4byte 0x00000469
_080F2E00: .4byte 0x0000046A
_080F2E04:
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _080F2E40
	movs r1, #7
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	ldr r2, _080F2E34 @ =0x00000469
	adds r0, r5, r2
	strb r3, [r0]
	ldr r4, _080F2E38 @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r3, [r0]
	ldr r0, _080F2E3C @ =0x0000046C
	adds r1, r5, r0
	b _080F2E60
	.align 2, 0
_080F2E34: .4byte 0x00000469
_080F2E38: .4byte 0x0000046A
_080F2E3C: .4byte 0x0000046C
_080F2E40:
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	ldr r4, _080F2E94 @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	ldr r6, _080F2E98 @ =0x0000046A
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _080F2E9C @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _080F2EA0 @ =0x0000046C
	adds r1, r5, r2
_080F2E60:
	movs r0, #1
	strb r0, [r1]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _080F2EA4 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	ldr r6, _080F2EA8 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	b _080F2EB6
	.align 2, 0
_080F2E94: .4byte 0x00000469
_080F2E98: .4byte 0x0000046A
_080F2E9C: .4byte 0x00000484
_080F2EA0: .4byte 0x0000046C
_080F2EA4: .4byte 0x0000046D
_080F2EA8: .4byte 0x0000046B
_080F2EAC:
	ldr r2, _080F2EBC @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F2EB6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F2EBC: .4byte 0x00000484
