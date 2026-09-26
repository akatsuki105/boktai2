	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _080DDAA0
	movs r5, #0
	ldr r6, _080DDA74 @ =0x085AD348
_080DDA62:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r4, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _080DDA78
	movs r0, #1
	b _080DDA7A
	.align 2, 0
_080DDA74: .4byte 0x085AD348
_080DDA78:
	movs r0, #0
_080DDA7A:
	cmp r0, #0
	beq _080DDA9A
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, #0x1c
	adds r1, r4, r1
	adds r0, r1, #0
	adds r0, #0x5d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
_080DDA9A:
	adds r5, #1
	cmp r5, #4
	ble _080DDA62
_080DDAA0:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
