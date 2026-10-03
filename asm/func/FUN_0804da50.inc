	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x32
	ldrb r0, [r3]
	cmp r0, #0
	beq _0804DA62
	movs r0, #0
	strb r0, [r3]
_0804DA62:
	movs r1, #0x17
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r1, [r2, #0x38]
	str r0, [r2, #0x44]
	movs r0, #1
	strb r0, [r3]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
