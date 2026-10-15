	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A16FC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1700 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080A170C
	ldr r0, _080A1704 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	movs r3, #0x28
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r3, #0x7f
	bgt _080A170C
	cmp r1, #0x7f
	bgt _080A170C
	adds r0, r3, #0
	muls r0, r3, r0
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	ldr r1, _080A1708 @ =0x00003FFF
	cmp r0, r1
	bgt _080A170C
	movs r0, #1
	b _080A170E
	.align 2, 0
_080A16FC: .4byte 0x030046A0
_080A1700: .4byte 0x00000942
_080A1704: .4byte 0x03002BE0
_080A1708: .4byte 0x00003FFF
_080A170C:
	movs r0, #0
_080A170E:
	pop {r4}
	pop {r1}
	bx r1
