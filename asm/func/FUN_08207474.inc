	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08207488
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0xf
	strb r0, [r2, #5]
_08207488:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _082074A4
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #4]
	str r0, [r2, #0x14]
	strb r1, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl MsgQueue_EndWait
_082074A4:
	pop {r0}
	bx r0
