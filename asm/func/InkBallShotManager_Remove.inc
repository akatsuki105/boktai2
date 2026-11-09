	push {lr}
	adds r3, r0, #0
	ldr r0, _08203030 @ =0x03000218
	ldr r0, [r0]
	cmp r3, #0
	beq _0820302A
	adds r1, r0, #0
	adds r1, #0x3c
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xec
	strh r2, [r0]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r2, r3, #0
	adds r2, #0x3c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0820302A:
	pop {r0}
	bx r0
	.align 2, 0
_08203030: .4byte 0x03000218
