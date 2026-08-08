	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldrb r0, [r3, #4]
	cmp r0, #0
	bne _0822DA6A
	movs r1, #0x80
	ands r1, r2
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	adds r0, r3, #0
	bl FUN_0822a398
_0822DA6A:
	pop {r0}
	bx r0
	.align 2, 0
