	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080F9F18 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F9EF2
	movs r0, #0
	strb r0, [r1]
_080F9EF2:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F9F10
	ldr r0, _080F9F1C @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F9F10:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F9F18: .4byte 0x0000046C
_080F9F1C: .4byte 0x00000484
