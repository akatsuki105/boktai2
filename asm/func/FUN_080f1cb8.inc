	push {lr}
	adds r2, r0, #0
	ldr r0, _080F1CE8 @ =0x0000046C
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F1CCA
	movs r0, #0
	strb r0, [r1]
_080F1CCA:
	movs r1, #2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F1CE4
	ldr r0, _080F1CEC @ =0x00000484
	adds r1, r2, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F1CE4:
	pop {r0}
	bx r0
	.align 2, 0
_080F1CE8: .4byte 0x0000046C
_080F1CEC: .4byte 0x00000484
