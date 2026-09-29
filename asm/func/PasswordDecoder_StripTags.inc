	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	movs r6, #0
	movs r2, #0
	b _08011576
_0801152C:
	lsls r3, r0, #0x18
	cmp r3, #0
	blt _08011556
	lsrs r3, r3, #0x18
	cmp r3, #0x3c
	bne _0801153C
	movs r6, #1
	b _08011552
_0801153C:
	cmp r3, #0x3e
	bne _08011544
	movs r6, #0
	b _08011552
_08011544:
	cmp r6, #0
	bne _08011552
	strb r0, [r4]
	adds r4, #1
	adds r2, #1
	cmp r2, r5
	bge _0801157C
_08011552:
	adds r1, #1
	b _08011576
_08011556:
	movs r6, #0
	strb r0, [r4]
	adds r1, #1
	adds r4, #1
	adds r2, #1
	cmp r2, r5
	bge _0801157C
	ldrb r3, [r1]
	cmp r3, #0
	beq _0801157C
	strb r3, [r4]
	adds r1, #1
	adds r4, #1
	adds r2, #1
	cmp r2, r5
	bge _0801157C
_08011576:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801152C
_0801157C:
	adds r0, r2, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
