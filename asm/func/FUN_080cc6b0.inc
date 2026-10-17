	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0xca
	lsls r0, r0, #3
	adds r5, r4, r0
	cmp r2, #0
	beq _080CC6CC
	ldr r2, _080CC6C8 @ =0x0000067A
	adds r1, r4, r2
	movs r0, #0x48
	b _080CC6D2
	.align 2, 0
_080CC6C8: .4byte 0x0000067A
_080CC6CC:
	ldr r0, _080CC710 @ =0x0000067A
	adds r1, r4, r0
	movs r0, #4
_080CC6D2:
	strb r0, [r1]
	ldr r1, _080CC714 @ =0x0000064C
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _080CC710 @ =0x0000067A
	adds r0, r4, r2
	ldrb r2, [r0]
	adds r0, r5, #0
	bl Particle_SetFrame
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080CC718 @ =0x00000679
	adds r0, r4, r1
	strb r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC710: .4byte 0x0000067A
_080CC714: .4byte 0x0000064C
_080CC718: .4byte 0x00000679
