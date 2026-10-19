	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820ABE6
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0xe
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl MsgQueue_EndWait
_0820ABE6:
	pop {r0}
	bx r0
	.align 2, 0
