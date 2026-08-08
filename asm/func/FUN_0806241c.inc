	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r1, #2
	ldr r0, _08062438 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0806243C @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08062440
	movs r0, #1
	b _08062442
	.align 2, 0
_08062438: .4byte 0x030046A0
_0806243C: .4byte 0x00000934
_08062440:
	movs r0, #0
_08062442:
	cmp r0, #0
	bne _08062454
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08062460
	movs r3, #8
	b _08062460
_08062454:
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08062460
	movs r3, #4
_08062460:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
