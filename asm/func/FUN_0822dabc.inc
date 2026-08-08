	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #4]
	cmp r0, #0
	beq _0822DACE
	ldrb r1, [r2, #0x11]
	adds r0, r2, #0
	bl FUN_0822a3c4
_0822DACE:
	pop {r0}
	bx r0
	.align 2, 0
