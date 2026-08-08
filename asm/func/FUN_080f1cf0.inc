	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080F1D08 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F1D0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F1D0E
	.align 2, 0
_080F1D08: .4byte 0x0000046C
_080F1D0C:
	movs r0, #0
_080F1D0E:
	ldr r1, _080F1D24 @ =0x0000025D
	adds r3, r5, r1
	cmp r0, #0
	beq _080F1D32
	ldrb r0, [r3]
	cmp r0, #0
	bne _080F1D28
	ldr r0, [r5, #0x44]
	adds r1, r0, #0
	adds r1, #0x1c
	b _080F1D2E
	.align 2, 0
_080F1D24: .4byte 0x0000025D
_080F1D28:
	ldr r0, [r5, #0x44]
	adds r1, r0, #0
	adds r1, #0x40
_080F1D2E:
	ldr r0, _080F1D50 @ =0x00007530
	strh r0, [r1, #2]
_080F1D32:
	movs r0, #0
	strh r0, [r5, #8]
	ldr r1, _080F1D50 @ =0x00007530
	strh r1, [r5, #0xa]
	strh r0, [r5, #0xc]
	movs r2, #1
	ldrb r0, [r3]
	cmp r0, #0
	bne _080F1D54
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080F1D5E
	.align 2, 0
_080F1D50: .4byte 0x00007530
_080F1D54:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_080F1D5E:
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r6, _080F1DD0 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _080F1DD4 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _080F1DD8 @ =FUN_080e48d0
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _080F1DDC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_080e49c4
	movs r0, #0x40
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _080F1DE0 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F1DD0: .4byte 0x00000469
_080F1DD4: .4byte 0x0000046A
_080F1DD8: .4byte FUN_080e48d0
_080F1DDC: .4byte 0x0000046B
_080F1DE0: .4byte 0x00000484
