	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080F1E24 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F1E28
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F1E2A
	.align 2, 0
_080F1E24: .4byte 0x0000046C
_080F1E28:
	movs r0, #0
_080F1E2A:
	cmp r0, #0
	beq _080F1E56
	ldr r4, _080F1E68 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r0, _080F1E6C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080F1E70 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_080F1E56:
	ldr r0, _080F1E74 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F1E68: .4byte FUN_080e48d0
_080F1E6C: .4byte 0x0000046D
_080F1E70: .4byte 0x0000046B
_080F1E74: .4byte 0x00000484
