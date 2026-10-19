	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _0820750C
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0x12
	strb r0, [r2, #5]
_0820750C:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08207528
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
_08207528:
	pop {r0}
	bx r0
