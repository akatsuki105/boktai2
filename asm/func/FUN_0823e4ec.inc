	push {r4, r5, r6, lr}
	sub sp, #0xc
	movs r5, #0
	movs r4, #0
	movs r6, #1
	rsbs r6, r6, #0
	b _0823E502
_0823E4FA:
	movs r0, #0xc8
	bl Delay
	adds r4, #1
_0823E502:
	cmp r4, #4
	bgt _0823E510
	bl FUN_0823e828
	adds r5, r0, #0
	cmp r5, r6
	beq _0823E4FA
_0823E510:
	cmp r5, #1
	bne _0823E54C
	bl FUN_0823e768
	cmp r0, #1
	bne _0823E528
	ldr r1, _0823E524 @ =gClock
	movs r0, #0
	strb r0, [r1, #9]
	b _0823E566
	.align 2, 0
_0823E524: .4byte gClock
_0823E528:
	ldr r0, _0823E544 @ =0x000007D4
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #7
	movs r2, #0x16
	movs r3, #0xc
	bl SetGameDateTime
	ldr r0, _0823E548 @ =gClock
	strb r5, [r0, #9]
	b _0823E566
	.align 2, 0
_0823E544: .4byte 0x000007D4
_0823E548: .4byte gClock
_0823E54C:
	ldr r0, _0823E570 @ =0x000007D4
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r4, #1
	str r4, [sp, #8]
	movs r1, #7
	movs r2, #0x16
	movs r3, #0xc
	bl SetGameDateTime
	ldr r0, _0823E574 @ =gClock
	strb r4, [r0, #9]
_0823E566:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0823E570: .4byte 0x000007D4
_0823E574: .4byte gClock
