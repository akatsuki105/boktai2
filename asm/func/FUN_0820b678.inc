	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _0820B68C
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0x10
	strb r0, [r4, #5]
_0820B68C:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _0820B6AC
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl MsgQueue_EndWait
	movs r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	strb r0, [r4, #4]
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
_0820B6AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
