	push {lr}
	adds r3, r0, #0
	movs r2, #0
	strb r1, [r3, #0xa]
	movs r0, #1
	strb r0, [r3, #4]
	str r2, [r3, #0x24]
	ldr r0, _0822A368 @ =0x03003560
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r3, #0x28]
	cmp r0, #0
	beq _0822A35E
	str r3, [r0, #0x24]
_0822A35E:
	str r3, [r1]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_0822A368: .4byte 0x03003560
