	push {lr}
	ldr r3, _08205FC4 @ =0x085AE8DC
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_08205FC4: .4byte 0x085AE8DC
