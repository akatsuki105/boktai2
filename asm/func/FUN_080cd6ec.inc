	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r1, #2
	ldr r0, _080CD708 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _080CD70C @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CD710
	movs r0, #1
	b _080CD712
	.align 2, 0
_080CD708: .4byte 0x030046A0
_080CD70C: .4byte 0x00000934
_080CD710:
	movs r0, #0
_080CD712:
	cmp r0, #0
	bne _080CD724
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CD730
	movs r3, #4
	b _080CD730
_080CD724:
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CD730
	movs r3, #8
_080CD730:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
