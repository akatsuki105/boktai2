	push {r4, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0821D5F4
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0821D5F6
_0821D5F4:
	movs r0, #0
_0821D5F6:
	cmp r0, #0
	beq _0821D624
	ldr r1, _0821D62C @ =0x00000804
	adds r0, r2, r1
	ldrb r0, [r0]
	adds r0, #5
	lsls r0, r0, #0x1d
	lsrs r0, r0, #0x18
	movs r3, #0xed
	lsls r3, r3, #2
	adds r1, r2, r3
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0x10
	movs r2, #1
	bl FUN_08221268
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0821D624:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0821D62C: .4byte 0x00000804
