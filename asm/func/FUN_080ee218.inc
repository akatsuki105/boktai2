	push {r4, r5, lr}
	ldr r0, _080EE224 @ =0x03002C60
	ldr r5, [r0]
	cmp r5, #0
	beq _080EE24C
	b _080EE246
	.align 2, 0
_080EE224: .4byte 0x03002C60
_080EE228:
	ldr r5, [r5]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r4, [r0]
	movs r2, #0xc4
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl Free
_080EE246:
	ldr r1, [r5, #4]
	cmp r1, #0
	bne _080EE228
_080EE24C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
