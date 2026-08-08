	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0821D140
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0821D142
_0821D140:
	movs r0, #0
_0821D142:
	cmp r0, #0
	beq _0821D150
	adds r0, r4, #0
	movs r1, #5
	movs r2, #1
	bl FUN_08221268
_0821D150:
	movs r1, #0x10
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0821D17E
	ldr r1, _0821D188 @ =0x0000080C
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
_0821D17E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0821D188: .4byte 0x0000080C
