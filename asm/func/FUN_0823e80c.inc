	push {lr}
	ldr r0, _0823E81C @ =gClock
	ldrb r0, [r0, #4]
	cmp r0, #2
	bls _0823E820
	movs r0, #0
	b _0823E822
	.align 2, 0
_0823E81C: .4byte gClock
_0823E820:
	movs r0, #1
_0823E822:
	pop {r1}
	bx r1
	.align 2, 0
