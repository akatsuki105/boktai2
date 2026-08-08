	push {r4, r5, r6, lr}
	ldr r0, _080EE268 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080EE26C
	movs r0, #1
	b _080EE26E
	.align 2, 0
_080EE268: .4byte 0x030047A4
_080EE26C:
	movs r0, #0
_080EE26E:
	cmp r0, #0
	beq _080EE2BA
	ldr r0, _080EE2C0 @ =0x03002C60
	ldr r5, [r0]
	cmp r5, #0
	beq _080EE2BA
	ldr r4, [r5, #4]
	cmp r4, #0
	beq _080EE2BA
	movs r6, #1
_080EE282:
	ldr r5, [r5]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _080EE2B4
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	ands r0, r6
	cmp r0, #0
	beq _080EE2B4
	adds r0, r4, #0
	ldr r1, _080EE2C4 @ =0x085AD3CC
	bl FUN_080edb4c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EE2B4
	adds r0, r4, #0
	bl FUN_080ee738
_080EE2B4:
	ldr r4, [r5, #4]
	cmp r4, #0
	bne _080EE282
_080EE2BA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080EE2C0: .4byte 0x03002C60
_080EE2C4: .4byte 0x085AD3CC
