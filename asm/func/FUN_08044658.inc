	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _0804466C
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #7
	strb r0, [r2, #5]
_0804466C:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _0804468A
	movs r0, #7
	movs r1, #0
	strb r0, [r2, #4]
	str r1, [r2, #0x14]
	movs r0, #1
	strb r0, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl MsgQueue_EndWait
_0804468A:
	pop {r0}
	bx r0
	.align 2, 0
