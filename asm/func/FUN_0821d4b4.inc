	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0821D4CC
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
_0821D4CC:
	movs r1, #0xea
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0821D4DE
	cmp r0, #1
	beq _0821D534
	b _0821D56A
_0821D4DE:
	movs r6, #4
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r5, r4, r2
	ldr r0, [r5]
	adds r2, r0, #0
	ands r2, r6
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	cmp r2, #0
	beq _0821D502
	adds r0, r4, #0
	movs r1, #0xd
	movs r2, #1
	bl FUN_08221268
_0821D502:
	movs r1, #0x10
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0821D56A
	adds r0, r4, #0
	movs r1, #5
	movs r2, #1
	bl FUN_08221268
	ldr r0, _0821D530 @ =0x00000804
	adds r1, r4, r0
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #1
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, [r5]
	orrs r0, r6
	str r0, [r5]
	b _0821D56A
	.align 2, 0
_0821D530: .4byte 0x00000804
_0821D534:
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0821D56A
	ldr r1, _0821D574 @ =0x0000080C
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	movs r2, #0x81
	lsls r2, r2, #4
	adds r0, r4, r2
	str r1, [r0]
	movs r0, #0x1f
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0821d870
_0821D56A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0821D574: .4byte 0x0000080C
