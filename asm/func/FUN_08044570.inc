	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08044582
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #2
	strb r0, [r1, #5]
_08044582:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _0804459E
	movs r0, #0
	strb r0, [r1, #4]
	str r0, [r1, #0x14]
	movs r0, #1
	strb r0, [r1, #8]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl EntityMsgBox_EndWait
_0804459E:
	pop {r0}
	bx r0
	.align 2, 0
