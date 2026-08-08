	push {r4, lr}
	adds r4, r1, #0
	ldr r3, [r0, #0x24]
	ldr r2, [r0, #0x28]
	movs r1, #0
	strb r1, [r0, #4]
	cmp r3, #0
	beq _0822A380
	str r2, [r3, #0x28]
	b _0822A388
_0822A380:
	ldr r1, _0822A394 @ =0x03003560
	lsls r0, r4, #2
	adds r0, r0, r1
	str r2, [r0]
_0822A388:
	cmp r2, #0
	beq _0822A38E
	str r3, [r2, #0x24]
_0822A38E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822A394: .4byte 0x03003560
