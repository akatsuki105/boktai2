	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _082081FE
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x11
	strb r0, [r1, #5]
_082081FE:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08208210
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl MsgQueue_EndWait
_08208210:
	pop {r0}
	bx r0
