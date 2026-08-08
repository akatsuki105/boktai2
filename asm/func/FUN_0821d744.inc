	push {lr}
	ldr r2, _0821D75C @ =0x085AFFB8
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0821D75C: .4byte 0x085AFFB8
