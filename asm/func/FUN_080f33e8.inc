	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080F3400 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F3404
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F3406
	.align 2, 0
_080F3400: .4byte 0x0000046C
_080F3404:
	movs r0, #0
_080F3406:
	cmp r0, #0
	beq _080F3434
	ldr r1, _080F3484 @ =0x000005A4
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _080F3488 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080F348C @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
_080F3434:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F3498
	adds r0, r4, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080F3498
	ldr r3, _080F3490 @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	cmp r0, #0x3b
	ble _080F3494
	movs r1, #2
	subs r3, #0x1c
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _080F3490 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _080F3498
	.align 2, 0
_080F3484: .4byte 0x000005A4
_080F3488: .4byte 0x0000046D
_080F348C: .4byte 0x0000046B
_080F3490: .4byte 0x00000484
_080F3494:
	adds r0, #1
	str r0, [r1]
_080F3498:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
