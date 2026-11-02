	push {r4, lr}
	sub sp, #4
	movs r4, #1
	str r4, [sp]
	bl Entity081ee2a0_Spawn
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
