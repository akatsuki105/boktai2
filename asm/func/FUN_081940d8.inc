	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r3, _081940F8 @ =0x0000046C
	adds r1, r5, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _081940FC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081940FE
	.align 2, 0
_081940F8: .4byte 0x0000046C
_081940FC:
	movs r0, #0
_081940FE:
	cmp r0, #0
	beq _0819414C
	movs r0, #0x20
	ldr r7, _081941A8 @ =0x00000474
	adds r2, r5, r7
	ldrh r1, [r2]
	movs r3, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #1
	subs r7, #7
	adds r0, r5, r7
	strb r1, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r3, [r0]
	ldr r3, _081941AC @ =0x00000553
	adds r0, r5, r3
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	ldr r3, _081941B0 @ =0x00000F2C
	adds r2, r6, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0819414C:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xa
	bl FUN_08191774
	movs r4, #0
	movs r0, #0xf8
	lsls r0, r0, #8
	strh r0, [r5, #0xa]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0xc
	bl FUN_0818fdd8
	ldr r7, _081941B4 @ =0x00000484
	adds r2, r5, r7
	ldr r0, [r2]
	cmp r0, #0xa0
	ble _0819419C
	movs r1, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	subs r7, #0x1b
	adds r0, r5, r7
	strb r4, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r7, #0x1b
	adds r1, r5, r7
	movs r0, #0
	str r0, [r1]
	ldr r0, _081941B8 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0819419C:
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081941A8: .4byte 0x00000474
_081941AC: .4byte 0x00000553
_081941B0: .4byte 0x00000F2C
_081941B4: .4byte 0x00000484
_081941B8: .4byte 0x0000046C
