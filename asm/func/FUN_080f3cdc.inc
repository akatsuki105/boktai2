	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080F3CF4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F3CF8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F3CFA
	.align 2, 0
_080F3CF4: .4byte 0x0000046D
_080F3CF8:
	movs r0, #0
_080F3CFA:
	cmp r0, #0
	beq _080F3D06
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080ef86c
_080F3D06:
	ldr r1, _080F3D20 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080F3D18
	ldr r0, _080F3D24 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080F3D18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F3D20: .4byte 0x0000046E
_080F3D24: .4byte 0x0000046B
