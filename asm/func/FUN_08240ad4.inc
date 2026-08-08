	push {lr}
	subs r3, r0, r3
	cmp r3, #0
	bge _08240ADE
	rsbs r3, r3, #0
_08240ADE:
	ldr r0, [sp, #4]
	subs r1, r1, r0
	cmp r1, #0
	bge _08240AE8
	rsbs r1, r1, #0
_08240AE8:
	ldr r0, [sp, #8]
	adds r2, r2, r0
	cmp r3, r2
	bge _08240AF8
	cmp r1, r2
	bge _08240AF8
	movs r0, #1
	b _08240AFA
_08240AF8:
	movs r0, #0
_08240AFA:
	pop {r1}
	bx r1
	.align 2, 0
