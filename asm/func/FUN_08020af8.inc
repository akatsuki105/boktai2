	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xa9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	movs r0, #2
	subs r1, #3
	strb r0, [r1]
	ldr r0, _08020B20 @ =FUN_08020b88
	str r0, [r4, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020B20: .4byte FUN_08020b88
