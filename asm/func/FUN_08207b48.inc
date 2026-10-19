	push {lr}
	ldr r3, _08207B5C @ =0x085AEACC
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_08207B5C: .4byte 0x085AEACC
