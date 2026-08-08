	push {r4, r5, lr}
	ldr r5, _08241354 @ =gUnkPtr_030047a8
	ldr r0, [r5]
	ldrb r1, [r0, #8]
	movs r0, #1
	subs r4, r0, r1
	adds r0, r4, #0
	bl FUN_082411ac
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241358
	adds r0, r4, #0
	bl FUN_08241260
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241358
	ldr r0, [r5]
	strb r4, [r0, #8]
	movs r0, #1
	b _0824135A
	.align 2, 0
_08241354: .4byte gUnkPtr_030047a8
_08241358:
	movs r0, #0
_0824135A:
	pop {r4, r5}
	pop {r1}
	bx r1
