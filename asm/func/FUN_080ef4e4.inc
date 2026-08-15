	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _080EF52C
	bl FUN_080edda0
	adds r4, r0, #0
	cmp r4, #0
	beq _080EF52C
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _080EF51C
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _080EF518 @ =0xFBFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080EF52C
	.align 2, 0
_080EF518: .4byte 0xFBFFFFFF
_080EF51C:
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080EF52C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
