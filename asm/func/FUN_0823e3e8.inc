	push {r4, lr}
	sub sp, #8
	mov r0, sp
	bl FUN_0823167c
	ldr r4, _0823E438 @ =gClock
	ldrb r2, [r4, #0xc]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldrb r2, [r4, #0xd]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldrb r2, [r4, #0x10]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldrb r2, [r4, #0x11]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823E438: .4byte gClock
