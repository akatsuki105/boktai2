	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r6, [sp, #0x10]
	ldr r0, _081DFA50 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DFA8E
	ldr r1, _081DFA54 @ =0x085AE3FA
	ldrb r0, [r1]
	str r0, [r5]
	ldrb r0, [r1, #1]
	str r0, [r2]
	ldrb r0, [r1, #2]
	str r0, [r3]
	ldrb r0, [r1, #3]
	str r0, [r6]
	cmp r4, #1
	beq _081DFA7C
	cmp r4, #1
	bgt _081DFA58
	cmp r4, #0
	beq _081DFA70
	b _081DFA8E
	.align 2, 0
_081DFA50: .4byte 0x03002C68
_081DFA54: .4byte 0x085AE3FA
_081DFA58:
	cmp r4, #2
	beq _081DFA62
	cmp r4, #3
	beq _081DFA88
	b _081DFA8E
_081DFA62:
	ldr r0, _081DFA6C @ =0x085AE3FE
	ldrb r0, [r0]
	str r0, [r5]
	b _081DFA8E
	.align 2, 0
_081DFA6C: .4byte 0x085AE3FE
_081DFA70:
	ldr r0, _081DFA78 @ =0x085AE3FE
	ldrb r0, [r0, #1]
	str r0, [r2]
	b _081DFA8E
	.align 2, 0
_081DFA78: .4byte 0x085AE3FE
_081DFA7C:
	ldr r0, _081DFA84 @ =0x085AE3FE
	ldrb r0, [r0, #2]
	str r0, [r3]
	b _081DFA8E
	.align 2, 0
_081DFA84: .4byte 0x085AE3FE
_081DFA88:
	ldr r0, _081DFA94 @ =0x085AE3FE
	ldrb r0, [r0, #3]
	str r0, [r6]
_081DFA8E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DFA94: .4byte 0x085AE3FE
