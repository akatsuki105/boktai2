	push {lr}
	adds r1, r0, #0
	ldr r0, _080F1E04 @ =0x0000046C
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080F1DF6
	movs r0, #0
	strb r0, [r2]
_080F1DF6:
	ldr r0, _080F1E08 @ =0x00000484
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080F1E04: .4byte 0x0000046C
_080F1E08: .4byte 0x00000484
