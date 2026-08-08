	push {lr}
	sub sp, #8
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	ldr r1, _082323CC @ =gVM
	ldr r0, [sp, #4]
	str r0, [r1, #4]
	movs r0, #0
	add sp, #8
	pop {r1}
	bx r1
	.align 2, 0
_082323CC: .4byte gVM
