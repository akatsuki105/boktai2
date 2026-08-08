	push {lr}
	movs r1, #0
	ldr r0, [r0, #0x6c]
	cmp r0, #4
	bne _0821B858
	movs r1, #1
_0821B858:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
