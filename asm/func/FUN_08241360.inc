	push {r4, r5, lr}
	ldr r5, _08241394 @ =gUnkPtr_030047a8
	ldr r0, [r5]
	ldrb r1, [r0, #8]
	movs r0, #1
	subs r4, r0, r1
	adds r0, r4, #0
	bl FUN_08241118
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241398
	adds r0, r4, #0
	bl FUN_08241224
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241398
	ldr r0, [r5]
	strb r4, [r0, #8]
	bl FUN_082410bc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0824139A
	.align 2, 0
_08241394: .4byte gUnkPtr_030047a8
_08241398:
	movs r0, #0
_0824139A:
	pop {r4, r5}
	pop {r1}
	bx r1
