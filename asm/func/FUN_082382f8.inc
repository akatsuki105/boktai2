	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #1
	beq _0823830E
	cmp r0, #2
	beq _0823832A
	adds r0, r4, #0
	movs r1, #3
	b _08238348
_0823830E:
	adds r0, r4, #0
	adds r0, #0x80
	adds r1, r5, #0
	bl FUN_08238178
	ldrb r1, [r5, #8]
	adds r0, r4, #0
	bl FUN_0823829c
	cmp r0, #0
	bge _0823834C
	adds r0, r4, #0
	movs r1, #1
	b _08238348
_0823832A:
	adds r0, r4, #0
	adds r0, #0x40
	ldrb r1, [r5, #0xe]
	bl FUN_082381c8
	adds r1, r0, #0
	cmp r1, #0
	beq _08238344
	adds r0, r4, #0
	adds r0, #0xc0
	bl FUN_08238178
	b _0823834C
_08238344:
	adds r0, r4, #0
	movs r1, #0
_08238348:
	bl FUN_082382ec
_0823834C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
