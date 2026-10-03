	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _080B9DC4 @ =0x030044E0
	ldrh r0, [r4, #2]
	movs r1, #0xf0
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #0
	beq _080B9DC8
	movs r0, #0
	strb r0, [r3, #8]
	ldrh r0, [r4, #2]
	b _080B9DE8
	.align 2, 0
_080B9DC4: .4byte 0x030044E0
_080B9DC8:
	ldrh r0, [r4]
	ands r1, r0
	cmp r1, #0
	beq _080B9DE4
	ldrb r0, [r3, #8]
	adds r0, #1
	strb r0, [r3, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _080B9DE6
	strb r2, [r3, #8]
	ldrh r0, [r4]
	b _080B9DE8
_080B9DE4:
	strb r1, [r3, #8]
_080B9DE6:
	movs r0, #0
_080B9DE8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
