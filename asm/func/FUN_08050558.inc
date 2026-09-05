	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805056A
	movs r0, #0
	strb r0, [r5]
_0805056A:
	ldr r0, [r4, #0x24]
	cmp r0, #0x77
	bls _0805058C
	bl FUN_0804e5e8
	movs r1, #9
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	movs r0, #1
	strb r0, [r5]
	str r2, [r4, #0x24]
	adds r0, r4, #0
	bl FUN_0804fbe0
	b _08050590
_0805058C:
	adds r0, #1
	str r0, [r4, #0x24]
_08050590:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
