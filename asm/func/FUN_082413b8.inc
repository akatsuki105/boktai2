	push {r4, r5, lr}
	ldr r0, _082413F4 @ =gUnkPtr_030047a8
	ldr r0, [r0]
	ldrb r4, [r0, #8]
	movs r0, #1
	subs r5, r0, r4
	bl FUN_082410a0
	adds r0, r4, #0
	bl FUN_082411ac
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _082413F8
	bl FUN_08231cec
	adds r0, r5, #0
	bl FUN_08241118
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _082413F8
	adds r0, r5, #0
	bl FUN_08241224
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _082413F8
	movs r0, #1
	b _082413FA
	.align 2, 0
_082413F4: .4byte gUnkPtr_030047a8
_082413F8:
	movs r0, #0
_082413FA:
	pop {r4, r5}
	pop {r1}
	bx r1
