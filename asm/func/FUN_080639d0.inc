	push {lr}
	adds r2, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0xf3
	ands r0, r1
	cmp r0, #0
	beq _080639F2
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080639F2:
	pop {r0}
	bx r0
	.align 2, 0
