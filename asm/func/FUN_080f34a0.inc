	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080F34E4 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F34B2
	movs r0, #0
	strb r0, [r1]
_080F34B2:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F34DC
	adds r0, r4, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F34DC
	ldr r0, _080F34E8 @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F34DC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F34E4: .4byte 0x0000046C
_080F34E8: .4byte 0x00000484
