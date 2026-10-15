	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08059D6E
	movs r0, #0
	strb r0, [r4, #1]
_08059D6E:
	ldrh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	cmp r0, r1
	blo _08059D86
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #2]
	strb r0, [r4, #1]
	strh r1, [r4, #8]
	ldr r0, _08059D94 @ =0x0000016D
	bl PlaySound_082406e0
_08059D86:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08059D94: .4byte 0x0000016D
