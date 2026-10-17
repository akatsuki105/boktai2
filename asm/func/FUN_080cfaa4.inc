	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CFAF6
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080cfa60
	cmp r0, #0
	beq _080CFAF6
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _080CFADA
	cmp r0, #5
	bne _080CFAEE
_080CFADA:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _080CFAEE
	adds r0, r4, #0
	bl FUN_080cf958
	b _080CFB08
_080CFAEE:
	adds r0, r4, #0
	bl FUN_080cf7f8
	b _080CFB08
_080CFAF6:
	ldr r1, _080CFB18 @ =0x000003CE
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080CFB08
	adds r0, r4, #0
	bl FUN_080cfa24
_080CFB08:
	ldr r0, _080CFB1C @ =0x000003D1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CFB18: .4byte 0x000003CE
_080CFB1C: .4byte 0x000003D1
