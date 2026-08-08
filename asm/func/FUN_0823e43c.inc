	push {r4, r5, lr}
	sub sp, #8
	ldr r4, _0823E460 @ =gClock
	ldrb r5, [r4, #0xe]
	mov r0, sp
	bl FUN_0823167c
	ldrb r2, [r4, #0xe]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	adds r0, r5, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823E460: .4byte gClock
