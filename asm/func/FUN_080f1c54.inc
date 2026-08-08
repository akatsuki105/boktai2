	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _080F1CB0 @ =0x0000046C
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F1C66
	movs r0, #0
	strb r0, [r1]
_080F1C66:
	movs r1, #0x20
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _080F1C9E
	movs r1, #0xa
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r3, r4
	strb r2, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r2, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, _080F1CB4 @ =0x00000484
	adds r0, r3, r1
	str r2, [r0]
	ldr r2, _080F1CB0 @ =0x0000046C
	adds r1, r3, r2
	movs r0, #1
	strb r0, [r1]
_080F1C9E:
	ldr r4, _080F1CB4 @ =0x00000484
	adds r1, r3, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F1CB0: .4byte 0x0000046C
_080F1CB4: .4byte 0x00000484
