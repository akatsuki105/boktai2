	push {lr}
	adds r3, r0, #0
	movs r2, #0
	strb r1, [r3, #0x11]
	movs r0, #1
	strb r0, [r3, #4]
	str r2, [r3, #0x20]
	ldr r0, _0822A3C0 @ =0x03003570
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r3, #0x24]
	cmp r0, #0
	beq _0822A3B6
	str r3, [r0, #0x20]
_0822A3B6:
	str r3, [r1]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_0822A3C0: .4byte 0x03003570
