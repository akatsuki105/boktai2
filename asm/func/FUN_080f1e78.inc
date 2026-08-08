	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080F1E90 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F1E94
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F1E96
	.align 2, 0
_080F1E90: .4byte 0x0000046C
_080F1E94:
	movs r0, #0
_080F1E96:
	cmp r0, #0
	beq _080F1ED4
	ldr r1, _080F1EC8 @ =0x000005A4
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _080F1ECC @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080F1ED0 @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	b _080F1EEE
	.align 2, 0
_080F1EC8: .4byte 0x000005A4
_080F1ECC: .4byte 0x0000046D
_080F1ED0: .4byte 0x0000046B
_080F1ED4:
	ldr r0, _080F1EF4 @ =0x00000484
	adds r5, r4, r0
	ldr r0, [r5]
	cmp r0, #0
	bne _080F1EE8
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #1
	bl FUN_08022488
_080F1EE8:
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
_080F1EEE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F1EF4: .4byte 0x00000484
