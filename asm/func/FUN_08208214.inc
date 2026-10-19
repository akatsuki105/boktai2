	push {r4, lr}
	adds r4, r1, #0
	adds r4, #0x20
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820823A
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x12
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl MsgQueue_EndWait
	movs r0, #1
	strh r0, [r4, #0x16]
_0820823A:
	pop {r4}
	pop {r0}
	bx r0
